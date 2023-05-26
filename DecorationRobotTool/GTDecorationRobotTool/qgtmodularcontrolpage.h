#ifndef QGTMODULARCONTROLPAGE_H
#define QGTMODULARCONTROLPAGE_H

#include <QWidget>
#include "ui_qgtmodularcontrolpage.h"

#include "Commen/qgtthread.h"

class QGTModularControlPage : public QWidget
{
	Q_OBJECT

public:
	QGTModularControlPage(QWidget *parent = 0);
	~QGTModularControlPage();


public:
	void Set_Thread_ModularControl_Enable(bool bIsBeginWork);

	private slots:
	void on_toolButton_SelectModule_Chasis_pressed();
	void on_toolButton_SelectModule_LiftPlat_pressed();
	void on_toolButton_SelectModule_Robot_pressed();
	void on_toolButton_SelectModule_JoyHandle_pressed();

public:
	QGTThread *m_pThread_Chasis;               //����ģ���߳�
	QGTThread *m_pThread_LiftPlat;             //����ƽ̨ģ���߳�
	QGTThread *m_pThread_Robot;                //��е��ģ���߳�
	QGTThread *m_pThread_Ros;                  //Rosƽ̨�����߳�
	QGTThread *m_pThread_Lidar;                //�����״﹤���߳�
	QGTThread *m_pThread_LaserMeasure;         //������ģ�鹤���߳�
	QGTThread *m_pThread_JoyHandle;            //��Ϸ�ֱ�ģ���߳�
private:
	Ui::QGTModularControlPage ui;
};

#endif // QGTMODULARCONTROLPAGE_H
