/****************************************************************************
** Meta object code from reading C++ file 'qgtdemoplanset.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qgtdemoplanset.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgtdemoplanset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGTDemoPlanSet_t {
    QByteArrayData data[7];
    char stringdata[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGTDemoPlanSet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGTDemoPlanSet_t qt_meta_stringdata_QGTDemoPlanSet = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 36),
QT_MOC_LITERAL(2, 52, 0),
QT_MOC_LITERAL(3, 53, 40),
QT_MOC_LITERAL(4, 94, 39),
QT_MOC_LITERAL(5, 134, 50),
QT_MOC_LITERAL(6, 185, 6)
    },
    "QGTDemoPlanSet\0on_toolButton_DemoPlanSet_Ok_pressed\0"
    "\0on_toolButton_DemoPlanSet_Cancel_pressed\0"
    "on_toolButton_DemoPlanSet_Reset_pressed\0"
    "on_comboBox_DemoPlanSet_Select_currentIndexChanged\0"
    "iValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGTDemoPlanSet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void QGTDemoPlanSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGTDemoPlanSet *_t = static_cast<QGTDemoPlanSet *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_DemoPlanSet_Ok_pressed(); break;
        case 1: _t->on_toolButton_DemoPlanSet_Cancel_pressed(); break;
        case 2: _t->on_toolButton_DemoPlanSet_Reset_pressed(); break;
        case 3: _t->on_comboBox_DemoPlanSet_Select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QGTDemoPlanSet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QGTDemoPlanSet.data,
      qt_meta_data_QGTDemoPlanSet,  qt_static_metacall, 0, 0}
};


const QMetaObject *QGTDemoPlanSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGTDemoPlanSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGTDemoPlanSet.stringdata))
        return static_cast<void*>(const_cast< QGTDemoPlanSet*>(this));
    return QWidget::qt_metacast(_clname);
}

int QGTDemoPlanSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
