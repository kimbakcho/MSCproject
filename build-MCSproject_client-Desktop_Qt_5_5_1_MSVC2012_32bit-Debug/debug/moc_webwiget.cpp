/****************************************************************************
** Meta object code from reading C++ file 'webwiget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MCSproject_client/webwiget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webwiget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_webwiget_t {
    QByteArrayData data[7];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_webwiget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_webwiget_t qt_meta_stringdata_webwiget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "webwiget"
QT_MOC_LITERAL(1, 9, 8), // "autostep"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "finishedpage"
QT_MOC_LITERAL(4, 32, 4), // "flag"
QT_MOC_LITERAL(5, 37, 11), // "sitemoniter"
QT_MOC_LITERAL(6, 49, 9) // "read_data"

    },
    "webwiget\0autostep\0\0finishedpage\0flag\0"
    "sitemoniter\0read_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_webwiget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void webwiget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        webwiget *_t = static_cast<webwiget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->autostep(); break;
        case 1: _t->finishedpage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sitemoniter(); break;
        case 3: _t->read_data(); break;
        default: ;
        }
    }
}

const QMetaObject webwiget::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_webwiget.data,
      qt_meta_data_webwiget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *webwiget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *webwiget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_webwiget.stringdata0))
        return static_cast<void*>(const_cast< webwiget*>(this));
    return QWebView::qt_metacast(_clname);
}

int webwiget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
