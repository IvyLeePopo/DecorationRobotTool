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
	QGTThread *m_pThread_Chasis;               //底盘模块线程
	QGTThread *m_pThread_LiftPlat;             //升降平台模块线程
	QGTThread *m_pThread_Robot;                //机械臂模块线程
	QGTThread *m_pThread_Ros;                  //Ros平台工作线程
	QGTThread *m_pThread_Lidar;                //激光雷达工作线程
	QGTThread *m_pThread_LaserMeasure;         //激光测距模块工作线程
	QGTThread *m_pThread_JoyHandle;            //游戏手柄模块线程
private:
	Ui::QGTModularControlPage ui;
};

#endif // QGTMODULARCONTROLPAGE_H
