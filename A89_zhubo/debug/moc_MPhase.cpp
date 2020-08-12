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
    QByteArrayData data[23];
    char stringdata0[206];
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
QT_MOC_LITERAL(3, 16, 7), // "timeout"
QT_MOC_LITERAL(4, 24, 12), // "phase_kaipai"
QT_MOC_LITERAL(5, 37, 10), // "on_timeout"
QT_MOC_LITERAL(6, 48, 12), // "on_responsed"
QT_MOC_LITERAL(7, 61, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 76, 5), // "reply"
QT_MOC_LITERAL(9, 82, 6), // "status"
QT_MOC_LITERAL(10, 89, 9), // "pu_locate"
QT_MOC_LITERAL(11, 99, 7), // "pu_stop"
QT_MOC_LITERAL(12, 107, 17), // "while_line_finish"
QT_MOC_LITERAL(13, 125, 8), // "to_phase"
QT_MOC_LITERAL(14, 134, 5), // "phase"
QT_MOC_LITERAL(15, 140, 5), // "start"
QT_MOC_LITERAL(16, 146, 3), // "end"
QT_MOC_LITERAL(17, 150, 9), // "countDown"
QT_MOC_LITERAL(18, 160, 9), // "wait_down"
QT_MOC_LITERAL(19, 170, 11), // "on_finished"
QT_MOC_LITERAL(20, 182, 3), // "str"
QT_MOC_LITERAL(21, 186, 8), // "on_start"
QT_MOC_LITERAL(22, 195, 10) // "on_located"

    },
    "MPhase\0located\0\0timeout\0phase_kaipai\0"
    "on_timeout\0on_responsed\0QNetworkReply*\0"
    "reply\0status\0pu_locate\0pu_stop\0"
    "while_line_finish\0to_phase\0phase\0start\0"
    "end\0countDown\0wait_down\0on_finished\0"
    "str\0on_start\0on_located"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MPhase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   79,    2, 0x08 /* Private */,
       6,    2,   80,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    5,   88,    2, 0x0a /* Public */,
      19,    1,   99,    2, 0x0a /* Public */,
      21,    0,  102,    2, 0x0a /* Public */,
      22,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::QString,   20,
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
        case 1: _t->timeout(); break;
        case 2: _t->phase_kaipai(); break;
        case 3: _t->on_timeout(); break;
        case 4: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->pu_locate(); break;
        case 6: _t->pu_stop(); break;
        case 7: _t->while_line_finish(); break;
        case 8: _t->to_phase((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 9: _t->on_finished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->on_start(); break;
        case 11: _t->on_located(); break;
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
            using _t = void (MPhase::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::located)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MPhase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::timeout)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MPhase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MPhase::phase_kaipai)) {
                *result = 2;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MPhase::located(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MPhase::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MPhase::phase_kaipai()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
