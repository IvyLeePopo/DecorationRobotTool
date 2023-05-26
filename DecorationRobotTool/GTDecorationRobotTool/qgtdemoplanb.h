#ifndef QGTDEMOPLANB_H
#define QGTDEMOPLANB_H

#include <QWidget>
#include "ui_qgtdemoplanb.h"

#include "GlobalUnit.h"

class QGTDemoPlanB : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanB(QWidget *parent = 0);
	~QGTDemoPlanB();

public:
	void Update_ChasisInfo_DemoPlanB();
	void Update_RobotInfo_DemoPlanB();
	void Update_LineFollowInfo_DemoPlanB();
	void Update_StructureInfo_DemoPlanB();

private:
	QPixmap pix_ChasisFrame;
	QPixmap pix_LeftWheel;
	QPixmap pix_RightWheel;

private:
	Ui::QGTDemoPlanB ui;
};

#endif // QGTDEMOPLANB_H
