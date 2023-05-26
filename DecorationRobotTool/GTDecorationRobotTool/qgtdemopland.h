#ifndef QGTDEMOPLAND_H
#define QGTDEMOPLAND_H

#include <QWidget>
#include "ui_qgtdemopland.h"

class QGTDemoPlanD : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanD(QWidget *parent = 0);
	~QGTDemoPlanD();

private:
	Ui::QGTDemoPlanD ui;
};

#endif // QGTDEMOPLAND_H
