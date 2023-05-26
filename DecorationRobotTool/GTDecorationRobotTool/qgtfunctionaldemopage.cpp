#include "qgtfunctionaldemopage.h"

QGTFunctionalDemoPage::QGTFunctionalDemoPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonIcon("SelectDemoPlan_A", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectDemoPlan_B->SetButtonIcon("SelectDemoPlan_B", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectDemoPlan_C->SetButtonIcon("SelectDemoPlan_C", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectDemoPlan_D->SetButtonIcon("SelectDemoPlan_D", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectDemoPlan_E->SetButtonIcon("SelectDemoPlan_E", QSize(120, 30), TBT_Round_Rect);
	ui.toolButton_SelectDemoPlan_F->SetButtonIcon("SelectDemoPlan_F", QSize(120, 30), TBT_Round_Rect);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->hide();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->show();

	m_pThread_LineFollow_Read = new QGTThread(this);
	m_pThread_DemoPlan = new QGTThread(this);

	m_pThread_LineFollow_Read->SetDefaultThreadType(TMT_LineFollow_Read);
	m_pThread_DemoPlan->SetDefaultThreadType(TMT_DemoPlan);

	QObject::connect(m_pThread_LineFollow_Read, SIGNAL(LineFollow_Info_Output()), this, SLOT(on_LineFollow_Info_Output()), Qt::UniqueConnection);

}

QGTFunctionalDemoPage::~QGTFunctionalDemoPage()
{

}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_A_pressed()
{
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->hide();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->show();
}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_B_pressed()
{
	ui.stackedWidget->setCurrentIndex(1);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->show();
	ui.line_SelectDemoPlan_B->hide();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->show();
}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_C_pressed()
{
	ui.stackedWidget->setCurrentIndex(2);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->show();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->hide();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->show();
}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_D_pressed()
{
	ui.stackedWidget->setCurrentIndex(3);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->show();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->hide();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->show();
}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_E_pressed()
{
	ui.stackedWidget->setCurrentIndex(4);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(true);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(false);

	ui.line_SelectDemoPlan_A->show();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->hide();
	ui.line_SelectDemoPlan_F->show();
}

void QGTFunctionalDemoPage::on_toolButton_SelectDemoPlan_F_pressed()
{
	ui.stackedWidget->setCurrentIndex(5);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_SelectDemoPlan_A->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_B->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_C->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_D->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_E->SetButtonChecked(false);
	ui.toolButton_SelectDemoPlan_F->SetButtonChecked(true);

	ui.line_SelectDemoPlan_A->show();
	ui.line_SelectDemoPlan_B->show();
	ui.line_SelectDemoPlan_C->show();
	ui.line_SelectDemoPlan_D->show();
	ui.line_SelectDemoPlan_E->show();
	ui.line_SelectDemoPlan_F->hide();
}

void QGTFunctionalDemoPage::on_Chasis_Info_Output()
{
	ui.DemoPlan_A->Update_ChasisInfo_DemoPlanA();
	ui.DemoPlan_B->Update_ChasisInfo_DemoPlanB();
	ui.DemoPlan_E->Update_ChasisInfo_DemoPlanE();
	ui.DemoPlan_F->Update_Chasis_Info_DemoPlanF();
}

void QGTFunctionalDemoPage::on_Robot_Info_Output()
{
	ui.DemoPlan_B->Update_RobotInfo_DemoPlanB();
	ui.DemoPlan_C->Update_RobotInfo_DemoPlanC();
	ui.DemoPlan_E->Update_RobotInfo_DemoPlanE();
}

void QGTFunctionalDemoPage::on_Lidar_Info_Output()
{
	ui.DemoPlan_F->Update_Lidar_Info_DemoPlanF();
}

void QGTFunctionalDemoPage::on_LaserMeasure_Info_Output()
{
	ui.DemoPlan_F->Update_LaserMeasure_Info_DemoPlanF();
}

void QGTFunctionalDemoPage::on_LineFollow_Info_Output()
{
	ui.DemoPlan_A->Update_LineFollowInfo_DemoPlanA();
	ui.DemoPlan_B->Update_LineFollowInfo_DemoPlanB();
	ui.DemoPlan_E->Update_LineFollowInfo_DemoPlanE();
}

void QGTFunctionalDemoPage::Set_Thread_DemoPlan_Enable(bool bIsBeginWork)
{
	if (bIsBeginWork)
	{
		m_pThread_DemoPlan->m_bIsExit = false;
		m_pThread_DemoPlan->start();
	}
	else
	{
		m_pThread_DemoPlan->m_bIsExit = true;
		m_pThread_DemoPlan->quit();
	}
}

void QGTFunctionalDemoPage::Set_AutoRun_DemoPlan_Enable(bool bIsRunning)
{
	if (bIsRunning)
	{
		if ((g_pGlobalUnit->m_iDemoPlanSet_Index == 0) || (g_pGlobalUnit->m_iDemoPlanSet_Index == 1) ||
			(g_pGlobalUnit->m_iDemoPlanSet_Index == 4))
		{
			m_pThread_LineFollow_Read->m_bIsExit = false;
			m_pThread_LineFollow_Read->start();
		}

		if (g_pGlobalUnit->m_iDemoPlanSet_Index == 0)
		{
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_LineFollow_RotateAdjust;
		}
		else if (g_pGlobalUnit->m_iDemoPlanSet_Index == 1)
		{
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_LineFollow_RotateAdjust;
		}
		else if (g_pGlobalUnit->m_iDemoPlanSet_Index == 2)
		{
			g_pGlobalUnit->Calc_DrawLine_RectPos();
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_DrawLine_Begin;
		}
		else if (g_pGlobalUnit->m_iDemoPlanSet_Index == 3)
		{
			g_pGlobalUnit->Write_Debug_Info("Tiling Start", DIT_Normal);
			g_pGlobalUnit->Calc_Tiling_MaterielAndPaste_Pos();
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_Tiling_PickMateriel_Begin;
		}
		else if (g_pGlobalUnit->m_iDemoPlanSet_Index == 4)
		{
			g_pGlobalUnit->m_iSprayPaint_Current_Count_MovedBy_Chasis = 0;
			g_pGlobalUnit->m_iSprayPaint_Current_Count_MovedBy_LiftPlat = 0;
			g_pGlobalUnit->m_iSprayPaint_Current_Count_MovedBy_Robot = 0;

			g_pGlobalUnit->m_bIs_SprayPaint_Robot_Move = false;

			g_pGlobalUnit->Calc_SprayPaint_Param();

			g_pGlobalUnit->Write_Debug_Info("SprayPaint Start", DIT_Normal);
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_LineFollow_RotateAdjust;
		}
		else if (g_pGlobalUnit->m_iDemoPlanSet_Index == 5)
		{
			g_pGlobalUnit->m_iRos_SprayPaint_Current_Count_MovedBy_Chasis = 0;
			g_pGlobalUnit->m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat = 0;

			g_pGlobalUnit->m_bIs_Ros_Work_Finished = true;
			g_pGlobalUnit->m_bIs_Ros_SprayPaint_RosWork = false;
			g_pGlobalUnit->m_nRos_Work_Pos_Status = RWPS_Idle;

			g_pGlobalUnit->Calc_Ros_SprayPaint_Param();

			g_pGlobalUnit->Write_Debug_Info("Ros SprayPaint Start", DIT_Normal);
			g_pGlobalUnit->m_nAutoRun_NowStatus = ARS_Ros_Chasis_RotateAdjust;
		}
	}
	else
	{
		g_pGlobalUnit->Set_DemPlan_Stop();

		if ((g_pGlobalUnit->m_iDemoPlanSet_Index == 0) || (g_pGlobalUnit->m_iDemoPlanSet_Index == 1) ||
			(g_pGlobalUnit->m_iDemoPlanSet_Index == 4))
		{
			m_pThread_LineFollow_Read->m_bIsExit = true;
			m_pThread_LineFollow_Read->quit();
		}
	}
}
