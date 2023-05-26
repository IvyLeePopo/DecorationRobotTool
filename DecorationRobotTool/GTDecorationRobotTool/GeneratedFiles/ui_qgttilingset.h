/********************************************************************************
** Form generated from reading UI file 'qgttilingset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTTILINGSET_H
#define UI_QGTTILINGSET_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTTilingSet
{
public:
    QGTToolButton *toolButton_TilingSet_Reset;
    QGTToolButton *toolButton_TilingSet_Cancel;
    QGTToolButton *toolButton_TilingSet_Ok;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_U;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_Y;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_Z;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_X;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_W;
    QLabel *label_14;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitPos_V;
    QLabel *label_24;
    QLabel *label_25;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_V;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_Z;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_W;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_Y;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_U;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitPos_X;
    QLabel *label_8;
    QLabel *label_20;
    QGTToolButton *toolButton_TilingSet_Material_InitPos_Read;
    QGTToolButton *toolButton_TilingSet_Paste_InitPos_Read;
    QSpinBox *spinBox_TilingSet_Pressure;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_Width;
    QLabel *label_27;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_Thickness;
    QLabel *label_28;
    QGTToolButton *toolButton_TilingSet_InitPos_Read;
    QLabel *label_29;
    QLabel *label_30;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_X;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_Z;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_U;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_Y;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_V;
    QDoubleSpinBox *doubleSpinBox_TilingSet_InitPos_W;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_Feed;
    QLabel *label_31;
    QSpinBox *spinBox_TilingSet_Material_Num;
    QLabel *label_19;
    QLabel *label_32;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_V;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_X;
    QLabel *label_33;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_Y;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_Z;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_W;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Material_InitAngle_U;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_X;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_Z;
    QLabel *label_41;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_U;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_Y;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_V;
    QDoubleSpinBox *doubleSpinBox_TilingSet_Paste_InitAngle_W;

    void setupUi(QWidget *QGTTilingSet)
    {
        if (QGTTilingSet->objectName().isEmpty())
            QGTTilingSet->setObjectName(QStringLiteral("QGTTilingSet"));
        QGTTilingSet->resize(850, 750);
        QGTTilingSet->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        toolButton_TilingSet_Reset = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_Reset->setObjectName(QStringLiteral("toolButton_TilingSet_Reset"));
        toolButton_TilingSet_Reset->setGeometry(QRect(10, 690, 100, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_TilingSet_Reset->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_Reset->setSizePolicy(sizePolicy);
        toolButton_TilingSet_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_TilingSet_Cancel = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_Cancel->setObjectName(QStringLiteral("toolButton_TilingSet_Cancel"));
        toolButton_TilingSet_Cancel->setGeometry(QRect(740, 690, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_TilingSet_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_Cancel->setSizePolicy(sizePolicy);
        toolButton_TilingSet_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_TilingSet_Ok = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_Ok->setObjectName(QStringLiteral("toolButton_TilingSet_Ok"));
        toolButton_TilingSet_Ok->setGeometry(QRect(630, 690, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_TilingSet_Ok->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_Ok->setSizePolicy(sizePolicy);
        toolButton_TilingSet_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_U = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_U->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_U"));
        doubleSpinBox_TilingSet_Material_InitPos_U->setGeometry(QRect(410, 155, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_U->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        doubleSpinBox_TilingSet_Material_InitPos_U->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_U->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_U->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_U->setMaximum(1000);
        label_7 = new QLabel(QGTTilingSet);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 85, 130, 30));
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitPos_Y = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_Y"));
        doubleSpinBox_TilingSet_Material_InitPos_Y->setGeometry(QRect(410, 85, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);\n"
""));
        doubleSpinBox_TilingSet_Material_InitPos_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_Y->setMaximum(1000);
        label_10 = new QLabel(QGTTilingSet);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 225, 130, 30));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitPos_Z = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_Z"));
        doubleSpinBox_TilingSet_Material_InitPos_Z->setGeometry(QRect(410, 120, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_Z->setMaximum(1000);
        label_11 = new QLabel(QGTTilingSet);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 120, 130, 30));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitPos_X = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_X->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_X"));
        doubleSpinBox_TilingSet_Material_InitPos_X->setGeometry(QRect(410, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_X->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitPos_X->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_X->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_X->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_X->setMaximum(1000);
        doubleSpinBox_TilingSet_Material_InitPos_W = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_W->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_W"));
        doubleSpinBox_TilingSet_Material_InitPos_W->setGeometry(QRect(410, 225, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_W->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitPos_W->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_W->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_W->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_W->setMaximum(1000);
        label_14 = new QLabel(QGTTilingSet);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(280, 155, 130, 30));
        label_14->setFont(font1);
        label_14->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_23 = new QLabel(QGTTilingSet);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(280, 50, 130, 30));
        label_23->setFont(font1);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitPos_V = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitPos_V->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitPos_V"));
        doubleSpinBox_TilingSet_Material_InitPos_V->setGeometry(QRect(410, 190, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitPos_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitPos_V->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitPos_V->setFont(font);
        doubleSpinBox_TilingSet_Material_InitPos_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitPos_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitPos_V->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitPos_V->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitPos_V->setMaximum(1000);
        label_24 = new QLabel(QGTTilingSet);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(280, 190, 130, 30));
        label_24->setFont(font1);
        label_24->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_25 = new QLabel(QGTTilingSet);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(590, 190, 130, 30));
        label_25->setFont(font1);
        label_25->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitPos_V = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_V"));
        doubleSpinBox_TilingSet_Paste_InitPos_V->setGeometry(QRect(720, 190, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_V->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_V->setMaximum(1000);
        doubleSpinBox_TilingSet_Paste_InitPos_Z = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_Z"));
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setGeometry(QRect(720, 120, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_Z->setMaximum(1000);
        label_12 = new QLabel(QGTTilingSet);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(590, 225, 130, 30));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitPos_W = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_W"));
        doubleSpinBox_TilingSet_Paste_InitPos_W->setGeometry(QRect(720, 225, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_W->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_W->setMaximum(1000);
        label_16 = new QLabel(QGTTilingSet);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(590, 155, 130, 30));
        label_16->setFont(font1);
        label_16->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitPos_Y = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_Y"));
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setGeometry(QRect(720, 85, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_Y->setMaximum(1000);
        label_26 = new QLabel(QGTTilingSet);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(590, 50, 130, 30));
        label_26->setFont(font1);
        label_26->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitPos_U = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_U"));
        doubleSpinBox_TilingSet_Paste_InitPos_U->setGeometry(QRect(720, 155, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_U->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_U->setMaximum(1000);
        doubleSpinBox_TilingSet_Paste_InitPos_X = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitPos_X"));
        doubleSpinBox_TilingSet_Paste_InitPos_X->setGeometry(QRect(720, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitPos_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitPos_X->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitPos_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitPos_X->setMaximum(1000);
        label_8 = new QLabel(QGTTilingSet);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(590, 85, 130, 30));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_20 = new QLabel(QGTTilingSet);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(590, 120, 130, 30));
        label_20->setFont(font1);
        label_20->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_TilingSet_Material_InitPos_Read = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_Material_InitPos_Read->setObjectName(QStringLiteral("toolButton_TilingSet_Material_InitPos_Read"));
        toolButton_TilingSet_Material_InitPos_Read->setGeometry(QRect(310, 10, 180, 30));
        sizePolicy.setHeightForWidth(toolButton_TilingSet_Material_InitPos_Read->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_Material_InitPos_Read->setSizePolicy(sizePolicy);
        toolButton_TilingSet_Material_InitPos_Read->setFont(font1);
        toolButton_TilingSet_Material_InitPos_Read->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_TilingSet_Paste_InitPos_Read = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_Paste_InitPos_Read->setObjectName(QStringLiteral("toolButton_TilingSet_Paste_InitPos_Read"));
        toolButton_TilingSet_Paste_InitPos_Read->setGeometry(QRect(620, 10, 180, 30));
        sizePolicy.setHeightForWidth(toolButton_TilingSet_Paste_InitPos_Read->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_Paste_InitPos_Read->setSizePolicy(sizePolicy);
        toolButton_TilingSet_Paste_InitPos_Read->setFont(font1);
        toolButton_TilingSet_Paste_InitPos_Read->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_TilingSet_Pressure = new QSpinBox(QGTTilingSet);
        spinBox_TilingSet_Pressure->setObjectName(QStringLiteral("spinBox_TilingSet_Pressure"));
        spinBox_TilingSet_Pressure->setGeometry(QRect(380, 590, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_TilingSet_Pressure->sizePolicy().hasHeightForWidth());
        spinBox_TilingSet_Pressure->setSizePolicy(sizePolicy);
        spinBox_TilingSet_Pressure->setFont(font);
        spinBox_TilingSet_Pressure->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_TilingSet_Pressure->setAlignment(Qt::AlignCenter);
        spinBox_TilingSet_Pressure->setMaximum(3000);
        label_9 = new QLabel(QGTTilingSet);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(280, 590, 100, 30));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_Width = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_Width->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_Width"));
        doubleSpinBox_TilingSet_Material_Width->setGeometry(QRect(110, 540, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_Width->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_Width->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_Width->setFont(font);
        doubleSpinBox_TilingSet_Material_Width->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_Width->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_Width->setDecimals(3);
        doubleSpinBox_TilingSet_Material_Width->setMinimum(0);
        doubleSpinBox_TilingSet_Material_Width->setMaximum(1000);
        label_27 = new QLabel(QGTTilingSet);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 540, 100, 30));
        label_27->setFont(font1);
        label_27->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_Thickness = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_Thickness->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_Thickness"));
        doubleSpinBox_TilingSet_Material_Thickness->setGeometry(QRect(110, 590, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_Thickness->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_Thickness->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_Thickness->setFont(font);
        doubleSpinBox_TilingSet_Material_Thickness->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_Thickness->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_Thickness->setDecimals(3);
        doubleSpinBox_TilingSet_Material_Thickness->setMinimum(0);
        doubleSpinBox_TilingSet_Material_Thickness->setMaximum(1000);
        label_28 = new QLabel(QGTTilingSet);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 590, 100, 30));
        label_28->setFont(font1);
        label_28->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_TilingSet_InitPos_Read = new QGTToolButton(QGTTilingSet);
        toolButton_TilingSet_InitPos_Read->setObjectName(QStringLiteral("toolButton_TilingSet_InitPos_Read"));
        toolButton_TilingSet_InitPos_Read->setGeometry(QRect(30, 10, 180, 30));
        sizePolicy.setHeightForWidth(toolButton_TilingSet_InitPos_Read->sizePolicy().hasHeightForWidth());
        toolButton_TilingSet_InitPos_Read->setSizePolicy(sizePolicy);
        toolButton_TilingSet_InitPos_Read->setFont(font1);
        toolButton_TilingSet_InitPos_Read->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        label_29 = new QLabel(QGTTilingSet);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(10, 190, 100, 30));
        label_29->setFont(font1);
        label_29->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_30 = new QLabel(QGTTilingSet);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(10, 50, 100, 30));
        label_30->setFont(font1);
        label_30->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_InitPos_X = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_X->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_X"));
        doubleSpinBox_TilingSet_InitPos_X->setGeometry(QRect(110, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_X->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_X->setFont(font);
        doubleSpinBox_TilingSet_InitPos_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_InitPos_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_X->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_X->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_X->setMaximum(1000);
        doubleSpinBox_TilingSet_InitPos_Z = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_Z->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_Z"));
        doubleSpinBox_TilingSet_InitPos_Z->setGeometry(QRect(110, 120, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_Z->setFont(font);
        doubleSpinBox_TilingSet_InitPos_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_InitPos_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_Z->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_Z->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_Z->setMaximum(1000);
        doubleSpinBox_TilingSet_InitPos_U = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_U->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_U"));
        doubleSpinBox_TilingSet_InitPos_U->setGeometry(QRect(110, 155, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_U->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_U->setFont(font);
        doubleSpinBox_TilingSet_InitPos_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_InitPos_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_U->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_U->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_U->setMaximum(1000);
        doubleSpinBox_TilingSet_InitPos_Y = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_Y->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_Y"));
        doubleSpinBox_TilingSet_InitPos_Y->setGeometry(QRect(110, 85, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_Y->setFont(font);
        doubleSpinBox_TilingSet_InitPos_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);\n"
""));
        doubleSpinBox_TilingSet_InitPos_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_Y->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_Y->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_Y->setMaximum(1000);
        label_15 = new QLabel(QGTTilingSet);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 155, 100, 30));
        label_15->setFont(font1);
        label_15->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_InitPos_V = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_V->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_V"));
        doubleSpinBox_TilingSet_InitPos_V->setGeometry(QRect(110, 190, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_V->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_V->setFont(font);
        doubleSpinBox_TilingSet_InitPos_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_InitPos_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_V->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_V->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_V->setMaximum(1000);
        doubleSpinBox_TilingSet_InitPos_W = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_InitPos_W->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_InitPos_W"));
        doubleSpinBox_TilingSet_InitPos_W->setGeometry(QRect(110, 225, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_InitPos_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_InitPos_W->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_InitPos_W->setFont(font);
        doubleSpinBox_TilingSet_InitPos_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_InitPos_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_InitPos_W->setDecimals(3);
        doubleSpinBox_TilingSet_InitPos_W->setMinimum(-1000);
        doubleSpinBox_TilingSet_InitPos_W->setMaximum(1000);
        label_13 = new QLabel(QGTTilingSet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 120, 100, 30));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_17 = new QLabel(QGTTilingSet);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 225, 100, 30));
        label_17->setFont(font1);
        label_17->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_18 = new QLabel(QGTTilingSet);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 85, 100, 30));
        label_18->setFont(font1);
        label_18->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_Feed = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_Feed->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_Feed"));
        doubleSpinBox_TilingSet_Paste_Feed->setGeometry(QRect(110, 640, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_Feed->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_Feed->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_Feed->setFont(font);
        doubleSpinBox_TilingSet_Paste_Feed->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_Feed->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_Feed->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_Feed->setMinimum(0);
        doubleSpinBox_TilingSet_Paste_Feed->setMaximum(1000);
        label_31 = new QLabel(QGTTilingSet);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 640, 100, 30));
        label_31->setFont(font1);
        label_31->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_TilingSet_Material_Num = new QSpinBox(QGTTilingSet);
        spinBox_TilingSet_Material_Num->setObjectName(QStringLiteral("spinBox_TilingSet_Material_Num"));
        spinBox_TilingSet_Material_Num->setGeometry(QRect(380, 540, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_TilingSet_Material_Num->sizePolicy().hasHeightForWidth());
        spinBox_TilingSet_Material_Num->setSizePolicy(sizePolicy);
        spinBox_TilingSet_Material_Num->setFont(font);
        spinBox_TilingSet_Material_Num->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_TilingSet_Material_Num->setAlignment(Qt::AlignCenter);
        spinBox_TilingSet_Material_Num->setMaximum(3000);
        label_19 = new QLabel(QGTTilingSet);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(280, 540, 100, 30));
        label_19->setFont(font1);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_32 = new QLabel(QGTTilingSet);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(280, 415, 130, 30));
        label_32->setFont(font1);
        label_32->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_21 = new QLabel(QGTTilingSet);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(280, 450, 130, 30));
        label_21->setFont(font1);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitAngle_V = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_V"));
        doubleSpinBox_TilingSet_Material_InitAngle_V->setGeometry(QRect(410, 415, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_V->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitAngle_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_V->setMaximum(1000);
        label_22 = new QLabel(QGTTilingSet);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(280, 310, 130, 30));
        label_22->setFont(font1);
        label_22->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitAngle_X = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_X"));
        doubleSpinBox_TilingSet_Material_InitAngle_X->setGeometry(QRect(410, 275, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_X->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitAngle_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_X->setMaximum(1000);
        label_33 = new QLabel(QGTTilingSet);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(280, 275, 130, 30));
        label_33->setFont(font1);
        label_33->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Material_InitAngle_Y = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_Y"));
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setGeometry(QRect(410, 310, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);\n"
""));
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_Y->setMaximum(1000);
        doubleSpinBox_TilingSet_Material_InitAngle_Z = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_Z"));
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setGeometry(QRect(410, 345, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_Z->setMaximum(1000);
        doubleSpinBox_TilingSet_Material_InitAngle_W = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_W"));
        doubleSpinBox_TilingSet_Material_InitAngle_W->setGeometry(QRect(410, 450, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_W->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitAngle_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_W->setMaximum(1000);
        doubleSpinBox_TilingSet_Material_InitAngle_U = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Material_InitAngle_U"));
        doubleSpinBox_TilingSet_Material_InitAngle_U->setGeometry(QRect(410, 380, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Material_InitAngle_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Material_InitAngle_U->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setFont(font);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Material_InitAngle_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setDecimals(3);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setMinimum(-1000);
        doubleSpinBox_TilingSet_Material_InitAngle_U->setMaximum(1000);
        label_34 = new QLabel(QGTTilingSet);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(280, 345, 130, 30));
        label_34->setFont(font1);
        label_34->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_35 = new QLabel(QGTTilingSet);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(280, 380, 130, 30));
        label_35->setFont(font1);
        label_35->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_36 = new QLabel(QGTTilingSet);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(590, 345, 130, 30));
        label_36->setFont(font1);
        label_36->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_X = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_X"));
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setGeometry(QRect(720, 275, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_X->setMaximum(1000);
        label_37 = new QLabel(QGTTilingSet);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(590, 275, 130, 30));
        label_37->setFont(font1);
        label_37->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_38 = new QLabel(QGTTilingSet);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(590, 380, 130, 30));
        label_38->setFont(font1);
        label_38->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_39 = new QLabel(QGTTilingSet);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(590, 310, 130, 30));
        label_39->setFont(font1);
        label_39->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_40 = new QLabel(QGTTilingSet);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(590, 415, 130, 30));
        label_40->setFont(font1);
        label_40->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_Z = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_Z"));
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setGeometry(QRect(720, 345, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_Z->setMaximum(1000);
        label_41 = new QLabel(QGTTilingSet);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(590, 450, 130, 30));
        label_41->setFont(font1);
        label_41->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_U = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_U"));
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setGeometry(QRect(720, 380, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_U->setMaximum(1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_Y"));
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setGeometry(QRect(720, 310, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_Y->setMaximum(1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_V = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_V"));
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setGeometry(QRect(720, 415, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_V->setMaximum(1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_W = new QDoubleSpinBox(QGTTilingSet);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setObjectName(QStringLiteral("doubleSpinBox_TilingSet_Paste_InitAngle_W"));
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setGeometry(QRect(720, 450, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_TilingSet_Paste_InitAngle_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setSizePolicy(sizePolicy);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setFont(font);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setDecimals(3);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setMinimum(-1000);
        doubleSpinBox_TilingSet_Paste_InitAngle_W->setMaximum(1000);

        retranslateUi(QGTTilingSet);

        QMetaObject::connectSlotsByName(QGTTilingSet);
    } // setupUi

    void retranslateUi(QWidget *QGTTilingSet)
    {
        QGTTilingSet->setWindowTitle(QApplication::translate("QGTTilingSet", "QGTTilingSet", 0));
        toolButton_TilingSet_Reset->setText(QApplication::translate("QGTTilingSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        toolButton_TilingSet_Cancel->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\266\210", 0));
        toolButton_TilingSet_Ok->setText(QApplication::translate("QGTTilingSet", "\344\277\235\345\255\230", 0));
        label_7->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 Y :", 0));
        label_10->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 W :", 0));
        label_11->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 Z :", 0));
        label_14->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 U :", 0));
        label_23->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 X :", 0));
        label_24->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256 V :", 0));
        label_25->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 V :", 0));
        label_12->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 W :", 0));
        label_16->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 U :", 0));
        label_26->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 X :", 0));
        label_8->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 Y :", 0));
        label_20->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256 Z :", 0));
        toolButton_TilingSet_Material_InitPos_Read->setText(QApplication::translate("QGTTilingSet", "\350\257\273\345\217\226\345\217\226\346\226\231\345\210\235\345\247\213\344\275\215\347\275\256", 0));
        toolButton_TilingSet_Paste_InitPos_Read->setText(QApplication::translate("QGTTilingSet", "\350\257\273\345\217\226\347\262\230\350\264\264\345\210\235\345\247\213\344\275\215\347\275\256", 0));
        label_9->setText(QApplication::translate("QGTTilingSet", "\346\234\253\347\253\257\345\216\213\345\212\233\345\200\274 :", 0));
        label_27->setText(QApplication::translate("QGTTilingSet", "\347\223\267\347\240\226\345\256\275\345\272\246\345\200\274 :", 0));
        label_28->setText(QApplication::translate("QGTTilingSet", "\347\223\267\347\240\226\345\216\232\345\272\246\345\200\274 :", 0));
        toolButton_TilingSet_InitPos_Read->setText(QApplication::translate("QGTTilingSet", "\350\257\273\345\217\226\345\210\235\345\247\213\344\275\215\347\275\256", 0));
        label_29->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 V :", 0));
        label_30->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 X :", 0));
        label_15->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 U :", 0));
        label_13->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 Z :", 0));
        label_17->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 W :", 0));
        label_18->setText(QApplication::translate("QGTTilingSet", "\345\210\235\345\247\213\344\275\215\347\275\256 Y :", 0));
        label_31->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\350\277\233\347\273\231\351\207\217 :", 0));
        label_19->setText(QApplication::translate("QGTTilingSet", "\347\223\267\347\240\226\346\225\260\351\207\217\345\200\274 :", 0));
        label_32->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 V :", 0));
        label_21->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 W :", 0));
        label_22->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 Y :", 0));
        label_33->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 X :", 0));
        label_34->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 Z :", 0));
        label_35->setText(QApplication::translate("QGTTilingSet", "\345\217\226\346\226\231\345\210\235\345\247\213\350\247\222\345\272\246 U :", 0));
        label_36->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 Z :", 0));
        label_37->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 X :", 0));
        label_38->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 U :", 0));
        label_39->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 Y :", 0));
        label_40->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 V :", 0));
        label_41->setText(QApplication::translate("QGTTilingSet", "\347\262\230\350\264\264\345\210\235\345\247\213\350\247\222\345\272\246 W :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTTilingSet: public Ui_QGTTilingSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTTILINGSET_H
