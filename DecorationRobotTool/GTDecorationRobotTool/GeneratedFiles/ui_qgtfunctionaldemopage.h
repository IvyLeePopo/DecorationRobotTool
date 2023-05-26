/********************************************************************************
** Form generated from reading UI file 'qgtfunctionaldemopage.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTFUNCTIONALDEMOPAGE_H
#define UI_QGTFUNCTIONALDEMOPAGE_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <qgtdemoplana.h>
#include <qgtdemoplanb.h>
#include <qgtdemoplanc.h>
#include <qgtdemopland.h>
#include <qgtdemoplane.h>
#include "qgtdemoplanf.h"

QT_BEGIN_NAMESPACE

class Ui_QGTFunctionalDemoPage
{
public:
    QFrame *line_SelectDemoPlan_A;
    QStackedWidget *stackedWidget;
    QGTDemoPlanA *DemoPlan_A;
    QGTDemoPlanB *DemoPlan_B;
    QGTDemoPlanC *DemoPlan_C;
    QGTDemoPlanD *DemoPlan_D;
    QGTDemoPlanE *DemoPlan_E;
    QGTDemoPlanF *DemoPlan_F;
    QGTToolButton *toolButton_SelectDemoPlan_B;
    QFrame *line_SelectDemoPlan_B;
    QFrame *line_SelectDemoPlan_C;
    QGTToolButton *toolButton_SelectDemoPlan_C;
    QGTToolButton *toolButton_SelectDemoPlan_A;
    QGTToolButton *toolButton_SelectDemoPlan_D;
    QFrame *line_SelectDemoPlan_D;
    QGTToolButton *toolButton_SelectDemoPlan_E;
    QFrame *line_SelectDemoPlan_E;
    QFrame *line_SelectDemoPlan_F;
    QGTToolButton *toolButton_SelectDemoPlan_F;

    void setupUi(QWidget *QGTFunctionalDemoPage)
    {
        if (QGTFunctionalDemoPage->objectName().isEmpty())
            QGTFunctionalDemoPage->setObjectName(QStringLiteral("QGTFunctionalDemoPage"));
        QGTFunctionalDemoPage->resize(1024, 640);
        line_SelectDemoPlan_A = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_A->setObjectName(QStringLiteral("line_SelectDemoPlan_A"));
        line_SelectDemoPlan_A->setGeometry(QRect(10, 35, 100, 1));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_A->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_A->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_A->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_A->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_A->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(QGTFunctionalDemoPage);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 50, 1024, 590));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        DemoPlan_A = new QGTDemoPlanA();
        DemoPlan_A->setObjectName(QStringLiteral("DemoPlan_A"));
        stackedWidget->addWidget(DemoPlan_A);
        DemoPlan_B = new QGTDemoPlanB();
        DemoPlan_B->setObjectName(QStringLiteral("DemoPlan_B"));
        stackedWidget->addWidget(DemoPlan_B);
        DemoPlan_C = new QGTDemoPlanC();
        DemoPlan_C->setObjectName(QStringLiteral("DemoPlan_C"));
        stackedWidget->addWidget(DemoPlan_C);
        DemoPlan_D = new QGTDemoPlanD();
        DemoPlan_D->setObjectName(QStringLiteral("DemoPlan_D"));
        stackedWidget->addWidget(DemoPlan_D);
        DemoPlan_E = new QGTDemoPlanE();
        DemoPlan_E->setObjectName(QStringLiteral("DemoPlan_E"));
        stackedWidget->addWidget(DemoPlan_E);
        DemoPlan_F = new QGTDemoPlanF();
        DemoPlan_F->setObjectName(QStringLiteral("DemoPlan_F"));
        stackedWidget->addWidget(DemoPlan_F);
        toolButton_SelectDemoPlan_B = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_B->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_B"));
        toolButton_SelectDemoPlan_B->setGeometry(QRect(140, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_B->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_B->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        toolButton_SelectDemoPlan_B->setFont(font);
        toolButton_SelectDemoPlan_B->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_SelectDemoPlan_B = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_B->setObjectName(QStringLiteral("line_SelectDemoPlan_B"));
        line_SelectDemoPlan_B->setGeometry(QRect(150, 35, 100, 1));
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_B->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_B->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_B->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_B->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_B->setFrameShadow(QFrame::Sunken);
        line_SelectDemoPlan_C = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_C->setObjectName(QStringLiteral("line_SelectDemoPlan_C"));
        line_SelectDemoPlan_C->setGeometry(QRect(290, 35, 100, 1));
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_C->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_C->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_C->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_C->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_C->setFrameShadow(QFrame::Sunken);
        toolButton_SelectDemoPlan_C = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_C->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_C"));
        toolButton_SelectDemoPlan_C->setGeometry(QRect(280, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_C->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_C->setSizePolicy(sizePolicy);
        toolButton_SelectDemoPlan_C->setFont(font);
        toolButton_SelectDemoPlan_C->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_SelectDemoPlan_A = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_A->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_A"));
        toolButton_SelectDemoPlan_A->setGeometry(QRect(0, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_A->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_A->setSizePolicy(sizePolicy);
        toolButton_SelectDemoPlan_A->setFont(font);
        toolButton_SelectDemoPlan_A->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_SelectDemoPlan_D = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_D->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_D"));
        toolButton_SelectDemoPlan_D->setGeometry(QRect(420, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_D->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_D->setSizePolicy(sizePolicy);
        toolButton_SelectDemoPlan_D->setFont(font);
        toolButton_SelectDemoPlan_D->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_SelectDemoPlan_D = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_D->setObjectName(QStringLiteral("line_SelectDemoPlan_D"));
        line_SelectDemoPlan_D->setGeometry(QRect(430, 35, 100, 1));
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_D->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_D->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_D->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_D->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_D->setFrameShadow(QFrame::Sunken);
        toolButton_SelectDemoPlan_E = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_E->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_E"));
        toolButton_SelectDemoPlan_E->setGeometry(QRect(560, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_E->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_E->setSizePolicy(sizePolicy);
        toolButton_SelectDemoPlan_E->setFont(font);
        toolButton_SelectDemoPlan_E->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        line_SelectDemoPlan_E = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_E->setObjectName(QStringLiteral("line_SelectDemoPlan_E"));
        line_SelectDemoPlan_E->setGeometry(QRect(570, 35, 100, 1));
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_E->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_E->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_E->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_E->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_E->setFrameShadow(QFrame::Sunken);
        line_SelectDemoPlan_F = new QFrame(QGTFunctionalDemoPage);
        line_SelectDemoPlan_F->setObjectName(QStringLiteral("line_SelectDemoPlan_F"));
        line_SelectDemoPlan_F->setGeometry(QRect(710, 35, 100, 1));
        sizePolicy.setHeightForWidth(line_SelectDemoPlan_F->sizePolicy().hasHeightForWidth());
        line_SelectDemoPlan_F->setSizePolicy(sizePolicy);
        line_SelectDemoPlan_F->setStyleSheet(QStringLiteral("background-color: rgb(85, 135, 198);"));
        line_SelectDemoPlan_F->setFrameShape(QFrame::HLine);
        line_SelectDemoPlan_F->setFrameShadow(QFrame::Sunken);
        toolButton_SelectDemoPlan_F = new QGTToolButton(QGTFunctionalDemoPage);
        toolButton_SelectDemoPlan_F->setObjectName(QStringLiteral("toolButton_SelectDemoPlan_F"));
        toolButton_SelectDemoPlan_F->setGeometry(QRect(700, 0, 120, 30));
        sizePolicy.setHeightForWidth(toolButton_SelectDemoPlan_F->sizePolicy().hasHeightForWidth());
        toolButton_SelectDemoPlan_F->setSizePolicy(sizePolicy);
        toolButton_SelectDemoPlan_F->setFont(font);
        toolButton_SelectDemoPlan_F->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));

        retranslateUi(QGTFunctionalDemoPage);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(QGTFunctionalDemoPage);
    } // setupUi

    void retranslateUi(QWidget *QGTFunctionalDemoPage)
    {
        QGTFunctionalDemoPage->setWindowTitle(QApplication::translate("QGTFunctionalDemoPage", "QGTFunctionalDemoPage", 0));
        toolButton_SelectDemoPlan_B->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan B", 0));
        toolButton_SelectDemoPlan_C->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan C", 0));
        toolButton_SelectDemoPlan_A->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan A", 0));
        toolButton_SelectDemoPlan_D->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan D", 0));
        toolButton_SelectDemoPlan_E->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan E", 0));
        toolButton_SelectDemoPlan_F->setText(QApplication::translate("QGTFunctionalDemoPage", " Plan F", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTFunctionalDemoPage: public Ui_QGTFunctionalDemoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTFUNCTIONALDEMOPAGE_H
