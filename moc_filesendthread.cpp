/****************************************************************************
** Meta object code from reading C++ file 'filesendthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filesendthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesendthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileSendThread_t {
    QByteArrayData data[6];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileSendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileSendThread_t qt_meta_stringdata_FileSendThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FileSendThread"
QT_MOC_LITERAL(1, 15, 8), // "sendOver"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "fileSendOver"
QT_MOC_LITERAL(4, 38, 13), // "getOverSingal"
QT_MOC_LITERAL(5, 52, 3) // "num"

    },
    "FileSendThread\0sendOver\0\0fileSendOver\0"
    "getOverSingal\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSendThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void FileSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileSendThread *_t = static_cast<FileSendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendOver(); break;
        case 1: _t->fileSendOver(); break;
        case 2: _t->getOverSingal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileSendThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSendThread::sendOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileSendThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSendThread::fileSendOver)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FileSendThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FileSendThread.data,
      qt_meta_data_FileSendThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSendThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int FileSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FileSendThread::sendOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FileSendThread::fileSendOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
