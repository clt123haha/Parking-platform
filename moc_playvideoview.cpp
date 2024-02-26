/****************************************************************************
** Meta object code from reading C++ file 'playvideoview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playvideoview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playvideoview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayVideoView_t {
    QByteArrayData data[14];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayVideoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayVideoView_t qt_meta_stringdata_PlayVideoView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PlayVideoView"
QT_MOC_LITERAL(1, 14, 9), // "sendCount"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "count"
QT_MOC_LITERAL(4, 31, 4), // "time"
QT_MOC_LITERAL(5, 36, 12), // "releseSlider"
QT_MOC_LITERAL(6, 49, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 71, 6), // "getMat"
QT_MOC_LITERAL(8, 78, 3), // "Mat"
QT_MOC_LITERAL(9, 82, 3), // "mat"
QT_MOC_LITERAL(10, 86, 10), // "moveSlider"
QT_MOC_LITERAL(11, 97, 1), // "p"
QT_MOC_LITERAL(12, 99, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(13, 131, 5) // "index"

    },
    "PlayVideoView\0sendCount\0\0count\0time\0"
    "releseSlider\0on_pushButton_clicked\0"
    "getMat\0Mat\0mat\0moveSlider\0p\0"
    "on_comboBox_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayVideoView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    2,   51,    2, 0x08 /* Private */,
      10,    1,   56,    2, 0x08 /* Private */,
      12,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    3,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void PlayVideoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayVideoView *_t = static_cast<PlayVideoView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->releseSlider(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->getMat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 4: _t->moveSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlayVideoView::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayVideoView::sendCount)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PlayVideoView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayVideoView.data,
      qt_meta_data_PlayVideoView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayVideoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayVideoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayVideoView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayVideoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void PlayVideoView::sendCount(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
