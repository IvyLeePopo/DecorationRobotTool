#ifndef QGTDEMOPLANE_H
#define QGTDEMOPLANE_H

#include <QWidget>
#include "ui_qgtdemoplane.h"

#include "GlobalUnit.h"

class QGTDemoPlanE : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanE(QWidget *parent = 0);
	~QGTDemoPlanE();

public:
	void Update_ChasisInfo_DemoPlanE();
	void Update_RobotInfo_DemoPlanE();
	void Update_LineFollowInfo_DemoPlanE();

private:
	QPixmap pix_ChasisFrame;
	QPixmap pix_LeftWheel;
	QPixmap pix_RightWheel;
private:
	Ui::QGTDemoPlanE ui;
};

#endif // QGTDEMOPLANE_H
