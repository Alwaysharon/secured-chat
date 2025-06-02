# server.pro

QT       += core gui network sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 link_pkgconfig

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    adminmanagement.cpp \
    main.cpp \
    messagemanage.cpp \
    server.cpp \
    servercore.cpp \
    usermanage.cpp \
    widget.cpp

HEADERS += \
    adminmanagement.h \
    messagemanage.h \
    server.h \
    servercore.h \
    usermanage.h \
    widget.h

FORMS += \
    adminmanagement.ui \
    messagemanage.ui \
    usermanage.ui \
    widget.ui

RESOURCES += \
    res.qrc

# —— 新增下面两行，借助 pkg-config 自动获取 OpenSSL 的 include 和 link 标志 —— 

PKGCONFIG += libcrypto

# ---------- 其他自动安装规则，不用动 ----------
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
