#ifndef QGTDEMOPLANSET_H
#define QGTDEMOPLANSET_H

#include <QWidget>
#include "ui_qgtdemoplanset.h"

#include "GlobalUnit.h"

class QGTDemoPlanSet : public QWidget
{
	Q_OBJECT

public:
	QGTDemoPlanSet(QWidget *parent = 0);
	~QGTDemoPlanSet();

	private slots:
	void on_toolButton_DemoPlanSet_Ok_pressed();
	void on_toolButton_DemoPlanSet_Cancel_pressed();
	void on_toolButton_DemoPlanSet_Reset_pressed();

	void on_comboBox_DemoPlanSet_Select_currentIndexChanged(int iValue);

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTDemoPlanSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTDEMOPLANSET_H
