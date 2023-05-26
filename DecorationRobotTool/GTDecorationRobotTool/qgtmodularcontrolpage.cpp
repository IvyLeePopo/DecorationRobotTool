#include "qgtmodularcontrolpage.h"

QGTModularControlPage::QGTModularControlPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectModule_Chasis->SetButtonIcon("SelectModule_Chasis", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectModule_LiftPlat->SetButtonIcon("SelectModule_LiftPlat", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectModule_Robot->SetButtonIcon("SelectModule_Robot", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectModule_JoyHandle->SetButtonIcon("SelectModule_JoyHandle", QSize(120, 30), TBT_Round_Rect);

	ui.toolButton_SelectModule_Chasis->SetButtonChecked(true);
	ui.toolButton_SelectModule_LiftPlat->SetButtonChecked(false);
	ui.toolButton_SelectModule_Robot->SetButtonChecked(false);
	ui.toolButton_SelectModule_JoyHandle->SetButtonChecked(false);

	ui.line_Module_Chasis->hide();
	ui.line_Module_LiftPlat->show();
	ui.line_Module_Robot->show();
	ui.line_Module_JoyHandle->show();

	m_pThread_Chasis = new QGTThread(this);
	m_pThread_LiftPlat = new QGTThread(this);
	m_pThread_Robot = new QGTThread(this);
	m_pThread_Ros = new QGTThread(this);
	m_pThread_Lidar = new QGTThread(this);
	m_pThread_LaserMeasure = new QGTThread(this);
	m_pThread_JoyHandle = new QGTThread(this);

	m_pThread_Chasis->SetDefaultThreadType(TMT_Chasis);
	m_pThread_LiftPlat->SetDefaultThreadType(TMT_LiftPlat);
	m_pThread_Robot->SetDefaultThreadType(TMT_Robot);
	m_pThread_Ros->SetDefaultThreadType(TMT_Ros);
	m_pThread_Lidar->SetDefaultThreadType(TMT_Lidar);
	m_pThread_LaserMeasure->SetDefaultThreadType(TMT_LaserMeasure);
	m_pThread_JoyHandle->SetDefaultThreadType(TMT_JoyHandle);

	QObject::connect(m_pThread_Chasis, SIGNAL(Chasis_Info_Output()), ui.Module_Chasis, SLOT(Update_ActualInfo_Chasis()), Qt::UniqueConnection);
	QObject::connect(m_pThread_Chasis, SIGNAL(Chasis_Info_Output()), ui.Module_LiftPlat, SLOT(Update_ActualInfo_LiftPlat_Other()), Qt::UniqueConnection);

	QObject::connect(m_pThread_LiftPlat, SIGNAL(LiftPlat_Info_Output()), ui.Module_LiftPlat, SLOT(Update_ActualInfo_LiftPlat_Normal()), Qt::UniqueConnection);

	QObject::connect(m_pThread_Robot, SIGNAL(Robot_Info_Output()), ui.Module_Robot, SLOT(Update_ActualInfo_Robot()), Qt::UniqueConnection);

	QObject::connect(m_pThread_JoyHandle, SIGNAL(JoyHandle_Info_Output()), ui.Module_JoyHandle, SLOT(Update_ActualInfo_JoyHandle()), Qt::UniqueConnection);
}

QGTModularControlPage::~QGTModularControlPage()
{

}

void QGTModularControlPage::on_toolButton_SelectModule_Chasis_pressed()
{
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectModule_Chasis->SetButtonChecked(true);
	ui.toolButton_SelectModule_LiftPlat->SetButtonChecked(false);
	ui.toolButton_SelectModule_Robot->SetButtonChecked(false);
	ui.toolButton_SelectModule_JoyHandle->SetButtonChecked(false);

	ui.line_Module_Chasis->hide();
	ui.line_Module_LiftPlat->show();
	ui.line_Module_Robot->show();
	ui.line_Module_JoyHandle->show();
}

void QGTModularControlPage::on_toolButton_SelectModule_LiftPlat_pressed()
{
	ui.stackedWidget->setCurrentIndex(1);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectModule_Chasis->SetButtonChecked(false);
	ui.toolButton_SelectModule_LiftPlat->SetButtonChecked(true);
	ui.toolButton_SelectModule_Robot->SetButtonChecked(false);
	ui.toolButton_SelectModule_JoyHandle->SetButtonChecked(false);

	ui.line_Module_Chasis->show();
	ui.line_Module_LiftPlat->hide();
	ui.line_Module_Robot->show();
	ui.line_Module_JoyHandle->show();
}

void QGTModularControlPage::on_toolButton_SelectModule_Robot_pressed()
{
	ui.stackedWidget->setCurrentIndex(2);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectModule_Chasis->SetButtonChecked(false);
	ui.toolButton_SelectModule_LiftPlat->SetButtonChecked(false);
	ui.toolButton_SelectModule_Robot->SetButtonChecked(true);
	ui.toolButton_SelectModule_JoyHandle->SetButtonChecked(false);

	ui.line_Module_Chasis->show();
	ui.line_Module_LiftPlat->show();
	ui.line_Module_Robot->hide();
	ui.line_Module_JoyHandle->show();
}

void QGTModularControlPage::on_toolButton_SelectModule_JoyHandle_pressed()
{
	ui.stackedWidget->setCurrentIndex(3);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectModule_Chasis->SetButtonChecked(false);
	ui.toolButton_SelectModule_LiftPlat->SetButtonChecked(false);
	ui.toolButton_SelectModule_Robot->SetButtonChecked(false);
	ui.toolButton_SelectModule_JoyHandle->SetButtonChecked(true);

	ui.line_Module_Chasis->show();
	ui.line_Module_LiftPlat->show();
	ui.line_Module_Robot->show();
	ui.line_Module_JoyHandle->hide();
}

void QGTModularControlPage::Set_Thread_ModularControl_Enable(bool bIsBeginWork)
{
	if (bIsBeginWork)
	{
		if (g_pGlobalUnit->IsChasisConnect())
		{
			m_pThread_Chasis->m_bIsExit = false;
			m_pThread_Chasis->start();
		}
		if (g_pGlobalUnit->IsLiftPlatConnect())
		{
			m_pThread_LiftPlat->m_bIsExit = false;
			m_pThread_LiftPlat->start();
		}
		if (g_pGlobalUnit->IsRobotConnect())
		{
			m_pThread_Robot->m_bIsExit = false;
			m_pThread_Robot->start();
		}
		if (g_pGlobalUnit->IsRosConnect())
		{
			m_pThread_Ros->m_bIsExit = false;
			m_pThread_Ros->start();
		}
		if (g_pGlobalUnit->IsLidarConnect())
		{
			m_pThread_Lidar->m_bIsExit = false;
			m_pThread_Lidar->start();
		}
		if (g_pGlobalUnit->IsLaserMeasureConnect())
		{
			m_pThread_LaserMeasure->m_bIsExit = false;
			m_pThread_LaserMeasure->start();
		}
		if (g_pGlobalUnit->IsJoyHandleConnect())
		{
			m_pThread_JoyHandle->m_bIsExit = false;
			m_pThread_JoyHandle->start();
		}
	}
	else
	{
		if (g_pGlobalUnit->IsChasisConnect())
		{
			m_pThread_Chasis->m_bIsExit = true;
			m_pThread_Chasis->quit();
		}
		if (g_pGlobalUnit->IsLiftPlatConnect())
		{
			m_pThread_LiftPlat->m_bIsExit = true;
			m_pThread_LiftPlat->quit();
		}
		if (g_pGlobalUnit->IsRobotConnect())
		{
			m_pThread_Robot->m_bIsExit = true;
			m_pThread_Robot->quit();
		}
		if (g_pGlobalUnit->IsRosConnect())
		{
			m_pThread_Ros->m_bIsExit = true;
			m_pThread_Ros->quit();
		}
		if (g_pGlobalUnit->IsLidarConnect())
		{
			m_pThread_Lidar->m_bIsExit = true;
			m_pThread_Lidar->quit();
		}
		if (g_pGlobalUnit->IsLaserMeasureConnect())
		{
			m_pThread_LaserMeasure->m_bIsExit = true;
			m_pThread_LaserMeasure->quit();
		}
		if (g_pGlobalUnit->IsJoyHandleConnect())
		{
			m_pThread_JoyHandle->m_bIsExit = true;
			m_pThread_JoyHandle->quit();
		}
	}
}
