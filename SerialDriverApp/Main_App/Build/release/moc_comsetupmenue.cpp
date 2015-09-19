/****************************************************************************
** Meta object code from reading C++ file 'comsetupmenue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../comsetupmenue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comsetupmenue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ComSetUpMenue_t {
    QByteArrayData data[10];
    char stringdata[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComSetUpMenue_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComSetUpMenue_t qt_meta_stringdata_ComSetUpMenue = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ComSetUpMenue"
QT_MOC_LITERAL(1, 14, 30), // "on_SetConfigPushButton_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 39), // "on_BaudRateComboBox_currentIn..."
QT_MOC_LITERAL(4, 86, 5), // "index"
QT_MOC_LITERAL(5, 92, 37), // "on_ParityComboBox_currentInde..."
QT_MOC_LITERAL(6, 130, 39), // "on_DataBitsComboBox_currentIn..."
QT_MOC_LITERAL(7, 170, 39), // "on_StopBitsComboBox_currentIn..."
QT_MOC_LITERAL(8, 210, 42), // "on_FlowControlComboBox_curren..."
QT_MOC_LITERAL(9, 253, 26) // "on_ComSetUpMenue_destroyed"

    },
    "ComSetUpMenue\0on_SetConfigPushButton_clicked\0"
    "\0on_BaudRateComboBox_currentIndexChanged\0"
    "index\0on_ParityComboBox_currentIndexChanged\0"
    "on_DataBitsComboBox_currentIndexChanged\0"
    "on_StopBitsComboBox_currentIndexChanged\0"
    "on_FlowControlComboBox_currentIndexChanged\0"
    "on_ComSetUpMenue_destroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComSetUpMenue[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       6,    1,   56,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       8,    1,   62,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void ComSetUpMenue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComSetUpMenue *_t = static_cast<ComSetUpMenue *>(_o);
        switch (_id) {
        case 0: _t->on_SetConfigPushButton_clicked(); break;
        case 1: _t->on_BaudRateComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_ParityComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_DataBitsComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_StopBitsComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_FlowControlComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ComSetUpMenue_destroyed(); break;
        default: ;
        }
    }
}

const QMetaObject ComSetUpMenue::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ComSetUpMenue.data,
      qt_meta_data_ComSetUpMenue,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ComSetUpMenue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComSetUpMenue::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ComSetUpMenue.stringdata))
        return static_cast<void*>(const_cast< ComSetUpMenue*>(this));
    return QWidget::qt_metacast(_clname);
}

int ComSetUpMenue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
