/****************************************************************************
** Meta object code from reading C++ file 'logic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Logic_t {
    QByteArrayData data[24];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logic_t qt_meta_stringdata_Logic = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Logic"
QT_MOC_LITERAL(1, 6, 19), // "sessionInnitialised"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "images"
QT_MOC_LITERAL(4, 34, 4), // "size"
QT_MOC_LITERAL(5, 39, 8), // "flipBack"
QT_MOC_LITERAL(6, 48, 2), // "x1"
QT_MOC_LITERAL(7, 51, 2), // "y1"
QT_MOC_LITERAL(8, 54, 2), // "x2"
QT_MOC_LITERAL(9, 57, 2), // "y2"
QT_MOC_LITERAL(10, 60, 4), // "flip"
QT_MOC_LITERAL(11, 65, 1), // "x"
QT_MOC_LITERAL(12, 67, 1), // "y"
QT_MOC_LITERAL(13, 69, 10), // "timeUpdate"
QT_MOC_LITERAL(14, 80, 4), // "time"
QT_MOC_LITERAL(15, 85, 11), // "stepsUpdate"
QT_MOC_LITERAL(16, 97, 5), // "steps"
QT_MOC_LITERAL(17, 103, 11), // "scoreUpdate"
QT_MOC_LITERAL(18, 115, 5), // "score"
QT_MOC_LITERAL(19, 121, 7), // "victory"
QT_MOC_LITERAL(20, 129, 8), // "isRecord"
QT_MOC_LITERAL(21, 138, 12), // "startNewGame"
QT_MOC_LITERAL(22, 151, 7), // "pressOn"
QT_MOC_LITERAL(23, 159, 10) // "getRecords"

    },
    "Logic\0sessionInnitialised\0\0images\0"
    "size\0flipBack\0x1\0y1\0x2\0y2\0flip\0x\0y\0"
    "timeUpdate\0time\0stepsUpdate\0steps\0"
    "scoreUpdate\0score\0victory\0isRecord\0"
    "startNewGame\0pressOn\0getRecords"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    4,   69,    2, 0x06 /* Public */,
      10,    2,   78,    2, 0x06 /* Public */,
      13,    1,   83,    2, 0x06 /* Public */,
      15,    1,   86,    2, 0x06 /* Public */,
      17,    1,   89,    2, 0x06 /* Public */,
      19,    2,   92,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      21,    1,   97,    2, 0x02 /* Public */,
      22,    2,  100,    2, 0x02 /* Public */,
      23,    0,  105,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::QTime,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool,   18,   20,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::QVariant,

       0        // eod
};

void Logic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Logic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sessionInnitialised((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->flipBack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->flip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->timeUpdate((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 4: _t->stepsUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->scoreUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->victory((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->startNewGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->pressOn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { QVariant _r = _t->getRecords();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Logic::*)(QVariant , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::sessionInnitialised)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Logic::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::flipBack)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Logic::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::flip)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Logic::*)(QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::timeUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Logic::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::stepsUpdate)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Logic::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::scoreUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Logic::*)(QVariant , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::victory)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Logic::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Logic.data,
    qt_meta_data_Logic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Logic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Logic.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Logic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Logic::sessionInnitialised(QVariant _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Logic::flipBack(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Logic::flip(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Logic::timeUpdate(QTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Logic::stepsUpdate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Logic::scoreUpdate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Logic::victory(QVariant _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
