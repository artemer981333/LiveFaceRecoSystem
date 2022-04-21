/****************************************************************************
** Meta object code from reading C++ file 'messagehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/messagehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageHandler_t {
    QByteArrayData data[14];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageHandler_t qt_meta_stringdata_MessageHandler = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MessageHandler"
QT_MOC_LITERAL(1, 15, 8), // "finished"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "sendMessage"
QT_MOC_LITERAL(4, 37, 7), // "message"
QT_MOC_LITERAL(5, 45, 14), // "runningChanged"
QT_MOC_LITERAL(6, 60, 7), // "running"
QT_MOC_LITERAL(7, 68, 9), // "askForLFR"
QT_MOC_LITERAL(8, 78, 3), // "run"
QT_MOC_LITERAL(9, 82, 10), // "setRunning"
QT_MOC_LITERAL(10, 93, 12), // "connectToLFR"
QT_MOC_LITERAL(11, 106, 13), // "LiveFaceReco*"
QT_MOC_LITERAL(12, 120, 3), // "lfr"
QT_MOC_LITERAL(13, 124, 9) // "connected"

    },
    "MessageHandler\0finished\0\0sendMessage\0"
    "message\0runningChanged\0running\0askForLFR\0"
    "run\0setRunning\0connectToLFR\0LiveFaceReco*\0"
    "lfr\0connected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 11,   12,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00495103,
      13, QMetaType::Bool, 0x00095001,

 // properties: notify_signal_id
       2,
       0,

       0        // eod
};

void MessageHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageHandler *_t = static_cast<MessageHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->askForLFR(); break;
        case 4: _t->run(); break;
        case 5: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->connectToLFR((*reinterpret_cast< LiveFaceReco*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MessageHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageHandler::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageHandler::sendMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageHandler::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageHandler::runningChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MessageHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageHandler::askForLFR)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MessageHandler *_t = static_cast<MessageHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->running(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->connected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MessageHandler *_t = static_cast<MessageHandler *>(_o);
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

const QMetaObject MessageHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MessageHandler.data,
      qt_meta_data_MessageHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MessageHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MessageHandler::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MessageHandler::sendMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageHandler::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MessageHandler::askForLFR()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
