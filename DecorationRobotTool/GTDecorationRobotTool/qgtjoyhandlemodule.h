#ifndef QGTJOYHANDLEMODULE_H
#define QGTJOYHANDLEMODULE_H

#include <QWidget>
#include "ui_qgtjoyhandlemodule.h"

#include "GlobalUnit.h"

class QGTJoyHandleModule : public QWidget
{
	Q_OBJECT

public:
	QGTJoyHandleModule(QWidget *parent = 0);
	~QGTJoyHandleModule();


	private slots:
	void Update_ActualInfo_JoyHandle();

private:
	void Update_Info_JoyHandle();
	void Update_Control_JoyHandle();

private:
	Ui::QGTJoyHandleModule ui;
};

#endif // QGTJOYHANDLEMODULE_H
