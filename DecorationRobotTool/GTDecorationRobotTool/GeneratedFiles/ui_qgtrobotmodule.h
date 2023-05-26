/********************************************************************************
** Form generated from reading UI file 'qgtrobotmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTROBOTMODULE_H
#define UI_QGTROBOTMODULE_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTRobotModule
{
public:
    QGTToolButton *toolButton_Robot_PosZ_Down;
    QLabel *label_Robot_JointAngle_Z;
    QLabel *label_25;
    QLabel *label_28;
    QLabel *label;
    QGTToolButton *toolButton_Robot_PosX_Down;
    QLabel *label_Robot_Pos_U;
    QGTToolButton *toolButton_Robot_PosZ_Up;
    QLabel *label_14;
    QLabel *label_Robot_JointAngle_Y;
    QGTToolButton *toolButton_Structure_Test;
    QLabel *label_Robot_JointAngle_U;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_U;
    QGTToolButton *toolButton_Structure_Calibrat;
    QLabel *label_33;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_Z;
    QLabel *label_Robot_Pos_W;
    QLabel *label_9;
    QLabel *label_26;
    QLabel *label_13;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_X;
    QLabel *label_5;
    QLabel *label_Robot_JointAngle_V;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_V;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_Y;
    QLabel *label_Robot_Pos_V;
    QGTToolButton *toolButton_Robot_PosX_Up;
    QLabel *label_Robot_Pos_Y;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_V;
    QLabel *label_31;
    QGTToolButton *toolButton_Robot_MoveTo_TargetPos;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_Z;
    QLabel *label_23;
    QLabel *label_22;
    QGTToolButton *toolButton_Robot_PosY_Up;
    QLabel *label_8;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_Y;
    QLabel *label_20;
    QLabel *label_3;
    QGTToolButton *toolButton_Robot_MoveTo_TargetAngle;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_W;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_U;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_X;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_X;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_X;
    QLabel *label_Robot_Pos_Z;
    QLabel *label_29;
    QLabel *label_32;
    QLabel *label_12;
    QLabel *label_7;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_Y;
    QLabel *label_6;
    QLabel *label_Robot_Pos_X;
    QLabel *label_24;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_Y;
    QLabel *label_17;
    QLabel *label_Robot_JointAngle_W;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_Z;
    QLabel *label_Robot_JointAngle_X;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_Z;
    QLabel *label_27;
    QLabel *label_30;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_21;
    QGTToolButton *toolButton_Robot_RotateRight_Axle_U;
    QGTToolButton *toolButton_Robot_PosY_Down;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_W;
    QGTToolButton *toolButton_Robot_RotateLeft_Axle_V;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetAngle_W;
    QLabel *label_35;
    QDoubleSpinBox *doubleSpinBox_Robot_SpeedRate;
    QDoubleSpinBox *doubleSpinBox_Robot_AccelerationRate;
    QLabel *label_36;
    QLabel *label_34;
    QLabel *label_Robot_Tcp_Force_1;
    QLabel *label_37;
    QLabel *label_Robot_Tcp_Force_2;
    QLabel *label_38;
    QLabel *label_Robot_Tcp_Force_3;
    QLabel *label_39;
    QLabel *label_Robot_Tcp_Force_4;
    QLabel *label_40;
    QTextEdit *textEdit_Robot_State;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_U;
    QLabel *label_41;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_V;
    QLabel *label_42;
    QDoubleSpinBox *doubleSpinBox_Robot_TargetPos_W;
    QLabel *label_43;

    void setupUi(QWidget *QGTRobotModule)
    {
        if (QGTRobotModule->objectName().isEmpty())
            QGTRobotModule->setObjectName(QStringLiteral("QGTRobotModule"));
        QGTRobotModule->resize(1024, 590);
        toolButton_Robot_PosZ_Down = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosZ_Down->setObjectName(QStringLiteral("toolButton_Robot_PosZ_Down"));
        toolButton_Robot_PosZ_Down->setGeometry(QRect(260, 130, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_Robot_PosZ_Down->sizePolicy().hasHeightForWidth());
        toolButton_Robot_PosZ_Down->setSizePolicy(sizePolicy);
        label_Robot_JointAngle_Z = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_Z->setObjectName(QStringLiteral("label_Robot_JointAngle_Z"));
        label_Robot_JointAngle_Z->setGeometry(QRect(120, 420, 80, 30));
        QFont font;
        font.setPointSize(15);
        label_Robot_JointAngle_Z->setFont(font);
        label_Robot_JointAngle_Z->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_Z->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(QGTRobotModule);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(640, 80, 160, 30));
        label_25->setFont(font);
        label_25->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_28 = new QLabel(QGTRobotModule);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(640, 315, 160, 30));
        label_28->setFont(font);
        label_28->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label = new QLabel(QGTRobotModule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 340, 90, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_PosX_Down = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosX_Down->setObjectName(QStringLiteral("toolButton_Robot_PosX_Down"));
        toolButton_Robot_PosX_Down->setGeometry(QRect(480, 50, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_PosX_Down->sizePolicy().hasHeightForWidth());
        toolButton_Robot_PosX_Down->setSizePolicy(sizePolicy);
        label_Robot_Pos_U = new QLabel(QGTRobotModule);
        label_Robot_Pos_U->setObjectName(QStringLiteral("label_Robot_Pos_U"));
        label_Robot_Pos_U->setGeometry(QRect(120, 130, 80, 30));
        label_Robot_Pos_U->setFont(font);
        label_Robot_Pos_U->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_U->setAlignment(Qt::AlignCenter);
        toolButton_Robot_PosZ_Up = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosZ_Up->setObjectName(QStringLiteral("toolButton_Robot_PosZ_Up"));
        toolButton_Robot_PosZ_Up->setGeometry(QRect(260, 20, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_PosZ_Up->sizePolicy().hasHeightForWidth());
        toolButton_Robot_PosZ_Up->setSizePolicy(sizePolicy);
        label_14 = new QLabel(QGTRobotModule);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(220, 50, 30, 30));
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_Y = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_Y->setObjectName(QStringLiteral("label_Robot_JointAngle_Y"));
        label_Robot_JointAngle_Y->setGeometry(QRect(120, 380, 80, 30));
        label_Robot_JointAngle_Y->setFont(font);
        label_Robot_JointAngle_Y->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_Y->setAlignment(Qt::AlignCenter);
        toolButton_Structure_Test = new QGTToolButton(QGTRobotModule);
        toolButton_Structure_Test->setObjectName(QStringLiteral("toolButton_Structure_Test"));
        toolButton_Structure_Test->setGeometry(QRect(830, 530, 150, 60));
        sizePolicy.setHeightForWidth(toolButton_Structure_Test->sizePolicy().hasHeightForWidth());
        toolButton_Structure_Test->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        toolButton_Structure_Test->setFont(font1);
        label_Robot_JointAngle_U = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_U->setObjectName(QStringLiteral("label_Robot_JointAngle_U"));
        label_Robot_JointAngle_U->setGeometry(QRect(120, 460, 80, 30));
        label_Robot_JointAngle_U->setFont(font);
        label_Robot_JointAngle_U->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_U->setAlignment(Qt::AlignCenter);
        toolButton_Robot_RotateLeft_Axle_U = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_U->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_U"));
        toolButton_Robot_RotateLeft_Axle_U->setGeometry(QRect(260, 430, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_U->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_U->setSizePolicy(sizePolicy);
        toolButton_Structure_Calibrat = new QGTToolButton(QGTRobotModule);
        toolButton_Structure_Calibrat->setObjectName(QStringLiteral("toolButton_Structure_Calibrat"));
        toolButton_Structure_Calibrat->setGeometry(QRect(640, 530, 150, 60));
        sizePolicy.setHeightForWidth(toolButton_Structure_Calibrat->sizePolicy().hasHeightForWidth());
        toolButton_Structure_Calibrat->setSizePolicy(sizePolicy);
        toolButton_Structure_Calibrat->setFont(font1);
        label_33 = new QLabel(QGTRobotModule);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(640, 490, 160, 30));
        label_33->setFont(font);
        label_33->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_RotateLeft_Axle_Z = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_Z->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_Z"));
        toolButton_Robot_RotateLeft_Axle_Z->setGeometry(QRect(260, 380, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_Z->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_Z->setSizePolicy(sizePolicy);
        label_Robot_Pos_W = new QLabel(QGTRobotModule);
        label_Robot_Pos_W->setObjectName(QStringLiteral("label_Robot_Pos_W"));
        label_Robot_Pos_W->setGeometry(QRect(120, 210, 80, 30));
        label_Robot_Pos_W->setFont(font);
        label_Robot_Pos_W->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_W->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(QGTRobotModule);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 130, 90, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_26 = new QLabel(QGTRobotModule);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(640, 115, 160, 30));
        label_26->setFont(font);
        label_26->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_13 = new QLabel(QGTRobotModule);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(220, 10, 30, 30));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_RotateRight_Axle_X = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_X->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_X"));
        toolButton_Robot_RotateRight_Axle_X->setGeometry(QRect(320, 280, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_X->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_X->setSizePolicy(sizePolicy);
        label_5 = new QLabel(QGTRobotModule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 500, 90, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_V = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_V->setObjectName(QStringLiteral("label_Robot_JointAngle_V"));
        label_Robot_JointAngle_V->setGeometry(QRect(120, 500, 80, 30));
        label_Robot_JointAngle_V->setFont(font);
        label_Robot_JointAngle_V->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_V = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_V->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_V"));
        doubleSpinBox_Robot_TargetAngle_V->setGeometry(QRect(810, 455, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_V->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_V->setFont(font);
        doubleSpinBox_Robot_TargetAngle_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_V->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_V->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_V->setMaximum(360);
        doubleSpinBox_Robot_TargetPos_Y = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_Y->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_Y"));
        doubleSpinBox_Robot_TargetPos_Y->setGeometry(QRect(810, 115, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_Y->setFont(font);
        doubleSpinBox_Robot_TargetPos_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_Y->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_Y->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_Y->setMaximum(1000);
        label_Robot_Pos_V = new QLabel(QGTRobotModule);
        label_Robot_Pos_V->setObjectName(QStringLiteral("label_Robot_Pos_V"));
        label_Robot_Pos_V->setGeometry(QRect(120, 170, 80, 30));
        label_Robot_Pos_V->setFont(font);
        label_Robot_Pos_V->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_V->setAlignment(Qt::AlignCenter);
        toolButton_Robot_PosX_Up = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosX_Up->setObjectName(QStringLiteral("toolButton_Robot_PosX_Up"));
        toolButton_Robot_PosX_Up->setGeometry(QRect(360, 60, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_PosX_Up->sizePolicy().hasHeightForWidth());
        toolButton_Robot_PosX_Up->setSizePolicy(sizePolicy);
        label_Robot_Pos_Y = new QLabel(QGTRobotModule);
        label_Robot_Pos_Y->setObjectName(QStringLiteral("label_Robot_Pos_Y"));
        label_Robot_Pos_Y->setGeometry(QRect(120, 50, 80, 30));
        label_Robot_Pos_Y->setFont(font);
        label_Robot_Pos_Y->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_Y->setAlignment(Qt::AlignCenter);
        toolButton_Robot_RotateRight_Axle_V = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_V->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_V"));
        toolButton_Robot_RotateRight_Axle_V->setGeometry(QRect(320, 480, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_V->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_V->setSizePolicy(sizePolicy);
        label_31 = new QLabel(QGTRobotModule);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(640, 420, 160, 30));
        label_31->setFont(font);
        label_31->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_MoveTo_TargetPos = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_MoveTo_TargetPos->setObjectName(QStringLiteral("toolButton_Robot_MoveTo_TargetPos"));
        toolButton_Robot_MoveTo_TargetPos->setGeometry(QRect(920, 130, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_MoveTo_TargetPos->sizePolicy().hasHeightForWidth());
        toolButton_Robot_MoveTo_TargetPos->setSizePolicy(sizePolicy);
        label_4 = new QLabel(QGTRobotModule);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 460, 90, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetAngle_Z = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_Z->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_Z"));
        doubleSpinBox_Robot_TargetAngle_Z->setGeometry(QRect(810, 385, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_Z->setFont(font);
        doubleSpinBox_Robot_TargetAngle_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_Z->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_Z->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_Z->setMaximum(360);
        label_23 = new QLabel(QGTRobotModule);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(220, 340, 30, 30));
        label_23->setFont(font);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_22 = new QLabel(QGTRobotModule);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(220, 420, 30, 30));
        label_22->setFont(font);
        label_22->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_PosY_Up = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosY_Up->setObjectName(QStringLiteral("toolButton_Robot_PosY_Up"));
        toolButton_Robot_PosY_Up->setGeometry(QRect(380, 110, 100, 100));
        label_8 = new QLabel(QGTRobotModule);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 90, 30));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_RotateRight_Axle_Y = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_Y->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_Y"));
        toolButton_Robot_RotateRight_Axle_Y->setGeometry(QRect(320, 330, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_Y->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_Y->setSizePolicy(sizePolicy);
        label_20 = new QLabel(QGTRobotModule);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(220, 500, 30, 30));
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTRobotModule);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 420, 90, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_MoveTo_TargetAngle = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_MoveTo_TargetAngle->setObjectName(QStringLiteral("toolButton_Robot_MoveTo_TargetAngle"));
        toolButton_Robot_MoveTo_TargetAngle->setGeometry(QRect(920, 355, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_MoveTo_TargetAngle->sizePolicy().hasHeightForWidth());
        toolButton_Robot_MoveTo_TargetAngle->setSizePolicy(sizePolicy);
        toolButton_Robot_RotateRight_Axle_W = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_W->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_W"));
        toolButton_Robot_RotateRight_Axle_W->setGeometry(QRect(320, 530, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_W->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_W->setSizePolicy(sizePolicy);
        label_18 = new QLabel(QGTRobotModule);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(220, 210, 30, 30));
        label_18->setFont(font);
        label_18->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetAngle_U = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_U->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_U"));
        doubleSpinBox_Robot_TargetAngle_U->setGeometry(QRect(810, 420, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_U->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_U->setFont(font);
        doubleSpinBox_Robot_TargetAngle_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_U->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_U->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_U->setMaximum(360);
        doubleSpinBox_Robot_TargetPos_X = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_X->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_X"));
        doubleSpinBox_Robot_TargetPos_X->setGeometry(QRect(810, 80, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_X->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_X->setFont(font);
        doubleSpinBox_Robot_TargetPos_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_X->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_X->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_X->setMaximum(1000);
        doubleSpinBox_Robot_TargetAngle_X = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_X->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_X"));
        doubleSpinBox_Robot_TargetAngle_X->setGeometry(QRect(810, 315, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_X->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_X->setFont(font);
        doubleSpinBox_Robot_TargetAngle_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_X->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_X->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_X->setMaximum(360);
        toolButton_Robot_RotateLeft_Axle_X = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_X->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_X"));
        toolButton_Robot_RotateLeft_Axle_X->setGeometry(QRect(260, 280, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_X->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_X->setSizePolicy(sizePolicy);
        label_Robot_Pos_Z = new QLabel(QGTRobotModule);
        label_Robot_Pos_Z->setObjectName(QStringLiteral("label_Robot_Pos_Z"));
        label_Robot_Pos_Z->setGeometry(QRect(120, 90, 80, 30));
        label_Robot_Pos_Z->setFont(font);
        label_Robot_Pos_Z->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_Z->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(QGTRobotModule);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(640, 350, 160, 30));
        label_29->setFont(font);
        label_29->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_32 = new QLabel(QGTRobotModule);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(640, 455, 160, 30));
        label_32->setFont(font);
        label_32->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_12 = new QLabel(QGTRobotModule);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 50, 90, 30));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7 = new QLabel(QGTRobotModule);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 210, 90, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_RotateLeft_Axle_Y = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_Y->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_Y"));
        toolButton_Robot_RotateLeft_Axle_Y->setGeometry(QRect(260, 330, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_Y->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_Y->setSizePolicy(sizePolicy);
        label_6 = new QLabel(QGTRobotModule);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 540, 90, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_X = new QLabel(QGTRobotModule);
        label_Robot_Pos_X->setObjectName(QStringLiteral("label_Robot_Pos_X"));
        label_Robot_Pos_X->setGeometry(QRect(120, 10, 80, 30));
        label_Robot_Pos_X->setFont(font);
        label_Robot_Pos_X->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Pos_X->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(QGTRobotModule);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(220, 540, 30, 30));
        label_24->setFont(font);
        label_24->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_19 = new QLabel(QGTRobotModule);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(220, 380, 30, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetAngle_Y = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_Y->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_Y"));
        doubleSpinBox_Robot_TargetAngle_Y->setGeometry(QRect(810, 350, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_Y->setFont(font);
        doubleSpinBox_Robot_TargetAngle_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_Y->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_Y->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_Y->setMaximum(360);
        label_17 = new QLabel(QGTRobotModule);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(220, 170, 30, 30));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_W = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_W->setObjectName(QStringLiteral("label_Robot_JointAngle_W"));
        label_Robot_JointAngle_W->setGeometry(QRect(120, 540, 80, 30));
        label_Robot_JointAngle_W->setFont(font);
        label_Robot_JointAngle_W->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_W->setAlignment(Qt::AlignCenter);
        toolButton_Robot_RotateRight_Axle_Z = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_Z->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_Z"));
        toolButton_Robot_RotateRight_Axle_Z->setGeometry(QRect(320, 380, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_Z->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_Z->setSizePolicy(sizePolicy);
        label_Robot_JointAngle_X = new QLabel(QGTRobotModule);
        label_Robot_JointAngle_X->setObjectName(QStringLiteral("label_Robot_JointAngle_X"));
        label_Robot_JointAngle_X->setGeometry(QRect(120, 340, 80, 30));
        label_Robot_JointAngle_X->setFont(font);
        label_Robot_JointAngle_X->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_JointAngle_X->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(QGTRobotModule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 380, 90, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetPos_Z = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_Z->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_Z"));
        doubleSpinBox_Robot_TargetPos_Z->setGeometry(QRect(810, 150, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_Z->setFont(font);
        doubleSpinBox_Robot_TargetPos_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_Z->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_Z->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_Z->setMaximum(1000);
        label_27 = new QLabel(QGTRobotModule);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(640, 150, 160, 30));
        label_27->setFont(font);
        label_27->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_30 = new QLabel(QGTRobotModule);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(640, 385, 160, 30));
        label_30->setFont(font);
        label_30->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10 = new QLabel(QGTRobotModule);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 170, 90, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_15 = new QLabel(QGTRobotModule);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(220, 90, 30, 30));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_11 = new QLabel(QGTRobotModule);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 90, 90, 30));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_16 = new QLabel(QGTRobotModule);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(220, 130, 30, 30));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_21 = new QLabel(QGTRobotModule);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(220, 460, 30, 30));
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_Robot_RotateRight_Axle_U = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateRight_Axle_U->setObjectName(QStringLiteral("toolButton_Robot_RotateRight_Axle_U"));
        toolButton_Robot_RotateRight_Axle_U->setGeometry(QRect(320, 430, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateRight_Axle_U->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateRight_Axle_U->setSizePolicy(sizePolicy);
        toolButton_Robot_PosY_Down = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_PosY_Down->setObjectName(QStringLiteral("toolButton_Robot_PosY_Down"));
        toolButton_Robot_PosY_Down->setGeometry(QRect(460, 0, 100, 100));
        sizePolicy.setHeightForWidth(toolButton_Robot_PosY_Down->sizePolicy().hasHeightForWidth());
        toolButton_Robot_PosY_Down->setSizePolicy(sizePolicy);
        toolButton_Robot_RotateLeft_Axle_W = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_W->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_W"));
        toolButton_Robot_RotateLeft_Axle_W->setGeometry(QRect(260, 530, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_W->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_W->setSizePolicy(sizePolicy);
        toolButton_Robot_RotateLeft_Axle_V = new QGTToolButton(QGTRobotModule);
        toolButton_Robot_RotateLeft_Axle_V->setObjectName(QStringLiteral("toolButton_Robot_RotateLeft_Axle_V"));
        toolButton_Robot_RotateLeft_Axle_V->setGeometry(QRect(260, 480, 50, 50));
        sizePolicy.setHeightForWidth(toolButton_Robot_RotateLeft_Axle_V->sizePolicy().hasHeightForWidth());
        toolButton_Robot_RotateLeft_Axle_V->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_W = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetAngle_W->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetAngle_W"));
        doubleSpinBox_Robot_TargetAngle_W->setGeometry(QRect(810, 490, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetAngle_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetAngle_W->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetAngle_W->setFont(font);
        doubleSpinBox_Robot_TargetAngle_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetAngle_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetAngle_W->setDecimals(3);
        doubleSpinBox_Robot_TargetAngle_W->setMinimum(-360);
        doubleSpinBox_Robot_TargetAngle_W->setMaximum(360);
        label_35 = new QLabel(QGTRobotModule);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(640, 0, 160, 30));
        label_35->setFont(font);
        label_35->setStyleSheet(QLatin1String("color: rgb(85, 170, 255);\n"
"border-style: solid"));
        doubleSpinBox_Robot_SpeedRate = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_SpeedRate->setObjectName(QStringLiteral("doubleSpinBox_Robot_SpeedRate"));
        doubleSpinBox_Robot_SpeedRate->setGeometry(QRect(810, 0, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_SpeedRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_SpeedRate->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        doubleSpinBox_Robot_SpeedRate->setFont(font2);
        doubleSpinBox_Robot_SpeedRate->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_SpeedRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_SpeedRate->setDecimals(1);
        doubleSpinBox_Robot_SpeedRate->setMaximum(200);
        doubleSpinBox_Robot_AccelerationRate = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_AccelerationRate->setObjectName(QStringLiteral("doubleSpinBox_Robot_AccelerationRate"));
        doubleSpinBox_Robot_AccelerationRate->setGeometry(QRect(810, 35, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_AccelerationRate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_AccelerationRate->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_AccelerationRate->setFont(font2);
        doubleSpinBox_Robot_AccelerationRate->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_AccelerationRate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_AccelerationRate->setDecimals(3);
        label_36 = new QLabel(QGTRobotModule);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(640, 35, 160, 30));
        label_36->setFont(font);
        label_36->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_34 = new QLabel(QGTRobotModule);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(400, 390, 200, 30));
        label_34->setFont(font);
        label_34->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_1 = new QLabel(QGTRobotModule);
        label_Robot_Tcp_Force_1->setObjectName(QStringLiteral("label_Robot_Tcp_Force_1"));
        label_Robot_Tcp_Force_1->setGeometry(QRect(490, 430, 100, 30));
        label_Robot_Tcp_Force_1->setFont(font);
        label_Robot_Tcp_Force_1->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_1->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(QGTRobotModule);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(420, 430, 70, 30));
        label_37->setFont(font);
        label_37->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_2 = new QLabel(QGTRobotModule);
        label_Robot_Tcp_Force_2->setObjectName(QStringLiteral("label_Robot_Tcp_Force_2"));
        label_Robot_Tcp_Force_2->setGeometry(QRect(490, 470, 100, 30));
        label_Robot_Tcp_Force_2->setFont(font);
        label_Robot_Tcp_Force_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_2->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(QGTRobotModule);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(420, 470, 70, 30));
        label_38->setFont(font);
        label_38->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_3 = new QLabel(QGTRobotModule);
        label_Robot_Tcp_Force_3->setObjectName(QStringLiteral("label_Robot_Tcp_Force_3"));
        label_Robot_Tcp_Force_3->setGeometry(QRect(490, 510, 100, 30));
        label_Robot_Tcp_Force_3->setFont(font);
        label_Robot_Tcp_Force_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_3->setAlignment(Qt::AlignCenter);
        label_39 = new QLabel(QGTRobotModule);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(420, 510, 70, 30));
        label_39->setFont(font);
        label_39->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_4 = new QLabel(QGTRobotModule);
        label_Robot_Tcp_Force_4->setObjectName(QStringLiteral("label_Robot_Tcp_Force_4"));
        label_Robot_Tcp_Force_4->setGeometry(QRect(490, 550, 100, 30));
        label_Robot_Tcp_Force_4->setFont(font);
        label_Robot_Tcp_Force_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Robot_Tcp_Force_4->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(QGTRobotModule);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(420, 550, 70, 30));
        label_40->setFont(font);
        label_40->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        textEdit_Robot_State = new QTextEdit(QGTRobotModule);
        textEdit_Robot_State->setObjectName(QStringLiteral("textEdit_Robot_State"));
        textEdit_Robot_State->setGeometry(QRect(390, 240, 200, 150));
        sizePolicy.setHeightForWidth(textEdit_Robot_State->sizePolicy().hasHeightForWidth());
        textEdit_Robot_State->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_U = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_U->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_U"));
        doubleSpinBox_Robot_TargetPos_U->setGeometry(QRect(810, 185, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_U->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_U->setFont(font);
        doubleSpinBox_Robot_TargetPos_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_U->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_U->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_U->setMaximum(1000);
        label_41 = new QLabel(QGTRobotModule);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(640, 185, 160, 30));
        label_41->setFont(font);
        label_41->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetPos_V = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_V->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_V"));
        doubleSpinBox_Robot_TargetPos_V->setGeometry(QRect(810, 220, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_V->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_V->setFont(font);
        doubleSpinBox_Robot_TargetPos_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_V->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_V->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_V->setMaximum(1000);
        label_42 = new QLabel(QGTRobotModule);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(640, 220, 160, 30));
        label_42->setFont(font);
        label_42->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_Robot_TargetPos_W = new QDoubleSpinBox(QGTRobotModule);
        doubleSpinBox_Robot_TargetPos_W->setObjectName(QStringLiteral("doubleSpinBox_Robot_TargetPos_W"));
        doubleSpinBox_Robot_TargetPos_W->setGeometry(QRect(810, 255, 100, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_Robot_TargetPos_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Robot_TargetPos_W->setSizePolicy(sizePolicy);
        doubleSpinBox_Robot_TargetPos_W->setFont(font);
        doubleSpinBox_Robot_TargetPos_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_Robot_TargetPos_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Robot_TargetPos_W->setDecimals(3);
        doubleSpinBox_Robot_TargetPos_W->setMinimum(-1000);
        doubleSpinBox_Robot_TargetPos_W->setMaximum(1000);
        label_43 = new QLabel(QGTRobotModule);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(640, 255, 160, 30));
        label_43->setFont(font);
        label_43->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        retranslateUi(QGTRobotModule);

        QMetaObject::connectSlotsByName(QGTRobotModule);
    } // setupUi

    void retranslateUi(QWidget *QGTRobotModule)
    {
        QGTRobotModule->setWindowTitle(QApplication::translate("QGTRobotModule", "QGTRobotModule", 0));
        toolButton_Robot_PosZ_Down->setText(QApplication::translate("QGTRobotModule", "Z--", 0));
        label_Robot_JointAngle_Z->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_25->setText(QApplication::translate("QGTRobotModule", "Target  Pos  X :", 0));
        label_28->setText(QApplication::translate("QGTRobotModule", "Target Angle X :", 0));
        label->setText(QApplication::translate("QGTRobotModule", "Angle X :", 0));
        toolButton_Robot_PosX_Down->setText(QApplication::translate("QGTRobotModule", "X--", 0));
        label_Robot_Pos_U->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        toolButton_Robot_PosZ_Up->setText(QApplication::translate("QGTRobotModule", "Z++", 0));
        label_14->setText(QApplication::translate("QGTRobotModule", "mm", 0));
        label_Robot_JointAngle_Y->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        toolButton_Structure_Test->setText(QApplication::translate("QGTRobotModule", "Test", 0));
        label_Robot_JointAngle_U->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        toolButton_Structure_Calibrat->setText(QApplication::translate("QGTRobotModule", "Calibrat", 0));
        label_33->setText(QApplication::translate("QGTRobotModule", "Target Angle W :", 0));
        label_Robot_Pos_W->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_9->setText(QApplication::translate("QGTRobotModule", "Pos   U :", 0));
        label_26->setText(QApplication::translate("QGTRobotModule", "Target  Pos  Y :", 0));
        label_13->setText(QApplication::translate("QGTRobotModule", "mm", 0));
        label_5->setText(QApplication::translate("QGTRobotModule", "Angle V :", 0));
        label_Robot_JointAngle_V->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_Robot_Pos_V->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        toolButton_Robot_PosX_Up->setText(QApplication::translate("QGTRobotModule", "X++", 0));
        label_Robot_Pos_Y->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_31->setText(QApplication::translate("QGTRobotModule", "Target Angle U :", 0));
        toolButton_Robot_MoveTo_TargetPos->setText(QString());
        label_4->setText(QApplication::translate("QGTRobotModule", "Angle U :", 0));
        label_23->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        label_22->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        toolButton_Robot_PosY_Up->setText(QApplication::translate("QGTRobotModule", "Y++", 0));
        label_8->setText(QApplication::translate("QGTRobotModule", "Pos   X :", 0));
        label_20->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        label_3->setText(QApplication::translate("QGTRobotModule", "Angle Z :", 0));
        toolButton_Robot_MoveTo_TargetAngle->setText(QString());
        label_18->setText(QApplication::translate("QGTRobotModule", "rad", 0));
        label_Robot_Pos_Z->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_29->setText(QApplication::translate("QGTRobotModule", "Target Angle Y :", 0));
        label_32->setText(QApplication::translate("QGTRobotModule", "Target Angle V :", 0));
        label_12->setText(QApplication::translate("QGTRobotModule", "Pos   Y :", 0));
        label_7->setText(QApplication::translate("QGTRobotModule", "Pos   W :", 0));
        label_6->setText(QApplication::translate("QGTRobotModule", "Angle W :", 0));
        label_Robot_Pos_X->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_24->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        label_19->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        label_17->setText(QApplication::translate("QGTRobotModule", "rad", 0));
        label_Robot_JointAngle_W->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_Robot_JointAngle_X->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_2->setText(QApplication::translate("QGTRobotModule", "Angle Y :", 0));
        label_27->setText(QApplication::translate("QGTRobotModule", "Target  Pos  Z :", 0));
        label_30->setText(QApplication::translate("QGTRobotModule", "Target Angle Z :", 0));
        label_10->setText(QApplication::translate("QGTRobotModule", "Pos   V :", 0));
        label_15->setText(QApplication::translate("QGTRobotModule", "mm", 0));
        label_11->setText(QApplication::translate("QGTRobotModule", "Pos   Z :", 0));
        label_16->setText(QApplication::translate("QGTRobotModule", "rad", 0));
        label_21->setText(QApplication::translate("QGTRobotModule", "\302\260", 0));
        toolButton_Robot_PosY_Down->setText(QApplication::translate("QGTRobotModule", "Y--", 0));
        label_35->setText(QApplication::translate("QGTRobotModule", "Speed          :", 0));
        label_36->setText(QApplication::translate("QGTRobotModule", "Acceleration   :", 0));
        label_34->setText(QApplication::translate("QGTRobotModule", "Tcp Pressure Force", 0));
        label_Robot_Tcp_Force_1->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_37->setText(QApplication::translate("QGTRobotModule", "CH 1 :", 0));
        label_Robot_Tcp_Force_2->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_38->setText(QApplication::translate("QGTRobotModule", "CH 2 :", 0));
        label_Robot_Tcp_Force_3->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_39->setText(QApplication::translate("QGTRobotModule", "CH 3 :", 0));
        label_Robot_Tcp_Force_4->setText(QApplication::translate("QGTRobotModule", "NULL", 0));
        label_40->setText(QApplication::translate("QGTRobotModule", "CH 4 :", 0));
        label_41->setText(QApplication::translate("QGTRobotModule", "Target  Pos  U :", 0));
        label_42->setText(QApplication::translate("QGTRobotModule", "Target  Pos  V :", 0));
        label_43->setText(QApplication::translate("QGTRobotModule", "Target  Pos  W :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTRobotModule: public Ui_QGTRobotModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTROBOTMODULE_H
