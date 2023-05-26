/********************************************************************************
** Form generated from reading UI file 'qgtdrawlineset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTDRAWLINESET_H
#define UI_QGTDRAWLINESET_H

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

class Ui_QGTDrawLineSet
{
public:
    QLabel *label;
    QGTToolButton *toolButton_DrawLineSet_Ok;
    QGTToolButton *toolButton_DrawLineSet_Reset;
    QGTToolButton *toolButton_DrawLineSet_Cancel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_X;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_Y;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_Z;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_U;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_V;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_InitPos_W;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_topLeft_X;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_topLeft_Y;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_topLeft_Z;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_Width;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_DrawLineSet_Height;
    QLabel *label_11;
    QSpinBox *spinBox_DrawLineSet_LiftPlat_bottomPos;
    QLabel *label_12;
    QSpinBox *spinBox_DrawLineSet_LiftPlat_topPos;
    QLabel *label_13;

    void setupUi(QWidget *QGTDrawLineSet)
    {
        if (QGTDrawLineSet->objectName().isEmpty())
            QGTDrawLineSet->setObjectName(QStringLiteral("QGTDrawLineSet"));
        QGTDrawLineSet->resize(600, 400);
        QGTDrawLineSet->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        label = new QLabel(QGTDrawLineSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 130, 30));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_DrawLineSet_Ok = new QGTToolButton(QGTDrawLineSet);
        toolButton_DrawLineSet_Ok->setObjectName(QStringLiteral("toolButton_DrawLineSet_Ok"));
        toolButton_DrawLineSet_Ok->setGeometry(QRect(380, 340, 100, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_DrawLineSet_Ok->sizePolicy().hasHeightForWidth());
        toolButton_DrawLineSet_Ok->setSizePolicy(sizePolicy);
        toolButton_DrawLineSet_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_DrawLineSet_Reset = new QGTToolButton(QGTDrawLineSet);
        toolButton_DrawLineSet_Reset->setObjectName(QStringLiteral("toolButton_DrawLineSet_Reset"));
        toolButton_DrawLineSet_Reset->setGeometry(QRect(10, 340, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_DrawLineSet_Reset->sizePolicy().hasHeightForWidth());
        toolButton_DrawLineSet_Reset->setSizePolicy(sizePolicy);
        toolButton_DrawLineSet_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_DrawLineSet_Cancel = new QGTToolButton(QGTDrawLineSet);
        toolButton_DrawLineSet_Cancel->setObjectName(QStringLiteral("toolButton_DrawLineSet_Cancel"));
        toolButton_DrawLineSet_Cancel->setGeometry(QRect(490, 340, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_DrawLineSet_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_DrawLineSet_Cancel->setSizePolicy(sizePolicy);
        toolButton_DrawLineSet_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        label_2 = new QLabel(QGTDrawLineSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 130, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTDrawLineSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 130, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_4 = new QLabel(QGTDrawLineSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 130, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_5 = new QLabel(QGTDrawLineSet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 170, 130, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_6 = new QLabel(QGTDrawLineSet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 210, 130, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_DrawLineSet_InitPos_X = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_X->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_X"));
        doubleSpinBox_DrawLineSet_InitPos_X->setGeometry(QRect(160, 10, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_X->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        doubleSpinBox_DrawLineSet_InitPos_X->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_X->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_X->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_X->setMaximum(1000);
        doubleSpinBox_DrawLineSet_InitPos_Y = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_Y->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_Y"));
        doubleSpinBox_DrawLineSet_InitPos_Y->setGeometry(QRect(160, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_InitPos_Y->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_Y->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_Y->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_Y->setMaximum(1000);
        doubleSpinBox_DrawLineSet_InitPos_Z = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_Z->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_Z"));
        doubleSpinBox_DrawLineSet_InitPos_Z->setGeometry(QRect(160, 90, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_InitPos_Z->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_Z->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_Z->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_Z->setMaximum(1000);
        doubleSpinBox_DrawLineSet_InitPos_U = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_U->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_U"));
        doubleSpinBox_DrawLineSet_InitPos_U->setGeometry(QRect(160, 130, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_U->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_U->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_InitPos_U->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_U->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_U->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_U->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_U->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_U->setMaximum(1000);
        doubleSpinBox_DrawLineSet_InitPos_V = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_V->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_V"));
        doubleSpinBox_DrawLineSet_InitPos_V->setGeometry(QRect(160, 170, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_V->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_V->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_InitPos_V->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_V->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_V->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_V->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_V->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_V->setMaximum(1000);
        doubleSpinBox_DrawLineSet_InitPos_W = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_InitPos_W->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_InitPos_W"));
        doubleSpinBox_DrawLineSet_InitPos_W->setGeometry(QRect(160, 210, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_InitPos_W->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_InitPos_W->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_InitPos_W->setFont(font1);
        doubleSpinBox_DrawLineSet_InitPos_W->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_InitPos_W->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_InitPos_W->setDecimals(3);
        doubleSpinBox_DrawLineSet_InitPos_W->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_InitPos_W->setMaximum(1000);
        label_7 = new QLabel(QGTDrawLineSet);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 10, 130, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_DrawLineSet_topLeft_X = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_topLeft_X->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_topLeft_X"));
        doubleSpinBox_DrawLineSet_topLeft_X->setGeometry(QRect(470, 10, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_topLeft_X->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_topLeft_X->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_topLeft_X->setFont(font1);
        doubleSpinBox_DrawLineSet_topLeft_X->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_topLeft_X->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_topLeft_X->setDecimals(3);
        doubleSpinBox_DrawLineSet_topLeft_X->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_topLeft_X->setMaximum(1000);
        doubleSpinBox_DrawLineSet_topLeft_Y = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_topLeft_Y->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_topLeft_Y"));
        doubleSpinBox_DrawLineSet_topLeft_Y->setGeometry(QRect(470, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_topLeft_Y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_topLeft_Y->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_topLeft_Y->setFont(font1);
        doubleSpinBox_DrawLineSet_topLeft_Y->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_topLeft_Y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_topLeft_Y->setDecimals(3);
        doubleSpinBox_DrawLineSet_topLeft_Y->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_topLeft_Y->setMaximum(1000);
        label_8 = new QLabel(QGTDrawLineSet);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(320, 50, 130, 30));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_DrawLineSet_topLeft_Z = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_topLeft_Z->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_topLeft_Z"));
        doubleSpinBox_DrawLineSet_topLeft_Z->setGeometry(QRect(470, 90, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_topLeft_Z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_topLeft_Z->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_topLeft_Z->setFont(font1);
        doubleSpinBox_DrawLineSet_topLeft_Z->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_topLeft_Z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_topLeft_Z->setDecimals(3);
        doubleSpinBox_DrawLineSet_topLeft_Z->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_topLeft_Z->setMaximum(1000);
        label_9 = new QLabel(QGTDrawLineSet);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(320, 90, 130, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_DrawLineSet_Width = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_Width->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_Width"));
        doubleSpinBox_DrawLineSet_Width->setGeometry(QRect(470, 130, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_Width->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_Width->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_Width->setFont(font1);
        doubleSpinBox_DrawLineSet_Width->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_Width->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_Width->setDecimals(3);
        doubleSpinBox_DrawLineSet_Width->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_Width->setMaximum(1000);
        label_10 = new QLabel(QGTDrawLineSet);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(320, 130, 130, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_DrawLineSet_Height = new QDoubleSpinBox(QGTDrawLineSet);
        doubleSpinBox_DrawLineSet_Height->setObjectName(QStringLiteral("doubleSpinBox_DrawLineSet_Height"));
        doubleSpinBox_DrawLineSet_Height->setGeometry(QRect(470, 170, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_DrawLineSet_Height->sizePolicy().hasHeightForWidth());
        doubleSpinBox_DrawLineSet_Height->setSizePolicy(sizePolicy);
        doubleSpinBox_DrawLineSet_Height->setFont(font1);
        doubleSpinBox_DrawLineSet_Height->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        doubleSpinBox_DrawLineSet_Height->setAlignment(Qt::AlignCenter);
        doubleSpinBox_DrawLineSet_Height->setDecimals(3);
        doubleSpinBox_DrawLineSet_Height->setMinimum(-1000);
        doubleSpinBox_DrawLineSet_Height->setMaximum(1000);
        label_11 = new QLabel(QGTDrawLineSet);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(320, 170, 130, 30));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_DrawLineSet_LiftPlat_bottomPos = new QSpinBox(QGTDrawLineSet);
        spinBox_DrawLineSet_LiftPlat_bottomPos->setObjectName(QStringLiteral("spinBox_DrawLineSet_LiftPlat_bottomPos"));
        spinBox_DrawLineSet_LiftPlat_bottomPos->setGeometry(QRect(470, 250, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_DrawLineSet_LiftPlat_bottomPos->sizePolicy().hasHeightForWidth());
        spinBox_DrawLineSet_LiftPlat_bottomPos->setSizePolicy(sizePolicy);
        spinBox_DrawLineSet_LiftPlat_bottomPos->setFont(font1);
        spinBox_DrawLineSet_LiftPlat_bottomPos->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_DrawLineSet_LiftPlat_bottomPos->setAlignment(Qt::AlignCenter);
        spinBox_DrawLineSet_LiftPlat_bottomPos->setMaximum(3000);
        label_12 = new QLabel(QGTDrawLineSet);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(320, 210, 130, 30));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_DrawLineSet_LiftPlat_topPos = new QSpinBox(QGTDrawLineSet);
        spinBox_DrawLineSet_LiftPlat_topPos->setObjectName(QStringLiteral("spinBox_DrawLineSet_LiftPlat_topPos"));
        spinBox_DrawLineSet_LiftPlat_topPos->setGeometry(QRect(470, 210, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_DrawLineSet_LiftPlat_topPos->sizePolicy().hasHeightForWidth());
        spinBox_DrawLineSet_LiftPlat_topPos->setSizePolicy(sizePolicy);
        spinBox_DrawLineSet_LiftPlat_topPos->setFont(font1);
        spinBox_DrawLineSet_LiftPlat_topPos->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_DrawLineSet_LiftPlat_topPos->setAlignment(Qt::AlignCenter);
        spinBox_DrawLineSet_LiftPlat_topPos->setMaximum(3000);
        label_13 = new QLabel(QGTDrawLineSet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(320, 250, 130, 30));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        retranslateUi(QGTDrawLineSet);

        QMetaObject::connectSlotsByName(QGTDrawLineSet);
    } // setupUi

    void retranslateUi(QWidget *QGTDrawLineSet)
    {
        QGTDrawLineSet->setWindowTitle(QApplication::translate("QGTDrawLineSet", "QGTDrawLineSet", 0));
        label->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 X :", 0));
        toolButton_DrawLineSet_Ok->setText(QApplication::translate("QGTDrawLineSet", "\344\277\235\345\255\230", 0));
        toolButton_DrawLineSet_Reset->setText(QApplication::translate("QGTDrawLineSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        toolButton_DrawLineSet_Cancel->setText(QApplication::translate("QGTDrawLineSet", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 Y :", 0));
        label_3->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 Z :", 0));
        label_4->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 U :", 0));
        label_5->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 V :", 0));
        label_6->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\351\233\266\347\202\271\344\275\215\347\275\256 W :", 0));
        label_7->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\345\267\246\344\270\212\351\241\266\347\202\271 X :", 0));
        label_8->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\345\267\246\344\270\212\351\241\266\347\202\271 Y :", 0));
        label_9->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\345\267\246\344\270\212\351\241\266\347\202\271 Z :", 0));
        label_10->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\347\237\251\345\275\242\345\256\275\345\272\246 W :", 0));
        label_11->setText(QApplication::translate("QGTDrawLineSet", "\347\224\273\347\272\277\347\237\251\345\275\242\351\253\230\345\272\246 H :", 0));
        label_12->setText(QApplication::translate("QGTDrawLineSet", "\345\215\207\351\231\215\345\271\263\345\217\260\346\234\200\351\253\230\347\202\271 :", 0));
        label_13->setText(QApplication::translate("QGTDrawLineSet", "\345\215\207\351\231\215\345\271\263\345\217\260\346\234\200\344\275\216\347\202\271 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTDrawLineSet: public Ui_QGTDrawLineSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTDRAWLINESET_H
