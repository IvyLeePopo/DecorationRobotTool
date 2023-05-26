#include "qgtchasismodule.h"

QGTChasisModule::QGTChasisModule(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.toolButton_Chasis_Move_Forward->SetButtonIcon("Btn_Chasis_MoveForward", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Backoff->SetButtonIcon("Btn_Chasis_MoveBackoff", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Left->SetButtonIcon("Btn_Chasis_MoveLeft", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Right->SetButtonIcon("Btn_Chasis_MoveRight", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Stop->SetButtonIcon("Btn_Stop", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Rotate_Right->SetButtonIcon("Btn_Rotate_Right", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Rotate_Left->SetButtonIcon("Btn_Rotate_Left", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Move_Rotate->SetButtonIcon("Btn_Chasis_Rotate", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_LinkRod_Up->SetButtonIcon("Btn_Move_LinkRod_Up", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_LinkRod_Down->SetButtonIcon("Btn_Move_LinkRod_Down", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Chasis_Electromagnet_On->SetButtonIcon("Btn_Electromagnet_On", QSize(100, 100), TBT_Round_Rect);
	ui.toolButton_Chasis_Electromagnet_Off->SetButtonIcon("Btn_Electromagnet_Off", QSize(100, 100), TBT_Round_Rect);
	

	ui.spinBox_Chasis_TargetSpeed_LeftWheel->setValue(g_pGlobalUnit->m_iChasis_Left_TargetSpeed);
	ui.spinBox_Chasis_TargetSpeed_RightWheel->setValue(g_pGlobalUnit->m_iChasis_Right_TargetSpeed);
	ui.spinBox_Chasis_TargetAngle_LeftWheel->setValue(g_pGlobalUnit->m_iChasis_Left_TargetAngle);
	ui.spinBox_Chasis_TargetAngle_RightWheel->setValue(g_pGlobalUnit->m_iChasis_Right_TargetAngle);

	pix_ChasisFrame = QPixmap(":/GTDecorationRobotTool/Resources/ChasisFrame.png");
	pix_LeftWheel = QPixmap(":/GTDecorationRobotTool/Resources/ChasisWheel.png");
	pix_RightWheel = QPixmap(":/GTDecorationRobotTool/Resources/ChasisWheel.png");

	ui.label_ChasisFrame->setPixmap(pix_ChasisFrame);
	ui.label_Chasis_LeftWheel->UpdateChasisWheel(pix_LeftWheel, 0);
	ui.label_Chasis_RightWheel->UpdateChasisWheel(pix_RightWheel, 0);


}

QGTChasisModule::~QGTChasisModule()
{

}

void QGTChasisModule::on_toolButton_Chasis_Move_Forward_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_NORMAL_Forward;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Backoff_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_NORMAL_Backoff;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Left_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_NORMAL_Left;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Right_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_NORMAL_Right;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Rotate_Right_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_ROTATE_Right;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Rotate_Left_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_ROTATE_Left;
}

void QGTChasisModule::on_toolButton_Chasis_Move_Rotate_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_ROTATE;
}

void QGTChasisModule::on_toolButton_Chasis_LinkRod_Up_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_LinkRod_Up;
}

void QGTChasisModule::on_toolButton_Chasis_LinkRod_Down_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_LinkRod_Down;
}

void QGTChasisModule::on_toolButton_Chasis_Electromagnet_On_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_Electromagnet_On;
}

void QGTChasisModule::on_toolButton_Chasis_Electromagnet_Off_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_Electromagnet_Off;
}

void QGTChasisModule::on_toolButton_Chasis_Stop_pressed()
{
	if (false == g_pGlobalUnit->IsChasisConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Chasis disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->m_nChasis_NowType = CMT_Stop;
}

void QGTChasisModule::on_spinBox_Chasis_TargetSpeed_LeftWheel_valueChanged(int iValue)
{
	g_pGlobalUnit->m_iChasis_Left_TargetSpeed = iValue;
}

void QGTChasisModule::on_spinBox_Chasis_TargetSpeed_RightWheel_valueChanged(int iValue)
{
	g_pGlobalUnit->m_iChasis_Right_TargetSpeed = iValue;
}

void QGTChasisModule::on_spinBox_Chasis_TargetAngle_LeftWheel_valueChanged(int iValue)
{
	g_pGlobalUnit->m_iChasis_Left_TargetAngle = iValue;
}

void QGTChasisModule::on_spinBox_Chasis_TargetAngle_RightWheel_valueChanged(int iValue)
{
	g_pGlobalUnit->m_iChasis_Right_TargetAngle = iValue;
}

void QGTChasisModule::Update_ActualInfo_Chasis()
{
	QString strSpeed_Left = QString::number(g_pGlobalUnit->m_nChasisInfo.iSpeed_LeftWheel);
	QString strSpeed_Right = QString::number(g_pGlobalUnit->m_nChasisInfo.iSpeed_RightWheel);
	double dwAngle_Left = (double)g_pGlobalUnit->m_nChasisInfo.iAngle_LeftWheel / (double)10;
	double dwAngle_Right = (double)g_pGlobalUnit->m_nChasisInfo.iAngle_RightWheel / (double)10;
	QString strAngle_Left = QString::number(dwAngle_Left, 'f', 1);
	QString strAngle_Right = QString::number(dwAngle_Right, 'f', 1);
	QString strDis_Left = QString::number(g_pGlobalUnit->m_nChasisInfo.iDis_LeftWheel);
	QString strDis_Right = QString::number(g_pGlobalUnit->m_nChasisInfo.iDis_RightWheel);

	ui.label_Chasis_LeftWheel_Speed->setText(strSpeed_Left);
	ui.label_Chasis_RightWheel_Speed->setText(strSpeed_Right);
	ui.label_Chasis_LeftWheel_Angle->setText(strAngle_Left);
	ui.label_Chasis_RightWheel_Angle->setText(strAngle_Right);
	ui.label_Chasis_LeftWheel_Dis->setText(strDis_Left);
	ui.label_Chasis_RightWheel_Dis->setText(strDis_Right);

	ui.label_Chasis_LeftWheel->UpdateChasisWheel(pix_LeftWheel, dwAngle_Left);
	ui.label_Chasis_RightWheel->UpdateChasisWheel(pix_RightWheel, dwAngle_Right);
}

