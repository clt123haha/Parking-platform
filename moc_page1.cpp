/****************************************************************************
** Meta object code from reading C++ file 'page1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "page1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Page1_t {
    QByteArrayData data[26];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Page1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Page1_t qt_meta_stringdata_Page1 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Page1"
QT_MOC_LITERAL(1, 6, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "getMat"
QT_MOC_LITERAL(4, 36, 3), // "Mat"
QT_MOC_LITERAL(5, 40, 3), // "mat"
QT_MOC_LITERAL(6, 44, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 68, 15), // "getEntranceBack"
QT_MOC_LITERAL(8, 84, 4), // "flag"
QT_MOC_LITERAL(9, 89, 5), // "count"
QT_MOC_LITERAL(10, 95, 5), // "char*"
QT_MOC_LITERAL(11, 101, 3), // "mes"
QT_MOC_LITERAL(12, 105, 7), // "getdate"
QT_MOC_LITERAL(13, 113, 3), // "row"
QT_MOC_LITERAL(14, 117, 2), // "id"
QT_MOC_LITERAL(15, 120, 4), // "str1"
QT_MOC_LITERAL(16, 125, 4), // "str2"
QT_MOC_LITERAL(17, 130, 4), // "str3"
QT_MOC_LITERAL(18, 135, 11), // "timerUpdata"
QT_MOC_LITERAL(19, 147, 12), // "fileSendOver"
QT_MOC_LITERAL(20, 160, 13), // "fileSplitOver"
QT_MOC_LITERAL(21, 174, 15), // "getFileSendBack"
QT_MOC_LITERAL(22, 190, 7), // "account"
QT_MOC_LITERAL(23, 198, 4), // "path"
QT_MOC_LITERAL(24, 203, 8), // "fileName"
QT_MOC_LITERAL(25, 212, 5) // "type_"

    },
    "Page1\0on_pushButton_clicked\0\0getMat\0"
    "Mat\0mat\0on_pushButton_2_clicked\0"
    "getEntranceBack\0flag\0count\0char*\0mes\0"
    "getdate\0row\0id\0str1\0str2\0str3\0timerUpdata\0"
    "fileSendOver\0fileSplitOver\0getFileSendBack\0"
    "account\0path\0fileName\0type_"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Page1[] = {

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
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    3,   64,    2, 0x08 /* Private */,
      12,    5,   71,    2, 0x08 /* Private */,
      18,    0,   82,    2, 0x08 /* Private */,
      19,    0,   83,    2, 0x08 /* Private */,
      20,    0,   84,    2, 0x08 /* Private */,
      21,    5,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Int,    8,   22,   23,   24,   25,

       0        // eod
};

void Page1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Page1 *_t = static_cast<Page1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->getMat((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->getEntranceBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3]))); break;
        case 4: _t->getdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->timerUpdata(); break;
        case 6: _t->fileSendOver(); break;
        case 7: _t->fileSplitOver(); break;
        case 8: _t->getFileSendBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3])),(*reinterpret_cast< char*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObject Page1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Page1.data,
      qt_meta_data_Page1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Page1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Page1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Page1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Page1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
