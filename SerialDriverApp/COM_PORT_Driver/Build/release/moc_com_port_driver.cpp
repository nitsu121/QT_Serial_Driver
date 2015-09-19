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
    QByteArrayData data[31];
    char stringdata[310];
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
QT_MOC_LITERAL(3, 23, 15), // "mb_queue_item_t"
QT_MOC_LITERAL(4, 39, 11), // "mb_response"
QT_MOC_LITERAL(5, 51, 4), // "addr"
QT_MOC_LITERAL(6, 56, 8), // "priority"
QT_MOC_LITERAL(7, 65, 3), // "reg"
QT_MOC_LITERAL(8, 69, 4), // "int*"
QT_MOC_LITERAL(9, 74, 3), // "buf"
QT_MOC_LITERAL(10, 78, 2), // "id"
QT_MOC_LITERAL(11, 81, 4), // "type"
QT_MOC_LITERAL(12, 86, 8), // "filename"
QT_MOC_LITERAL(13, 95, 6), // "status"
QT_MOC_LITERAL(14, 102, 4), // "dest"
QT_MOC_LITERAL(15, 107, 4), // "size"
QT_MOC_LITERAL(16, 112, 22), // "NumOfResponceRegisters"
QT_MOC_LITERAL(17, 135, 9), // "pushqueue"
QT_MOC_LITERAL(18, 145, 7), // "address"
QT_MOC_LITERAL(19, 153, 4), // "data"
QT_MOC_LITERAL(20, 158, 8), // "data_len"
QT_MOC_LITERAL(21, 167, 18), // "modbusq_reg_type_t"
QT_MOC_LITERAL(22, 186, 21), // "Com_Port_Not_Conneted"
QT_MOC_LITERAL(23, 208, 18), // "Com_Port_Connected"
QT_MOC_LITERAL(24, 227, 15), // "Board_Not_Found"
QT_MOC_LITERAL(25, 243, 11), // "Board_Found"
QT_MOC_LITERAL(26, 255, 7), // "enqueue"
QT_MOC_LITERAL(27, 263, 16), // "enqueue_coil_cmd"
QT_MOC_LITERAL(28, 280, 9), // "StartCoil"
QT_MOC_LITERAL(29, 290, 13), // "NumberOfCoils"
QT_MOC_LITERAL(30, 304, 5) // "value"

    },
    "com_port_driver\0error\0\0mb_queue_item_t\0"
    "mb_response\0addr\0priority\0reg\0int*\0"
    "buf\0id\0type\0filename\0status\0dest\0size\0"
    "NumOfResponceRegisters\0pushqueue\0"
    "address\0data\0data_len\0modbusq_reg_type_t\0"
    "Com_Port_Not_Conneted\0Com_Port_Connected\0"
    "Board_Not_Found\0Board_Found\0enqueue\0"
    "enqueue_coil_cmd\0StartCoil\0NumberOfCoils\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_com_port_driver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,   11,   62,    2, 0x06 /* Public */,
      17,    8,   85,    2, 0x06 /* Public */,
      22,    0,  102,    2, 0x06 /* Public */,
      23,    0,  103,    2, 0x06 /* Public */,
      24,    0,  104,    2, 0x06 /* Public */,
      25,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    8,  106,    2, 0x0a /* Public */,
      27,    8,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    5,    6,    7,    9,   10,   11,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, 0x80000000 | 21, QMetaType::QString,   18,    6,    7,   19,   20,   10,   11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, 0x80000000 | 21, QMetaType::QString,   18,    6,    7,   19,   20,   10,   11,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Int, 0x80000000 | 21,    5,    6,   28,   29,   30,   20,   10,   11,

       0        // eod
};

void com_port_driver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        com_port_driver *_t = static_cast<com_port_driver *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< mb_queue_item_t(*)>(_a[1]))); break;
        case 1: _t->mb_response((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int*(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11]))); break;
        case 2: _t->pushqueue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< modbusq_reg_type_t(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 3: _t->Com_Port_Not_Conneted(); break;
        case 4: _t->Com_Port_Connected(); break;
        case 5: _t->Board_Not_Found(); break;
        case 6: _t->Board_Found(); break;
        case 7: _t->enqueue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< modbusq_reg_type_t(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 8: _t->enqueue_coil_cmd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< modbusq_reg_type_t(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (com_port_driver::*_t)(mb_queue_item_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::error)) {
                *result = 0;
            }
        }
        {
            typedef void (com_port_driver::*_t)(int , bool , int , int * , int , int , QString , int , int * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::mb_response)) {
                *result = 1;
            }
        }
        {
            typedef void (com_port_driver::*_t)(int , bool , int , int * , int , int , modbusq_reg_type_t , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::pushqueue)) {
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
        {
            typedef void (com_port_driver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::Board_Not_Found)) {
                *result = 5;
            }
        }
        {
            typedef void (com_port_driver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&com_port_driver::Board_Found)) {
                *result = 6;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void com_port_driver::error(mb_queue_item_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void com_port_driver::mb_response(int _t1, bool _t2, int _t3, int * _t4, int _t5, int _t6, QString _t7, int _t8, int * _t9, int _t10, int _t11)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void com_port_driver::pushqueue(int _t1, bool _t2, int _t3, int * _t4, int _t5, int _t6, modbusq_reg_type_t _t7, const QString & _t8)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
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

// SIGNAL 5
void com_port_driver::Board_Not_Found()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void com_port_driver::Board_Found()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
