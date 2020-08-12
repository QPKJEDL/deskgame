/****************************************************************************
** Meta object code from reading C++ file 'MChat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mod/mod_chat/MChat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MChat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MChat_t {
    QByteArrayData data[22];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MChat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MChat_t qt_meta_stringdata_MChat = {
    {
QT_MOC_LITERAL(0, 0, 5), // "MChat"
QT_MOC_LITERAL(1, 6, 11), // "show_reword"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "user"
QT_MOC_LITERAL(4, 24, 5), // "money"
QT_MOC_LITERAL(5, 30, 8), // "showText"
QT_MOC_LITERAL(6, 39, 3), // "txt"
QT_MOC_LITERAL(7, 43, 4), // "name"
QT_MOC_LITERAL(8, 48, 2), // "id"
QT_MOC_LITERAL(9, 51, 10), // "ban_finish"
QT_MOC_LITERAL(10, 62, 14), // "show_top_three"
QT_MOC_LITERAL(11, 77, 4), // "data"
QT_MOC_LITERAL(12, 82, 11), // "readMessage"
QT_MOC_LITERAL(13, 94, 11), // "request_ban"
QT_MOC_LITERAL(14, 106, 3), // "uid"
QT_MOC_LITERAL(15, 110, 12), // "on_responsed"
QT_MOC_LITERAL(16, 123, 14), // "QNetworkReply*"
QT_MOC_LITERAL(17, 138, 5), // "reply"
QT_MOC_LITERAL(18, 144, 6), // "status"
QT_MOC_LITERAL(19, 151, 5), // "clear"
QT_MOC_LITERAL(20, 157, 7), // "pu_name"
QT_MOC_LITERAL(21, 165, 6) // "userid"

    },
    "MChat\0show_reword\0\0user\0money\0showText\0"
    "txt\0name\0id\0ban_finish\0show_top_three\0"
    "data\0readMessage\0request_ban\0uid\0"
    "on_responsed\0QNetworkReply*\0reply\0"
    "status\0clear\0pu_name\0userid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MChat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    3,   64,    2, 0x06 /* Public */,
       9,    1,   71,    2, 0x06 /* Public */,
      10,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   77,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      15,    2,   81,    2, 0x08 /* Private */,
      19,    0,   86,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      20,    2,   87,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QJsonObject,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int,   17,   18,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,    7,

       0        // eod
};

void MChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MChat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_reword((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->ban_finish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->show_top_three((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->readMessage(); break;
        case 5: _t->request_ban((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->clear(); break;
        case 8: _t->pu_name((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MChat::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MChat::show_reword)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MChat::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MChat::showText)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MChat::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MChat::ban_finish)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MChat::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MChat::show_top_three)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MChat::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MChat.data,
    qt_meta_data_MChat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MChat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MChat.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MChat::show_reword(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MChat::showText(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MChat::ban_finish(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MChat::show_top_three(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
