/****************************************************************************
** Meta object code from reading C++ file 'addvideosourceform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/addvideosourceform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addvideosourceform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddVideoSourceForm_t {
    QByteArrayData data[16];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddVideoSourceForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddVideoSourceForm_t qt_meta_stringdata_AddVideoSourceForm = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AddVideoSourceForm"
QT_MOC_LITERAL(1, 19, 18), // "videoSourceDeleted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 23), // "VideoSourceAddedByIndex"
QT_MOC_LITERAL(5, 69, 4), // "name"
QT_MOC_LITERAL(6, 74, 9), // "enterance"
QT_MOC_LITERAL(7, 84, 6), // "releID"
QT_MOC_LITERAL(8, 91, 22), // "VideoSourceAddedByPath"
QT_MOC_LITERAL(9, 114, 4), // "path"
QT_MOC_LITERAL(10, 119, 24), // "addDeleteableVideoSource"
QT_MOC_LITERAL(11, 144, 12), // "updatePixmap"
QT_MOC_LITERAL(12, 157, 6), // "pixmap"
QT_MOC_LITERAL(13, 164, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(14, 185, 18), // "on_AddRele_clicked"
QT_MOC_LITERAL(15, 204, 7) // "checked"

    },
    "AddVideoSourceForm\0videoSourceDeleted\0"
    "\0index\0VideoSourceAddedByIndex\0name\0"
    "enterance\0releID\0VideoSourceAddedByPath\0"
    "path\0addDeleteableVideoSource\0"
    "updatePixmap\0pixmap\0on_AddButton_clicked\0"
    "on_AddRele_clicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddVideoSourceForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    4,   52,    2, 0x06 /* Public */,
       8,    4,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    3,   70,    2, 0x0a /* Public */,
      11,    2,   77,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool, QMetaType::QUuid,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QUuid,    9,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    3,    5,    6,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,   12,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

void AddVideoSourceForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddVideoSourceForm *_t = static_cast<AddVideoSourceForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoSourceDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->VideoSourceAddedByIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QUuid(*)>(_a[4]))); break;
        case 2: _t->VideoSourceAddedByPath((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QUuid(*)>(_a[4]))); break;
        case 3: _t->addDeleteableVideoSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->updatePixmap((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_AddButton_clicked(); break;
        case 6: _t->on_AddRele_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AddVideoSourceForm::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddVideoSourceForm::videoSourceDeleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddVideoSourceForm::*_t)(int , QString , bool , QUuid );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddVideoSourceForm::VideoSourceAddedByIndex)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AddVideoSourceForm::*_t)(const QString & , QString , bool , QUuid );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddVideoSourceForm::VideoSourceAddedByPath)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AddVideoSourceForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddVideoSourceForm.data,
      qt_meta_data_AddVideoSourceForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddVideoSourceForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddVideoSourceForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddVideoSourceForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddVideoSourceForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void AddVideoSourceForm::videoSourceDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddVideoSourceForm::VideoSourceAddedByIndex(int _t1, QString _t2, bool _t3, QUuid _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AddVideoSourceForm::VideoSourceAddedByPath(const QString & _t1, QString _t2, bool _t3, QUuid _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
