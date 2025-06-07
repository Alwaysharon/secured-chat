#include "crypto_util.h"
#include <QProcess>
#include <QTemporaryFile>
#include <QFile>
#include <QDebug>
#include <QRandomGenerator>
#include <QFileInfo>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

QByteArray generate_random_sm4_key() {
    QByteArray key(16, Qt::Uninitialized);
    for (int i = 0; i < 16; ++i)
        key[i] = static_cast<char>(QRandomGenerator::global()->bounded(0, 256));
    return key;
}

bool sm4_encrypt(const QByteArray &key, const QByteArray &in, QByteArray &out) {
    if (key.size() != 16) return false;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    if (!EVP_EncryptInit_ex(ctx, EVP_sm4_ecb(), NULL, (const unsigned char*)key.constData(), NULL)) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    QByteArray output(in.size() + EVP_CIPHER_block_size(EVP_sm4_ecb()), 0);
    int outlen1 = 0, outlen2 = 0;

    if (!EVP_EncryptUpdate(ctx,
                           reinterpret_cast<unsigned char*>(output.data()), &outlen1,
                           reinterpret_cast<const unsigned char*>(in.constData()), in.size())) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    if (!EVP_EncryptFinal_ex(ctx,
                             reinterpret_cast<unsigned char*>(output.data()) + outlen1, &outlen2)) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    out = output.left(outlen1 + outlen2);
    return true;
}


bool sm4_decrypt(const QByteArray &key, const QByteArray &cipher, QByteArray &plain) {
    if (key.size() != 16) return false;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    if (!EVP_DecryptInit_ex(ctx, EVP_sm4_ecb(), NULL, (const unsigned char*)key.constData(), NULL)) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    QByteArray output(cipher.size() + EVP_CIPHER_block_size(EVP_sm4_ecb()), 0);
    int outlen1 = 0, outlen2 = 0;

    if (!EVP_DecryptUpdate(ctx,
                           reinterpret_cast<unsigned char*>(output.data()), &outlen1,
                           reinterpret_cast<const unsigned char*>(cipher.constData()), cipher.size())) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    if (!EVP_DecryptFinal_ex(ctx,
                             reinterpret_cast<unsigned char*>(output.data()) + outlen1, &outlen2)) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    plain = output.left(outlen1 + outlen2);
    return true;
}



bool sm2_encrypt(const QString &pub_key_file, const QByteArray &in, QByteArray &out) {
    if (!QFileInfo::exists(pub_key_file)) {
        qWarning() << "SM2 pub key not found:" << pub_key_file;
        return false;
    }

    QTemporaryFile inFile, outFile;

    if (!inFile.open() || !outFile.open()) return false;

    inFile.write(in); inFile.flush();
    QString outFileName = outFile.fileName();
    outFile.close();

    QProcess process;
    process.start("gmssl", {
        "sm2utl", "-encrypt",
        "-in", inFile.fileName(),
        "-out", outFileName,
        "-pubin", "-inkey", pub_key_file
    });
    if (!process.waitForFinished(3000)) return false;

    QFile cipher(outFileName);
    if (!cipher.open(QIODevice::ReadOnly)) return false;
    out = cipher.readAll();
    return true;
}

bool sm2_decrypt(const QString &priv_key_file, const QByteArray &in, QByteArray &out) {
    if (!QFileInfo::exists(priv_key_file)) {
        qWarning() << "SM2 priv key not found:" << priv_key_file;
        return false;
    }

    QTemporaryFile inFile, outFile;

    if (!inFile.open() || !outFile.open()) return false;

    inFile.write(in); inFile.flush();
    QString outFileName = outFile.fileName();
    outFile.close();

    QProcess process;
    process.start("gmssl", {
        "sm2utl", "-decrypt",
        "-in", inFile.fileName(),
        "-out", outFileName,
        "-inkey", priv_key_file
    });
    if (!process.waitForFinished(3000)) return false;

    QFile plainFile(outFileName);
    if (!plainFile.open(QIODevice::ReadOnly)) return false;
    out = plainFile.readAll();
    return true;
}

QByteArray generate_random_key() {
    QByteArray key(16, 0);
    for (int i = 0; i < 16; ++i) {
        key[i] = static_cast<char>(QRandomGenerator::global()->bounded(256));
    }
    return key;
}

QByteArray sm2_decrypt_no_pass(const QString &privKeyPath, const QByteArray &cipherText) {
    BIO *bio = BIO_new_file(privKeyPath.toUtf8().constData(), "r");
    EVP_PKEY *pkey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
    BIO_free(bio);

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, NULL);
    EVP_PKEY_decrypt_init(ctx);

    size_t outlen = 0;
    EVP_PKEY_decrypt(ctx, NULL, &outlen, (const unsigned char *)cipherText.constData(), cipherText.size());

    QByteArray plaintext(outlen, 0);
    EVP_PKEY_decrypt(ctx, (unsigned char *)plaintext.data(), &outlen, (const unsigned char *)cipherText.constData(), cipherText.size());

    plaintext.resize(outlen);
    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    return plaintext;
}
void logAudit(const QString &eventType, const QString &username, const QString &details) {
    QFile file("audit.log");  // 日志文件放在服务器当前目录
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString logEntry = QString("[%1] 用户: %2 | 类型: %3 | 详情: %4\n")
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
            .arg(username)
            .arg(eventType)
            .arg(details);
        out << logEntry;
    }
}