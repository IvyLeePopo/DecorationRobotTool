#include "qgtdemoplanf.h"

QGTDemoPlanF::QGTDemoPlanF(QWidget *parent)
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

QGTDemoPlanF::~QGTDemoPlanF()
{

}

void QGTDemoPlanF::Update_Chasis_Info_DemoPlanF()
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

void QGTDemoPlanF::Update_Lidar_Info_DemoPlanF()
{
	ui.ImageWindow_Lidar->Display_LidarData(g_pGlobalUnit->m_nLidar_Points_Array, g_pGlobalUnit->m_ptLidar_Turning, g_pGlobalUnit->m_nLidar_Line);
	QString strRos_Hor_Dis = QString::number(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Dis_fromLeftwall);
	QString strRos_Angle_From_workWall = QString::number(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Angle_fromWorkwall);
	QString strRos_Dis_From_workWall = QString::number(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Dis_fromWorkwall);
	ui.label_Ros_Hor_Dis->setText(strRos_Hor_Dis);
	ui.label_Ros_Angle_From_workWall->setText(strRos_Angle_From_workWall);
	ui.label_Ros_Dis_From_workWall->setText(strRos_Dis_From_workWall);
}

void QGTDemoPlanF::Update_LaserMeasure_Info_DemoPlanF()
{
	QString strRos_Ver_Dis = QString::number(g_pGlobalUnit->m_dLaserMeasure_Distance);
	ui.label_Ros_Ver_Dis->setText(strRos_Ver_Dis);
}
