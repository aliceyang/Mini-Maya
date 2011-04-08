/****************************************************************************
** Meta object code from reading C++ file 'MyLoadButton.h'
**
** Created: Fri Apr 23 22:19:11 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyLoadButton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLoadButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyLoadButton[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      39,   35,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   13,   13,   13, 0x0a,
      66,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyLoadButton[] = {
    "MyLoadButton\0\0mesh\0sendMesh(Mesh*)\0"
    "mtl\0sendMtl(string)\0loadFile()\0"
    "acceptMtlRequest()\0"
};

const QMetaObject MyLoadButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MyLoadButton,
      qt_meta_data_MyLoadButton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyLoadButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyLoadButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyLoadButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyLoadButton))
        return static_cast<void*>(const_cast< MyLoadButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MyLoadButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 1: sendMtl((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: loadFile(); break;
        case 3: acceptMtlRequest(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyLoadButton::sendMesh(Mesh * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyLoadButton::sendMtl(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
