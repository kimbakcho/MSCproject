/****************************************************************************
** Meta object code from reading C++ file 'tcpserverframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MSCproject/tcpserverframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserverframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tcpserverframe_t {
    QByteArrayData data[13];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tcpserverframe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tcpserverframe_t qt_meta_stringdata_Tcpserverframe = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Tcpserverframe"
QT_MOC_LITERAL(1, 15, 14), // "sig_sendtxtlog"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "log"
QT_MOC_LITERAL(4, 35, 11), // "serverstart"
QT_MOC_LITERAL(5, 47, 11), // "remotestart"
QT_MOC_LITERAL(6, 59, 10), // "remotestop"
QT_MOC_LITERAL(7, 70, 16), // "QEsetport_change"
QT_MOC_LITERAL(8, 87, 3), // "str"
QT_MOC_LITERAL(9, 91, 19), // "QEjaccnumber_change"
QT_MOC_LITERAL(10, 111, 17), // "QEjpwumber_change"
QT_MOC_LITERAL(11, 129, 22), // "QEjQLmoneyprice_change"
QT_MOC_LITERAL(12, 152, 15) // "slot_sendtxtlog"

    },
    "Tcpserverframe\0sig_sendtxtlog\0\0log\0"
    "serverstart\0remotestart\0remotestop\0"
    "QEsetport_change\0str\0QEjaccnumber_change\0"
    "QEjpwumber_change\0QEjQLmoneyprice_change\0"
    "slot_sendtxtlog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcpserverframe[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Tcpserverframe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tcpserverframe *_t = static_cast<Tcpserverframe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_sendtxtlog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->serverstart(); break;
        case 2: _t->remotestart(); break;
        case 3: _t->remotestop(); break;
        case 4: _t->QEsetport_change((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->QEjaccnumber_change((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->QEjpwumber_change((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->QEjQLmoneyprice_change((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_sendtxtlog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tcpserverframe::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tcpserverframe::sig_sendtxtlog)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Tcpserverframe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tcpserverframe.data,
      qt_meta_data_Tcpserverframe,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tcpserverframe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcpserverframe::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tcpserverframe.stringdata0))
        return static_cast<void*>(const_cast< Tcpserverframe*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tcpserverframe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Tcpserverframe::sig_sendtxtlog(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
