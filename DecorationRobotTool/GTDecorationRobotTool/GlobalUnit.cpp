#include "GlobalUnit.h"

CGlobalUnit *g_pGlobalUnit = new CGlobalUnit;

CGlobalUnit::CGlobalUnit()
{
	g_pGlobalUnit = this;

	/*------------------------------------基本设置模块---------------------------------------*/
	m_pHdlc_Chasis = new CChasisNet();
	m_pLiftPlatNet = new CMotorModbus();
	m_pRobotNet = new CURRobotArmNet();
	m_pHdlc_Ros = new CRosplatNet();
	m_pNet_Lidar = new qrk::Urg_driver();
	m_pNet_LaserMeasure = new CSerialPort();
	m_pRobot_Pressure_Net = new CSerialPort();

	m_nLoginState = LS_Nobody;
	m_bIsSelect_Chasis_Connect = true;
	m_bIsSelect_LiftPlat_Connect = true;
	m_bIsSelect_Robot_Connect = false;
	m_bIsSelect_Ros_Connect = true;
	m_bIsSelect_Lidar_Connect = true;
	m_bIsSelect_LaserMeasure_Connect = true;
	m_bIsSelect_JoyHandle_Connect = false;

	m_bIsConnect = false;

	m_strChasis_IpAddr.clear();
	m_strChasis_Port.clear();

	m_iLiftPlat_PortNum = 0;
	m_iLiftPlat_Baudrate = 0;

	m_strRobot_IpAddr.clear();
	m_strRobot_Port.clear();

	m_strRos_IpAddr.clear();
	m_strRos_Port.clear();

	m_strLidar_Port.clear();
	m_iLidar_Baudrate = 0;

	m_iLaserMeasure_Port = 0;
	m_iLaserMeasure_Baudrate = 0;

	m_iRobot_Pressure_Port = 0;

	m_bIsShowLog = false;
	/*------------------------------------基本设置模块---------------------------------------*/

	/*----------------------Chasis（底盘）运动模块-----------------------*/
	m_nChasis_NowType = CMT_Idle;
	m_bIsChasisInfo_Valid = false;
	memset(m_bzChasisCmd, 0, 16);
	m_iChasis_Left_TargetSpeed = 0;
	m_iChasis_Right_TargetSpeed = 0;
	m_iChasis_Left_TargetAngle = 0;
	m_iChasis_Right_TargetAngle = 0;
	/*----------------------Chasis（底盘）运动模块-----------------------*/


	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/
	m_nLiftPlat_NowStatus = LPS_Read;
	m_iLiftPlat_TargetSpeed = 0;
	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/

	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/
	m_iRobot_Force_Count = 0;
	m_dRobot_SpeedRate = 0.00;
	m_dRobot_AccelerationRate = 0.00;
	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/


	/*--------------------------------------------------Ros平台--------------------------------------------------*/
	m_nRos_Work_Pos_Status = RWPS_Idle;
	m_bIs_Ros_Work_Finished = true;
	m_bIs_Ros_Need_Open_Spraygun = false;
	/*--------------------------------------------------Ros平台--------------------------------------------------*/


	/*-------------------------------------------------雷达控制模块----------------------------------------------*/
	m_iLidar_SearchTurning_Step = 0;
	m_iLidar_SearchTurning_Dis_Threshold = 0;
	m_iLidar_SearchTurning_Len_Threshold = 0;

	m_iLidar_ScanFail_Count = 0;

	m_bIs_Lidar_Data_Valid = false;

	m_nLidar_Points_Array.clear();
	/*-------------------------------------------------雷达控制模块----------------------------------------------*/

	/*-------------------------------------------------激光测距模块----------------------------------------------*/
	m_dLaserMeasure_Distance = 0.000;
	/*-------------------------------------------------激光测距模块----------------------------------------------*/


	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/
	m_nJoy_Btn_Last_Status = JBS_Idle;
	m_nJoy_Pov_Last_Status = JPS_Center;
	m_nJoy_Btn_Status = JBS_Idle;
	m_nJoy_Pov_Status = JPS_Center;
	m_bIs_JoyHandle_Control_Valid = false;
	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/


	/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/
	m_iDemoPlanSet_Index = 0;
	m_bIsAutoRun = false;
	m_bIsLoopRun = false;
	m_nAutoRun_NowStatus = ARS_Idle;
	/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/



	/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/
	m_pFindLine = new CFindLine();
	m_bIs_LineFollowInfo_Valid = false;
	m_iLineFollow_InitDis_LeftWheel = 0;
	m_iLineFollow_InitDis_RightWheel = 0;
	LaserLine_Dis_Offset_Array.clear();
	m_dLineFollowSet_Calibration = 0;
	m_iLineFollowSet_SearchThreshold = 0;
	m_iLineFollowSet_MinBinaryThreshold = 0;
	m_iLineFollowSet_MaxBinaryThreshold = 0;
	m_iLineFollowSet_MinContourArea = 0;
	m_iLineFollowSet_MaxContourArea = 0;
	m_dLineFollowSet_AngleRange = 0;
	m_dLineFollowSet_DisRange = 0;
	m_iLineFollowSet_TargetDis = 0;
	m_iLineFollowSet_SpeedRate = 0;
	m_nLineFollowSet_ResultImage = cv::Mat();
	m_dLineFollowSet_ResultAngel = 0;
	m_dLineFollowSet_ResultDis = 0;
	/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/



	/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/
	m_fun_Calibration_Get_Camera_R_And_T = NULL;
	m_fun_Structure_GetPointer = NULL;
	m_fun_Structure_StartTest = NULL;
	m_fun_Structure_Display = NULL;
	m_fun_PointCloud_FindPoint = NULL;

	memset(m_dzStructure_Camera_R, 0, sizeof(m_dzStructure_Camera_R));
	memset(m_dzStructure_Camera_T, 0, sizeof(m_dzStructure_Camera_T));
	memset(m_dzStructure_Robot_R, 0, sizeof(m_dzStructure_Robot_R));
	memset(m_dzStructure_Robot_T, 0, sizeof(m_dzStructure_Robot_T));
	memset(m_dzStructure_R, 0, sizeof(m_dzStructure_R));
	memset(m_dzStructure_T, 0, sizeof(m_dzStructure_T));
	memset(m_dzStructure_Robot_Pos, 0, sizeof(m_dzStructure_Robot_Pos));

	m_bIsStructure_LoadDll = false;
	m_bIsStructure_Move = false;
	m_bIsStructure_beginTest = false;
	/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/



	/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/
	m_bIsDrawLine_Move = false;
	m_dDrawLine_Width = 0;
	m_dDrawLine_Height = 0;
	m_iDrawLine_LiftPlat_topPos = 0;
	m_iDrawLine_LiftPlat_bottomPos = 0;
	/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/



	/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/
	m_nTiling_MaterielPos_Array.clear();
	m_nTiling_PastePos_Array.clear();
	m_iTiling_Count = -1;
	m_bIsTiling_Move = false;
	/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/



	/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/
	m_iSprayPaint_Count_MovedBy_Chasis = 0;
	m_iSprayPaint_Count_MovedBy_LiftPlat = 0;
	m_iSprayPaint_Count_MovedBy_Robot = 0;

	m_dSprayPaint_LiftPlat_InitPos = 0.000;
	m_dSprayPaint_HorDis_MovedBy_Robot = 0.000;
	m_dSprayPaint_Width_By_Spray = 0.000;

	m_dSprayPaint_Overlap_By_Robot = 0.00;
	m_dSprayPaint_Overlap_By_LiftPlat = 0.00;
	m_dSprayPaint_Overlap_By_Chasis = 0.00;

	m_iSprayPaint_Current_Count_MovedBy_Chasis = 0;
	m_iSprayPaint_Current_Count_MovedBy_LiftPlat = 0;
	m_iSprayPaint_Current_Count_MovedBy_Robot = 0;

	m_bIs_SprayPaint_Robot_Move = false;

	m_dSprayPaint_Dis_MovedBy_Chasis = 0.000;
	m_dSprayPaint_Dis_MovedBy_LiftPlat = 0.000;
	m_dSprayPaint_VerDis_MovedBy_Robot = 0.000;

	m_bIs_SprayPaint_VerInsideCorner_Enable = false;
	m_bIs_SprayPaint_HorInsideCorner_Enable = false;
	m_iSprayPaint_Count_VerInsideCorner = 0;
	m_iSprayPaint_Count_HorInsideCorner = 0;

	/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/




	/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/
	m_dRos_SprayPaint_Dis_Precision = 0.000;

	m_dRos_SprayPaint_LiftPlat_InitPos = 0.000;

	m_dRos_SprayPaint_Hor_WorkDis = 0.000;
	m_dRos_SprayPaint_Ver_WorkDis = 0.000;
	m_dRos_SprayPaint_Hor_Overlap = 0.000;
	m_dRos_SprayPaint_Ver_Overlap = 0.000;

	m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall = 0.000;
	m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall = 0.000;
	m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall = 0.000;
	m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall = 0.000;

	m_iRos_SprayPaint_Count_MovedBy_Chasis = 0;
	m_iRos_SprayPaint_Count_MovedBy_LiftPlat = 0;

	m_iRos_SprayPaint_Current_Count_MovedBy_Chasis = 0;
	m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat = 0;

	m_dRos_SprayPaint_LiftPlat_MaxPos = 0.000;

	m_dRos_SprayPaint_Dis_MovedBy_Chasis = 0.000;
	m_dRos_SprayPaint_Dis_MovedBy_LiftPlat = 0.000;

	m_dRos_SprayPaint_Chasis_Angle_fromWorkwall = 0.000;
	m_dRos_SprayPaint_Chasis_Dis_fromLeftwall = 0.000;
	m_dRos_SprayPaint_Chasis_Dis_fromWorkwall = 0.000;

	m_bIs_Ros_SprayPaint_RosWork = false;
	/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/




	InitializeCriticalSection(&m_nLock); //初始化临界区 

	putSystemSetting(true);
}


CGlobalUnit::~CGlobalUnit()
{

	SetDisConnect();

	if (NULL != m_pHdlc_Chasis)
	{
		delete m_pHdlc_Chasis;
		m_pHdlc_Chasis = NULL;
	}

	if (NULL != m_pLiftPlatNet)
	{
		delete m_pLiftPlatNet;
		m_pLiftPlatNet = NULL;
	}

	if (NULL != m_pRobotNet)
	{
		delete m_pRobotNet;
		m_pRobotNet = NULL;
	}

	if (NULL != m_pHdlc_Ros)
	{
		delete m_pHdlc_Ros;
		m_pHdlc_Ros = NULL;
	}

	if (NULL != m_pNet_Lidar)
	{
		delete m_pNet_Lidar;
		m_pNet_Lidar = NULL;
	}

	if (NULL != m_pNet_LaserMeasure)
	{
		delete m_pNet_LaserMeasure;
		m_pNet_LaserMeasure = NULL;
	}

	if (NULL != m_pFindLine)
	{
		delete m_pFindLine;
		m_pFindLine = NULL;
	}

	putSystemSetting(false);

	DeleteCriticalSection(&m_nLock); //删除临界区
}

QString CGlobalUnit::GetExePath()
{
	QDir dir_temp;
	QString strPath = dir_temp.currentPath();
	return strPath;
}

QString CGlobalUnit::GetActualDate()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	QString strDate = QString::number(sys.wYear) + "-" + QString::number(sys.wMonth) + "-" + QString::number(sys.wDay);
	return strDate;
}

QString CGlobalUnit::GetActualTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	QString strTime = QString::number(sys.wYear) + "-" + QString::number(sys.wMonth) + "-" + QString::number(sys.wDay) + "  " +
		QString::number(sys.wHour) + ":" + QString::number(sys.wMinute) + ":" + QString::number(sys.wSecond) + ":" + QString::number(sys.wMilliseconds);
	return strTime;
}

void CGlobalUnit::Write_Debug_Info(const QString strInfo_Input, Debug_Info_Type iType)
{
	EnterCriticalSection(&m_nLock);//进入临界区

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
	{
		LeaveCriticalSection(&m_nLock);//离开临界区
		return;
	}

	if (iType == DIT_Normal)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	}
	else if (iType == DIT_Warning)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	}
	else if (iType == DIT_Error)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
	if (m_bIsShowLog)
	{
		qDebug() << strInfo_Input;
	}
	LeaveCriticalSection(&m_nLock);//离开临界区
}

void CGlobalUnit::Write_Log_Info(const QString strInfo_Input)
{
	EnterCriticalSection(&m_nLock);//进入临界区
	QString strFileName = "GR_Log-" + GetActualDate();
	QFile file_Log(strFileName);
	if (!file_Log.open(QFile::WriteOnly | QIODevice::Append))
	{
		LeaveCriticalSection(&m_nLock);//离开临界区
		return;
	}
	QTextStream text_Out(&file_Log);
	QString strInfo = GetActualTime() + "---" + strInfo_Input;
	text_Out << strInfo;
	LeaveCriticalSection(&m_nLock);//离开临界区
}

void CGlobalUnit::putSystemSetting(bool bIsRead)
{
	QString strIniPath = GetExePath();
	strIniPath.append("\\SystemSet\\SystemSet.ini");
	QSettings PaintRobotSet(strIniPath, QSettings::IniFormat);

	if (bIsRead)
	{
		/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/
		m_iChasis_Left_TargetSpeed = PaintRobotSet.value("ChasisModule/m_iChasis_Left_TargetSpeed").toInt();
		m_iChasis_Right_TargetSpeed = PaintRobotSet.value("ChasisModule/m_iChasis_Right_TargetSpeed").toInt();
		m_iChasis_Left_TargetAngle = PaintRobotSet.value("ChasisModule/m_iChasis_Left_TargetAngle").toInt();
		m_iChasis_Right_TargetAngle = PaintRobotSet.value("ChasisModule/m_iChasis_Right_TargetAngle").toInt();
		/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/

		/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/
		m_iLiftPlat_TargetSpeed = PaintRobotSet.value("LiftPlatModule/m_iLiftPlat_TargetSpeed").toInt();
		/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/

		/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/
		m_dRobot_SpeedRate = PaintRobotSet.value("RobotModule/m_dRobot_SpeedRate").toDouble();
		m_dRobot_AccelerationRate = PaintRobotSet.value("RobotModule/m_dRobot_AccelerationRate").toDouble();
		/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/



		/*---------------------------通讯设置---------------------------*/
		m_strChasis_IpAddr = PaintRobotSet.value("CommunicationSet/m_strChasis_IpAddr").toString();
		m_strChasis_Port = PaintRobotSet.value("CommunicationSet/m_strChasis_Port").toString();
		
		m_strRobot_IpAddr = PaintRobotSet.value("CommunicationSet/m_strRobot_IpAddr").toString();
		m_strRobot_Port = PaintRobotSet.value("CommunicationSet/m_strRobot_Port").toString();

		m_strRos_IpAddr = PaintRobotSet.value("CommunicationSet/m_strRos_IpAddr").toString();
		m_strRos_Port = PaintRobotSet.value("CommunicationSet/m_strRos_Port").toString();
		m_strLidar_Port = PaintRobotSet.value("CommunicationSet/m_strLidar_Port").toString();
		m_iLidar_Baudrate = PaintRobotSet.value("CommunicationSet/m_iLidar_Baudrate").toInt();
		m_iLaserMeasure_Port = PaintRobotSet.value("CommunicationSet/m_iLaserMeasure_Port").toInt();
		m_iLaserMeasure_Baudrate = PaintRobotSet.value("CommunicationSet/m_iLaserMeasure_Baudrate").toInt();

		m_iLiftPlat_PortNum = PaintRobotSet.value("CommunicationSet/m_iLiftPlat_PortNum").toInt();
		m_iLiftPlat_Baudrate = PaintRobotSet.value("CommunicationSet/m_iLiftPlat_Baudrate").toInt();

		m_iRobot_Pressure_Port = PaintRobotSet.value("CommunicationSet/m_iRobot_Pressure_Port").toInt();
		/*---------------------------通讯设置---------------------------*/

		/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/
		m_iDemoPlanSet_Index = PaintRobotSet.value("DemoPlanSet/m_iDemoPlanSet_Index").toInt();
		/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/

		/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/
		m_dLineFollowSet_Calibration = PaintRobotSet.value("LineFollowSet/m_dLineFollowSet_Calibration").toDouble();
		m_iLineFollowSet_SearchThreshold = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_SearchThreshold").toInt();
		m_iLineFollowSet_MinBinaryThreshold = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_MinBinaryThreshold").toInt();
		m_iLineFollowSet_MaxBinaryThreshold = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_MaxBinaryThreshold").toInt();
		m_iLineFollowSet_MinContourArea = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_MinContourArea").toInt();
		m_iLineFollowSet_MaxContourArea = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_MaxContourArea").toInt();
		m_dLineFollowSet_AngleRange = PaintRobotSet.value("LineFollowSet/m_dLineFollowSet_AngleRange").toDouble();
		m_dLineFollowSet_DisRange = PaintRobotSet.value("LineFollowSet/m_dLineFollowSet_DisRange").toDouble();
		m_iLineFollowSet_TargetDis = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_TargetDis").toInt();
		m_iLineFollowSet_SpeedRate = PaintRobotSet.value("LineFollowSet/m_iLineFollowSet_SpeedRate").toInt();
		/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/


		/*-------------------------------------------------雷达控制模块----------------------------------------------*/
		m_iLidar_SearchTurning_Step = PaintRobotSet.value("LidarSet/m_iLidar_SearchTurning_Step").toInt();
		m_iLidar_SearchTurning_Dis_Threshold = PaintRobotSet.value("LidarSet/m_iLidar_SearchTurning_Dis_Threshold").toInt();
		m_iLidar_SearchTurning_Len_Threshold = PaintRobotSet.value("LidarSet/m_iLidar_SearchTurning_Len_Threshold").toInt();
		/*-------------------------------------------------雷达控制模块----------------------------------------------*/


		/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/
		//相机的坐标系对于机械臂末端坐标系的旋转矩阵和平移矩阵
		m_dzStructure_Camera_R[0] = PaintRobotSet.value("StructureSet/Camera_R_0").toDouble();
		m_dzStructure_Camera_R[1] = PaintRobotSet.value("StructureSet/Camera_R_1").toDouble();
		m_dzStructure_Camera_R[2] = PaintRobotSet.value("StructureSet/Camera_R_2").toDouble();
		m_dzStructure_Camera_R[3] = PaintRobotSet.value("StructureSet/Camera_R_3").toDouble();
		m_dzStructure_Camera_R[4] = PaintRobotSet.value("StructureSet/Camera_R_4").toDouble();
		m_dzStructure_Camera_R[5] = PaintRobotSet.value("StructureSet/Camera_R_5").toDouble();
		m_dzStructure_Camera_R[6] = PaintRobotSet.value("StructureSet/Camera_R_6").toDouble();
		m_dzStructure_Camera_R[7] = PaintRobotSet.value("StructureSet/Camera_R_7").toDouble();
		m_dzStructure_Camera_R[8] = PaintRobotSet.value("StructureSet/Camera_R_8").toDouble();

		m_dzStructure_Camera_T[0] = PaintRobotSet.value("StructureSet/Camera_T_0").toDouble();
		m_dzStructure_Camera_T[1] = PaintRobotSet.value("StructureSet/Camera_T_1").toDouble();
		m_dzStructure_Camera_T[2] = PaintRobotSet.value("StructureSet/Camera_T_2").toDouble();

		//机械臂的末端坐标系对于基座标系的旋转矩阵和平移矩阵
		m_dzStructure_Robot_R[0] = PaintRobotSet.value("StructureSet/Robot_R_0").toDouble();
		m_dzStructure_Robot_R[1] = PaintRobotSet.value("StructureSet/Robot_R_1").toDouble();
		m_dzStructure_Robot_R[2] = PaintRobotSet.value("StructureSet/Robot_R_2").toDouble();
		m_dzStructure_Robot_R[3] = PaintRobotSet.value("StructureSet/Robot_R_3").toDouble();
		m_dzStructure_Robot_R[4] = PaintRobotSet.value("StructureSet/Robot_R_4").toDouble();
		m_dzStructure_Robot_R[5] = PaintRobotSet.value("StructureSet/Robot_R_5").toDouble();
		m_dzStructure_Robot_R[6] = PaintRobotSet.value("StructureSet/Robot_R_6").toDouble();
		m_dzStructure_Robot_R[7] = PaintRobotSet.value("StructureSet/Robot_R_7").toDouble();
		m_dzStructure_Robot_R[8] = PaintRobotSet.value("StructureSet/Robot_R_8").toDouble();

		m_dzStructure_Robot_T[0] = PaintRobotSet.value("StructureSet/Robot_T_0").toDouble();
		m_dzStructure_Robot_T[1] = PaintRobotSet.value("StructureSet/Robot_T_1").toDouble();
		m_dzStructure_Robot_T[2] = PaintRobotSet.value("StructureSet/Robot_T_2").toDouble();

		//相机坐标系到机械臂基坐标系的旋转矩阵和平移矩阵
		m_dzStructure_R[0] = PaintRobotSet.value("StructureSet/Structure_R_0").toDouble();
		m_dzStructure_R[1] = PaintRobotSet.value("StructureSet/Structure_R_1").toDouble();
		m_dzStructure_R[2] = PaintRobotSet.value("StructureSet/Structure_R_2").toDouble();
		m_dzStructure_R[3] = PaintRobotSet.value("StructureSet/Structure_R_3").toDouble();
		m_dzStructure_R[4] = PaintRobotSet.value("StructureSet/Structure_R_4").toDouble();
		m_dzStructure_R[5] = PaintRobotSet.value("StructureSet/Structure_R_5").toDouble();
		m_dzStructure_R[6] = PaintRobotSet.value("StructureSet/Structure_R_6").toDouble();
		m_dzStructure_R[7] = PaintRobotSet.value("StructureSet/Structure_R_7").toDouble();
		m_dzStructure_R[8] = PaintRobotSet.value("StructureSet/Structure_R_8").toDouble();

		m_dzStructure_T[0] = PaintRobotSet.value("StructureSet/Structure_T_0").toDouble();
		m_dzStructure_T[1] = PaintRobotSet.value("StructureSet/Structure_T_1").toDouble();
		m_dzStructure_T[2] = PaintRobotSet.value("StructureSet/Structure_T_2").toDouble();
		/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/



		/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/
		m_nDrawLine_InitPos.dwX = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_X").toDouble();
		m_nDrawLine_InitPos.dwY = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_Y").toDouble();
		m_nDrawLine_InitPos.dwZ = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_Z").toDouble();
		m_nDrawLine_InitPos.dwU = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_U").toDouble();
		m_nDrawLine_InitPos.dwV = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_V").toDouble();
		m_nDrawLine_InitPos.dwW = PaintRobotSet.value("DrawLineSet/m_nDrawLine_InitPos_W").toDouble();

		m_ptDrawLine_topLeft.setX(PaintRobotSet.value("DrawLineSet/m_ptDrawLine_topLeft_X").toDouble());
		m_ptDrawLine_topLeft.setY(PaintRobotSet.value("DrawLineSet/m_ptDrawLine_topLeft_Y").toDouble());
		m_ptDrawLine_topLeft.setZ(PaintRobotSet.value("DrawLineSet/m_ptDrawLine_topLeft_Z").toDouble());

		m_dDrawLine_Width = PaintRobotSet.value("DrawLineSet/m_dDrawLine_Width").toDouble();
		m_dDrawLine_Height = PaintRobotSet.value("DrawLineSet/m_dDrawLine_Height").toDouble();

		m_iDrawLine_LiftPlat_topPos = PaintRobotSet.value("DrawLineSet/m_iDrawLine_LiftPlat_topPos").toInt();
		m_iDrawLine_LiftPlat_bottomPos = PaintRobotSet.value("DrawLineSet/m_iDrawLine_LiftPlat_bottomPos").toInt();
		/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/



		/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/
		m_nTiling_InitPos.dwX = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_X").toDouble();
		m_nTiling_InitPos.dwY = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Y").toDouble();
		m_nTiling_InitPos.dwZ = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Z").toDouble();
		m_nTiling_InitPos.dwU = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_U").toDouble();
		m_nTiling_InitPos.dwV = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_V").toDouble();
		m_nTiling_InitPos.dwW = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_W").toDouble();

		m_nTiling_InitPos_Materiel.dwX = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_X").toDouble();
		m_nTiling_InitPos_Materiel.dwY = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_Y").toDouble();
		m_nTiling_InitPos_Materiel.dwZ = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_Z").toDouble();
		m_nTiling_InitPos_Materiel.dwU = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_U").toDouble();
		m_nTiling_InitPos_Materiel.dwV = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_V").toDouble();
		m_nTiling_InitPos_Materiel.dwW = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Materiel_W").toDouble();

		m_nTiling_InitPos_Paste.dwX = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_X").toDouble();
		m_nTiling_InitPos_Paste.dwY = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_Y").toDouble();
		m_nTiling_InitPos_Paste.dwZ = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_Z").toDouble();
		m_nTiling_InitPos_Paste.dwU = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_U").toDouble();
		m_nTiling_InitPos_Paste.dwV = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_V").toDouble();
		m_nTiling_InitPos_Paste.dwW = PaintRobotSet.value("TilingSet/m_nTiling_InitPos_Paste_W").toDouble();

		m_nTiling_InitAngle_Materiel.dwX = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_X").toDouble();
		m_nTiling_InitAngle_Materiel.dwY = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_Y").toDouble();
		m_nTiling_InitAngle_Materiel.dwZ = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_Z").toDouble();
		m_nTiling_InitAngle_Materiel.dwU = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_U").toDouble();
		m_nTiling_InitAngle_Materiel.dwV = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_V").toDouble();
		m_nTiling_InitAngle_Materiel.dwW = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Materiel_W").toDouble();

		m_nTiling_InitAngle_Paste.dwX = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_X").toDouble();
		m_nTiling_InitAngle_Paste.dwY = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_Y").toDouble();
		m_nTiling_InitAngle_Paste.dwZ = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_Z").toDouble();
		m_nTiling_InitAngle_Paste.dwU = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_U").toDouble();
		m_nTiling_InitAngle_Paste.dwV = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_V").toDouble();
		m_nTiling_InitAngle_Paste.dwW = PaintRobotSet.value("TilingSet/m_nTiling_InitAngle_Paste_W").toDouble();

		m_dTiling_Materiel_Width = PaintRobotSet.value("TilingSet/m_dTiling_Materiel_Width").toDouble();
		m_dTiling_Materiel_Thickness = PaintRobotSet.value("TilingSet/m_dTiling_Materiel_Thickness").toDouble();
		m_dTiling_Paste_Feed = PaintRobotSet.value("TilingSet/m_dTiling_Paste_Feed").toDouble();
		m_iTiling_Materiel_Num = PaintRobotSet.value("TilingSet/m_iTiling_Materiel_Num").toInt();
		m_iTiling_Pressure_Range = PaintRobotSet.value("TilingSet/m_iTiling_Pressure_Range").toInt();
		/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/



		/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/
		m_nSprayPaint_Robot_InitPos.dwX = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_X").toDouble();
		m_nSprayPaint_Robot_InitPos.dwY = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_Y").toDouble();
		m_nSprayPaint_Robot_InitPos.dwZ = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_Z").toDouble();
		m_nSprayPaint_Robot_InitPos.dwU = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_U").toDouble();
		m_nSprayPaint_Robot_InitPos.dwV = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_V").toDouble();
		m_nSprayPaint_Robot_InitPos.dwW = PaintRobotSet.value("SprayPaintSet/m_nSprayPaint_Robot_InitPos_W").toDouble();

		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwX = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_X").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwY = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_Y").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwZ = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_Z").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwU = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_U").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwV = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_V").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwW = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_A_W").toDouble();

		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwX = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_X").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwY = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_Y").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwZ = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_Z").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwU = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_U").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwV = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_V").toDouble();
		m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwW = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_VerInsideCorner_RobotPos_B_W").toDouble();

		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwX = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_X").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwY = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_Y").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwZ = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_Z").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwU = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_U").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwV = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_V").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwW = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_A_W").toDouble();

		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwX = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_X").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwY = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_Y").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwZ = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_Z").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwU = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_U").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwV = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_V").toDouble();
		m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwW = PaintRobotSet.value("SprayPaintSet/m_nSprayPaintSet_HorInsideCorner_RobotPos_B_W").toDouble();

		m_bIs_SprayPaint_VerInsideCorner_Enable = PaintRobotSet.value("SprayPaintSet/m_bIs_SprayPaint_VerInsideCorner_Enable").toBool();
		m_bIs_SprayPaint_HorInsideCorner_Enable = PaintRobotSet.value("SprayPaintSet/m_bIs_SprayPaint_HorInsideCorner_Enable").toBool();
		m_iSprayPaint_Count_VerInsideCorner = PaintRobotSet.value("SprayPaintSet/m_iSprayPaint_Count_VerInsideCorner").toInt();
		m_iSprayPaint_Count_HorInsideCorner = PaintRobotSet.value("SprayPaintSet/m_iSprayPaint_Count_HorInsideCorner").toInt();

		m_iSprayPaint_Count_MovedBy_Chasis = PaintRobotSet.value("SprayPaintSet/m_iSprayPaint_Count_MovedBy_Chasis").toInt();
		m_iSprayPaint_Count_MovedBy_LiftPlat = PaintRobotSet.value("SprayPaintSet/m_iSprayPaint_Count_MovedBy_LiftPlat").toInt();
		m_iSprayPaint_Count_MovedBy_Robot = PaintRobotSet.value("SprayPaintSet/m_iSprayPaint_Count_MovedBy_Robot").toInt();

		m_dSprayPaint_LiftPlat_InitPos = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_LiftPlat_InitPos").toDouble();
		m_dSprayPaint_HorDis_MovedBy_Robot = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_HorDis_MovedBy_Robot").toDouble();
		m_dSprayPaint_Width_By_Spray = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_Width_By_Spray").toDouble();

		m_dSprayPaint_Overlap_By_Robot = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_Overlap_By_Robot").toDouble();
		m_dSprayPaint_Overlap_By_LiftPlat = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_Overlap_By_LiftPlat").toDouble();
		m_dSprayPaint_Overlap_By_Chasis = PaintRobotSet.value("SprayPaintSet/m_dSprayPaint_Overlap_By_Chasis").toDouble();
		/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/


		/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/
		m_dRos_SprayPaint_Dis_Precision = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Dis_Precision").toDouble();
		m_dRos_SprayPaint_LiftPlat_InitPos = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_LiftPlat_InitPos").toDouble();
		m_dRos_SprayPaint_Hor_WorkDis = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Hor_WorkDis").toDouble();
		m_dRos_SprayPaint_Ver_WorkDis = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Ver_WorkDis").toDouble();
		m_dRos_SprayPaint_Hor_Overlap = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Hor_Overlap").toDouble();
		m_dRos_SprayPaint_Ver_Overlap = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Ver_Overlap").toDouble();
		m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall").toDouble();
		m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall").toDouble();
		m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall").toDouble();
		m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall = PaintRobotSet.value("RosSprayPaintSet/m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall").toDouble();
		/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/
	}
	else
	{
		/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/
		PaintRobotSet.beginGroup("ChasisModule");
		PaintRobotSet.setValue("m_iChasis_Left_TargetSpeed", m_iChasis_Left_TargetSpeed);
		PaintRobotSet.setValue("m_iChasis_Right_TargetSpeed", m_iChasis_Right_TargetSpeed);
		PaintRobotSet.setValue("m_iChasis_Left_TargetAngle", m_iChasis_Left_TargetAngle);
		PaintRobotSet.setValue("m_iChasis_Right_TargetAngle", m_iChasis_Right_TargetAngle);
		PaintRobotSet.endGroup();
		/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/

		/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/
		PaintRobotSet.beginGroup("LiftPlatModule");
		PaintRobotSet.setValue("m_iLiftPlat_TargetSpeed", m_iLiftPlat_TargetSpeed);
		PaintRobotSet.endGroup();
		/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/

		/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/
		PaintRobotSet.beginGroup("RobotModule");
		PaintRobotSet.setValue("m_dRobot_SpeedRate", m_dRobot_SpeedRate);
		PaintRobotSet.setValue("m_dRobot_AccelerationRate", m_dRobot_AccelerationRate);
		PaintRobotSet.endGroup();
		/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/




		/*---------------------------通讯设置---------------------------*/
		PaintRobotSet.beginGroup("CommunicationSet");
		PaintRobotSet.setValue("m_strChasis_IpAddr", m_strChasis_IpAddr);
		PaintRobotSet.setValue("m_strChasis_Port", m_strChasis_Port);
		
		PaintRobotSet.setValue("m_strRobot_IpAddr", m_strRobot_IpAddr);
		PaintRobotSet.setValue("m_strRobot_Port", m_strRobot_Port);

		PaintRobotSet.setValue("m_strRos_IpAddr", m_strRos_IpAddr);
		PaintRobotSet.setValue("m_strRos_Port", m_strRos_Port);
		PaintRobotSet.setValue("m_strLidar_Port", m_strLidar_Port);
		PaintRobotSet.setValue("m_iLidar_Baudrate", m_iLidar_Baudrate);
		PaintRobotSet.setValue("m_iLaserMeasure_Port", m_iLaserMeasure_Port);
		PaintRobotSet.setValue("m_iLaserMeasure_Baudrate", m_iLaserMeasure_Baudrate);
		
		PaintRobotSet.setValue("m_iLiftPlat_PortNum", m_iLiftPlat_PortNum);
		PaintRobotSet.setValue("m_iLiftPlat_Baudrate", m_iLiftPlat_Baudrate);

		PaintRobotSet.setValue("m_iRobot_Pressure_Port", m_iRobot_Pressure_Port);
		PaintRobotSet.endGroup();
		/*---------------------------通讯设置---------------------------*/

		/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("DemoPlanSet");
		PaintRobotSet.setValue("m_iDemoPlanSet_Index", m_iDemoPlanSet_Index);
		PaintRobotSet.endGroup();
		/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/

		/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("LineFollowSet");
		PaintRobotSet.setValue("m_dLineFollowSet_Calibration", m_dLineFollowSet_Calibration);
		PaintRobotSet.setValue("m_iLineFollowSet_SearchThreshold", m_iLineFollowSet_SearchThreshold);
		PaintRobotSet.setValue("m_iLineFollowSet_MinBinaryThreshold", m_iLineFollowSet_MinBinaryThreshold);
		PaintRobotSet.setValue("m_iLineFollowSet_MaxBinaryThreshold", m_iLineFollowSet_MaxBinaryThreshold);
		PaintRobotSet.setValue("m_iLineFollowSet_MinContourArea", m_iLineFollowSet_MinContourArea);
		PaintRobotSet.setValue("m_iLineFollowSet_MaxContourArea", m_iLineFollowSet_MaxContourArea);
		PaintRobotSet.setValue("m_dLineFollowSet_AngleRange", m_dLineFollowSet_AngleRange);
		PaintRobotSet.setValue("m_dLineFollowSet_DisRange", m_dLineFollowSet_DisRange);
		PaintRobotSet.setValue("m_iLineFollowSet_TargetDis", m_iLineFollowSet_TargetDis);
		PaintRobotSet.setValue("m_iLineFollowSet_SpeedRate", m_iLineFollowSet_SpeedRate);
		PaintRobotSet.endGroup();
		/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/


		/*-------------------------------------------------雷达控制模块----------------------------------------------*/
		PaintRobotSet.beginGroup("LidarSet");
		PaintRobotSet.setValue("m_iLidar_SearchTurning_Step", m_iLidar_SearchTurning_Step);
		PaintRobotSet.setValue("m_iLidar_SearchTurning_Dis_Threshold", m_iLidar_SearchTurning_Dis_Threshold);
		PaintRobotSet.setValue("m_iLidar_SearchTurning_Len_Threshold", m_iLidar_SearchTurning_Len_Threshold);
		PaintRobotSet.endGroup();
		/*-------------------------------------------------雷达控制模块----------------------------------------------*/


		/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("StructureSet");
		//相机的坐标系对于机械臂末端坐标系的旋转矩阵和平移矩阵
		PaintRobotSet.setValue("Camera_R_0", m_dzStructure_Camera_R[0]);
		PaintRobotSet.setValue("Camera_R_1", m_dzStructure_Camera_R[1]);
		PaintRobotSet.setValue("Camera_R_2", m_dzStructure_Camera_R[2]);
		PaintRobotSet.setValue("Camera_R_3", m_dzStructure_Camera_R[3]);
		PaintRobotSet.setValue("Camera_R_4", m_dzStructure_Camera_R[4]);
		PaintRobotSet.setValue("Camera_R_5", m_dzStructure_Camera_R[5]);
		PaintRobotSet.setValue("Camera_R_6", m_dzStructure_Camera_R[6]);
		PaintRobotSet.setValue("Camera_R_7", m_dzStructure_Camera_R[7]);
		PaintRobotSet.setValue("Camera_R_8", m_dzStructure_Camera_R[8]);

		PaintRobotSet.setValue("Camera_T_0", m_dzStructure_Camera_T[0]);
		PaintRobotSet.setValue("Camera_T_1", m_dzStructure_Camera_T[1]);
		PaintRobotSet.setValue("Camera_T_2", m_dzStructure_Camera_T[2]);

		//机械臂的末端坐标系对于基座标系的旋转矩阵和平移矩阵
		PaintRobotSet.setValue("Robot_R_0", m_dzStructure_Robot_R[0]);
		PaintRobotSet.setValue("Robot_R_1", m_dzStructure_Robot_R[1]);
		PaintRobotSet.setValue("Robot_R_2", m_dzStructure_Robot_R[2]);
		PaintRobotSet.setValue("Robot_R_3", m_dzStructure_Robot_R[3]);
		PaintRobotSet.setValue("Robot_R_4", m_dzStructure_Robot_R[4]);
		PaintRobotSet.setValue("Robot_R_5", m_dzStructure_Robot_R[5]);
		PaintRobotSet.setValue("Robot_R_6", m_dzStructure_Robot_R[6]);
		PaintRobotSet.setValue("Robot_R_7", m_dzStructure_Robot_R[7]);
		PaintRobotSet.setValue("Robot_R_8", m_dzStructure_Robot_R[8]);

		PaintRobotSet.setValue("Robot_T_0", m_dzStructure_Robot_T[0]);
		PaintRobotSet.setValue("Robot_T_1", m_dzStructure_Robot_T[1]);
		PaintRobotSet.setValue("Robot_T_2", m_dzStructure_Robot_T[2]);

		//相机坐标系到机械臂基坐标系的旋转矩阵和平移矩阵
		PaintRobotSet.setValue("Structure_R_0", m_dzStructure_R[0]);
		PaintRobotSet.setValue("Structure_R_1", m_dzStructure_R[1]);
		PaintRobotSet.setValue("Structure_R_2", m_dzStructure_R[2]);
		PaintRobotSet.setValue("Structure_R_3", m_dzStructure_R[3]);
		PaintRobotSet.setValue("Structure_R_4", m_dzStructure_R[4]);
		PaintRobotSet.setValue("Structure_R_5", m_dzStructure_R[5]);
		PaintRobotSet.setValue("Structure_R_6", m_dzStructure_R[6]);
		PaintRobotSet.setValue("Structure_R_7", m_dzStructure_R[7]);
		PaintRobotSet.setValue("Structure_R_8", m_dzStructure_R[8]);

		PaintRobotSet.setValue("Structure_T_0", m_dzStructure_T[0]);
		PaintRobotSet.setValue("Structure_T_1", m_dzStructure_T[1]);
		PaintRobotSet.setValue("Structure_T_2", m_dzStructure_T[2]);

		//机械臂的坐标
		PaintRobotSet.setValue("Robot_Pos_0", m_dzStructure_Robot_Pos[0]);
		PaintRobotSet.setValue("Robot_Pos_1", m_dzStructure_Robot_Pos[1]);
		PaintRobotSet.setValue("Robot_Pos_2", m_dzStructure_Robot_Pos[2]);
		PaintRobotSet.setValue("Robot_Pos_3", m_dzStructure_Robot_Pos[3]);
		PaintRobotSet.setValue("Robot_Pos_4", m_dzStructure_Robot_Pos[4]);
		PaintRobotSet.setValue("Robot_Pos_5", m_dzStructure_Robot_Pos[5]);
		PaintRobotSet.endGroup();
		/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/


		/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("DrawLineSet");
		PaintRobotSet.setValue("m_nDrawLine_InitPos_X", m_nDrawLine_InitPos.dwX);
		PaintRobotSet.setValue("m_nDrawLine_InitPos_Y", m_nDrawLine_InitPos.dwY);
		PaintRobotSet.setValue("m_nDrawLine_InitPos_Z", m_nDrawLine_InitPos.dwZ);
		PaintRobotSet.setValue("m_nDrawLine_InitPos_U", m_nDrawLine_InitPos.dwU);
		PaintRobotSet.setValue("m_nDrawLine_InitPos_V", m_nDrawLine_InitPos.dwV);
		PaintRobotSet.setValue("m_nDrawLine_InitPos_W", m_nDrawLine_InitPos.dwW);

		PaintRobotSet.setValue("m_ptDrawLine_topLeft_X", m_ptDrawLine_topLeft.x());
		PaintRobotSet.setValue("m_ptDrawLine_topLeft_Y", m_ptDrawLine_topLeft.y());
		PaintRobotSet.setValue("m_ptDrawLine_topLeft_Z", m_ptDrawLine_topLeft.z());

		PaintRobotSet.setValue("m_dDrawLine_Width", m_dDrawLine_Width);
		PaintRobotSet.setValue("m_dDrawLine_Height", m_dDrawLine_Height);

		PaintRobotSet.setValue("m_iDrawLine_LiftPlat_topPos", m_iDrawLine_LiftPlat_topPos);
		PaintRobotSet.setValue("m_iDrawLine_LiftPlat_bottomPos", m_iDrawLine_LiftPlat_bottomPos);
		PaintRobotSet.endGroup();
		/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/



		/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("TilingSet");

		PaintRobotSet.setValue("m_nTiling_InitPos_X", m_nTiling_InitPos.dwX);
		PaintRobotSet.setValue("m_nTiling_InitPos_Y", m_nTiling_InitPos.dwY);
		PaintRobotSet.setValue("m_nTiling_InitPos_Z", m_nTiling_InitPos.dwZ);
		PaintRobotSet.setValue("m_nTiling_InitPos_U", m_nTiling_InitPos.dwU);
		PaintRobotSet.setValue("m_nTiling_InitPos_V", m_nTiling_InitPos.dwV);
		PaintRobotSet.setValue("m_nTiling_InitPos_W", m_nTiling_InitPos.dwW);

		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_X", m_nTiling_InitPos_Materiel.dwX);
		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_Y", m_nTiling_InitPos_Materiel.dwY);
		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_Z", m_nTiling_InitPos_Materiel.dwZ);
		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_U", m_nTiling_InitPos_Materiel.dwU);
		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_V", m_nTiling_InitPos_Materiel.dwV);
		PaintRobotSet.setValue("m_nTiling_InitPos_Materiel_W", m_nTiling_InitPos_Materiel.dwW);

		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_X", m_nTiling_InitPos_Paste.dwX);
		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_Y", m_nTiling_InitPos_Paste.dwY);
		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_Z", m_nTiling_InitPos_Paste.dwZ);
		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_U", m_nTiling_InitPos_Paste.dwU);
		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_V", m_nTiling_InitPos_Paste.dwV);
		PaintRobotSet.setValue("m_nTiling_InitPos_Paste_W", m_nTiling_InitPos_Paste.dwW);

		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_X", m_nTiling_InitAngle_Materiel.dwX);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_Y", m_nTiling_InitAngle_Materiel.dwY);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_Z", m_nTiling_InitAngle_Materiel.dwZ);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_U", m_nTiling_InitAngle_Materiel.dwU);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_V", m_nTiling_InitAngle_Materiel.dwV);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Materiel_W", m_nTiling_InitAngle_Materiel.dwW);

		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_X", m_nTiling_InitAngle_Paste.dwX);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_Y", m_nTiling_InitAngle_Paste.dwY);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_Z", m_nTiling_InitAngle_Paste.dwZ);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_U", m_nTiling_InitAngle_Paste.dwU);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_V", m_nTiling_InitAngle_Paste.dwV);
		PaintRobotSet.setValue("m_nTiling_InitAngle_Paste_W", m_nTiling_InitAngle_Paste.dwW);

		PaintRobotSet.setValue("m_dTiling_Materiel_Width", m_dTiling_Materiel_Width);
		PaintRobotSet.setValue("m_dTiling_Materiel_Thickness", m_dTiling_Materiel_Thickness);
		PaintRobotSet.setValue("m_dTiling_Paste_Feed", m_dTiling_Paste_Feed);
		PaintRobotSet.setValue("m_iTiling_Materiel_Num", m_iTiling_Materiel_Num);
		PaintRobotSet.setValue("m_iTiling_Pressure_Range", m_iTiling_Pressure_Range);

		PaintRobotSet.endGroup();
		/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/



		/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("SprayPaintSet");

		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_X", m_nSprayPaint_Robot_InitPos.dwX);
		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_Y", m_nSprayPaint_Robot_InitPos.dwY);
		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_Z", m_nSprayPaint_Robot_InitPos.dwZ);
		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_U", m_nSprayPaint_Robot_InitPos.dwU);
		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_V", m_nSprayPaint_Robot_InitPos.dwV);
		PaintRobotSet.setValue("m_nSprayPaint_Robot_InitPos_W", m_nSprayPaint_Robot_InitPos.dwW);

		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_X", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwX);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_Y", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwY);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_Z", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwZ);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_U", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwU);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_V", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwV);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_A_W", m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwW);

		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_X", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwX);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_Y", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwY);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_Z", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwZ);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_U", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwU);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_V", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwV);
		PaintRobotSet.setValue("m_nSprayPaintSet_VerInsideCorner_RobotPos_B_W", m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwW);

		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_X", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwX);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_Y", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwY);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_Z", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwZ);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_U", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwU);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_V", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwV);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_A_W", m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwW);

		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_X", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwX);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_Y", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwY);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_Z", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwZ);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_U", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwU);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_V", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwV);
		PaintRobotSet.setValue("m_nSprayPaintSet_HorInsideCorner_RobotPos_B_W", m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwW);

		PaintRobotSet.setValue("m_bIs_SprayPaint_VerInsideCorner_Enable", m_bIs_SprayPaint_VerInsideCorner_Enable);
		PaintRobotSet.setValue("m_bIs_SprayPaint_HorInsideCorner_Enable", m_bIs_SprayPaint_HorInsideCorner_Enable);
		PaintRobotSet.setValue("m_iSprayPaint_Count_VerInsideCorner", m_iSprayPaint_Count_VerInsideCorner);
		PaintRobotSet.setValue("m_iSprayPaint_Count_HorInsideCorner", m_iSprayPaint_Count_HorInsideCorner);

		PaintRobotSet.setValue("m_iSprayPaint_Count_MovedBy_Chasis", m_iSprayPaint_Count_MovedBy_Chasis);
		PaintRobotSet.setValue("m_iSprayPaint_Count_MovedBy_LiftPlat", m_iSprayPaint_Count_MovedBy_LiftPlat);
		PaintRobotSet.setValue("m_iSprayPaint_Count_MovedBy_Robot", m_iSprayPaint_Count_MovedBy_Robot);

		PaintRobotSet.setValue("m_dSprayPaint_LiftPlat_InitPos", m_dSprayPaint_LiftPlat_InitPos);
		PaintRobotSet.setValue("m_dSprayPaint_HorDis_MovedBy_Robot", m_dSprayPaint_HorDis_MovedBy_Robot);
		PaintRobotSet.setValue("m_dSprayPaint_Width_By_Spray", m_dSprayPaint_Width_By_Spray);

		PaintRobotSet.setValue("m_dSprayPaint_Overlap_By_Robot", m_dSprayPaint_Overlap_By_Robot);
		PaintRobotSet.setValue("m_dSprayPaint_Overlap_By_LiftPlat", m_dSprayPaint_Overlap_By_LiftPlat);
		PaintRobotSet.setValue("m_dSprayPaint_Overlap_By_Chasis", m_dSprayPaint_Overlap_By_Chasis);

		PaintRobotSet.endGroup();
		/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/


		/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/
		PaintRobotSet.beginGroup("RosSprayPaintSet");
		PaintRobotSet.setValue("m_dRos_SprayPaint_Dis_Precision", m_dRos_SprayPaint_Dis_Precision);
		PaintRobotSet.setValue("m_dRos_SprayPaint_LiftPlat_InitPos", m_dRos_SprayPaint_LiftPlat_InitPos);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Hor_WorkDis", m_dRos_SprayPaint_Hor_WorkDis);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Ver_WorkDis", m_dRos_SprayPaint_Ver_WorkDis);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Hor_Overlap", m_dRos_SprayPaint_Hor_Overlap);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Ver_Overlap", m_dRos_SprayPaint_Ver_Overlap);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall", m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall", m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall", m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall);
		PaintRobotSet.setValue("m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall", m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall);
		PaintRobotSet.endGroup();
		/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/

	}
}

bool CGlobalUnit::SetConnect()
{
	std::string strIp_Chasis = m_strChasis_IpAddr.toStdString();
	const char *pBufIp_Chasis = strIp_Chasis.c_str();
	const unsigned short iPort_Chasis = m_strChasis_Port.toShort();

	std::string strIp_RobotArm = m_strRobot_IpAddr.toStdString();
	const char *pBufIp_RobotArm = strIp_RobotArm.c_str();
	const unsigned short iPort_RobotArm = m_strRobot_Port.toShort();

	std::string strIp_Ros = m_strRos_IpAddr.toStdString();
	const char *pBufIp_Ros = strIp_Ros.c_str();
	const unsigned short iPort_Ros = m_strRos_Port.toShort();

	if (true == m_bIsSelect_Chasis_Connect)
	{
		if (false == m_pHdlc_Chasis->OpenPort(pBufIp_Chasis, iPort_Chasis))
		{
			Write_Debug_Info("Open Chasis Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_LiftPlat_Connect)
	{
		if (false == m_pLiftPlatNet->OpenPort(m_iLiftPlat_PortNum, m_iLiftPlat_Baudrate, "N", 8, 1, EV_RXCHAR))
		{
			Write_Debug_Info("Open LiftPlat Port Fail", DIT_Error);
			return false;
		}
		if (false == Set_LiftPlat_MotorEnable(true))
		{
			Write_Debug_Info("Enable LiftPlat Motor Modbus Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_Robot_Connect)
	{
		if (false == m_pRobotNet->OpenPort(pBufIp_RobotArm, iPort_RobotArm))
		{
			Write_Debug_Info("Open Robot Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_Ros_Connect)
	{
		if (false == m_pHdlc_Ros->OpenPort(pBufIp_Ros, iPort_Ros))
		{
			Write_Debug_Info("Open Ros Port Fail", DIT_Error);
			return false;
		}	
	}

	if (true == m_bIsSelect_Lidar_Connect)
	{
		if (false == Set_Lidar_Connect())
		{
			Write_Debug_Info("Open Lidar Port Fail", DIT_Error);
			return false;
		}
// 		if (false == Set_Lidar_Begin_Scan())
// 		{
// 			Write_Debug_Info("Start Lidar Scan Fail", DIT_Error);
// 			return false;
// 		}
	}

	if (true == m_bIsSelect_LaserMeasure_Connect)
	{
		if (false == m_pNet_LaserMeasure->InitPort(m_iLaserMeasure_Port, m_iLaserMeasure_Baudrate, "N", 8, 1, EV_RXCHAR))
		{
			Write_Debug_Info("Open LaserMeasure Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_JoyHandle_Connect)
	{
		if (false == Is_JoyHandle_Valid())
		{
			Write_Debug_Info("Connect JoyHandle Fail", DIT_Error);
			return false;
		}
	}

	Write_Debug_Info("Connect Pass", DIT_Normal);
	m_bIsConnect = true;
	return true;
}

bool CGlobalUnit::SetDisConnect()
{
	if (true == m_bIsSelect_Chasis_Connect)
	{
		if (false == m_pHdlc_Chasis->ClosePort())
		{
			Write_Debug_Info("Close Chasis Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_LiftPlat_Connect)
	{
		if (false == Set_LiftPlat_MotorEnable(false))
		{
			Write_Debug_Info("UnEnable LiftPlat Motor Modbus Fail", DIT_Error);
			return false;
		}
		if (false == m_pLiftPlatNet->ClosePort())
		{
			Write_Debug_Info("Close LiftPlat Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_Robot_Connect)
	{
		if (false == m_pRobotNet->ClosePort())
		{
			Write_Debug_Info("Close Robot Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_Ros_Connect)
	{
		if (false == m_pHdlc_Ros->ClosePort())
		{
			Write_Debug_Info("Close Ros Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_Lidar_Connect)
	{
// 		if (false == Set_Lidar_End_Scan())
// 		{
// 			Write_Debug_Info("End Lidar Scan Fail", DIT_Error);
// 			return false;
// 		}
		if (false == Set_Lidar_DisConnect())
		{
			Write_Debug_Info("Close Lidar Port Fail", DIT_Error);
			return false;
		}
	}

	if (true == m_bIsSelect_LaserMeasure_Connect)
	{
		if (false == m_pNet_LaserMeasure->ClosePort())
		{
			Write_Debug_Info("Close LaserMeasure Port Fail", DIT_Error);
			return false;
		}
	}

	Write_Debug_Info("DisConnect Pass", DIT_Normal);
	m_bIsConnect = false;
	return true;
}

bool CGlobalUnit::IsChasisConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_Chasis_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsLiftPlatConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_LiftPlat_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsRobotConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_Robot_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsRosConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_Ros_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsLidarConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_Lidar_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsLaserMeasureConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_LaserMeasure_Connect))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsJoyHandleConnect()
{
	if ((true == m_bIsConnect) && (true == m_bIsSelect_JoyHandle_Connect))
	{
		return true;
	}
	return false;
}

int CGlobalUnit::Translate16ToInt(const byte high_Input, const byte low_Input)
{

	int iData_Output = high_Input << 8 | low_Input;
	if (iData_Output > 32767)
	{
		iData_Output = 32768 - iData_Output;
	}
	return iData_Output;
}

bool CGlobalUnit::IsValidChasisAngle(const int iLeftAngle_Input, const int iRightAngle_Input, const int iAngleOffset_Input)
{
	double dwAngle_Left = (double)m_nChasisInfo.iAngle_LeftWheel / (double)10;
	double dwAngle_Right = (double)m_nChasisInfo.iAngle_RightWheel / (double)10;
	double dwAngle_Left_Offset = fabs(dwAngle_Left - (double)iLeftAngle_Input);
	double dwAngle_Right_Offset = fabs(dwAngle_Right - (double)iRightAngle_Input);

	if ((dwAngle_Left_Offset < iAngleOffset_Input) && (dwAngle_Right_Offset < iAngleOffset_Input))
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::Get_Chasis_ActualInfo()
{
	EnterCriticalSection(&m_nLock);

	char szRecvData[30] = { 0 };
	if (false == m_pHdlc_Chasis->Read(GT_Chasis_Device_Addr, szRecvData))
	{
		Write_Debug_Info("Get_Chasis_ActualInfo Fail", DIT_Error);
		LeaveCriticalSection(&m_nLock);
		return false;
	}
	m_nChasisInfo.iSpeed_LeftWheel = Translate16ToInt(szRecvData[2], szRecvData[3]);
	m_nChasisInfo.iAngle_LeftWheel = Translate16ToInt(szRecvData[4], szRecvData[5]);
	m_nChasisInfo.iSpeed_RightWheel = Translate16ToInt(szRecvData[6], szRecvData[7]);
	m_nChasisInfo.iAngle_RightWheel = Translate16ToInt(szRecvData[8], szRecvData[9]);
	m_nChasisInfo.iDis_LeftWheel = Translate16ToInt(szRecvData[10], szRecvData[11]);
	m_nChasisInfo.iDis_RightWheel = Translate16ToInt(szRecvData[12], szRecvData[13]);
	m_nChasisInfo.iHeight_LiftPlat = Translate16ToInt(szRecvData[14], szRecvData[15]);

	LeaveCriticalSection(&m_nLock);
	return true;
}

bool CGlobalUnit::Set_Chasis_RotatedAngle(const int iAngle_Left_Input, const int iAngle_Right_Input)
{
	int iAngle_Left = iAngle_Left_Input * 1;
	int iAngle_Right = iAngle_Right_Input * 1;
// 	memset(m_bzChasisCmd, 0, sizeof(m_bzChasisCmd));
	m_bzChasisCmd[0] = (byte)(0x00);
	m_bzChasisCmd[1] = (byte)(0x00);
	m_bzChasisCmd[4] = (byte)(0x00);
	m_bzChasisCmd[5] = (byte)(0x00);
	m_bzChasisCmd[8] = (byte)(0x00);
	
	m_bzChasisCmd[2] = (byte)((0xFF00 & iAngle_Left) >> 8);
	m_bzChasisCmd[3] = (byte)(0xFF & iAngle_Left);
	m_bzChasisCmd[6] = (byte)((0xFF00 & iAngle_Right) >> 8);
	m_bzChasisCmd[7] = (byte)(0xFF & iAngle_Right);
	if (false == m_pHdlc_Chasis->Write(m_bzChasisCmd, GT_Chasis_Device_Addr, sizeof(m_bzChasisCmd)))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_MoveSpeed(const int iSpeed_Left, const int iSpeed_Right)
{
	int iSpeed_Left_temp = iSpeed_Left;
	int iSpeed_Right_temp = iSpeed_Right;

	if (iSpeed_Left_temp < 0)
	{
		iSpeed_Left_temp = 32767 - iSpeed_Left_temp;
	}
	if (iSpeed_Right_temp < 0)
	{
		iSpeed_Right_temp = 32767 - iSpeed_Right_temp;
	}

	//速度赋值
	m_bzChasisCmd[0] = (byte)((0xFF00 & iSpeed_Left_temp) >> 8);
	m_bzChasisCmd[1] = (byte)(0xFF & iSpeed_Left_temp);
	m_bzChasisCmd[4] = (byte)((0xFF00 & iSpeed_Right_temp) >> 8);
	m_bzChasisCmd[5] = (byte)(0xFF & iSpeed_Right_temp);
	if (false == m_pHdlc_Chasis->Write(m_bzChasisCmd, GT_Chasis_Device_Addr, sizeof(m_bzChasisCmd)))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_LinkRod_MoveUpOrDown(const int iRodMotor_Speed)
{
	int iSpeed_temp = iRodMotor_Speed;
	if (iSpeed_temp < 0)
	{
		iSpeed_temp = 127 + abs(iSpeed_temp);
	}

	m_bzChasisCmd[8] = (byte)(0xFF & iSpeed_temp);
	if (false == m_pHdlc_Chasis->Write(m_bzChasisCmd, GT_Chasis_Device_Addr, sizeof(m_bzChasisCmd)))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Electromagnet_Enable(bool bIsEnable)
{
	//修改方向，By qiufan, 2017/0628/1500
	if (bIsEnable)
	{
		m_bzChasisCmd[11] = (byte)0;
	}
	else
	{
		m_bzChasisCmd[11] = (byte)0xFF;
	}
	if (false == m_pHdlc_Chasis->Write(m_bzChasisCmd, GT_Chasis_Device_Addr, sizeof(m_bzChasisCmd)))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Normal_Forward(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 90;
	int iAngle_Right = 90;
	//当不满足当前目标角度时，先调整角度，否则直接下发运动指令
	if (!IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Normal_Forward --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		if (false == Set_Chasis_MoveSpeed(iSpeed_Left_Input, iSpeed_Right_Input))
		{
			Write_Debug_Info("Normal_Forward --- Move --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Normal_Backoff(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 90;
	int iAngle_Right = 90;
	//当不满足当前目标角度时，先调整角度，否则直接下发运动指令
	if (!IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Normal_Backoff --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		if (false == Set_Chasis_MoveSpeed(-iSpeed_Left_Input, -iSpeed_Right_Input))
		{
			Write_Debug_Info("Normal_Backoff --- Move --- Fail", DIT_Error);
			return false;
		}
	}

	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Normal_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 180;
	int iAngle_Right = 180;

	//当不满足当前目标角度时，先调整角度，否则直接下发运动指令
	if (!IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Normal_Left --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		if (false == Set_Chasis_MoveSpeed(iSpeed_Left_Input, iSpeed_Right_Input))
		{
			Write_Debug_Info("Normal_Left --- Move --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Normal_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 180;
	int iAngle_Right = 180;

	//当不满足当前目标角度时，先调整角度，否则直接下发运动指令
	if (false == IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Normal_Right --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		if (false == Set_Chasis_MoveSpeed(-iSpeed_Left_Input, -iSpeed_Right_Input))
		{
			Write_Debug_Info("Normal_Right --- Move --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Rotate_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 180;
	int iAngle_Right = 180;
	if (false == IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Rotate_Right --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		int iSpeed_Left = -iSpeed_Left_Input;
		int iSpeed_Right = iSpeed_Right_Input;
		if (false == Set_Chasis_MoveSpeed(iSpeed_Left, iSpeed_Right))
		{
			Write_Debug_Info("Rotate_Right --- Move --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Rotate_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input)
{
	int iAngle_Left = 180;
	int iAngle_Right = 180;
	if (false == IsValidChasisAngle(iAngle_Left, iAngle_Right, 2))
	{
		if (false == Set_Chasis_RotatedAngle(iAngle_Left, iAngle_Right))
		{
			Write_Debug_Info("Rotate_Left --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	else
	{
		int iSpeed_Left = iSpeed_Left_Input;
		int iSpeed_Right = -iSpeed_Right_Input;
		if (false == Set_Chasis_MoveSpeed(iSpeed_Left, iSpeed_Right))
		{
			Write_Debug_Info("Rotate_Left --- Move --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Move_Rotate()
{
	if (false == IsValidChasisAngle(m_iChasis_Left_TargetAngle, m_iChasis_Right_TargetAngle, 2))
	{
		if (false == Set_Chasis_RotatedAngle(m_iChasis_Left_TargetAngle, m_iChasis_Right_TargetAngle))
		{
			Write_Debug_Info("Move_Rotate --- Rotate angle --- Fail", DIT_Error);
			return false;
		}
	}
	return true;
}

bool CGlobalUnit::Set_Chasis_Stop()
{
	if (false == Set_Chasis_MoveSpeed(0, 0))
	{
		return false;
	}
	if (false == Set_Chasis_LinkRod_MoveUpOrDown(0))
	{
		return false;
	}
	if (false == Set_Chasis_Electromagnet_Enable(false))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::IsLiftPlatArrivePos(const int iPos_Actual, const int iPos_Target)
{
	if (abs(iPos_Target - iPos_Actual) < 10)
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::Get_LiftPlat_ActualInfo()
{
	EnterCriticalSection(&m_nLock);

	long szRecvData[100] = { 0 };
	if (false == m_pLiftPlatNet->ReadData(szRecvData))
	{
		LeaveCriticalSection(&m_nLock);
		return false;
	}
	m_nLiftPlat_MotorInfo.iModbus_enable = szRecvData[0];
	m_nLiftPlat_MotorInfo.iEN_enable = szRecvData[1];

	if (szRecvData[2] > 32767)
	{
		m_nLiftPlat_MotorInfo.iTarget_speed = szRecvData[2] - 65536;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iTarget_speed = szRecvData[2];
	}

	m_nLiftPlat_MotorInfo.iAcceleration = szRecvData[3];
	m_nLiftPlat_MotorInfo.iSpeed_start = szRecvData[4];
	m_nLiftPlat_MotorInfo.iSpeed_kp = szRecvData[5];
	m_nLiftPlat_MotorInfo.iSpeed_ki = szRecvData[6];
	m_nLiftPlat_MotorInfo.iPosition_kp = szRecvData[7];
	m_nLiftPlat_MotorInfo.iSpeed_feedforward = szRecvData[8];
	m_nLiftPlat_MotorInfo.iDIR_polarity = szRecvData[9];
	m_nLiftPlat_MotorInfo.iE_Gear_numerator = szRecvData[10];
	m_nLiftPlat_MotorInfo.iE_Gear_denominator = szRecvData[11];

	if (szRecvData[13] > 32767)
	{
		m_nLiftPlat_MotorInfo.iPU = (szRecvData[13] - 32768) * 65536 + szRecvData[12];
		m_nLiftPlat_MotorInfo.iPU = -(0x7FFFFFFF - m_nLiftPlat_MotorInfo.iPU + 1);
	}
	else
	{
		m_nLiftPlat_MotorInfo.iPU = szRecvData[13] * 65536 + szRecvData[12];
	}

	m_nLiftPlat_MotorInfo.iWaring_code = 8;
	switch (szRecvData[14])
	{
	case 0:
		m_nLiftPlat_MotorInfo.iWaring_code = 0;
		break;
	case 0x10:
		m_nLiftPlat_MotorInfo.iWaring_code = 1;
		break;
	case 0x20:
		m_nLiftPlat_MotorInfo.iWaring_code = 2;
		break;
	case 0x11:
		m_nLiftPlat_MotorInfo.iWaring_code = 3;
		break;
	case 0x12:
		m_nLiftPlat_MotorInfo.iWaring_code = 4;
		break;
	case 0x13:
		m_nLiftPlat_MotorInfo.iWaring_code = 5;
		break;
	case 0x14:
		m_nLiftPlat_MotorInfo.iWaring_code = 6;
		break;
	case 0x15:
		m_nLiftPlat_MotorInfo.iWaring_code = 7;
		break;
	default:
		break;
	}

	if (szRecvData[15] > 32767)
	{
		m_nLiftPlat_MotorInfo.iSystem_DC_current = szRecvData[15] - 65536;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iSystem_DC_current = szRecvData[15];
	}

	if (szRecvData[16] > 32767)
	{
		m_nLiftPlat_MotorInfo.iSpeed_actual = szRecvData[16] - 65536;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iSpeed_actual = szRecvData[16];
	}

	if (szRecvData[17] > 32767)
	{
		m_nLiftPlat_MotorInfo.iSystem_voltage = szRecvData[17] - 65536;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iSystem_voltage = szRecvData[17];
	}

	if (szRecvData[18] > 32760)
	{
		m_nLiftPlat_MotorInfo.iSystem_temperature = 32760;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iSystem_temperature = szRecvData[18];
	}

	if (szRecvData[19] > 32767)
	{
		m_nLiftPlat_MotorInfo.iSystem_pwm = szRecvData[19] - 65536;
	}
	else
	{
		m_nLiftPlat_MotorInfo.iSystem_pwm = szRecvData[19];
	}

	m_nLiftPlat_MotorInfo.iModbus_save_flag = szRecvData[20];

	if (szRecvData[23] > 32767)
	{
		m_nLiftPlat_MotorInfo.iPU_all = (szRecvData[23] - 32768) * 65536 + szRecvData[22];
		m_nLiftPlat_MotorInfo.iPU_all = -(0x7FFFFFFF - g_pGlobalUnit->m_nLiftPlat_MotorInfo.iPU_all + 1);
	}
	else
	{
		m_nLiftPlat_MotorInfo.iPU_all = szRecvData[23] * 65536 + szRecvData[22];
	}

	m_nLiftPlat_MotorInfo.iSpeed_filter = szRecvData[24];
	m_nLiftPlat_MotorInfo.iPosition_feedforward = szRecvData[25];

	LeaveCriticalSection(&m_nLock);
	return true;
}

bool CGlobalUnit::Set_LiftPlat_MotorEnable(bool bEnable)
{
	int iCmd = -1;
	if (true == bEnable)
	{
		iCmd = 1;
	}
	else
	{
		iCmd = 0;
	}
	QString strCmd = QString::number(iCmd);
	if (false == m_pLiftPlatNet->WriteData(0, strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_LiftPlat_Move_UpOrDown(GT_LiftPlat_Status iStatus)
{
	int iSpeed = 0;
	if (iStatus == LPS_Up)
	{
		iSpeed = m_iLiftPlat_TargetSpeed;
	}
	else if (iStatus == LPS_Down)
	{
		iSpeed = -m_iLiftPlat_TargetSpeed;
	}
	else if (iStatus == LPS_Stop)
	{
		iSpeed = 0;
	}

	QString strCmd = QString::number(iSpeed);
	for (int iTry = 0; iTry < 3; iTry++)
	{
		if (m_pLiftPlatNet->WriteData(2, strCmd))
		{
			return true;
		}
	}
	return false;
}

bool CGlobalUnit::Set_LiftPlat_MoveTo_TargetPos(const int iPos_Begin, const int iPos_End)
{
	if (iPos_End - iPos_Begin > 10)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_End - iPos_Begin < -10)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
	else
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
	}
	return true;
}

QString CGlobalUnit::GetRobotMoveCommend(GT_URRobotArm_Status iStatus, int iDirection)
{
	QString strCmd = "";
	double dwData_X, dwData_Y, dwData_Z, dwData_U, dwData_V, dwData_W;

	bool bRotated = (iStatus > UR_Space_W) ? true : false;
	if (true == bRotated)
	{
		dwData_X = m_nRobot_Actual_JointAngle.dwX * (GT_PI / 180);
		dwData_Y = m_nRobot_Actual_JointAngle.dwY * (GT_PI / 180);
		dwData_Z = m_nRobot_Actual_JointAngle.dwZ * (GT_PI / 180);
		dwData_U = m_nRobot_Actual_JointAngle.dwU * (GT_PI / 180);
		dwData_V = m_nRobot_Actual_JointAngle.dwV * (GT_PI / 180);
		dwData_W = m_nRobot_Actual_JointAngle.dwW * (GT_PI / 180);
	}
	else
	{
		GT_RobotArm_Pose pose_SpacePos = Translate_Normal_To_Robot_CoordinateSystem(m_nRobot_Actual_SpacePos);
		dwData_X = pose_SpacePos.dwX / 1000;
		dwData_Y = pose_SpacePos.dwY / 1000;
		dwData_Z = pose_SpacePos.dwZ / 1000;
		dwData_U = pose_SpacePos.dwU;
		dwData_V = pose_SpacePos.dwV;
		dwData_W = pose_SpacePos.dwW;
	}

	switch (iStatus)
	{
	case UR_Space_X:
		dwData_X = (dwData_X + 10) * iDirection;
		break;
	case UR_Space_Y:
		dwData_Y = (dwData_Y + 10) * iDirection;
		break;
	case UR_Space_Z:
		dwData_Z = (dwData_Z + 10) * iDirection;
		break;
	case UR_Space_U:
		break;
	case UR_Space_V:
		break;
	case UR_Space_W:
		break;
	case UR_Joint_X:
		dwData_X = (dwData_X + 100) * iDirection;
		break;
	case UR_Joint_Y:
		dwData_Y = (dwData_Y + 100) * iDirection;
		break;
	case UR_Joint_Z:
		dwData_Z = (dwData_Z + 100) * iDirection;
		break;
	case UR_Joint_U:
		dwData_U = (dwData_U + 100) * iDirection;
		break;
	case UR_Joint_V:
		dwData_V = (dwData_V + 100) * iDirection;
		break;
	case UR_Joint_W:
		dwData_W = (dwData_W + 100) * iDirection;
		break;
	default:
		break;
	}

	QString strData_X = QString::number(dwData_X);
	QString strData_Y = QString::number(dwData_Y);
	QString strData_Z = QString::number(dwData_Z);
	QString strData_U = QString::number(dwData_U);
	QString strData_V = QString::number(dwData_V);
	QString strData_W = QString::number(dwData_W);
	QString strAccelerationRate = QString::number(m_dRobot_AccelerationRate);
	QString strSpeedRate = QString::number(m_dRobot_SpeedRate);
	if (true == bRotated)
	{
		strCmd = "movej([" + strData_X + "," + strData_Y + "," + strData_Z + "," + strData_U + "," + strData_V + "," + strData_W + "], a = " + strAccelerationRate + ", v = " + strSpeedRate + ")";
	}
	else
	{
		strCmd = "movel(p[" + strData_X + "," + strData_Y + "," + strData_Z + "," + strData_U + "," + strData_V + "," + strData_W + "], a = " + strAccelerationRate + ", v = " + strSpeedRate + ")";
	}

	return strCmd;
}

bool CGlobalUnit::IsRobotArrivePos(GT_RobotArm_Pose rInfo_Input)
{
	if (fabs(rInfo_Input.dwX - m_nRobot_Actual_SpacePos.dwX) < 0.3 &&
		fabs(rInfo_Input.dwY - m_nRobot_Actual_SpacePos.dwY) < 0.3 &&
		fabs(rInfo_Input.dwZ - m_nRobot_Actual_SpacePos.dwZ) < 0.3 &&
		fabs(rInfo_Input.dwU - m_nRobot_Actual_SpacePos.dwU) < 0.006 &&
		fabs(rInfo_Input.dwV - m_nRobot_Actual_SpacePos.dwV) < 0.006 &&
		fabs(rInfo_Input.dwW - m_nRobot_Actual_SpacePos.dwW) < 0.006)
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsRobotArrivePos(const QGTPoint3D ptInput)
{
	if (fabs(ptInput.x() - m_nRobot_Actual_SpacePos.dwX) < 0.3 &&
		fabs(ptInput.y() - m_nRobot_Actual_SpacePos.dwY) < 0.3 &&
		fabs(ptInput.z() - m_nRobot_Actual_SpacePos.dwZ) < 0.3)
	{
		return true;
	}
	return false;
}

bool CGlobalUnit::IsRobotArriveAngle(GT_RobotArm_Pose rInfo_Input)
{
	if (fabs(rInfo_Input.dwX - m_nRobot_Actual_JointAngle.dwX) < 0.3 &&
		fabs(rInfo_Input.dwY - m_nRobot_Actual_JointAngle.dwY) < 0.3 &&
		fabs(rInfo_Input.dwZ - m_nRobot_Actual_JointAngle.dwZ) < 0.3 &&
		fabs(rInfo_Input.dwU - m_nRobot_Actual_JointAngle.dwU) < 0.3 &&
		fabs(rInfo_Input.dwW - m_nRobot_Actual_JointAngle.dwW) < 0.3)
	{
		if ((fabs(rInfo_Input.dwV - m_nRobot_Actual_JointAngle.dwV) < 0.3) || (fabs(rInfo_Input.dwV + 360 - m_nRobot_Actual_JointAngle.dwV) < 0.3))
		{
			return true;
		}
	}
	return false;
}

void CGlobalUnit::Get_Robot_ActualInfo()
{
	EnterCriticalSection(&m_nLock);

	double dwTime_Begin = ::GetTickCount();

	double dzRobotSpacePos[6] = { 0 };
	double dzRobotJointAngle[6] = { 0 };
	double dzRobotSpaceSpeed[6] = { 0 };
	double dzRobotJointSpeed[6] = { 0 };
	double dzRobotJointCurrent[6] = { 0 };
	double dzRobotJointTemperature[6] = { 0 };

	m_pRobotNet->GetSpacePositions(dzRobotSpacePos);
	m_pRobotNet->GetJointAngle(dzRobotJointAngle);

// 	m_pRobotNet->GetSpaceSpeed(dzRobotSpaceSpeed);
// 	m_pRobotNet->GetJointSpeed(dzRobotJointSpeed);
// 	m_pRobotNet->GetJointCurrent(dzRobotJointCurrent);
// 	m_pRobotNet->GetJointTemperature(dzRobotJointTemperature);

	//获取机械手空间位置坐标值
	GT_RobotArm_Pose pose_SpacePos;
	pose_SpacePos.dwX = dzRobotSpacePos[0];
	pose_SpacePos.dwY = dzRobotSpacePos[1];
	pose_SpacePos.dwZ = dzRobotSpacePos[2];
	pose_SpacePos.dwU = dzRobotSpacePos[3];
	pose_SpacePos.dwV = dzRobotSpacePos[4];
	pose_SpacePos.dwW = dzRobotSpacePos[5];

	m_nRobot_Actual_SpacePos = Translate_Robot_To_Normal_CoordinateSystem(pose_SpacePos);

	//获取机械手关节角度
	m_nRobot_Actual_JointAngle.dwX = dzRobotJointAngle[0];
	m_nRobot_Actual_JointAngle.dwY = dzRobotJointAngle[1];
	m_nRobot_Actual_JointAngle.dwZ = dzRobotJointAngle[2];
	m_nRobot_Actual_JointAngle.dwU = dzRobotJointAngle[3];
	m_nRobot_Actual_JointAngle.dwV = dzRobotJointAngle[4];
	m_nRobot_Actual_JointAngle.dwW = dzRobotJointAngle[5];

	double dwTime_End = ::GetTickCount();
	double dwTime = dwTime_End - dwTime_Begin;
	if (dwTime > 1000)
	{
		QString strInfo = "Robot read info use time " + QString::number(dwTime) + " ms";
		Write_Debug_Info(strInfo, DIT_Error);
	}

// 	Get_Robot_TcpForce();

	LeaveCriticalSection(&m_nLock);
}

bool CGlobalUnit::Set_Robot_Move_Normal(GT_URRobotArm_Status iStatus, int iDirection)
{
	QString strCmd = GetRobotMoveCommend(iStatus, iDirection);
	if (false == m_pRobotNet->Write(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_Stop()
{
	QString strCmd = "stopl(1)";
	if (false == m_pRobotNet->Write(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_MoveTo_Target_SpacePos(GT_RobotArm_Pose rInfo_Input)
{
	GT_RobotArm_Pose pose_Input = Translate_Normal_To_Robot_CoordinateSystem(rInfo_Input);
	QString strData_X = QString::number(pose_Input.dwX / 1000);
	QString strData_Y = QString::number(pose_Input.dwY / 1000);
	QString strData_Z = QString::number(pose_Input.dwZ / 1000);
	QString strData_U = QString::number(pose_Input.dwU);
	QString strData_V = QString::number(pose_Input.dwV);
	QString strData_W = QString::number(pose_Input.dwW);
	QString strAccelerationRate = QString::number(m_dRobot_AccelerationRate);
	QString strSpeedRate = QString::number(m_dRobot_SpeedRate);

	QString strCmd = "movel(p[" + strData_X + "," + strData_Y + "," + strData_Z + "," + strData_U + "," + strData_V + "," + strData_W + "], a = " + strAccelerationRate + ", v = " + strSpeedRate + ")";
	if (false == m_pRobotNet->Write(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_MoveTo_Target_SpacePos(const QGTPoint3D ptInput)
{
	QGTPoint3D pt_Input = Translate_Normal_To_Robot_CoordinateSystem(ptInput);
	QString strData_X = QString::number(pt_Input.x() / 1000);
	QString strData_Y = QString::number(pt_Input.y() / 1000);
	QString strData_Z = QString::number(pt_Input.z() / 1000);
	QString strData_U = QString::number(m_nRobot_Actual_SpacePos.dwU);
	QString strData_V = QString::number(m_nRobot_Actual_SpacePos.dwV);
	QString strData_W = QString::number(m_nRobot_Actual_SpacePos.dwW);
	QString strAccelerationRate = QString::number(m_dRobot_AccelerationRate);
	QString strSpeedRate = QString::number(m_dRobot_SpeedRate);

	QString strCmd = "movel(p[" + strData_X + "," + strData_Y + "," + strData_Z + "," + strData_U + "," + strData_V + "," + strData_W + "], a = " + strAccelerationRate + ", v = " + strSpeedRate + ")";
	if (false == m_pRobotNet->Write(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_MoveTo_Target_JointAngle(GT_RobotArm_Pose rInfo_Input)
{
	QString strData_X = QString::number(rInfo_Input.dwX * (GT_PI / 180));
	QString strData_Y = QString::number(rInfo_Input.dwY * (GT_PI / 180));
	QString strData_Z = QString::number(rInfo_Input.dwZ * (GT_PI / 180));
	QString strData_U = QString::number(rInfo_Input.dwU * (GT_PI / 180));
	QString strData_V = QString::number(rInfo_Input.dwV * (GT_PI / 180));
	QString strData_W = QString::number(rInfo_Input.dwW * (GT_PI / 180));
	QString strAccelerationRate = QString::number(m_dRobot_AccelerationRate);
	QString strSpeedRate = QString::number(m_dRobot_SpeedRate);

	QString strCmd = "movej([" + strData_X + "," + strData_Y + "," + strData_Z + "," + strData_U + "," + strData_V + "," + strData_W + "], a = " + strAccelerationRate + ", v = " + strSpeedRate + ")";
	if (false == m_pRobotNet->Write(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_Load_Program()
{
	QString strCmd = "load<GetActualTcpForce.urp>";
	if (false == m_pRobotNet->Write_Other(strCmd))
	{
		return false;
	}
	strCmd = "play";
	if (false == m_pRobotNet->Write_Other(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_Start_Program()
{
	QString strCmd = "1";
	if (false == m_pRobotNet->Write_Register(strCmd))
	{
		Write_Debug_Info("Start Program Fail", DIT_Error);
		return false;
	}
	return true;
}

bool CGlobalUnit::Set_Robot_Stop_Program()
{
	QString strCmd = "0";
	if (false == m_pRobotNet->Write_Register(strCmd))
	{
		Write_Debug_Info("Stop Program Fail", DIT_Error);
		return false;
	}
// 	QString strCmd = "stop";
// 	if (false == m_pRobotNet->Write_Other(strCmd))
// 	{
// 		return false;
// 	}
	return true;
}

bool CGlobalUnit::Set_Robot_uoload_Prog()
{
	QString strCmd;
	char buf[128];
	strCmd = "def driverProg():\n";

	sprintf(buf, "\tMULT_jointstate = %i\n", 1000000);
	strCmd += buf;

	strCmd += "\tSERVO_IDLE = 0\n";
	strCmd += "\tSERVO_RUNNING = 1\n";
	strCmd += "\tcmd_servo_state = SERVO_IDLE\n";
	strCmd += "\tcmd_servo_q = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]\n";
	strCmd += "\tdef set_servo_setpoint(q):\n";
	strCmd += "\t\tenter_critical\n";
	strCmd += "\t\tcmd_servo_state = SERVO_RUNNING\n";
	strCmd += "\t\tcmd_servo_q = q\n";
	strCmd += "\t\texit_critical\n";
	strCmd += "\tend\n";
	strCmd += "\tthread servoThread():\n";
	strCmd += "\t\tstate = SERVO_IDLE\n";
	strCmd += "\t\twhile True:\n";
	strCmd += "\t\t\tenter_critical\n";
	strCmd += "\t\t\tq = cmd_servo_q\n";
	strCmd += "\t\t\tdo_brake = False\n";
	strCmd += "\t\t\tif (state == SERVO_RUNNING) and ";
	strCmd += "(cmd_servo_state == SERVO_IDLE):\n";
	strCmd += "\t\t\t\tdo_brake = True\n";
	strCmd += "\t\t\tend\n";
	strCmd += "\t\t\tstate = cmd_servo_state\n";
	strCmd += "\t\t\tcmd_servo_state = SERVO_IDLE\n";
	strCmd += "\t\t\texit_critical\n";
	strCmd += "\t\t\tif do_brake:\n";
	strCmd += "\t\t\t\tstopj(1.0)\n";
	strCmd += "\t\t\t\tsync()\n";
	strCmd += "\t\t\telif state == SERVO_RUNNING:\n";

	sprintf(buf, "\t\t\t\tservoj(q, t=%.4f, lookahead_time=0.03)\n", 0.008);

	strCmd += buf;

	strCmd += "\t\t\telse:\n";
	strCmd += "\t\t\t\tsync()\n";
	strCmd += "\t\t\tend\n";
	strCmd += "\t\tend\n";
	strCmd += "\tend\n";

	QString strLocalIp = "192.168.0.7";
	int strLoaclPort = 50007;

	sprintf(buf, "\tsocket_open(\"%s\", %i)\n", strLocalIp.toStdString(), strLoaclPort);
	strCmd += buf;

	strCmd += "\tthread_servo = run servoThread()\n";
	strCmd += "\tkeepalive = 1\n";
	strCmd += "\twhile keepalive > 0:\n";
	strCmd += "\t\tparams_mult = socket_read_binary_integer(6+1)\n";
	strCmd += "\t\tif params_mult[0] > 0:\n";
	strCmd += "\t\t\tq = [params_mult[1] / MULT_jointstate, ";
	strCmd += "params_mult[2] / MULT_jointstate, ";
	strCmd += "params_mult[3] / MULT_jointstate, ";
	strCmd += "params_mult[4] / MULT_jointstate, ";
	strCmd += "params_mult[5] / MULT_jointstate, ";
	strCmd += "params_mult[6] / MULT_jointstate]\n";
	strCmd += "\t\t\tkeepalive = params_mult[7]\n";
	strCmd += "\t\t\tset_servo_setpoint(q)\n";
	strCmd += "\t\tend\n";
	strCmd += "\tend\n";
	strCmd += "\tsleep(.1)\n";
	strCmd += "\tsocket_close()\n";
	strCmd += "\tkill thread_servo\n";
	strCmd += "end\n";

	if (false == m_pRobotNet->addCommandToQueue(strCmd))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Get_Robot_TcpForce()
{
	int iLen = 0;
	char szBuffer[2048 * 4] = { 0 };
	if (false == m_pRobot_Pressure_Net->ReadPort(iLen, szBuffer))
	{
		return false;
	}

	QString strBuffer = QString::fromLocal8Bit(szBuffer);

	int iPos_Begin = strBuffer.indexOf("CH0:");
	int iPos_End = strBuffer.indexOf("\r\n");
	if ((-1 == iPos_Begin) || (-1 == iPos_End))
	{
		return false;
	}

	QString strValue = strBuffer.mid(iPos_Begin, iPos_End - iPos_Begin);
	if ((-1 == strValue.indexOf("CH1:")) || (-1 == strValue.indexOf("CH2:")) ||
		(-1 == strValue.indexOf("CH3:")))
	{
		return false;
	}

	double dwForce_1(0.0), dwForce_2(0.0), dwForce_3(0.0), dwForce_4(0.0);
	if (false == Parse_Robot_Pressure_Data("CH0:", "V", strValue, dwForce_1))
	{
		return false;
	}
	if (false == Parse_Robot_Pressure_Data("CH1:", "V", strValue, dwForce_2))
	{
		return false;
	}
	if (false == Parse_Robot_Pressure_Data("CH2:", "V", strValue, dwForce_3))
	{
		return false;
	}
	if (false == Parse_Robot_Pressure_Data("CH3:", "V", strValue, dwForce_4))
	{
		return false;
	}

	m_nRobot_Actual_TcpForce.iForce_1 = dwForce_1 * 1000;
	m_nRobot_Actual_TcpForce.iForce_2 = dwForce_2 * 1000;
	m_nRobot_Actual_TcpForce.iForce_3 = dwForce_3 * 1000;
	m_nRobot_Actual_TcpForce.iForce_4 = dwForce_4 * 1000;

	m_iRobot_Force_Count++;

	return true;
}

bool CGlobalUnit::Set_Ros_Work()
{
	byte bzRosCmd[9] = { 0 };
	if (m_nRos_Work_Pos_Status == RWPS_Idle)
	{
		bzRosCmd[0] = (byte)0x00;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_1)
	{
		bzRosCmd[0] = (byte)0x01;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_2)
	{
		bzRosCmd[0] = (byte)0x02;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_3)
	{
		bzRosCmd[0] = (byte)0x03;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_4)
	{
		bzRosCmd[0] = (byte)0x04;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_5)
	{
		bzRosCmd[0] = (byte)0x05;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_6)
	{
		bzRosCmd[0] = (byte)0x06;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_7)
	{
		bzRosCmd[0] = (byte)0x07;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_8)
	{
		bzRosCmd[0] = (byte)0x08;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Pos_9)
	{
		bzRosCmd[0] = (byte)0x09;
	}
	else if (m_nRos_Work_Pos_Status == RWPS_Working)
	{
		bzRosCmd[0] = (byte)0x64;
	}

	int iHor_WorkDis = m_dRos_SprayPaint_Hor_WorkDis;
	int iVer_WorkDis = m_dRos_SprayPaint_Ver_WorkDis;

	bzRosCmd[1] = (byte)((0xFF00 & iHor_WorkDis) >> 8);
	bzRosCmd[2] = (byte)(0xFF & iHor_WorkDis);
	bzRosCmd[3] = (byte)((0xFF00 & iVer_WorkDis) >> 8);
	bzRosCmd[4] = (byte)(0xFF & iVer_WorkDis);
	bzRosCmd[5] = (byte)0x00;
	bzRosCmd[6] = (byte)0x00;
	bzRosCmd[7] = (byte)0x00;
	bzRosCmd[8] = (byte)0x00;

	if (false == m_pHdlc_Ros->Write(bzRosCmd, GT_Chasis_Device_Addr, sizeof(bzRosCmd)))
	{
		return false;
	}
	return true;
}

bool CGlobalUnit::Get_Ros_Return_Info()
{
	EnterCriticalSection(&m_nLock);

	char szRecvData[10] = { 0 };
	if (false == m_pHdlc_Ros->Read(GT_Chasis_Device_Addr, szRecvData))
	{
		Write_Debug_Info("Get_Ros_ReturnInfo Fail", DIT_Error);
		LeaveCriticalSection(&m_nLock);
		return false;
	}

	int iRos_Status = szRecvData[0];
	int iSpraygun_Status = szRecvData[1];

	if (iRos_Status == 0)
	{
		m_bIs_Ros_Work_Finished = true;
	}
	else
	{
		m_bIs_Ros_Work_Finished = false;
	}

	if (iSpraygun_Status == 1)
	{
		m_bIs_Ros_Need_Open_Spraygun = true;
		Write_Debug_Info("Open Spraygun", DIT_Normal);
	}
	else
	{
		m_bIs_Ros_Need_Open_Spraygun = false;
	}

	LeaveCriticalSection(&m_nLock);
	return true;
}

bool CGlobalUnit::Set_Lidar_Connect()
{
	try
	{
		if (false == m_pNet_Lidar->open(m_strLidar_Port.toStdString().c_str(), m_iLidar_Baudrate))
		{
			return false;
		}
	}
	catch (...)
	{
		Write_Debug_Info("Open lidar error", DIT_Error);
		return false;
	}

	m_iLidar_ScanFail_Count = 0;
	m_bIs_Lidar_Data_Valid = false;
	return true;
}

bool CGlobalUnit::Set_Lidar_DisConnect()
{
	try
	{
		m_pNet_Lidar->close();
	}
	catch (...)
	{
		Write_Debug_Info("Close lidar error", DIT_Error);
		return false;
	}

	m_iLidar_ScanFail_Count = 0;
	m_bIs_Lidar_Data_Valid = false;
	return true;
}

bool CGlobalUnit::Set_Lidar_Begin_Scan()
{
	try
	{
		if (false == m_pNet_Lidar->is_open())
		{
			return false;
		}

		if (false == m_pNet_Lidar->laser_on())
		{
			return false;
		}
	}
	catch (...)
	{
		Write_Debug_Info("Begin lidar scan error", DIT_Error);
		return false;
	}
	
	return true;
}

bool CGlobalUnit::Set_Lidar_End_Scan()
{
	try
	{
		if (false == m_pNet_Lidar->is_open())
		{
			return false;
		}

		m_pNet_Lidar->stop_measurement();

		if (false == m_pNet_Lidar->laser_off())
		{
			return false;
		}
	}
	catch (...)
	{
		Write_Debug_Info("End lidar scan error", DIT_Error);
		return false;
	}
	
	return true;
}

bool CGlobalUnit::Get_Lidar_ScanData()
{
	EnterCriticalSection(&m_nLock);//进入临界区

	if (NULL == m_pNet_Lidar)
	{
		return false;
	}

	try
	{
		if (false == m_pNet_Lidar->is_open())
		{
			Write_Debug_Info("Lidar is closed", DIT_Error);
			LeaveCriticalSection(&m_nLock);//离开临界区
			return false;
		}

		if (false == m_pNet_Lidar->set_scanning_parameter(m_pNet_Lidar->deg2step(-120), m_pNet_Lidar->deg2step(+180), 1))
		{
			m_str_LogInfo = QString::fromLocal8Bit("设置扫描参数错误 : ") + QString::fromUtf8(m_pNet_Lidar->what());
			Write_Debug_Info(m_str_LogInfo, DIT_Error);
			LeaveCriticalSection(&m_nLock);//离开临界区
			return false;
		}

		Sleep(5);

		if (false == m_pNet_Lidar->start_measurement(qrk::Urg_driver::Distance, 1, 0))
		{
			m_str_LogInfo = QString::fromLocal8Bit("启动扫描错误 : ") + QString::fromUtf8(m_pNet_Lidar->what());
			Write_Debug_Info(m_str_LogInfo, DIT_Error);
			LeaveCriticalSection(&m_nLock);//离开临界区
			return false;
		}

		Sleep(30);

		std::vector<long> dis_Array;
		long time_stamp = 0;

// 		if (false == m_pNet_Lidar->get_distance(dis_Array, &time_stamp))
// 		{
// 			m_str_LogInfo = QString::fromLocal8Bit("获取扫描结果错误 : ") + QString::fromUtf8(m_pNet_Lidar->what());
// 			Write_Debug_Info(m_str_LogInfo, DIT_Error);
// 			LeaveCriticalSection(&m_nLock);//离开临界区
// 			return false;
// 		}

		for (int iTry = 0; iTry < 3; iTry++)
		{
			if (false == m_pNet_Lidar->get_distance(dis_Array, &time_stamp))
			{
				if (iTry == 2)
				{
					m_str_LogInfo = QString::fromLocal8Bit("   获取扫描结果错误 : ") + QString::fromUtf8(m_pNet_Lidar->what());
					Write_Debug_Info(m_str_LogInfo, DIT_Error);
					Write_Log_Info(m_str_LogInfo);
					LeaveCriticalSection(&m_nLock);//离开临界区
					return false;
				}
				else
				{
					Sleep(30);
					continue;
				}
			}
			else
			{
				break;
			}
		}

		QList<GT_Lidar_Data> Scan_Data_Array_Temp;

		for (int i = 0; i < dis_Array.size(); i++)
		{
			double dwAngle_Scan = m_pNet_Lidar->index2rad(i);
			double dwDis_Scan = dis_Array.at(i);
			double dw_X = dwDis_Scan * std::sin(dwAngle_Scan);
			double dw_Y = dwDis_Scan * std::cos(dwAngle_Scan);

			QPointF pt_2D(dw_X, dw_Y);
			GT_Lidar_Data data_Temp;
			data_Temp.scan_Index = i;
			data_Temp.scan_Flag = 0;
			data_Temp.scan_Angle = dwAngle_Scan;
			data_Temp.scan_Distance = dwDis_Scan;
			data_Temp.scan_Point = pt_2D;
			Scan_Data_Array_Temp.push_back(data_Temp);

			double dwAngle = dwAngle_Scan * 180 / M_PI;
		}

		Get_Lidar_Scan_Line(Scan_Data_Array_Temp);

	}
	catch (...)
	{
		Write_Debug_Info("Get lidar data error", DIT_Error);
	}

	LeaveCriticalSection(&m_nLock);//离开临界区
	return true;
}

bool CGlobalUnit::Set_Laser_Measure()
{
	EnterCriticalSection(&m_nLock);//进入临界区

	QString strCmd = "F\r\n";
	if (!m_pNet_LaserMeasure->WritePort(strCmd.toStdString().c_str(), strCmd.length()))
	{
		Write_Debug_Info("Send cmd to laser measure error", DIT_Error);
		LeaveCriticalSection(&m_nLock);//离开临界区
		return false;
	}

	Sleep(380);

	int iReadLen = 0;
	char szReadBuf[8192] = { 0 };
	if (!m_pNet_LaserMeasure->ReadPort(iReadLen, szReadBuf))
	{
		Write_Debug_Info("Laser measure return error", DIT_Error);
		LeaveCriticalSection(&m_nLock);//离开临界区
		return false;
	}

	QString strRecv = QString::fromUtf8(szReadBuf);
	Write_Debug_Info(strRecv, DIT_Normal);

	int iPos_Begin = strRecv.indexOf("F: ");
	int iPos_End = strRecv.indexOf("m");

	if ((iPos_Begin != -1) && (iPos_End != -1) && (iPos_End > iPos_Begin + 3))
	{
		QString strDis = strRecv.mid(iPos_Begin + 3, iPos_End - iPos_Begin - 3);
		m_dLaserMeasure_Distance = strDis.toDouble() * 1000;
	}
	else
	{
		Write_Debug_Info("Laser measure return check error", DIT_Error);
		LeaveCriticalSection(&m_nLock);//离开临界区
		return false;
	}

	LeaveCriticalSection(&m_nLock);//离开临界区
	return true;
}

bool CGlobalUnit::Parse_Robot_Pressure_Data(const QString strReg_1, const QString strReg_2, QString &strOutput, double &dwOutput)
{
	int iPos_Begin = strOutput.indexOf(strReg_1);
	int iPos_End = strOutput.indexOf(strReg_2, iPos_Begin);

	if ((-1 == iPos_Begin) || (-1 == iPos_End))
	{
		return false;
	}

	QString strValue = strOutput.mid(iPos_Begin, iPos_End - iPos_Begin);
	strOutput = strOutput.mid(iPos_End, strOutput.length() - iPos_End);

	iPos_Begin = strValue.indexOf(strReg_1);
	iPos_End = strValue.length();

	QString strForce = strValue.mid(iPos_Begin + 4, iPos_End - iPos_Begin - 4);
	dwOutput = strForce.toDouble();

	return true;
}

bool CGlobalUnit::Is_JoyHandle_Valid()
{
	JOYCAPS jc;

	if (joyGetNumDevs() <= 0) //判断系统支持的手柄数目
	{
		return false;
	}

	if (JOYERR_NOERROR != joyGetDevCaps(JOYSTICKID1, &jc, sizeof(jc))) //判断ID1手柄是否可用
	{
		return false;
	}

	return true;
}

bool CGlobalUnit::Get_JoyHandle_ActualInfo()
{
	JOYINFOEX joy_Info;
	if (JOYERR_NOERROR != joyGetPosEx(JOYSTICKID1, &joy_Info))
	{
		return false;
	}

	m_nJoy_Btn_Last_Status = m_nJoy_Btn_Status;
	m_nJoy_Pov_Last_Status = m_nJoy_Pov_Status;

	m_nJoy_Btn_Status = Get_JoyButton_Status(joy_Info.dwButtons);
	m_nJoy_Pov_Status = Get_JoyPov_Status(joy_Info.dwPOV);

	return true;
}

void CGlobalUnit::Set_JoyHandle_Control()
{
	if (m_nJoy_Btn_Status == JBS_Idle)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (m_nJoy_Btn_Last_Status != JBS_Idle)
			{
				if (IsChasisConnect())
				{
					m_nChasis_NowType = CMT_Stop;
				}
				if (IsLiftPlatConnect())
				{
					m_nLiftPlat_NowStatus = LPS_Stop;
				}
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前未按下按键");
	}
	else if (m_nJoy_Btn_Status == JBS_A)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (m_nJoy_Pov_Status == JPS_Center)
			{
				if (IsChasisConnect())
				{
					m_nChasis_NowType = CMT_NORMAL_Backoff;
				}
			}
			else
			{
				if (IsChasisConnect())
				{
					m_nChasis_NowType = CMT_LinkRod_Up;
				}
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A 键");
	}
	else if (m_nJoy_Btn_Status == JBS_B)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (m_nJoy_Pov_Status == JPS_Center)
			{
				if (IsChasisConnect())
				{
					m_nChasis_NowType = CMT_NORMAL_Right;
				}
			}
			else
			{
				if (IsChasisConnect())
				{
					m_nChasis_NowType = CMT_LinkRod_Down;
				}
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 B 键");
	}
	else if (m_nJoy_Btn_Status == JBS_X)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsChasisConnect())
			{
				m_nChasis_NowType = CMT_NORMAL_Left;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 X 键");
	}
	else if (m_nJoy_Btn_Status == JBS_Y)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsChasisConnect())
			{
				m_nChasis_NowType = CMT_NORMAL_Forward;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 Y 键");
	}
	else if (m_nJoy_Btn_Status == JBS_LB)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsChasisConnect())
			{
				m_nChasis_NowType = CMT_ROTATE_Left;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 LB 键");
	}
	else if (m_nJoy_Btn_Status == JBS_RB)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsChasisConnect())
			{
				m_nChasis_NowType = CMT_ROTATE_Right;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 RB 键");
	}
	else if (m_nJoy_Btn_Status == JBS_LT)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsLiftPlatConnect())
			{
				m_nLiftPlat_NowStatus = LPS_Up;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 LT 键");
	}
	else if (m_nJoy_Btn_Status == JBS_RT)
	{
		if (m_bIs_JoyHandle_Control_Valid)
		{
			if (IsLiftPlatConnect())
			{
				m_nLiftPlat_NowStatus = LPS_Down;
			}
		}
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 RT 键");
	}
	else if (m_nJoy_Btn_Status == JBS_BACK)
	{
		m_bIs_JoyHandle_Control_Valid = false;
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 BACK 键");
	}
	else if (m_nJoy_Btn_Status == JBS_START)
	{
		m_bIs_JoyHandle_Control_Valid = true;
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 START 键");
	}
	else if (m_nJoy_Btn_Status == JBS_LOGO)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 LOGO 键");
	}
	else if (m_nJoy_Btn_Status == JBS_A_B)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A+B 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_A_X)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A+X 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_A_Y)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A+Y 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_B_X)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 B+X 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_B_Y)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 B+Y 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_A_B_X)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A+B+X 组合键");
	}
	else if (m_nJoy_Btn_Status == JBS_A_B_Y)
	{
		m_strJoy_Btn_Status = QString::fromLocal8Bit("游戏手柄当前按下 A+B+Y 组合键");
	}



	if (m_nJoy_Pov_Status == JPS_Center)
	{
		m_strJoy_Pov_Status = QString::fromLocal8Bit("游戏手柄当前 摇杆 回零");
	}
	else if (m_nJoy_Pov_Status == JPS_Forward)
	{
		m_strJoy_Pov_Status = QString::fromLocal8Bit("游戏手柄当前 摇杆 向前");
	}
	else if (m_nJoy_Pov_Status == JPS_Backward)
	{
		m_strJoy_Pov_Status = QString::fromLocal8Bit("游戏手柄当前 摇杆 向后");
	}
	else if (m_nJoy_Pov_Status == JPS_Leftward)
	{
		m_strJoy_Pov_Status = QString::fromLocal8Bit("游戏手柄当前 摇杆 向左");
	}
	else if (m_nJoy_Pov_Status == JPS_Rightward)
	{
		m_strJoy_Pov_Status = QString::fromLocal8Bit("游戏手柄当前 摇杆 向右");
	}
}

Joy_Button_Status CGlobalUnit::Get_JoyButton_Status(const int iPos)
{
	int kk = iPos;

	Joy_Button_Status status_Output = JBS_Idle;

	switch (iPos)
	{
	case 0:
		status_Output = JBS_Idle;
		break;
	case 1:
		status_Output = JBS_A;
		break;
	case 2:
		status_Output = JBS_B;
		break;
	case 8:
		status_Output = JBS_X;
		break;
	case 16:
		status_Output = JBS_Y;
		break;
	case 64:
		status_Output = JBS_LB;
		break;
	case 128:
		status_Output = JBS_RB;
		break;
	case 256:
		status_Output = JBS_LT;
		break;
	case 512:
		status_Output = JBS_RT;
		break;
	case 1024:
		status_Output = JBS_BACK;
		break;
	case 2048:
		status_Output = JBS_START;
		break;
	case 4096:
		status_Output = JBS_LOGO;
		break;
	case 3:
		status_Output = JBS_A_B;
		break;
	case 9:
		status_Output = JBS_A_X;
		break;
	case 17:
		status_Output = JBS_A_Y;
		break;
	case 10:
		status_Output = JBS_B_X;
		break;
	case 18:
		status_Output = JBS_B_Y;
		break;
	case 11:
		status_Output = JBS_A_B_X;
		break;
	case 19:
		status_Output = JBS_A_B_Y;
		break;
	default:
		break;
	}

	return status_Output;
}

Joy_POV_Status CGlobalUnit::Get_JoyPov_Status(const int iPov)
{
	Joy_POV_Status status_Output = JPS_Center;

	if (iPov == JOY_POVCENTERED)
	{
		status_Output = JPS_Center;
	}
	else if (iPov == JOY_POVFORWARD)
	{
		status_Output = JPS_Forward;
	}
	else if (iPov == JOY_POVFORWARD + 4500)
	{
		status_Output = JPS_Forward;
	}
	else if (iPov == JOY_POVBACKWARD)
	{
		status_Output = JPS_Backward;
	}
	else if (iPov == JOY_POVBACKWARD + 4500)
	{
		status_Output = JPS_Backward;
	}
	else if (iPov == JOY_POVLEFT)
	{
		status_Output = JPS_Leftward;
	}
	else if (iPov == JOY_POVLEFT + 4500)
	{
		status_Output = JPS_Leftward;
	}
	else if (iPov == JOY_POVRIGHT)
	{
		status_Output = JPS_Rightward;
	}
	else if (iPov == JOY_POVRIGHT + 4500)
	{
		status_Output = JPS_Rightward;
	}

	return status_Output;
}

void CGlobalUnit::Get_LineFollow_ActualInfo()
{
	EnterCriticalSection(&m_nLock);

	if (m_pFindLine->StartFindLine(m_dLineFollowSet_Calibration, m_iLineFollowSet_SearchThreshold, m_iLineFollowSet_MinBinaryThreshold, m_iLineFollowSet_MaxBinaryThreshold, \
		m_iLineFollowSet_MinContourArea, m_iLineFollowSet_MaxContourArea, m_nLineFollowSet_ResultImage, m_dLineFollowSet_ResultAngel, m_dLineFollowSet_ResultDis))
	{
		Write_Debug_Info("Find Laser Line Pass", DIT_Normal);
		m_bIs_LineFollowInfo_Valid = true;
	}
	else
	{
		Write_Debug_Info("Find Laser Line Fail", DIT_Error);
		m_bIs_LineFollowInfo_Valid = false;
	}

	LeaveCriticalSection(&m_nLock);
}

void CGlobalUnit::Set_LineFollow_RotateAdjust()
{
	//每次循环运动的初始化调整---自转调整
	int iSpeed_Left = m_iLineFollowSet_SpeedRate;
	int iSpeed_Right = m_iLineFollowSet_SpeedRate;
	if (m_dLineFollowSet_ResultAngel > m_dLineFollowSet_AngleRange)
	{
		Set_Chasis_Move_Rotate_Right(iSpeed_Left, iSpeed_Right);
		Write_Debug_Info("LineFollow --- RotateAdjust Right", DIT_Normal);
	}
	else if (m_dLineFollowSet_ResultAngel < -m_dLineFollowSet_AngleRange)
	{
		Set_Chasis_Move_Rotate_Left(iSpeed_Left, iSpeed_Right);
		Write_Debug_Info("LineFollow --- RotateAdjust Left", DIT_Normal);
	}
	else
	{
		Set_Chasis_Stop();
		LaserLine_Dis_Offset_Array.clear();
		m_nAutoRun_NowStatus = ARS_LineFollow_SideswayAdjust;
	}
}

void CGlobalUnit::Set_LineFollow_SideswayAdjust()
{
	//每次循环运动的初始化调整---平移调整
	int iSidesway_Speed = 0;
	if (m_iLineFollowSet_SpeedRate == 1)
	{
		iSidesway_Speed = 2;
	}
	else
	{
		iSidesway_Speed = m_iLineFollowSet_SpeedRate;
	}

	if (m_dLineFollowSet_ResultDis < -m_dLineFollowSet_DisRange)
	{
		Set_Chasis_Move_Normal_Forward(iSidesway_Speed, iSidesway_Speed);
		Write_Debug_Info("Auto Run --- Sidesway_Adjust Left", DIT_Normal);
	}
	else if (m_dLineFollowSet_ResultDis > m_dLineFollowSet_DisRange)
	{
		Set_Chasis_Move_Normal_Backoff(iSidesway_Speed, iSidesway_Speed);
		Write_Debug_Info("Auto Run --- Sidesway_Adjust Right", DIT_Normal);
	}
	else
	{
		Set_Chasis_Stop();
		LaserLine_Dis_Offset_Array.push_back(m_dLineFollowSet_ResultDis);
		if (LaserLine_Dis_Offset_Array.size() >= 10)
		{
			double Dis_Offset_All(0.00), Dis_Offset;
			for (int i = 0; i < LaserLine_Dis_Offset_Array.size(); i++)
			{
				Dis_Offset_All += LaserLine_Dis_Offset_Array.at(i);
			}
			Dis_Offset = Dis_Offset_All / LaserLine_Dis_Offset_Array.size();
			if ((Dis_Offset > -m_dLineFollowSet_DisRange) && (Dis_Offset < m_dLineFollowSet_DisRange))
			{
				m_iLineFollow_InitDis_LeftWheel = m_nChasisInfo.iDis_LeftWheel;
				m_iLineFollow_InitDis_RightWheel = m_nChasisInfo.iDis_RightWheel;

				m_nAutoRun_NowStatus = ARS_LineFollow_Forward;
			}
			else
			{
				LaserLine_Dis_Offset_Array.clear();
				m_nAutoRun_NowStatus = ARS_LineFollow_SideswayAdjust;
			}
		}
	}
}

void CGlobalUnit::Set_LineFollow_Forward()
{
	int iDis_Left = m_nChasisInfo.iDis_LeftWheel - m_iLineFollow_InitDis_LeftWheel;
	int iDis_Right = m_nChasisInfo.iDis_RightWheel - m_iLineFollow_InitDis_RightWheel;

	int iTarget_Dis = 0;
	if (m_iDemoPlanSet_Index == 4)
	{
		iTarget_Dis = m_dSprayPaint_Dis_MovedBy_Chasis * m_iSprayPaint_Current_Count_MovedBy_Chasis / 10;
	}
	else
	{
		iTarget_Dis = m_iLineFollowSet_TargetDis;
	}

	m_str_LogInfo = QString::fromLocal8Bit("循线运动目标距离 : ") + QString::number(iTarget_Dis);
	Write_Debug_Info(m_str_LogInfo, DIT_Normal);

	m_str_LogInfo = QString::fromLocal8Bit("循线运动左轮行程 : ") + QString::number(iDis_Left);
	Write_Debug_Info(m_str_LogInfo, DIT_Normal);

	m_str_LogInfo = QString::fromLocal8Bit("循线运动右轮行程 : ") + QString::number(iDis_Right);
	Write_Debug_Info(m_str_LogInfo, DIT_Normal);


	if ((iDis_Left >= iTarget_Dis) || (iDis_Right >= iTarget_Dis))
	{
		Set_Chasis_Stop();
		if (m_iDemoPlanSet_Index == 0)
		{
			m_nAutoRun_NowStatus = ARS_Structure_Test;
		}
		else if (m_iDemoPlanSet_Index == 1)
		{
			m_nAutoRun_NowStatus = ARS_Structure_Test;
		}
		else if (m_iDemoPlanSet_Index == 2)
		{
			m_nAutoRun_NowStatus = ARS_Structure_Test;
		}
		else if (m_iDemoPlanSet_Index == 3)
		{
			m_nAutoRun_NowStatus = ARS_Structure_Test;
		}
		else if (m_iDemoPlanSet_Index == 4)
		{
			if ((m_bIs_SprayPaint_VerInsideCorner_Enable == true) && (m_iSprayPaint_Current_Count_MovedBy_Chasis == 0))
			{
				m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_A;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_SprayPaint_LiftPlat_Ready;
			}
		}
	}
	else
	{
		double dwRange_Angle = m_dLineFollowSet_AngleRange * 20;
		if (m_dLineFollowSet_ResultAngel > dwRange_Angle)
		{
			Set_Chasis_Move_Rotate_Right(m_iLineFollowSet_SpeedRate, m_iLineFollowSet_SpeedRate);
			Write_Debug_Info("Auto Run --- Forward Rotate Right", DIT_Normal);
		}
		else if (m_dLineFollowSet_ResultAngel < -dwRange_Angle)
		{
			Set_Chasis_Move_Rotate_Left(m_iLineFollowSet_SpeedRate, m_iLineFollowSet_SpeedRate);
			Write_Debug_Info("Auto Run --- Forward Rotate Left", DIT_Normal);
		}
		else
		{
			//此时直接前行，不需要调整舵轮角度
			Set_Chasis_Move_Normal_Right(m_iChasis_Left_TargetSpeed, m_iChasis_Right_TargetSpeed);
			Write_Debug_Info("Auto Run --- Move Normal Forward", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_LineFollow_Backoff()
{
	int iDis_Left = m_nChasisInfo.iDis_LeftWheel - m_iLineFollow_InitDis_LeftWheel;
	int iDis_Right = m_nChasisInfo.iDis_RightWheel - m_iLineFollow_InitDis_RightWheel;

	if ((iDis_Left <= 0) || (iDis_Right <= 0))
	{
		Set_Chasis_Stop();
		m_nAutoRun_NowStatus = ARS_LineFollow_RotateAdjust;
	}
	else
	{
		double dwRange_Angle = m_dLineFollowSet_AngleRange * 20;
		//差速运动控制，进行小范围的调整
		if (m_dLineFollowSet_ResultAngel > dwRange_Angle)
		{
			Set_Chasis_Move_Rotate_Right(m_iLineFollowSet_SpeedRate, m_iLineFollowSet_SpeedRate);
			Write_Debug_Info("Auto Run --- Backoff Rotate Right", DIT_Normal);
		}
		else if (m_dLineFollowSet_ResultAngel < -dwRange_Angle)
		{
			Set_Chasis_Move_Rotate_Left(m_iLineFollowSet_SpeedRate, m_iLineFollowSet_SpeedRate);
			Write_Debug_Info("Auto Run --- Backoff Rotate Left", DIT_Normal);
		}
		else
		{
			//此时直接前行，不需要调整舵轮角度
			Set_Chasis_Move_Normal_Left(m_iChasis_Left_TargetSpeed, m_iChasis_Right_TargetSpeed);
			Write_Debug_Info("Auto Run --- Move Normal Backoff", DIT_Normal);
		}
	}
}

bool CGlobalUnit::Init_Structure_Dll()
{
	QString strDllPath = GetExePath();
	QString strDllPath_StructureCalibration = strDllPath + "\\GTStructureCalibration.dll";
	m_hDll_StructureCalibration.setFileName(strDllPath_StructureCalibration);
	if (false == m_hDll_StructureCalibration.load())
	{
		return false;
	}
	m_fun_Calibration_Get_Camera_R_And_T = (StructureCalibrationFun)m_hDll_StructureCalibration.resolve("Get_Camera_R_And_T");


	QString strDllPath_StructureDetection = strDllPath + "\\GTStructureDetection.dll";
	m_hDll_StructureDetection.setFileName(strDllPath_StructureDetection);
	if (false == m_hDll_StructureDetection.load())
	{
		return false;
	}
	m_fun_Structure_GetPointer = (StructureDetection_GetPointer_Fun)m_hDll_StructureDetection.resolve("GetProjectorHwnd");
	m_fun_Structure_StartTest = (StructureDetection_StartTest_Fun)m_hDll_StructureDetection.resolve("StartStructureTest");
	m_fun_Structure_Display = (StructureDetection_Display_Fun)m_hDll_StructureDetection.resolve("DisplayProjector");


	QString strDllPath_PointCloudModule = strDllPath + "\\GTPointCloudModule.dll";
	m_hDll_PointCloudModule.setFileName(strDllPath_PointCloudModule);
	if (false == m_hDll_PointCloudModule.load())
	{
		return false;
	}
	m_fun_PointCloud_FindPoint = (PointCloud_FindPoint_Fun)m_hDll_PointCloudModule.resolve("Find_Point_Concave_And_Convex");

	m_bIsStructure_LoadDll = true;
	return true;
}

void CGlobalUnit::Calc_Structure_Camera_R_And_T()
{
	// 	m_fun_Calibration_Get_Camera_R_And_T(m_dzStructure_Camera_R, m_dzStructure_Camera_T);
}

void CGlobalUnit::Calc_Structure_Robot_R_And_T()
{
	//用OpenCV方式 标定机械手，Tcp坐标系到基坐标系

	m_dzStructure_Robot_T[0] = m_nRobot_Actual_SpacePos.dwX;
	m_dzStructure_Robot_T[1] = m_nRobot_Actual_SpacePos.dwY;
	m_dzStructure_Robot_T[2] = m_nRobot_Actual_SpacePos.dwZ;
	double dz_robot_r[3] = { m_nRobot_Actual_SpacePos.dwU, m_nRobot_Actual_SpacePos.dwV, m_nRobot_Actual_SpacePos.dwW };

	double dz_robot_R[9] = { 0 };

	cv::Mat_<double> robot_r(3, 1, dz_robot_r);
	cv::Mat_<double> robot_R(3, 3, dz_robot_R);

	cv::Rodrigues(robot_r, robot_R);

	m_dzStructure_Robot_R[0] = robot_R.at<double>(0, 0);
	m_dzStructure_Robot_R[1] = robot_R.at<double>(0, 1);
	m_dzStructure_Robot_R[2] = robot_R.at<double>(0, 2);
	m_dzStructure_Robot_R[3] = robot_R.at<double>(1, 0);
	m_dzStructure_Robot_R[4] = robot_R.at<double>(1, 1);
	m_dzStructure_Robot_R[5] = robot_R.at<double>(1, 2);
	m_dzStructure_Robot_R[6] = robot_R.at<double>(2, 0);
	m_dzStructure_Robot_R[7] = robot_R.at<double>(2, 1);
	m_dzStructure_Robot_R[8] = robot_R.at<double>(2, 2);
}

void CGlobalUnit::Calc_Structure_R_And_T()
{
	cv::Mat_<double> robot_R(3, 3, m_dzStructure_Robot_R), robot_T(3, 1, m_dzStructure_Robot_T);

	double dzR_tcp[9] = { -1, 0, 0, 0, 1, 0, 0, 0, -1 };
	double dzT_tcp[3] = { 0, 0, 30 };
	cv::Mat_<double> tcp_R(3, 3, dzR_tcp), tcp_T(3, 1, dzT_tcp);

	double dzR[9] = { 0 };
	double dzT[3] = { 0 };
	cv::Mat_<double> structure_R(3, 3, dzR), structure_T(3, 1, dzT);

	structure_R = robot_R * tcp_R;
	structure_T = robot_R * tcp_T + robot_T;

	m_dzStructure_R[0] = structure_R.at<double>(0, 0);
	m_dzStructure_R[1] = structure_R.at<double>(0, 1);
	m_dzStructure_R[2] = structure_R.at<double>(0, 2);
	m_dzStructure_R[3] = structure_R.at<double>(1, 0);
	m_dzStructure_R[4] = structure_R.at<double>(1, 1);
	m_dzStructure_R[5] = structure_R.at<double>(1, 2);
	m_dzStructure_R[6] = structure_R.at<double>(2, 0);
	m_dzStructure_R[7] = structure_R.at<double>(2, 1);
	m_dzStructure_R[8] = structure_R.at<double>(2, 2);

	m_dzStructure_T[0] = structure_T.at<double>(0, 0);
	m_dzStructure_T[1] = structure_T.at<double>(1, 0);
	m_dzStructure_T[2] = structure_T.at<double>(2, 0);
}

void CGlobalUnit::Set_Structure_Calibrat()
{
	Calc_Structure_Camera_R_And_T();
	Calc_Structure_Robot_R_And_T();
	Calc_Structure_R_And_T();
}

void CGlobalUnit::Set_Structure_Test()
{
	if (IsRobotArrivePos(m_nStructure_InitPos))
	{
		m_bIsStructure_Move = false;  //初始化机械臂移动的状态位
		if (!m_bIsStructure_beginTest)
		{
			g_pGlobalUnit->m_fun_Structure_StartTest();
			m_bIsStructure_beginTest = true;
		}
	}
	else
	{
		if (!m_bIsStructure_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nStructure_InitPos);
			m_bIsStructure_Move = true;
		}
	}
}

void CGlobalUnit::Set_Structure_Burnish()
{
	GT_RobotArm_Pose rInfo_structure;
	rInfo_structure.dwX = g_pGlobalUnit->m_dzStructure_Robot_Pos[0] + 50;
	rInfo_structure.dwY = g_pGlobalUnit->m_dzStructure_Robot_Pos[1] + 50;
	rInfo_structure.dwZ = g_pGlobalUnit->m_dzStructure_Robot_Pos[2] - 50;
	rInfo_structure.dwU = m_nStructure_InitPos.dwU;
	rInfo_structure.dwV = m_nStructure_InitPos.dwV;
	rInfo_structure.dwW = m_nStructure_InitPos.dwW;

	if (IsRobotArrivePos(rInfo_structure))
	{
		m_bIsStructure_Move = false;  //初始化机械臂移动的状态位
		m_nAutoRun_NowStatus = ARS_Structure_InitPos;
	}
	else
	{
		if (!m_bIsStructure_Move)
		{
			//只发送一次移动到缺陷点打磨的指令
			Set_Robot_MoveTo_Target_SpacePos(rInfo_structure);
			m_bIsStructure_Move = true;
		}
		Write_Debug_Info("Wait robot move to defect point ...", DIT_Warning);
	}
}

void CGlobalUnit::Set_Structure_InitPos()
{
	if (IsRobotArrivePos(m_nStructure_InitPos))
	{
		m_bIsStructure_Move = false;  //初始化机械臂移动的状态位
		m_nAutoRun_NowStatus = ARS_LineFollow_Backoff;
	}
	else
	{
		if (!m_bIsStructure_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nStructure_InitPos);
			m_bIsStructure_Move = true;
		}
	}
}

void CGlobalUnit::Calc_DrawLine_RectPos()
{
	double dzR[9] = { cos(CV_PI / 4), -sin(CV_PI / 4), 0, sin(CV_PI / 4), cos(CV_PI / 4), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	double dzP[3] = { 0 };
	double dzP_Begin[3] = { m_ptDrawLine_topLeft.x(), m_ptDrawLine_topLeft.y(), m_ptDrawLine_topLeft.z() };
	cv::Mat_<double> mat_A(3, 1, dzP);
	cv::Mat_<double> mat_topLeft(3, 1, dzP_Begin), mat_bottomLeft(3, 1, dzP), mat_bottomRight(3, 1, dzP), mat_topRight(3, 1, dzP);

	mat_A = R * mat_topLeft;

	double dwWall_X = mat_A.at<double>(0, 0);
	double dwWall_Y = mat_A.at<double>(1, 0);
	double dwWall_Z = mat_A.at<double>(2, 0);

	double dzP_wall_B[3] = { dwWall_X - g_pGlobalUnit->m_dDrawLine_Height, dwWall_Y, dwWall_Z };
	double dzP_wall_C[3] = { dwWall_X - g_pGlobalUnit->m_dDrawLine_Height, dwWall_Y + g_pGlobalUnit->m_dDrawLine_Width, dwWall_Z };
	double dzP_wall_D[3] = { dwWall_X, dwWall_Y + g_pGlobalUnit->m_dDrawLine_Width, dwWall_Z };

	cv::Mat_<double>  mat_B(3, 1, dzP_wall_B), mat_C(3, 1, dzP_wall_C), mat_D(3, 1, dzP_wall_D);

	mat_bottomLeft = R_inv * mat_B;
	std::cout << mat_bottomLeft << std::endl;
	std::cout << "-------------" << std::endl;

	m_ptDrawLine_bottomLeft.setX(mat_bottomLeft.at<double>(0, 0));
	m_ptDrawLine_bottomLeft.setY(mat_bottomLeft.at<double>(1, 0));
	m_ptDrawLine_bottomLeft.setZ(mat_bottomLeft.at<double>(2, 0));



	mat_bottomRight = R_inv * mat_C;
	std::cout << mat_bottomRight << std::endl;
	std::cout << "-------------" << std::endl;

	m_ptDrawLine_bottomRight.setX(mat_bottomRight.at<double>(0, 0));
	m_ptDrawLine_bottomRight.setY(mat_bottomRight.at<double>(1, 0));
	m_ptDrawLine_bottomRight.setZ(mat_bottomRight.at<double>(2, 0));



	mat_topRight = R_inv * mat_D;
	std::cout << mat_topRight << std::endl;
	std::cout << "-------------" << std::endl;

	m_ptDrawLine_topRight.setX(mat_topRight.at<double>(0, 0));
	m_ptDrawLine_topRight.setY(mat_topRight.at<double>(1, 0));
	m_ptDrawLine_topRight.setZ(mat_topRight.at<double>(2, 0));

	QString strTopLeft = "DrawLine topLeft : X = " + QString::number(m_ptDrawLine_topLeft.x()) + ", Y = " + QString::number(m_ptDrawLine_topLeft.y()) + ", Z = " + QString::number(m_ptDrawLine_topLeft.z());
	QString strBottomLeft = "DrawLine bottomLeft : X = " + QString::number(m_ptDrawLine_bottomLeft.x()) + ", Y = " + QString::number(m_ptDrawLine_bottomLeft.y()) + ", Z = " + QString::number(m_ptDrawLine_bottomLeft.z());
	QString strBottomRight = "DrawLine bottomRight : X = " + QString::number(m_ptDrawLine_bottomRight.x()) + ", Y = " + QString::number(m_ptDrawLine_bottomRight.y()) + ", Z = " + QString::number(m_ptDrawLine_bottomRight.z());
	QString strTopRight = "DrawLine topRight : X = " + QString::number(m_ptDrawLine_topRight.x()) + ", Y = " + QString::number(m_ptDrawLine_topRight.y()) + ", Z = " + QString::number(m_ptDrawLine_topRight.z());
	Write_Debug_Info(strTopLeft, DIT_Normal);
	Write_Debug_Info(strBottomLeft, DIT_Normal);
	Write_Debug_Info(strBottomRight, DIT_Normal);
	Write_Debug_Info(strTopRight, DIT_Normal);
}

void CGlobalUnit::Set_DrawLine_Begin()
{
	if (IsRobotArrivePos(m_nDrawLine_InitPos))
	{
		Write_Debug_Info("robot arrive draw line init pos ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_LiftPlat_Pos_A;
	}
	else
	{
		//等待机械臂移动到画线的零点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nDrawLine_InitPos);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line init pos ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_LiftPlat_Pos_A()
{
	int iLiftPlat_Height = m_nChasisInfo.iHeight_LiftPlat;
	if (IsLiftPlatArrivePos(iLiftPlat_Height, m_iDrawLine_LiftPlat_bottomPos))
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info("LiftPlat arrive draw line A pos ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_From_topLeft;
	}
	else
	{
		//等待升降平台下降到最低点位置
		if (!m_bIsDrawLine_Move)
		{
			Set_LiftPlat_MoveTo_TargetPos(iLiftPlat_Height, m_iDrawLine_LiftPlat_bottomPos);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait LiftPlat move to draw line A pos ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_From_topLeft()
{
	if (IsRobotArrivePos(m_ptDrawLine_topLeft))
	{
		Write_Debug_Info("robot arrive draw line topLeft point ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_bottomLeft;
	}
	else
	{
		//等待机械臂移动到画矩形的起点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptDrawLine_topLeft);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line topLeft point ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_To_bottomLeft()
{
	if (IsRobotArrivePos(m_ptDrawLine_bottomLeft))
	{
		Write_Debug_Info("robot arrive draw line bottomLeft point ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_bottomRight;
	}
	else
	{
		//等待机械臂移动到画矩形的起点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptDrawLine_bottomLeft);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line bottomLeft point ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_To_bottomRight()
{
	if (IsRobotArrivePos(m_ptDrawLine_bottomRight))
	{
		Write_Debug_Info("robot arrive draw line bottomRight point ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_topRight;
	}
	else
	{
		//等待机械臂移动到画矩形的起点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptDrawLine_bottomRight);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line bottomRight point ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_To_topRight()
{
	if (IsRobotArrivePos(m_ptDrawLine_topRight))
	{
		Write_Debug_Info("robot arrive draw line topRight point ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_LiftPlat_Pos_B;
	}
	else
	{
		//等待机械臂移动到画矩形的起点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptDrawLine_topRight);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line topRight point ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_LiftPlat_Pos_B()
{
	int iLiftPlat_Height = m_nChasisInfo.iHeight_LiftPlat;
	if (IsLiftPlatArrivePos(iLiftPlat_Height, m_iDrawLine_LiftPlat_topPos))
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info("LiftPlat arrive draw line B pos ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_topLeft;
	}
	else
	{
		//等待升降平台下降到最低点位置
		if (!m_bIsDrawLine_Move)
		{
			Set_LiftPlat_MoveTo_TargetPos(iLiftPlat_Height, m_iDrawLine_LiftPlat_topPos);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait LiftPlat move to draw line B pos ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_To_topLeft()
{
	if (IsRobotArrivePos(m_ptDrawLine_topLeft))
	{
		Write_Debug_Info("robot arrive draw line topLeft point ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_To_LiftPlat_Pos_C;
	}
	else
	{
		//等待机械臂移动到画矩形的起点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptDrawLine_topLeft);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line topLeft point ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_LiftPlat_Pos_C()
{
	int iLiftPlat_Height = m_nChasisInfo.iHeight_LiftPlat;
	if (IsLiftPlatArrivePos(iLiftPlat_Height, m_iDrawLine_LiftPlat_bottomPos))
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info("LiftPlat arrive draw line C pos ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_DrawLine_End;
	}
	else
	{
		//等待升降平台下降到最低点位置
		if (!m_bIsDrawLine_Move)
		{
			Set_LiftPlat_MoveTo_TargetPos(iLiftPlat_Height, m_iDrawLine_LiftPlat_bottomPos);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait LiftPlat move to draw line C pos ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_DrawLine_End()
{
	if (IsRobotArrivePos(m_nDrawLine_InitPos))
	{
		Write_Debug_Info("robot arrive draw line init pos ...", DIT_Normal);
		m_bIsDrawLine_Move = false;
		m_nAutoRun_NowStatus = ARS_Idle;
	}
	else
	{
		//等待机械臂移动到画线的零点
		if (!m_bIsDrawLine_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nDrawLine_InitPos);
			m_bIsDrawLine_Move = true;
			Write_Debug_Info("Wait robot move to draw line init pos ...", DIT_Normal);
		}
	}
}

void CGlobalUnit::Calc_Tiling_MaterielAndPaste_Pos()
{
	double dzR[9] = { cos(CV_PI / 4), -sin(CV_PI / 4), 0, sin(CV_PI / 4), cos(CV_PI / 4), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	QGTPoint3D pt_Materiel_Begin = QGTPoint3D(m_nTiling_InitPos_Materiel.dwX, m_nTiling_InitPos_Materiel.dwY, m_nTiling_InitPos_Materiel.dwZ);
	QGTPoint3D pt_Paste_Begin = QGTPoint3D(m_nTiling_InitPos_Paste.dwX, m_nTiling_InitPos_Paste.dwY, m_nTiling_InitPos_Paste.dwZ);

	m_nTiling_MaterielPos_Array.clear();
	m_nTiling_PastePos_Array.clear();

	double dzP_Materiel[3] = { 0 };
	double dzP_Materiel_Begin[3] = { pt_Materiel_Begin.x(), pt_Materiel_Begin.y(), pt_Materiel_Begin.z() };
	cv::Mat_<double> mat_P_Materiel_Begin(3, 1, dzP_Materiel_Begin), mat_P_Materiel_Begin_New(3, 1, dzP_Materiel);

	mat_P_Materiel_Begin_New = R * mat_P_Materiel_Begin; //将取料初始点转换成标准坐标系下的点
	double dwMateriel_Begin_New_X = mat_P_Materiel_Begin_New.at<double>(0, 0);
	double dwMateriel_Begin_New_Y = mat_P_Materiel_Begin_New.at<double>(1, 0);
	double dwMateriel_Begin_New_Z = mat_P_Materiel_Begin_New.at<double>(2, 0);


	for (int i = 0; i < m_iTiling_Materiel_Num; i++)
	{
		if (i >= 4)
		{
			if (i % 4 == 0)
			{
				double dwOffset_Materiel = m_dTiling_Materiel_Width + 50;  //取料时，两堆瓷砖的间距
				dwMateriel_Begin_New_Y += dwOffset_Materiel;
			}
		}
		double dzP_Materiel_Temp_New[3] = { dwMateriel_Begin_New_X - m_dTiling_Materiel_Thickness * i, dwMateriel_Begin_New_Y, dwMateriel_Begin_New_Z };
		cv::Mat_<double> mat_P_Materiel_Temp_New(3, 1, dzP_Materiel_Temp_New), mat_P_Materiel_Temp(3, 1, dzP_Materiel);
		mat_P_Materiel_Temp = R_inv * mat_P_Materiel_Temp_New;
		QGTPoint3D pt_Materiel_Temp;
		pt_Materiel_Temp.setX(mat_P_Materiel_Temp.at<double>(0, 0));
		pt_Materiel_Temp.setY(mat_P_Materiel_Temp.at<double>(1, 0));
		pt_Materiel_Temp.setZ(mat_P_Materiel_Temp.at<double>(2, 0));
		m_nTiling_MaterielPos_Array.push_back(pt_Materiel_Temp);
	}


	double dzP_Paste[3] = { 0 };
	double dzP_Paste_Begin[3] = { pt_Paste_Begin.x(), pt_Paste_Begin.y(), pt_Paste_Begin.z() };
	cv::Mat_<double> mat_P_Paste_Begin(3, 1, dzP_Paste_Begin), mat_P_Paste_Begin_New(3, 1, dzP_Paste);

	mat_P_Paste_Begin_New = R * mat_P_Paste_Begin; //将粘贴初始点转换成标准坐标系下的点
	double dwPaste_Begin_New_X = mat_P_Paste_Begin_New.at<double>(0, 0);
	double dwPaste_Begin_New_Y = mat_P_Paste_Begin_New.at<double>(1, 0);
	double dwPaste_Begin_New_Z = mat_P_Paste_Begin_New.at<double>(2, 0);


	for (int i = 0; i < m_iTiling_Materiel_Num; i++)
	{
		double dwOffset_Paste = m_dTiling_Materiel_Width + 20; //粘贴时两块瓷砖中心点的距离

		if (i >= 4)
		{
			if (i % 4 == 0)
			{
				dwPaste_Begin_New_X -= dwOffset_Paste;
			}
		}
		
		double dzP_Paste_Temp_New[3] = { dwPaste_Begin_New_X, dwPaste_Begin_New_Y + dwOffset_Paste * i, dwPaste_Begin_New_Z };
		cv::Mat_<double> mat_P_Paste_Temp_New(3, 1, dzP_Paste_Temp_New), mat_P_Paste_Temp(3, 1, dzP_Paste);
		mat_P_Paste_Temp = R_inv * mat_P_Paste_Temp_New;
		QGTPoint3D pt_Paste_Temp;
		pt_Paste_Temp.setX(mat_P_Paste_Temp.at<double>(0, 0));
		pt_Paste_Temp.setY(mat_P_Paste_Temp.at<double>(1, 0));
		pt_Paste_Temp.setZ(mat_P_Paste_Temp.at<double>(2, 0));
		m_nTiling_PastePos_Array.push_back(pt_Paste_Temp);
	}

}

void CGlobalUnit::Set_Tiling_PickMateriel_Begin()
{
	if (IsRobotArriveAngle(m_nTiling_InitAngle_Materiel))
	{
		Write_Debug_Info("Arrive Tiling PickMateriel Begin Pos", DIT_Normal);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Materiel_Picking;

		m_iTiling_Count++;
		if (m_iTiling_Count >= m_iTiling_Materiel_Num)
		{
			Write_Debug_Info("Tiling Over", DIT_Normal);
			m_iTiling_Count = -1;
			m_nAutoRun_NowStatus = ARS_Idle;
		}
		else
		{
			m_ptTiling_MaterielPos = m_nTiling_MaterielPos_Array.at(m_iTiling_Count);
			m_ptTiling_PastePos = m_nTiling_PastePos_Array.at(m_iTiling_Count);
		}
	}
	else
	{
		//等待机械臂移动到贴瓷砖的初始位置
		if (!m_bIsTiling_Move)
		{
			GT_RobotArm_Pose pose_InitAngle_Materiel = m_nTiling_InitAngle_Materiel;
			pose_InitAngle_Materiel.dwZ = pose_InitAngle_Materiel.dwZ - 360;

			Set_Robot_MoveTo_Target_JointAngle(pose_InitAngle_Materiel);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling PickMateriel Begin Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_MaterielPos()
{
	if (IsRobotArrivePos(m_ptTiling_MaterielPos))
	{
		Write_Debug_Info("Arrive Tiling Materiel Pos", DIT_Normal);
		Sleep(1000);
		m_nChasis_NowType = CMT_Electromagnet_On;
		Sleep(1000);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_PickMateriel_End;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的物料位置
		if (!m_bIsTiling_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptTiling_MaterielPos);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Materiel Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_PickMateriel_End()
{
	if (IsRobotArriveAngle(m_nTiling_InitAngle_Materiel))
	{
		Write_Debug_Info("Arrive Tiling PickMateriel End Pos", DIT_Normal);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Paste_Begin;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的初始位置
		if (!m_bIsTiling_Move)
		{
			GT_RobotArm_Pose pose_InitAngle_Materiel = m_nTiling_InitAngle_Materiel;
			pose_InitAngle_Materiel.dwZ = pose_InitAngle_Materiel.dwZ - 360;

			Set_Robot_MoveTo_Target_JointAngle(pose_InitAngle_Materiel);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling PickMateriel End Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_Paste_Begin()
{
	if (IsRobotArriveAngle(m_nTiling_InitPos))
	{
		Write_Debug_Info("Arrive Tiling Paste Begin Pos", DIT_Normal);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Paste_Near_Begin;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的粘贴位置
		if (!m_bIsTiling_Move)
		{
			GT_RobotArm_Pose pose_InitPos = m_nTiling_InitPos;
			pose_InitPos.dwZ = pose_InitPos.dwZ - 360;

			Set_Robot_MoveTo_Target_JointAngle(pose_InitPos);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Paste Begin Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_PastePos_Near_Begin()
{
	if (IsRobotArrivePos(m_ptTiling_PastePos))
	{
		Write_Debug_Info("Arrive Tiling Paste Near Pos", DIT_Normal);
		m_nTiling_TcpForce_Init = m_nRobot_Actual_TcpForce;

		QString strInfo = "TcpForce_Init : " + QString::number(m_nTiling_TcpForce_Init.iForce_1) + QString::number(m_nTiling_TcpForce_Init.iForce_2) + QString::number(m_nTiling_TcpForce_Init.iForce_3) + QString::number(m_nTiling_TcpForce_Init.iForce_4);
		Write_Debug_Info(strInfo, DIT_Warning);

		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Paste;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的粘贴位置
		if (!m_bIsTiling_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptTiling_PastePos);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Paste Near Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_PastePos()
{
	m_nTiling_TcpForce_Paste = m_nRobot_Actual_TcpForce;

	QString strInfo = "TcpForce_Paste : " + QString::number(m_nTiling_TcpForce_Paste.iForce_1) + QString::number(m_nTiling_TcpForce_Paste.iForce_2) + QString::number(m_nTiling_TcpForce_Paste.iForce_3) + QString::number(m_nTiling_TcpForce_Paste.iForce_4);
	Write_Debug_Info(strInfo, DIT_Warning);

	bool bIsArrive_PastePos = false;
	if ((abs(m_nTiling_TcpForce_Paste.iForce_1 - m_nTiling_TcpForce_Init.iForce_1) > m_iTiling_Pressure_Range) ||
		(abs(m_nTiling_TcpForce_Paste.iForce_2 - m_nTiling_TcpForce_Init.iForce_2) > m_iTiling_Pressure_Range) ||
		(abs(m_nTiling_TcpForce_Paste.iForce_3 - m_nTiling_TcpForce_Init.iForce_3) > m_iTiling_Pressure_Range) ||
		(abs(m_nTiling_TcpForce_Paste.iForce_4 - m_nTiling_TcpForce_Init.iForce_4) > m_iTiling_Pressure_Range))
	{
		bIsArrive_PastePos = true;
	}
	else
	{
		bIsArrive_PastePos = false;
	}

	if (bIsArrive_PastePos)
	{
		Write_Debug_Info("Arrive Tiling Paste Pos", DIT_Normal);
		Set_Robot_Stop();
		Sleep(1000);
		m_nChasis_NowType = CMT_Electromagnet_Off;
		Sleep(1000);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Paste_Near_End;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的粘贴位置
		if (!m_bIsTiling_Move)
		{
			QGTPoint3D pt_Temp;
			pt_Temp = m_ptTiling_PastePos;
			double dwZ = pt_Temp.z() + m_dTiling_Paste_Feed;
			pt_Temp.setZ(dwZ);
			Set_Robot_MoveTo_Target_SpacePos(pt_Temp);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Paste Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_PastePos_Near_End()
{
	if (IsRobotArrivePos(m_ptTiling_PastePos))
	{
		Write_Debug_Info("Arrive Tiling Paste Near Pos", DIT_Normal);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_Paste_End;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的粘贴位置
		if (!m_bIsTiling_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_ptTiling_PastePos);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Paste Near Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Tiling_Paste_End()
{
	if (IsRobotArriveAngle(m_nTiling_InitPos))
	{
		Write_Debug_Info("Arrive Tiling Paste End Pos", DIT_Normal);
		m_bIsTiling_Move = false;
		m_nAutoRun_NowStatus = ARS_Tiling_PickMateriel_Begin;
	}
	else
	{
		//等待机械臂移动到贴瓷砖的粘贴位置
		if (!m_bIsTiling_Move)
		{
			GT_RobotArm_Pose pose_InitPos = m_nTiling_InitPos;
			pose_InitPos.dwZ = pose_InitPos.dwZ - 360;

			Set_Robot_MoveTo_Target_JointAngle(pose_InitPos);
			m_bIsTiling_Move = true;
			Write_Debug_Info("Move To Tiling Paste End Pos", DIT_Normal);
		}
	}
}

void CGlobalUnit::Calc_SprayPaint_Param()
{
	m_dSprayPaint_VerDis_MovedBy_Robot = (1 - m_dSprayPaint_Overlap_By_Robot) * m_dSprayPaint_Width_By_Spray;

	double dwDis_All_By_Robot = (m_iSprayPaint_Count_MovedBy_Robot * 2 - 1) * m_dSprayPaint_VerDis_MovedBy_Robot;  //机械臂一共移动的距离
	double dwArea_By_Robot = dwDis_All_By_Robot + m_dSprayPaint_Width_By_Spray;  //升降平台单次移动时喷漆的工作区域

	m_dSprayPaint_Dis_MovedBy_LiftPlat = dwArea_By_Robot - m_dSprayPaint_Overlap_By_LiftPlat * m_dSprayPaint_Width_By_Spray;

	m_dSprayPaint_Dis_MovedBy_Chasis = (1 - m_dSprayPaint_Overlap_By_Chasis) * m_dSprayPaint_HorDis_MovedBy_Robot;
}

void CGlobalUnit::Calc_SprayPaint_Robot_Pos()
{
	m_nSprayPaint_Work_RobotPos_A = m_nSprayPaint_Robot_InitPos;
	m_nSprayPaint_Work_RobotPos_A.dwX = m_nSprayPaint_Robot_InitPos.dwX - 2 * m_dSprayPaint_VerDis_MovedBy_Robot * m_iSprayPaint_Current_Count_MovedBy_Robot;
	
	m_nSprayPaint_Work_RobotPos_B = m_nSprayPaint_Work_RobotPos_A;
	m_nSprayPaint_Work_RobotPos_B.dwY = m_nSprayPaint_Work_RobotPos_A.dwY + m_dSprayPaint_HorDis_MovedBy_Robot;

	m_nSprayPaint_Work_RobotPos_C = m_nSprayPaint_Work_RobotPos_B;
	m_nSprayPaint_Work_RobotPos_C.dwX = m_nSprayPaint_Work_RobotPos_B.dwX - m_dSprayPaint_VerDis_MovedBy_Robot;

	m_nSprayPaint_Work_RobotPos_D = m_nSprayPaint_Work_RobotPos_C;
	m_nSprayPaint_Work_RobotPos_D.dwY = m_nSprayPaint_Work_RobotPos_C.dwY - m_dSprayPaint_HorDis_MovedBy_Robot;

	Write_Debug_Info(QString::fromLocal8Bit("喷漆方案---计算机械臂喷漆路径"), DIT_Normal);
}

void CGlobalUnit::Set_SprayPaint_LiftPlat_Ready()
{
	int iRet = m_iSprayPaint_Current_Count_MovedBy_Chasis % 2;
	if (iRet == 0)
	{
		Set_SprayPaint_LiftPlat_Ready_evenNumber();
	}
	else
	{
		Set_SprayPaint_LiftPlat_Ready_oddNumber();
	}
}

void CGlobalUnit::Set_SprayPaint_LiftPlat_Ready_evenNumber()
{
	int iPos_Begin = m_dSprayPaint_LiftPlat_InitPos;
	int iPos_Target = iPos_Begin + m_iSprayPaint_Current_Count_MovedBy_LiftPlat * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info(QString::fromLocal8Bit("喷漆方案---升降平台到达指定位置"), DIT_Normal);
		if ((m_bIs_SprayPaint_HorInsideCorner_Enable == true) && (m_iSprayPaint_Current_Count_MovedBy_LiftPlat == m_iSprayPaint_Count_MovedBy_LiftPlat - 1))
		{
			Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_A;
		}
		else
		{
			Calc_SprayPaint_Robot_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_A;
		}
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_SprayPaint_LiftPlat_Ready_oddNumber()
{
	int iPos_Begin = m_dSprayPaint_LiftPlat_InitPos + (m_iSprayPaint_Count_MovedBy_LiftPlat - 1) * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = iPos_Begin - m_iSprayPaint_Current_Count_MovedBy_LiftPlat * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info(QString::fromLocal8Bit("喷漆方案---升降平台到达指定位置"), DIT_Normal);
		if ((m_bIs_SprayPaint_HorInsideCorner_Enable == true) && (m_iSprayPaint_Current_Count_MovedBy_LiftPlat == 0))
		{
			Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_A;
		}
		else
		{
			Calc_SprayPaint_Robot_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_A;
		}
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_SprayPaint_Robot_Pos_A()
{
	if (IsRobotArrivePos(m_nSprayPaint_Work_RobotPos_A))
	{
		Write_Debug_Info("Arrive SprayPaint Robot Pos A", DIT_Normal);
		Set_Chasis_Electromagnet_Enable(true);
		m_bIs_SprayPaint_Robot_Move = false;
		m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_B;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaint_Work_RobotPos_A);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint Robot Pos A", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_Robot_Pos_B()
{
	if (IsRobotArrivePos(m_nSprayPaint_Work_RobotPos_B))
	{
		Write_Debug_Info("Arrive SprayPaint Robot Pos B", DIT_Normal);
		Set_Chasis_Electromagnet_Enable(false);
		m_bIs_SprayPaint_Robot_Move = false;
		m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_C;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaint_Work_RobotPos_B);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint Robot Pos B", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_Robot_Pos_C()
{
	if (IsRobotArrivePos(m_nSprayPaint_Work_RobotPos_C))
	{
		Write_Debug_Info("Arrive SprayPaint Robot Pos C", DIT_Normal);
		Set_Chasis_Electromagnet_Enable(true);
		m_bIs_SprayPaint_Robot_Move = false;
		m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_D;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaint_Work_RobotPos_C);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint Robot Pos C", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_Robot_Pos_D()
{
	if (IsRobotArrivePos(m_nSprayPaint_Work_RobotPos_D))
	{
		Write_Debug_Info("Arrive SprayPaint Robot Pos D", DIT_Normal);
		Set_Chasis_Electromagnet_Enable(false);
		m_bIs_SprayPaint_Robot_Move = false;
		m_iSprayPaint_Current_Count_MovedBy_Robot++;

		if (m_iSprayPaint_Current_Count_MovedBy_Robot >= m_iSprayPaint_Count_MovedBy_Robot)
		{
			//若当前机械臂移动次数达到指定次数，则判定是否需要继续移动升降平台；否则继续移动机械臂
			m_iSprayPaint_Current_Count_MovedBy_Robot = 0;
			m_iSprayPaint_Current_Count_MovedBy_LiftPlat++;

			if (m_iSprayPaint_Current_Count_MovedBy_LiftPlat >= m_iSprayPaint_Count_MovedBy_LiftPlat)
			{
				//若当前升降平台移动次数达到指定次数，则判断是否需要继续移动机器人底盘；否则继续
				m_iSprayPaint_Current_Count_MovedBy_LiftPlat = 0;
				m_iSprayPaint_Current_Count_MovedBy_Chasis++;

				if (m_iSprayPaint_Current_Count_MovedBy_Chasis >= m_iSprayPaint_Count_MovedBy_Chasis)
				{
					//若当前底盘移动次数达到指定次数，则停止；否则继续开始下一轮循线运动
					m_iSprayPaint_Current_Count_MovedBy_Chasis = 0;
					m_nAutoRun_NowStatus = ARS_Idle;
				}
				else
				{
					m_nAutoRun_NowStatus = ARS_LineFollow_Forward;
				}

			}
			else
			{
				m_nAutoRun_NowStatus = ARS_SprayPaint_LiftPlat_Ready;
			}

		}
		else
		{
			Calc_SprayPaint_Robot_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_A;
		}
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaint_Work_RobotPos_D);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint Robot Pos D", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_A()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_VerInsideCorner_RobotPos_A))
	{
		Write_Debug_Info("Arrive SprayPaint VerInsideCorner Robot Pos A", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_VerInsideCorner_RobotPos_A);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint VerInsideCorner Robot Pos A", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin()
{
	int iHeight = (m_iSprayPaint_Count_MovedBy_LiftPlat - 1) * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = m_dSprayPaint_LiftPlat_InitPos;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Electromagnet_Enable(true);
		m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End;
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End()
{
	int iHeight = (m_iSprayPaint_Count_MovedBy_LiftPlat - 1) * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = m_dSprayPaint_LiftPlat_InitPos + iHeight;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Electromagnet_Enable(false);
		m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_B;
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_B()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_VerInsideCorner_RobotPos_B))
	{
		Write_Debug_Info("Arrive SprayPaint VerInsideCorner Robot Pos B", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_VerInsideCorner_RobotPos_B);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint VerInsideCorner Robot Pos B", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin()
{
	int iHeight = (m_iSprayPaint_Count_MovedBy_LiftPlat - 1) * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = m_dSprayPaint_LiftPlat_InitPos + iHeight;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Electromagnet_Enable(true);
		m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End;
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End()
{
	int iHeight = (m_iSprayPaint_Count_MovedBy_LiftPlat - 1) * m_dSprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = m_dSprayPaint_LiftPlat_InitPos;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Electromagnet_Enable(false);
		m_iSprayPaint_Current_Count_VerInsideCorner++;
		if (m_iSprayPaint_Current_Count_VerInsideCorner >= m_iSprayPaint_Count_HorInsideCorner)
		{
			m_iSprayPaint_Current_Count_VerInsideCorner = 0;
			m_nAutoRun_NowStatus = ARS_SprayPaint_LiftPlat_Ready;
		}
		else
		{
			m_nAutoRun_NowStatus = ARS_SprayPaint_VerInsideCorner_Robot_A;
		}
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos()
{
	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A = m_nSprayPaintSet_HorInsideCorner_RobotPos_A;

	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B = m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A;
	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B.dwY = m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A.dwY + m_dSprayPaint_HorDis_MovedBy_Robot;

	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D = m_nSprayPaintSet_HorInsideCorner_RobotPos_B;

	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C = m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D;
	m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C.dwY = m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D.dwY + m_dSprayPaint_HorDis_MovedBy_Robot;
}

void CGlobalUnit::Set_SprayPaint_HorInsideCorner_Work_Robot_A()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A))
	{
		Write_Debug_Info("Arrive SprayPaint HorInsideCorner Work RobotPos A", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		Set_Chasis_Electromagnet_Enable(true);
		m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_B;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint HorInsideCorner Work RobotPos A", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_HorInsideCorner_Work_Robot_B()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B))
	{
		Write_Debug_Info("Arrive SprayPaint HorInsideCorner Work RobotPos B", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		Set_Chasis_Electromagnet_Enable(false);
		m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_C;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint HorInsideCorner Work RobotPos B", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_HorInsideCorner_Work_Robot_C()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C))
	{
		Write_Debug_Info("Arrive SprayPaint HorInsideCorner Work RobotPos C", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		Set_Chasis_Electromagnet_Enable(true);
		m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_D;
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint HorInsideCorner Work RobotPos C", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_SprayPaint_HorInsideCorner_Work_Robot_D()
{
	if (IsRobotArrivePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D))
	{
		Write_Debug_Info("Arrive SprayPaint HorInsideCorner Work RobotPos D", DIT_Normal);
		m_bIs_SprayPaint_Robot_Move = false;
		Set_Chasis_Electromagnet_Enable(false);
		m_iSprayPaint_Current_Count_HorInsideCorner++;
		if (m_iSprayPaint_Current_Count_HorInsideCorner >= m_iSprayPaint_Count_HorInsideCorner)
		{
			m_iSprayPaint_Current_Count_HorInsideCorner = 0;
			Calc_SprayPaint_Robot_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_Robot_Pos_A;
		}
		else
		{
			Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos();
			m_nAutoRun_NowStatus = ARS_SprayPaint_HorInsideCorner_Work_Robot_A;
		}
	}
	else
	{
		if (!m_bIs_SprayPaint_Robot_Move)
		{
			Set_Robot_MoveTo_Target_SpacePos(m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D);
			m_bIs_SprayPaint_Robot_Move = true;
			Write_Debug_Info("Move To SprayPaint HorInsideCorner Work RobotPos D", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Run_DemoPlan_A()
{
	if (IsChasisConnect())
	{
		if (m_bIs_LineFollowInfo_Valid)
		{
			if (m_nAutoRun_NowStatus == ARS_LineFollow_RotateAdjust)
			{
				Set_LineFollow_RotateAdjust();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_SideswayAdjust)
			{
				Set_LineFollow_SideswayAdjust();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_Forward)
			{
				Set_LineFollow_Forward();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_Backoff)
			{
				Set_LineFollow_Backoff();
			}
		}
		else
		{
			Set_Chasis_Stop();
		}
	}
}

void CGlobalUnit::Set_Run_DemoPlan_B()
{
	if (IsChasisConnect())
	{
		if (m_bIs_LineFollowInfo_Valid)
		{
			if (m_nAutoRun_NowStatus == ARS_LineFollow_RotateAdjust)
			{
				Set_LineFollow_RotateAdjust();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_SideswayAdjust)
			{
				Set_LineFollow_SideswayAdjust();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_Forward)
			{
				Set_LineFollow_Forward();
			}
			else if (m_nAutoRun_NowStatus == ARS_LineFollow_Backoff)
			{
				Set_LineFollow_Backoff();
			}
		}
		else
		{
			Set_Chasis_Stop();
		}
	}
}

void CGlobalUnit::Set_Run_DemoPlan_C()
{
	// 1.机械臂移动到 零点位置
	// 2.升降平台移动到 A 点位置（最低点）
	// 3.机械臂移动到 矩形起点 位置
	// 4.机械臂移动到 矩形左下 位置
	// 5.机械臂移动到 矩形右下 位置
	// 6.机械臂移动到 矩形右上 位置
	// 7.升降平台移动到 B 点位置（最高点）
	// 8.机械臂移动到 矩形终点 位置
	// 9.升降平台移动到 C 点位置（最低点）
	// 10.机械臂移动到 零点位置

	if (IsRobotConnect() && IsChasisConnect() && IsLiftPlatConnect())
	{
		if (m_nAutoRun_NowStatus == ARS_DrawLine_Begin)
		{
			Set_DrawLine_Begin();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_LiftPlat_Pos_A)
		{
			Set_DrawLine_LiftPlat_Pos_A();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_From_topLeft)
		{
			Set_DrawLine_From_topLeft();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_bottomLeft)
		{
			Set_DrawLine_To_bottomLeft();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_bottomRight)
		{
			Set_DrawLine_To_bottomRight();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_topRight)
		{
			Set_DrawLine_To_topRight();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_LiftPlat_Pos_B)
		{
			Set_DrawLine_LiftPlat_Pos_B();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_topLeft)
		{
			Set_DrawLine_To_topLeft();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_To_LiftPlat_Pos_C)
		{
			Set_DrawLine_LiftPlat_Pos_C();
		}
		else if (m_nAutoRun_NowStatus == ARS_DrawLine_End)
		{
			Set_DrawLine_End();
		}
	}
}

void CGlobalUnit::Set_Run_DemoPlan_D()
{
	if (IsRobotConnect())
	{
		if (m_nAutoRun_NowStatus == ARS_Tiling_PickMateriel_Begin)
		{
			Set_Tiling_PickMateriel_Begin();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Materiel_Picking)
		{
			Set_Tiling_MaterielPos();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_PickMateriel_End)
		{
			Set_Tiling_PickMateriel_End();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Paste_Begin)
		{
			Set_Tiling_Paste_Begin();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Paste_Near_Begin)
		{
			Set_Tiling_PastePos_Near_Begin();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Paste)
		{
			Set_Tiling_PastePos();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Paste_Near_End)
		{
			Set_Tiling_PastePos_Near_End();
		}
		else if (m_nAutoRun_NowStatus == ARS_Tiling_Paste_End)
		{
			Set_Tiling_Paste_End();
		}
	}
}

void CGlobalUnit::Set_Run_DemoPlan_E()
{
	if (m_nAutoRun_NowStatus == ARS_LineFollow_RotateAdjust)
	{
		Set_LineFollow_RotateAdjust();
	}
	else if (m_nAutoRun_NowStatus == ARS_LineFollow_SideswayAdjust)
	{
		Set_LineFollow_SideswayAdjust();
	}
	else if (m_nAutoRun_NowStatus == ARS_LineFollow_Forward)
	{
		Set_LineFollow_Forward();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_LiftPlat_Ready)
	{
		Set_SprayPaint_LiftPlat_Ready();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_Robot_Pos_A)
	{
		Set_SprayPaint_Robot_Pos_A();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_Robot_Pos_B)
	{
		Set_SprayPaint_Robot_Pos_B();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_Robot_Pos_C)
	{
		Set_SprayPaint_Robot_Pos_C();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_Robot_Pos_D)
	{
		Set_SprayPaint_Robot_Pos_D();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_A)
	{
		Set_SprayPaint_VerInsideCorner_Robot_A();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin)
	{
		Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End)
	{
		Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_B)
	{
		Set_SprayPaint_VerInsideCorner_Robot_B();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin)
	{
		Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End)
	{
		Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_HorInsideCorner_Work_Robot_A)
	{
		Set_SprayPaint_HorInsideCorner_Work_Robot_A();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_HorInsideCorner_Work_Robot_B)
	{
		Set_SprayPaint_HorInsideCorner_Work_Robot_B();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_HorInsideCorner_Work_Robot_C)
	{
		Set_SprayPaint_HorInsideCorner_Work_Robot_C();
	}
	else if (m_nAutoRun_NowStatus == ARS_SprayPaint_HorInsideCorner_Work_Robot_D)
	{
		Set_SprayPaint_HorInsideCorner_Work_Robot_D();
	}
	
}

void CGlobalUnit::Set_Run_DemoPlan_F()
{
	if (m_nAutoRun_NowStatus == ARS_Ros_Chasis_RotateAdjust)
	{
		Set_Ros_SprayPaint_Chasis_RotateAdjust();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_Chasis_SideswayAdjust)
	{
		Set_Ros_SprayPaint_Chasis_SideswayAdjust();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_Chasis_Left)
	{
		Set_Ros_SprayPaint_Chasis_Left();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_Chasis_Right)
	{
		Set_Ros_SprayPaint_Chasis_Right();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_LiftPlat_Ready)
	{
		Set_Ros_SprayPaint_LiftPlat_Ready();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_1)
	{
		Set_Ros_SprayPaint_Pos_1();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_2)
	{
		Set_Ros_SprayPaint_Pos_2();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_3)
	{
		Set_Ros_SprayPaint_Pos_3();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_4)
	{
		Set_Ros_SprayPaint_Pos_4();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_5)
	{
		Set_Ros_SprayPaint_Pos_5();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_6)
	{
		Set_Ros_SprayPaint_Pos_6();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_7)
	{
		Set_Ros_SprayPaint_Pos_7();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_8)
	{
		Set_Ros_SprayPaint_Pos_8();
	}
	else if (m_nAutoRun_NowStatus == ARS_Ros_SprayPaint_Pos_9)
	{
		Set_Ros_SprayPaint_Pos_9();
	}
}

void CGlobalUnit::Set_DemPlan_Run()
{
	if (m_iDemoPlanSet_Index == 0)
	{
		Set_Run_DemoPlan_A();
	}
	else if (m_iDemoPlanSet_Index == 1)
	{
		Set_Run_DemoPlan_B();
	}
	else if (m_iDemoPlanSet_Index == 2)
	{
		Set_Run_DemoPlan_C();
	}
	else if (m_iDemoPlanSet_Index == 3)
	{
		Set_Run_DemoPlan_D();
	}
	else if (m_iDemoPlanSet_Index == 4)
	{
		Set_Run_DemoPlan_E();
	}
	else if (m_iDemoPlanSet_Index == 5)
	{
		Set_Run_DemoPlan_F();
	}
	else
	{
		Write_Debug_Info("No Demo Run", DIT_Normal);
		Sleep(50);
	}
}

void CGlobalUnit::Set_DemPlan_Stop()
{
	if (m_iDemoPlanSet_Index == 0)
	{
		if (IsChasisConnect())
		{
			Set_Chasis_Stop();
		}
	}
	else if (m_iDemoPlanSet_Index == 1)
	{
		if (IsRobotConnect())
		{
			Set_Robot_Stop();
		}
		if (IsChasisConnect())
		{
			Set_Chasis_Stop();
		}
	}
	else if (m_iDemoPlanSet_Index == 2)
	{
		if (IsRobotConnect())
		{
			Set_Robot_Stop();
		}
		if (IsLiftPlatConnect())
		{
			m_nLiftPlat_NowStatus = LPS_Stop;
		}
		m_bIsDrawLine_Move = false;
	}
	else if (m_iDemoPlanSet_Index == 3)
	{
		if (IsRobotConnect())
		{
			Set_Robot_Stop();
		}
		m_iTiling_Count = -1;
		m_bIsTiling_Move = false;
		Write_Debug_Info("Tiling Stop", DIT_Normal);
	}
	else if (m_iDemoPlanSet_Index == 4)
	{
		Set_Robot_Stop();
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Stop();
		m_bIs_SprayPaint_Robot_Move = false;
		m_iSprayPaint_Current_Count_MovedBy_Chasis = 0;
		m_iSprayPaint_Current_Count_MovedBy_LiftPlat = 0;
		m_iSprayPaint_Current_Count_MovedBy_Robot = 0;
		Write_Debug_Info("SprayPaint Stop", DIT_Normal);
	}
	else if (m_iDemoPlanSet_Index == 5)
	{
		m_nRos_Work_Pos_Status = RWPS_Idle;
		m_nLiftPlat_NowStatus = LPS_Stop;
		Set_Chasis_Stop();
		m_bIs_Ros_Work_Finished = true;
		m_bIs_Ros_SprayPaint_RosWork = false;
		m_iRos_SprayPaint_Current_Count_MovedBy_Chasis = 0;
		m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat = 0;
		Write_Debug_Info("Ros SprayPaint Stop", DIT_Normal);
	}
	m_nAutoRun_NowStatus = ARS_Idle;
}

GT_RobotArm_Pose CGlobalUnit::Translate_Robot_To_Normal_CoordinateSystem(GT_RobotArm_Pose pose_Input)
{
	double dzR[9] = { cos(GT_Ang), -sin(GT_Ang), 0, sin(GT_Ang), cos(GT_Ang), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	double dz_Pose_Input[3] = { pose_Input.dwX, pose_Input.dwY, pose_Input.dwZ };
	double dz_Pose_Output[3] = { 0 };

	cv::Mat_<double> mat_Pose_Input(3, 1, dz_Pose_Input);
	cv::Mat_<double> mat_Pose_Output(3, 1, dz_Pose_Output);

	// S0 为当前坐标系下的点，S1为目标坐标系下的点，R(θ)为从当前坐标系到目标坐标系的旋转矩阵，则转换公式为
	// S0 = R(θ) * S1
	mat_Pose_Output = R_inv * mat_Pose_Input;

	GT_RobotArm_Pose pose_Output = pose_Input;
	pose_Output.dwX = mat_Pose_Output.at<double>(0, 0);
	pose_Output.dwY = mat_Pose_Output.at<double>(1, 0);
	pose_Output.dwZ = mat_Pose_Output.at<double>(2, 0);

	return pose_Output;
}

QGTPoint3D CGlobalUnit::Translate_Robot_To_Normal_CoordinateSystem(const QGTPoint3D pt_Input)
{
	double dzR[9] = { cos(GT_Ang), -sin(GT_Ang), 0, sin(GT_Ang), cos(GT_Ang), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	double dz_pt_Input[3] = { pt_Input.x(), pt_Input.y(), pt_Input.z() };
	double dz_pt_Output[3] = { 0 };

	cv::Mat_<double> mat_pt_Input(3, 1, dz_pt_Input);
	cv::Mat_<double> mat_pt_Output(3, 1, dz_pt_Output);

	// S0 为当前坐标系下的点，S1为目标坐标系下的点，R(θ)为从当前坐标系到目标坐标系的旋转矩阵，则转换公式为
	// S0 = R(θ) * S1
	mat_pt_Output = R_inv * mat_pt_Input;

	QGTPoint3D pt_Output;
	pt_Output.setX(mat_pt_Output.at<double>(0, 0));
	pt_Output.setY(mat_pt_Output.at<double>(1, 0));
	pt_Output.setZ(mat_pt_Output.at<double>(2, 0));

	return pt_Output;
}

GT_RobotArm_Pose CGlobalUnit::Translate_Normal_To_Robot_CoordinateSystem(GT_RobotArm_Pose pose_Input)
{
	double dzR[9] = { cos(-GT_Ang), -sin(-GT_Ang), 0, sin(-GT_Ang), cos(-GT_Ang), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	double dz_Pose_Input[3] = { pose_Input.dwX, pose_Input.dwY, pose_Input.dwZ };
	double dz_Pose_Output[3] = { 0 };

	cv::Mat_<double> mat_Pose_Input(3, 1, dz_Pose_Input);
	cv::Mat_<double> mat_Pose_Output(3, 1, dz_Pose_Output);

	// S0 为当前坐标系下的点，S1为目标坐标系下的点，R(θ)为从当前坐标系到目标坐标系的旋转矩阵，则转换公式为
	// S0 = R(θ) * S1
	mat_Pose_Output = R_inv * mat_Pose_Input;

	GT_RobotArm_Pose pose_Output = pose_Input;
	pose_Output.dwX = mat_Pose_Output.at<double>(0, 0);
	pose_Output.dwY = mat_Pose_Output.at<double>(1, 0);
	pose_Output.dwZ = mat_Pose_Output.at<double>(2, 0);

	return pose_Output;
}

QGTPoint3D CGlobalUnit::Translate_Normal_To_Robot_CoordinateSystem(const QGTPoint3D pt_Input)
{
	double dzR[9] = { cos(-GT_Ang), -sin(-GT_Ang), 0, sin(-GT_Ang), cos(-GT_Ang), 0, 0, 0, 1 };
	cv::Mat_<double> R(3, 3, dzR);
	cv::Mat_<double> R_inv = R.t();

	double dz_pt_Input[3] = { pt_Input.x(), pt_Input.y(), pt_Input.z() };
	double dz_pt_Output[3] = { 0 };

	cv::Mat_<double> mat_pt_Input(3, 1, dz_pt_Input);
	cv::Mat_<double> mat_pt_Output(3, 1, dz_pt_Output);

	// S0 为当前坐标系下的点，S1为目标坐标系下的点，R(θ)为从当前坐标系到目标坐标系的旋转矩阵，则转换公式为
	// S0 = R(θ) * S1
	mat_pt_Output = R_inv * mat_pt_Input;

	QGTPoint3D pt_Output;
	pt_Output.setX(mat_pt_Output.at<double>(0, 0));
	pt_Output.setY(mat_pt_Output.at<double>(1, 0));
	pt_Output.setZ(mat_pt_Output.at<double>(2, 0));

	return pt_Output;
}

bool CGlobalUnit::Is_Turning(const QList<GT_Lidar_Data> data_Array_Input, const int iIndex)
{
	int iStep = m_iLidar_SearchTurning_Step;
	int iDis_Threshold = m_iLidar_SearchTurning_Dis_Threshold;
	int iLen_Threshold = m_iLidar_SearchTurning_Len_Threshold;

	if ((iIndex >= iStep) && (iIndex < data_Array_Input.size() - iStep))
	{
		double dwDis_Center = data_Array_Input.at(iIndex).scan_Distance;
		double dwAngle = data_Array_Input.at(iIndex).scan_Angle;

		double dwDis_Begin = data_Array_Input.at(iIndex - iStep).scan_Distance;
		double dwDis_End = data_Array_Input.at(iIndex + iStep).scan_Distance;

		if ((dwDis_Center - dwDis_Begin > iDis_Threshold) && (dwDis_Center - dwDis_End > iDis_Threshold))
		{
			QList<double> line_Len_Array;
			double dwLine_Len_All(0.0), dwLine_Len_Max(0.0);

			for (int i = iIndex - iStep; i < iIndex + iStep; i++)
			{
				QLineF line_Temp(data_Array_Input.at(i).scan_Point, data_Array_Input.at(i + 1).scan_Point);
				line_Len_Array.push_back(line_Temp.length());
			}

			for (int j = 0; j < line_Len_Array.size(); j++)
			{
				double dwLine_Len_Temp = line_Len_Array.at(j);
				if (dwLine_Len_Max <= dwLine_Len_Temp)
				{
					dwLine_Len_Max = dwLine_Len_Temp;
				}
				dwLine_Len_All += dwLine_Len_Temp;
			}

			double dwLine_Len_Average = dwLine_Len_All / (double)line_Len_Array.size();

			if (dwLine_Len_Max - dwLine_Len_Average < iLen_Threshold)
			{
				return true;
			}
		}
	}

	return false;
}

int CGlobalUnit::Get_Scan_Turning(const QList<GT_Lidar_Data> data_Array_Input)
{
	QList<GT_Lidar_Data> turn_Array;

	for (int i = 0; i < data_Array_Input.size(); i++)
	{
		if (Is_Turning(data_Array_Input, i))
		{
			turn_Array.push_back(data_Array_Input.at(i));
		}
	}

	int iIndex_Out = -1;

	if (turn_Array.size() == 0)
	{
		iIndex_Out = -1;
	}
	else if (turn_Array.size() == 1)
	{
		iIndex_Out = turn_Array.at(0).scan_Index;
	}
	else
	{
		double dwAngle_Out = turn_Array.at(0).scan_Angle;

		for (int i = 0; i < turn_Array.size(); i++)
		{
			double dwAngle_Temp = turn_Array.at(i).scan_Angle;
			if (dwAngle_Out <= dwAngle_Temp)
			{
				dwAngle_Out = dwAngle_Temp;
				iIndex_Out = turn_Array.at(i).scan_Index;
			}
		}
	}

	return iIndex_Out;
}

double CGlobalUnit::Distance_From_Point_To_Line(const QLineF lineInput, const QPointF ptInput)
{
	double dwDis_Output(0.000), dPoint_X(0.000), dPoint_Y(0.000);
	QPointF ptVector_Line = QPointF(lineInput.x2() - lineInput.x1(), lineInput.y2() - lineInput.y1());

	if ((lineInput.x1() != lineInput.x2()) && (lineInput.y1() != lineInput.y2()))
	{
		double dwK = (double)lineInput.dy() / (double)lineInput.dx();
		double dwB = lineInput.y1() - dwK * lineInput.x1();

		//点到直线的垂线与直线成90度角，则两个向量乘积的结果为0；
		//计算点到直线的垂线交点
		dPoint_X = (double)(ptVector_Line.x() * ptInput.x() + ptVector_Line.y() * ptInput.y() - ptVector_Line.y() * dwB) / (double)(ptVector_Line.x() + dwK * ptVector_Line.y());
		dPoint_Y = dwK * dPoint_X + dwB;
	}
	else if (lineInput.y1() == lineInput.y2())
	{
		dPoint_X = lineInput.x1();
		dPoint_Y = lineInput.y1();
	}
	else
	{
		dPoint_X = 0;
		dPoint_Y = 0;
	}

	dwDis_Output = std::sqrt(std::powf(dPoint_X - ptInput.x(), 2) + std::powf(dPoint_Y - ptInput.y(), 2));
	return dwDis_Output;
}

void CGlobalUnit::Get_Lidar_Scan_Line(const QList<GT_Lidar_Data> data_Array_Input)
{
	if (data_Array_Input.size() == 0)
	{
		m_dRos_SprayPaint_Chasis_Angle_fromWorkwall = 0;
		m_dRos_SprayPaint_Chasis_Dis_fromLeftwall = 0;
		m_dRos_SprayPaint_Chasis_Dis_fromWorkwall = 0;
		return;
	}

	m_nLidar_Points_Array.clear();

	for (int i = 0; i < data_Array_Input.size(); i++)
	{
		GT_Lidar_Data data_Out = data_Array_Input.at(i);
		m_nLidar_Points_Array.push_back(data_Out.scan_Point);
	}

	int iIndex_Turning = Get_Scan_Turning(data_Array_Input);
	if (iIndex_Turning < 0)
	{
		return;
	}
	GT_Lidar_Data data_Turning = data_Array_Input.at(iIndex_Turning);
	m_ptLidar_Turning = data_Turning.scan_Point;


	QList<GT_Lidar_Data> line_Data_Array;
	for (int i = 0; i < data_Array_Input.size(); i++)
	{
		GT_Lidar_Data data_Temp = data_Array_Input.at(i);
		if ((data_Temp.scan_Angle <= data_Turning.scan_Angle) && ((data_Temp.scan_Angle >= 0)))
		{
			line_Data_Array.push_back(data_Temp);
		}
	}

	std::vector<cv::Point> lidar_Points_Array;
	for (int i = 0; i < line_Data_Array.size(); i++)
	{
		QPointF pt_scan = line_Data_Array.at(i).scan_Point;
		cv::Point pt_Temp(pt_scan.x(), pt_scan.y());
		lidar_Points_Array.push_back(pt_Temp);
	}

	cv::Vec4f line_para;
	cv::fitLine(lidar_Points_Array, line_para, CV_DIST_L2, 0, 0.01, 0.01);

	double dw_X_0 = line_para[2];
	double dw_Y_0 = line_para[3];
	double dw_K = line_para[1] / line_para[0];
	//计算直线的端点(y = k(x - x0) + y0) 

	QPointF pt_A(0, -dw_K * dw_X_0 + dw_Y_0);

	double dw_B_X = m_ptLidar_Turning.x();
	QPointF pt_B(dw_B_X, dw_K * (dw_B_X - dw_X_0) + dw_Y_0);

	m_nLidar_Line = QLineF(pt_A, pt_B);
	QLineF line_Orange(QPointF(0, 0), QPointF(1, 0));

	double dw_Angle = m_nLidar_Line.angleTo(line_Orange);
	if (dw_Angle > 180)
	{
		m_dRos_SprayPaint_Chasis_Angle_fromWorkwall = dw_Angle - 360;
	}
	else
	{
		m_dRos_SprayPaint_Chasis_Angle_fromWorkwall = dw_Angle;
	}

	m_dRos_SprayPaint_Chasis_Dis_fromLeftwall = m_nLidar_Line.length();

	m_dRos_SprayPaint_Chasis_Dis_fromWorkwall = Distance_From_Point_To_Line(m_nLidar_Line, QPointF(0, 0));
}

void CGlobalUnit::Calc_Ros_SprayPaint_Param()
{
	m_dRos_SprayPaint_Dis_MovedBy_LiftPlat = (1 - m_dRos_SprayPaint_Ver_Overlap) * m_dRos_SprayPaint_Ver_WorkDis;

	m_dRos_SprayPaint_Dis_MovedBy_Chasis = (1 - m_dRos_SprayPaint_Hor_Overlap) * m_dRos_SprayPaint_Hor_WorkDis;

	m_iRos_SprayPaint_Count_MovedBy_LiftPlat = (m_dLaserMeasure_Distance + m_nChasisInfo.iHeight_LiftPlat - m_dRos_SprayPaint_LiftPlat_InitPos - 100) / m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;

	m_iRos_SprayPaint_Count_MovedBy_Chasis = (m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall - m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall) / m_dRos_SprayPaint_Dis_MovedBy_Chasis;

	m_dRos_SprayPaint_LiftPlat_MaxPos = m_dRos_SprayPaint_LiftPlat_InitPos + m_dRos_SprayPaint_Dis_MovedBy_LiftPlat * m_iRos_SprayPaint_Count_MovedBy_LiftPlat;

}

void CGlobalUnit::Set_Ros_SprayPaint_Chasis_RotateAdjust()
{
	//每次循环运动的初始化调整---自转调整
	int iSpeed_Left = m_iLineFollowSet_SpeedRate;
	int iSpeed_Right = m_iLineFollowSet_SpeedRate;
	if (m_bIs_Lidar_Data_Valid)
	{
		if (m_dRos_SprayPaint_Chasis_Angle_fromWorkwall > m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall)
		{
			Set_Chasis_Move_Rotate_Right(iSpeed_Left, iSpeed_Right);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis RotateAdjust Right", DIT_Normal);
		}
		else if (m_dRos_SprayPaint_Chasis_Angle_fromWorkwall < -m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall)
		{
			Set_Chasis_Move_Rotate_Left(iSpeed_Left, iSpeed_Right);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis RotateAdjust Left", DIT_Normal);
		}
		else
		{
			Set_Chasis_Stop();
			m_nAutoRun_NowStatus = ARS_Ros_Chasis_SideswayAdjust;
		}
	}
	else
	{
		Set_Chasis_Stop();
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Chasis_SideswayAdjust()
{
	//每次循环运动的初始化调整---平移调整
	int iSidesway_Speed = 0;
	if (m_iLineFollowSet_SpeedRate == 1)
	{
		iSidesway_Speed = 2;
	}
	else
	{
		iSidesway_Speed = m_iLineFollowSet_SpeedRate;
	}

	if (m_bIs_Lidar_Data_Valid)
	{
		//计算当前实际测量的底盘到工作墙面的距离与设定的参数阈值的差值
		double dwChasis_Dis_Offset_fromworkWall = m_dRos_SprayPaint_Chasis_Dis_fromWorkwall - m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall;

		if (dwChasis_Dis_Offset_fromworkWall > m_dRos_SprayPaint_Dis_Precision)
		{
			Set_Chasis_Move_Normal_Forward(iSidesway_Speed, iSidesway_Speed);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis SideswayAdjust Forward", DIT_Normal);
		}
		else if (dwChasis_Dis_Offset_fromworkWall < -m_dRos_SprayPaint_Dis_Precision)
		{
			Set_Chasis_Move_Normal_Backoff(iSidesway_Speed, iSidesway_Speed);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis SideswayAdjust Backoff", DIT_Normal);
		}
		else
		{
			Set_Chasis_Stop();
			if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_Chasis_Left;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_Chasis_Right;
			}
		}
	}
	else
	{
		Set_Chasis_Stop();
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Chasis_Left()
{
	if (m_bIs_Lidar_Data_Valid)
	{
		double dwChasis_Dis_Offset_fromLeftwall = m_dRos_SprayPaint_Chasis_Dis_fromLeftwall - m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall;

		if (dwChasis_Dis_Offset_fromLeftwall < -m_dRos_SprayPaint_Dis_Precision)
		{
			Set_Chasis_Move_Normal_Right(m_iChasis_Left_TargetSpeed, m_iChasis_Right_TargetSpeed);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis Move Right", DIT_Normal);
		}
		else if (dwChasis_Dis_Offset_fromLeftwall > m_dRos_SprayPaint_Dis_Precision)
		{
			Set_Chasis_Move_Normal_Left(m_iChasis_Left_TargetSpeed, m_iChasis_Right_TargetSpeed);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis Move Left", DIT_Normal);
		}
		else
		{
			Set_Chasis_Stop();
			m_nAutoRun_NowStatus = ARS_Ros_LiftPlat_Ready;
		}
	}
	else
	{
		Set_Chasis_Stop();
	}	
}

void CGlobalUnit::Set_Ros_SprayPaint_Chasis_Right()
{
	if (m_bIs_Lidar_Data_Valid)
	{
		double dwChasis_Target_Dis_fromLeftwall = m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall + (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis - 1) * m_dRos_SprayPaint_Dis_MovedBy_Chasis;

		if (m_dRos_SprayPaint_Chasis_Dis_fromLeftwall < dwChasis_Target_Dis_fromLeftwall)
		{
			Set_Chasis_Move_Normal_Right(m_iChasis_Left_TargetSpeed, m_iChasis_Right_TargetSpeed);
			Write_Debug_Info("Ros SprayPaintSet --- Chasis Move Right", DIT_Normal);
		}
		else
		{
			Set_Chasis_Stop();
			m_nAutoRun_NowStatus = ARS_Ros_LiftPlat_Ready;
		}
	}
	else
	{
		Set_Chasis_Stop();
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_LiftPlat_Ready()
{
	int iRet = m_iRos_SprayPaint_Current_Count_MovedBy_Chasis % 2;
	if (iRet == 0)
	{
		Set_Ros_SprayPaint_LiftPlat_Ready_evenNumber();
	}
	else
	{
		Set_Ros_SprayPaint_LiftPlat_Ready_oddNumber();
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_LiftPlat_Ready_evenNumber()
{
	int iPos_Begin = m_dRos_SprayPaint_LiftPlat_InitPos;
	int iPos_Target = iPos_Begin + m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat * m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info(QString::fromLocal8Bit("喷漆方案---底盘移动偶数次---升降平台到达指定位置"), DIT_Normal);

		if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == 0)
		{
			//底盘移动偶数次时，若底盘当前移动次数为0，则执行工作位置 1 ~ 3 的操作；否则，执行其它工作位置的操作
			if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_1;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_3;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_2;
			}
		}
		else if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == m_iRos_SprayPaint_Count_MovedBy_Chasis + 2)
		{
			//底盘移动偶数次时，若底盘当前移动次数为 最大移动次数+2，则执行工作位置 7 ~ 9 的操作；否则，执行工作位置 4 ~ 6 的操作
			if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_7;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_9;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_8;
			}
		}
		else
		{
			if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_6;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_4;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_5;
			}
		}
		
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_LiftPlat_Ready_oddNumber()
{
	int iPos_Begin = m_dRos_SprayPaint_LiftPlat_InitPos + m_iRos_SprayPaint_Count_MovedBy_LiftPlat * m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Target = iPos_Begin - m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat * m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;
	int iPos_Cur = m_nChasisInfo.iHeight_LiftPlat;

	if (iPos_Cur == iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Stop;
		Write_Debug_Info(QString::fromLocal8Bit("喷漆方案---底盘移动奇数次---升降平台到达指定位置"), DIT_Normal);

		if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == m_iRos_SprayPaint_Count_MovedBy_Chasis + 2)
		{
			//底盘移动奇数次时，若底盘当前移动次数为 最大移动次数+2，则执行工作位置 7 ~ 9 的操作；否则，执行工作位置 4 ~ 6 的操作
			if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_9;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_7;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_8;
			}
		}
		else
		{
			if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == 0)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_4;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat == m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_6;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_SprayPaint_Pos_5;
			}
		}
	}
	else if (iPos_Cur < iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Up;
	}
	else if (iPos_Cur > iPos_Target)
	{
		m_nLiftPlat_NowStatus = LPS_Down;
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_1()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 1 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_1;
			Write_Debug_Info("Ros SprayPaint Pos 1 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 1 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_2()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 2 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_2;
			Write_Debug_Info("Ros SprayPaint Pos 2 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 2 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_3()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 3 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_3;
			Write_Debug_Info("Ros SprayPaint Pos 3 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 3 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_4()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 4 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_4;
			Write_Debug_Info("Ros SprayPaint Pos 4 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 4 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_5()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 5 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_5;
			Write_Debug_Info("Ros SprayPaint Pos 5 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 5 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_6()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 6 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_6;
			Write_Debug_Info("Ros SprayPaint Pos 6 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 6 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_7()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 7 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_7;
			Write_Debug_Info("Ros SprayPaint Pos 7 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 7 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_8()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 8 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_8;
			Write_Debug_Info("Ros SprayPaint Pos 8 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 8 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_Pos_9()
{
	if (m_bIs_Ros_Work_Finished && m_bIs_Ros_SprayPaint_RosWork)
	{
		Set_Ros_SprayPaint_SingleWork_Finished();
		Write_Debug_Info("Ros SprayPaint Pos 9 Finished Work", DIT_Normal);
	}
	else
	{
		if (m_bIs_Ros_Work_Finished)
		{
			m_nRos_Work_Pos_Status = RWPS_Pos_9;
			Write_Debug_Info("Ros SprayPaint Pos 9 Begin Work", DIT_Normal);
		}
		else
		{
			m_nRos_Work_Pos_Status = RWPS_Working;
			m_bIs_Ros_SprayPaint_RosWork = true;
			Write_Debug_Info("Ros SprayPaint Pos 9 Working", DIT_Normal);
		}
	}
}

void CGlobalUnit::Set_Ros_SprayPaint_SingleWork_Finished()
{
	m_bIs_Ros_SprayPaint_RosWork = false;
	m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat++;

	if (m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat > m_iRos_SprayPaint_Count_MovedBy_LiftPlat)
	{
		//若当前升降平台移动次数达到指定次数，则判断是否需要继续移动机器人底盘；否则继续
		m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat = 0;
		m_iRos_SprayPaint_Current_Count_MovedBy_Chasis++;

		if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis > m_iRos_SprayPaint_Count_MovedBy_Chasis + 2)
		{
			//若当前底盘移动次数达到指定次数，即达到 计算的最大移动次数+3，则停止；否则继续开始下一轮循线运动
			m_iRos_SprayPaint_Current_Count_MovedBy_Chasis = 0;
			m_nAutoRun_NowStatus = ARS_Idle;
		}
		else
		{
			if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == 1)
			{
				//若底盘当前移动次数为 1，即机器人当前在左边阴角位置，执行工作位置4的操作，不需要调整机身底盘；否则矫正机身底盘
				m_nAutoRun_NowStatus = ARS_Ros_LiftPlat_Ready;
			}
			else if (m_iRos_SprayPaint_Current_Count_MovedBy_Chasis == m_iRos_SprayPaint_Count_MovedBy_Chasis + 2)
			{
				//若底盘当前移动次数为 计算的最大次数+2，即机器人当前在右边阴角位置，执行工作位置7的操作，不需要调整机身底盘；否则矫正机身底盘
				m_nAutoRun_NowStatus = ARS_Ros_LiftPlat_Ready;
			}
			else
			{
				m_nAutoRun_NowStatus = ARS_Ros_Chasis_RotateAdjust;
			}
		}
	}
	else
	{
		m_nAutoRun_NowStatus = ARS_Ros_LiftPlat_Ready;
	}
}


