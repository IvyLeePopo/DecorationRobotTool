/********************************************************************************
** Form generated from reading UI file 'qgtliftplatmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTLIFTPLATMODULE_H
#define UI_QGTLIFTPLATMODULE_H

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

class Ui_QGTLiftPlatModule
{
public:
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_Motor_voltage;
    QLabel *label_Motor_current;
    QLabel *label_En_Status_explain;
    QLabel *label_Modbus_Status_explain;
    QLabel *label_Speed_start;
    QLabel *label_Motor_temperature;
    QGTToolButton *toolButton_LiftPlat_Stop;
    QLabel *label_Acceleration;
    QLabel *label_19;
    QLabel *label_Motor_Speed_actual;
    QLabel *label_16;
    QLabel *label_En_Status;
    QLabel *label_10;
    QLabel *label_Pu_AllStep;
    QLabel *label_18;
    QLabel *label_3;
    QSpinBox *spinBox_Motor_TargetSpeed;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_Modbus_Status;
    QLabel *label_2;
    QLabel *label_Plat_Height;
    QLabel *label_Target_Speed;
    QLabel *label_5;
    QLabel *label_25;
    QLabel *label_24;
    QGTToolButton *toolButton_LiftPlat_MoveUp;
    QLabel *label_22;
    QLabel *label_26;
    QLabel *label_23;
    QLabel *label_Motor_PWM;
    QLabel *label_9;
    QLabel *label_Pu_Step;
    QLabel *label_8;
    QGTToolButton *toolButton_LiftPlat_MoveDown;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_21;
    QLabel *label_7;

    void setupUi(QWidget *QGTLiftPlatModule)
    {
        if (QGTLiftPlatModule->objectName().isEmpty())
            QGTLiftPlatModule->setObjectName(QStringLiteral("QGTLiftPlatModule"));
        QGTLiftPlatModule->resize(1024, 590);
        label_14 = new QLabel(QGTLiftPlatModule);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(420, 160, 150, 30));
        QFont font;
        font.setPointSize(20);
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_15 = new QLabel(QGTLiftPlatModule);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(420, 230, 150, 30));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_voltage = new QLabel(QGTLiftPlatModule);
        label_Motor_voltage->setObjectName(QStringLiteral("label_Motor_voltage"));
        label_Motor_voltage->setGeometry(QRect(570, 90, 80, 30));
        label_Motor_voltage->setFont(font);
        label_Motor_voltage->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_voltage->setAlignment(Qt::AlignCenter);
        label_Motor_current = new QLabel(QGTLiftPlatModule);
        label_Motor_current->setObjectName(QStringLiteral("label_Motor_current"));
        label_Motor_current->setGeometry(QRect(570, 20, 80, 30));
        label_Motor_current->setFont(font);
        label_Motor_current->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_current->setAlignment(Qt::AlignCenter);
        label_En_Status_explain = new QLabel(QGTLiftPlatModule);
        label_En_Status_explain->setObjectName(QStringLiteral("label_En_Status_explain"));
        label_En_Status_explain->setGeometry(QRect(250, 90, 120, 30));
        label_En_Status_explain->setFont(font);
        label_En_Status_explain->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_En_Status_explain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Modbus_Status_explain = new QLabel(QGTLiftPlatModule);
        label_Modbus_Status_explain->setObjectName(QStringLiteral("label_Modbus_Status_explain"));
        label_Modbus_Status_explain->setGeometry(QRect(250, 20, 120, 30));
        label_Modbus_Status_explain->setFont(font);
        label_Modbus_Status_explain->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Modbus_Status_explain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Speed_start = new QLabel(QGTLiftPlatModule);
        label_Speed_start->setObjectName(QStringLiteral("label_Speed_start"));
        label_Speed_start->setGeometry(QRect(160, 530, 80, 30));
        label_Speed_start->setFont(font);
        label_Speed_start->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Speed_start->setAlignment(Qt::AlignCenter);
        label_Motor_temperature = new QLabel(QGTLiftPlatModule);
        label_Motor_temperature->setObjectName(QStringLiteral("label_Motor_temperature"));
        label_Motor_temperature->setGeometry(QRect(570, 160, 80, 30));
        label_Motor_temperature->setFont(font);
        label_Motor_temperature->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_temperature->setAlignment(Qt::AlignCenter);
        toolButton_LiftPlat_Stop = new QGTToolButton(QGTLiftPlatModule);
        toolButton_LiftPlat_Stop->setObjectName(QStringLiteral("toolButton_LiftPlat_Stop"));
        toolButton_LiftPlat_Stop->setGeometry(QRect(850, 220, 150, 150));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_LiftPlat_Stop->sizePolicy().hasHeightForWidth());
        toolButton_LiftPlat_Stop->setSizePolicy(sizePolicy);
        label_Acceleration = new QLabel(QGTLiftPlatModule);
        label_Acceleration->setObjectName(QStringLiteral("label_Acceleration"));
        label_Acceleration->setGeometry(QRect(160, 460, 80, 30));
        label_Acceleration->setFont(font);
        label_Acceleration->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Acceleration->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(QGTLiftPlatModule);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(660, 160, 100, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_Speed_actual = new QLabel(QGTLiftPlatModule);
        label_Motor_Speed_actual->setObjectName(QStringLiteral("label_Motor_Speed_actual"));
        label_Motor_Speed_actual->setGeometry(QRect(570, 390, 80, 30));
        label_Motor_Speed_actual->setFont(font);
        label_Motor_Speed_actual->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_Speed_actual->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(QGTLiftPlatModule);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(420, 390, 150, 30));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_En_Status = new QLabel(QGTLiftPlatModule);
        label_En_Status->setObjectName(QStringLiteral("label_En_Status"));
        label_En_Status->setGeometry(QRect(160, 90, 80, 30));
        label_En_Status->setFont(font);
        label_En_Status->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_En_Status->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(QGTLiftPlatModule);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(250, 460, 120, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Pu_AllStep = new QLabel(QGTLiftPlatModule);
        label_Pu_AllStep->setObjectName(QStringLiteral("label_Pu_AllStep"));
        label_Pu_AllStep->setGeometry(QRect(160, 230, 80, 30));
        label_Pu_AllStep->setFont(font);
        label_Pu_AllStep->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Pu_AllStep->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(QGTLiftPlatModule);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(660, 90, 100, 30));
        label_18->setFont(font);
        label_18->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTLiftPlatModule);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 20, 150, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Motor_TargetSpeed = new QSpinBox(QGTLiftPlatModule);
        spinBox_Motor_TargetSpeed->setObjectName(QStringLiteral("spinBox_Motor_TargetSpeed"));
        spinBox_Motor_TargetSpeed->setGeometry(QRect(570, 530, 100, 30));
        sizePolicy.setHeightForWidth(spinBox_Motor_TargetSpeed->sizePolicy().hasHeightForWidth());
        spinBox_Motor_TargetSpeed->setSizePolicy(sizePolicy);
        spinBox_Motor_TargetSpeed->setFont(font);
        spinBox_Motor_TargetSpeed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        spinBox_Motor_TargetSpeed->setAlignment(Qt::AlignCenter);
        spinBox_Motor_TargetSpeed->setMaximum(5000);
        spinBox_Motor_TargetSpeed->setSingleStep(100);
        label_17 = new QLabel(QGTLiftPlatModule);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(660, 20, 100, 30));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_20 = new QLabel(QGTLiftPlatModule);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(660, 230, 100, 30));
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Modbus_Status = new QLabel(QGTLiftPlatModule);
        label_Modbus_Status->setObjectName(QStringLiteral("label_Modbus_Status"));
        label_Modbus_Status->setGeometry(QRect(160, 20, 80, 30));
        label_Modbus_Status->setFont(font);
        label_Modbus_Status->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Modbus_Status->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(QGTLiftPlatModule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 150, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Plat_Height = new QLabel(QGTLiftPlatModule);
        label_Plat_Height->setObjectName(QStringLiteral("label_Plat_Height"));
        label_Plat_Height->setGeometry(QRect(570, 460, 80, 30));
        label_Plat_Height->setFont(font);
        label_Plat_Height->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Plat_Height->setAlignment(Qt::AlignCenter);
        label_Target_Speed = new QLabel(QGTLiftPlatModule);
        label_Target_Speed->setObjectName(QStringLiteral("label_Target_Speed"));
        label_Target_Speed->setGeometry(QRect(160, 390, 80, 30));
        label_Target_Speed->setFont(font);
        label_Target_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Target_Speed->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(QGTLiftPlatModule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 390, 120, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_25 = new QLabel(QGTLiftPlatModule);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(420, 460, 150, 30));
        label_25->setFont(font);
        label_25->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_24 = new QLabel(QGTLiftPlatModule);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 530, 150, 30));
        label_24->setFont(font);
        label_24->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        toolButton_LiftPlat_MoveUp = new QGTToolButton(QGTLiftPlatModule);
        toolButton_LiftPlat_MoveUp->setObjectName(QStringLiteral("toolButton_LiftPlat_MoveUp"));
        toolButton_LiftPlat_MoveUp->setGeometry(QRect(850, 50, 150, 150));
        sizePolicy.setHeightForWidth(toolButton_LiftPlat_MoveUp->sizePolicy().hasHeightForWidth());
        toolButton_LiftPlat_MoveUp->setSizePolicy(sizePolicy);
        label_22 = new QLabel(QGTLiftPlatModule);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(660, 460, 100, 30));
        label_22->setFont(font);
        label_22->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_26 = new QLabel(QGTLiftPlatModule);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(420, 530, 150, 30));
        label_26->setFont(font);
        label_26->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_23 = new QLabel(QGTLiftPlatModule);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(250, 530, 120, 30));
        label_23->setFont(font);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Motor_PWM = new QLabel(QGTLiftPlatModule);
        label_Motor_PWM->setObjectName(QStringLiteral("label_Motor_PWM"));
        label_Motor_PWM->setGeometry(QRect(570, 230, 80, 30));
        label_Motor_PWM->setFont(font);
        label_Motor_PWM->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Motor_PWM->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(QGTLiftPlatModule);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 460, 150, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Pu_Step = new QLabel(QGTLiftPlatModule);
        label_Pu_Step->setObjectName(QStringLiteral("label_Pu_Step"));
        label_Pu_Step->setGeometry(QRect(160, 160, 80, 30));
        label_Pu_Step->setFont(font);
        label_Pu_Step->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Pu_Step->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(QGTLiftPlatModule);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 390, 150, 30));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        toolButton_LiftPlat_MoveDown = new QGTToolButton(QGTLiftPlatModule);
        toolButton_LiftPlat_MoveDown->setObjectName(QStringLiteral("toolButton_LiftPlat_MoveDown"));
        toolButton_LiftPlat_MoveDown->setGeometry(QRect(850, 390, 150, 150));
        sizePolicy.setHeightForWidth(toolButton_LiftPlat_MoveDown->sizePolicy().hasHeightForWidth());
        toolButton_LiftPlat_MoveDown->setSizePolicy(sizePolicy);
        label_6 = new QLabel(QGTLiftPlatModule);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 150, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label = new QLabel(QGTLiftPlatModule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 150, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(QGTLiftPlatModule);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 90, 150, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_21 = new QLabel(QGTLiftPlatModule);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(660, 390, 100, 30));
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7 = new QLabel(QGTLiftPlatModule);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 230, 150, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(QGTLiftPlatModule);

        QMetaObject::connectSlotsByName(QGTLiftPlatModule);
    } // setupUi

    void retranslateUi(QWidget *QGTLiftPlatModule)
    {
        QGTLiftPlatModule->setWindowTitle(QApplication::translate("QGTLiftPlatModule", "QGTLiftPlatModule", 0));
        label_14->setText(QApplication::translate("QGTLiftPlatModule", "\346\270\251\345\272\246 :", 0));
        label_15->setText(QApplication::translate("QGTLiftPlatModule", "\350\276\223\345\207\272\350\204\211\345\256\275 :", 0));
        label_Motor_voltage->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_Motor_current->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_En_Status_explain->setText(QApplication::translate("QGTLiftPlatModule", "\347\246\201\346\255\242", 0));
        label_Modbus_Status_explain->setText(QApplication::translate("QGTLiftPlatModule", "\347\246\201\346\255\242", 0));
        label_Speed_start->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_Motor_temperature->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_Acceleration->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_19->setText(QApplication::translate("QGTLiftPlatModule", "(\342\204\203)", 0));
        label_Motor_Speed_actual->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_16->setText(QApplication::translate("QGTLiftPlatModule", "\345\275\223\345\211\215\350\275\254\351\200\237 :", 0));
        label_En_Status->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_10->setText(QApplication::translate("QGTLiftPlatModule", "(r/min)/s", 0));
        label_Pu_AllStep->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_18->setText(QApplication::translate("QGTLiftPlatModule", "(V)", 0));
        label_3->setText(QApplication::translate("QGTLiftPlatModule", "\347\224\265\346\265\201 :", 0));
        label_17->setText(QApplication::translate("QGTLiftPlatModule", "(A)", 0));
        label_20->setText(QApplication::translate("QGTLiftPlatModule", "(%)", 0));
        label_Modbus_Status->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_2->setText(QApplication::translate("QGTLiftPlatModule", "En\344\275\277\350\203\275 :", 0));
        label_Plat_Height->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_Target_Speed->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_5->setText(QApplication::translate("QGTLiftPlatModule", "(r/min)", 0));
        label_25->setText(QApplication::translate("QGTLiftPlatModule", "\345\275\223\345\211\215\351\253\230\345\272\246 :", 0));
        label_24->setText(QApplication::translate("QGTLiftPlatModule", "\347\224\265\346\234\272\350\265\267\345\247\213\350\275\254\351\200\237 :", 0));
        label_22->setText(QApplication::translate("QGTLiftPlatModule", "(mm)", 0));
        label_26->setText(QApplication::translate("QGTLiftPlatModule", "\347\224\265\346\234\272\350\275\254\351\200\237 :", 0));
        label_23->setText(QApplication::translate("QGTLiftPlatModule", "(r/min)", 0));
        label_Motor_PWM->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_9->setText(QApplication::translate("QGTLiftPlatModule", "\347\224\265\346\234\272\345\212\240\351\200\237\345\272\246 :", 0));
        label_Pu_Step->setText(QApplication::translate("QGTLiftPlatModule", "0", 0));
        label_8->setText(QApplication::translate("QGTLiftPlatModule", "\347\233\256\346\240\207\350\275\254\351\200\237 :", 0));
        label_6->setText(QApplication::translate("QGTLiftPlatModule", "Pu\346\255\245\346\225\260 :", 0));
        label->setText(QApplication::translate("QGTLiftPlatModule", "modbus\344\275\277\350\203\275 :", 0));
        label_4->setText(QApplication::translate("QGTLiftPlatModule", "\347\224\265\345\216\213 :", 0));
        label_21->setText(QApplication::translate("QGTLiftPlatModule", "(r/min)", 0));
        label_7->setText(QApplication::translate("QGTLiftPlatModule", "Pu\346\200\273\346\255\245\346\225\260 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTLiftPlatModule: public Ui_QGTLiftPlatModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTLIFTPLATMODULE_H
