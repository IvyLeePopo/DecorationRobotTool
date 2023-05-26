#ifndef QGTTHREAD_H
#define QGTTHREAD_H

#include <QThread>
#include "GlobalUnit.h"

enum GT_ThreadModule_Type
{
	TMT_Chasis           = 0,
	TMT_LiftPlat         = 1,
	TMT_Robot            = 2,
	TMT_Ros              = 3,
	TMT_Lidar            = 4,
	TMT_LaserMeasure     = 5,
	TMT_JoyHandle        = 6,
	TMT_LineFollow_Read  = 7,
	TMT_DemoPlan         = 8
};

class QGTThread : public QThread
{
	Q_OBJECT

public:
	QGTThread(QObject *parent);
	~QGTThread();

signals:
	void LineFollow_Info_Output();
	void Chasis_Info_Output();
	void LiftPlat_Info_Output();
	void Robot_Info_Output();
	void Lidar_Info_Output();
	void LaserMeasure_Info_Output();
	void JoyHandle_Info_Output();

public:
	void SetDefaultThreadType(GT_ThreadModule_Type iType){ m_iThreadType = iType; };
protected:
	virtual void run();
private:
	void StartThread_Chasis();                    //开始底盘控制线程
	void StartThread_LiftPlat();                  //开始升降平台控制线程
	void StartThread_Robot();                     //开始机械手接收线程
	void StartThread_Ros();                       //开始Ros平台工作线程
	void StartThread_Lidar();                     //开始激光雷达工作线程
	void StartThread_LaserMeasure();              //开始激光测距工作线程
	void StartThread_JoyHandle();                 //开始游戏手柄接收线程
	void StartThread_LineFollow_Read();           //开始循线运动的接收线程，主要用于接收相机反馈的图像信息
	void StartThread_DemoPlan();                  //开始演示方案的线程
public:
	bool m_bIsExit;
private:
	GT_ThreadModule_Type m_iThreadType;
};

#endif // QGTTHREAD_H
