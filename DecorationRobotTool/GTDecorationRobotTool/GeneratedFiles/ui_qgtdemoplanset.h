/********************************************************************************
** Form generated from reading UI file 'qgtdemoplanset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTDEMOPLANSET_H
#define UI_QGTDEMOPLANSET_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTDemoPlanSet
{
public:
    QLabel *label_3;
    QGTToolButton *toolButton_DemoPlanSet_Reset;
    QGTToolButton *toolButton_DemoPlanSet_Cancel;
    QGTToolButton *toolButton_DemoPlanSet_Ok;
    QComboBox *comboBox_DemoPlanSet_Select;
    QTextEdit *textEditDemoPlanSet_View;
    QLabel *label_4;

    void setupUi(QWidget *QGTDemoPlanSet)
    {
        if (QGTDemoPlanSet->objectName().isEmpty())
            QGTDemoPlanSet->setObjectName(QStringLiteral("QGTDemoPlanSet"));
        QGTDemoPlanSet->resize(500, 300);
        QGTDemoPlanSet->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        label_3 = new QLabel(QGTDemoPlanSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 160, 30));
        QFont font;
        font.setPointSize(15);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));
        toolButton_DemoPlanSet_Reset = new QGTToolButton(QGTDemoPlanSet);
        toolButton_DemoPlanSet_Reset->setObjectName(QStringLiteral("toolButton_DemoPlanSet_Reset"));
        toolButton_DemoPlanSet_Reset->setGeometry(QRect(10, 240, 100, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_DemoPlanSet_Reset->sizePolicy().hasHeightForWidth());
        toolButton_DemoPlanSet_Reset->setSizePolicy(sizePolicy);
        toolButton_DemoPlanSet_Reset->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_DemoPlanSet_Cancel = new QGTToolButton(QGTDemoPlanSet);
        toolButton_DemoPlanSet_Cancel->setObjectName(QStringLiteral("toolButton_DemoPlanSet_Cancel"));
        toolButton_DemoPlanSet_Cancel->setGeometry(QRect(390, 240, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_DemoPlanSet_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_DemoPlanSet_Cancel->setSizePolicy(sizePolicy);
        toolButton_DemoPlanSet_Cancel->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        toolButton_DemoPlanSet_Ok = new QGTToolButton(QGTDemoPlanSet);
        toolButton_DemoPlanSet_Ok->setObjectName(QStringLiteral("toolButton_DemoPlanSet_Ok"));
        toolButton_DemoPlanSet_Ok->setGeometry(QRect(280, 240, 100, 50));
        sizePolicy.setHeightForWidth(toolButton_DemoPlanSet_Ok->sizePolicy().hasHeightForWidth());
        toolButton_DemoPlanSet_Ok->setSizePolicy(sizePolicy);
        toolButton_DemoPlanSet_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        comboBox_DemoPlanSet_Select = new QComboBox(QGTDemoPlanSet);
        comboBox_DemoPlanSet_Select->setObjectName(QStringLiteral("comboBox_DemoPlanSet_Select"));
        comboBox_DemoPlanSet_Select->setGeometry(QRect(180, 30, 100, 30));
        sizePolicy.setHeightForWidth(comboBox_DemoPlanSet_Select->sizePolicy().hasHeightForWidth());
        comboBox_DemoPlanSet_Select->setSizePolicy(sizePolicy);
        comboBox_DemoPlanSet_Select->setFont(font);
        comboBox_DemoPlanSet_Select->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        textEditDemoPlanSet_View = new QTextEdit(QGTDemoPlanSet);
        textEditDemoPlanSet_View->setObjectName(QStringLiteral("textEditDemoPlanSet_View"));
        textEditDemoPlanSet_View->setGeometry(QRect(170, 90, 320, 120));
        sizePolicy.setHeightForWidth(textEditDemoPlanSet_View->sizePolicy().hasHeightForWidth());
        textEditDemoPlanSet_View->setSizePolicy(sizePolicy);
        textEditDemoPlanSet_View->setFont(font);
        textEditDemoPlanSet_View->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        textEditDemoPlanSet_View->setFrameShape(QFrame::NoFrame);
        textEditDemoPlanSet_View->setReadOnly(true);
        label_4 = new QLabel(QGTDemoPlanSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 90, 160, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(135, 206, 250);"));

        retranslateUi(QGTDemoPlanSet);

        comboBox_DemoPlanSet_Select->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QGTDemoPlanSet);
    } // setupUi

    void retranslateUi(QWidget *QGTDemoPlanSet)
    {
        QGTDemoPlanSet->setWindowTitle(QApplication::translate("QGTDemoPlanSet", "QGTDemoPlanSet", 0));
        label_3->setText(QApplication::translate("QGTDemoPlanSet", "\346\274\224\347\244\272\346\226\271\346\241\210\351\200\211\346\213\251 :", 0));
        toolButton_DemoPlanSet_Reset->setText(QApplication::translate("QGTDemoPlanSet", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        toolButton_DemoPlanSet_Cancel->setText(QApplication::translate("QGTDemoPlanSet", "\345\217\226\346\266\210", 0));
        toolButton_DemoPlanSet_Ok->setText(QApplication::translate("QGTDemoPlanSet", "\344\277\235\345\255\230", 0));
        comboBox_DemoPlanSet_Select->setCurrentText(QString());
        label_4->setText(QApplication::translate("QGTDemoPlanSet", "\346\274\224\347\244\272\346\226\271\346\241\210\346\217\217\350\277\260 :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTDemoPlanSet: public Ui_QGTDemoPlanSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTDEMOPLANSET_H
