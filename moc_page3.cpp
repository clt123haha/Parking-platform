/****************************************************************************
** Meta object code from reading C++ file 'page3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "page3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Page3_t {
    QByteArrayData data[23];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Page3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Page3_t qt_meta_stringdata_Page3 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Page3"
QT_MOC_LITERAL(1, 6, 8), // "rth2Over"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 15), // "getFileSendBack"
QT_MOC_LITERAL(4, 32, 4), // "flag"
QT_MOC_LITERAL(5, 37, 5), // "char*"
QT_MOC_LITERAL(6, 43, 7), // "account"
QT_MOC_LITERAL(7, 51, 4), // "path"
QT_MOC_LITERAL(8, 56, 8), // "fileName"
QT_MOC_LITERAL(9, 65, 5), // "type_"
QT_MOC_LITERAL(10, 71, 8), // "findNmae"
QT_MOC_LITERAL(11, 80, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 102, 6), // "getMat"
QT_MOC_LITERAL(13, 109, 3), // "Mat"
QT_MOC_LITERAL(14, 113, 3), // "mat"
QT_MOC_LITERAL(15, 117, 11), // "timerUpdata"
QT_MOC_LITERAL(16, 129, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(17, 153, 21), // "getCurVehicleInfoBack"
QT_MOC_LITERAL(18, 175, 3), // "num"
QT_MOC_LITERAL(19, 179, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(20, 204, 4), // "arg1"
QT_MOC_LITERAL(21, 209, 13), // "fileSplitOver"
QT_MOC_LITERAL(22, 223, 12) // "fileSendOver"

    },
    "Page3\0rth2Over\0\0getFileSendBack\0flag\0"
    "char*\0account\0path\0fileName\0type_\0"
    "findNmae\0on_pushButton_clicked\0getMat\0"
    "Mat\0mat\0timerUpdata\0on_pushButton_2_clicked\0"
    "getCurVehicleInfoBack\0num\0"
    "on_checkBox_stateChanged\0arg1\0"
    "fileSplitOver\0fileSendOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Page3[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    6,   65,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,
      17,    1,   84,    2, 0x08 /* Private */,
      19,    1,   87,    2, 0x08 /* Private */,
      21,    0,   90,    2, 0x08 /* Private */,
      22,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 5,    4,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Page3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Page3 *_t = static_cast<Page3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rth2Over(); break;
        case 1: _t->getFileSendBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3])),(*reinterpret_cast< char*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< char*(*)>(_a[6]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->getMat((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->timerUpdata(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->getCurVehicleInfoBack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->fileSplitOver(); break;
        case 9: _t->fileSendOver(); break;
        default: ;
        }
    }
}

const QMetaObject Page3::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Page3.data,
      qt_meta_data_Page3,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Page3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Page3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Page3.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Page3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
