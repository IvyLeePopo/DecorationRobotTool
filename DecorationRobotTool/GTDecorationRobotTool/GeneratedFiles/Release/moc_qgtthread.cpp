/****************************************************************************
** Meta object code from reading C++ file 'qgtthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Commen/qgtthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgtthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGTThread_t {
    QByteArrayData data[9];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGTThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGTThread_t qt_meta_stringdata_QGTThread = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 22),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 18),
QT_MOC_LITERAL(4, 53, 20),
QT_MOC_LITERAL(5, 74, 17),
QT_MOC_LITERAL(6, 92, 17),
QT_MOC_LITERAL(7, 110, 24),
QT_MOC_LITERAL(8, 135, 21)
    },
    "QGTThread\0LineFollow_Info_Output\0\0"
    "Chasis_Info_Output\0LiftPlat_Info_Output\0"
    "Robot_Info_Output\0Lidar_Info_Output\0"
    "LaserMeasure_Info_Output\0JoyHandle_Info_Output"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGTThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGTThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGTThread *_t = static_cast<QGTThread *>(_o);
        switch (_id) {
        case 0: _t->LineFollow_Info_Output(); break;
        case 1: _t->Chasis_Info_Output(); break;
        case 2: _t->LiftPlat_Info_Output(); break;
        case 3: _t->Robot_Info_Output(); break;
        case 4: _t->Lidar_Info_Output(); break;
        case 5: _t->LaserMeasure_Info_Output(); break;
        case 6: _t->JoyHandle_Info_Output(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::LineFollow_Info_Output)) {
                *result = 0;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::Chasis_Info_Output)) {
                *result = 1;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::LiftPlat_Info_Output)) {
                *result = 2;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::Robot_Info_Output)) {
                *result = 3;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::Lidar_Info_Output)) {
                *result = 4;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::LaserMeasure_Info_Output)) {
                *result = 5;
            }
        }
        {
            typedef void (QGTThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGTThread::JoyHandle_Info_Output)) {
                *result = 6;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QGTThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QGTThread.data,
      qt_meta_data_QGTThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *QGTThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGTThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGTThread.stringdata))
        return static_cast<void*>(const_cast< QGTThread*>(this));
    return QThread::qt_metacast(_clname);
}

int QGTThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QGTThread::LineFollow_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QGTThread::Chasis_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QGTThread::LiftPlat_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QGTThread::Robot_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QGTThread::Lidar_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QGTThread::LaserMeasure_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QGTThread::JoyHandle_Info_Output()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
