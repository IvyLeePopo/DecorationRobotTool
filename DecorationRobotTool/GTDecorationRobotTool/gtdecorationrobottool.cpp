#include "gtdecorationrobottool.h"

GTDecorationRobotTool::GTDecorationRobotTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏  
	this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明,此时控件不透明

	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);

	ui.toolButton_Login->SetButtonIcon("Btn_Login", QSize(40, 40), TBT_Normal_Rect);
	ui.toolButton_MiniSize->SetButtonIcon("Btn_MiniSize", QSize(40, 40), TBT_Normal_Rect);
	ui.toolButton_Exit->SetButtonIcon("Btn_Exit", QSize(40, 40), TBT_Normal_Rect);

	ui.toolButton_BaseSet->SetButtonIcon("Btn_BaseSet", QSize(40, 40), TBT_Menu);
	InitBaseSetMenu();

	ui.toolButton_Select_FunctionalDemo->SetButtonIcon("Btn_Select_FunctionalDemo", QSize(60, 60), TBT_Circle);
	ui.toolButton_Select_ModularControl->SetButtonIcon("Btn_Select_ModularControl", QSize(60, 60), TBT_Circle);

	ui.toolButton_Auto_Run->SetButtonIcon("Btn_Run", QSize(60, 60), TBT_Normal_Rect);


	QObject::connect(ui.page_ModularControl->m_pThread_Chasis, SIGNAL(Chasis_Info_Output()), ui.page_FunctionalDemo, SLOT(on_Chasis_Info_Output()), Qt::UniqueConnection);
	QObject::connect(ui.page_ModularControl->m_pThread_Robot, SIGNAL(Robot_Info_Output()), ui.page_FunctionalDemo, SLOT(on_Robot_Info_Output()), Qt::UniqueConnection);
	QObject::connect(ui.page_ModularControl->m_pThread_Lidar, SIGNAL(Lidar_Info_Output()), ui.page_FunctionalDemo, SLOT(on_Lidar_Info_Output()), Qt::UniqueConnection);
	QObject::connect(ui.page_ModularControl->m_pThread_LaserMeasure, SIGNAL(LaserMeasure_Info_Output()), ui.page_FunctionalDemo, SLOT(on_LaserMeasure_Info_Output()), Qt::UniqueConnection);


	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_Auto_Run_pressed()), Qt::UniqueConnection);

}

GTDecorationRobotTool::~GTDecorationRobotTool()
{
	if (NULL != g_pGlobalUnit)
	{
		delete g_pGlobalUnit;
		g_pGlobalUnit = NULL;
	}
}

void GTDecorationRobotTool::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void GTDecorationRobotTool::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void GTDecorationRobotTool::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

void GTDecorationRobotTool::paintEvent(QPaintEvent *pEvent)
{
	QPainter p(this);
	//窗口整体不透明，局部透明
	//绘制区域全透明。如果绘制区域有控件不会影响控件的透明
	p.setCompositionMode(QPainter::CompositionMode_Clear);
	p.fillRect(0, 0, 1024, 768, Qt::SolidPattern);
}

void GTDecorationRobotTool::InitBaseSetMenu()
{
	QMenu *pBaseSet_Menu = ui.toolButton_BaseSet->GetCurrentMenu();

	action_Connect = new QAction("Connect", this);
	action_ShowLog = new QAction("Show Log", this);
	action_CommunicationSet = new QAction("Communication Set", this);
	action_DemoPlanSet = new QAction("DemoPlan Set", this);
	action_LineFollowSet = new QAction("LineFollow Set", this);
	action_DrawLineSet = new QAction("DrawLine Set", this);
	action_TilingSet = new QAction("Tiling Set", this);
	action_SprayPaintSet = new QAction("SprayPaint Set", this);
	action_RosSprayPaintSet = new QAction("Ros SprayPaint Set", this);

	pBaseSet_Menu->addAction(action_Connect);
	pBaseSet_Menu->addAction(action_ShowLog);
	pBaseSet_Menu->addAction(action_CommunicationSet);
	pBaseSet_Menu->addAction(action_DemoPlanSet);
	pBaseSet_Menu->addAction(action_LineFollowSet);
	pBaseSet_Menu->addAction(action_DrawLineSet);
	pBaseSet_Menu->addAction(action_TilingSet);
	pBaseSet_Menu->addAction(action_SprayPaintSet);
	pBaseSet_Menu->addAction(action_RosSprayPaintSet);

	connect(action_Connect, SIGNAL(triggered()), this, SLOT(on_Action_Connect_pressed()), Qt::UniqueConnection);
	connect(action_ShowLog, SIGNAL(triggered()), this, SLOT(on_Action_ShowLog_pressed()), Qt::UniqueConnection);
	connect(action_CommunicationSet, SIGNAL(triggered()), this, SLOT(on_Action_CommunicationSet_pressed()), Qt::UniqueConnection);
	connect(action_DemoPlanSet, SIGNAL(triggered()), this, SLOT(on_Action_DemoPlanSet_pressed()), Qt::UniqueConnection);
	connect(action_LineFollowSet, SIGNAL(triggered()), this, SLOT(on_Action_LineFollowSet_pressed()), Qt::UniqueConnection);
	connect(action_DrawLineSet, SIGNAL(triggered()), this, SLOT(on_Action_DrawLineSet_pressed()), Qt::UniqueConnection);
	connect(action_TilingSet, SIGNAL(triggered()), this, SLOT(on_Action_TilingSet_pressed()), Qt::UniqueConnection);
	connect(action_SprayPaintSet, SIGNAL(triggered()), this, SLOT(on_Action_SprayPaintSet_pressed()), Qt::UniqueConnection);
	connect(action_RosSprayPaintSet, SIGNAL(triggered()), this, SLOT(on_Action_RosSprayPaintSet_pressed()), Qt::UniqueConnection);
}

void GTDecorationRobotTool::UpdateActionState(GT_MenuButon_Action_Type iType, bool bIsNormaStatel)
{
	if (true == bIsNormaStatel) //正常状态下，即没有连接网络或者没有显示Log
	{
		if (iType == MBAT_Connect)
		{
			action_Connect->setText("Connect");
		}
		else if (iType == MBAT_Showlog)
		{
			action_ShowLog->setText("Show Log");
		}
	}
	else
	{
		if (iType == MBAT_Connect)
		{
			action_Connect->setText("DisConnect");
		}
		else if (iType == MBAT_Showlog)
		{
			action_ShowLog->setText("Hide Log");
		}
	}
}

void GTDecorationRobotTool::on_toolButton_Login_pressed()
{
	QGTLoginPage *pLogin_Ui = new QGTLoginPage(this);
	pLogin_Ui->show();
	connect(pLogin_Ui, SIGNAL(Update_Login_State()), this, SLOT(on_Update_Login_State()), Qt::UniqueConnection);
}

void GTDecorationRobotTool::on_Update_Login_State()
{
	if (g_pGlobalUnit->m_nLoginState == LS_Developer)
	{
		ui.toolButton_Login->setText("Developer");
	}
	else if (g_pGlobalUnit->m_nLoginState == LS_Customer)
	{
		ui.toolButton_Login->setText("Customer");
	}
	else if (g_pGlobalUnit->m_nLoginState == LS_Nobody)
	{
		QString strTemp = QString::fromLocal8Bit("装修机器人");
		ui.toolButton_Login->setText(strTemp);
	}
}

void GTDecorationRobotTool::on_toolButton_MiniSize_pressed()
{
	this->showMinimized();
}

void GTDecorationRobotTool::on_toolButton_Exit_pressed()
{
	QApplication* app;
	app->quit();
}

void GTDecorationRobotTool::on_toolButton_Select_FunctionalDemo_pressed()
{
	ui.stackedWidget->setCurrentIndex(0);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.toolButton_Select_FunctionalDemo->SetButtonChecked(true);
	ui.toolButton_Select_ModularControl->SetButtonChecked(false);
}

void GTDecorationRobotTool::on_toolButton_Select_ModularControl_pressed()
{
	ui.stackedWidget->setCurrentIndex(1);
	ui.stackedWidget->currentWidget()->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.toolButton_Select_FunctionalDemo->SetButtonChecked(false);
	ui.toolButton_Select_ModularControl->SetButtonChecked(true);
}

void GTDecorationRobotTool::on_Action_Connect_pressed()
{
	if (!g_pGlobalUnit->m_bIsConnect)
	{
		if (false == g_pGlobalUnit->SetConnect())
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, tr("Warning"),
				"Connect timeout, Please try again",
				QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

			g_pGlobalUnit->Write_Debug_Info("Connect Fail", DIT_Error);
			return;
		}

		ui.page_FunctionalDemo->Set_Thread_DemoPlan_Enable(true);
		ui.page_ModularControl->Set_Thread_ModularControl_Enable(true);
	}
	else
	{
		ui.page_FunctionalDemo->Set_Thread_DemoPlan_Enable(false);
		ui.page_ModularControl->Set_Thread_ModularControl_Enable(false);

		if (false == g_pGlobalUnit->SetDisConnect())
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, tr("Warning"),
				"DisConnect timeout, Please try again",
				QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

			g_pGlobalUnit->Write_Debug_Info("DisConnect Fail", DIT_Error);
			return;
		}
	}
	UpdateActionState(MBAT_Connect, !g_pGlobalUnit->m_bIsConnect);
}

void GTDecorationRobotTool::on_Action_ShowLog_pressed()
{
	if (false == g_pGlobalUnit->m_bIsShowLog)
	{
		g_pGlobalUnit->m_bIsShowLog = true;
	}
	else
	{
		g_pGlobalUnit->m_bIsShowLog = false;
	}
	UpdateActionState(MBAT_Showlog, !g_pGlobalUnit->m_bIsShowLog);
}

void GTDecorationRobotTool::on_Action_CommunicationSet_pressed()
{
	QGTCommunicationSet *pSetUi = new QGTCommunicationSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_DemoPlanSet_pressed()
{
	QGTDemoPlanSet *pSetUi = new QGTDemoPlanSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_LineFollowSet_pressed()
{
	QGTLineFollowSet *pSetUi = new QGTLineFollowSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_DrawLineSet_pressed()
{
	QGTDrawLineSet *pSetUi = new QGTDrawLineSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_TilingSet_pressed()
{
	QGTTilingSet *pSetUi = new QGTTilingSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_SprayPaintSet_pressed()
{
	QGTSprayPaintSet *pSetUi = new QGTSprayPaintSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_Action_RosSprayPaintSet_pressed()
{
	QGTRosSprayPaintSet *pSetUi = new QGTRosSprayPaintSet(this);
	pSetUi->show();
}

void GTDecorationRobotTool::on_toolButton_Auto_Run_pressed()
{
	if (!g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"GTDecorationRobotTool is disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}

	g_pGlobalUnit->m_bIsAutoRun = false == ui.toolButton_Auto_Run->IsButtonChecked() ? true : false;
	
	ui.page_FunctionalDemo->Set_AutoRun_DemoPlan_Enable(g_pGlobalUnit->m_bIsAutoRun);
	ui.toolButton_Auto_Run->SetButtonChecked(g_pGlobalUnit->m_bIsAutoRun);
}
