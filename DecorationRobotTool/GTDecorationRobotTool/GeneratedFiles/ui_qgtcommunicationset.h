/********************************************************************************
** Form generated from reading UI file 'qgtcommunicationset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTCOMMUNICATIONSET_H
#define UI_QGTCOMMUNICATIONSET_H

#include <Commen/qgtipaddressedit.h>
#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTCommunicationSet
{
public:
    QGTIpAddressEdit *widget_Chasis_IpAddress;
    QLineEdit *lineEdit_Chasis_Port;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox_LiftPlatform_Port;
    QLineEdit *lineEdit_Robot_Port;
    QCheckBox *checkBox_IsSelect_LiftPlat_Connect;
    QGTToolButton *toolButton_Communication_Reset;
    QLabel *label_2;
    QCheckBox *checkBox_IsSelect_Chasis_Connect;
    QGTIpAddressEdit *widget_Robot_IpAddress;
    QCheckBox *checkBox_IsSelect_Robot_Connect;
    QGTToolButton *toolButton_Communication_Ok;
    QGTToolButton *toolButton_Communication_Cancel;
    QCheckBox *checkBox_IsSelect_JoyHandle_Connect;
    QLineEdit *lineEdit_Ros_Port;
    QGTIpAddressEdit *widget_Ros_IpAddress;
    QCheckBox *checkBox_IsSelect_Ros_Connect;
    QLabel *label_4;
    QComboBox *comboBox_Lidar_Port;
    QLabel *label_5;
    QComboBox *comboBox_Lidar_Baudrate;
    QComboBox *comboBox_LaserMeasure_Baudrate;
    QLabel *label_6;
    QComboBox *comboBox_LaserMeasure_Port;
    QComboBox *comboBox_LiftPlatform_Baudrate;
    QCheckBox *checkBox_IsSelect_Lidar_Connect;
    QCheckBox *checkBox_IsSelect_LaserMeasure_Connect;

    void setupUi(QWidget *QGTCommunicationSet)
    {
        if (QGTCommunicationSet->objectName().isEmpty())
            QGTCommunicationSet->setObjectName(QStringLiteral("QGTCommunicationSet"));
        QGTCommunicationSet->resize(500, 450);
        QGTCommunicationSet->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        widget_Chasis_IpAddress = new QGTIpAddressEdit(QGTCommunicationSet);
        widget_Chasis_IpAddress->setObjectName(QStringLiteral("widget_Chasis_IpAddress"));
        widget_Chasis_IpAddress->setGeometry(QRect(170, 10, 200, 30));
        QFont font;
        font.setPointSize(12);
        widget_Chasis_IpAddress->setFont(font);
        widget_Chasis_IpAddress->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Chasis_Port = new QLineEdit(QGTCommunicationSet);
        lineEdit_Chasis_Port->setObjectName(QStringLiteral("lineEdit_Chasis_Port"));
        lineEdit_Chasis_Port->setGeometry(QRect(390, 10, 100, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Chasis_Port->sizePolicy().hasHeightForWidth());
        lineEdit_Chasis_Port->setSizePolicy(sizePolicy);
        lineEdit_Chasis_Port->setFont(font);
        lineEdit_Chasis_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Chasis_Port->setAlignment(Qt::AlignCenter);
        label = new QLabel(QGTCommunicationSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 110, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        label_3 = new QLabel(QGTCommunicationSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 250, 110, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_LiftPlatform_Port = new QComboBox(QGTCommunicationSet);
        comboBox_LiftPlatform_Port->setObjectName(QStringLiteral("comboBox_LiftPlatform_Port"));
        comboBox_LiftPlatform_Port->setGeometry(QRect(170, 250, 200, 30));
        sizePolicy.setHeightForWidth(comboBox_LiftPlatform_Port->sizePolicy().hasHeightForWidth());
        comboBox_LiftPlatform_Port->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        comboBox_LiftPlatform_Port->setFont(font1);
        comboBox_LiftPlatform_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Robot_Port = new QLineEdit(QGTCommunicationSet);
        lineEdit_Robot_Port->setObjectName(QStringLiteral("lineEdit_Robot_Port"));
        lineEdit_Robot_Port->setGeometry(QRect(390, 60, 100, 30));
        sizePolicy.setHeightForWidth(lineEdit_Robot_Port->sizePolicy().hasHeightForWidth());
        lineEdit_Robot_Port->setSizePolicy(sizePolicy);
        lineEdit_Robot_Port->setFont(font);
        lineEdit_Robot_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Robot_Port->setAlignment(Qt::AlignCenter);
        checkBox_IsSelect_LiftPlat_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_LiftPlat_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_LiftPlat_Connect"));
        checkBox_IsSelect_LiftPlat_Connect->setGeometry(QRect(10, 250, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_LiftPlat_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_LiftPlat_Connect->setSizePolicy(sizePolicy);
        toolButton_Communication_Reset = new QGTToolButton(QGTCommunicationSet);
        toolButton_Communication_Reset->setObjectName(QStringLiteral("toolButton_Communication_Reset"));
        toolButton_Communication_Reset->setGeometry(QRect(10, 390, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_Communication_Reset->sizePolicy().hasHeightForWidth());
        toolButton_Communication_Reset->setSizePolicy(sizePolicy);
        toolButton_Communication_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        label_2 = new QLabel(QGTCommunicationSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 110, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        checkBox_IsSelect_Chasis_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_Chasis_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_Chasis_Connect"));
        checkBox_IsSelect_Chasis_Connect->setGeometry(QRect(10, 10, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_Chasis_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_Chasis_Connect->setSizePolicy(sizePolicy);
        widget_Robot_IpAddress = new QGTIpAddressEdit(QGTCommunicationSet);
        widget_Robot_IpAddress->setObjectName(QStringLiteral("widget_Robot_IpAddress"));
        widget_Robot_IpAddress->setGeometry(QRect(170, 60, 200, 30));
        widget_Robot_IpAddress->setFont(font);
        widget_Robot_IpAddress->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        checkBox_IsSelect_Robot_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_Robot_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_Robot_Connect"));
        checkBox_IsSelect_Robot_Connect->setGeometry(QRect(10, 60, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_Robot_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_Robot_Connect->setSizePolicy(sizePolicy);
        toolButton_Communication_Ok = new QGTToolButton(QGTCommunicationSet);
        toolButton_Communication_Ok->setObjectName(QStringLiteral("toolButton_Communication_Ok"));
        toolButton_Communication_Ok->setGeometry(QRect(280, 390, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_Communication_Ok->sizePolicy().hasHeightForWidth());
        toolButton_Communication_Ok->setSizePolicy(sizePolicy);
        toolButton_Communication_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_Communication_Cancel = new QGTToolButton(QGTCommunicationSet);
        toolButton_Communication_Cancel->setObjectName(QStringLiteral("toolButton_Communication_Cancel"));
        toolButton_Communication_Cancel->setGeometry(QRect(390, 390, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_Communication_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_Communication_Cancel->setSizePolicy(sizePolicy);
        toolButton_Communication_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        checkBox_IsSelect_JoyHandle_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_JoyHandle_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_JoyHandle_Connect"));
        checkBox_IsSelect_JoyHandle_Connect->setGeometry(QRect(10, 310, 200, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_JoyHandle_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_JoyHandle_Connect->setSizePolicy(sizePolicy);
        checkBox_IsSelect_JoyHandle_Connect->setFont(font);
        checkBox_IsSelect_JoyHandle_Connect->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Ros_Port = new QLineEdit(QGTCommunicationSet);
        lineEdit_Ros_Port->setObjectName(QStringLiteral("lineEdit_Ros_Port"));
        lineEdit_Ros_Port->setGeometry(QRect(390, 110, 100, 30));
        sizePolicy.setHeightForWidth(lineEdit_Ros_Port->sizePolicy().hasHeightForWidth());
        lineEdit_Ros_Port->setSizePolicy(sizePolicy);
        lineEdit_Ros_Port->setFont(font1);
        lineEdit_Ros_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        lineEdit_Ros_Port->setAlignment(Qt::AlignCenter);
        widget_Ros_IpAddress = new QGTIpAddressEdit(QGTCommunicationSet);
        widget_Ros_IpAddress->setObjectName(QStringLiteral("widget_Ros_IpAddress"));
        widget_Ros_IpAddress->setGeometry(QRect(170, 110, 200, 30));
        widget_Ros_IpAddress->setFont(font);
        widget_Ros_IpAddress->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        checkBox_IsSelect_Ros_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_Ros_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_Ros_Connect"));
        checkBox_IsSelect_Ros_Connect->setGeometry(QRect(10, 110, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_Ros_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_Ros_Connect->setSizePolicy(sizePolicy);
        label_4 = new QLabel(QGTCommunicationSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 110, 110, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_Lidar_Port = new QComboBox(QGTCommunicationSet);
        comboBox_Lidar_Port->setObjectName(QStringLiteral("comboBox_Lidar_Port"));
        comboBox_Lidar_Port->setGeometry(QRect(170, 150, 200, 30));
        sizePolicy.setHeightForWidth(comboBox_Lidar_Port->sizePolicy().hasHeightForWidth());
        comboBox_Lidar_Port->setSizePolicy(sizePolicy);
        comboBox_Lidar_Port->setFont(font1);
        comboBox_Lidar_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        label_5 = new QLabel(QGTCommunicationSet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 150, 110, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_Lidar_Baudrate = new QComboBox(QGTCommunicationSet);
        comboBox_Lidar_Baudrate->setObjectName(QStringLiteral("comboBox_Lidar_Baudrate"));
        comboBox_Lidar_Baudrate->setGeometry(QRect(390, 150, 100, 30));
        sizePolicy.setHeightForWidth(comboBox_Lidar_Baudrate->sizePolicy().hasHeightForWidth());
        comboBox_Lidar_Baudrate->setSizePolicy(sizePolicy);
        comboBox_Lidar_Baudrate->setFont(font1);
        comboBox_Lidar_Baudrate->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_LaserMeasure_Baudrate = new QComboBox(QGTCommunicationSet);
        comboBox_LaserMeasure_Baudrate->setObjectName(QStringLiteral("comboBox_LaserMeasure_Baudrate"));
        comboBox_LaserMeasure_Baudrate->setGeometry(QRect(390, 190, 100, 30));
        sizePolicy.setHeightForWidth(comboBox_LaserMeasure_Baudrate->sizePolicy().hasHeightForWidth());
        comboBox_LaserMeasure_Baudrate->setSizePolicy(sizePolicy);
        comboBox_LaserMeasure_Baudrate->setFont(font1);
        comboBox_LaserMeasure_Baudrate->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        label_6 = new QLabel(QGTCommunicationSet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 190, 110, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_LaserMeasure_Port = new QComboBox(QGTCommunicationSet);
        comboBox_LaserMeasure_Port->setObjectName(QStringLiteral("comboBox_LaserMeasure_Port"));
        comboBox_LaserMeasure_Port->setGeometry(QRect(170, 190, 200, 30));
        sizePolicy.setHeightForWidth(comboBox_LaserMeasure_Port->sizePolicy().hasHeightForWidth());
        comboBox_LaserMeasure_Port->setSizePolicy(sizePolicy);
        comboBox_LaserMeasure_Port->setFont(font1);
        comboBox_LaserMeasure_Port->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        comboBox_LiftPlatform_Baudrate = new QComboBox(QGTCommunicationSet);
        comboBox_LiftPlatform_Baudrate->setObjectName(QStringLiteral("comboBox_LiftPlatform_Baudrate"));
        comboBox_LiftPlatform_Baudrate->setGeometry(QRect(390, 250, 100, 30));
        sizePolicy.setHeightForWidth(comboBox_LiftPlatform_Baudrate->sizePolicy().hasHeightForWidth());
        comboBox_LiftPlatform_Baudrate->setSizePolicy(sizePolicy);
        comboBox_LiftPlatform_Baudrate->setFont(font1);
        comboBox_LiftPlatform_Baudrate->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        checkBox_IsSelect_Lidar_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_Lidar_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_Lidar_Connect"));
        checkBox_IsSelect_Lidar_Connect->setGeometry(QRect(10, 150, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_Lidar_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_Lidar_Connect->setSizePolicy(sizePolicy);
        checkBox_IsSelect_LaserMeasure_Connect = new QCheckBox(QGTCommunicationSet);
        checkBox_IsSelect_LaserMeasure_Connect->setObjectName(QStringLiteral("checkBox_IsSelect_LaserMeasure_Connect"));
        checkBox_IsSelect_LaserMeasure_Connect->setGeometry(QRect(10, 190, 20, 30));
        sizePolicy.setHeightForWidth(checkBox_IsSelect_LaserMeasure_Connect->sizePolicy().hasHeightForWidth());
        checkBox_IsSelect_LaserMeasure_Connect->setSizePolicy(sizePolicy);

        retranslateUi(QGTCommunicationSet);

        comboBox_LiftPlatform_Port->setCurrentIndex(-1);
        comboBox_Lidar_Port->setCurrentIndex(-1);
        comboBox_Lidar_Baudrate->setCurrentIndex(-1);
        comboBox_LaserMeasure_Baudrate->setCurrentIndex(-1);
        comboBox_LaserMeasure_Port->setCurrentIndex(-1);
        comboBox_LiftPlatform_Baudrate->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QGTCommunicationSet);
    } // setupUi

    void retranslateUi(QWidget *QGTCommunicationSet)
    {
        QGTCommunicationSet->setWindowTitle(QApplication::translate("QGTCommunicationSet", "QGTCommunicationSet", 0));
        label->setText(QApplication::translate("QGTCommunicationSet", "Chasis   Addr:", 0));
        label_3->setText(QApplication::translate("QGTCommunicationSet", "LiftPlat Addr:", 0));
        comboBox_LiftPlatform_Port->setCurrentText(QString());
        checkBox_IsSelect_LiftPlat_Connect->setText(QString());
        toolButton_Communication_Reset->setText(QApplication::translate("QGTCommunicationSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("QGTCommunicationSet", "Robot    Addr:", 0));
        checkBox_IsSelect_Chasis_Connect->setText(QString());
        checkBox_IsSelect_Robot_Connect->setText(QString());
        toolButton_Communication_Ok->setText(QApplication::translate("QGTCommunicationSet", "\344\277\235\345\255\230", 0));
        toolButton_Communication_Cancel->setText(QApplication::translate("QGTCommunicationSet", "\345\217\226\346\266\210", 0));
        checkBox_IsSelect_JoyHandle_Connect->setText(QApplication::translate("QGTCommunicationSet", " Is Connect JoyHandle", 0));
        checkBox_IsSelect_Ros_Connect->setText(QString());
        label_4->setText(QApplication::translate("QGTCommunicationSet", "Ros      Addr:", 0));
        comboBox_Lidar_Port->setCurrentText(QString());
        label_5->setText(QApplication::translate("QGTCommunicationSet", "Lidar    Addr:", 0));
        comboBox_Lidar_Baudrate->setCurrentText(QString());
        comboBox_LaserMeasure_Baudrate->setCurrentText(QString());
        label_6->setText(QApplication::translate("QGTCommunicationSet", "Laser    Addr:", 0));
        comboBox_LaserMeasure_Port->setCurrentText(QString());
        comboBox_LiftPlatform_Baudrate->setCurrentText(QString());
        checkBox_IsSelect_Lidar_Connect->setText(QString());
        checkBox_IsSelect_LaserMeasure_Connect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QGTCommunicationSet: public Ui_QGTCommunicationSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTCOMMUNICATIONSET_H
