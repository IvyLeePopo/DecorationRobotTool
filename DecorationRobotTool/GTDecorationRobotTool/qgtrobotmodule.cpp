#include "qgtrobotmodule.h"

QGTRobotModule::QGTRobotModule(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.toolButton_Robot_PosX_Up->SetButtonIcon("Btn_PosX_Up", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_PosX_Down->SetButtonIcon("Btn_PosX_Down", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_PosY_Up->SetButtonIcon("Btn_PosY_Up", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_PosY_Down->SetButtonIcon("Btn_PosY_Down", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_PosZ_Up->SetButtonIcon("Btn_PosZ_Up", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_PosZ_Down->SetButtonIcon("Btn_PosZ_Down", QSize(100, 100), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_X->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_X->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_Y->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_Y->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_Z->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_Z->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_U->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_U->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_V->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_V->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);

	ui.toolButton_Robot_RotateLeft_Axle_W->SetButtonIcon("Btn_Rotate_Left", QSize(50, 50), TBT_Normal_Rect);
	ui.toolButton_Robot_RotateRight_Axle_W->SetButtonIcon("Btn_Rotate_Right", QSize(50, 50), TBT_Normal_Rect);


	ui.toolButton_Robot_MoveTo_TargetPos->SetButtonIcon("Btn_Robot_MoveTo_Target_SpacePos", QSize(100, 100), TBT_Normal_Rect);
	ui.toolButton_Robot_MoveTo_TargetAngle->SetButtonIcon("Btn_Robot_MoveTo_Target_JointAngle", QSize(100, 100), TBT_Normal_Rect);

	ui.toolButton_Structure_Calibrat->SetButtonIcon("Btn_Structure_Calibrat", QSize(150, 60), TBT_Round_Rect);
	ui.toolButton_Structure_Test->SetButtonIcon("Btn_Structure_Test", QSize(150, 60), TBT_Round_Rect);


	ui.doubleSpinBox_Robot_SpeedRate->setValue(g_pGlobalUnit->m_dRobot_SpeedRate);
	ui.doubleSpinBox_Robot_AccelerationRate->setValue(g_pGlobalUnit->m_dRobot_AccelerationRate);

}

QGTRobotModule::~QGTRobotModule()
{

}

void QGTRobotModule::on_toolButton_Robot_PosX_Up_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_X, 1);
}

void QGTRobotModule::on_toolButton_Robot_PosX_Up_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_PosX_Down_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_X, -1);
}

void QGTRobotModule::on_toolButton_Robot_PosX_Down_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_PosY_Up_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_Y, 1);
}

void QGTRobotModule::on_toolButton_Robot_PosY_Up_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_PosY_Down_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_Y, -1);
}

void QGTRobotModule::on_toolButton_Robot_PosY_Down_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_PosZ_Up_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_Z, 1);
}

void QGTRobotModule::on_toolButton_Robot_PosZ_Up_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_PosZ_Down_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Space_Z, -1);
}

void QGTRobotModule::on_toolButton_Robot_PosZ_Down_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_X_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_X, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_X_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_X_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_X, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_X_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_Y_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_Y, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_Y_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_Y_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_Y, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_Y_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_Z_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_Z, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_Z_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_Z_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_Z, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_Z_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_U_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_U, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_U_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_U_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_U, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_U_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_V_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_V, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_V_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_V_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_V, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_V_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_W_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_W, -1);
}

void QGTRobotModule::on_toolButton_Robot_RotateLeft_Axle_W_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_W_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	g_pGlobalUnit->Set_Robot_Move_Normal(UR_Joint_W, 1);
}

void QGTRobotModule::on_toolButton_Robot_RotateRight_Axle_W_released()
{
	g_pGlobalUnit->Set_Robot_Stop();
}

void QGTRobotModule::on_toolButton_Robot_MoveTo_TargetPos_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	GT_RobotArm_Pose rInfo_Pos;
	rInfo_Pos.dwX = ui.doubleSpinBox_Robot_TargetPos_X->value();
	rInfo_Pos.dwY = ui.doubleSpinBox_Robot_TargetPos_Y->value();
	rInfo_Pos.dwZ = ui.doubleSpinBox_Robot_TargetPos_Z->value();
	rInfo_Pos.dwU = ui.doubleSpinBox_Robot_TargetPos_U->value();
	rInfo_Pos.dwV = ui.doubleSpinBox_Robot_TargetPos_V->value();
	rInfo_Pos.dwW = ui.doubleSpinBox_Robot_TargetPos_W->value();
	g_pGlobalUnit->Set_Robot_MoveTo_Target_SpacePos(rInfo_Pos);
}

void QGTRobotModule::on_toolButton_Robot_MoveTo_TargetAngle_pressed()
{
	if (false == g_pGlobalUnit->IsRobotConnect())
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"RobotArm disconnect now, please connect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}
	GT_RobotArm_Pose rInfo_Angle;
	rInfo_Angle.dwX = ui.doubleSpinBox_Robot_TargetAngle_X->value();
	rInfo_Angle.dwY = ui.doubleSpinBox_Robot_TargetAngle_Y->value();
	rInfo_Angle.dwZ = ui.doubleSpinBox_Robot_TargetAngle_Z->value();
	rInfo_Angle.dwU = ui.doubleSpinBox_Robot_TargetAngle_U->value();
	rInfo_Angle.dwV = ui.doubleSpinBox_Robot_TargetAngle_V->value();
	rInfo_Angle.dwW = ui.doubleSpinBox_Robot_TargetAngle_W->value();
	g_pGlobalUnit->Set_Robot_MoveTo_Target_JointAngle(rInfo_Angle);
}

void QGTRobotModule::on_doubleSpinBox_Robot_SpeedRate_valueChanged(double dValue)
{
	g_pGlobalUnit->m_dRobot_SpeedRate = dValue;
}

void QGTRobotModule::on_doubleSpinBox_Robot_AccelerationRate_valueChanged(double dValue)
{
	g_pGlobalUnit->m_dRobot_AccelerationRate = dValue;
}

void QGTRobotModule::Update_ActualInfo_Robot()
{
	QString strSpacePos_X = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX, 'f', 3);
	QString strSpacePos_Y = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY, 'f', 3);
	QString strSpacePos_Z = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ, 'f', 3);
	QString strSpacePos_U = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU, 'f', 3);
	QString strSpacePos_V = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV, 'f', 3);
	QString strSpacePos_W = QString::number(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW, 'f', 3);

	QString strJointAngle_X = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwX, 'f', 3);
	QString strJointAngle_Y = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwY, 'f', 3);
	QString strJointAngle_Z = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwZ, 'f', 3);
	QString strJointAngle_U = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwU, 'f', 3);
	QString strJointAngle_V = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwV, 'f', 3);
	QString strJointAngle_W = QString::number(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwW, 'f', 3);

	ui.label_Robot_Pos_X->setText(strSpacePos_X);
	ui.label_Robot_Pos_Y->setText(strSpacePos_Y);
	ui.label_Robot_Pos_Z->setText(strSpacePos_Z);
	ui.label_Robot_Pos_U->setText(strSpacePos_U);
	ui.label_Robot_Pos_V->setText(strSpacePos_V);
	ui.label_Robot_Pos_W->setText(strSpacePos_W);

	ui.label_Robot_JointAngle_X->setText(strJointAngle_X);
	ui.label_Robot_JointAngle_Y->setText(strJointAngle_Y);
	ui.label_Robot_JointAngle_Z->setText(strJointAngle_Z);
	ui.label_Robot_JointAngle_U->setText(strJointAngle_U);
	ui.label_Robot_JointAngle_V->setText(strJointAngle_V);
	ui.label_Robot_JointAngle_W->setText(strJointAngle_W);

	QString strTcpForce_1 = QString::number(g_pGlobalUnit->m_nRobot_Actual_TcpForce.iForce_1);
	QString strTcpForce_2 = QString::number(g_pGlobalUnit->m_nRobot_Actual_TcpForce.iForce_2);
	QString strTcpForce_3 = QString::number(g_pGlobalUnit->m_nRobot_Actual_TcpForce.iForce_3);
	QString strTcpForce_4 = QString::number(g_pGlobalUnit->m_nRobot_Actual_TcpForce.iForce_4);
	ui.label_Robot_Tcp_Force_1->setText(strTcpForce_1);
	ui.label_Robot_Tcp_Force_2->setText(strTcpForce_2);
	ui.label_Robot_Tcp_Force_3->setText(strTcpForce_3);
	ui.label_Robot_Tcp_Force_4->setText(strTcpForce_4);

	QString strState_1 = "CH 0 : " + strTcpForce_1;
	QString strState_2 = "CH 1 : " + strTcpForce_2;
	QString strState_3 = "CH 2 : " + strTcpForce_3;
	QString strState_4 = "CH 3 : " + strTcpForce_4;
	if (g_pGlobalUnit->m_iRobot_Force_Count >= 1000)
	{
		g_pGlobalUnit->m_iRobot_Force_Count = 0;
		ui.textEdit_Robot_State->clear();
	}
	ui.textEdit_Robot_State->append("");
	ui.textEdit_Robot_State->append("");
	ui.textEdit_Robot_State->append(strState_1);
	ui.textEdit_Robot_State->append(strState_2);
	ui.textEdit_Robot_State->append(strState_3);
	ui.textEdit_Robot_State->append(strState_4);
}

void QGTRobotModule::on_toolButton_Structure_Calibrat_pressed()
{

}

void QGTRobotModule::on_toolButton_Structure_Test_pressed()
{
	g_pGlobalUnit->Set_Robot_uoload_Prog();
}
