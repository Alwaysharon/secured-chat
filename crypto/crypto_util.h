#ifndef CRYPTO_UTIL_H
#define CRYPTO_UTIL_H

#include <QByteArray>
#include <QString>

void logAudit(const QString &user, const QString &action, const QString &detail);

QByteArray sm2_decrypt_no_pass(const QString &privKeyPath, const QByteArray &cipherText);

QByteArray generate_random_key(); 
// SM2 加密（使用 server_pub.pem）
bool sm2_encrypt(const QString &pub_key_file, const QByteArray &in, QByteArray &out);

// SM2 解密（使用 server_priv.pem）
bool sm2_decrypt(const QString &priv_key_file, const QByteArray &in, QByteArray &out);

// SM4 加密
bool sm4_encrypt(const QByteArray &key, const QByteArray &in, QByteArray &out);

// SM4 解密
bool sm4_decrypt(const QByteArray &key, const QByteArray &cipher, QByteArray &plain);

// 生成 16 字节随机 SM4 密钥
QByteArray generate_random_sm4_key();

#endif // CRYPTO_UTIL_H
