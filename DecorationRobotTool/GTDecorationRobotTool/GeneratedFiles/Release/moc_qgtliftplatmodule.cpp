/****************************************************************************
** Meta object code from reading C++ file 'qgtliftplatmodule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qgtliftplatmodule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgtliftplatmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGTLiftPlatModule_t {
    QByteArrayData data[9];
    char stringdata[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGTLiftPlatModule_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGTLiftPlatModule_t qt_meta_stringdata_QGTLiftPlatModule = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 37),
QT_MOC_LITERAL(2, 56, 0),
QT_MOC_LITERAL(3, 57, 39),
QT_MOC_LITERAL(4, 97, 35),
QT_MOC_LITERAL(5, 133, 41),
QT_MOC_LITERAL(6, 175, 6),
QT_MOC_LITERAL(7, 182, 33),
QT_MOC_LITERAL(8, 216, 32)
    },
    "QGTLiftPlatModule\0"
    "on_toolButton_LiftPlat_MoveUp_pressed\0"
    "\0on_toolButton_LiftPlat_MoveDown_pressed\0"
    "on_toolButton_LiftPlat_Stop_pressed\0"
    "on_spinBox_Motor_TargetSpeed_valueChanged\0"
    "iValue\0Update_ActualInfo_LiftPlat_Normal\0"
    "Update_ActualInfo_LiftPlat_Other"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGTLiftPlatModule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGTLiftPlatModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGTLiftPlatModule *_t = static_cast<QGTLiftPlatModule *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_LiftPlat_MoveUp_pressed(); break;
        case 1: _t->on_toolButton_LiftPlat_MoveDown_pressed(); break;
        case 2: _t->on_toolButton_LiftPlat_Stop_pressed(); break;
        case 3: _t->on_spinBox_Motor_TargetSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Update_ActualInfo_LiftPlat_Normal(); break;
        case 5: _t->Update_ActualInfo_LiftPlat_Other(); break;
        default: ;
        }
    }
}

const QMetaObject QGTLiftPlatModule::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QGTLiftPlatModule.data,
      qt_meta_data_QGTLiftPlatModule,  qt_static_metacall, 0, 0}
};


const QMetaObject *QGTLiftPlatModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGTLiftPlatModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGTLiftPlatModule.stringdata))
        return static_cast<void*>(const_cast< QGTLiftPlatModule*>(this));
    return QWidget::qt_metacast(_clname);
}

int QGTLiftPlatModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
