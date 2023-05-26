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
	// X 方向坐标位置移动
	void on_toolButton_Robot_PosX_Up_pressed();
	void on_toolButton_Robot_PosX_Up_released();
	void on_toolButton_Robot_PosX_Down_pressed();
	void on_toolButton_Robot_PosX_Down_released();

	// Y 方向坐标位置移动
	void on_toolButton_Robot_PosY_Up_pressed();
	void on_toolButton_Robot_PosY_Up_released();
	void on_toolButton_Robot_PosY_Down_pressed();
	void on_toolButton_Robot_PosY_Down_released();

	// Z 方向坐标位置移动
	void on_toolButton_Robot_PosZ_Up_pressed();
	void on_toolButton_Robot_PosZ_Up_released();
	void on_toolButton_Robot_PosZ_Down_pressed();
	void on_toolButton_Robot_PosZ_Down_released();

	// X 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_X_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_X_released();
	void on_toolButton_Robot_RotateRight_Axle_X_pressed();
	void on_toolButton_Robot_RotateRight_Axle_X_released();

	// Y 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_Y_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_Y_released();
	void on_toolButton_Robot_RotateRight_Axle_Y_pressed();
	void on_toolButton_Robot_RotateRight_Axle_Y_released();

	// Z 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_Z_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_Z_released();
	void on_toolButton_Robot_RotateRight_Axle_Z_pressed();
	void on_toolButton_Robot_RotateRight_Axle_Z_released();

	// U 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_U_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_U_released();
	void on_toolButton_Robot_RotateRight_Axle_U_pressed();
	void on_toolButton_Robot_RotateRight_Axle_U_released();

	// V 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_V_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_V_released();
	void on_toolButton_Robot_RotateRight_Axle_V_pressed();
	void on_toolButton_Robot_RotateRight_Axle_V_released();

	// W 轴角度转动
	void on_toolButton_Robot_RotateLeft_Axle_W_pressed();
	void on_toolButton_Robot_RotateLeft_Axle_W_released();
	void on_toolButton_Robot_RotateRight_Axle_W_pressed();
	void on_toolButton_Robot_RotateRight_Axle_W_released();

	//移动到目标空间坐标位置
	void on_toolButton_Robot_MoveTo_TargetPos_pressed();
	void on_toolButton_Robot_MoveTo_TargetAngle_pressed();

	//改变机械臂的移动速度和加速度
	void on_doubleSpinBox_Robot_SpeedRate_valueChanged(double dValue);
	void on_doubleSpinBox_Robot_AccelerationRate_valueChanged(double dValue);

	//更新机械臂显示信息
	void Update_ActualInfo_Robot();

	void on_toolButton_Structure_Calibrat_pressed();
	void on_toolButton_Structure_Test_pressed();

private:
	Ui::QGTRobotModule ui;
};

#endif // QGTROBOTMODULE_H
