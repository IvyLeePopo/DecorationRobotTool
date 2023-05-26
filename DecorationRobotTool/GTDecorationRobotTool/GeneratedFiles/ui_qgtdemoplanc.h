/********************************************************************************
** Form generated from reading UI file 'qgtdemoplanc.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTDEMOPLANC_H
#define UI_QGTDEMOPLANC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTDemoPlanC
{
public:
    QLabel *label_17;
    QLabel *label_RobotPos_W;
    QLabel *label_25;
    QLabel *label_RobotPos_Z;
    QLabel *label_19;
    QLabel *label_RobotPos_U;
    QLabel *label_21;
    QLabel *label_12;
    QLabel *label_RobotPos_X;
    QLabel *label_RobotPos_V;
    QLabel *label_23;
    QLabel *label_RobotPos_Y;

    void setupUi(QWidget *QGTDemoPlanC)
    {
        if (QGTDemoPlanC->objectName().isEmpty())
            QGTDemoPlanC->setObjectName(QStringLiteral("QGTDemoPlanC"));
        QGTDemoPlanC->resize(1024, 590);
        label_17 = new QLabel(QGTDemoPlanC);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 50, 110, 30));
        QFont font;
        font.setPointSize(12);
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_W = new QLabel(QGTDemoPlanC);
        label_RobotPos_W->setObjectName(QStringLiteral("label_RobotPos_W"));
        label_RobotPos_W->setGeometry(QRect(140, 210, 110, 30));
        label_RobotPos_W->setFont(font);
        label_RobotPos_W->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_W->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(QGTDemoPlanC);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 210, 110, 30));
        label_25->setFont(font);
        label_25->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Z = new QLabel(QGTDemoPlanC);
        label_RobotPos_Z->setObjectName(QStringLiteral("label_RobotPos_Z"));
        label_RobotPos_Z->setGeometry(QRect(140, 90, 110, 30));
        label_RobotPos_Z->setFont(font);
        label_RobotPos_Z->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Z->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(QGTDemoPlanC);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 90, 110, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_U = new QLabel(QGTDemoPlanC);
        label_RobotPos_U->setObjectName(QStringLiteral("label_RobotPos_U"));
        label_RobotPos_U->setGeometry(QRect(140, 130, 110, 30));
        label_RobotPos_U->setFont(font);
        label_RobotPos_U->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_U->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(QGTDemoPlanC);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 130, 110, 30));
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_12 = new QLabel(QGTDemoPlanC);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 10, 110, 30));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_X = new QLabel(QGTDemoPlanC);
        label_RobotPos_X->setObjectName(QStringLiteral("label_RobotPos_X"));
        label_RobotPos_X->setGeometry(QRect(140, 10, 110, 30));
        label_RobotPos_X->setFont(font);
        label_RobotPos_X->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_X->setAlignment(Qt::AlignCenter);
        label_RobotPos_V = new QLabel(QGTDemoPlanC);
        label_RobotPos_V->setObjectName(QStringLiteral("label_RobotPos_V"));
        label_RobotPos_V->setGeometry(QRect(140, 170, 110, 30));
        label_RobotPos_V->setFont(font);
        label_RobotPos_V->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_V->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(QGTDemoPlanC);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(20, 170, 110, 30));
        label_23->setFont(font);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Y = new QLabel(QGTDemoPlanC);
        label_RobotPos_Y->setObjectName(QStringLiteral("label_RobotPos_Y"));
        label_RobotPos_Y->setGeometry(QRect(140, 50, 110, 30));
        label_RobotPos_Y->setFont(font);
        label_RobotPos_Y->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Y->setAlignment(Qt::AlignCenter);

        retranslateUi(QGTDemoPlanC);

        QMetaObject::connectSlotsByName(QGTDemoPlanC);
    } // setupUi

    void retranslateUi(QWidget *QGTDemoPlanC)
    {
        QGTDemoPlanC->setWindowTitle(QApplication::translate("QGTDemoPlanC", "QGTDemoPlanC", 0));
        label_17->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Y :", 0));
        label_RobotPos_W->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 W", 0));
        label_25->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 W :", 0));
        label_RobotPos_Z->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Z", 0));
        label_19->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Z :", 0));
        label_RobotPos_U->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 U", 0));
        label_21->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 U :", 0));
        label_12->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 X :", 0));
        label_RobotPos_X->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 X", 0));
        label_RobotPos_V->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 V", 0));
        label_23->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 V :", 0));
        label_RobotPos_Y->setText(QApplication::translate("QGTDemoPlanC", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Y", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTDemoPlanC: public Ui_QGTDemoPlanC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTDEMOPLANC_H
