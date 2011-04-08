/****************************************************************************
** Meta object code from reading C++ file 'MyExportButton.h'
**
** Created: Fri Apr 23 22:19:15 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyExportButton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyExportButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyExportButton[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      30,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   15,   15,   15, 0x0a,
      58,   56,   15,   15, 0x0a,
      80,   76,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyExportButton[] = {
    "MyExportButton\0\0requestMesh()\0"
    "requestMtl()\0exportFile()\0m\0"
    "acceptMesh(Mesh*)\0mtl\0acceptMtl(string)\0"
};

const QMetaObject MyExportButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MyExportButton,
      qt_meta_data_MyExportButton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyExportButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyExportButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyExportButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyExportButton))
        return static_cast<void*>(const_cast< MyExportButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MyExportButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestMesh(); break;
        case 1: requestMtl(); break;
        case 2: exportFile(); break;
        case 3: acceptMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 4: acceptMtl((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyExportButton::requestMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyExportButton::requestMtl()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
