#ifndef QGTCOMMUNICATIONSET_H
#define QGTCOMMUNICATIONSET_H

#include <QWidget>
#include "ui_qgtcommunicationset.h"

#include "GlobalUnit.h"

class QGTCommunicationSet : public QWidget
{
	Q_OBJECT

public:
	QGTCommunicationSet(QWidget *parent = 0);
	~QGTCommunicationSet();


	private slots:
	void on_toolButton_Communication_Ok_pressed();
	void on_toolButton_Communication_Cancel_pressed();
	void on_toolButton_Communication_Reset_pressed();

	void on_checkBox_IsSelect_Chasis_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_LiftPlat_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_Robot_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_Ros_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_Lidar_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_LaserMeasure_Connect_clicked(bool bIsCheck);
	void on_checkBox_IsSelect_JoyHandle_Connect_clicked(bool bIsCheck);

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTCommunicationSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTCOMMUNICATIONSET_H
