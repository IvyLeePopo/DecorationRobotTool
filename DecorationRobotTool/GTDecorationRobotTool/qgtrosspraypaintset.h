#ifndef QGTROSSPRAYPAINTSET_H
#define QGTROSSPRAYPAINTSET_H

#include <QWidget>
#include "ui_qgtrosspraypaintset.h"

#include "GlobalUnit.h"

class QGTRosSprayPaintSet : public QWidget
{
	Q_OBJECT

public:
	QGTRosSprayPaintSet(QWidget *parent = 0);
	~QGTRosSprayPaintSet();


	private slots:
	void on_toolButton_RosSprayPaintSet_Reset_pressed();
	void on_toolButton_RosSprayPaintSet_Ok_pressed();
	void on_toolButton_RosSprayPaintSet_Cancel_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTRosSprayPaintSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTROSSPRAYPAINTSET_H
