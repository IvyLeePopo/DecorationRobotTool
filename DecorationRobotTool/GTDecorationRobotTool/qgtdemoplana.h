#ifndef QGTDEMOPLANA_H
#define QGTDEMOPLANA_H

#include <QWidget>
#include "ui_qgtdemoplana.h"

#include "GlobalUnit.h"

class QGTDemoPlanA : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanA(QWidget *parent = 0);
	~QGTDemoPlanA();

public:
	void Update_ChasisInfo_DemoPlanA();
	void Update_LineFollowInfo_DemoPlanA();
private:
	QPixmap pix_ChasisFrame;
	QPixmap pix_LeftWheel;
	QPixmap pix_RightWheel;
private:
	Ui::QGTDemoPlanA ui;
};

#endif // QGTDEMOPLANA_H
