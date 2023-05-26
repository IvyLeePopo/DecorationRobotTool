#include "qgtliftplatmodule.h"

QGTLiftPlatModule::QGTLiftPlatModule(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.toolButton_LiftPlat_MoveUp->SetButtonIcon("Btn_Chasis_MoveForward", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_LiftPlat_MoveDown->SetButtonIcon("Btn_Chasis_MoveBackoff", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_LiftPlat_Stop->SetButtonIcon("Btn_Stop", QSize(150, 150), TBT_Normal_Rect);

	ui.spinBox_Motor_TargetSpeed->setValue(g_pGlobalUnit->m_iLiftPlat_TargetSpeed);
}

QGTLiftPlatModule::~QGTLiftPlatModule()
{

}

void QGTLiftPlatModule::on_toolButton_LiftPlat_MoveUp_pressed()
{
	if (false == g_pGlobalUnit->IsLiftPlatConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"LiftPlat disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}

	g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Up;
}

void QGTLiftPlatModule::on_toolButton_LiftPlat_MoveDown_pressed()
{
	if (false == g_pGlobalUnit->IsLiftPlatConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"LiftPlat disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}

	g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Down;
}

void QGTLiftPlatModule::on_toolButton_LiftPlat_Stop_pressed()
{
	if (false == g_pGlobalUnit->IsLiftPlatConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"LiftPlat disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	
	g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Stop;
}

void QGTLiftPlatModule::on_spinBox_Motor_TargetSpeed_valueChanged(int iValue)
{
	g_pGlobalUnit->m_iLiftPlat_TargetSpeed = iValue;
}

void QGTLiftPlatModule::Update_ActualInfo_LiftPlat_Normal()
{
	QString strModbus_enable = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iModbus_enable, 10);
	QString strEN_enable = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iEN_enable % 2, 10);
	QString strPU = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iPU, 10);
	QString strPU_all = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iPU_all, 10);
	QString strTarget_speed = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iTarget_speed, 10);
	QString strAcceleration = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iAcceleration, 10);
	QString strSpeed_start = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSpeed_start, 10);
	QString strSystem_DC_current = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSystem_DC_current / (double)2000, 'f', 1);
	QString strSystem_voltage = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSystem_voltage / (double)327, 'f', 1);
	QString strSystem_temperature = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSystem_temperature, 10);
	QString strSystem_pwm = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSystem_pwm / (double)327, 'f', 1);
	QString strSpeed_actual = QString::number(g_pGlobalUnit->m_nLiftPlat_MotorInfo.iSpeed_actual / (double)10, 'f', 1);

	if (g_pGlobalUnit->m_nLiftPlat_MotorInfo.iModbus_enable == 0)
	{
		ui.label_Modbus_Status_explain->setText(QString::fromLocal8Bit("禁止"));
	}
	else
	{
		ui.label_Modbus_Status_explain->setText(QString::fromLocal8Bit("使能"));
	}

	if (g_pGlobalUnit->m_nLiftPlat_MotorInfo.iEN_enable == 0)
	{
		ui.label_En_Status_explain->setText(QString::fromLocal8Bit("禁止"));
	}
	else
	{
		ui.label_En_Status_explain->setText(QString::fromLocal8Bit("使能"));
	}
	ui.label_Modbus_Status->setText(strModbus_enable);
	ui.label_En_Status->setText(strEN_enable);
	ui.label_Pu_Step->setText(strPU);
	ui.label_Pu_AllStep->setText(strPU_all);
	ui.label_Target_Speed->setText(strTarget_speed);
	ui.label_Acceleration->setText(strAcceleration);
	ui.label_Speed_start->setText(strSpeed_start);
	ui.label_Motor_current->setText(strSystem_DC_current);
	ui.label_Motor_voltage->setText(strSystem_voltage);
	ui.label_Motor_voltage->setText(strSystem_temperature);
	ui.label_Motor_PWM->setText(strSystem_pwm);
	ui.label_Motor_Speed_actual->setText(strSpeed_actual);
}

void QGTLiftPlatModule::Update_ActualInfo_LiftPlat_Other()
{
	QString strHeight_actual = QString::number(g_pGlobalUnit->m_nChasisInfo.iHeight_LiftPlat);
	ui.label_Plat_Height->setText(strHeight_actual);
}
