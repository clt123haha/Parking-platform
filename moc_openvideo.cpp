/****************************************************************************
** Meta object code from reading C++ file 'openvideo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "openvideo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openvideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_openVideo_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_openVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_openVideo_t qt_meta_stringdata_openVideo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "openVideo"
QT_MOC_LITERAL(1, 10, 12), // "receiveFrame"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "currentFrame"
QT_MOC_LITERAL(4, 37, 3), // "Mat"
QT_MOC_LITERAL(5, 41, 5), // "frame"
QT_MOC_LITERAL(6, 47, 8), // "endVideo"
QT_MOC_LITERAL(7, 56, 7) // "setOver"

    },
    "openVideo\0receiveFrame\0\0currentFrame\0"
    "Mat\0frame\0endVideo\0setOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_openVideo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       6,    0,   34,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void openVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        openVideo *_t = static_cast<openVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 1: _t->endVideo(); break;
        case 2: _t->setOver(); break;
        default: ;
        }
    }
}

const QMetaObject openVideo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_openVideo.data,
      qt_meta_data_openVideo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *openVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *openVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_openVideo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int openVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
