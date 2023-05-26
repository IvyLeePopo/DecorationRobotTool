/********************************************************************************
** Form generated from reading UI file 'qgtdemoplanb.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGTDEMOPLANB_H
#define UI_QGTDEMOPLANB_H

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

class Ui_QGTDemoPlanB
{
public:
    QLabel *label_RightWheel_Speed;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_RightWheel_Angle;
    QLabel *label_Dis_Offset;
    QLabel *label_4;
    QLabel *label_Angle_Offset;
    QLabel *label_3;
    QLabel *label_LeftWheel_Speed;
    QGTImageView *graphicsView;
    QLabel *label_2;
    QLabel *label_LeftWheel_Angle;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_RightWheel_Dis;
    QLabel *label_LeftWheel_Dis;
    QLabel *label_6;
    QLabel *label_LiftPlat_Height;
    QLabel *label_ChasisFrame;
    QLabel *label_11;
    QLabel *label_DefectPos_X;
    QLabel *label_DefectPos_Y;
    QLabel *label_14;
    QLabel *label_DefectPos_Z;
    QLabel *label_16;
    QGTChasisWheelView *label_LeftWheel;
    QGTChasisWheelView *label_RightWheel;
    QLabel *label_12;
    QLabel *label_RobotPos_X;
    QLabel *label_RobotPos_Y;
    QLabel *label_17;
    QLabel *label_RobotPos_Z;
    QLabel *label_19;
    QLabel *label_RobotPos_U;
    QLabel *label_21;
    QLabel *label_RobotPos_V;
    QLabel *label_23;
    QLabel *label_RobotPos_W;
    QLabel *label_25;

    void setupUi(QWidget *QGTDemoPlanB)
    {
        if (QGTDemoPlanB->objectName().isEmpty())
            QGTDemoPlanB->setObjectName(QStringLiteral("QGTDemoPlanB"));
        QGTDemoPlanB->resize(1024, 590);
        label_RightWheel_Speed = new QLabel(QGTDemoPlanB);
        label_RightWheel_Speed->setObjectName(QStringLiteral("label_RightWheel_Speed"));
        label_RightWheel_Speed->setGeometry(QRect(230, 360, 60, 30));
        label_RightWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_7 = new QLabel(QGTDemoPlanB);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 360, 60, 30));
        label_7->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_5 = new QLabel(QGTDemoPlanB);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 360, 60, 30));
        label_5->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_10 = new QLabel(QGTDemoPlanB);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(300, 400, 60, 30));
        label_10->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RightWheel_Angle = new QLabel(QGTDemoPlanB);
        label_RightWheel_Angle->setObjectName(QStringLiteral("label_RightWheel_Angle"));
        label_RightWheel_Angle->setGeometry(QRect(230, 320, 60, 30));
        label_RightWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Dis_Offset = new QLabel(QGTDemoPlanB);
        label_Dis_Offset->setObjectName(QStringLiteral("label_Dis_Offset"));
        label_Dis_Offset->setGeometry(QRect(370, 360, 60, 30));
        label_Dis_Offset->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_4 = new QLabel(QGTDemoPlanB);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 320, 60, 30));
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_Angle_Offset = new QLabel(QGTDemoPlanB);
        label_Angle_Offset->setObjectName(QStringLiteral("label_Angle_Offset"));
        label_Angle_Offset->setGeometry(QRect(370, 320, 60, 30));
        label_Angle_Offset->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(QGTDemoPlanB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 360, 60, 30));
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Speed = new QLabel(QGTDemoPlanB);
        label_LeftWheel_Speed->setObjectName(QStringLiteral("label_LeftWheel_Speed"));
        label_LeftWheel_Speed->setGeometry(QRect(90, 360, 60, 30));
        label_LeftWheel_Speed->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        graphicsView = new QGTImageView(QGTDemoPlanB);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 416, 312));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        label_2 = new QLabel(QGTDemoPlanB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 320, 60, 30));
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Angle = new QLabel(QGTDemoPlanB);
        label_LeftWheel_Angle->setObjectName(QStringLiteral("label_LeftWheel_Angle"));
        label_LeftWheel_Angle->setGeometry(QRect(90, 320, 60, 30));
        label_LeftWheel_Angle->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_8 = new QLabel(QGTDemoPlanB);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 400, 60, 30));
        label_8->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_9 = new QLabel(QGTDemoPlanB);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 400, 60, 30));
        label_9->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RightWheel_Dis = new QLabel(QGTDemoPlanB);
        label_RightWheel_Dis->setObjectName(QStringLiteral("label_RightWheel_Dis"));
        label_RightWheel_Dis->setGeometry(QRect(230, 400, 60, 30));
        label_RightWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel_Dis = new QLabel(QGTDemoPlanB);
        label_LeftWheel_Dis->setObjectName(QStringLiteral("label_LeftWheel_Dis"));
        label_LeftWheel_Dis->setGeometry(QRect(90, 400, 60, 30));
        label_LeftWheel_Dis->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_6 = new QLabel(QGTDemoPlanB);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 320, 60, 30));
        label_6->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LiftPlat_Height = new QLabel(QGTDemoPlanB);
        label_LiftPlat_Height->setObjectName(QStringLiteral("label_LiftPlat_Height"));
        label_LiftPlat_Height->setGeometry(QRect(370, 400, 60, 30));
        label_LiftPlat_Height->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_ChasisFrame = new QLabel(QGTDemoPlanB);
        label_ChasisFrame->setObjectName(QStringLiteral("label_ChasisFrame"));
        label_ChasisFrame->setGeometry(QRect(450, 10, 240, 420));
        label_ChasisFrame->setStyleSheet(QStringLiteral("background-image: url(:/GTDecorationRobotTool/Resources/ChasisFrame.png);"));
        label_11 = new QLabel(QGTDemoPlanB);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 470, 100, 30));
        QFont font;
        font.setPointSize(12);
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_DefectPos_X = new QLabel(QGTDemoPlanB);
        label_DefectPos_X->setObjectName(QStringLiteral("label_DefectPos_X"));
        label_DefectPos_X->setGeometry(QRect(130, 470, 100, 30));
        label_DefectPos_X->setFont(font);
        label_DefectPos_X->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_DefectPos_Y = new QLabel(QGTDemoPlanB);
        label_DefectPos_Y->setObjectName(QStringLiteral("label_DefectPos_Y"));
        label_DefectPos_Y->setGeometry(QRect(130, 510, 100, 30));
        label_DefectPos_Y->setFont(font);
        label_DefectPos_Y->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_14 = new QLabel(QGTDemoPlanB);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 510, 100, 30));
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_DefectPos_Z = new QLabel(QGTDemoPlanB);
        label_DefectPos_Z->setObjectName(QStringLiteral("label_DefectPos_Z"));
        label_DefectPos_Z->setGeometry(QRect(130, 550, 100, 30));
        label_DefectPos_Z->setFont(font);
        label_DefectPos_Z->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_16 = new QLabel(QGTDemoPlanB);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 550, 100, 30));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_LeftWheel = new QGTChasisWheelView(QGTDemoPlanB);
        label_LeftWheel->setObjectName(QStringLiteral("label_LeftWheel"));
        label_LeftWheel->setGeometry(QRect(510, 60, 120, 120));
        sizePolicy.setHeightForWidth(label_LeftWheel->sizePolicy().hasHeightForWidth());
        label_LeftWheel->setSizePolicy(sizePolicy);
        label_LeftWheel->setStyleSheet(QStringLiteral(""));
        label_LeftWheel->setFrameShape(QFrame::NoFrame);
        label_RightWheel = new QGTChasisWheelView(QGTDemoPlanB);
        label_RightWheel->setObjectName(QStringLiteral("label_RightWheel"));
        label_RightWheel->setGeometry(QRect(510, 260, 120, 120));
        sizePolicy.setHeightForWidth(label_RightWheel->sizePolicy().hasHeightForWidth());
        label_RightWheel->setSizePolicy(sizePolicy);
        label_RightWheel->setFrameShape(QFrame::NoFrame);
        label_12 = new QLabel(QGTDemoPlanB);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(720, 10, 110, 30));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_X = new QLabel(QGTDemoPlanB);
        label_RobotPos_X->setObjectName(QStringLiteral("label_RobotPos_X"));
        label_RobotPos_X->setGeometry(QRect(840, 10, 110, 30));
        label_RobotPos_X->setFont(font);
        label_RobotPos_X->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Y = new QLabel(QGTDemoPlanB);
        label_RobotPos_Y->setObjectName(QStringLiteral("label_RobotPos_Y"));
        label_RobotPos_Y->setGeometry(QRect(840, 50, 110, 30));
        label_RobotPos_Y->setFont(font);
        label_RobotPos_Y->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_17 = new QLabel(QGTDemoPlanB);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(720, 50, 110, 30));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_Z = new QLabel(QGTDemoPlanB);
        label_RobotPos_Z->setObjectName(QStringLiteral("label_RobotPos_Z"));
        label_RobotPos_Z->setGeometry(QRect(840, 90, 110, 30));
        label_RobotPos_Z->setFont(font);
        label_RobotPos_Z->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_19 = new QLabel(QGTDemoPlanB);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(720, 90, 110, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_U = new QLabel(QGTDemoPlanB);
        label_RobotPos_U->setObjectName(QStringLiteral("label_RobotPos_U"));
        label_RobotPos_U->setGeometry(QRect(840, 130, 110, 30));
        label_RobotPos_U->setFont(font);
        label_RobotPos_U->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_21 = new QLabel(QGTDemoPlanB);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(720, 130, 110, 30));
        label_21->setFont(font);
        label_21->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_V = new QLabel(QGTDemoPlanB);
        label_RobotPos_V->setObjectName(QStringLiteral("label_RobotPos_V"));
        label_RobotPos_V->setGeometry(QRect(840, 170, 110, 30));
        label_RobotPos_V->setFont(font);
        label_RobotPos_V->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_23 = new QLabel(QGTDemoPlanB);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(720, 170, 110, 30));
        label_23->setFont(font);
        label_23->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_RobotPos_W = new QLabel(QGTDemoPlanB);
        label_RobotPos_W->setObjectName(QStringLiteral("label_RobotPos_W"));
        label_RobotPos_W->setGeometry(QRect(840, 210, 110, 30));
        label_RobotPos_W->setFont(font);
        label_RobotPos_W->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_25 = new QLabel(QGTDemoPlanB);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(720, 210, 110, 30));
        label_25->setFont(font);
        label_25->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        retranslateUi(QGTDemoPlanB);

        QMetaObject::connectSlotsByName(QGTDemoPlanB);
    } // setupUi

    void retranslateUi(QWidget *QGTDemoPlanB)
    {
        QGTDemoPlanB->setWindowTitle(QApplication::translate("QGTDemoPlanB", "QGTDemoPlanB", 0));
        label_RightWheel_Speed->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\351\200\237\345\272\246", 0));
        label_7->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\351\200\237\345\272\246", 0));
        label_5->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\351\200\237\345\272\246", 0));
        label_10->setText(QApplication::translate("QGTDemoPlanB", "\345\271\263\345\217\260\351\253\230\345\272\246", 0));
        label_RightWheel_Angle->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\350\247\222\345\272\246", 0));
        label_Dis_Offset->setText(QApplication::translate("QGTDemoPlanB", "\345\201\217\347\247\273\350\267\235\347\246\273", 0));
        label_4->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\350\247\222\345\272\246", 0));
        label_Angle_Offset->setText(QApplication::translate("QGTDemoPlanB", "\345\201\217\347\247\273\350\247\222\345\272\246", 0));
        label_3->setText(QApplication::translate("QGTDemoPlanB", "\345\201\217\347\247\273\350\267\235\347\246\273", 0));
        label_LeftWheel_Speed->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\351\200\237\345\272\246", 0));
        label_2->setText(QApplication::translate("QGTDemoPlanB", "\345\201\217\347\247\273\350\247\222\345\272\246", 0));
        label_LeftWheel_Angle->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\350\247\222\345\272\246", 0));
        label_8->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\350\241\214\347\250\213", 0));
        label_9->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\350\241\214\347\250\213", 0));
        label_RightWheel_Dis->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\350\241\214\347\250\213", 0));
        label_LeftWheel_Dis->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256\350\241\214\347\250\213", 0));
        label_6->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256\350\247\222\345\272\246", 0));
        label_LiftPlat_Height->setText(QApplication::translate("QGTDemoPlanB", "\345\271\263\345\217\260\351\253\230\345\272\246", 0));
        label_ChasisFrame->setText(QApplication::translate("QGTDemoPlanB", "TextLabel", 0));
        label_11->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 X", 0));
        label_DefectPos_X->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 X", 0));
        label_DefectPos_Y->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 Y", 0));
        label_14->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 Y", 0));
        label_DefectPos_Z->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 Z", 0));
        label_16->setText(QApplication::translate("QGTDemoPlanB", "\347\274\272\351\231\267\347\202\271\345\235\220\346\240\207 Z", 0));
        label_LeftWheel->setText(QApplication::translate("QGTDemoPlanB", "\345\267\246\350\275\256", 0));
        label_RightWheel->setText(QApplication::translate("QGTDemoPlanB", "\345\217\263\350\275\256", 0));
        label_12->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 X :", 0));
        label_RobotPos_X->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 X", 0));
        label_RobotPos_Y->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Y", 0));
        label_17->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Y :", 0));
        label_RobotPos_Z->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Z", 0));
        label_19->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 Z :", 0));
        label_RobotPos_U->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 U", 0));
        label_21->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 U :", 0));
        label_RobotPos_V->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 V", 0));
        label_23->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 V :", 0));
        label_RobotPos_W->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 W", 0));
        label_25->setText(QApplication::translate("QGTDemoPlanB", "\346\234\272\346\242\260\350\207\202\345\247\277\346\200\201 W :", 0));
    } // retranslateUi

};

namespace Ui {
    class QGTDemoPlanB: public Ui_QGTDemoPlanB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGTDEMOPLANB_H
