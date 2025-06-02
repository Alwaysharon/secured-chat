#ifndef SM3_H
#define SM3_H

#include <cstdint>
#include <cstring>

// 供外部调用的唯一接口：compute_sm3()，
// 参数：
//    - data: 输入的消息字节指针
//    - len:  输入长度（字节数）
//    - out:  输出缓冲区，至少要能放下 32 字节（SM3 输出 256 位）
// 使用示例：
//    unsigned char digest[32];
//    sm3::compute_sm3((const unsigned char*)msg, msg_len, digest);
//
// 计算完毕后，digest[0..31] 即为 raw 二进制 digest；
//
// 你可以再用 QByteArray((char*)digest,32).toHex() 把它转成十六进制字符串。

namespace sm3 {

/// SM3 的内部 state 大小常量
static constexpr int SM3_DIGEST_SIZE = 32;   // SM3 输出 256 bit = 32 byte

/**
 * @brief compute_sm3  计算一个完整消息的 SM3 摘要（一次性接口）
 *
 * @param data    输入消息缓冲区
 * @param len     输入消息长度（字节）
 * @param out     输出缓冲区，必须至少能存 32 字节
 */
void compute_sm3(const unsigned char *data, size_t len, unsigned char out[SM3_DIGEST_SIZE]);

} // namespace sm3

#endif // SM3_H
