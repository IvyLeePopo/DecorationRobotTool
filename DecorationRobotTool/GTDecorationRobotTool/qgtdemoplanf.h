#ifndef QGTDEMOPLANF_H
#define QGTDEMOPLANF_H

#include <QWidget>
#include "ui_qgtdemoplanf.h"

#include "GlobalUnit.h"

class QGTDemoPlanF : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanF(QWidget *parent = 0);
	~QGTDemoPlanF();

public:
	void Update_Chasis_Info_DemoPlanF();
	void Update_Lidar_Info_DemoPlanF();
	void Update_LaserMeasure_Info_DemoPlanF();

private:
	QPixmap pix_ChasisFrame;
	QPixmap pix_LeftWheel;
	QPixmap pix_RightWheel;

private:
	Ui::QGTDemoPlanF ui;
};

#endif // QGTDEMOPLANF_H
