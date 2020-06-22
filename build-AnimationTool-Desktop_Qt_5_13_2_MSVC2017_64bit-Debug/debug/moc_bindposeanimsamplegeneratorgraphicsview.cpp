/****************************************************************************
** Meta object code from reading C++ file 'bindposeanimsamplegeneratorgraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AnimationTool/BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bindposeanimsamplegeneratorgraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView_t {
    QByteArrayData data[7];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView_t qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 39), // "BindPoseAnimSampleGeneratorGr..."
QT_MOC_LITERAL(1, 40, 41), // "SignalAddJointToAnimSampleGen..."
QT_MOC_LITERAL(2, 82, 0), // ""
QT_MOC_LITERAL(3, 83, 42), // "SignalAddSpriteToAnimSampleGe..."
QT_MOC_LITERAL(4, 126, 13), // "SetWidthPixel"
QT_MOC_LITERAL(5, 140, 3), // "val"
QT_MOC_LITERAL(6, 144, 14) // "SetHeightPixel"

    },
    "BindPoseAnimSampleGeneratorGraphicsView\0"
    "SignalAddJointToAnimSampleGeneratorWidget\0"
    "\0SignalAddSpriteToAnimSampleGeneratorWidget\0"
    "SetWidthPixel\0val\0SetHeightPixel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BindPoseAnimSampleGeneratorGraphicsView[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void BindPoseAnimSampleGeneratorGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BindPoseAnimSampleGeneratorGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalAddJointToAnimSampleGeneratorWidget(); break;
        case 1: _t->SignalAddSpriteToAnimSampleGeneratorWidget(); break;
        case 2: _t->SetWidthPixel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SetHeightPixel((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BindPoseAnimSampleGeneratorGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView.data,
    qt_meta_data_BindPoseAnimSampleGeneratorGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BindPoseAnimSampleGeneratorGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BindPoseAnimSampleGeneratorGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BindPoseAnimSampleGeneratorGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int BindPoseAnimSampleGeneratorGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
