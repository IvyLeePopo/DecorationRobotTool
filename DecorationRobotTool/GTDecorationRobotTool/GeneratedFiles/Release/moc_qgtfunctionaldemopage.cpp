/****************************************************************************
** Meta object code from reading C++ file 'qgtfunctionaldemopage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qgtfunctionaldemopage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgtfunctionaldemopage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGTFunctionalDemoPage_t {
    QByteArrayData data[13];
    char stringdata[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGTFunctionalDemoPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGTFunctionalDemoPage_t qt_meta_stringdata_QGTFunctionalDemoPage = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 38),
QT_MOC_LITERAL(2, 61, 0),
QT_MOC_LITERAL(3, 62, 38),
QT_MOC_LITERAL(4, 101, 38),
QT_MOC_LITERAL(5, 140, 38),
QT_MOC_LITERAL(6, 179, 38),
QT_MOC_LITERAL(7, 218, 38),
QT_MOC_LITERAL(8, 257, 21),
QT_MOC_LITERAL(9, 279, 20),
QT_MOC_LITERAL(10, 300, 20),
QT_MOC_LITERAL(11, 321, 27),
QT_MOC_LITERAL(12, 349, 25)
    },
    "QGTFunctionalDemoPage\0"
    "on_toolButton_SelectDemoPlan_A_pressed\0"
    "\0on_toolButton_SelectDemoPlan_B_pressed\0"
    "on_toolButton_SelectDemoPlan_C_pressed\0"
    "on_toolButton_SelectDemoPlan_D_pressed\0"
    "on_toolButton_SelectDemoPlan_E_pressed\0"
    "on_toolButton_SelectDemoPlan_F_pressed\0"
    "on_Chasis_Info_Output\0on_Robot_Info_Output\0"
    "on_Lidar_Info_Output\0on_LaserMeasure_Info_Output\0"
    "on_LineFollow_Info_Output"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGTFunctionalDemoPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGTFunctionalDemoPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGTFunctionalDemoPage *_t = static_cast<QGTFunctionalDemoPage *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_SelectDemoPlan_A_pressed(); break;
        case 1: _t->on_toolButton_SelectDemoPlan_B_pressed(); break;
        case 2: _t->on_toolButton_SelectDemoPlan_C_pressed(); break;
        case 3: _t->on_toolButton_SelectDemoPlan_D_pressed(); break;
        case 4: _t->on_toolButton_SelectDemoPlan_E_pressed(); break;
        case 5: _t->on_toolButton_SelectDemoPlan_F_pressed(); break;
        case 6: _t->on_Chasis_Info_Output(); break;
        case 7: _t->on_Robot_Info_Output(); break;
        case 8: _t->on_Lidar_Info_Output(); break;
        case 9: _t->on_LaserMeasure_Info_Output(); break;
        case 10: _t->on_LineFollow_Info_Output(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QGTFunctionalDemoPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QGTFunctionalDemoPage.data,
      qt_meta_data_QGTFunctionalDemoPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *QGTFunctionalDemoPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGTFunctionalDemoPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGTFunctionalDemoPage.stringdata))
        return static_cast<void*>(const_cast< QGTFunctionalDemoPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int QGTFunctionalDemoPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
