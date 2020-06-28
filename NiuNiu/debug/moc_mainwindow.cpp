/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "update"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "update_date"
QT_MOC_LITERAL(4, 31, 11), // "line_finish"
QT_MOC_LITERAL(5, 43, 7), // "pu_stop"
QT_MOC_LITERAL(6, 51, 9), // "pu_locate"
QT_MOC_LITERAL(7, 61, 10), // "on_timeout"
QT_MOC_LITERAL(8, 72, 7), // "on_exit"
QT_MOC_LITERAL(9, 80, 12), // "on_responsed"
QT_MOC_LITERAL(10, 93, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 108, 5), // "reply"
QT_MOC_LITERAL(12, 114, 6), // "status"
QT_MOC_LITERAL(13, 121, 13), // "on_count_down"
QT_MOC_LITERAL(14, 135, 13), // "Request_faPai"
QT_MOC_LITERAL(15, 149, 4), // "CARD"
QT_MOC_LITERAL(16, 154, 4), // "card"
QT_MOC_LITERAL(17, 159, 14), // "Request_summit"
QT_MOC_LITERAL(18, 174, 15), // "Request_useless"
QT_MOC_LITERAL(19, 190, 13), // "Request_start"
QT_MOC_LITERAL(20, 204, 18) // "Request_initialize"

    },
    "MainWindow\0update\0\0update_date\0"
    "line_finish\0pu_stop\0pu_locate\0on_timeout\0"
    "on_exit\0on_responsed\0QNetworkReply*\0"
    "reply\0status\0on_count_down\0Request_faPai\0"
    "CARD\0card\0Request_summit\0Request_useless\0"
    "Request_start\0Request_initialize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    2,   91,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,
      19,    0,  102,    2, 0x08 /* Private */,
      20,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->update_date(); break;
        case 2: _t->line_finish(); break;
        case 3: _t->pu_stop(); break;
        case 4: _t->pu_locate(); break;
        case 5: _t->on_timeout(); break;
        case 6: _t->on_exit(); break;
        case 7: _t->on_responsed((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_count_down(); break;
        case 9: _t->Request_faPai((*reinterpret_cast< CARD(*)>(_a[1]))); break;
        case 10: _t->Request_summit(); break;
        case 11: _t->Request_useless(); break;
        case 12: _t->Request_start(); break;
        case 13: _t->Request_initialize(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
