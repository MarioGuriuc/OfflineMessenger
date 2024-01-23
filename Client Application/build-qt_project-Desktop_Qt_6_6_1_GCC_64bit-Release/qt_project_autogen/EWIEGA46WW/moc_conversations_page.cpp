/****************************************************************************
** Meta object code from reading C++ file 'conversations_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qt_project/conversations_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conversations_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_conversations_page_t {
    QByteArrayData data[8];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_conversations_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_conversations_page_t qt_meta_stringdata_conversations_page = {
    {
QT_MOC_LITERAL(0, 0, 18), // "conversations_page"
QT_MOC_LITERAL(1, 19, 22), // "on_send_button_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 23), // "on_reply_button_clicked"
QT_MOC_LITERAL(4, 67, 31), // "on_users_list_itemDoubleClicked"
QT_MOC_LITERAL(5, 99, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 116, 4), // "item"
QT_MOC_LITERAL(7, 121, 24) // "on_logout_button_clicked"

    },
    "conversations_page\0on_send_button_clicked\0"
    "\0on_reply_button_clicked\0"
    "on_users_list_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_logout_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_conversations_page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void conversations_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<conversations_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_send_button_clicked(); break;
        case 1: _t->on_reply_button_clicked(); break;
        case 2: _t->on_users_list_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_logout_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject conversations_page::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_conversations_page.data,
    qt_meta_data_conversations_page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *conversations_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *conversations_page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_conversations_page.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int conversations_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
