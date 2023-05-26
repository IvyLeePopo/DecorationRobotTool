#include "qgtdemoplane.h"

QGTDemoPlanE::QGTDemoPlanE(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	pix_ChasisFrame = QPixmap(":/GTDecorationRobotTool/Resources/ChasisFrame.png");
	pix_LeftWheel = QPixmap(":/GTDecorationRobotTool/Resources/ChasisWheel.png");
	pix_RightWheel = QPixmap(":/GTDecorationRobotTool/Resources/ChasisWheel.png");

	ui.label_ChasisFrame->setPixmap(pix_ChasisFrame);
	ui.label_LeftWheel->UpdateChasisWheel(pix_LeftWheel, 0);
	ui.label_RightWheel->UpdateChasisWheel(pix_RightWheel, 0);
}

QGTDemoPlanE::~QGTDemoPlanE()
{

}

void QGTDemoPlanE::Update_ChasisInfo_DemoPlanE()
{
	//获取到的底盘和升降平台的实时信息
	double dwLeftWheel_Angle = (double)g_pGlobalUnit->m_nChasisInfo.iAngle_LeftWheel / (double)10;
	double dwRightWheel_Angle = (double)g_pGlobalUnit->m_nChasisInfo.iAngle_RightWheel / (double)10;
	QString strLeftWheel_Angle = QString::number(dwLeftWheel_Angle, 'f', 1);
	QString strLeftWheel_Speed = QString::number(g_pGlobalUnit->m_nChasisInfo.iSpeed_LeftWheel);
	QString strLeftWheel_Dis = QString::number(g_pGlobalUnit->m_nChasisInfo.iDis_LeftWheel);
	QString strRightWheel_Angle = QString::number(dwRightWheel_Angle, 'f', 1);
	QString strRightWheel_Speed = QString::number(g_pGlobalUnit->m_nChasisInfo.iSpeed_RightWheel);
	QString strRightWheel_Dis = QString::number(g_pGlobalUnit->m_nChasisInfo.iDis_RightWheel);
	QString strLiftPlat_Height = QString::number(g_pGlobalUnit->m_nChasisInfo.iHeight_LiftPlat);

	ui.label_LeftWheel_Angle->setText(strLeftWheel_Angle);
	ui.label_LeftWheel_Speed->setText(strLeftWheel_Speed);
	ui.label_LeftWheel_Dis->setText(strLeftWheel_Dis);
	ui.label_RightWheel_Angle->setText(strRightWheel_Angle);
	ui.label_RightWheel_Speed->setText(strRightWheel_Speed);
	ui.label_RightWheel_Dis->setText(strRightWheel_Dis);
	ui.label_LiftPlat_Height->setText(strLiftPlat_Height);
	ui.label_LeftWheel->UpdateChasisWheel(pix_LeftWheel, dwLeftWheel_Angle);
	ui.label_RightWheel->UpdateChasisWheel(pix_RightWheel, dwRightWheel_Angle);
}

void QGTDemoPlanE::Update_RobotInfo_DemoPlanE()
{
	QString strSpacePos_X = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX, 'f', 3);
	QString strSpacePos_Y = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY, 'f', 3);
	QString strSpacePos_Z = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ, 'f', 3);
	QString strSpacePos_U = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU, 'f', 3);
	QString strSpacePos_V = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV, 'f', 3);
	QString strSpacePos_W = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW, 'f', 3);

	ui.label_RobotPos_X->setText(strSpacePos_X);
	ui.label_RobotPos_Y->setText(strSpacePos_Y);
	ui.label_RobotPos_Z->setText(strSpacePos_Z);
	ui.label_RobotPos_U->setText(strSpacePos_U);
	ui.label_RobotPos_V->setText(strSpacePos_V);
	ui.label_RobotPos_W->setText(strSpacePos_W);
}

void QGTDemoPlanE::Update_LineFollowInfo_DemoPlanE()
{
	//相机反馈的实时信息
	ui.graphicsView->DisplayImage(g_pGlobalUnit->m_nLineFollowSet_ResultImage);
	QString strAngle = QString::number(g_pGlobalUnit->m_dLineFollowSet_ResultAngel, 'f', 2);
	QString strDis = QString::number(g_pGlobalUnit->m_dLineFollowSet_ResultDis, 'f', 2);
	ui.label_Angle_Offset->setText(strAngle);
	ui.label_Dis_Offset->setText(strDis);
}
