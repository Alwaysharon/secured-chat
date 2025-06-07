#ifndef SM2_UTIL_H
#define SM2_UTIL_H

#include <QByteArray>
#include <QString>

bool sm2_encrypt(const QString &pubKeyFile, const QByteArray &input, QByteArray &output);
bool sm2_decrypt(const QString &privKeyFile, const QByteArray &input, QByteArray &output);

bool sm4_encrypt(const QByteArray &key, const QByteArray &input, QByteArray &output);
bool sm4_decrypt(const QByteArray &key, const QByteArray &input, QByteArray &output);

#endif // SM2_UTIL_H
