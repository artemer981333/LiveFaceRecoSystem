/****************************************************************************
** Meta object code from reading C++ file 'devicecontrolform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/devicecontrolform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicecontrolform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceControlForm_t {
    QByteArrayData data[13];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceControlForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceControlForm_t qt_meta_stringdata_DeviceControlForm = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DeviceControlForm"
QT_MOC_LITERAL(1, 18, 16), // "relesListUpdated"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 27), // "QList<DevicesManager::Rele>"
QT_MOC_LITERAL(4, 64, 5), // "reles"
QT_MOC_LITERAL(5, 70, 9), // "showEvent"
QT_MOC_LITERAL(6, 80, 11), // "QShowEvent*"
QT_MOC_LITERAL(7, 92, 5), // "event"
QT_MOC_LITERAL(8, 98, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(9, 119, 22), // "on_DevicesList_clicked"
QT_MOC_LITERAL(10, 142, 5), // "index"
QT_MOC_LITERAL(11, 148, 21), // "on_EditButton_clicked"
QT_MOC_LITERAL(12, 170, 19) // "on_OKButton_clicked"

    },
    "DeviceControlForm\0relesListUpdated\0\0"
    "QList<DevicesManager::Rele>\0reles\0"
    "showEvent\0QShowEvent*\0event\0"
    "on_AddButton_clicked\0on_DevicesList_clicked\0"
    "index\0on_EditButton_clicked\0"
    "on_OKButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceControlForm[] = {

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
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,
      11,    0,   54,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceControlForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceControlForm *_t = static_cast<DeviceControlForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->relesListUpdated((*reinterpret_cast< const QList<DevicesManager::Rele>(*)>(_a[1]))); break;
        case 1: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: _t->on_AddButton_clicked(); break;
        case 3: _t->on_DevicesList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_EditButton_clicked(); break;
        case 5: _t->on_OKButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DeviceControlForm::*_t)(const QList<DevicesManager::Rele> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceControlForm::relesListUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DeviceControlForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DeviceControlForm.data,
      qt_meta_data_DeviceControlForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DeviceControlForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceControlForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceControlForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeviceControlForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DeviceControlForm::relesListUpdated(const QList<DevicesManager::Rele> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
