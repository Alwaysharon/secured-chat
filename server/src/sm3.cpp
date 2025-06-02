#include "sm3.h"
#include <cstdint>
#include <cstring>

namespace sm3 {

// SM3 填充常量：256 位初始值
static const uint32_t IV[8] = {
    0x7380166F, 0x4914B2B9,
    0x172442D7, 0xDA8A0600,
    0xA96F30BC, 0x163138AA,
    0xE38DEE4D, 0xB0FB0E4E
};

static inline uint32_t ROTL(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

static inline uint32_t P0(uint32_t x) {
    return x ^ ROTL(x, 9) ^ ROTL(x, 17);
}

static inline uint32_t P1(uint32_t x) {
    return x ^ ROTL(x, 15) ^ ROTL(x, 23);
}

static inline uint32_t FF0(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

static inline uint32_t FF1(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (x & z) | (y & z);
}

static inline uint32_t GG0(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

static inline uint32_t GG1(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | ((~x) & z);
}

/**
 * @brief 计算一轮（消息分片） SM3 压缩函数
 * @param V_i    当前链值（8 个 uint32），下标 i
 * @param B_i    当前分组的 512-bit（64 字节）数据块
 * @param V_o    输出链值（8 个 uint32）
 */
static void CF(const uint32_t V_i[8], const unsigned char B_i[64], uint32_t V_o[8]) {
    uint32_t W[68], W1[64];
    // 1. 将 B_i 分成 16 个 32-bit 大端字
    for (int j = 0; j < 16; j++) {
        W[j] = ((uint32_t)B_i[j * 4 + 0] << 24)
             | ((uint32_t)B_i[j * 4 + 1] << 16)
             | ((uint32_t)B_i[j * 4 + 2] << 8)
             | ((uint32_t)B_i[j * 4 + 3] << 0);
    }
    // 2. 扩展填充 W[16..67]
    for (int j = 16; j < 68; j++) {
        uint32_t t = P1(W[j - 16] ^ W[j - 9] ^ ROTL(W[j - 3], 15))
                   ^ ROTL(W[j - 13], 7)
                   ^ W[j - 6];
        W[j] = t;
    }
    // 3. W1[j] = W[j] ^ W[j+4], j=0..63
    for (int j = 0; j < 64; j++) {
        W1[j] = W[j] ^ W[j + 4];
    }

    // 4. 初始化八个寄存器 A,B,C,D,E,F,G,H
    uint32_t A = V_i[0];
    uint32_t B = V_i[1];
    uint32_t C = V_i[2];
    uint32_t D = V_i[3];
    uint32_t E = V_i[4];
    uint32_t F = V_i[5];
    uint32_t G = V_i[6];
    uint32_t H = V_i[7];

    // 5. 迭代 64 轮
    for (int j = 0; j < 64; j++) {
        uint32_t SS1, SS2, TT1, TT2, Tj;
        if (j < 16) {
            Tj = 0x79CC4519;
        } else {
            Tj = 0x7A879D8A;
        }
        SS1 = ROTL((ROTL(A, 12) + E + ROTL(Tj, j)) & 0xFFFFFFFF, 7);
        SS2 = SS1 ^ ROTL(A, 12);

        uint32_t TT1_f, TT2_g;
        if (j < 16) {
            TT1_f = FF0(A, B, C);
            TT2_g = GG0(E, F, G);
        } else {
            TT1_f = FF1(A, B, C);
            TT2_g = GG1(E, F, G);
        }
        TT1 = (TT1_f + D + SS2 + W1[j]) & 0xFFFFFFFF;
        TT2 = (TT2_g + H + SS1 + W[j]) & 0xFFFFFFFF;

        D = C;
        C = ROTL(B, 9);
        B = A;
        A = TT1;

        H = G;
        G = ROTL(F, 19);
        F = E;
        E = P0(TT2);
    }

    // 6. 计算压缩后输出 V_o[i] = V_i[i] ^ A/B/C/.../H
    V_o[0] = V_i[0] ^ A;
    V_o[1] = V_i[1] ^ B;
    V_o[2] = V_i[2] ^ C;
    V_o[3] = V_i[3] ^ D;
    V_o[4] = V_i[4] ^ E;
    V_o[5] = V_i[5] ^ F;
    V_o[6] = V_i[6] ^ G;
    V_o[7] = V_i[7] ^ H;
}

/**
 * @brief 对任意长度消息 data[0..len-1] 进行 SM3 摘要
 * @param data   输入消息字节
 * @param len    输入长度（字节数）
 * @param out    结果缓冲，长度 32 字节
 */
void compute_sm3(const unsigned char *data, size_t len, unsigned char out[SM3_DIGEST_SIZE]) {
    // 1. 初始化链值 V = IV
    uint32_t V[8];
    for (int i = 0; i < 8; i++) {
        V[i] = IV[i];
    }

    // 2. 对消息分组，512-bit 一组
    //    每组会执行 CF(V, B_i) 来更新 V
    //    末尾要做“补位”和“长度”附加
    size_t block_count = (len + 1 + 8 + 63) / 64; // 向上取整
    unsigned char *buf = new unsigned char[block_count * 64];
    memset(buf, 0, block_count * 64);

    // 把原始消息先拷进 buf
    memcpy(buf, data, len);
    // “1” 位补 0x80
    buf[len] = 0x80;
    // 最后 8 个字节记录消息比特长度（大端）
    uint64_t bit_len = (uint64_t)len * 8;
    // 存到 buf[block_count*64 - 8 .. block_count*64-1]
    for (int i = 0; i < 8; i++) {
        buf[block_count * 64 - 1 - i] = (unsigned char)(bit_len & 0xFF);
        bit_len >>= 8;
    }

    // 3. 逐块压缩
    for (size_t i = 0; i < block_count; i++) {
        unsigned char *B_i = buf + i * 64;
        uint32_t V_new[8];
        CF(V, B_i, V_new);
        for (int j = 0; j < 8; j++) {
            V[j] = V_new[j];
        }
    }

    delete[] buf;

    // 4. 把 V[0..7] 转为大端字节，放入 out[0..31]
    for (int i = 0; i < 8; i++) {
        out[i * 4 + 0] = (unsigned char)((V[i] >> 24) & 0xFF);
        out[i * 4 + 1] = (unsigned char)((V[i] >> 16) & 0xFF);
        out[i * 4 + 2] = (unsigned char)((V[i] >> 8) & 0xFF);
        out[i * 4 + 3] = (unsigned char)((V[i] >> 0) & 0xFF);
    }
}

} // namespace sm3
