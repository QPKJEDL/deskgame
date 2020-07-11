/****************************************************************************
** Meta object code from reading C++ file 'MPhase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NiuNiu_zhubo_mod/mod/mod_phase/MPhase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MPhase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MPhase_t {
    QByteArrayData data[18];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MPhase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MPhase_t qt_meta_stringdata_MPhase = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MPhase"
QT_MOC_LITERAL(1, 7, 7), // "located"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "on_timeout"
QT_MOC_LITERAL(4, 27, 12), // "on_responsed"
QT_MOC_LITERAL(5, 40, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 55, 5), // "reply"
QT_MOC_LITERAL(7, 61, 6), // "status"
QT_MOC_LITERAL(8, 68, 9), // "pu_locate"
QT_MOC_LITERAL(9, 78, 17), // "while_line_finish"
QT_MOC_LITERAL(10, 96, 8), // "to_phase"
QT_MOC_LITERAL(11, 105, 5), // "phase"
QT_MOC_LITERAL(12, 111, 5), // "start"
QT_MOC_LITERAL(13, 117, 3), // "end"
QT_MOC_LITERAL(14, 121, 9), // "countDown"
QT_MOC_LITERAL(15, 131, 11), // "on_finished"
QT_MOC_LITERAL(16, 143, 10), // "on_useless"
QT_MOC_LITERAL(17, 154, 8) // "on_start"

    },
    "MPhase\0located\0\0on_timeout\0on_responsed\0"
    "QNetworkReply*\0reply\0status\0pu_locate\0"
    "while_line_finish\0to_phase\0phase\0start\0"
    "end\0countDown\0on_finished\0on_useless\0"
    "on_start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MPhase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    2,   63,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    4,   70,    2, 0x0a /* Public */,
      15,    0,   79,    2, 0x0a /* Public */,
      16,    0,   80,    2, 0x0a /* Public */,
      17,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MPhase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MPhase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->located((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_timeout(); break;
        case 2: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->pu_locate(); break;
        case 4: _t->while_line_finish(); break;
        case 5: _t->to_phase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->on_finished(); break;
        case 7: _t->on_useless(); break;
        case 8: _t->on_start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            using _t = void (MPhase::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::located)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MPhase::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MPhase.data,
    qt_meta_data_MPhase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MPhase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MPhase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MPhase.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MPhase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MPhase::located(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
