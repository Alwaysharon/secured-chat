/****************************************************************************
** Meta object code from reading C++ file 'adminmanagement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "adminmanagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminmanagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminManagement_t {
    QByteArrayData data[17];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminManagement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminManagement_t qt_meta_stringdata_AdminManagement = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AdminManagement"
QT_MOC_LITERAL(1, 16, 17), // "onUserDataChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 47, 7), // "topLeft"
QT_MOC_LITERAL(5, 55, 11), // "bottomRight"
QT_MOC_LITERAL(6, 67, 12), // "QVector<int>"
QT_MOC_LITERAL(7, 80, 5), // "roles"
QT_MOC_LITERAL(8, 86, 17), // "onChatDataChanged"
QT_MOC_LITERAL(9, 104, 25), // "on_FindUserButton_clicked"
QT_MOC_LITERAL(10, 130, 25), // "on_FindChatButton_clicked"
QT_MOC_LITERAL(11, 156, 24), // "on_NewUserButton_clicked"
QT_MOC_LITERAL(12, 181, 24), // "on_NewChatButton_clicked"
QT_MOC_LITERAL(13, 206, 27), // "on_DeleteUserButton_clicked"
QT_MOC_LITERAL(14, 234, 27), // "on_DeleteChatButton_clicked"
QT_MOC_LITERAL(15, 262, 27), // "on_ManageUserButton_clicked"
QT_MOC_LITERAL(16, 290, 27) // "on_ManageChatButton_clicked"

    },
    "AdminManagement\0onUserDataChanged\0\0"
    "QModelIndex\0topLeft\0bottomRight\0"
    "QVector<int>\0roles\0onChatDataChanged\0"
    "on_FindUserButton_clicked\0"
    "on_FindChatButton_clicked\0"
    "on_NewUserButton_clicked\0"
    "on_NewChatButton_clicked\0"
    "on_DeleteUserButton_clicked\0"
    "on_DeleteChatButton_clicked\0"
    "on_ManageUserButton_clicked\0"
    "on_ManageChatButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminManagement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x08 /* Private */,
       8,    3,   71,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminManagement *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onUserDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 1: _t->onChatDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 2: _t->on_FindUserButton_clicked(); break;
        case 3: _t->on_FindChatButton_clicked(); break;
        case 4: _t->on_NewUserButton_clicked(); break;
        case 5: _t->on_NewChatButton_clicked(); break;
        case 6: _t->on_DeleteUserButton_clicked(); break;
        case 7: _t->on_DeleteChatButton_clicked(); break;
        case 8: _t->on_ManageUserButton_clicked(); break;
        case 9: _t->on_ManageChatButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdminManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminManagement.data,
    qt_meta_data_AdminManagement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminManagement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
