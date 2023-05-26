#ifndef QGTLOGINPAGE_H
#define QGTLOGINPAGE_H

#include <QWidget>
#include "ui_qgtloginpage.h"

#include "GlobalUnit.h"

class QGTLoginPage : public QWidget
{
	Q_OBJECT

public:
	QGTLoginPage(QWidget *parent = 0);
	~QGTLoginPage();

signals:
	void Update_Login_State();

	private slots:
	void on_toolButton_Login_Ok_pressed();
	void on_toolButton_Login_Cancel_pressed();

private:
	bool IsValidPassword();
private:
	Ui::QGTLoginPage ui;
	QShortcut *EnterKey;
};

#endif // QGTLOGINPAGE_H
