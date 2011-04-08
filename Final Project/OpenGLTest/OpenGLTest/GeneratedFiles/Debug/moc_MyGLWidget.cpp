/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created: Fri Apr 23 22:19:13 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyGLWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      38,   33,   11,   11, 0x05,
      54,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     113,  106,   11,   11, 0x0a,
     144,   12,   11,   11, 0x0a,
     163,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0mesh\0sendMesh(Mesh*)\0face\0"
    "sendFace(Face*)\0sendLights(Light*)\0"
    "drawMesh()\0resendMesh()\0smooth()\0"
    "vertex\0recieveSelectedVertex(Vertex*)\0"
    "receiveMesh(Mesh*)\0receiveMeshRequest()\0"
};

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget,
      qt_meta_data_MyGLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 1: sendFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 2: sendLights((*reinterpret_cast< Light*(*)>(_a[1]))); break;
        case 3: drawMesh(); break;
        case 4: resendMesh(); break;
        case 5: smooth(); break;
        case 6: recieveSelectedVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 7: receiveMesh((*reinterpret_cast< Mesh*(*)>(_a[1]))); break;
        case 8: receiveMeshRequest(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::sendMesh(Mesh * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::sendFace(Face * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::sendLights(Light * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
