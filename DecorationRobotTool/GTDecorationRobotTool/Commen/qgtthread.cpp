#include "qgtthread.h"

QGTThread::QGTThread(QObject *parent)
	: QThread(parent)
{
	m_bIsExit = false;
}

QGTThread::~QGTThread()
{

}

void QGTThread::run()
{
	switch (m_iThreadType)
	{
	case TMT_Chasis:
		StartThread_Chasis();
		break;
	case TMT_LiftPlat:
		StartThread_LiftPlat();
		break;
	case TMT_Robot:
		StartThread_Robot();
		break;
	case TMT_Ros:
		StartThread_Ros();
		break;
	case TMT_Lidar:
		StartThread_Lidar();
		break;
	case TMT_LaserMeasure:
		StartThread_LaserMeasure();
		break;
	case TMT_JoyHandle:
		StartThread_JoyHandle();
		break;
	case TMT_LineFollow_Read:
		StartThread_LineFollow_Read();
		break;
	case TMT_DemoPlan:
		StartThread_DemoPlan();
		break;
	default:
		break;
	}
}

void QGTThread::StartThread_Chasis()
{
	while (!m_bIsExit)
	{
		if (true == g_pGlobalUnit->IsChasisConnect())
		{
			if (true == g_pGlobalUnit->Get_Chasis_ActualInfo())
			{
				int iSpeed_Left = g_pGlobalUnit->m_iChasis_Left_TargetSpeed;
				int iSpeed_Right = g_pGlobalUnit->m_iChasis_Right_TargetSpeed;
				int iAngle_Left = g_pGlobalUnit->m_iChasis_Left_TargetAngle;
				int iAngle_Right = g_pGlobalUnit->m_iChasis_Right_TargetAngle;

				if (g_pGlobalUnit->m_nChasis_NowType == CMT_Idle)
				{
					//do nothing
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_NORMAL_Forward) //正常前进
				{
					g_pGlobalUnit->Set_Chasis_Move_Normal_Forward(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_NORMAL_Backoff) //正常后退
				{
					g_pGlobalUnit->Set_Chasis_Move_Normal_Backoff(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_NORMAL_Left) //正常左移
				{
					g_pGlobalUnit->Set_Chasis_Move_Normal_Left(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_NORMAL_Right) //正常右移
				{
					g_pGlobalUnit->Set_Chasis_Move_Normal_Right(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_ROTATE_Right) //顺时针旋转
				{
					g_pGlobalUnit->Set_Chasis_Move_Rotate_Right(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_ROTATE_Left) //逆时针旋转
				{
					g_pGlobalUnit->Set_Chasis_Move_Rotate_Left(iSpeed_Left, iSpeed_Right);
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_ROTATE)
				{
					g_pGlobalUnit->Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right);
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_LinkRod_Up)
				{
					g_pGlobalUnit->Set_Chasis_LinkRod_MoveUpOrDown(-100);
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_LinkRod_Down)
				{
					g_pGlobalUnit->Set_Chasis_LinkRod_MoveUpOrDown(100);
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_Electromagnet_On)
				{
					g_pGlobalUnit->Set_Chasis_Electromagnet_Enable(true);
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_Electromagnet_Off)
				{
					g_pGlobalUnit->Set_Chasis_Electromagnet_Enable(false);
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				else if (g_pGlobalUnit->m_nChasis_NowType == CMT_Stop)
				{
					g_pGlobalUnit->Set_Chasis_Stop();
					g_pGlobalUnit->m_nChasis_NowType = CMT_Idle;
				}
				g_pGlobalUnit->m_bIsChasisInfo_Valid = true;
				emit Chasis_Info_Output();
			}
			else
			{
				g_pGlobalUnit->m_bIsChasisInfo_Valid = false;
			}

			Sleep(50);
		}
	}
}

void QGTThread::StartThread_LiftPlat()
{
	while (!m_bIsExit)
	{
		//升降平台运动---只有连接了升降平台才能对其进行相关操作
		if (true == g_pGlobalUnit->IsLiftPlatConnect())
		{
			if (g_pGlobalUnit->m_nLiftPlat_NowStatus == LPS_Read)
			{
				if (false == g_pGlobalUnit->Get_LiftPlat_ActualInfo())
				{
					g_pGlobalUnit->Write_Debug_Info("Read LiftPlat Info Fail", DIT_Error);
				}
			}
			else if (g_pGlobalUnit->m_nLiftPlat_NowStatus == LPS_Up)
			{
				g_pGlobalUnit->Set_LiftPlat_Move_UpOrDown(g_pGlobalUnit->m_nLiftPlat_NowStatus);
				g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Read;
			}
			else if (g_pGlobalUnit->m_nLiftPlat_NowStatus == LPS_Down)
			{
				g_pGlobalUnit->Set_LiftPlat_Move_UpOrDown(g_pGlobalUnit->m_nLiftPlat_NowStatus);
				g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Read;
			}
			else if (g_pGlobalUnit->m_nLiftPlat_NowStatus == LPS_Stop)
			{
				g_pGlobalUnit->Set_LiftPlat_Move_UpOrDown(g_pGlobalUnit->m_nLiftPlat_NowStatus);
				g_pGlobalUnit->m_nLiftPlat_NowStatus = LPS_Read;
			}

			Sleep(100);
			emit LiftPlat_Info_Output();
		}
	}
}

void QGTThread::StartThread_Robot()
{
	while (!m_bIsExit)
	{
		if (true == g_pGlobalUnit->IsRobotConnect())
		{
			g_pGlobalUnit->Get_Robot_ActualInfo();
			emit Robot_Info_Output();
			Sleep(5);
		}
	}
}

void QGTThread::StartThread_Ros()
{
	while (!m_bIsExit)
	{
		if (true == g_pGlobalUnit->IsRosConnect())
		{
// 			double dwTime_Begin = ::GetTickCount();

			g_pGlobalUnit->Set_Ros_Work();
			Sleep(25);
			g_pGlobalUnit->Get_Ros_Return_Info();
			Sleep(25);

// 			double dwTime_End = ::GetTickCount();
// 			double dwTime_Offset = dwTime_End - dwTime_Begin;
// 			QString strTime = QString::fromLocal8Bit("Ros平台 频率 : ") + QString::number(dwTime_Offset);
// 			g_pGlobalUnit->Write_Debug_Info(strTime, DIT_Normal);
		}
	}
}

void QGTThread::StartThread_Lidar()
{
	while (!m_bIsExit)
	{
		if (true == g_pGlobalUnit->IsLidarConnect())
		{
			if (g_pGlobalUnit->Get_Lidar_ScanData())
			{
				g_pGlobalUnit->m_bIs_Lidar_Data_Valid = true;
			}
			else
			{
				g_pGlobalUnit->m_bIs_Lidar_Data_Valid = false;
				g_pGlobalUnit->m_iLidar_ScanFail_Count++;

				if (g_pGlobalUnit->m_iLidar_ScanFail_Count >= 5)
				{
	
					while (true)
					{
						if (g_pGlobalUnit->Set_Lidar_Connect())
						{
							g_pGlobalUnit->Write_Debug_Info(QString::fromLocal8Bit("激光雷达自动重启机制---重置激光雷达"), DIT_Normal);
							break;
						}
					}

				}
			}

			Sleep(10);
			emit Lidar_Info_Output();
			Sleep(10);
		}
	}
}

void QGTThread::StartThread_LaserMeasure()
{
	while (!m_bIsExit)
	{
		if (true == g_pGlobalUnit->IsLaserMeasureConnect())
		{
			g_pGlobalUnit->Set_Laser_Measure();

			Sleep(5);
			emit LaserMeasure_Info_Output();
			Sleep(5);
		}
	}
}

void QGTThread::StartThread_JoyHandle()
{
	while (!m_bIsExit)
	{
		Sleep(200);
		g_pGlobalUnit->Get_JoyHandle_ActualInfo();
		g_pGlobalUnit->Set_JoyHandle_Control();
		emit JoyHandle_Info_Output();
	}
}

void QGTThread::StartThread_LineFollow_Read()
{
	while (!m_bIsExit)
	{
		g_pGlobalUnit->Get_LineFollow_ActualInfo();
		emit LineFollow_Info_Output();
		Sleep(5);
	}
}

void QGTThread::StartThread_DemoPlan()
{
	while (!m_bIsExit)
	{
		if (g_pGlobalUnit->m_bIsAutoRun)
		{
			g_pGlobalUnit->Set_DemPlan_Run();
		}
		Sleep(5);
	}
}
