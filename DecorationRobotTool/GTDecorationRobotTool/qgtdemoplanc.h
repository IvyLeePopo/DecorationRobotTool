#ifndef QGTDEMOPLANC_H
#define QGTDEMOPLANC_H

#include <QWidget>
#include "ui_qgtdemoplanc.h"

#include "GlobalUnit.h"

class QGTDemoPlanC : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanC(QWidget *parent = 0);
	~QGTDemoPlanC();

public:
	void Update_RobotInfo_DemoPlanC();
private:
	Ui::QGTDemoPlanC ui;
};

#endif // QGTDEMOPLANC_H
