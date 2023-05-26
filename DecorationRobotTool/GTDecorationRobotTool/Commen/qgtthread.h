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
	void StartThread_Chasis();                    //��ʼ���̿����߳�
	void StartThread_LiftPlat();                  //��ʼ����ƽ̨�����߳�
	void StartThread_Robot();                     //��ʼ��е�ֽ����߳�
	void StartThread_Ros();                       //��ʼRosƽ̨�����߳�
	void StartThread_Lidar();                     //��ʼ�����״﹤���߳�
	void StartThread_LaserMeasure();              //��ʼ�����๤���߳�
	void StartThread_JoyHandle();                 //��ʼ��Ϸ�ֱ������߳�
	void StartThread_LineFollow_Read();           //��ʼѭ���˶��Ľ����̣߳���Ҫ���ڽ������������ͼ����Ϣ
	void StartThread_DemoPlan();                  //��ʼ��ʾ�������߳�
public:
	bool m_bIsExit;
private:
	GT_ThreadModule_Type m_iThreadType;
};

#endif // QGTTHREAD_H
