/********************************************************************************
** Form generated from reading UI file 'qgtdemoplana.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTDEMOPLANA_H
#define UI_QGTDEMOPLANA_H

#include <Commen/qgtchasiswheelview.h>
#include <Commen/qgtimageview.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGTDemoPlanA
{
public:
    QLabel *label_LiftPlat_Height;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_LeftWheel_Dis;
    QLabel *label_3;
    QLabel *label_RightWheel_Angle;
    QGTImageView *graphicsView;
    QLabel *label_6;
    QLabel *label_LeftWheel_Speed;
    QLabel *label_Dis_Offset;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_Angle_Offset;
    QLabel *label_RightWheel_Dis;
    QLabel *label_RightWheel_Speed;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_LeftWheel_Angle;
    QLabel *label_ChasisFrame;
    QGTChasisWheelView *label_RightWheel;
    QGTChasisWheelView *label_LeftWheel;

    void setupUi(QWidget *QGTDemoPlanA)
    {
        if (QGTDemoPlanA->objectName().isEmpty())
            QGTDemoPlanA->setObjectName(QStringLiteral("QGTDemoPlanA"));
        QGTDemoPlanA->resize(1024, 590);
        label_LiftPlat_Height = new QLabel(QGTDemoPlanA);
        label_LiftPlat_Height->setObjectName(QStringLiteral("label_LiftPlat_Height"));
        label_LiftPlat_Height->setGeometry(QRect(580, 540, 80, 30));
        label_LiftPlat_Height->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_2 = new QLabel(QGTDemoPlanA);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 500, 60, 30));
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10 = new QLabel(QGTDemoPlanA);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(580, 500, 80, 30));
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Dis = new QLabel(QGTDemoPlanA);
        label_LeftWheel_Dis->setObjectName(QStringLiteral("label_LeftWheel_Dis"));
        label_LeftWheel_Dis->setGeometry(QRect(300, 540, 60, 30));
        label_LeftWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTDemoPlanA);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 500, 60, 30));
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RightWheel_Angle = new QLabel(QGTDemoPlanA);
        label_RightWheel_Angle->setObjectName(QStringLiteral("label_RightWheel_Angle"));
        label_RightWheel_Angle->setGeometry(QRect(370, 540, 60, 30));
        label_RightWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        graphicsView = new QGTImageView(QGTDemoPlanA);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 640, 480));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        label_6 = new QLabel(QGTDemoPlanA);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 500, 60, 30));
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Speed = new QLabel(QGTDemoPlanA);
        label_LeftWheel_Speed->setObjectName(QStringLiteral("label_LeftWheel_Speed"));
        label_LeftWheel_Speed->setGeometry(QRect(230, 540, 60, 30));
        label_LeftWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Dis_Offset = new QLabel(QGTDemoPlanA);
        label_Dis_Offset->setObjectName(QStringLiteral("label_Dis_Offset"));
        label_Dis_Offset->setGeometry(QRect(90, 540, 60, 30));
        label_Dis_Offset->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7 = new QLabel(QGTDemoPlanA);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 500, 60, 30));
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_9 = new QLabel(QGTDemoPlanA);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(510, 500, 60, 30));
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Angle_Offset = new QLabel(QGTDemoPlanA);
        label_Angle_Offset->setObjectName(QStringLiteral("label_Angle_Offset"));
        label_Angle_Offset->setGeometry(QRect(20, 540, 60, 30));
        label_Angle_Offset->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RightWheel_Dis = new QLabel(QGTDemoPlanA);
        label_RightWheel_Dis->setObjectName(QStringLiteral("label_RightWheel_Dis"));
        label_RightWheel_Dis->setGeometry(QRect(510, 540, 60, 30));
        label_RightWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RightWheel_Speed = new QLabel(QGTDemoPlanA);
        label_RightWheel_Speed->setObjectName(QStringLiteral("label_RightWheel_Speed"));
        label_RightWheel_Speed->setGeometry(QRect(440, 540, 60, 30));
        label_RightWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_8 = new QLabel(QGTDemoPlanA);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 500, 60, 30));
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_4 = new QLabel(QGTDemoPlanA);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 500, 60, 30));
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_5 = new QLabel(QGTDemoPlanA);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 500, 60, 30));
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Angle = new QLabel(QGTDemoPlanA);
        label_LeftWheel_Angle->setObjectName(QStringLiteral("label_LeftWheel_Angle"));
        label_LeftWheel_Angle->setGeometry(QRect(160, 540, 60, 30));
        label_LeftWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_ChasisFrame = new QLabel(QGTDemoPlanA);
        label_ChasisFrame->setObjectName(QStringLiteral("label_ChasisFrame"));
        label_ChasisFrame->setGeometry(QRect(770, 20, 240, 420));
        label_ChasisFrame->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/ChasisFrame.png);"));
        label_RightWheel = new QGTChasisWheelView(QGTDemoPlanA);
        label_RightWheel->setObjectName(QStringLiteral("label_RightWheel"));
        label_RightWheel->setGeometry(QRect(830, 270, 120, 120));
        sizePolicy.setHeightForWidth(label_RightWheel->sizePolicy().hasHeightForWidth());
        label_RightWheel->setSizePolicy(sizePolicy);
        label_RightWheel->setFrameShape(QFrame::NoFrame);
        label_LeftWheel = new QGTChasisWheelView(QGTDemoPlanA);
        label_LeftWheel->setObjectName(QStringLiteral("label_LeftWheel"));
        label_LeftWheel->setGeometry(QRect(830, 70, 120, 120));
        sizePolicy.setHeightForWidth(label_LeftWheel->sizePolicy().hasHeightForWidth());
        label_LeftWheel->setSizePolicy(sizePolicy);
        label_LeftWheel->setStyleSheet(QStringLiteral(""));
        label_LeftWheel->setFrameShape(QFrame::NoFrame);

        retranslateUi(QGTDemoPlanA);

        QMetaObject::connectSlotsByName(QGTDemoPlanA);
    } // setupUi

    void retranslateUi(QWidget *QGTDemoPlanA)
    {
        QGTDemoPlanA->setWindowTitle(QApplication::translate("QGTDemoPlanA", "QGTDemoPlanA", 0));
        label_LiftPlat_Height->setText(QApplication::translate("QGTDemoPlanA", "\345\215\207\351\231\215\345\271\263\345\217\260\351\253\230\345\272\246", 0));
        label_2->setText(QApplication::translate("QGTDemoPlanA", "\345\201\217\347\247\273\350\247\222\345\272\246", 0));
        label_10->setText(QApplication::translate("QGTDemoPlanA", "\345\215\207\351\231\215\345\271\263\345\217\260\351\253\230\345\272\246", 0));
        label_LeftWheel_Dis->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\350\241\214\347\250\213", 0));
        label_3->setText(QApplication::translate("QGTDemoPlanA", "\345\201\217\347\247\273\350\267\235\347\246\273", 0));
        label_RightWheel_Angle->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\350\247\222\345\272\246", 0));
        label_6->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\350\247\222\345\272\246", 0));
        label_LeftWheel_Speed->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\351\200\237\345\272\246", 0));
        label_Dis_Offset->setText(QApplication::translate("QGTDemoPlanA", "\345\201\217\347\247\273\350\267\235\347\246\273", 0));
        label_7->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\351\200\237\345\272\246", 0));
        label_9->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\350\241\214\347\250\213", 0));
        label_Angle_Offset->setText(QApplication::translate("QGTDemoPlanA", "\345\201\217\347\247\273\350\247\222\345\272\246", 0));
        label_RightWheel_Dis->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\350\241\214\347\250\213", 0));
        label_RightWheel_Speed->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256\351\200\237\345\272\246", 0));
        label_8->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\350\241\214\347\250\213", 0));
        label_4->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\350\247\222\345\272\246", 0));
        label_5->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\351\200\237\345\272\246", 0));
        label_LeftWheel_Angle->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256\350\247\222\345\272\246", 0));
        label_ChasisFrame->setText(QApplication::translate("QGTDemoPlanA", "TextLabel", 0));
        label_RightWheel->setText(QApplication::translate("QGTDemoPlanA", "\345\217\263\350\275\256", 0));
        label_LeftWheel->setText(QApplication::translate("QGTDemoPlanA", "\345\267\246\350\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTDemoPlanA: public Ui_QGTDemoPlanA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTDEMOPLANA_H
