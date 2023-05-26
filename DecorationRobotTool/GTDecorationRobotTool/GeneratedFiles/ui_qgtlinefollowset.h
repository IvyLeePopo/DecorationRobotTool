/********************************************************************************
** Form generated from reading UI file 'qgtlinefollowset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTLINEFOLLOWSET_H
#define UI_QGTLINEFOLLOWSET_H

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

class Ui_QGTLineFollowSet
{
public:
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_LineFollowSet_Calibration;
    QLabel *label_8;
    QGTToolButton *toolButton_LineFollowSet_Ok;
    QGTToolButton *toolButton_LineFollowSet_Cancel;
    QSpinBox *spinBox_LineFollowSet_MinContourArea;
    QSpinBox *spinBox_LineFollowSet_MaxContourArea;
    QGTToolButton *toolButton_LineFollowSet_Reset;
    QLabel *label_11;
    QLabel *label_4;
    QLabel *label;
    QSpinBox *spinBox_LineFollowSet_SpeedRate;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_LineFollowSet_DisRange;
    QSpinBox *spinBox_LineFollowSet_MaxBinaryThreshold;
    QSpinBox *spinBox_LineFollowSet_SearchThreshold;
    QSpinBox *spinBox_LineFollowSet_MinBinaryThreshold;
    QSpinBox *spinBox_LineFollowSet_TargetDis;
    QDoubleSpinBox *doubleSpinBox_LineFollowSet_AngleRange;

    void setupUi(QWidget *QGTLineFollowSet)
    {
        if (QGTLineFollowSet->objectName().isEmpty())
            QGTLineFollowSet->setObjectName(QStringLiteral("QGTLineFollowSet"));
        QGTLineFollowSet->resize(668, 501);
        QGTLineFollowSet->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        label_5 = new QLabel(QGTLineFollowSet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 180, 30));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_13 = new QLabel(QGTLineFollowSet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 290, 180, 30));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7 = new QLabel(QGTLineFollowSet);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 170, 180, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_LineFollowSet_Calibration = new QDoubleSpinBox(QGTLineFollowSet);
        doubleSpinBox_LineFollowSet_Calibration->setObjectName(QStringLiteral("doubleSpinBox_LineFollowSet_Calibration"));
        doubleSpinBox_LineFollowSet_Calibration->setGeometry(QRect(190, 10, 150, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_LineFollowSet_Calibration->sizePolicy().hasHeightForWidth());
        doubleSpinBox_LineFollowSet_Calibration->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        doubleSpinBox_LineFollowSet_Calibration->setFont(font1);
        doubleSpinBox_LineFollowSet_Calibration->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        doubleSpinBox_LineFollowSet_Calibration->setAlignment(Qt::AlignCenter);
        doubleSpinBox_LineFollowSet_Calibration->setDecimals(7);
        doubleSpinBox_LineFollowSet_Calibration->setSingleStep(0.001);
        label_8 = new QLabel(QGTLineFollowSet);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 210, 180, 30));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_LineFollowSet_Ok = new QGTToolButton(QGTLineFollowSet);
        toolButton_LineFollowSet_Ok->setObjectName(QStringLiteral("toolButton_LineFollowSet_Ok"));
        toolButton_LineFollowSet_Ok->setGeometry(QRect(450, 450, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_LineFollowSet_Ok->sizePolicy().hasHeightForWidth());
        toolButton_LineFollowSet_Ok->setSizePolicy(sizePolicy);
        toolButton_LineFollowSet_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_LineFollowSet_Cancel = new QGTToolButton(QGTLineFollowSet);
        toolButton_LineFollowSet_Cancel->setObjectName(QStringLiteral("toolButton_LineFollowSet_Cancel"));
        toolButton_LineFollowSet_Cancel->setGeometry(QRect(560, 450, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_LineFollowSet_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_LineFollowSet_Cancel->setSizePolicy(sizePolicy);
        toolButton_LineFollowSet_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_LineFollowSet_MinContourArea = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_MinContourArea->setObjectName(QStringLiteral("spinBox_LineFollowSet_MinContourArea"));
        spinBox_LineFollowSet_MinContourArea->setGeometry(QRect(190, 170, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_MinContourArea->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_MinContourArea->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_MinContourArea->setFont(font1);
        spinBox_LineFollowSet_MinContourArea->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_MinContourArea->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_MinContourArea->setMaximum(30000);
        spinBox_LineFollowSet_MaxContourArea = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_MaxContourArea->setObjectName(QStringLiteral("spinBox_LineFollowSet_MaxContourArea"));
        spinBox_LineFollowSet_MaxContourArea->setGeometry(QRect(190, 210, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_MaxContourArea->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_MaxContourArea->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_MaxContourArea->setFont(font1);
        spinBox_LineFollowSet_MaxContourArea->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_MaxContourArea->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_MaxContourArea->setMaximum(30000);
        toolButton_LineFollowSet_Reset = new QGTToolButton(QGTLineFollowSet);
        toolButton_LineFollowSet_Reset->setObjectName(QStringLiteral("toolButton_LineFollowSet_Reset"));
        toolButton_LineFollowSet_Reset->setGeometry(QRect(10, 450, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_LineFollowSet_Reset->sizePolicy().hasHeightForWidth());
        toolButton_LineFollowSet_Reset->setSizePolicy(sizePolicy);
        toolButton_LineFollowSet_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        label_11 = new QLabel(QGTLineFollowSet);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 370, 180, 30));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_4 = new QLabel(QGTLineFollowSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 50, 180, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label = new QLabel(QGTLineFollowSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 180, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_LineFollowSet_SpeedRate = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_SpeedRate->setObjectName(QStringLiteral("spinBox_LineFollowSet_SpeedRate"));
        spinBox_LineFollowSet_SpeedRate->setGeometry(QRect(190, 370, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_SpeedRate->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_SpeedRate->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_SpeedRate->setFont(font1);
        spinBox_LineFollowSet_SpeedRate->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_SpeedRate->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_SpeedRate->setMaximum(50);
        label_9 = new QLabel(QGTLineFollowSet);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 330, 180, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_6 = new QLabel(QGTLineFollowSet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 180, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10 = new QLabel(QGTLineFollowSet);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 250, 180, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_LineFollowSet_DisRange = new QDoubleSpinBox(QGTLineFollowSet);
        doubleSpinBox_LineFollowSet_DisRange->setObjectName(QStringLiteral("doubleSpinBox_LineFollowSet_DisRange"));
        doubleSpinBox_LineFollowSet_DisRange->setGeometry(QRect(190, 290, 150, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_LineFollowSet_DisRange->sizePolicy().hasHeightForWidth());
        doubleSpinBox_LineFollowSet_DisRange->setSizePolicy(sizePolicy);
        doubleSpinBox_LineFollowSet_DisRange->setFont(font1);
        doubleSpinBox_LineFollowSet_DisRange->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        doubleSpinBox_LineFollowSet_DisRange->setAlignment(Qt::AlignCenter);
        doubleSpinBox_LineFollowSet_DisRange->setMaximum(1000);
        doubleSpinBox_LineFollowSet_DisRange->setSingleStep(0.01);
        spinBox_LineFollowSet_MaxBinaryThreshold = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_MaxBinaryThreshold->setObjectName(QStringLiteral("spinBox_LineFollowSet_MaxBinaryThreshold"));
        spinBox_LineFollowSet_MaxBinaryThreshold->setGeometry(QRect(190, 130, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_MaxBinaryThreshold->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_MaxBinaryThreshold->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_MaxBinaryThreshold->setFont(font1);
        spinBox_LineFollowSet_MaxBinaryThreshold->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_MaxBinaryThreshold->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_MaxBinaryThreshold->setMaximum(255);
        spinBox_LineFollowSet_SearchThreshold = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_SearchThreshold->setObjectName(QStringLiteral("spinBox_LineFollowSet_SearchThreshold"));
        spinBox_LineFollowSet_SearchThreshold->setGeometry(QRect(190, 50, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_SearchThreshold->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_SearchThreshold->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_SearchThreshold->setFont(font1);
        spinBox_LineFollowSet_SearchThreshold->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_SearchThreshold->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_SearchThreshold->setMaximum(255);
        spinBox_LineFollowSet_MinBinaryThreshold = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_MinBinaryThreshold->setObjectName(QStringLiteral("spinBox_LineFollowSet_MinBinaryThreshold"));
        spinBox_LineFollowSet_MinBinaryThreshold->setGeometry(QRect(190, 90, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_MinBinaryThreshold->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_MinBinaryThreshold->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_MinBinaryThreshold->setFont(font1);
        spinBox_LineFollowSet_MinBinaryThreshold->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_MinBinaryThreshold->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_MinBinaryThreshold->setMaximum(255);
        spinBox_LineFollowSet_TargetDis = new QSpinBox(QGTLineFollowSet);
        spinBox_LineFollowSet_TargetDis->setObjectName(QStringLiteral("spinBox_LineFollowSet_TargetDis"));
        spinBox_LineFollowSet_TargetDis->setGeometry(QRect(190, 330, 150, 30));
        sizePolicy.setHeightForWidth(spinBox_LineFollowSet_TargetDis->sizePolicy().hasHeightForWidth());
        spinBox_LineFollowSet_TargetDis->setSizePolicy(sizePolicy);
        spinBox_LineFollowSet_TargetDis->setFont(font1);
        spinBox_LineFollowSet_TargetDis->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        spinBox_LineFollowSet_TargetDis->setAlignment(Qt::AlignCenter);
        spinBox_LineFollowSet_TargetDis->setMaximum(10000);
        doubleSpinBox_LineFollowSet_AngleRange = new QDoubleSpinBox(QGTLineFollowSet);
        doubleSpinBox_LineFollowSet_AngleRange->setObjectName(QStringLiteral("doubleSpinBox_LineFollowSet_AngleRange"));
        doubleSpinBox_LineFollowSet_AngleRange->setGeometry(QRect(190, 250, 150, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_LineFollowSet_AngleRange->sizePolicy().hasHeightForWidth());
        doubleSpinBox_LineFollowSet_AngleRange->setSizePolicy(sizePolicy);
        doubleSpinBox_LineFollowSet_AngleRange->setFont(font1);
        doubleSpinBox_LineFollowSet_AngleRange->setStyleSheet(QStringLiteral("color: rgb(85, 0, 255);"));
        doubleSpinBox_LineFollowSet_AngleRange->setAlignment(Qt::AlignCenter);
        doubleSpinBox_LineFollowSet_AngleRange->setMaximum(360);
        doubleSpinBox_LineFollowSet_AngleRange->setSingleStep(0.01);

        retranslateUi(QGTLineFollowSet);

        QMetaObject::connectSlotsByName(QGTLineFollowSet);
    } // setupUi

    void retranslateUi(QWidget *QGTLineFollowSet)
    {
        QGTLineFollowSet->setWindowTitle(QApplication::translate("QGTLineFollowSet", "QGTLineFollowSet", 0));
        label_5->setText(QApplication::translate("QGTLineFollowSet", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274\344\270\213\351\231\220 :", 0));
        label_13->setText(QApplication::translate("QGTLineFollowSet", "\345\201\217\347\247\273\350\267\235\347\246\273\350\257\257\345\267\256 :", 0));
        label_7->setText(QApplication::translate("QGTLineFollowSet", "\350\275\256\345\273\223\351\235\242\347\247\257\344\270\213\351\231\220 :", 0));
        label_8->setText(QApplication::translate("QGTLineFollowSet", "\350\275\256\345\273\223\351\235\242\347\247\257\344\270\212\351\231\220 :", 0));
        toolButton_LineFollowSet_Ok->setText(QApplication::translate("QGTLineFollowSet", "\344\277\235\345\255\230", 0));
        toolButton_LineFollowSet_Cancel->setText(QApplication::translate("QGTLineFollowSet", "\345\217\226\346\266\210", 0));
        toolButton_LineFollowSet_Reset->setText(QApplication::translate("QGTLineFollowSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        label_11->setText(QApplication::translate("QGTLineFollowSet", "\345\267\256\351\200\237\350\277\220\345\212\250\351\200\237\347\216\207 :", 0));
        label_4->setText(QApplication::translate("QGTLineFollowSet", "\346\243\200\346\265\213\351\230\210\345\200\274 :", 0));
        label->setText(QApplication::translate("QGTLineFollowSet", "\347\233\270\346\234\272\346\240\207\345\256\232 :", 0));
        label_9->setText(QApplication::translate("QGTLineFollowSet", "\345\276\252\347\272\277\347\233\256\346\240\207\350\267\235\347\246\273 :", 0));
        label_6->setText(QApplication::translate("QGTLineFollowSet", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274\344\270\212\351\231\220 :", 0));
        label_10->setText(QApplication::translate("QGTLineFollowSet", "\345\201\217\347\247\273\350\247\222\345\272\246\350\257\257\345\267\256 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTLineFollowSet: public Ui_QGTLineFollowSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTLINEFOLLOWSET_H
