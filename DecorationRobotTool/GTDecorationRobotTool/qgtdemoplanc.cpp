#include "qgtdemoplanc.h"

QGTDemoPlanC::QGTDemoPlanC(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QGTDemoPlanC::~QGTDemoPlanC()
{

}

void QGTDemoPlanC::Update_RobotInfo_DemoPlanC()
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
