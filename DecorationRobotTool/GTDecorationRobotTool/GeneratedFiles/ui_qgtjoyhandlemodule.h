/********************************************************************************
** Form generated from reading UI file 'qgtjoyhandlemodule.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTJOYHANDLEMODULE_H
#define UI_QGTJOYHANDLEMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTJoyHandleModule
{
public:
    QLabel *label_JoyHandle_Pov_Status;
    QLabel *label;
    QLabel *label_JoyHandle_Button_Status;
    QLabel *label_2;

    void setupUi(QWidget *QGTJoyHandleModule)
    {
        if (QGTJoyHandleModule->objectName().isEmpty())
            QGTJoyHandleModule->setObjectName(QStringLiteral("QGTJoyHandleModule"));
        QGTJoyHandleModule->resize(1024, 590);
        label_JoyHandle_Pov_Status = new QLabel(QGTJoyHandleModule);
        label_JoyHandle_Pov_Status->setObjectName(QStringLiteral("label_JoyHandle_Pov_Status"));
        label_JoyHandle_Pov_Status->setGeometry(QRect(160, 60, 300, 30));
        QFont font;
        font.setPointSize(15);
        label_JoyHandle_Pov_Status->setFont(font);
        label_JoyHandle_Pov_Status->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_JoyHandle_Pov_Status->setAlignment(Qt::AlignCenter);
        label = new QLabel(QGTJoyHandleModule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 150, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_JoyHandle_Button_Status = new QLabel(QGTJoyHandleModule);
        label_JoyHandle_Button_Status->setObjectName(QStringLiteral("label_JoyHandle_Button_Status"));
        label_JoyHandle_Button_Status->setGeometry(QRect(160, 10, 300, 30));
        label_JoyHandle_Button_Status->setFont(font);
        label_JoyHandle_Button_Status->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_JoyHandle_Button_Status->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(QGTJoyHandleModule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 150, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        retranslateUi(QGTJoyHandleModule);

        QMetaObject::connectSlotsByName(QGTJoyHandleModule);
    } // setupUi

    void retranslateUi(QWidget *QGTJoyHandleModule)
    {
        QGTJoyHandleModule->setWindowTitle(QApplication::translate("QGTJoyHandleModule", "QGTJoyHandleModule", 0));
        label_JoyHandle_Pov_Status->setText(QApplication::translate("QGTJoyHandleModule", "NULL", 0));
        label->setText(QApplication::translate("QGTJoyHandleModule", "\346\211\213\346\237\204\346\214\211\351\222\256\347\212\266\346\200\201 :", 0));
        label_JoyHandle_Button_Status->setText(QApplication::translate("QGTJoyHandleModule", "NULL", 0));
        label_2->setText(QApplication::translate("QGTJoyHandleModule", "\346\211\213\346\237\204\346\221\207\346\235\206\347\212\266\346\200\201 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTJoyHandleModule: public Ui_QGTJoyHandleModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTJOYHANDLEMODULE_H
