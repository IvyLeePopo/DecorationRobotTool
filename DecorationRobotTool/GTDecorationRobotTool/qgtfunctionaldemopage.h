#ifndef QGTFUNCTIONALDEMOPAGE_H
#define QGTFUNCTIONALDEMOPAGE_H

#include <QWidget>
#include "ui_qgtfunctionaldemopage.h"

#include "Commen/qgtthread.h"

class QGTFunctionalDemoPage : public QWidget
{
	Q_OBJECT

public:
	QGTFunctionalDemoPage(QWidget *parent = 0);
	~QGTFunctionalDemoPage();


public:
	void Set_Thread_DemoPlan_Enable(bool bIsBeginWork);
	void Set_AutoRun_DemoPlan_Enable(bool bIsRunning);

	private slots:
	void on_toolButton_SelectDemoPlan_A_pressed();
	void on_toolButton_SelectDemoPlan_B_pressed();
	void on_toolButton_SelectDemoPlan_C_pressed();
	void on_toolButton_SelectDemoPlan_D_pressed();
	void on_toolButton_SelectDemoPlan_E_pressed();
	void on_toolButton_SelectDemoPlan_F_pressed();

	void on_Chasis_Info_Output();
	void on_Robot_Info_Output();
	void on_Lidar_Info_Output();
	void on_LaserMeasure_Info_Output();
	void on_LineFollow_Info_Output();
private:
	QGTThread *m_pThread_LineFollow_Read;      //ѭ���˶��Ľ����̣߳����ڻ�ȡ���������ʵʱ��Ϣ
	QGTThread *m_pThread_DemoPlan;             //��ʾ�������߳�
private:
	Ui::QGTFunctionalDemoPage ui;
};

#endif // QGTFUNCTIONALDEMOPAGE_H
