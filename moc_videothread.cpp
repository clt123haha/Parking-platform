/****************************************************************************
** Meta object code from reading C++ file 'videothread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "videothread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_videothread_t {
    QByteArrayData data[7];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_videothread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_videothread_t qt_meta_stringdata_videothread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "videothread"
QT_MOC_LITERAL(1, 12, 9), // "sendFrame"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "currentFrame"
QT_MOC_LITERAL(4, 36, 3), // "Mat"
QT_MOC_LITERAL(5, 40, 5), // "frame"
QT_MOC_LITERAL(6, 46, 8) // "videoEnd"

    },
    "videothread\0sendFrame\0\0currentFrame\0"
    "Mat\0frame\0videoEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_videothread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

       0        // eod
};

void videothread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        videothread *_t = static_cast<videothread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 1: _t->videoEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (videothread::*_t)(int , Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videothread::sendFrame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (videothread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videothread::videoEnd)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject videothread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_videothread.data,
      qt_meta_data_videothread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *videothread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videothread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_videothread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int videothread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void videothread::sendFrame(int _t1, Mat _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void videothread::videoEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
