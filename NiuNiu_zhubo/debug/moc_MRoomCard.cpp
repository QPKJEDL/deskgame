/****************************************************************************
** Meta object code from reading C++ file 'MRoomCard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NiuNiu_zhubo_mod/mod/mod_roomCard/MRoomCard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MRoomCard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRoomCard_t {
    QByteArrayData data[15];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRoomCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRoomCard_t qt_meta_stringdata_MRoomCard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MRoomCard"
QT_MOC_LITERAL(1, 10, 12), // "get_location"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "finished"
QT_MOC_LITERAL(4, 33, 16), // "request_roomCard"
QT_MOC_LITERAL(5, 50, 6), // "locate"
QT_MOC_LITERAL(6, 57, 4), // "loca"
QT_MOC_LITERAL(7, 62, 5), // "clear"
QT_MOC_LITERAL(8, 68, 13), // "while_timeout"
QT_MOC_LITERAL(9, 82, 5), // "focus"
QT_MOC_LITERAL(10, 88, 11), // "while_input"
QT_MOC_LITERAL(11, 100, 12), // "on_responsed"
QT_MOC_LITERAL(12, 113, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 128, 5), // "reply"
QT_MOC_LITERAL(14, 134, 6) // "status"

    },
    "MRoomCard\0get_location\0\0finished\0"
    "request_roomCard\0locate\0loca\0clear\0"
    "while_timeout\0focus\0while_input\0"
    "on_responsed\0QNetworkReply*\0reply\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRoomCard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   63,    2, 0x0a /* Public */,
       5,    1,   64,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    2,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,

       0        // eod
};

void MRoomCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MRoomCard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->get_location((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->finished();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->request_roomCard(); break;
        case 3: _t->locate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        case 5: _t->while_timeout(); break;
        case 6: _t->focus(); break;
        case 7: _t->while_input(); break;
        case 8: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
            using _t = int (MRoomCard::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRoomCard::get_location)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (MRoomCard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MRoomCard::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRoomCard::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MRoomCard.data,
    qt_meta_data_MRoomCard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRoomCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRoomCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRoomCard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MRoomCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
int MRoomCard::get_location(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int MRoomCard::finished()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
