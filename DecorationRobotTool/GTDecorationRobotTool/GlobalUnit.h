

#include "HDLC/ChasisNet.h"
#include "HDLC/RosplatNet.h"
#include "HDLC/URRobotArmNet.h"
#include "HDLC/MotorModbus.h"
#include "HDLC/FindLine.h"

#include "Commen/QGTPoint3D.h"


#include <Urg_driver.h>

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>


#include <mmsystem.h>

#include <QDir>
#include <QSettings>
#include <QLibrary>
#include <QDebug>
#include <QShortcut>
#include <QMessageBox>
#include <QIODevice>

#include <tchar.h>
#include <string>


using namespace cv;
using namespace std;

#pragma comment (lib,"Winmm.lib")

#pragma once

const double GT_PI = 3.1415926;
const double GT_Ang = -CV_PI / 4;   //从标准坐标系到机械臂基坐标系的旋转角度（满足右手定则）
const byte GT_Chasis_Device_Addr = 0x01;


enum GT_LOGIN_STATE
{
	LS_Nobody = 0, LS_Developer, LS_Customer
};

enum Debug_Info_Type
{
	DIT_Normal  = 0, DIT_Warning, DIT_Error
};

enum Joy_Button_Status
{
	JBS_Idle = 0, JBS_A, JBS_B, JBS_X, JBS_Y, JBS_LB, JBS_RB, JBS_LT, JBS_RT, JBS_BACK, JBS_START, JBS_LOGO, JBS_A_B, JBS_A_X, JBS_A_Y, JBS_B_X, JBS_B_Y, JBS_A_B_X, JBS_A_B_Y
};

enum Joy_POV_Status
{
	JPS_Center = 0, JPS_Forward, JPS_Backward, JPS_Leftward, JPS_Rightward
};

enum GT_SystemSet_Type       //系统设置的类型
{
	SST_Chasis = 0, SST_LiftPlat, SST_Robot, SST_Communication, SST_DemoPlan, SST_LineFollow, SST_Structure, SST_DrawLine, SST_Tiling, SST_All
};

enum GT_Chasis_Move_Type  //底盘运动方式
{
	CMT_Idle = 0, CMT_NORMAL_Forward, CMT_NORMAL_Backoff, CMT_NORMAL_Left, CMT_NORMAL_Right, CMT_ROTATE_Right, CMT_ROTATE_Left, 
	CMT_ROTATE, CMT_LinkRod_Up, CMT_LinkRod_Down, CMT_Electromagnet_On, CMT_Electromagnet_Off, CMT_Stop
};

enum GT_LiftPlat_Status
{
	LPS_Read = 0, LPS_Up, LPS_Down, LPS_Stop
};

enum GT_URRobotArm_Status
{
	UR_Space_X = 0, UR_Space_Y, UR_Space_Z, UR_Space_U, UR_Space_V, UR_Space_W, UR_Joint_X, UR_Joint_Y, UR_Joint_Z, UR_Joint_U, UR_Joint_V, UR_Joint_W
};

enum GT_Ros_Work_Position_Status
{
	RWPS_Idle = 0, RWPS_Pos_1, RWPS_Pos_2, RWPS_Pos_3, RWPS_Pos_4, RWPS_Pos_5, RWPS_Pos_6, RWPS_Pos_7, RWPS_Pos_8, RWPS_Pos_9, RWPS_Working
};

enum GT_Auto_Run_Status
{
	ARS_Idle = 0, ARS_LineFollow_RotateAdjust, ARS_LineFollow_SideswayAdjust, ARS_LineFollow_Forward, ARS_LineFollow_Backoff, ARS_Structure_Test, ARS_Structure_Burnish, ARS_Structure_InitPos, ARS_DrawLine_Begin, ARS_DrawLine_To_LiftPlat_Pos_A, ARS_DrawLine_From_topLeft, ARS_DrawLine_To_bottomLeft, 
	ARS_DrawLine_To_bottomRight, ARS_DrawLine_To_topRight, ARS_DrawLine_To_LiftPlat_Pos_B, ARS_DrawLine_To_topLeft, ARS_DrawLine_To_LiftPlat_Pos_C, ARS_DrawLine_End, ARS_Tiling_PickMateriel_Begin, ARS_Tiling_Materiel_Picking, ARS_Tiling_PickMateriel_End, ARS_Tiling_Paste_Begin, ARS_Tiling_Paste_Near_Begin, 
	ARS_Tiling_Paste, ARS_Tiling_Paste_Near_End, ARS_Tiling_Paste_End, ARS_SprayPaint_LiftPlat_Ready, ARS_SprayPaint_Robot_Pos_A, ARS_SprayPaint_Robot_Pos_B, ARS_SprayPaint_Robot_Pos_C, ARS_SprayPaint_Robot_Pos_D, ARS_SprayPaint_VerInsideCorner_Robot_A, ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin, 
	ARS_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End, ARS_SprayPaint_VerInsideCorner_Robot_B, ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin, ARS_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End, ARS_SprayPaint_HorInsideCorner_Work_Robot_A, ARS_SprayPaint_HorInsideCorner_Work_Robot_B,
	ARS_SprayPaint_HorInsideCorner_Work_Robot_C, ARS_SprayPaint_HorInsideCorner_Work_Robot_D,

	ARS_Ros_Chasis_RotateAdjust, ARS_Ros_Chasis_SideswayAdjust, ARS_Ros_Chasis_Left, ARS_Ros_Chasis_Right, ARS_Ros_LiftPlat_Ready, ARS_Ros_SprayPaint_Pos_1, ARS_Ros_SprayPaint_Pos_2, ARS_Ros_SprayPaint_Pos_3, ARS_Ros_SprayPaint_Pos_4, ARS_Ros_SprayPaint_Pos_5, ARS_Ros_SprayPaint_Pos_6, 
	ARS_Ros_SprayPaint_Pos_7, ARS_Ros_SprayPaint_Pos_8, ARS_Ros_SprayPaint_Pos_9, ARS_Ros_SprayPaint_SingleWork_Finished
};

struct GT_CHASIS_INFO
{
	int iSpeed_LeftWheel;   //左轮速度
	int iSpeed_RightWheel;  //右轮速度
	int iAngle_LeftWheel;   //左轮旋转角度
	int iAngle_RightWheel;  //右轮旋转角度
	int iDis_LeftWheel;     //左轮行程
	int iDis_RightWheel;    //左轮行程
	int iHeight_LiftPlat;   //升降平台高度（由拉线编码器读出）
	GT_CHASIS_INFO()
	{
		iSpeed_LeftWheel = 0;
		iSpeed_RightWheel = 0;
		iAngle_LeftWheel = 0;
		iAngle_RightWheel = 0;
		iDis_LeftWheel = 0;
		iDis_RightWheel = 0;
		iHeight_LiftPlat = 0;
	}

	~GT_CHASIS_INFO()
	{};
};

struct GT_RobotArm_Pose
{
	double dwX;
	double dwY;
	double dwZ;
	double dwU;
	double dwV;
	double dwW;
	GT_RobotArm_Pose()
	{
		dwX = 0.00;
		dwY = 0.00;
		dwZ = 0.00;
		dwU = 0.00;
		dwV = 0.00;
		dwW = 0.00;
	}
	~GT_RobotArm_Pose()
	{};
};


struct GT_Robot_Tcp_Force
{
	int iForce_1;
	int iForce_2;
	int iForce_3;
	int iForce_4;
};


struct GT_Lidar_Data
{
	int scan_Index;
	double scan_Flag;
	double scan_Angle;
	double scan_Distance;
	QPointF scan_Point;
};


class CGlobalUnit
{
public:
	CGlobalUnit();
	virtual ~CGlobalUnit();


public:

	QString GetActualDate();      //获取实时的日期

	QString GetActualTime();      //获取实时的时间

	void Write_Debug_Info(const QString strInfo_Input, Debug_Info_Type iType);  //输出调试信息

	void Write_Log_Info(const QString strInfo_Input);   //输出日志信息

	void putSystemSetting(bool bIsRead);   //读写配置文件参数

	/*------------------------------------基本设置模块---------------------------------------*/
	bool SetConnect();         //连接各个模块
	bool SetDisConnect();      //断开与各个模块的连接
	bool IsChasisConnect();
	bool IsLiftPlatConnect();
	bool IsRobotConnect();
	bool IsRosConnect();
	bool IsLidarConnect();
	bool IsLaserMeasureConnect();
	bool IsJoyHandleConnect();
	/*------------------------------------基本设置模块---------------------------------------*/

	/*----------------------Chasis（底盘）运动模块-----------------------*/
	int Translate16ToInt(const byte high_Input, const byte low_Input); //将从底盘模块接收到的数据从16进制转换成常用int类型
	bool IsValidChasisAngle(const int iLeftAngle_Input, const int iRightAngle_Input, const int iAngleOffset_Input); //判断舵轮旋转角度是否达到需求的角度
	
	bool Get_Chasis_ActualInfo();
	bool Set_Chasis_RotatedAngle(const int iAngle_Left_Input, const int iAngle_Right_Input);          //设置底盘舵轮的旋转角度 (角度范围10~350)
	bool Set_Chasis_MoveSpeed(const int iSpeed_Left, const int iSpeed_Right);                         //设置底盘舵轮的移动速度 (速度有正负)
	bool Set_Chasis_LinkRod_MoveUpOrDown(const int iRodMotor_Speed);                                  //设置推杆电机 (速度有正负)
	bool Set_Chasis_Electromagnet_Enable(bool bIsEnable);                                             //设置电磁铁使能
	
	bool Set_Chasis_Move_Normal_Forward(const int iSpeed_Left_Input, const int iSpeed_Right_Input);   //正常前进
	bool Set_Chasis_Move_Normal_Backoff(const int iSpeed_Left_Input, const int iSpeed_Right_Input);   //正常后退
	bool Set_Chasis_Move_Normal_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input);      //正常左移
	bool Set_Chasis_Move_Normal_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input);     //正常右移

	bool Set_Chasis_Move_Rotate_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input);     //顺时针旋转
	bool Set_Chasis_Move_Rotate_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input);      //逆时针旋转
	bool Set_Chasis_Move_Rotate();                                                                    //仅旋转角度

	bool Set_Chasis_Stop();                                                                           //保持当前舵轮角度并停止运行
	/*----------------------Chasis（底盘）运动模块-----------------------*/



	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/
	bool IsLiftPlatArrivePos(const int iPos_Actual, const int iPos_Target);        //判断升降平台是否到达指定位置
	bool Get_LiftPlat_ActualInfo();                                                //获取升降平台模块的电机的实时信息
	bool Set_LiftPlat_MotorEnable(bool bEnable);                                   //设置升降平台模块的电机使能
	bool Set_LiftPlat_Move_UpOrDown(GT_LiftPlat_Status iStatus);                   //设置升降平台以目标转速上升或下降
	bool Set_LiftPlat_MoveTo_TargetPos(const int iPos_Begin, const int iPos_End);  //设置升降平台到达指定高度
	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/


	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/
	bool IsRobotArrivePos(GT_RobotArm_Pose rInfo_Input);                       //判断机械臂是否到达指定姿态
	bool IsRobotArrivePos(const QGTPoint3D ptInput);                           //判断机械臂是否到达指定坐标点
	bool IsRobotArriveAngle(GT_RobotArm_Pose rInfo_Input);                     //判断机械臂是否到达指定关节角度
	void Get_Robot_ActualInfo();                                               //获取当前机械手的实时信息
	bool Set_Robot_Move_Normal(GT_URRobotArm_Status iStatus, int iDirection);  //机械手坐标控制及单轴旋转控制
	bool Set_Robot_Stop();                                                     //设置机械手停止运动
	bool Set_Robot_MoveTo_Target_SpacePos(GT_RobotArm_Pose rInfo_Input);       //设置机械手运动至目标空间位置
	bool Set_Robot_MoveTo_Target_SpacePos(const QGTPoint3D ptInput);           //设置机械手运动至目标空间坐标点
	bool Set_Robot_MoveTo_Target_JointAngle(GT_RobotArm_Pose rInfo_Input);     //设置机械手运动至目标关节角度
	bool Set_Robot_Load_Program();
	bool Set_Robot_Start_Program();
	bool Set_Robot_Stop_Program();
	bool Set_Robot_uoload_Prog();
	bool Get_Robot_TcpForce();
	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/



	/*--------------------------------------------------Ros平台--------------------------------------------------*/
	bool Set_Ros_Work();
	bool Get_Ros_Return_Info();
	/*--------------------------------------------------Ros平台--------------------------------------------------*/



	/*-------------------------------------------------雷达控制模块----------------------------------------------*/
	bool Set_Lidar_Connect();                                     //连接激光雷达
	bool Set_Lidar_DisConnect();                                  //断开激光雷达
	bool Set_Lidar_Begin_Scan();                                  //开始雷达扫描
	bool Set_Lidar_End_Scan();                                    //结束雷达扫描
	bool Get_Lidar_ScanData();                                    //获取雷达扫描的数据

	/*-------------------------------------------------雷达控制模块----------------------------------------------*/



	/*-------------------------------------------------激光测距模块----------------------------------------------*/
	bool Set_Laser_Measure();
	/*-------------------------------------------------激光测距模块----------------------------------------------*/



	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/
	bool Is_JoyHandle_Valid();                                 //判断游戏手柄是否可用
	bool Get_JoyHandle_ActualInfo();                           //获取游戏手柄当前的状态信息
	void Set_JoyHandle_Control();
	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/



	/*-------------------------------------------DemoPlan（演示方案）-------------------------------------------*/
	void Set_Run_DemoPlan_A();   //1、循线(沿激光线前行到指定位置)
	void Set_Run_DemoPlan_B();   //1、循线(沿激光线前行到指定位置) 2、结构光检测(结构光投影光栅条纹检测墙面上的缺陷点) 3、打磨
	void Set_Run_DemoPlan_C();   //1、画线(机械臂模拟装修前画线工艺，在墙面上画出一个矩形框)
	void Set_Run_DemoPlan_D();   //1、贴瓷砖(机械臂从料盒中取料后将瓷砖贴在墙面上)
	void Set_Run_DemoPlan_E();   //1、循线(沿激光线前行到指定位置) 2、升降平台上升到指定位置 3、机械臂到达指定位置喷漆 
	void Set_Run_DemoPlan_F();   //1、循线(使用激光雷达) 2、升降平台上升到指定位置 3、机械臂到达指定位置喷漆 
	void Set_DemPlan_Run();      //运行演示方案
	void Set_DemPlan_Stop();     //停止演示方案
	/*-------------------------------------------DemoPlan（演示方案）-------------------------------------------*/



	/*-------------------------------------------LineFollow（循线）演示-------------------------------------------*/
	void Get_LineFollow_ActualInfo();                          //获取循线运动的相机反馈的实时信息（实时图像、偏移角度、偏移距离）
	void Set_LineFollow_RotateAdjust();                        //循线运动---初始化时的自转调整
	void Set_LineFollow_SideswayAdjust();                      //循线运动---初始化时的平移调整
	void Set_LineFollow_Forward();                             //循线运动---前进
	void Set_LineFollow_Backoff();                             //循线运动---后退
	/*-------------------------------------------LineFollow（循线）演示-------------------------------------------*/


	/*-------------------------------------------Structure（结构光检测）演示-------------------------------------------*/
	bool Init_Structure_Dll();                                 //结构光检测---加载Dll
	void Calc_Structure_Camera_R_And_T();                      //结构光检测---计算出相机坐标系到世界坐标系的转换矩阵
	void Calc_Structure_Robot_R_And_T();                       //结构光检测---计算出世界坐标系到机械臂基坐标系的转换矩阵
	void Calc_Structure_R_And_T();                             //结构光检测---计算出相机坐标系到机械臂基坐标系的转换矩阵
	void Set_Structure_Calibrat();                             //结构光检测---进行系统标定
	
	void Set_Structure_Test();                                 //结构光检测---开始检测缺陷点
	void Set_Structure_Burnish();                              //结构光检测---打磨
	void Set_Structure_InitPos();                              //结构光检测---机械臂移动到零点位置
	/*-------------------------------------------Structure（结构光检测）演示-------------------------------------------*/


	/*-------------------------------------------DrawLine（画线）演示-------------------------------------------*/
	void Calc_DrawLine_RectPos();                              //画线---计算出画线时需要绘制的矩形的四个顶点坐标
	void Set_DrawLine_Begin();                                 //画线---机械臂移动到零点位置

	void Set_DrawLine_LiftPlat_Pos_A();                        //画线---升降平台移动到 A 位置（即最低点）

	void Set_DrawLine_From_topLeft();                          //画线---机械臂移动到矩形开始位置（即矩形左上顶点）
	void Set_DrawLine_To_bottomLeft();                         //画线---机械臂移动到矩形左下顶点
	void Set_DrawLine_To_bottomRight();                        //画线---机械臂移动到矩形右下顶点
	void Set_DrawLine_To_topRight();                           //画线---机械臂移动到矩形右上顶点

	void Set_DrawLine_LiftPlat_Pos_B();                        //画线---升降平台移动到 B 位置（即最高点）

	void Set_DrawLine_To_topLeft();                            //画线---机械臂移动到矩形结束位置（即矩形左上顶点）

	void Set_DrawLine_LiftPlat_Pos_C();                        //画线---升降平台移动到 C 位置（即最低点）

	void Set_DrawLine_End();                                   //画线---机械臂移动到零点位置
	/*-------------------------------------------DrawLine（画线）演示-------------------------------------------*/



	/*-------------------------------------------Tiling（贴瓷砖）演示-------------------------------------------*/
	void Calc_Tiling_MaterielAndPaste_Pos();
	void Set_Tiling_PickMateriel_Begin();                      //贴瓷砖---取料开始---机械臂移动到取料初始位置 
	void Set_Tiling_MaterielPos();                             //贴瓷砖---正在取料---机械臂移动到物料的位置
	void Set_Tiling_PickMateriel_End();                        //贴瓷砖---取料结束---机械臂移动到取料初始位置
	void Set_Tiling_Paste_Begin();                             //贴瓷砖---粘贴开始---机械臂移动到粘贴物料的初始位置
	void Set_Tiling_PastePos_Near_Begin();                     //贴瓷砖---机械臂移动到指定的靠近粘贴物料的位置
	void Set_Tiling_PastePos();                                //贴瓷砖---正在粘贴---机械臂移动到粘贴物料的位置
	void Set_Tiling_PastePos_Near_End();                       //贴瓷砖---机械臂移动到指定的靠近粘贴物料的位置
	void Set_Tiling_Paste_End();                               //贴瓷砖---粘贴结束---机械臂移动到粘贴物料的初始位置
	/*-------------------------------------------Tiling（贴瓷砖）演示-------------------------------------------*/




	/*-------------------------------------------SprayPaint（喷漆）演示-------------------------------------------*/
	void Calc_SprayPaint_Param();                                           //喷漆方案---计算喷漆方案中各个参数值
	void Calc_SprayPaint_Robot_Pos();

	void Set_SprayPaint_LiftPlat_Ready();                                   //喷漆方案---升降平台准备---升降平台到达指定位置
	void Set_SprayPaint_LiftPlat_Ready_evenNumber();                        //喷漆方案---升降平台准备---底盘移动偶数次时
	void Set_SprayPaint_LiftPlat_Ready_oddNumber();                         //喷漆方案---升降平台准备---底盘移动奇数次时 
	void Set_SprayPaint_Robot_Pos_A();                                      //喷漆方案---升降平台准备---机械臂到达 A 点 
	void Set_SprayPaint_Robot_Pos_B();                                      //喷漆方案---升降平台准备---机械臂到达 B 点 
	void Set_SprayPaint_Robot_Pos_C();                                      //喷漆方案---升降平台准备---机械臂到达 C 点 
	void Set_SprayPaint_Robot_Pos_D();                                      //喷漆方案---升降平台准备---机械臂到达 D 点 

	void Set_SprayPaint_VerInsideCorner_Robot_A();                          //喷漆方案---垂直阴角喷涂---机械臂到达工作位置坐标 A
	void Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin();           //喷漆方案---垂直阴角喷涂---工作位置坐标 A 时，升降平台到达起始点
	void Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End();             //喷漆方案---垂直阴角喷涂---工作位置坐标 A 时，升降平台到达起终点
	void Set_SprayPaint_VerInsideCorner_Robot_B();                          //喷漆方案---垂直阴角喷涂---机械臂到达工作位置坐标 B
	void Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin();           //喷漆方案---垂直阴角喷涂---工作位置坐标 B 时，升降平台到达起始点
	void Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End();             //喷漆方案---垂直阴角喷涂---工作位置坐标 B 时，升降平台到达起终点

	void Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos();                  //喷漆方案---水平阴角喷涂---计算机械臂工作坐标
	void Set_SprayPaint_HorInsideCorner_Work_Robot_A();                     //喷漆方案---水平阴角喷涂---机械臂到达工作位置坐标 A
	void Set_SprayPaint_HorInsideCorner_Work_Robot_B();                     //喷漆方案---水平阴角喷涂---机械臂到达工作位置坐标 B
	void Set_SprayPaint_HorInsideCorner_Work_Robot_C();                     //喷漆方案---水平阴角喷涂---机械臂到达工作位置坐标 C
	void Set_SprayPaint_HorInsideCorner_Work_Robot_D();                     //喷漆方案---水平阴角喷涂---机械臂到达工作位置坐标 D
	/*-------------------------------------------SprayPaint（喷漆）演示-------------------------------------------*/




	/*-------------------------------------------SprayPaint（喷漆）Ros平台演示-------------------------------------------*/
	void Calc_Ros_SprayPaint_Param();                                           //Ros平台喷漆方案---计算喷漆方案中各个参数值

	void Set_Ros_SprayPaint_Chasis_RotateAdjust();                              //Ros平台喷漆方案---根据激光雷达检测结果调整底盘的方向，使其始终垂直于工作墙面
	void Set_Ros_SprayPaint_Chasis_SideswayAdjust();                            //Ros平台喷漆方案---根据激光雷达的检测结果平移底盘，使其与工作墙面始终保持一定的距离

	void Set_Ros_SprayPaint_Chasis_Left();                                      //Ros平台喷漆方案---向左移动
	void Set_Ros_SprayPaint_Chasis_Right();                                     //Ros平台喷漆方案---向右移动

	void Set_Ros_SprayPaint_LiftPlat_Ready();                                   //Ros平台喷漆方案---升降平台准备---升降平台到达指定位置
	void Set_Ros_SprayPaint_LiftPlat_Ready_evenNumber();                        //Ros平台喷漆方案---升降平台准备---底盘移动偶数次时
	void Set_Ros_SprayPaint_LiftPlat_Ready_oddNumber();                         //Ros平台喷漆方案---升降平台准备---底盘移动奇数次时

	void Set_Ros_SprayPaint_Pos_1();
	void Set_Ros_SprayPaint_Pos_2();
	void Set_Ros_SprayPaint_Pos_3();
	void Set_Ros_SprayPaint_Pos_4();
	void Set_Ros_SprayPaint_Pos_5();
	void Set_Ros_SprayPaint_Pos_6();
	void Set_Ros_SprayPaint_Pos_7();
	void Set_Ros_SprayPaint_Pos_8();
	void Set_Ros_SprayPaint_Pos_9();
	void Set_Ros_SprayPaint_SingleWork_Finished();
	/*-------------------------------------------SprayPaint（喷漆）Ros平台演示-------------------------------------------*/

	

private:
	QString GetExePath();  //获取应用程序路径

	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/
	Joy_Button_Status Get_JoyButton_Status(const int iPos);
	Joy_POV_Status Get_JoyPov_Status(const int iPov);
	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/

	QString GetRobotMoveCommend(GT_URRobotArm_Status iStatus, int iDirection);

	bool Parse_Robot_Pressure_Data(const QString strReg_1, const QString strReg_2, QString &strOutput, double &dwOutput); //解析压力传感器的数据

	bool Is_Turning(const QList<GT_Lidar_Data> data_Array_Input, const int iIndex);

	int Get_Scan_Turning(const QList<GT_Lidar_Data> data_Array_Input);

	void Get_Lidar_Scan_Line(const QList<GT_Lidar_Data> data_Array_Input);

	double Distance_From_Point_To_Line(const QLineF lineInput, const QPointF ptInput);

	GT_RobotArm_Pose Translate_Robot_To_Normal_CoordinateSystem(GT_RobotArm_Pose pose_Input);  //将机械臂基坐标系转换成标准的直角坐标系
	QGTPoint3D Translate_Robot_To_Normal_CoordinateSystem(const QGTPoint3D pt_Input);          //将机械臂基坐标系转换成标准的直角坐标系

	GT_RobotArm_Pose Translate_Normal_To_Robot_CoordinateSystem(GT_RobotArm_Pose pose_Input);  //将标准的直角坐标系转换成机械臂基坐标系
	QGTPoint3D Translate_Normal_To_Robot_CoordinateSystem(const QGTPoint3D pt_Input);          //将标准的直角坐标系转换成机械臂基坐标系


public:
	/*------------------------------------基本设置模块---------------------------------------*/
	GT_LOGIN_STATE m_nLoginState;                           //登录状态
	bool m_bIsSelect_Chasis_Connect;                        //是否选择连接底盘
	bool m_bIsSelect_LiftPlat_Connect;                      //是否选择连接升降平台
	bool m_bIsSelect_Robot_Connect;                         //是否选择连接机械手
	bool m_bIsSelect_Ros_Connect;                           //是否选择连接Ros平台
	bool m_bIsSelect_Lidar_Connect;                         //是否选择连接激光雷达
	bool m_bIsSelect_LaserMeasure_Connect;                  //是否选择连接激光测距
	bool m_bIsSelect_JoyHandle_Connect;                     //是否选择连接游戏手柄
	
	bool m_bIsConnect;                                      //是否已经连接
	bool m_bIsShowLog;                                      //是否显示Log

	CRITICAL_SECTION m_nLock;                                  //临界区

	QString m_str_LogInfo;

	CHDLCnet *m_pHdlc_Chasis;                               //用于和底盘控制系统通信的类指针
	QString m_strChasis_IpAddr;                             //底盘模块的Ip地址
	QString m_strChasis_Port;                               //底盘模块的端口

	CMotorModbus *m_pLiftPlatNet;                           //升降平台电机驱动器串口通信类
	int m_iLiftPlat_PortNum;                                //升降平台的端口号
	int m_iLiftPlat_Baudrate;                               //升降平台的波特率

	CURRobotArmNet *m_pRobotNet;                            //用于和机械手模块通信的类指针
	QString m_strRobot_IpAddr;                              //机械手模块的IP地址
	QString m_strRobot_Port;                                //机械手模块的端口

	CHDLCnet *m_pHdlc_Ros;                                  //用于和Ros平台通信的类指针
	QString m_strRos_IpAddr;                                //Ros平台的IP地址
	QString m_strRos_Port;                                  //Ros平台的端口

	qrk::Urg_driver *m_pNet_Lidar;                          //用于和激光雷达通信的类指针
	QString m_strLidar_Port;                                //激光雷达通信串口号
	int m_iLidar_Baudrate;                                  //激光雷达通信波特率

	CSerialPort *m_pNet_LaserMeasure;                       //激光测距模块的通信类指针
	int m_iLaserMeasure_Port;                               //激光测距模块的通信端口号
	int m_iLaserMeasure_Baudrate;                           //激光测距模块的通信波特率

	CSerialPort *m_pRobot_Pressure_Net;                     //机械臂末端用于读取压力传感器的值的通信类指针
	int m_iRobot_Pressure_Port;                             //机械臂末端用于读取压力传感器的值的通信端口
	/*------------------------------------基本设置模块--------------------------------------*/


	/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/
	GT_CHASIS_INFO m_nChasisInfo;                          //底盘运动模块的信息
	GT_Chasis_Move_Type m_nChasis_NowType;                 //底盘模块现在的运行方式

	bool m_bIsChasisInfo_Valid;                            //底盘信息是否有效（即接收到的底盘数据信息是否OK）

	byte m_bzChasisCmd[16];                                //上位机发送给底盘的指令
	int m_iChasis_Left_TargetSpeed;                        //底盘模块左轮运动的目标速度
	int m_iChasis_Right_TargetSpeed;                       //底盘模块右轮运动的目标速度
	int m_iChasis_Left_TargetAngle;                        //底盘模块左轮的目标角度
	int m_iChasis_Right_TargetAngle;                       //底盘模块右轮的目标角度
	/*----------------------------------------------Chasis（底盘）模块------------------------------------------*/

	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/
	Motor_Info m_nLiftPlat_MotorInfo;                    //获取到的电机的信息
	GT_LiftPlat_Status m_nLiftPlat_NowStatus;            //升降平台当前状态
	int m_iLiftPlat_TargetSpeed;                         //升降平台电机的目标转速
	/*-------------------------------------------LiftPlat（升降平台）模块-------------------------------------------*/

	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/
	GT_RobotArm_Pose m_nRobot_Actual_SpacePos;           //机械手当前的空间位置坐标
	GT_RobotArm_Pose m_nRobot_Actual_JointAngle;         //机械手当前的关节角度值
	GT_RobotArm_Pose m_nRobot_Target_SpacePos;           //目标空间位置坐标
	GT_RobotArm_Pose m_nRobot_Target_JointAngle;         //目标关节角度

	GT_Robot_Tcp_Force m_nRobot_Actual_TcpForce;         //机械手当前的Tcp末端的力
	int m_iRobot_Force_Count;

	double m_dRobot_SpeedRate;                           //机械手运动速度
	double m_dRobot_AccelerationRate;                    //机械手运动加速度
	/*-------------------------------------------URRobot（机械手）模块-------------------------------------------*/




	/*--------------------------------------------------Ros平台--------------------------------------------------*/
	GT_Ros_Work_Position_Status m_nRos_Work_Pos_Status;             //Ros平台工作位置状态
	bool m_bIs_Ros_Need_Open_Spraygun;                              //是否需要打开喷枪
	bool m_bIs_Ros_Work_Finished;                                   //Ros平台的单次工作是否完成
	/*--------------------------------------------------Ros平台--------------------------------------------------*/




	/*-------------------------------------------------雷达控制模块----------------------------------------------*/
	int m_iLidar_SearchTurning_Step;                                 //搜寻转折点的点数步长
	int m_iLidar_SearchTurning_Dis_Threshold;                        //搜寻转折点的距离阈值
	int m_iLidar_SearchTurning_Len_Threshold;                        //搜寻转折点的长度阈值

	int m_iLidar_ScanFail_Count;                                     //激光雷达扫描失败的次数

	bool m_bIs_Lidar_Data_Valid;                                     //激光雷达数据是否有效

	QList<QPointF> m_nLidar_Points_Array;
	QPointF m_ptLidar_Turning;
	QLineF m_nLidar_Line;
	/*-------------------------------------------------雷达控制模块----------------------------------------------*/



	/*-------------------------------------------------激光测距模块----------------------------------------------*/
	double m_dLaserMeasure_Distance;
	/*-------------------------------------------------激光测距模块----------------------------------------------*/



	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/
	Joy_Button_Status m_nJoy_Btn_Last_Status;                 //游戏手柄的上一次的按键状态
	Joy_POV_Status m_nJoy_Pov_Last_Status;                    //游戏手柄的上一次的摇杆状态
	Joy_Button_Status m_nJoy_Btn_Status;    //游戏手柄的按键状态
	Joy_POV_Status m_nJoy_Pov_Status;       //游戏手柄的摇杆状态
	QString m_strJoy_Btn_Status;
	QString m_strJoy_Pov_Status;
	bool m_bIs_JoyHandle_Control_Valid;     //是否可以通过游戏手柄控制装修机器人各个模块
	/*-------------------------------------------JoyHandle（游戏手柄）模块-------------------------------------------*/

	
	/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/
	bool m_bIsAutoRun;                                     //是否自动运行
	bool m_bIsLoopRun;                                     //是否循环演示
	int m_iDemoPlanSet_Index;                              //选择的方案序号
	GT_Auto_Run_Status m_nAutoRun_NowStatus;               //自动化工艺流程演示操作当前的状态
	/*-------------------------------------------DemoPlan（演示方案）参数设置-------------------------------------------*/


	/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/
	CFindLine *m_pFindLine;                                //用于寻激光线的找直线类指针
	bool m_bIs_LineFollowInfo_Valid;                       //是否循线运动的相机反馈的实时信息有效
	int m_iLineFollow_InitDis_LeftWheel;                   //底盘开始自动寻线运动时初始的行程值，用于自动寻线的往复运动
	int m_iLineFollow_InitDis_RightWheel;                  //底盘开始自动寻线运动时初始的行程值，用于自动寻线的往复运动
	vector<double> LaserLine_Dis_Offset_Array;
	
	//相机寻线--------------输入参数
	double m_dLineFollowSet_Calibration;                   //相机的标定值
	int m_iLineFollowSet_SearchThreshold;                  //搜索直线的阈值
	int m_iLineFollowSet_MinBinaryThreshold;               //二值化的最小阈值
	int m_iLineFollowSet_MaxBinaryThreshold;               //二值化的最大阈值
	int m_iLineFollowSet_MinContourArea;                   //搜索的最小轮廓面积
	int m_iLineFollowSet_MaxContourArea;                   //搜索的最大轮廓面积 
	double m_dLineFollowSet_AngleRange;                    //偏移角度的误差范围（单位:度）
	double m_dLineFollowSet_DisRange;                      //偏移距离的误差范围（单位:像素）
	int m_iLineFollowSet_TargetDis;                        //底盘运动的目标距离   
	int m_iLineFollowSet_SpeedRate;                        //循线运动时差速运动的速率

	//相机寻线--------------输出参数
	cv::Mat m_nLineFollowSet_ResultImage;                  //循线运动 - 相机反馈的图像
	double m_dLineFollowSet_ResultAngel;                   //循线运动 - 底盘与激光线的偏移角度                 
	double m_dLineFollowSet_ResultDis;                     //循线运动 - 底盘与激光线的偏移距离  
	/*-------------------------------------------LineFollow（循线）参数设置-------------------------------------------*/



	/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/
	typedef void(*StructureCalibrationFun)(double[], double[]);
	StructureCalibrationFun m_fun_Calibration_Get_Camera_R_And_T;

	typedef QWidget*(*StructureDetection_GetPointer_Fun)();
	StructureDetection_GetPointer_Fun m_fun_Structure_GetPointer;

	typedef void(*StructureDetection_StartTest_Fun)();
	StructureDetection_StartTest_Fun m_fun_Structure_StartTest;

	typedef void(*StructureDetection_Display_Fun)(QPixmap);
	StructureDetection_Display_Fun m_fun_Structure_Display;

	typedef void(*PointCloud_FindPoint_Fun)(double[], double[], double[]);
	PointCloud_FindPoint_Fun m_fun_PointCloud_FindPoint;

	QLibrary m_hDll_StructureCalibration;                  //结构光检测系统相机外参数标定模块
	QLibrary m_hDll_StructureDetection;                    //结构光检测系统测试模块
	QLibrary m_hDll_PointCloudModule;                      //结构光检测系统点云处理模块

	double m_dzStructure_Camera_R[9];                      //从摄像机坐标系到世界坐标系的的旋转矩阵
	double m_dzStructure_Camera_T[3];                      //从摄像机坐标系到世界坐标系的的平移矩阵

	double m_dzStructure_Robot_R[9];                       //从机械臂Tcp坐标系到世基坐标系的的旋转矩阵
	double m_dzStructure_Robot_T[3];                       //从机械臂Tcp坐标系到世基坐标系的的平移矩阵

	double m_dzStructure_R[9];                             //从摄像机坐标系到机械臂基坐标系的的旋转矩阵
	double m_dzStructure_T[3];                             //从摄像机坐标系到机械臂基坐标系的的平移矩阵

	double m_dzStructure_Robot_Pos[6];                     //结构光检测到的缺陷点在机械臂基坐标系下的位置

	bool m_bIsStructure_LoadDll;                           //是否已经加载了结构光检测模块的Dll
	
	bool m_bIsStructure_Move;                              //是否已经发送指令给机械臂控制移动
	bool m_bIsStructure_beginTest;                         //是否已经开始进行结构光检测
	GT_RobotArm_Pose m_nStructure_InitPos;                 //机械臂的零点
	/*-------------------------------------------Structure（结构光检测）参数设置-------------------------------------------*/



	/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/
	GT_RobotArm_Pose m_nDrawLine_InitPos;                  //机械臂的零点
	QGTPoint3D m_ptDrawLine_topLeft;                       //机械臂画矩形的左上顶点
	QGTPoint3D m_ptDrawLine_bottomLeft;                    //机械臂画矩形的左下顶点
	QGTPoint3D m_ptDrawLine_bottomRight;                   //机械臂画矩形的右下顶点
	QGTPoint3D m_ptDrawLine_topRight;                      //机械臂画矩形的右上顶点
	bool m_bIsDrawLine_Move;                               //是否已经发送指令给机械臂控制移动
	
	double m_dDrawLine_Width;                              //画线的矩形宽度
	double m_dDrawLine_Height;                             //画线的矩形高度

	int m_iDrawLine_LiftPlat_topPos;                       //升降平台的最高位置
	int m_iDrawLine_LiftPlat_bottomPos;                    //升降平台的最低位置
	/*-------------------------------------------DrawLine（在墙面画基准线）参数设置-------------------------------------------*/


	/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/
	GT_RobotArm_Pose m_nTiling_InitPos;                    //贴瓷砖演示的初始位置
	GT_RobotArm_Pose m_nTiling_InitPos_Materiel;           //拾取物料的初始位置
	GT_RobotArm_Pose m_nTiling_InitPos_Paste;              //粘贴物料的初始位置
	GT_RobotArm_Pose m_nTiling_InitAngle_Materiel;         //拾取物料的初始角度
	GT_RobotArm_Pose m_nTiling_InitAngle_Paste;            //粘贴物料的初始角度

	QGTPoint3D m_ptTiling_MaterielPos;                //物料的坐标位置
	QGTPoint3D m_ptTiling_PastePos;                   //在墙面上粘贴物料的坐标位置

	QList<QGTPoint3D> m_nTiling_MaterielPos_Array;
	QList<QGTPoint3D> m_nTiling_PastePos_Array;

	double m_dTiling_Materiel_Width;                       //瓷砖的宽度
	double m_dTiling_Materiel_Thickness;                   //瓷砖的厚度
	double m_dTiling_Paste_Feed;                           //粘贴瓷砖时机械臂往前的进给量
	int m_iTiling_Materiel_Num;                            //瓷砖的数量
	int m_iTiling_Pressure_Range;                          //机械臂末端压力传感器的阈值

	GT_Robot_Tcp_Force m_nTiling_TcpForce_Init;            //机械臂末端压力传感器的初始压力值
	GT_Robot_Tcp_Force m_nTiling_TcpForce_Paste;           //机械臂末端压力传感器的粘贴物料时的压力值

	int m_iTiling_Count;
	bool m_bIsTiling_Move;                                 //是否已经发送指令给机械臂控制移动
	/*-------------------------------------------Tiling（贴瓷砖）参数设置-------------------------------------------*/




	/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/
	GT_RobotArm_Pose m_nSprayPaint_Robot_InitPos;                               //喷漆方案---机械臂初始坐标位置
	GT_RobotArm_Pose m_nSprayPaintSet_VerInsideCorner_RobotPos_A;               //喷漆方案---垂直阴角喷涂---机械臂姿态 A
	GT_RobotArm_Pose m_nSprayPaintSet_VerInsideCorner_RobotPos_B;               //喷漆方案---垂直阴角喷涂---机械臂姿态 B
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_RobotPos_A;               //喷漆方案---水平阴角喷涂---机械臂姿态 A
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_RobotPos_B;               //喷漆方案---水平阴角喷涂---机械臂姿态 B

	bool m_bIs_SprayPaint_VerInsideCorner_Enable;                               //喷漆方案---是否使能垂直阴角喷涂
	bool m_bIs_SprayPaint_HorInsideCorner_Enable;                               //喷漆方案---是否使能水平阴角喷涂

	int m_iSprayPaint_Count_VerInsideCorner;                                    //喷漆方案---垂直阴角喷涂的次数
	int m_iSprayPaint_Count_HorInsideCorner;                                    //喷漆方案---水平阴角喷涂的次数

	int m_iSprayPaint_Count_MovedBy_Chasis;                                     //喷漆方案---底盘移动次数
	int m_iSprayPaint_Count_MovedBy_LiftPlat;                                   //喷漆方案---升降平台移动次数
	int m_iSprayPaint_Count_MovedBy_Robot;                                      //喷漆方案---机械臂移动次数
	
	double m_dSprayPaint_LiftPlat_InitPos;                                      //喷漆方案---升降平台的初始位置
	double m_dSprayPaint_HorDis_MovedBy_Robot;                                  //喷漆方案---机械臂水平单次移动距离
	double m_dSprayPaint_Width_By_Spray;                                        //喷漆方案---执行器喷枪的工作宽度

	double m_dSprayPaint_Overlap_By_Robot;                                      //喷漆方案---机械臂单次喷涂的重合率
	double m_dSprayPaint_Overlap_By_LiftPlat;                                   //喷漆方案---升降平台单次喷涂的重合率
	double m_dSprayPaint_Overlap_By_Chasis;                                     //喷漆方案---底盘单次喷涂的重合率


	//SprayPaint Work
	int m_iSprayPaint_Current_Count_MovedBy_Chasis;                             //喷漆方案---底盘当前移动的次数
	int m_iSprayPaint_Current_Count_MovedBy_LiftPlat;                           //喷漆方案---升降平台当前移动的次数
	int m_iSprayPaint_Current_Count_MovedBy_Robot;                              //喷漆方案---机械臂当前移动的次数

	int m_iSprayPaint_Current_Count_VerInsideCorner;                            //喷漆方案---垂直阴角当前喷涂的次数
	int m_iSprayPaint_Current_Count_HorInsideCorner;                            //喷漆方案---水平阴角当前喷涂的次数
	
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_A;                             //喷漆方案---正常喷涂---机械臂工作坐标 A
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_B;                             //喷漆方案---正常喷涂---机械臂工作坐标 B
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_C;                             //喷漆方案---正常喷涂---机械臂工作坐标 C
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_D;                             //喷漆方案---正常喷涂---机械臂工作坐标 D

	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A;          //喷漆方案---水平阴角喷涂---机械臂工作坐标 A  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B;          //喷漆方案---水平阴角喷涂---机械臂工作坐标 B  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C;          //喷漆方案---水平阴角喷涂---机械臂工作坐标 C  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D;          //喷漆方案---水平阴角喷涂---机械臂工作坐标 D  


	bool m_bIs_SprayPaint_Robot_Move;

	double m_dSprayPaint_Dis_MovedBy_Chasis;                                    //喷漆方案---底盘单次移动距离
	double m_dSprayPaint_Dis_MovedBy_LiftPlat;                                  //喷漆方案---升降平台单次移动距离
	double m_dSprayPaint_VerDis_MovedBy_Robot;                                  //喷漆方案---机械臂垂直单次移动距离
	/*-------------------------------------------SprayPaintSet（喷漆）参数设置-------------------------------------------*/




	/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/
	double m_dRos_SprayPaint_Dis_Precision;                                         //喷漆方案---距离上的精度误差

	double m_dRos_SprayPaint_LiftPlat_InitPos;                                      //喷漆方案---升降平台的初始位置

	double m_dRos_SprayPaint_Hor_WorkDis;                                           //喷漆方案---单次动作水平工作距离
	double m_dRos_SprayPaint_Ver_WorkDis;                                           //喷漆方案---单次动作垂直工作距离

	double m_dRos_SprayPaint_Hor_Overlap;                                           //喷漆方案---水平方向的喷涂重合率
	double m_dRos_SprayPaint_Ver_Overlap;                                           //喷漆方案---垂直方向的喷涂重合率


	double m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall;                       //喷漆方案---底盘当前与工作墙面的夹角范围
	double m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall;                     //喷漆方案---底盘与工作墙面的距离阈值
	double m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall;                            //喷漆方案---底盘距离左边墙面的最小距离
	double m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall;                            //喷漆方案---底盘距离左边墙面的最大距离


	//Ros SprayPaint Work
	int m_iRos_SprayPaint_Count_MovedBy_Chasis;                                     //喷漆方案---底盘移动次数
	int m_iRos_SprayPaint_Count_MovedBy_LiftPlat;                                   //喷漆方案---升降平台移动次数

	int m_iRos_SprayPaint_Current_Count_MovedBy_Chasis;                             //喷漆方案---底盘当前移动的次数
	int m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat;                           //喷漆方案---升降平台当前移动的次数

	double m_dRos_SprayPaint_LiftPlat_MaxPos;                                       //喷漆方案---升降平台上升的最高位置

	double m_dRos_SprayPaint_Dis_MovedBy_Chasis;                                    //喷漆方案---底盘单次移动距离
	double m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;                                  //喷漆方案---升降平台单次移动距离

	double m_dRos_SprayPaint_Chasis_Angle_fromWorkwall;                             //喷漆方案---底盘当前与工作墙面的夹角
	double m_dRos_SprayPaint_Chasis_Dis_fromLeftwall;                               //喷漆方案---底盘距离左边墙面的距离
	double m_dRos_SprayPaint_Chasis_Dis_fromWorkwall;                               //喷漆方案---底盘与工作墙面的距离

	bool m_bIs_Ros_SprayPaint_RosWork;
	/*-------------------------------------------SprayPaintSet（喷漆）Ros平台参数设置-------------------------------------------*/

	


};

extern CGlobalUnit *g_pGlobalUnit;
