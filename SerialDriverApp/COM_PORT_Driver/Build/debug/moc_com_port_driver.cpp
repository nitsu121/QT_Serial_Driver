/****************************************************************************
** Meta object code from reading C++ file 'com_port_driver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../com_port_driver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'com_port_driver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_com_port_driver_t {
    QByteArrayData data[10];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_com_port_driver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_com_port_driver_t qt_meta_stringdata_com_port_driver = {
    {
QT_MOC_LITERAL(0, 0, 15), // "com_port_driver"
QT_MOC_LITERAL(1, 16, 5), // "error"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "com_queue_item_t"
QT_MOC_LITERAL(4, 40, 9), // "pushqueue"
QT_MOC_LITERAL(5, 50, 12), // "com_response"
QT_MOC_LITERAL(6, 63, 7), // "quint8*"
QT_MOC_LITERAL(7, 71, 21), // "Com_Port_Not_Conneted"
QT_MOC_LITERAL(8, 93, 18), // "Com_Port_Connected"
QT_MOC_LITERAL(9, 112, 7) // "enqueue"

    },
    "com_port_driver\0error\0\0com_queue_item_t\0"
    "pushqueue\0com_response\0quint8*\0"
    "Com_Port_Not_Conneted\0Com_Port_Connected\0"
    "enqueue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_com_port_driver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    2,   50,    2, 0x06 /* Public */,
       7,    0,   55,    2, 0x06 /* Public */,
       8,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UChar,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void com_port_driver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        com_port_driver *_t = static_cast<com_port_driver *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< com_queue_item_t(*)>(_a[1]))); break;
        case 1: _t->pushqueue((*reinterpret_cast< com_queue_item_t(*)>(_a[1]))); break;
        case 2: _t->com_response((*reinterpret_cast< quint8*(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 3: _t->Com_Port_Not_Conneted(); break;
        case 4: _t->Com_Port_Connected(); break;
        case 5: _t->enqueue((*reinterpret_cast< com_queue_item_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (com_port_driver::*_t)(com_queue_item_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::error)) {
                *result = 0;
            }
        }
        {
            typedef void (com_port_driver::*_t)(com_queue_item_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::pushqueue)) {
                *result = 1;
            }
        }
        {
            typedef void (com_port_driver::*_t)(quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::com_response)) {
                *result = 2;
            }
        }
        {
            typedef void (com_port_driver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::Com_Port_Not_Conneted)) {
                *result = 3;
            }
        }
        {
            typedef void (com_port_driver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::Com_Port_Connected)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject com_port_driver::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_com_port_driver.data,
      qt_meta_data_com_port_driver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *com_port_driver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *com_port_driver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_com_port_driver.stringdata))
        return static_cast<void*>(const_cast< com_port_driver*>(this));
    return QThread::qt_metacast(_clname);
}

int com_port_driver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void com_port_driver::error(com_queue_item_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void com_port_driver::pushqueue(com_queue_item_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void com_port_driver::com_response(quint8 * _t1, quint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void com_port_driver::Com_Port_Not_Conneted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void com_port_driver::Com_Port_Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
