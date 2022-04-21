/****************************************************************************
** Meta object code from reading C++ file 'personalcardeditorform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/personalcardeditorform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personalcardeditorform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PersonalCardEditorForm_t {
    QByteArrayData data[25];
    char stringdata0[520];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PersonalCardEditorForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PersonalCardEditorForm_t qt_meta_stringdata_PersonalCardEditorForm = {
    {
QT_MOC_LITERAL(0, 0, 22), // "PersonalCardEditorForm"
QT_MOC_LITERAL(1, 23, 14), // "updateCardList"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "QList<PersonalCard>"
QT_MOC_LITERAL(4, 59, 5), // "cards"
QT_MOC_LITERAL(5, 65, 9), // "showEvent"
QT_MOC_LITERAL(6, 75, 11), // "QShowEvent*"
QT_MOC_LITERAL(7, 87, 5), // "event"
QT_MOC_LITERAL(8, 93, 24), // "on_AddCardButton_clicked"
QT_MOC_LITERAL(9, 118, 25), // "on_EditCardButton_clicked"
QT_MOC_LITERAL(10, 144, 23), // "on_SearchLE_textChanged"
QT_MOC_LITERAL(11, 168, 4), // "arg1"
QT_MOC_LITERAL(12, 173, 19), // "on_OKButton_clicked"
QT_MOC_LITERAL(13, 193, 23), // "on_CancelButton_clicked"
QT_MOC_LITERAL(14, 217, 31), // "on_AddSelectImageButton_clicked"
QT_MOC_LITERAL(15, 249, 32), // "on_EditSelectImageButton_clicked"
QT_MOC_LITERAL(16, 282, 27), // "on_DeleteCardButton_clicked"
QT_MOC_LITERAL(17, 310, 22), // "on_ClearButton_clicked"
QT_MOC_LITERAL(18, 333, 19), // "on_CardView_clicked"
QT_MOC_LITERAL(19, 353, 5), // "index"
QT_MOC_LITERAL(20, 359, 39), // "on_EditBrightnessSlider_actio..."
QT_MOC_LITERAL(21, 399, 6), // "action"
QT_MOC_LITERAL(22, 406, 37), // "on_EditContrastSlider_actionT..."
QT_MOC_LITERAL(23, 444, 38), // "on_AddBrightnessSlider_action..."
QT_MOC_LITERAL(24, 483, 36) // "on_AddContrastSlider_actionTr..."

    },
    "PersonalCardEditorForm\0updateCardList\0"
    "\0QList<PersonalCard>\0cards\0showEvent\0"
    "QShowEvent*\0event\0on_AddCardButton_clicked\0"
    "on_EditCardButton_clicked\0"
    "on_SearchLE_textChanged\0arg1\0"
    "on_OKButton_clicked\0on_CancelButton_clicked\0"
    "on_AddSelectImageButton_clicked\0"
    "on_EditSelectImageButton_clicked\0"
    "on_DeleteCardButton_clicked\0"
    "on_ClearButton_clicked\0on_CardView_clicked\0"
    "index\0on_EditBrightnessSlider_actionTriggered\0"
    "action\0on_EditContrastSlider_actionTriggered\0"
    "on_AddBrightnessSlider_actionTriggered\0"
    "on_AddContrastSlider_actionTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonalCardEditorForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   97,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      22,    1,  117,    2, 0x08 /* Private */,
      23,    1,  120,    2, 0x08 /* Private */,
      24,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void PersonalCardEditorForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonalCardEditorForm *_t = static_cast<PersonalCardEditorForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCardList((*reinterpret_cast< const QList<PersonalCard>(*)>(_a[1]))); break;
        case 1: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: _t->on_AddCardButton_clicked(); break;
        case 3: _t->on_EditCardButton_clicked(); break;
        case 4: _t->on_SearchLE_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_OKButton_clicked(); break;
        case 6: _t->on_CancelButton_clicked(); break;
        case 7: _t->on_AddSelectImageButton_clicked(); break;
        case 8: _t->on_EditSelectImageButton_clicked(); break;
        case 9: _t->on_DeleteCardButton_clicked(); break;
        case 10: _t->on_ClearButton_clicked(); break;
        case 11: _t->on_CardView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_EditBrightnessSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_EditContrastSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_AddBrightnessSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_AddContrastSlider_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PersonalCardEditorForm::*_t)(const QList<PersonalCard> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PersonalCardEditorForm::updateCardList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PersonalCardEditorForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PersonalCardEditorForm.data,
      qt_meta_data_PersonalCardEditorForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PersonalCardEditorForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonalCardEditorForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PersonalCardEditorForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PersonalCardEditorForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PersonalCardEditorForm::updateCardList(const QList<PersonalCard> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
