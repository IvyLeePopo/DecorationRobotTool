/********************************************************************************
** Form generated from reading UI file 'qgtchasismodule.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTCHASISMODULE_H
#define UI_QGTCHASISMODULE_H

#include <Commen/qgtchasiswheelview.h>
#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTChasisModule
{
public:
    QLabel *label_12;
    QLabel *label_Chasis_LeftWheel_Dis;
    QLabel *label_Chasis_RightWheel_Angle;
    QLabel *label_22;
    QGTToolButton *toolButton_Chasis_Move_Left;
    QSpinBox *spinBox_Chasis_TargetSpeed_LeftWheel;
    QLabel *label_Chasis_LeftWheel_Speed;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_19;
    QLabel *label_4;
    QSpinBox *spinBox_Chasis_TargetSpeed_RightWheel;
    QLabel *label_Chasis_RightWheel_Speed;
    QGTToolButton *toolButton_Chasis_Stop;
    QLabel *label_23;
    QSpinBox *spinBox_Chasis_TargetAngle_RightWheel;
    QGTToolButton *toolButton_Chasis_Move_Forward;
    QLabel *label_5;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_6;
    QGTToolButton *toolButton_Chasis_Move_Rotate_Right;
    QGTToolButton *toolButton_Chasis_Move_Right;
    QLabel *label_7;
    QLabel *label_24;
    QLabel *label_9;
    QLabel *label_10;
    QGTToolButton *toolButton_Chasis_Move_Rotate_Left;
    QLabel *label_Chasis_RightWheel_Dis;
    QLabel *label_11;
    QSpinBox *spinBox_Chasis_TargetAngle_LeftWheel;
    QLabel *label_Chasis_LeftWheel_Angle;
    QGTToolButton *toolButton_Chasis_Move_Rotate;
    QGTToolButton *toolButton_Chasis_Move_Backoff;
    QLabel *label_ChasisFrame;
    QGTChasisWheelView *label_Chasis_LeftWheel;
    QGTChasisWheelView *label_Chasis_RightWheel;
    QGTToolButton *toolButton_Chasis_LinkRod_Down;
    QGTToolButton *toolButton_Chasis_LinkRod_Up;
    QGTToolButton *toolButton_Chasis_Electromagnet_Off;
    QGTToolButton *toolButton_Chasis_Electromagnet_On;

    void setupUi(QWidget *QGTChasisModule)
    {
        if (QGTChasisModule->objectName().isEmpty())
            QGTChasisModule->setObjectName(QStringLiteral("QGTChasisModule"));
        QGTChasisModule->resize(1024, 590);
        label_12 = new QLabel(QGTChasisModule);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(250, 390, 100, 30));
        QFont font;
        font.setPointSize(12);
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Chasis_LeftWheel_Dis = new QLabel(QGTChasisModule);
        label_Chasis_LeftWheel_Dis->setObjectName(QStringLiteral("label_Chasis_LeftWheel_Dis"));
        label_Chasis_LeftWheel_Dis->setGeometry(QRect(360, 80, 50, 30));
        label_Chasis_LeftWheel_Dis->setFont(font);
        label_Chasis_LeftWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Chasis_RightWheel_Angle = new QLabel(QGTChasisModule);
        label_Chasis_RightWheel_Angle->setObjectName(QStringLiteral("label_Chasis_RightWheel_Angle"));
        label_Chasis_RightWheel_Angle->setGeometry(QRect(360, 120, 50, 30));
        label_Chasis_RightWheel_Angle->setFont(font);
        label_Chasis_RightWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_22 = new QLabel(QGTChasisModule);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(410, 80, 30, 30));
        label_22->setFont(font);
        label_22->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Left = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Left->setObjectName(QStringLiteral("toolButton_Chasis_Move_Left"));
        toolButton_Chasis_Move_Left->setGeometry(QRect(710, 110, 100, 100));
        toolButton_Chasis_Move_Left->setStyleSheet(QStringLiteral("border-style: solid"));
        spinBox_Chasis_TargetSpeed_LeftWheel = new QSpinBox(QGTChasisModule);
        spinBox_Chasis_TargetSpeed_LeftWheel->setObjectName(QStringLiteral("spinBox_Chasis_TargetSpeed_LeftWheel"));
        spinBox_Chasis_TargetSpeed_LeftWheel->setGeometry(QRect(380, 270, 100, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox_Chasis_TargetSpeed_LeftWheel->sizePolicy().hasHeightForWidth());
        spinBox_Chasis_TargetSpeed_LeftWheel->setSizePolicy(sizePolicy);
        spinBox_Chasis_TargetSpeed_LeftWheel->setFont(font);
        spinBox_Chasis_TargetSpeed_LeftWheel->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetSpeed_LeftWheel->setAlignment(Qt::AlignCenter);
        label_Chasis_LeftWheel_Speed = new QLabel(QGTChasisModule);
        label_Chasis_LeftWheel_Speed->setObjectName(QStringLiteral("label_Chasis_LeftWheel_Speed"));
        label_Chasis_LeftWheel_Speed->setGeometry(QRect(360, 40, 50, 30));
        label_Chasis_LeftWheel_Speed->setFont(font);
        label_Chasis_LeftWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_2 = new QLabel(QGTChasisModule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 0, 100, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTChasisModule);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 40, 100, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_19 = new QLabel(QGTChasisModule);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(410, 40, 50, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_4 = new QLabel(QGTChasisModule);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 80, 100, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetSpeed_RightWheel = new QSpinBox(QGTChasisModule);
        spinBox_Chasis_TargetSpeed_RightWheel->setObjectName(QStringLiteral("spinBox_Chasis_TargetSpeed_RightWheel"));
        spinBox_Chasis_TargetSpeed_RightWheel->setGeometry(QRect(380, 310, 100, 30));
        sizePolicy.setHeightForWidth(spinBox_Chasis_TargetSpeed_RightWheel->sizePolicy().hasHeightForWidth());
        spinBox_Chasis_TargetSpeed_RightWheel->setSizePolicy(sizePolicy);
        spinBox_Chasis_TargetSpeed_RightWheel->setFont(font);
        spinBox_Chasis_TargetSpeed_RightWheel->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetSpeed_RightWheel->setAlignment(Qt::AlignCenter);
        label_Chasis_RightWheel_Speed = new QLabel(QGTChasisModule);
        label_Chasis_RightWheel_Speed->setObjectName(QStringLiteral("label_Chasis_RightWheel_Speed"));
        label_Chasis_RightWheel_Speed->setGeometry(QRect(360, 160, 50, 30));
        label_Chasis_RightWheel_Speed->setFont(font);
        label_Chasis_RightWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Chasis_Stop = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Stop->setObjectName(QStringLiteral("toolButton_Chasis_Stop"));
        toolButton_Chasis_Stop->setGeometry(QRect(810, 110, 100, 100));
        toolButton_Chasis_Stop->setStyleSheet(QStringLiteral("border-style: solid"));
        label_23 = new QLabel(QGTChasisModule);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(410, 0, 30, 30));
        label_23->setFont(font);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetAngle_RightWheel = new QSpinBox(QGTChasisModule);
        spinBox_Chasis_TargetAngle_RightWheel->setObjectName(QStringLiteral("spinBox_Chasis_TargetAngle_RightWheel"));
        spinBox_Chasis_TargetAngle_RightWheel->setGeometry(QRect(380, 390, 100, 30));
        sizePolicy.setHeightForWidth(spinBox_Chasis_TargetAngle_RightWheel->sizePolicy().hasHeightForWidth());
        spinBox_Chasis_TargetAngle_RightWheel->setSizePolicy(sizePolicy);
        spinBox_Chasis_TargetAngle_RightWheel->setFont(font);
        spinBox_Chasis_TargetAngle_RightWheel->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetAngle_RightWheel->setAlignment(Qt::AlignCenter);
        spinBox_Chasis_TargetAngle_RightWheel->setMinimum(10);
        spinBox_Chasis_TargetAngle_RightWheel->setMaximum(349);
        toolButton_Chasis_Move_Forward = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Forward->setObjectName(QStringLiteral("toolButton_Chasis_Move_Forward"));
        toolButton_Chasis_Move_Forward->setGeometry(QRect(810, 10, 100, 100));
        toolButton_Chasis_Move_Forward->setStyleSheet(QStringLiteral("border-style: solid"));
        label_5 = new QLabel(QGTChasisModule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 120, 100, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_20 = new QLabel(QGTChasisModule);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(410, 160, 50, 30));
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_21 = new QLabel(QGTChasisModule);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(410, 120, 30, 30));
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_6 = new QLabel(QGTChasisModule);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 160, 100, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Rotate_Right = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Rotate_Right->setObjectName(QStringLiteral("toolButton_Chasis_Move_Rotate_Right"));
        toolButton_Chasis_Move_Rotate_Right->setGeometry(QRect(140, 480, 100, 100));
        toolButton_Chasis_Move_Rotate_Right->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Right = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Right->setObjectName(QStringLiteral("toolButton_Chasis_Move_Right"));
        toolButton_Chasis_Move_Right->setGeometry(QRect(910, 110, 100, 100));
        toolButton_Chasis_Move_Right->setStyleSheet(QStringLiteral("border-style: solid"));
        label_7 = new QLabel(QGTChasisModule);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(250, 200, 100, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_24 = new QLabel(QGTChasisModule);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(410, 200, 30, 30));
        label_24->setFont(font);
        label_24->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_9 = new QLabel(QGTChasisModule);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(250, 270, 100, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10 = new QLabel(QGTChasisModule);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(250, 350, 100, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Rotate_Left = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Rotate_Left->setObjectName(QStringLiteral("toolButton_Chasis_Move_Rotate_Left"));
        toolButton_Chasis_Move_Rotate_Left->setGeometry(QRect(270, 480, 100, 100));
        toolButton_Chasis_Move_Rotate_Left->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        label_Chasis_RightWheel_Dis = new QLabel(QGTChasisModule);
        label_Chasis_RightWheel_Dis->setObjectName(QStringLiteral("label_Chasis_RightWheel_Dis"));
        label_Chasis_RightWheel_Dis->setGeometry(QRect(360, 200, 50, 30));
        label_Chasis_RightWheel_Dis->setFont(font);
        label_Chasis_RightWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_11 = new QLabel(QGTChasisModule);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(250, 310, 100, 30));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetAngle_LeftWheel = new QSpinBox(QGTChasisModule);
        spinBox_Chasis_TargetAngle_LeftWheel->setObjectName(QStringLiteral("spinBox_Chasis_TargetAngle_LeftWheel"));
        spinBox_Chasis_TargetAngle_LeftWheel->setGeometry(QRect(380, 350, 100, 30));
        sizePolicy.setHeightForWidth(spinBox_Chasis_TargetAngle_LeftWheel->sizePolicy().hasHeightForWidth());
        spinBox_Chasis_TargetAngle_LeftWheel->setSizePolicy(sizePolicy);
        spinBox_Chasis_TargetAngle_LeftWheel->setFont(font);
        spinBox_Chasis_TargetAngle_LeftWheel->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Chasis_TargetAngle_LeftWheel->setAlignment(Qt::AlignCenter);
        spinBox_Chasis_TargetAngle_LeftWheel->setMinimum(10);
        spinBox_Chasis_TargetAngle_LeftWheel->setMaximum(349);
        spinBox_Chasis_TargetAngle_LeftWheel->setValue(10);
        label_Chasis_LeftWheel_Angle = new QLabel(QGTChasisModule);
        label_Chasis_LeftWheel_Angle->setObjectName(QStringLiteral("label_Chasis_LeftWheel_Angle"));
        label_Chasis_LeftWheel_Angle->setGeometry(QRect(360, 0, 50, 30));
        label_Chasis_LeftWheel_Angle->setFont(font);
        label_Chasis_LeftWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Rotate = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Rotate->setObjectName(QStringLiteral("toolButton_Chasis_Move_Rotate"));
        toolButton_Chasis_Move_Rotate->setGeometry(QRect(10, 480, 100, 100));
        toolButton_Chasis_Move_Rotate->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        toolButton_Chasis_Move_Backoff = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Move_Backoff->setObjectName(QStringLiteral("toolButton_Chasis_Move_Backoff"));
        toolButton_Chasis_Move_Backoff->setGeometry(QRect(810, 210, 100, 100));
        toolButton_Chasis_Move_Backoff->setStyleSheet(QStringLiteral("border-style: solid"));
        label_ChasisFrame = new QLabel(QGTChasisModule);
        label_ChasisFrame->setObjectName(QStringLiteral("label_ChasisFrame"));
        label_ChasisFrame->setGeometry(QRect(0, 0, 240, 420));
        label_ChasisFrame->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/ChasisFrame.png);"));
        label_Chasis_LeftWheel = new QGTChasisWheelView(QGTChasisModule);
        label_Chasis_LeftWheel->setObjectName(QStringLiteral("label_Chasis_LeftWheel"));
        label_Chasis_LeftWheel->setGeometry(QRect(60, 50, 120, 120));
        sizePolicy.setHeightForWidth(label_Chasis_LeftWheel->sizePolicy().hasHeightForWidth());
        label_Chasis_LeftWheel->setSizePolicy(sizePolicy);
        label_Chasis_LeftWheel->setFrameShape(QFrame::NoFrame);
        label_Chasis_RightWheel = new QGTChasisWheelView(QGTChasisModule);
        label_Chasis_RightWheel->setObjectName(QStringLiteral("label_Chasis_RightWheel"));
        label_Chasis_RightWheel->setGeometry(QRect(60, 250, 120, 120));
        sizePolicy.setHeightForWidth(label_Chasis_RightWheel->sizePolicy().hasHeightForWidth());
        label_Chasis_RightWheel->setSizePolicy(sizePolicy);
        label_Chasis_RightWheel->setFrameShape(QFrame::NoFrame);
        toolButton_Chasis_LinkRod_Down = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_LinkRod_Down->setObjectName(QStringLiteral("toolButton_Chasis_LinkRod_Down"));
        toolButton_Chasis_LinkRod_Down->setGeometry(QRect(590, 480, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Chasis_LinkRod_Down->sizePolicy().hasHeightForWidth());
        toolButton_Chasis_LinkRod_Down->setSizePolicy(sizePolicy);
        toolButton_Chasis_LinkRod_Down->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        toolButton_Chasis_LinkRod_Up = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_LinkRod_Up->setObjectName(QStringLiteral("toolButton_Chasis_LinkRod_Up"));
        toolButton_Chasis_LinkRod_Up->setGeometry(QRect(460, 480, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Chasis_LinkRod_Up->sizePolicy().hasHeightForWidth());
        toolButton_Chasis_LinkRod_Up->setSizePolicy(sizePolicy);
        toolButton_Chasis_LinkRod_Up->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        toolButton_Chasis_Electromagnet_Off = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Electromagnet_Off->setObjectName(QStringLiteral("toolButton_Chasis_Electromagnet_Off"));
        toolButton_Chasis_Electromagnet_Off->setGeometry(QRect(910, 480, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Chasis_Electromagnet_Off->sizePolicy().hasHeightForWidth());
        toolButton_Chasis_Electromagnet_Off->setSizePolicy(sizePolicy);
        toolButton_Chasis_Electromagnet_Off->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        toolButton_Chasis_Electromagnet_On = new QGTToolButton(QGTChasisModule);
        toolButton_Chasis_Electromagnet_On->setObjectName(QStringLiteral("toolButton_Chasis_Electromagnet_On"));
        toolButton_Chasis_Electromagnet_On->setGeometry(QRect(780, 480, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Chasis_Electromagnet_On->sizePolicy().hasHeightForWidth());
        toolButton_Chasis_Electromagnet_On->setSizePolicy(sizePolicy);
        toolButton_Chasis_Electromagnet_On->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));

        retranslateUi(QGTChasisModule);

        QMetaObject::connectSlotsByName(QGTChasisModule);
    } // setupUi

    void retranslateUi(QWidget *QGTChasisModule)
    {
        QGTChasisModule->setWindowTitle(QApplication::translate("QGTChasisModule", "QGTChasisModule", 0));
        label_12->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256\347\233\256\346\240\207\350\247\222\345\272\246", 0));
        label_Chasis_LeftWheel_Dis->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        label_Chasis_RightWheel_Angle->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        label_22->setText(QApplication::translate("QGTChasisModule", "mm", 0));
        toolButton_Chasis_Move_Left->setText(QApplication::translate("QGTChasisModule", "\345\267\246", 0));
        label_Chasis_LeftWheel_Speed->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        label_2->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256\345\275\223\345\211\215\350\247\222\345\272\246", 0));
        label_3->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256\345\275\223\345\211\215\351\200\237\345\272\246", 0));
        label_19->setText(QApplication::translate("QGTChasisModule", "rad/s", 0));
        label_4->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256\345\275\223\345\211\215\350\241\214\347\250\213", 0));
        label_Chasis_RightWheel_Speed->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        toolButton_Chasis_Stop->setText(QApplication::translate("QGTChasisModule", "Stop", 0));
        label_23->setText(QApplication::translate("QGTChasisModule", "\302\260", 0));
        toolButton_Chasis_Move_Forward->setText(QApplication::translate("QGTChasisModule", "\344\270\212", 0));
        label_5->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256\345\275\223\345\211\215\350\247\222\345\272\246", 0));
        label_20->setText(QApplication::translate("QGTChasisModule", "rad/s", 0));
        label_21->setText(QApplication::translate("QGTChasisModule", "\302\260", 0));
        label_6->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256\345\275\223\345\211\215\351\200\237\345\272\246", 0));
        toolButton_Chasis_Move_Rotate_Right->setText(QApplication::translate("QGTChasisModule", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\254", 0));
        toolButton_Chasis_Move_Right->setText(QApplication::translate("QGTChasisModule", "\345\217\263", 0));
        label_7->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256\345\275\223\345\211\215\350\241\214\347\250\213", 0));
        label_24->setText(QApplication::translate("QGTChasisModule", "mm", 0));
        label_9->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256\347\233\256\346\240\207\351\200\237\345\272\246", 0));
        label_10->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256\347\233\256\346\240\207\350\247\222\345\272\246", 0));
        toolButton_Chasis_Move_Rotate_Left->setText(QApplication::translate("QGTChasisModule", "\351\200\206\346\227\266\351\222\210\346\227\213\350\275\254", 0));
        label_Chasis_RightWheel_Dis->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        label_11->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256\347\233\256\346\240\207\351\200\237\345\272\246", 0));
        label_Chasis_LeftWheel_Angle->setText(QApplication::translate("QGTChasisModule", "NULL", 0));
        toolButton_Chasis_Move_Rotate->setText(QApplication::translate("QGTChasisModule", "Rotate", 0));
        toolButton_Chasis_Move_Backoff->setText(QApplication::translate("QGTChasisModule", "\344\270\213", 0));
        label_ChasisFrame->setText(QApplication::translate("QGTChasisModule", "TextLabel", 0));
        label_Chasis_LeftWheel->setText(QApplication::translate("QGTChasisModule", "\345\267\246\350\275\256", 0));
        label_Chasis_RightWheel->setText(QApplication::translate("QGTChasisModule", "\345\217\263\350\275\256", 0));
        toolButton_Chasis_LinkRod_Down->setText(QApplication::translate("QGTChasisModule", "\350\277\236\346\235\206 Down", 0));
        toolButton_Chasis_LinkRod_Up->setText(QApplication::translate("QGTChasisModule", "\350\277\236\346\235\206 Up", 0));
        toolButton_Chasis_Electromagnet_Off->setText(QApplication::translate("QGTChasisModule", "\347\224\265\347\243\201\351\223\201 Off", 0));
        toolButton_Chasis_Electromagnet_On->setText(QApplication::translate("QGTChasisModule", "\347\224\265\347\243\201\351\223\201 On", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTChasisModule: public Ui_QGTChasisModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTCHASISMODULE_H
