

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
const double GT_Ang = -CV_PI / 4;   //�ӱ�׼����ϵ����е�ۻ�����ϵ����ת�Ƕȣ��������ֶ���
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

enum GT_SystemSet_Type       //ϵͳ���õ�����
{
	SST_Chasis = 0, SST_LiftPlat, SST_Robot, SST_Communication, SST_DemoPlan, SST_LineFollow, SST_Structure, SST_DrawLine, SST_Tiling, SST_All
};

enum GT_Chasis_Move_Type  //�����˶���ʽ
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
	int iSpeed_LeftWheel;   //�����ٶ�
	int iSpeed_RightWheel;  //�����ٶ�
	int iAngle_LeftWheel;   //������ת�Ƕ�
	int iAngle_RightWheel;  //������ת�Ƕ�
	int iDis_LeftWheel;     //�����г�
	int iDis_RightWheel;    //�����г�
	int iHeight_LiftPlat;   //����ƽ̨�߶ȣ������߱�����������
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

	QString GetActualDate();      //��ȡʵʱ������

	QString GetActualTime();      //��ȡʵʱ��ʱ��

	void Write_Debug_Info(const QString strInfo_Input, Debug_Info_Type iType);  //���������Ϣ

	void Write_Log_Info(const QString strInfo_Input);   //�����־��Ϣ

	void putSystemSetting(bool bIsRead);   //��д�����ļ�����

	/*------------------------------------��������ģ��---------------------------------------*/
	bool SetConnect();         //���Ӹ���ģ��
	bool SetDisConnect();      //�Ͽ������ģ�������
	bool IsChasisConnect();
	bool IsLiftPlatConnect();
	bool IsRobotConnect();
	bool IsRosConnect();
	bool IsLidarConnect();
	bool IsLaserMeasureConnect();
	bool IsJoyHandleConnect();
	/*------------------------------------��������ģ��---------------------------------------*/

	/*----------------------Chasis�����̣��˶�ģ��-----------------------*/
	int Translate16ToInt(const byte high_Input, const byte low_Input); //���ӵ���ģ����յ������ݴ�16����ת���ɳ���int����
	bool IsValidChasisAngle(const int iLeftAngle_Input, const int iRightAngle_Input, const int iAngleOffset_Input); //�ж϶�����ת�Ƕ��Ƿ�ﵽ����ĽǶ�
	
	bool Get_Chasis_ActualInfo();
	bool Set_Chasis_RotatedAngle(const int iAngle_Left_Input, const int iAngle_Right_Input);          //���õ��̶��ֵ���ת�Ƕ� (�Ƕȷ�Χ10~350)
	bool Set_Chasis_MoveSpeed(const int iSpeed_Left, const int iSpeed_Right);                         //���õ��̶��ֵ��ƶ��ٶ� (�ٶ�������)
	bool Set_Chasis_LinkRod_MoveUpOrDown(const int iRodMotor_Speed);                                  //�����Ƹ˵�� (�ٶ�������)
	bool Set_Chasis_Electromagnet_Enable(bool bIsEnable);                                             //���õ����ʹ��
	
	bool Set_Chasis_Move_Normal_Forward(const int iSpeed_Left_Input, const int iSpeed_Right_Input);   //����ǰ��
	bool Set_Chasis_Move_Normal_Backoff(const int iSpeed_Left_Input, const int iSpeed_Right_Input);   //��������
	bool Set_Chasis_Move_Normal_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input);      //��������
	bool Set_Chasis_Move_Normal_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input);     //��������

	bool Set_Chasis_Move_Rotate_Right(const int iSpeed_Left_Input, const int iSpeed_Right_Input);     //˳ʱ����ת
	bool Set_Chasis_Move_Rotate_Left(const int iSpeed_Left_Input, const int iSpeed_Right_Input);      //��ʱ����ת
	bool Set_Chasis_Move_Rotate();                                                                    //����ת�Ƕ�

	bool Set_Chasis_Stop();                                                                           //���ֵ�ǰ���ֽǶȲ�ֹͣ����
	/*----------------------Chasis�����̣��˶�ģ��-----------------------*/



	/*-------------------------------------------LiftPlat������ƽ̨��ģ��-------------------------------------------*/
	bool IsLiftPlatArrivePos(const int iPos_Actual, const int iPos_Target);        //�ж�����ƽ̨�Ƿ񵽴�ָ��λ��
	bool Get_LiftPlat_ActualInfo();                                                //��ȡ����ƽ̨ģ��ĵ����ʵʱ��Ϣ
	bool Set_LiftPlat_MotorEnable(bool bEnable);                                   //��������ƽ̨ģ��ĵ��ʹ��
	bool Set_LiftPlat_Move_UpOrDown(GT_LiftPlat_Status iStatus);                   //��������ƽ̨��Ŀ��ת���������½�
	bool Set_LiftPlat_MoveTo_TargetPos(const int iPos_Begin, const int iPos_End);  //��������ƽ̨����ָ���߶�
	/*-------------------------------------------LiftPlat������ƽ̨��ģ��-------------------------------------------*/


	/*-------------------------------------------URRobot����е�֣�ģ��-------------------------------------------*/
	bool IsRobotArrivePos(GT_RobotArm_Pose rInfo_Input);                       //�жϻ�е���Ƿ񵽴�ָ����̬
	bool IsRobotArrivePos(const QGTPoint3D ptInput);                           //�жϻ�е���Ƿ񵽴�ָ�������
	bool IsRobotArriveAngle(GT_RobotArm_Pose rInfo_Input);                     //�жϻ�е���Ƿ񵽴�ָ���ؽڽǶ�
	void Get_Robot_ActualInfo();                                               //��ȡ��ǰ��е�ֵ�ʵʱ��Ϣ
	bool Set_Robot_Move_Normal(GT_URRobotArm_Status iStatus, int iDirection);  //��е��������Ƽ�������ת����
	bool Set_Robot_Stop();                                                     //���û�е��ֹͣ�˶�
	bool Set_Robot_MoveTo_Target_SpacePos(GT_RobotArm_Pose rInfo_Input);       //���û�е���˶���Ŀ��ռ�λ��
	bool Set_Robot_MoveTo_Target_SpacePos(const QGTPoint3D ptInput);           //���û�е���˶���Ŀ��ռ������
	bool Set_Robot_MoveTo_Target_JointAngle(GT_RobotArm_Pose rInfo_Input);     //���û�е���˶���Ŀ��ؽڽǶ�
	bool Set_Robot_Load_Program();
	bool Set_Robot_Start_Program();
	bool Set_Robot_Stop_Program();
	bool Set_Robot_uoload_Prog();
	bool Get_Robot_TcpForce();
	/*-------------------------------------------URRobot����е�֣�ģ��-------------------------------------------*/



	/*--------------------------------------------------Rosƽ̨--------------------------------------------------*/
	bool Set_Ros_Work();
	bool Get_Ros_Return_Info();
	/*--------------------------------------------------Rosƽ̨--------------------------------------------------*/



	/*-------------------------------------------------�״����ģ��----------------------------------------------*/
	bool Set_Lidar_Connect();                                     //���Ӽ����״�
	bool Set_Lidar_DisConnect();                                  //�Ͽ������״�
	bool Set_Lidar_Begin_Scan();                                  //��ʼ�״�ɨ��
	bool Set_Lidar_End_Scan();                                    //�����״�ɨ��
	bool Get_Lidar_ScanData();                                    //��ȡ�״�ɨ�������

	/*-------------------------------------------------�״����ģ��----------------------------------------------*/



	/*-------------------------------------------------������ģ��----------------------------------------------*/
	bool Set_Laser_Measure();
	/*-------------------------------------------------������ģ��----------------------------------------------*/



	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/
	bool Is_JoyHandle_Valid();                                 //�ж���Ϸ�ֱ��Ƿ����
	bool Get_JoyHandle_ActualInfo();                           //��ȡ��Ϸ�ֱ���ǰ��״̬��Ϣ
	void Set_JoyHandle_Control();
	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/



	/*-------------------------------------------DemoPlan����ʾ������-------------------------------------------*/
	void Set_Run_DemoPlan_A();   //1��ѭ��(�ؼ�����ǰ�е�ָ��λ��)
	void Set_Run_DemoPlan_B();   //1��ѭ��(�ؼ�����ǰ�е�ָ��λ��) 2���ṹ����(�ṹ��ͶӰ��դ���Ƽ��ǽ���ϵ�ȱ�ݵ�) 3����ĥ
	void Set_Run_DemoPlan_C();   //1������(��е��ģ��װ��ǰ���߹��գ���ǽ���ϻ���һ�����ο�)
	void Set_Run_DemoPlan_D();   //1������ש(��е�۴��Ϻ���ȡ�Ϻ󽫴�ש����ǽ����)
	void Set_Run_DemoPlan_E();   //1��ѭ��(�ؼ�����ǰ�е�ָ��λ��) 2������ƽ̨������ָ��λ�� 3����е�۵���ָ��λ������ 
	void Set_Run_DemoPlan_F();   //1��ѭ��(ʹ�ü����״�) 2������ƽ̨������ָ��λ�� 3����е�۵���ָ��λ������ 
	void Set_DemPlan_Run();      //������ʾ����
	void Set_DemPlan_Stop();     //ֹͣ��ʾ����
	/*-------------------------------------------DemoPlan����ʾ������-------------------------------------------*/



	/*-------------------------------------------LineFollow��ѭ�ߣ���ʾ-------------------------------------------*/
	void Get_LineFollow_ActualInfo();                          //��ȡѭ���˶������������ʵʱ��Ϣ��ʵʱͼ��ƫ�ƽǶȡ�ƫ�ƾ��룩
	void Set_LineFollow_RotateAdjust();                        //ѭ���˶�---��ʼ��ʱ����ת����
	void Set_LineFollow_SideswayAdjust();                      //ѭ���˶�---��ʼ��ʱ��ƽ�Ƶ���
	void Set_LineFollow_Forward();                             //ѭ���˶�---ǰ��
	void Set_LineFollow_Backoff();                             //ѭ���˶�---����
	/*-------------------------------------------LineFollow��ѭ�ߣ���ʾ-------------------------------------------*/


	/*-------------------------------------------Structure���ṹ���⣩��ʾ-------------------------------------------*/
	bool Init_Structure_Dll();                                 //�ṹ����---����Dll
	void Calc_Structure_Camera_R_And_T();                      //�ṹ����---������������ϵ����������ϵ��ת������
	void Calc_Structure_Robot_R_And_T();                       //�ṹ����---�������������ϵ����е�ۻ�����ϵ��ת������
	void Calc_Structure_R_And_T();                             //�ṹ����---������������ϵ����е�ۻ�����ϵ��ת������
	void Set_Structure_Calibrat();                             //�ṹ����---����ϵͳ�궨
	
	void Set_Structure_Test();                                 //�ṹ����---��ʼ���ȱ�ݵ�
	void Set_Structure_Burnish();                              //�ṹ����---��ĥ
	void Set_Structure_InitPos();                              //�ṹ����---��е���ƶ������λ��
	/*-------------------------------------------Structure���ṹ���⣩��ʾ-------------------------------------------*/


	/*-------------------------------------------DrawLine�����ߣ���ʾ-------------------------------------------*/
	void Calc_DrawLine_RectPos();                              //����---���������ʱ��Ҫ���Ƶľ��ε��ĸ���������
	void Set_DrawLine_Begin();                                 //����---��е���ƶ������λ��

	void Set_DrawLine_LiftPlat_Pos_A();                        //����---����ƽ̨�ƶ��� A λ�ã�����͵㣩

	void Set_DrawLine_From_topLeft();                          //����---��е���ƶ������ο�ʼλ�ã����������϶��㣩
	void Set_DrawLine_To_bottomLeft();                         //����---��е���ƶ����������¶���
	void Set_DrawLine_To_bottomRight();                        //����---��е���ƶ����������¶���
	void Set_DrawLine_To_topRight();                           //����---��е���ƶ����������϶���

	void Set_DrawLine_LiftPlat_Pos_B();                        //����---����ƽ̨�ƶ��� B λ�ã�����ߵ㣩

	void Set_DrawLine_To_topLeft();                            //����---��е���ƶ������ν���λ�ã����������϶��㣩

	void Set_DrawLine_LiftPlat_Pos_C();                        //����---����ƽ̨�ƶ��� C λ�ã�����͵㣩

	void Set_DrawLine_End();                                   //����---��е���ƶ������λ��
	/*-------------------------------------------DrawLine�����ߣ���ʾ-------------------------------------------*/



	/*-------------------------------------------Tiling������ש����ʾ-------------------------------------------*/
	void Calc_Tiling_MaterielAndPaste_Pos();
	void Set_Tiling_PickMateriel_Begin();                      //����ש---ȡ�Ͽ�ʼ---��е���ƶ���ȡ�ϳ�ʼλ�� 
	void Set_Tiling_MaterielPos();                             //����ש---����ȡ��---��е���ƶ������ϵ�λ��
	void Set_Tiling_PickMateriel_End();                        //����ש---ȡ�Ͻ���---��е���ƶ���ȡ�ϳ�ʼλ��
	void Set_Tiling_Paste_Begin();                             //����ש---ճ����ʼ---��е���ƶ���ճ�����ϵĳ�ʼλ��
	void Set_Tiling_PastePos_Near_Begin();                     //����ש---��е���ƶ���ָ���Ŀ���ճ�����ϵ�λ��
	void Set_Tiling_PastePos();                                //����ש---����ճ��---��е���ƶ���ճ�����ϵ�λ��
	void Set_Tiling_PastePos_Near_End();                       //����ש---��е���ƶ���ָ���Ŀ���ճ�����ϵ�λ��
	void Set_Tiling_Paste_End();                               //����ש---ճ������---��е���ƶ���ճ�����ϵĳ�ʼλ��
	/*-------------------------------------------Tiling������ש����ʾ-------------------------------------------*/




	/*-------------------------------------------SprayPaint�����ᣩ��ʾ-------------------------------------------*/
	void Calc_SprayPaint_Param();                                           //���᷽��---�������᷽���и�������ֵ
	void Calc_SprayPaint_Robot_Pos();

	void Set_SprayPaint_LiftPlat_Ready();                                   //���᷽��---����ƽ̨׼��---����ƽ̨����ָ��λ��
	void Set_SprayPaint_LiftPlat_Ready_evenNumber();                        //���᷽��---����ƽ̨׼��---�����ƶ�ż����ʱ
	void Set_SprayPaint_LiftPlat_Ready_oddNumber();                         //���᷽��---����ƽ̨׼��---�����ƶ�������ʱ 
	void Set_SprayPaint_Robot_Pos_A();                                      //���᷽��---����ƽ̨׼��---��е�۵��� A �� 
	void Set_SprayPaint_Robot_Pos_B();                                      //���᷽��---����ƽ̨׼��---��е�۵��� B �� 
	void Set_SprayPaint_Robot_Pos_C();                                      //���᷽��---����ƽ̨׼��---��е�۵��� C �� 
	void Set_SprayPaint_Robot_Pos_D();                                      //���᷽��---����ƽ̨׼��---��е�۵��� D �� 

	void Set_SprayPaint_VerInsideCorner_Robot_A();                          //���᷽��---��ֱ������Ϳ---��е�۵��﹤��λ������ A
	void Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_Begin();           //���᷽��---��ֱ������Ϳ---����λ������ A ʱ������ƽ̨������ʼ��
	void Set_SprayPaint_VerInsideCorner_Robot_A_LiftPlat_End();             //���᷽��---��ֱ������Ϳ---����λ������ A ʱ������ƽ̨�������յ�
	void Set_SprayPaint_VerInsideCorner_Robot_B();                          //���᷽��---��ֱ������Ϳ---��е�۵��﹤��λ������ B
	void Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_Begin();           //���᷽��---��ֱ������Ϳ---����λ������ B ʱ������ƽ̨������ʼ��
	void Set_SprayPaint_VerInsideCorner_Robot_B_LiftPlat_End();             //���᷽��---��ֱ������Ϳ---����λ������ B ʱ������ƽ̨�������յ�

	void Calc_SprayPaint_HorInsideCorner_Robot_Work_Pos();                  //���᷽��---ˮƽ������Ϳ---�����е�۹�������
	void Set_SprayPaint_HorInsideCorner_Work_Robot_A();                     //���᷽��---ˮƽ������Ϳ---��е�۵��﹤��λ������ A
	void Set_SprayPaint_HorInsideCorner_Work_Robot_B();                     //���᷽��---ˮƽ������Ϳ---��е�۵��﹤��λ������ B
	void Set_SprayPaint_HorInsideCorner_Work_Robot_C();                     //���᷽��---ˮƽ������Ϳ---��е�۵��﹤��λ������ C
	void Set_SprayPaint_HorInsideCorner_Work_Robot_D();                     //���᷽��---ˮƽ������Ϳ---��е�۵��﹤��λ������ D
	/*-------------------------------------------SprayPaint�����ᣩ��ʾ-------------------------------------------*/




	/*-------------------------------------------SprayPaint�����ᣩRosƽ̨��ʾ-------------------------------------------*/
	void Calc_Ros_SprayPaint_Param();                                           //Rosƽ̨���᷽��---�������᷽���и�������ֵ

	void Set_Ros_SprayPaint_Chasis_RotateAdjust();                              //Rosƽ̨���᷽��---���ݼ����״������������̵ķ���ʹ��ʼ�մ�ֱ�ڹ���ǽ��
	void Set_Ros_SprayPaint_Chasis_SideswayAdjust();                            //Rosƽ̨���᷽��---���ݼ����״�ļ����ƽ�Ƶ��̣�ʹ���빤��ǽ��ʼ�ձ���һ���ľ���

	void Set_Ros_SprayPaint_Chasis_Left();                                      //Rosƽ̨���᷽��---�����ƶ�
	void Set_Ros_SprayPaint_Chasis_Right();                                     //Rosƽ̨���᷽��---�����ƶ�

	void Set_Ros_SprayPaint_LiftPlat_Ready();                                   //Rosƽ̨���᷽��---����ƽ̨׼��---����ƽ̨����ָ��λ��
	void Set_Ros_SprayPaint_LiftPlat_Ready_evenNumber();                        //Rosƽ̨���᷽��---����ƽ̨׼��---�����ƶ�ż����ʱ
	void Set_Ros_SprayPaint_LiftPlat_Ready_oddNumber();                         //Rosƽ̨���᷽��---����ƽ̨׼��---�����ƶ�������ʱ

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
	/*-------------------------------------------SprayPaint�����ᣩRosƽ̨��ʾ-------------------------------------------*/

	

private:
	QString GetExePath();  //��ȡӦ�ó���·��

	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/
	Joy_Button_Status Get_JoyButton_Status(const int iPos);
	Joy_POV_Status Get_JoyPov_Status(const int iPov);
	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/

	QString GetRobotMoveCommend(GT_URRobotArm_Status iStatus, int iDirection);

	bool Parse_Robot_Pressure_Data(const QString strReg_1, const QString strReg_2, QString &strOutput, double &dwOutput); //����ѹ��������������

	bool Is_Turning(const QList<GT_Lidar_Data> data_Array_Input, const int iIndex);

	int Get_Scan_Turning(const QList<GT_Lidar_Data> data_Array_Input);

	void Get_Lidar_Scan_Line(const QList<GT_Lidar_Data> data_Array_Input);

	double Distance_From_Point_To_Line(const QLineF lineInput, const QPointF ptInput);

	GT_RobotArm_Pose Translate_Robot_To_Normal_CoordinateSystem(GT_RobotArm_Pose pose_Input);  //����е�ۻ�����ϵת���ɱ�׼��ֱ������ϵ
	QGTPoint3D Translate_Robot_To_Normal_CoordinateSystem(const QGTPoint3D pt_Input);          //����е�ۻ�����ϵת���ɱ�׼��ֱ������ϵ

	GT_RobotArm_Pose Translate_Normal_To_Robot_CoordinateSystem(GT_RobotArm_Pose pose_Input);  //����׼��ֱ������ϵת���ɻ�е�ۻ�����ϵ
	QGTPoint3D Translate_Normal_To_Robot_CoordinateSystem(const QGTPoint3D pt_Input);          //����׼��ֱ������ϵת���ɻ�е�ۻ�����ϵ


public:
	/*------------------------------------��������ģ��---------------------------------------*/
	GT_LOGIN_STATE m_nLoginState;                           //��¼״̬
	bool m_bIsSelect_Chasis_Connect;                        //�Ƿ�ѡ�����ӵ���
	bool m_bIsSelect_LiftPlat_Connect;                      //�Ƿ�ѡ����������ƽ̨
	bool m_bIsSelect_Robot_Connect;                         //�Ƿ�ѡ�����ӻ�е��
	bool m_bIsSelect_Ros_Connect;                           //�Ƿ�ѡ������Rosƽ̨
	bool m_bIsSelect_Lidar_Connect;                         //�Ƿ�ѡ�����Ӽ����״�
	bool m_bIsSelect_LaserMeasure_Connect;                  //�Ƿ�ѡ�����Ӽ�����
	bool m_bIsSelect_JoyHandle_Connect;                     //�Ƿ�ѡ��������Ϸ�ֱ�
	
	bool m_bIsConnect;                                      //�Ƿ��Ѿ�����
	bool m_bIsShowLog;                                      //�Ƿ���ʾLog

	CRITICAL_SECTION m_nLock;                                  //�ٽ���

	QString m_str_LogInfo;

	CHDLCnet *m_pHdlc_Chasis;                               //���ں͵��̿���ϵͳͨ�ŵ���ָ��
	QString m_strChasis_IpAddr;                             //����ģ���Ip��ַ
	QString m_strChasis_Port;                               //����ģ��Ķ˿�

	CMotorModbus *m_pLiftPlatNet;                           //����ƽ̨�������������ͨ����
	int m_iLiftPlat_PortNum;                                //����ƽ̨�Ķ˿ں�
	int m_iLiftPlat_Baudrate;                               //����ƽ̨�Ĳ�����

	CURRobotArmNet *m_pRobotNet;                            //���ںͻ�е��ģ��ͨ�ŵ���ָ��
	QString m_strRobot_IpAddr;                              //��е��ģ���IP��ַ
	QString m_strRobot_Port;                                //��е��ģ��Ķ˿�

	CHDLCnet *m_pHdlc_Ros;                                  //���ں�Rosƽ̨ͨ�ŵ���ָ��
	QString m_strRos_IpAddr;                                //Rosƽ̨��IP��ַ
	QString m_strRos_Port;                                  //Rosƽ̨�Ķ˿�

	qrk::Urg_driver *m_pNet_Lidar;                          //���ںͼ����״�ͨ�ŵ���ָ��
	QString m_strLidar_Port;                                //�����״�ͨ�Ŵ��ں�
	int m_iLidar_Baudrate;                                  //�����״�ͨ�Ų�����

	CSerialPort *m_pNet_LaserMeasure;                       //������ģ���ͨ����ָ��
	int m_iLaserMeasure_Port;                               //������ģ���ͨ�Ŷ˿ں�
	int m_iLaserMeasure_Baudrate;                           //������ģ���ͨ�Ų�����

	CSerialPort *m_pRobot_Pressure_Net;                     //��е��ĩ�����ڶ�ȡѹ����������ֵ��ͨ����ָ��
	int m_iRobot_Pressure_Port;                             //��е��ĩ�����ڶ�ȡѹ����������ֵ��ͨ�Ŷ˿�
	/*------------------------------------��������ģ��--------------------------------------*/


	/*----------------------------------------------Chasis�����̣�ģ��------------------------------------------*/
	GT_CHASIS_INFO m_nChasisInfo;                          //�����˶�ģ�����Ϣ
	GT_Chasis_Move_Type m_nChasis_NowType;                 //����ģ�����ڵ����з�ʽ

	bool m_bIsChasisInfo_Valid;                            //������Ϣ�Ƿ���Ч�������յ��ĵ���������Ϣ�Ƿ�OK��

	byte m_bzChasisCmd[16];                                //��λ�����͸����̵�ָ��
	int m_iChasis_Left_TargetSpeed;                        //����ģ�������˶���Ŀ���ٶ�
	int m_iChasis_Right_TargetSpeed;                       //����ģ�������˶���Ŀ���ٶ�
	int m_iChasis_Left_TargetAngle;                        //����ģ�����ֵ�Ŀ��Ƕ�
	int m_iChasis_Right_TargetAngle;                       //����ģ�����ֵ�Ŀ��Ƕ�
	/*----------------------------------------------Chasis�����̣�ģ��------------------------------------------*/

	/*-------------------------------------------LiftPlat������ƽ̨��ģ��-------------------------------------------*/
	Motor_Info m_nLiftPlat_MotorInfo;                    //��ȡ���ĵ������Ϣ
	GT_LiftPlat_Status m_nLiftPlat_NowStatus;            //����ƽ̨��ǰ״̬
	int m_iLiftPlat_TargetSpeed;                         //����ƽ̨�����Ŀ��ת��
	/*-------------------------------------------LiftPlat������ƽ̨��ģ��-------------------------------------------*/

	/*-------------------------------------------URRobot����е�֣�ģ��-------------------------------------------*/
	GT_RobotArm_Pose m_nRobot_Actual_SpacePos;           //��е�ֵ�ǰ�Ŀռ�λ������
	GT_RobotArm_Pose m_nRobot_Actual_JointAngle;         //��е�ֵ�ǰ�ĹؽڽǶ�ֵ
	GT_RobotArm_Pose m_nRobot_Target_SpacePos;           //Ŀ��ռ�λ������
	GT_RobotArm_Pose m_nRobot_Target_JointAngle;         //Ŀ��ؽڽǶ�

	GT_Robot_Tcp_Force m_nRobot_Actual_TcpForce;         //��е�ֵ�ǰ��Tcpĩ�˵���
	int m_iRobot_Force_Count;

	double m_dRobot_SpeedRate;                           //��е���˶��ٶ�
	double m_dRobot_AccelerationRate;                    //��е���˶����ٶ�
	/*-------------------------------------------URRobot����е�֣�ģ��-------------------------------------------*/




	/*--------------------------------------------------Rosƽ̨--------------------------------------------------*/
	GT_Ros_Work_Position_Status m_nRos_Work_Pos_Status;             //Rosƽ̨����λ��״̬
	bool m_bIs_Ros_Need_Open_Spraygun;                              //�Ƿ���Ҫ����ǹ
	bool m_bIs_Ros_Work_Finished;                                   //Rosƽ̨�ĵ��ι����Ƿ����
	/*--------------------------------------------------Rosƽ̨--------------------------------------------------*/




	/*-------------------------------------------------�״����ģ��----------------------------------------------*/
	int m_iLidar_SearchTurning_Step;                                 //��Ѱת�۵�ĵ�������
	int m_iLidar_SearchTurning_Dis_Threshold;                        //��Ѱת�۵�ľ�����ֵ
	int m_iLidar_SearchTurning_Len_Threshold;                        //��Ѱת�۵�ĳ�����ֵ

	int m_iLidar_ScanFail_Count;                                     //�����״�ɨ��ʧ�ܵĴ���

	bool m_bIs_Lidar_Data_Valid;                                     //�����״������Ƿ���Ч

	QList<QPointF> m_nLidar_Points_Array;
	QPointF m_ptLidar_Turning;
	QLineF m_nLidar_Line;
	/*-------------------------------------------------�״����ģ��----------------------------------------------*/



	/*-------------------------------------------------������ģ��----------------------------------------------*/
	double m_dLaserMeasure_Distance;
	/*-------------------------------------------------������ģ��----------------------------------------------*/



	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/
	Joy_Button_Status m_nJoy_Btn_Last_Status;                 //��Ϸ�ֱ�����һ�εİ���״̬
	Joy_POV_Status m_nJoy_Pov_Last_Status;                    //��Ϸ�ֱ�����һ�ε�ҡ��״̬
	Joy_Button_Status m_nJoy_Btn_Status;    //��Ϸ�ֱ��İ���״̬
	Joy_POV_Status m_nJoy_Pov_Status;       //��Ϸ�ֱ���ҡ��״̬
	QString m_strJoy_Btn_Status;
	QString m_strJoy_Pov_Status;
	bool m_bIs_JoyHandle_Control_Valid;     //�Ƿ����ͨ����Ϸ�ֱ�����װ�޻����˸���ģ��
	/*-------------------------------------------JoyHandle����Ϸ�ֱ���ģ��-------------------------------------------*/

	
	/*-------------------------------------------DemoPlan����ʾ��������������-------------------------------------------*/
	bool m_bIsAutoRun;                                     //�Ƿ��Զ�����
	bool m_bIsLoopRun;                                     //�Ƿ�ѭ����ʾ
	int m_iDemoPlanSet_Index;                              //ѡ��ķ������
	GT_Auto_Run_Status m_nAutoRun_NowStatus;               //�Զ�������������ʾ������ǰ��״̬
	/*-------------------------------------------DemoPlan����ʾ��������������-------------------------------------------*/


	/*-------------------------------------------LineFollow��ѭ�ߣ���������-------------------------------------------*/
	CFindLine *m_pFindLine;                                //����Ѱ�����ߵ���ֱ����ָ��
	bool m_bIs_LineFollowInfo_Valid;                       //�Ƿ�ѭ���˶������������ʵʱ��Ϣ��Ч
	int m_iLineFollow_InitDis_LeftWheel;                   //���̿�ʼ�Զ�Ѱ���˶�ʱ��ʼ���г�ֵ�������Զ�Ѱ�ߵ������˶�
	int m_iLineFollow_InitDis_RightWheel;                  //���̿�ʼ�Զ�Ѱ���˶�ʱ��ʼ���г�ֵ�������Զ�Ѱ�ߵ������˶�
	vector<double> LaserLine_Dis_Offset_Array;
	
	//���Ѱ��--------------�������
	double m_dLineFollowSet_Calibration;                   //����ı궨ֵ
	int m_iLineFollowSet_SearchThreshold;                  //����ֱ�ߵ���ֵ
	int m_iLineFollowSet_MinBinaryThreshold;               //��ֵ������С��ֵ
	int m_iLineFollowSet_MaxBinaryThreshold;               //��ֵ���������ֵ
	int m_iLineFollowSet_MinContourArea;                   //��������С�������
	int m_iLineFollowSet_MaxContourArea;                   //���������������� 
	double m_dLineFollowSet_AngleRange;                    //ƫ�ƽǶȵ���Χ����λ:�ȣ�
	double m_dLineFollowSet_DisRange;                      //ƫ�ƾ������Χ����λ:���أ�
	int m_iLineFollowSet_TargetDis;                        //�����˶���Ŀ�����   
	int m_iLineFollowSet_SpeedRate;                        //ѭ���˶�ʱ�����˶�������

	//���Ѱ��--------------�������
	cv::Mat m_nLineFollowSet_ResultImage;                  //ѭ���˶� - ���������ͼ��
	double m_dLineFollowSet_ResultAngel;                   //ѭ���˶� - �����뼤���ߵ�ƫ�ƽǶ�                 
	double m_dLineFollowSet_ResultDis;                     //ѭ���˶� - �����뼤���ߵ�ƫ�ƾ���  
	/*-------------------------------------------LineFollow��ѭ�ߣ���������-------------------------------------------*/



	/*-------------------------------------------Structure���ṹ���⣩��������-------------------------------------------*/
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

	QLibrary m_hDll_StructureCalibration;                  //�ṹ����ϵͳ���������궨ģ��
	QLibrary m_hDll_StructureDetection;                    //�ṹ����ϵͳ����ģ��
	QLibrary m_hDll_PointCloudModule;                      //�ṹ����ϵͳ���ƴ���ģ��

	double m_dzStructure_Camera_R[9];                      //�����������ϵ����������ϵ�ĵ���ת����
	double m_dzStructure_Camera_T[3];                      //�����������ϵ����������ϵ�ĵ�ƽ�ƾ���

	double m_dzStructure_Robot_R[9];                       //�ӻ�е��Tcp����ϵ����������ϵ�ĵ���ת����
	double m_dzStructure_Robot_T[3];                       //�ӻ�е��Tcp����ϵ����������ϵ�ĵ�ƽ�ƾ���

	double m_dzStructure_R[9];                             //�����������ϵ����е�ۻ�����ϵ�ĵ���ת����
	double m_dzStructure_T[3];                             //�����������ϵ����е�ۻ�����ϵ�ĵ�ƽ�ƾ���

	double m_dzStructure_Robot_Pos[6];                     //�ṹ���⵽��ȱ�ݵ��ڻ�е�ۻ�����ϵ�µ�λ��

	bool m_bIsStructure_LoadDll;                           //�Ƿ��Ѿ������˽ṹ����ģ���Dll
	
	bool m_bIsStructure_Move;                              //�Ƿ��Ѿ�����ָ�����е�ۿ����ƶ�
	bool m_bIsStructure_beginTest;                         //�Ƿ��Ѿ���ʼ���нṹ����
	GT_RobotArm_Pose m_nStructure_InitPos;                 //��е�۵����
	/*-------------------------------------------Structure���ṹ���⣩��������-------------------------------------------*/



	/*-------------------------------------------DrawLine����ǽ�滭��׼�ߣ���������-------------------------------------------*/
	GT_RobotArm_Pose m_nDrawLine_InitPos;                  //��е�۵����
	QGTPoint3D m_ptDrawLine_topLeft;                       //��е�ۻ����ε����϶���
	QGTPoint3D m_ptDrawLine_bottomLeft;                    //��е�ۻ����ε����¶���
	QGTPoint3D m_ptDrawLine_bottomRight;                   //��е�ۻ����ε����¶���
	QGTPoint3D m_ptDrawLine_topRight;                      //��е�ۻ����ε����϶���
	bool m_bIsDrawLine_Move;                               //�Ƿ��Ѿ�����ָ�����е�ۿ����ƶ�
	
	double m_dDrawLine_Width;                              //���ߵľ��ο��
	double m_dDrawLine_Height;                             //���ߵľ��θ߶�

	int m_iDrawLine_LiftPlat_topPos;                       //����ƽ̨�����λ��
	int m_iDrawLine_LiftPlat_bottomPos;                    //����ƽ̨�����λ��
	/*-------------------------------------------DrawLine����ǽ�滭��׼�ߣ���������-------------------------------------------*/


	/*-------------------------------------------Tiling������ש����������-------------------------------------------*/
	GT_RobotArm_Pose m_nTiling_InitPos;                    //����ש��ʾ�ĳ�ʼλ��
	GT_RobotArm_Pose m_nTiling_InitPos_Materiel;           //ʰȡ���ϵĳ�ʼλ��
	GT_RobotArm_Pose m_nTiling_InitPos_Paste;              //ճ�����ϵĳ�ʼλ��
	GT_RobotArm_Pose m_nTiling_InitAngle_Materiel;         //ʰȡ���ϵĳ�ʼ�Ƕ�
	GT_RobotArm_Pose m_nTiling_InitAngle_Paste;            //ճ�����ϵĳ�ʼ�Ƕ�

	QGTPoint3D m_ptTiling_MaterielPos;                //���ϵ�����λ��
	QGTPoint3D m_ptTiling_PastePos;                   //��ǽ����ճ�����ϵ�����λ��

	QList<QGTPoint3D> m_nTiling_MaterielPos_Array;
	QList<QGTPoint3D> m_nTiling_PastePos_Array;

	double m_dTiling_Materiel_Width;                       //��ש�Ŀ��
	double m_dTiling_Materiel_Thickness;                   //��ש�ĺ��
	double m_dTiling_Paste_Feed;                           //ճ����שʱ��е����ǰ�Ľ�����
	int m_iTiling_Materiel_Num;                            //��ש������
	int m_iTiling_Pressure_Range;                          //��е��ĩ��ѹ������������ֵ

	GT_Robot_Tcp_Force m_nTiling_TcpForce_Init;            //��е��ĩ��ѹ���������ĳ�ʼѹ��ֵ
	GT_Robot_Tcp_Force m_nTiling_TcpForce_Paste;           //��е��ĩ��ѹ����������ճ������ʱ��ѹ��ֵ

	int m_iTiling_Count;
	bool m_bIsTiling_Move;                                 //�Ƿ��Ѿ�����ָ�����е�ۿ����ƶ�
	/*-------------------------------------------Tiling������ש����������-------------------------------------------*/




	/*-------------------------------------------SprayPaintSet�����ᣩ��������-------------------------------------------*/
	GT_RobotArm_Pose m_nSprayPaint_Robot_InitPos;                               //���᷽��---��е�۳�ʼ����λ��
	GT_RobotArm_Pose m_nSprayPaintSet_VerInsideCorner_RobotPos_A;               //���᷽��---��ֱ������Ϳ---��е����̬ A
	GT_RobotArm_Pose m_nSprayPaintSet_VerInsideCorner_RobotPos_B;               //���᷽��---��ֱ������Ϳ---��е����̬ B
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_RobotPos_A;               //���᷽��---ˮƽ������Ϳ---��е����̬ A
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_RobotPos_B;               //���᷽��---ˮƽ������Ϳ---��е����̬ B

	bool m_bIs_SprayPaint_VerInsideCorner_Enable;                               //���᷽��---�Ƿ�ʹ�ܴ�ֱ������Ϳ
	bool m_bIs_SprayPaint_HorInsideCorner_Enable;                               //���᷽��---�Ƿ�ʹ��ˮƽ������Ϳ

	int m_iSprayPaint_Count_VerInsideCorner;                                    //���᷽��---��ֱ������Ϳ�Ĵ���
	int m_iSprayPaint_Count_HorInsideCorner;                                    //���᷽��---ˮƽ������Ϳ�Ĵ���

	int m_iSprayPaint_Count_MovedBy_Chasis;                                     //���᷽��---�����ƶ�����
	int m_iSprayPaint_Count_MovedBy_LiftPlat;                                   //���᷽��---����ƽ̨�ƶ�����
	int m_iSprayPaint_Count_MovedBy_Robot;                                      //���᷽��---��е���ƶ�����
	
	double m_dSprayPaint_LiftPlat_InitPos;                                      //���᷽��---����ƽ̨�ĳ�ʼλ��
	double m_dSprayPaint_HorDis_MovedBy_Robot;                                  //���᷽��---��е��ˮƽ�����ƶ�����
	double m_dSprayPaint_Width_By_Spray;                                        //���᷽��---ִ������ǹ�Ĺ������

	double m_dSprayPaint_Overlap_By_Robot;                                      //���᷽��---��е�۵�����Ϳ���غ���
	double m_dSprayPaint_Overlap_By_LiftPlat;                                   //���᷽��---����ƽ̨������Ϳ���غ���
	double m_dSprayPaint_Overlap_By_Chasis;                                     //���᷽��---���̵�����Ϳ���غ���


	//SprayPaint Work
	int m_iSprayPaint_Current_Count_MovedBy_Chasis;                             //���᷽��---���̵�ǰ�ƶ��Ĵ���
	int m_iSprayPaint_Current_Count_MovedBy_LiftPlat;                           //���᷽��---����ƽ̨��ǰ�ƶ��Ĵ���
	int m_iSprayPaint_Current_Count_MovedBy_Robot;                              //���᷽��---��е�۵�ǰ�ƶ��Ĵ���

	int m_iSprayPaint_Current_Count_VerInsideCorner;                            //���᷽��---��ֱ���ǵ�ǰ��Ϳ�Ĵ���
	int m_iSprayPaint_Current_Count_HorInsideCorner;                            //���᷽��---ˮƽ���ǵ�ǰ��Ϳ�Ĵ���
	
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_A;                             //���᷽��---������Ϳ---��е�۹������� A
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_B;                             //���᷽��---������Ϳ---��е�۹������� B
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_C;                             //���᷽��---������Ϳ---��е�۹������� C
	GT_RobotArm_Pose m_nSprayPaint_Work_RobotPos_D;                             //���᷽��---������Ϳ---��е�۹������� D

	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_A;          //���᷽��---ˮƽ������Ϳ---��е�۹������� A  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_B;          //���᷽��---ˮƽ������Ϳ---��е�۹������� B  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_C;          //���᷽��---ˮƽ������Ϳ---��е�۹������� C  
	GT_RobotArm_Pose m_nSprayPaintSet_HorInsideCorner_Work_RobotPos_D;          //���᷽��---ˮƽ������Ϳ---��е�۹������� D  


	bool m_bIs_SprayPaint_Robot_Move;

	double m_dSprayPaint_Dis_MovedBy_Chasis;                                    //���᷽��---���̵����ƶ�����
	double m_dSprayPaint_Dis_MovedBy_LiftPlat;                                  //���᷽��---����ƽ̨�����ƶ�����
	double m_dSprayPaint_VerDis_MovedBy_Robot;                                  //���᷽��---��е�۴�ֱ�����ƶ�����
	/*-------------------------------------------SprayPaintSet�����ᣩ��������-------------------------------------------*/




	/*-------------------------------------------SprayPaintSet�����ᣩRosƽ̨��������-------------------------------------------*/
	double m_dRos_SprayPaint_Dis_Precision;                                         //���᷽��---�����ϵľ������

	double m_dRos_SprayPaint_LiftPlat_InitPos;                                      //���᷽��---����ƽ̨�ĳ�ʼλ��

	double m_dRos_SprayPaint_Hor_WorkDis;                                           //���᷽��---���ζ���ˮƽ��������
	double m_dRos_SprayPaint_Ver_WorkDis;                                           //���᷽��---���ζ�����ֱ��������

	double m_dRos_SprayPaint_Hor_Overlap;                                           //���᷽��---ˮƽ�������Ϳ�غ���
	double m_dRos_SprayPaint_Ver_Overlap;                                           //���᷽��---��ֱ�������Ϳ�غ���


	double m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall;                       //���᷽��---���̵�ǰ�빤��ǽ��ļнǷ�Χ
	double m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall;                     //���᷽��---�����빤��ǽ��ľ�����ֵ
	double m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall;                            //���᷽��---���̾������ǽ�����С����
	double m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall;                            //���᷽��---���̾������ǽ���������


	//Ros SprayPaint Work
	int m_iRos_SprayPaint_Count_MovedBy_Chasis;                                     //���᷽��---�����ƶ�����
	int m_iRos_SprayPaint_Count_MovedBy_LiftPlat;                                   //���᷽��---����ƽ̨�ƶ�����

	int m_iRos_SprayPaint_Current_Count_MovedBy_Chasis;                             //���᷽��---���̵�ǰ�ƶ��Ĵ���
	int m_iRos_SprayPaint_Current_Count_MovedBy_LiftPlat;                           //���᷽��---����ƽ̨��ǰ�ƶ��Ĵ���

	double m_dRos_SprayPaint_LiftPlat_MaxPos;                                       //���᷽��---����ƽ̨���������λ��

	double m_dRos_SprayPaint_Dis_MovedBy_Chasis;                                    //���᷽��---���̵����ƶ�����
	double m_dRos_SprayPaint_Dis_MovedBy_LiftPlat;                                  //���᷽��---����ƽ̨�����ƶ�����

	double m_dRos_SprayPaint_Chasis_Angle_fromWorkwall;                             //���᷽��---���̵�ǰ�빤��ǽ��ļн�
	double m_dRos_SprayPaint_Chasis_Dis_fromLeftwall;                               //���᷽��---���̾������ǽ��ľ���
	double m_dRos_SprayPaint_Chasis_Dis_fromWorkwall;                               //���᷽��---�����빤��ǽ��ľ���

	bool m_bIs_Ros_SprayPaint_RosWork;
	/*-------------------------------------------SprayPaintSet�����ᣩRosƽ̨��������-------------------------------------------*/

	


};

extern CGlobalUnit *g_pGlobalUnit;
