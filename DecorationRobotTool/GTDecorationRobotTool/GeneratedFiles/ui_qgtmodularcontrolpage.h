/********************************************************************************
** Form generated from reading UI file 'qgtmodularcontrolpage.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTMODULARCONTROLPAGE_H
#define UI_QGTMODULARCONTROLPAGE_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <qgtchasismodule.h>
#include <qgtjoyhandlemodule.h>
#include <qgtliftplatmodule.h>
#include <qgtrobotmodule.h>

QT_BEGIN_NAMESPACE

class Ui_QGTModularControlPage
{
public:
    QGTToolButton *toolButton_SelectModule_JoyHandle;
    QGTToolButton *toolButton_SelectModule_LiftPlat;
    QFrame *line_Module_LiftPlat;
    QStackedWidget *stackedWidget;
    QGTChasisModule *Module_Chasis;
    QGTLiftPlatModule *Module_LiftPlat;
    QGTRobotModule *Module_Robot;
    QGTJoyHandleModule *Module_JoyHandle;
    QGTToolButton *toolButton_SelectModule_Robot;
    QFrame *line_Module_Robot;
    QFrame *line_Module_Chasis;
    QGTToolButton *toolButton_SelectModule_Chasis;
    QFrame *line_Module_JoyHandle;

    void setupUi(QWidget *QGTModularControlPage)
    {
        if (QGTModularControlPage->objectName().isEmpty())
            QGTModularControlPage->setObjectName(QStringLiteral("QGTModularControlPage"));
        QGTModularControlPage->resize(1024, 640);
        toolButton_SelectModule_JoyHandle = new QGTToolButton(QGTModularControlPage);
        toolButton_SelectModule_JoyHandle->setObjectName(QStringLiteral("toolButton_SelectModule_JoyHandle"));
        toolButton_SelectModule_JoyHandle->setGeometry(QRect(420, 5, 120, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_SelectModule_JoyHandle->sizePolicy().hasHeightForWidth());
        toolButton_SelectModule_JoyHandle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        toolButton_SelectModule_JoyHandle->setFont(font);
        toolButton_SelectModule_JoyHandle->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_SelectModule_LiftPlat = new QGTToolButton(QGTModularControlPage);
        toolButton_SelectModule_LiftPlat->setObjectName(QStringLiteral("toolButton_SelectModule_LiftPlat"));
        toolButton_SelectModule_LiftPlat->setGeometry(QRect(140, 5, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectModule_LiftPlat->sizePolicy().hasHeightForWidth());
        toolButton_SelectModule_LiftPlat->setSizePolicy(sizePolicy);
        toolButton_SelectModule_LiftPlat->setFont(font);
        toolButton_SelectModule_LiftPlat->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_Module_LiftPlat = new QFrame(QGTModularControlPage);
        line_Module_LiftPlat->setObjectName(QStringLiteral("line_Module_LiftPlat"));
        line_Module_LiftPlat->setGeometry(QRect(150, 40, 100, 1));
        sizePolicy.setHeightForWidth(line_Module_LiftPlat->sizePolicy().hasHeightForWidth());
        line_Module_LiftPlat->setSizePolicy(sizePolicy);
        line_Module_LiftPlat->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_Module_LiftPlat->setFrameShape(QFrame::HLine);
        line_Module_LiftPlat->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(QGTModularControlPage);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 55, 1024, 580));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        Module_Chasis = new QGTChasisModule();
        Module_Chasis->setObjectName(QStringLiteral("Module_Chasis"));
        stackedWidget->addWidget(Module_Chasis);
        Module_LiftPlat = new QGTLiftPlatModule();
        Module_LiftPlat->setObjectName(QStringLiteral("Module_LiftPlat"));
        stackedWidget->addWidget(Module_LiftPlat);
        Module_Robot = new QGTRobotModule();
        Module_Robot->setObjectName(QStringLiteral("Module_Robot"));
        stackedWidget->addWidget(Module_Robot);
        Module_JoyHandle = new QGTJoyHandleModule();
        Module_JoyHandle->setObjectName(QStringLiteral("Module_JoyHandle"));
        stackedWidget->addWidget(Module_JoyHandle);
        toolButton_SelectModule_Robot = new QGTToolButton(QGTModularControlPage);
        toolButton_SelectModule_Robot->setObjectName(QStringLiteral("toolButton_SelectModule_Robot"));
        toolButton_SelectModule_Robot->setGeometry(QRect(280, 5, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectModule_Robot->sizePolicy().hasHeightForWidth());
        toolButton_SelectModule_Robot->setSizePolicy(sizePolicy);
        toolButton_SelectModule_Robot->setFont(font);
        toolButton_SelectModule_Robot->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_Module_Robot = new QFrame(QGTModularControlPage);
        line_Module_Robot->setObjectName(QStringLiteral("line_Module_Robot"));
        line_Module_Robot->setGeometry(QRect(290, 40, 100, 1));
        sizePolicy.setHeightForWidth(line_Module_Robot->sizePolicy().hasHeightForWidth());
        line_Module_Robot->setSizePolicy(sizePolicy);
        line_Module_Robot->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_Module_Robot->setFrameShape(QFrame::HLine);
        line_Module_Robot->setFrameShadow(QFrame::Sunken);
        line_Module_Chasis = new QFrame(QGTModularControlPage);
        line_Module_Chasis->setObjectName(QStringLiteral("line_Module_Chasis"));
        line_Module_Chasis->setGeometry(QRect(10, 40, 100, 1));
        sizePolicy.setHeightForWidth(line_Module_Chasis->sizePolicy().hasHeightForWidth());
        line_Module_Chasis->setSizePolicy(sizePolicy);
        line_Module_Chasis->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_Module_Chasis->setFrameShape(QFrame::HLine);
        line_Module_Chasis->setFrameShadow(QFrame::Sunken);
        toolButton_SelectModule_Chasis = new QGTToolButton(QGTModularControlPage);
        toolButton_SelectModule_Chasis->setObjectName(QStringLiteral("toolButton_SelectModule_Chasis"));
        toolButton_SelectModule_Chasis->setGeometry(QRect(0, 5, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectModule_Chasis->sizePolicy().hasHeightForWidth());
        toolButton_SelectModule_Chasis->setSizePolicy(sizePolicy);
        toolButton_SelectModule_Chasis->setFont(font);
        toolButton_SelectModule_Chasis->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_Module_JoyHandle = new QFrame(QGTModularControlPage);
        line_Module_JoyHandle->setObjectName(QStringLiteral("line_Module_JoyHandle"));
        line_Module_JoyHandle->setGeometry(QRect(430, 40, 100, 1));
        sizePolicy.setHeightForWidth(line_Module_JoyHandle->sizePolicy().hasHeightForWidth());
        line_Module_JoyHandle->setSizePolicy(sizePolicy);
        line_Module_JoyHandle->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_Module_JoyHandle->setFrameShape(QFrame::HLine);
        line_Module_JoyHandle->setFrameShadow(QFrame::Sunken);

        retranslateUi(QGTModularControlPage);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(QGTModularControlPage);
    } // setupUi

    void retranslateUi(QWidget *QGTModularControlPage)
    {
        QGTModularControlPage->setWindowTitle(QApplication::translate("QGTModularControlPage", "QGTModularControlPage", 0));
        toolButton_SelectModule_JoyHandle->setText(QApplication::translate("QGTModularControlPage", "JoyHandle", 0));
        toolButton_SelectModule_LiftPlat->setText(QApplication::translate("QGTModularControlPage", "LiftPlat", 0));
        toolButton_SelectModule_Robot->setText(QApplication::translate("QGTModularControlPage", "Robot", 0));
        toolButton_SelectModule_Chasis->setText(QApplication::translate("QGTModularControlPage", "Chasis", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTModularControlPage: public Ui_QGTModularControlPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTMODULARCONTROLPAGE_H
