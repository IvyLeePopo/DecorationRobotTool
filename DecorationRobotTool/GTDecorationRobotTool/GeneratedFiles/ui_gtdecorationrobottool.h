/********************************************************************************
** Form generated from reading UI file 'gtdecorationrobottool.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GTDECORATIONROBOTTOOL_H
#define UI_GTDECORATIONROBOTTOOL_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <qgtfunctionaldemopage.h>
#include <qgtmodularcontrolpage.h>

QT_BEGIN_NAMESPACE

class Ui_GTDecorationRobotToolClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGTToolButton *toolButton_Login;
    QGTToolButton *toolButton_MiniSize;
    QGTToolButton *toolButton_Exit;
    QStackedWidget *stackedWidget;
    QGTFunctionalDemoPage *page_FunctionalDemo;
    QGTModularControlPage *page_ModularControl;
    QWidget *widget_2;
    QGTToolButton *toolButton_Select_FunctionalDemo;
    QGTToolButton *toolButton_Select_ModularControl;
    QGTToolButton *toolButton_BaseSet;
    QGTToolButton *toolButton_Auto_Run;

    void setupUi(QMainWindow *GTDecorationRobotToolClass)
    {
        if (GTDecorationRobotToolClass->objectName().isEmpty())
            GTDecorationRobotToolClass->setObjectName(QStringLiteral("GTDecorationRobotToolClass"));
        GTDecorationRobotToolClass->resize(1024, 800);
        centralWidget = new QWidget(GTDecorationRobotToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1024, 768));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BackGround.png);"));
        toolButton_Login = new QGTToolButton(widget);
        toolButton_Login->setObjectName(QStringLiteral("toolButton_Login"));
        toolButton_Login->setGeometry(QRect(10, 10, 150, 40));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_Login->sizePolicy().hasHeightForWidth());
        toolButton_Login->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        toolButton_Login->setFont(font);
        toolButton_Login->setFocusPolicy(Qt::NoFocus);
        toolButton_Login->setStyleSheet(QLatin1String("border:2px groove gray;\n"
"border-radius:16px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_Login->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_MiniSize = new QGTToolButton(widget);
        toolButton_MiniSize->setObjectName(QStringLiteral("toolButton_MiniSize"));
        toolButton_MiniSize->setGeometry(QRect(940, 10, 40, 40));
        sizePolicy.setHeightForWidth(toolButton_MiniSize->sizePolicy().hasHeightForWidth());
        toolButton_MiniSize->setSizePolicy(sizePolicy);
        toolButton_MiniSize->setFocusPolicy(Qt::NoFocus);
        toolButton_MiniSize->setStyleSheet(QStringLiteral(""));
        toolButton_Exit = new QGTToolButton(widget);
        toolButton_Exit->setObjectName(QStringLiteral("toolButton_Exit"));
        toolButton_Exit->setGeometry(QRect(980, 10, 40, 40));
        sizePolicy.setHeightForWidth(toolButton_Exit->sizePolicy().hasHeightForWidth());
        toolButton_Exit->setSizePolicy(sizePolicy);
        toolButton_Exit->setFocusPolicy(Qt::NoFocus);
        toolButton_Exit->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 127, 1024, 640));
        page_FunctionalDemo = new QGTFunctionalDemoPage();
        page_FunctionalDemo->setObjectName(QStringLiteral("page_FunctionalDemo"));
        page_FunctionalDemo->setStyleSheet(QStringLiteral("background-image: url(:/PaintRobotTool/Resources/ui_BaseSet.png);"));
        stackedWidget->addWidget(page_FunctionalDemo);
        page_ModularControl = new QGTModularControlPage();
        page_ModularControl->setObjectName(QStringLiteral("page_ModularControl"));
        page_ModularControl->setStyleSheet(QStringLiteral("background-image: url(:/PaintRobotTool/Resources/ui_BaseSet.png);"));
        stackedWidget->addWidget(page_ModularControl);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 61, 200, 60));
        widget_2->setStyleSheet(QStringLiteral("background-image: url(:/PaintRobotTool/Resources/ui_BaseSet.png);"));
        toolButton_Select_FunctionalDemo = new QGTToolButton(widget_2);
        toolButton_Select_FunctionalDemo->setObjectName(QStringLiteral("toolButton_Select_FunctionalDemo"));
        toolButton_Select_FunctionalDemo->setGeometry(QRect(0, 0, 60, 60));
        sizePolicy.setHeightForWidth(toolButton_Select_FunctionalDemo->sizePolicy().hasHeightForWidth());
        toolButton_Select_FunctionalDemo->setSizePolicy(sizePolicy);
        toolButton_Select_FunctionalDemo->setFont(font);
        toolButton_Select_FunctionalDemo->setFocusPolicy(Qt::NoFocus);
        toolButton_Select_FunctionalDemo->setStyleSheet(QLatin1String("border-radius:30px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(135, 206, 235);"));
        toolButton_Select_FunctionalDemo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_Select_ModularControl = new QGTToolButton(widget_2);
        toolButton_Select_ModularControl->setObjectName(QStringLiteral("toolButton_Select_ModularControl"));
        toolButton_Select_ModularControl->setGeometry(QRect(70, 0, 60, 60));
        sizePolicy.setHeightForWidth(toolButton_Select_ModularControl->sizePolicy().hasHeightForWidth());
        toolButton_Select_ModularControl->setSizePolicy(sizePolicy);
        toolButton_Select_ModularControl->setFont(font);
        toolButton_Select_ModularControl->setFocusPolicy(Qt::NoFocus);
        toolButton_Select_ModularControl->setStyleSheet(QLatin1String("border-radius:30px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(135, 206, 235);\n"
""));
        toolButton_Select_ModularControl->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_BaseSet = new QGTToolButton(widget);
        toolButton_BaseSet->setObjectName(QStringLiteral("toolButton_BaseSet"));
        toolButton_BaseSet->setGeometry(QRect(830, 10, 40, 40));
        sizePolicy.setHeightForWidth(toolButton_BaseSet->sizePolicy().hasHeightForWidth());
        toolButton_BaseSet->setSizePolicy(sizePolicy);
        toolButton_BaseSet->setFocusPolicy(Qt::NoFocus);
        toolButton_BaseSet->setStyleSheet(QStringLiteral(""));
        toolButton_Auto_Run = new QGTToolButton(widget);
        toolButton_Auto_Run->setObjectName(QStringLiteral("toolButton_Auto_Run"));
        toolButton_Auto_Run->setGeometry(QRect(490, 20, 60, 60));
        sizePolicy.setHeightForWidth(toolButton_Auto_Run->sizePolicy().hasHeightForWidth());
        toolButton_Auto_Run->setSizePolicy(sizePolicy);
        GTDecorationRobotToolClass->setCentralWidget(centralWidget);

        retranslateUi(GTDecorationRobotToolClass);

        QMetaObject::connectSlotsByName(GTDecorationRobotToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *GTDecorationRobotToolClass)
    {
        GTDecorationRobotToolClass->setWindowTitle(QApplication::translate("GTDecorationRobotToolClass", "GTDecorationRobotTool", 0));
        toolButton_Login->setText(QApplication::translate("GTDecorationRobotToolClass", "\350\243\205\344\277\256\346\234\272\345\231\250\344\272\272", 0));
        toolButton_Select_FunctionalDemo->setText(QApplication::translate("GTDecorationRobotToolClass", "\346\274\224\347\244\272", 0));
        toolButton_Select_ModularControl->setText(QApplication::translate("GTDecorationRobotToolClass", "\346\216\247\345\210\266", 0));
    } // retranslateUi

};

namespace Ui {
    class GTDecorationRobotToolClass: public Ui_GTDecorationRobotToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GTDECORATIONROBOTTOOL_H
