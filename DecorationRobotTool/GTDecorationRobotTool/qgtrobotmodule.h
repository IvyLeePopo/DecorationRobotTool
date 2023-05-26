#ifndef QGTROBOTMODULE_H
#define QGTROBOTMODULE_H

#include <QWidget>
#include "ui_qgtrobotmodule.h"

#include "GlobalUnit.h"

class QGTRobotModule : public QWidget
{
	Q_OBJECT

public:
	QGTRobotModule(QWidget *parent = 0);
	~QGTRobotModule();


	private slots:
	// X ��������λ���ƶ�
	void on_toolButton_Robot_PosX_Up_pressed();
	void on_toolButton_Robot_PosX_Up_released();
	void on_toolButton_Robot_PosX_Down_pressed();
	void on_toolButton_Robot_PosX_Down_released();

	// Y ��������λ���ƶ�
	void on_toolButton_Robot_PosY_Up_pressed();
	void on_toolButton_Robot_PosY_Up_released();
	void on_toolButton_Robot_PosY_Down_pressed();
	void on_toolButton_Robot_PosY_Down_released();

	// Z ��������λ���ƶ�
	void on_toolButton_Robot_PosZ_Up_pressed();
	void on_toolButton_Robot_PosZ_Up_released();
	void on_toolButton_Robot_PosZ_Down_pressed();
	void on_toolButton_Robot_PosZ_Down_released();

	// X ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_X_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_X_released();
	void on_toolButton_Robot_RotateRight_Axle_X_pressed();
	void on_toolButton_Robot_RotateRight_Axle_X_released();

	// Y ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_Y_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_Y_released();
	void on_toolButton_Robot_RotateRight_Axle_Y_pressed();
	void on_toolButton_Robot_RotateRight_Axle_Y_released();

	// Z ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_Z_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_Z_released();
	void on_toolButton_Robot_RotateRight_Axle_Z_pressed();
	void on_toolButton_Robot_RotateRight_Axle_Z_released();

	// U ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_U_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_U_released();
	void on_toolButton_Robot_RotateRight_Axle_U_pressed();
	void on_toolButton_Robot_RotateRight_Axle_U_released();

	// V ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_V_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_V_released();
	void on_toolButton_Robot_RotateRight_Axle_V_pressed();
	void on_toolButton_Robot_RotateRight_Axle_V_released();

	// W ��Ƕ�ת��
	void on_toolButton_Robot_RotateLeft_Axle_W_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_W_released();
	void on_toolButton_Robot_RotateRight_Axle_W_pressed();
	void on_toolButton_Robot_RotateRight_Axle_W_released();

	//�ƶ���Ŀ��ռ�����λ��
	void on_toolButton_Robot_MoveTo_TargetPos_pressed();
	void on_toolButton_Robot_MoveTo_TargetAngle_pressed();

	//�ı��е�۵��ƶ��ٶȺͼ��ٶ�
	void on_doubleSpinBox_Robot_SpeedRate_valueChanged(double dValue);
	void on_doubleSpinBox_Robot_AccelerationRate_valueChanged(double dValue);

	//���»�е����ʾ��Ϣ
	void Update_ActualInfo_Robot();

	void on_toolButton_Structure_Calibrat_pressed();
	void on_toolButton_Structure_Test_pressed();

private:
	Ui::QGTRobotModule ui;
};

#endif // QGTROBOTMODULE_H
