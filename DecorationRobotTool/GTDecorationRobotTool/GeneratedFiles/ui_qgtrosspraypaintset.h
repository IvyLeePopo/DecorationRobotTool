/********************************************************************************
** Form generated from reading UI file 'qgtrosspraypaintset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTROSSPRAYPAINTSET_H
#define UI_QGTROSSPRAYPAINTSET_H

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

class Ui_QGTRosSprayPaintSet
{
public:
    QGTToolButton *toolButton_RosSprayPaintSet_Cancel;
    QSpinBox *spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step;
    QGTToolButton *toolButton_RosSprayPaintSet_Reset;
    QLabel *label_2;
    QGTToolButton *toolButton_RosSprayPaintSet_Ok;
    QSpinBox *spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold;
    QLabel *label_3;
    QSpinBox *spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Dis_Precision;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Hor_WorkDis;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Ver_WorkDis;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Hor_Overlap;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_RosSprayPaintSet_Ver_Overlap;
    QLabel *label_14;

    void setupUi(QWidget *QGTRosSprayPaintSet)
    {
        if (QGTRosSprayPaintSet->objectName().isEmpty())
            QGTRosSprayPaintSet->setObjectName(QStringLiteral("QGTRosSprayPaintSet"));
        QGTRosSprayPaintSet->resize(970, 680);
        QGTRosSprayPaintSet->setStyleSheet(QStringLiteral("background-color: rgb(35, 41, 46);"));
        toolButton_RosSprayPaintSet_Cancel = new QGTToolButton(QGTRosSprayPaintSet);
        toolButton_RosSprayPaintSet_Cancel->setObjectName(QStringLiteral("toolButton_RosSprayPaintSet_Cancel"));
        toolButton_RosSprayPaintSet_Cancel->setGeometry(QRect(860, 620, 100, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_RosSprayPaintSet_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_RosSprayPaintSet_Cancel->setSizePolicy(sizePolicy);
        toolButton_RosSprayPaintSet_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step = new QSpinBox(QGTRosSprayPaintSet);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setObjectName(QStringLiteral("spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setGeometry(QRect(200, 10, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->sizePolicy().hasHeightForWidth());
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setFont(font);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setAlignment(Qt::AlignCenter);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setMinimum(1);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setMaximum(1000);
        toolButton_RosSprayPaintSet_Reset = new QGTToolButton(QGTRosSprayPaintSet);
        toolButton_RosSprayPaintSet_Reset->setObjectName(QStringLiteral("toolButton_RosSprayPaintSet_Reset"));
        toolButton_RosSprayPaintSet_Reset->setGeometry(QRect(10, 620, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_RosSprayPaintSet_Reset->sizePolicy().hasHeightForWidth());
        toolButton_RosSprayPaintSet_Reset->setSizePolicy(sizePolicy);
        toolButton_RosSprayPaintSet_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        label_2 = new QLabel(QGTRosSprayPaintSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 190, 30));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        toolButton_RosSprayPaintSet_Ok = new QGTToolButton(QGTRosSprayPaintSet);
        toolButton_RosSprayPaintSet_Ok->setObjectName(QStringLiteral("toolButton_RosSprayPaintSet_Ok"));
        toolButton_RosSprayPaintSet_Ok->setGeometry(QRect(750, 620, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_RosSprayPaintSet_Ok->sizePolicy().hasHeightForWidth());
        toolButton_RosSprayPaintSet_Ok->setSizePolicy(sizePolicy);
        toolButton_RosSprayPaintSet_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold = new QSpinBox(QGTRosSprayPaintSet);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setObjectName(QStringLiteral("spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setGeometry(QRect(200, 50, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->sizePolicy().hasHeightForWidth());
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setSizePolicy(sizePolicy);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setFont(font);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setAlignment(Qt::AlignCenter);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setMinimum(1);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setMaximum(100000);
        label_3 = new QLabel(QGTRosSprayPaintSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 190, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold = new QSpinBox(QGTRosSprayPaintSet);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setObjectName(QStringLiteral("spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setGeometry(QRect(200, 90, 120, 30));
        sizePolicy.setHeightForWidth(spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->sizePolicy().hasHeightForWidth());
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setSizePolicy(sizePolicy);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setFont(font);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setAlignment(Qt::AlignCenter);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setMinimum(1);
        spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setMaximum(100000);
        label_4 = new QLabel(QGTRosSprayPaintSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 90, 190, 30));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos"));
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setGeometry(QRect(650, 50, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setFont(font);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setMaximum(10000);
        label_5 = new QLabel(QGTRosSprayPaintSet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(430, 50, 170, 30));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Dis_Precision = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Dis_Precision"));
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setGeometry(QRect(650, 10, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Dis_Precision->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Dis_Precision->setMaximum(2000);
        label_6 = new QLabel(QGTRosSprayPaintSet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 10, 170, 30));
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setGeometry(QRect(650, 250, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setMinimum(-2000);
        doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setMaximum(2000);
        label_7 = new QLabel(QGTRosSprayPaintSet);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(430, 250, 220, 30));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setGeometry(QRect(650, 290, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setMaximum(5000);
        label_8 = new QLabel(QGTRosSprayPaintSet);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(430, 290, 220, 30));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setGeometry(QRect(650, 330, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setMaximum(100000);
        label_9 = new QLabel(QGTRosSprayPaintSet);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(430, 330, 220, 30));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setGeometry(QRect(650, 370, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setMaximum(100000);
        label_10 = new QLabel(QGTRosSprayPaintSet);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(430, 370, 220, 30));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Hor_WorkDis"));
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setGeometry(QRect(650, 170, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setMaximum(10000);
        label_11 = new QLabel(QGTRosSprayPaintSet);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(430, 170, 220, 30));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Ver_WorkDis"));
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setGeometry(QRect(650, 210, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setMaximum(10000);
        label_12 = new QLabel(QGTRosSprayPaintSet);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(430, 210, 220, 30));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Hor_Overlap"));
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setGeometry(QRect(650, 90, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Hor_Overlap->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setMaximum(1);
        doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setSingleStep(0.001);
        label_13 = new QLabel(QGTRosSprayPaintSet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(430, 90, 220, 30));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap = new QDoubleSpinBox(QGTRosSprayPaintSet);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setObjectName(QStringLiteral("doubleSpinBox_RosSprayPaintSet_Ver_Overlap"));
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setGeometry(QRect(650, 130, 120, 30));
        sizePolicy.setHeightForWidth(doubleSpinBox_RosSprayPaintSet_Ver_Overlap->sizePolicy().hasHeightForWidth());
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setSizePolicy(sizePolicy);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setFont(font);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 85, 255);"));
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setAlignment(Qt::AlignCenter);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setDecimals(3);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setMinimum(0);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setMaximum(1);
        doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setSingleStep(0.001);
        label_14 = new QLabel(QGTRosSprayPaintSet);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(430, 130, 220, 30));
        label_14->setFont(font1);
        label_14->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        retranslateUi(QGTRosSprayPaintSet);

        QMetaObject::connectSlotsByName(QGTRosSprayPaintSet);
    } // setupUi

    void retranslateUi(QWidget *QGTRosSprayPaintSet)
    {
        QGTRosSprayPaintSet->setWindowTitle(QApplication::translate("QGTRosSprayPaintSet", "QGTRosSprayPaintSet", 0));
        toolButton_RosSprayPaintSet_Cancel->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\217\226\346\266\210", 0));
        toolButton_RosSprayPaintSet_Reset->setText(QApplication::translate("QGTRosSprayPaintSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("QGTRosSprayPaintSet", "\346\220\234\345\257\273\350\275\254\346\212\230\347\202\271\347\232\204\347\202\271\346\225\260\346\255\245\351\225\277 :", 0));
        toolButton_RosSprayPaintSet_Ok->setText(QApplication::translate("QGTRosSprayPaintSet", "\344\277\235\345\255\230", 0));
        label_3->setText(QApplication::translate("QGTRosSprayPaintSet", "\346\220\234\345\257\273\350\275\254\346\212\230\347\202\271\347\232\204\350\267\235\347\246\273\351\230\210\345\200\274 :", 0));
        label_4->setText(QApplication::translate("QGTRosSprayPaintSet", "\346\220\234\345\257\273\350\275\254\346\212\230\347\202\271\347\232\204\351\225\277\345\272\246\351\230\210\345\200\274 :", 0));
        label_5->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\215\207\351\231\215\345\271\263\345\217\260\347\232\204\345\210\235\345\247\213\344\275\215\347\275\256 :", 0));
        label_6->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\267\245\344\275\234\350\267\235\347\246\273\347\232\204\347\262\276\345\272\246\350\257\257\345\267\256 :", 0));
        label_7->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\272\225\347\233\230\344\270\216\345\267\245\344\275\234\345\242\231\351\235\242\347\232\204\345\244\271\350\247\222\350\214\203\345\233\264 :", 0));
        label_8->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\272\225\347\233\230\344\270\216\345\267\245\344\275\234\345\242\231\351\235\242\347\232\204\350\267\235\347\246\273\351\230\210\345\200\274 :", 0));
        label_9->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\272\225\347\233\230\350\267\235\345\267\246\350\276\271\345\242\231\351\235\242\347\232\204\346\234\200\345\260\217\350\267\235\347\246\273 :", 0));
        label_10->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\272\225\347\233\230\350\267\235\345\267\246\350\276\271\345\242\231\351\235\242\347\232\204\346\234\200\345\244\247\350\267\235\347\246\273 :", 0));
        label_11->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\215\225\346\254\241\345\226\267\346\266\202\345\212\250\344\275\234\346\260\264\345\271\263\345\267\245\344\275\234\350\267\235\347\246\273 :", 0));
        label_12->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\215\225\346\254\241\345\226\267\346\266\202\345\212\250\344\275\234\345\236\202\347\233\264\345\267\245\344\275\234\350\267\235\347\246\273 :", 0));
        label_13->setText(QApplication::translate("QGTRosSprayPaintSet", "\346\260\264\345\271\263\346\226\271\345\220\221\347\232\204\345\226\267\346\266\202\351\207\215\345\220\210\347\216\207 :", 0));
        label_14->setText(QApplication::translate("QGTRosSprayPaintSet", "\345\236\202\347\233\264\346\226\271\345\220\221\347\232\204\345\226\267\346\266\202\351\207\215\345\220\210\347\216\207 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTRosSprayPaintSet: public Ui_QGTRosSprayPaintSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTROSSPRAYPAINTSET_H
