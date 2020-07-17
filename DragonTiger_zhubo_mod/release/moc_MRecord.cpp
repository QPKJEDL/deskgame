/****************************************************************************
** Meta object code from reading C++ file 'MRecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mod/mod_record/MRecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MRecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRecord_t {
    QByteArrayData data[10];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRecord_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRecord_t qt_meta_stringdata_MRecord = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MRecord"
QT_MOC_LITERAL(1, 8, 14), // "request_record"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "apply_record"
QT_MOC_LITERAL(4, 37, 4), // "game"
QT_MOC_LITERAL(5, 42, 10), // "on_useless"
QT_MOC_LITERAL(6, 53, 12), // "on_responsed"
QT_MOC_LITERAL(7, 66, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 81, 5), // "reply"
QT_MOC_LITERAL(9, 87, 6) // "status"

    },
    "MRecord\0request_record\0\0apply_record\0"
    "game\0on_useless\0on_responsed\0"
    "QNetworkReply*\0reply\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRecord[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    2,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

       0        // eod
};

void MRecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MRecord *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->request_record(); break;
        case 1: _t->apply_record((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_useless(); break;
        case 3: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRecord::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MRecord.data,
    qt_meta_data_MRecord,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MRecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRecord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRecord.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MRecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
