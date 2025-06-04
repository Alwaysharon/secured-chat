QT       += core gui network sql widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

# 更安全的路径，不要手动加 /usr/include
INCLUDEPATH += ../../crypto
LIBS += -lssl -lcrypto

SOURCES += \
    adminmanagement.cpp \
    main.cpp \
    messagemanage.cpp \
    server.cpp \
    servercore.cpp \
    usermanage.cpp \
    widget.cpp \
    ../../crypto/crypto_util.cpp

HEADERS += \
    adminmanagement.h \
    messagemanage.h \
    server.h \
    servercore.h \
    usermanage.h \
    widget.h \
    ../../crypto/crypto_util.h

FORMS += \
    adminmanagement.ui \
    messagemanage.ui \
    usermanage.ui \
    widget.ui

RESOURCES += \
    res.qrc
