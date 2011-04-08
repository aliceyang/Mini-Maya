/****************************************************************************
** Meta object code from reading C++ file 'LightsListWidget.h'
**
** Created: Fri Apr 23 22:19:16 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LightsListWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LightsListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LightsListWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x05,
      33,   31,   17,   17, 0x05,
      46,   44,   17,   17, 0x05,
      59,   57,   17,   17, 0x05,
      76,   74,   17,   17, 0x05,
      92,   90,   17,   17, 0x05,
     108,  106,   17,   17, 0x05,
     122,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     131,   17,   17,   17, 0x0a,
     152,   18,   17,   17, 0x0a,
     162,   31,   17,   17, 0x0a,
     172,   44,   17,   17, 0x0a,
     182,   74,   17,   17, 0x0a,
     195,   90,   17,   17, 0x0a,
     208,  106,   17,   17, 0x0a,
     221,   17,   17,   17, 0x0a,
     236,   17,   17,   17, 0x0a,
     251,   17,   17,   17, 0x0a,
     267,   17,   17,   17, 0x0a,
     276,   17,   17,   17, 0x0a,
     286,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LightsListWidget[] = {
    "LightsListWidget\0\0r\0sendR(int)\0g\0"
    "sendG(int)\0b\0sendB(int)\0s\0sendShine(int)\0"
    "x\0sendX(double)\0y\0sendY(double)\0z\0"
    "sendZ(double)\0redraw()\0acceptLights(Light*)\0"
    "setR(int)\0setG(int)\0setB(int)\0"
    "setX(double)\0setY(double)\0setZ(double)\0"
    "setToAmbient()\0setToDiffuse()\0"
    "setToSpecular()\0enable()\0disable()\0"
    "activated()\0"
};

const QMetaObject LightsListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_LightsListWidget,
      qt_meta_data_LightsListWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightsListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightsListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightsListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightsListWidget))
        return static_cast<void*>(const_cast< LightsListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int LightsListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: sendG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: sendB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: sendShine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: sendX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: sendY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: sendZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: redraw(); break;
        case 8: acceptLights((*reinterpret_cast< Light*(*)>(_a[1]))); break;
        case 9: setR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: setB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: setZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: setToAmbient(); break;
        case 16: setToDiffuse(); break;
        case 17: setToSpecular(); break;
        case 18: enable(); break;
        case 19: disable(); break;
        case 20: activated(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void LightsListWidget::sendR(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LightsListWidget::sendG(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LightsListWidget::sendB(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LightsListWidget::sendShine(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LightsListWidget::sendX(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LightsListWidget::sendY(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LightsListWidget::sendZ(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void LightsListWidget::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
