/****************************************************************************
** Meta object code from reading C++ file 'VertexTreeWidget.h'
**
** Created: Fri Apr 23 22:19:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VertexTreeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VertexTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VertexTreeWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      27,   17,   17,   17, 0x05,
      42,   40,   17,   17, 0x05,
      73,   71,   17,   17, 0x05,
      87,   71,   17,   17, 0x05,
     101,   71,   17,   17, 0x05,
     117,  115,   17,   17, 0x05,
     133,  115,   17,   17, 0x05,
     149,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     171,  169,   17,   17, 0x0a,
     191,  189,   17,   17, 0x0a,
     206,  204,   17,   17, 0x0a,
     221,  219,   17,   17, 0x0a,
     234,   17,   17,   17, 0x0a,
     249,   17,   17,   17, 0x0a,
     267,   17,   17,   17, 0x0a,
     289,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VertexTreeWidget[] = {
    "VertexTreeWidget\0\0redraw()\0updateMesh()\0"
    "v\0addEdgeBetweenFaces(Vertex*)\0s\0"
    "sendX(double)\0sendY(double)\0sendZ(double)\0"
    "b\0enableXYZ(bool)\0enableRGB(bool)\0"
    "sendVertex(Vertex*)\0m\0acceptMesh(Mesh*)\0"
    "x\0setX(double)\0y\0setY(double)\0z\0"
    "setZ(double)\0deleteVertex()\0"
    "addVertexToEdge()\0addEdgeBetweenFaces()\0"
    "activated()\0"
};

const QMetaObject VertexTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_VertexTreeWidget,
      qt_meta_data_VertexTreeWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VertexTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VertexTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VertexTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VertexTreeWidget))
        return static_cast<void*>(const_cast< VertexTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int VertexTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: redraw(); break;
        case 1: updateMesh(); break;
        case 2: addEdgeBetweenFaces((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: sendX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: sendY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: sendZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: enableXYZ((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: enableRGB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: sendVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 9: acceptMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 10: setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: setZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: deleteVertex(); break;
        case 14: addVertexToEdge(); break;
        case 15: addEdgeBetweenFaces(); break;
        case 16: activated(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void VertexTreeWidget::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VertexTreeWidget::updateMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VertexTreeWidget::addEdgeBetweenFaces(Vertex * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VertexTreeWidget::sendX(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VertexTreeWidget::sendY(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VertexTreeWidget::sendZ(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VertexTreeWidget::enableXYZ(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void VertexTreeWidget::enableRGB(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void VertexTreeWidget::sendVertex(Vertex * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
