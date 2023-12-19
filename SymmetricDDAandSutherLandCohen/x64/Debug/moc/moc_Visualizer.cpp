/****************************************************************************
** Meta object code from reading C++ file 'Visualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../Visualizer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Visualizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVisualizerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVisualizerENDCLASS = QtMocHelpers::stringData(
    "Visualizer",
    "clipLine",
    "",
    "drawLine",
    "drawCurveUsingHermite",
    "drawCurveUsingBezier",
    "drawCurveUsingBSpline"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVisualizerENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[22];
    char stringdata5[21];
    char stringdata6[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVisualizerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVisualizerENDCLASS_t qt_meta_stringdata_CLASSVisualizerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Visualizer"
        QT_MOC_LITERAL(11, 8),  // "clipLine"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 8),  // "drawLine"
        QT_MOC_LITERAL(30, 21),  // "drawCurveUsingHermite"
        QT_MOC_LITERAL(52, 20),  // "drawCurveUsingBezier"
        QT_MOC_LITERAL(73, 21)   // "drawCurveUsingBSpline"
    },
    "Visualizer",
    "clipLine",
    "",
    "drawLine",
    "drawCurveUsingHermite",
    "drawCurveUsingBezier",
    "drawCurveUsingBSpline"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVisualizerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    0,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Visualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSVisualizerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVisualizerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVisualizerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Visualizer, std::true_type>,
        // method 'clipLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawCurveUsingHermite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawCurveUsingBezier'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawCurveUsingBSpline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Visualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Visualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clipLine(); break;
        case 1: _t->drawLine(); break;
        case 2: _t->drawCurveUsingHermite(); break;
        case 3: _t->drawCurveUsingBezier(); break;
        case 4: _t->drawCurveUsingBSpline(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Visualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Visualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVisualizerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Visualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
