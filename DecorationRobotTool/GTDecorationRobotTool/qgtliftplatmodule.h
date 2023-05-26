#ifndef QGTLIFTPLATMODULE_H
#define QGTLIFTPLATMODULE_H

#include <QWidget>
#include "ui_qgtliftplatmodule.h"

#include "GlobalUnit.h"

class QGTLiftPlatModule : public QWidget
{
	Q_OBJECT

public:
	QGTLiftPlatModule(QWidget *parent = 0);
	~QGTLiftPlatModule();

	private slots:
	void on_toolButton_LiftPlat_MoveUp_pressed();
	void on_toolButton_LiftPlat_MoveDown_pressed();
	void on_toolButton_LiftPlat_Stop_pressed();

	void on_spinBox_Motor_TargetSpeed_valueChanged(int iValue);

	void Update_ActualInfo_LiftPlat_Normal();
	void Update_ActualInfo_LiftPlat_Other();
private:
	Ui::QGTLiftPlatModule ui;
};

#endif // QGTLIFTPLATMODULE_H
