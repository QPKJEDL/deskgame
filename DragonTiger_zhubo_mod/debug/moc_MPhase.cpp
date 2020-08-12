/****************************************************************************
** Meta object code from reading C++ file 'MPhase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mod/mod_phase/MPhase.h"
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
    QByteArrayData data[19];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MPhase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MPhase_t qt_meta_stringdata_MPhase = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MPhase"
QT_MOC_LITERAL(1, 7, 7), // "timeout"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "kaipaizhong"
QT_MOC_LITERAL(4, 28, 10), // "on_timeout"
QT_MOC_LITERAL(5, 39, 7), // "pu_stop"
QT_MOC_LITERAL(6, 47, 12), // "on_responsed"
QT_MOC_LITERAL(7, 60, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 75, 5), // "reply"
QT_MOC_LITERAL(9, 81, 6), // "status"
QT_MOC_LITERAL(10, 88, 8), // "to_phase"
QT_MOC_LITERAL(11, 97, 5), // "phase"
QT_MOC_LITERAL(12, 103, 5), // "start"
QT_MOC_LITERAL(13, 109, 3), // "end"
QT_MOC_LITERAL(14, 113, 9), // "countDown"
QT_MOC_LITERAL(15, 123, 9), // "wait_down"
QT_MOC_LITERAL(16, 133, 10), // "on_started"
QT_MOC_LITERAL(17, 144, 11), // "on_finished"
QT_MOC_LITERAL(18, 156, 10) // "on_useless"

    },
    "MPhase\0timeout\0\0kaipaizhong\0on_timeout\0"
    "pu_stop\0on_responsed\0QNetworkReply*\0"
    "reply\0status\0to_phase\0phase\0start\0end\0"
    "countDown\0wait_down\0on_started\0"
    "on_finished\0on_useless"
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
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    2,   63,    2, 0x08 /* Private */,
      10,    5,   68,    2, 0x0a /* Public */,
      16,    0,   79,    2, 0x0a /* Public */,
      17,    0,   80,    2, 0x0a /* Public */,
      18,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,   15,
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
        case 0: _t->timeout(); break;
        case 1: _t->kaipaizhong(); break;
        case 2: _t->on_timeout(); break;
        case 3: _t->pu_stop(); break;
        case 4: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->to_phase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 6: _t->on_started(); break;
        case 7: _t->on_finished(); break;
        case 8: _t->on_useless(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (MPhase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::timeout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MPhase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::kaipaizhong)) {
                *result = 1;
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
void MPhase::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MPhase::kaipaizhong()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
