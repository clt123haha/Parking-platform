/****************************************************************************
** Meta object code from reading C++ file 'page2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "page2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Page2_t {
    QByteArrayData data[27];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Page2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Page2_t qt_meta_stringdata_Page2 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Page2"
QT_MOC_LITERAL(1, 6, 15), // "getFileSendBack"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "flag"
QT_MOC_LITERAL(4, 28, 5), // "char*"
QT_MOC_LITERAL(5, 34, 7), // "account"
QT_MOC_LITERAL(6, 42, 4), // "path"
QT_MOC_LITERAL(7, 47, 8), // "fileName"
QT_MOC_LITERAL(8, 56, 5), // "type_"
QT_MOC_LITERAL(9, 62, 13), // "fileSplitOver"
QT_MOC_LITERAL(10, 76, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 98, 6), // "getMat"
QT_MOC_LITERAL(12, 105, 3), // "Mat"
QT_MOC_LITERAL(13, 109, 3), // "mat"
QT_MOC_LITERAL(14, 113, 11), // "timerUpdata"
QT_MOC_LITERAL(15, 125, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(16, 149, 11), // "getExitBack"
QT_MOC_LITERAL(17, 161, 5), // "count"
QT_MOC_LITERAL(18, 167, 9), // "park_time"
QT_MOC_LITERAL(19, 177, 5), // "money"
QT_MOC_LITERAL(20, 183, 6), // "number"
QT_MOC_LITERAL(21, 190, 3), // "mes"
QT_MOC_LITERAL(22, 194, 7), // "time_in"
QT_MOC_LITERAL(23, 202, 8), // "time_out"
QT_MOC_LITERAL(24, 211, 12), // "fileSendOver"
QT_MOC_LITERAL(25, 224, 21), // "getCURVEHICLEINFOBACK"
QT_MOC_LITERAL(26, 246, 3) // "num"

    },
    "Page2\0getFileSendBack\0\0flag\0char*\0"
    "account\0path\0fileName\0type_\0fileSplitOver\0"
    "on_pushButton_clicked\0getMat\0Mat\0mat\0"
    "timerUpdata\0on_pushButton_2_clicked\0"
    "getExitBack\0count\0park_time\0money\0"
    "number\0mes\0time_in\0time_out\0fileSendOver\0"
    "getCURVEHICLEINFOBACK\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Page2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   59,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      14,    0,   75,    2, 0x08 /* Private */,
      15,    0,   76,    2, 0x08 /* Private */,
      16,    8,   77,    2, 0x08 /* Private */,
      24,    0,   94,    2, 0x08 /* Private */,
      25,    1,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   17,   18,   19,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void Page2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Page2 *_t = static_cast<Page2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getFileSendBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3])),(*reinterpret_cast< char*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->fileSplitOver(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->getMat((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->timerUpdata(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->getExitBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 7: _t->fileSendOver(); break;
        case 8: _t->getCURVEHICLEINFOBACK((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Page2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Page2.data,
      qt_meta_data_Page2,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Page2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Page2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Page2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Page2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
