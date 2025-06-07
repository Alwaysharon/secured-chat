#include "sm2_util.h"
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/sm2.h>
#include <openssl/sm4.h>
#include <QFile>
#include <QDebug>

bool loadPublicKey(const QString &filePath, EVP_PKEY **pkey) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return false;

    BIO *bio = BIO_new_mem_buf(file.readAll().data(), -1);
    *pkey = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);
    return *pkey != nullptr;
}

bool loadPrivateKey(const QString &filePath, EVP_PKEY **pkey) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return false;

    BIO *bio = BIO_new_mem_buf(file.readAll().data(), -1);
    *pkey = PEM_read_bio_PrivateKey(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);
    return *pkey != nullptr;
}

bool sm2_encrypt(const QString &pubKeyFile, const QByteArray &input, QByteArray &output) {
    EVP_PKEY *pkey = nullptr;
    if (!loadPublicKey(pubKeyFile, &pkey)) return false;

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) return false;

    if (EVP_PKEY_encrypt_init(ctx) <= 0) return false;
    size_t outlen = 0;
    EVP_PKEY_encrypt(ctx, nullptr, &outlen, (const unsigned char *)input.data(), input.size());
    output.resize(outlen);
    if (EVP_PKEY_encrypt(ctx, (unsigned char *)output.data(), &outlen,
                         (const unsigned char *)input.data(), input.size()) <= 0) {
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        return false;
    }

    output.resize(outlen);
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
    return true;
}

bool sm2_decrypt(const QString &privKeyFile, const QByteArray &input, QByteArray &output) {
    EVP_PKEY *pkey = nullptr;
    if (!loadPrivateKey(privKeyFile, &pkey)) return false;

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) return false;

    if (EVP_PKEY_decrypt_init(ctx) <= 0) return false;
    size_t outlen = 0;
    EVP_PKEY_decrypt(ctx, nullptr, &outlen, (const unsigned char *)input.data(), input.size());
    output.resize(outlen);
    if (EVP_PKEY_decrypt(ctx, (unsigned char *)output.data(), &outlen,
                         (const unsigned char *)input.data(), input.size()) <= 0) {
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        return false;
    }

    output.resize(outlen);
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
    return true;
}

bool sm4_encrypt(const QByteArray &key, const QByteArray &input, QByteArray &output) {
    if (key.size() != 16) return false;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    int outlen1 = 0, outlen2 = 0;
    output.resize(input.size() + 16);

    EVP_EncryptInit_ex(ctx, EVP_sm4_ecb(), nullptr, (const unsigned char *)key.data(), nullptr);
    EVP_EncryptUpdate(ctx, (unsigned char *)output.data(), &outlen1,
                      (const unsigned char *)input.data(), input.size());
    EVP_EncryptFinal_ex(ctx, (unsigned char *)output.data() + outlen1, &outlen2);

    output.resize(outlen1 + outlen2);
    EVP_CIPHER_CTX_free(ctx);
    return true;
}

// bool sm4_decrypt(const QByteArray &key, const QByteArray &input, QByteArray &output) {
//     if (key.size() != 16) return false;
//     EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
//     if (!ctx) return false;

//     int outlen1 = 0, outlen2 = 0;
//     output.resize(input.size());

//     EVP_DecryptInit_ex(ctx, EVP_sm4_ecb(), nullptr, (const unsigned char *)key.data(), nullptr);
//     EVP_DecryptUpdate(ctx, (unsigned char *)output.data(), &outlen1,
//                       (const unsigned char *)input.data(), input.size());
//     EVP_DecryptFinal_ex(ctx, (unsigned char *)output.data() + outlen1, &outlen2);

//     output.resize(outlen1 + outlen2);
//     EVP_CIPHER_CTX_free(ctx);
//     return true;
// }
