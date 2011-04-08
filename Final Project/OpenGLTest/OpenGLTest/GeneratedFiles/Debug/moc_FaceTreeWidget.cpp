/****************************************************************************
** Meta object code from reading C++ file 'FaceTreeWidget.h'
**
** Created: Fri Apr 23 22:19:18 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FaceTreeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FaceTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FaceTreeWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      25,   15,   15,   15, 0x05,
      40,   38,   15,   15, 0x05,
      56,   54,   15,   15, 0x05,
      72,   70,   15,   15, 0x05,
      92,   86,   15,   15, 0x05,
     115,  107,   15,   15, 0x05,
     135,   70,   15,   15, 0x05,
     151,   70,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     169,  167,   15,   15, 0x0a,
     189,  187,   15,   15, 0x0a,
     207,   38,   15,   15, 0x0a,
     220,   54,   15,   15, 0x0a,
     233,   70,   15,   15, 0x0a,
     246,   86,   15,   15, 0x0a,
     260,  107,   15,   15, 0x0a,
     278,   15,   15,   15, 0x0a,
     301,   15,   15,   15, 0x0a,
     316,  314,   15,   15, 0x0a,
     345,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FaceTreeWidget[] = {
    "FaceTreeWidget\0\0redraw()\0updateMesh()\0"
    "r\0sendR(double)\0g\0sendG(double)\0b\0"
    "sendB(double)\0shine\0sendShine(int)\0"
    "enabled\0sendShineBool(bool)\0enableXYZ(bool)\0"
    "enableRGB(bool)\0m\0acceptMesh(Mesh*)\0"
    "f\0acceptFace(Face*)\0setR(double)\0"
    "setG(double)\0setB(double)\0setShine(int)\0"
    "enableShine(bool)\0SplitQuadToTriangles()\0"
    "deleteFace()\0v\0addEdgeBetweenFaces(Vertex*)\0"
    "activated()\0"
};

const QMetaObject FaceTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_FaceTreeWidget,
      qt_meta_data_FaceTreeWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FaceTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FaceTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FaceTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FaceTreeWidget))
        return static_cast<void*>(const_cast< FaceTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int FaceTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: redraw(); break;
        case 1: updateMesh(); break;
        case 2: sendR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: sendG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: sendB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: sendShine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: sendShineBool((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: enableXYZ((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: enableRGB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: acceptMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 10: acceptFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 11: setR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: setG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: setB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: setShine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: enableShine((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: SplitQuadToTriangles(); break;
        case 17: deleteFace(); break;
        case 18: addEdgeBetweenFaces((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 19: activated(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void FaceTreeWidget::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FaceTreeWidget::updateMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FaceTreeWidget::sendR(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FaceTreeWidget::sendG(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FaceTreeWidget::sendB(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FaceTreeWidget::sendShine(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FaceTreeWidget::sendShineBool(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FaceTreeWidget::enableXYZ(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void FaceTreeWidget::enableRGB(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
