#ifndef QGTCHASISMODULE_H
#define QGTCHASISMODULE_H

#include <QWidget>
#include "ui_qgtchasismodule.h"

#include "Commen/qgtthread.h"

class QGTChasisModule : public QWidget
{
	Q_OBJECT

public:
	QGTChasisModule(QWidget *parent = 0);
	~QGTChasisModule();

	private slots:
	void on_toolButton_Chasis_Move_Forward_pressed();
	void on_toolButton_Chasis_Move_Backoff_pressed();
	void on_toolButton_Chasis_Move_Left_pressed();
	void on_toolButton_Chasis_Move_Right_pressed();
	void on_toolButton_Chasis_Stop_pressed();
	void on_toolButton_Chasis_Move_Rotate_Right_pressed();
	void on_toolButton_Chasis_Move_Rotate_Left_pressed();
	void on_toolButton_Chasis_Move_Rotate_pressed();
	void on_toolButton_Chasis_LinkRod_Up_pressed();
	void on_toolButton_Chasis_LinkRod_Down_pressed();
	void on_toolButton_Chasis_Electromagnet_On_pressed();
	void on_toolButton_Chasis_Electromagnet_Off_pressed();


	void on_spinBox_Chasis_TargetSpeed_LeftWheel_valueChanged(int iValue);
	void on_spinBox_Chasis_TargetSpeed_RightWheel_valueChanged(int iValue);
	void on_spinBox_Chasis_TargetAngle_LeftWheel_valueChanged(int iValue);
	void on_spinBox_Chasis_TargetAngle_RightWheel_valueChanged(int iValue);

	void Update_ActualInfo_Chasis();

private:
	QPixmap pix_ChasisFrame;
	QPixmap pix_LeftWheel;
	QPixmap pix_RightWheel;
private:
	Ui::QGTChasisModule ui;
};

#endif // QGTCHASISMODULE_H
