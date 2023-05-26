/********************************************************************************
** Form generated from reading UI file 'qgtloginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTLOGINPAGE_H
#define UI_QGTLOGINPAGE_H

#include <Commen/qgttoolbutton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTLoginPage
{
public:
    QGTToolButton *toolButton_Login_Cancel;
    QGTToolButton *toolButton_Login_Ok;
    QStackedWidget *stackedWidget;
    QWidget *page_Login_Init;
    QComboBox *comboBox_Login_Username;
    QLabel *label;
    QLineEdit *lineEdit_Login_Password;
    QLabel *label_2;
    QWidget *page_Login_Over;
    QLabel *label_UserName;

    void setupUi(QWidget *QGTLoginPage)
    {
        if (QGTLoginPage->objectName().isEmpty())
            QGTLoginPage->setObjectName(QStringLiteral("QGTLoginPage"));
        QGTLoginPage->resize(400, 300);
        QGTLoginPage->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);"));
        toolButton_Login_Cancel = new QGTToolButton(QGTLoginPage);
        toolButton_Login_Cancel->setObjectName(QStringLiteral("toolButton_Login_Cancel"));
        toolButton_Login_Cancel->setGeometry(QRect(360, 0, 40, 40));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_Login_Cancel->sizePolicy().hasHeightForWidth());
        toolButton_Login_Cancel->setSizePolicy(sizePolicy);
        toolButton_Login_Cancel->setFocusPolicy(Qt::NoFocus);
        toolButton_Login_Cancel->setStyleSheet(QStringLiteral(""));
        toolButton_Login_Ok = new QGTToolButton(QGTLoginPage);
        toolButton_Login_Ok->setObjectName(QStringLiteral("toolButton_Login_Ok"));
        toolButton_Login_Ok->setGeometry(QRect(100, 220, 200, 50));
        sizePolicy.setHeightForWidth(toolButton_Login_Ok->sizePolicy().hasHeightForWidth());
        toolButton_Login_Ok->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        toolButton_Login_Ok->setFont(font);
        toolButton_Login_Ok->setFocusPolicy(Qt::NoFocus);
        toolButton_Login_Ok->setStyleSheet(QLatin1String("border-radius:10px;\n"
"padding:2px 4px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(38, 76, 115);"));
        stackedWidget = new QStackedWidget(QGTLoginPage);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 70, 360, 100));
        page_Login_Init = new QWidget();
        page_Login_Init->setObjectName(QStringLiteral("page_Login_Init"));
        comboBox_Login_Username = new QComboBox(page_Login_Init);
        comboBox_Login_Username->setObjectName(QStringLiteral("comboBox_Login_Username"));
        comboBox_Login_Username->setGeometry(QRect(130, 10, 200, 30));
        sizePolicy.setHeightForWidth(comboBox_Login_Username->sizePolicy().hasHeightForWidth());
        comboBox_Login_Username->setSizePolicy(sizePolicy);
        comboBox_Login_Username->setFont(font);
        comboBox_Login_Username->setStyleSheet(QLatin1String("color: rgb(85, 170, 255);\n"
""));
        label = new QLabel(page_Login_Init);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 100, 30));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        lineEdit_Login_Password = new QLineEdit(page_Login_Init);
        lineEdit_Login_Password->setObjectName(QStringLiteral("lineEdit_Login_Password"));
        lineEdit_Login_Password->setGeometry(QRect(130, 60, 200, 30));
        sizePolicy.setHeightForWidth(lineEdit_Login_Password->sizePolicy().hasHeightForWidth());
        lineEdit_Login_Password->setSizePolicy(sizePolicy);
        lineEdit_Login_Password->setFont(font);
        lineEdit_Login_Password->setFocusPolicy(Qt::StrongFocus);
        lineEdit_Login_Password->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        lineEdit_Login_Password->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(page_Login_Init);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 100, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        stackedWidget->addWidget(page_Login_Init);
        page_Login_Over = new QWidget();
        page_Login_Over->setObjectName(QStringLiteral("page_Login_Over"));
        label_UserName = new QLabel(page_Login_Over);
        label_UserName->setObjectName(QStringLiteral("label_UserName"));
        label_UserName->setGeometry(QRect(80, 35, 200, 30));
        label_UserName->setFont(font);
        label_UserName->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_UserName->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_Login_Over);
        QWidget::setTabOrder(lineEdit_Login_Password, comboBox_Login_Username);

        retranslateUi(QGTLoginPage);

        QMetaObject::connectSlotsByName(QGTLoginPage);
    } // setupUi

    void retranslateUi(QWidget *QGTLoginPage)
    {
        QGTLoginPage->setWindowTitle(QApplication::translate("QGTLoginPage", "QGTLoginPage", 0));
        toolButton_Login_Ok->setText(QApplication::translate("QGTLoginPage", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("QGTLoginPage", "Username :", 0));
        label_2->setText(QApplication::translate("QGTLoginPage", "Password :", 0));
        label_UserName->setText(QApplication::translate("QGTLoginPage", "Username :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTLoginPage: public Ui_QGTLoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTLOGINPAGE_H
