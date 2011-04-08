/****************************************************************************
** Meta object code from reading C++ file 'ControlPointTreeWidget.h'
**
** Created: Fri Apr 23 22:19:20 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ControlPointTreeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControlPointTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlPointTreeWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      33,   23,   23,   23, 0x05,
      48,   46,   23,   23, 0x05,
      62,   46,   23,   23, 0x05,
      76,   46,   23,   23, 0x05,
      92,   90,   23,   23, 0x05,
     108,   90,   23,   23, 0x05,
     124,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,  144,   23,   23, 0x0a,
     166,  164,   23,   23, 0x0a,
     181,  179,   23,   23, 0x0a,
     196,  194,   23,   23, 0x0a,
     209,   23,   23,   23, 0x0a,
     221,   23,   23,   23, 0x0a,
     231,  227,   23,   23, 0x0a,
     250,  246,   23,   23, 0x0a,
     269,  265,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ControlPointTreeWidget[] = {
    "ControlPointTreeWidget\0\0redraw()\0"
    "updateMesh()\0s\0sendX(double)\0sendY(double)\0"
    "sendZ(double)\0b\0enableXYZ(bool)\0"
    "enableRGB(bool)\0sendVertex(Vertex*)\0"
    "m\0acceptMesh(Mesh*)\0x\0setX(double)\0y\0"
    "setY(double)\0z\0setZ(double)\0activated()\0"
    "FFD()\0sin\0currS(QString)\0tin\0"
    "currT(QString)\0uin\0currU(QString)\0"
};

const QMetaObject ControlPointTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_ControlPointTreeWidget,
      qt_meta_data_ControlPointTreeWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlPointTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlPointTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlPointTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPointTreeWidget))
        return static_cast<void*>(const_cast< ControlPointTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int ControlPointTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: redraw(); break;
        case 1: updateMesh(); break;
        case 2: sendX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: sendY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: sendZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: enableXYZ((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: enableRGB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: sendVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 8: acceptMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 9: setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: setZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: activated(); break;
        case 13: FFD(); break;
        case 14: currS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: currT((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: currU((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ControlPointTreeWidget::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ControlPointTreeWidget::updateMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ControlPointTreeWidget::sendX(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ControlPointTreeWidget::sendY(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ControlPointTreeWidget::sendZ(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ControlPointTreeWidget::enableXYZ(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ControlPointTreeWidget::enableRGB(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ControlPointTreeWidget::sendVertex(Vertex * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
