/****************************************************************************
** Meta object code from reading C++ file 'videodetectionhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/LFR/videodetectionhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videodetectionhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoDetectionHandler_t {
    QByteArrayData data[28];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoDetectionHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoDetectionHandler_t qt_meta_stringdata_VideoDetectionHandler = {
    {
QT_MOC_LITERAL(0, 0, 21), // "VideoDetectionHandler"
QT_MOC_LITERAL(1, 22, 8), // "finished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "runningChanged"
QT_MOC_LITERAL(4, 47, 7), // "running"
QT_MOC_LITERAL(5, 55, 12), // "frameUpdated"
QT_MOC_LITERAL(6, 68, 13), // "VideoDisplay*"
QT_MOC_LITERAL(7, 82, 7), // "display"
QT_MOC_LITERAL(8, 90, 7), // "cv::Mat"
QT_MOC_LITERAL(9, 98, 6), // "pixmap"
QT_MOC_LITERAL(10, 105, 8), // "DrawInfo"
QT_MOC_LITERAL(11, 114, 4), // "info"
QT_MOC_LITERAL(12, 119, 14), // "personDetected"
QT_MOC_LITERAL(13, 134, 8), // "detected"
QT_MOC_LITERAL(14, 143, 2), // "id"
QT_MOC_LITERAL(15, 146, 10), // "confidence"
QT_MOC_LITERAL(16, 157, 10), // "similarity"
QT_MOC_LITERAL(17, 168, 36), // "VideoDetectionHandler::VideoD..."
QT_MOC_LITERAL(18, 205, 12), // "videoDisplay"
QT_MOC_LITERAL(19, 218, 24), // "setCameraInputResolution"
QT_MOC_LITERAL(20, 243, 1), // "x"
QT_MOC_LITERAL(21, 245, 1), // "y"
QT_MOC_LITERAL(22, 247, 25), // "setCameraOutputResolution"
QT_MOC_LITERAL(23, 273, 23), // "setBrightnessCorrection"
QT_MOC_LITERAL(24, 297, 4), // "corr"
QT_MOC_LITERAL(25, 302, 21), // "setContrastCorrection"
QT_MOC_LITERAL(26, 324, 3), // "run"
QT_MOC_LITERAL(27, 328, 10) // "setRunning"

    },
    "VideoDetectionHandler\0finished\0\0"
    "runningChanged\0running\0frameUpdated\0"
    "VideoDisplay*\0display\0cv::Mat\0pixmap\0"
    "DrawInfo\0info\0personDetected\0detected\0"
    "id\0confidence\0similarity\0"
    "VideoDetectionHandler::VideoDisplay*\0"
    "videoDisplay\0setCameraInputResolution\0"
    "x\0y\0setCameraOutputResolution\0"
    "setBrightnessCorrection\0corr\0"
    "setContrastCorrection\0run\0setRunning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoDetectionHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    3,   68,    2, 0x06 /* Public */,
      12,    5,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,   86,    2, 0x0a /* Public */,
      22,    2,   91,    2, 0x0a /* Public */,
      23,    1,   96,    2, 0x0a /* Public */,
      25,    1,   99,    2, 0x0a /* Public */,
      26,    0,  102,    2, 0x0a /* Public */,
      27,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   13,   14,   15,   16,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void VideoDetectionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoDetectionHandler *_t = static_cast<VideoDetectionHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->frameUpdated((*reinterpret_cast< VideoDisplay*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< DrawInfo(*)>(_a[3]))); break;
        case 3: _t->personDetected((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< VideoDetectionHandler::VideoDisplay*(*)>(_a[5]))); break;
        case 4: _t->setCameraInputResolution((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setCameraOutputResolution((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setBrightnessCorrection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setContrastCorrection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->run(); break;
        case 9: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (VideoDetectionHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoDetectionHandler::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoDetectionHandler::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoDetectionHandler::runningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VideoDetectionHandler::*_t)(VideoDisplay * , cv::Mat , DrawInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoDetectionHandler::frameUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (VideoDetectionHandler::*_t)(bool , int , double , double , VideoDetectionHandler::VideoDisplay * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoDetectionHandler::personDetected)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        VideoDetectionHandler *_t = static_cast<VideoDetectionHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->running(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        VideoDetectionHandler *_t = static_cast<VideoDetectionHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRunning(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject VideoDetectionHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VideoDetectionHandler.data,
      qt_meta_data_VideoDetectionHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VideoDetectionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoDetectionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoDetectionHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoDetectionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VideoDetectionHandler::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoDetectionHandler::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoDetectionHandler::frameUpdated(VideoDisplay * _t1, cv::Mat _t2, DrawInfo _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoDetectionHandler::personDetected(bool _t1, int _t2, double _t3, double _t4, VideoDetectionHandler::VideoDisplay * _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
