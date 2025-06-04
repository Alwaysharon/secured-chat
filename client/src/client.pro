QT       += core gui network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    chat.cpp \
    chatlist.cpp \
    clientcore.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    messagebox.cpp \
    ../../crypto/crypto_util.cpp  # ✅ 添加加密实现

HEADERS += \
    chat.h \
    chatlist.h \
    clientcore.h \
    loginwindow.h \
    mainwindow.h \
    messagebox.h \
    ../../crypto/crypto_util.h   # ✅ 添加头文件引用

FORMS += \
    chat.ui \
    chatlist.ui \
    loginwindow.ui \
    mainwindow.ui

RESOURCES += \
    ImageRes.qrc

INCLUDEPATH += ../../crypto

LIBS += -L/usr/lib -lssl -lcrypto

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
