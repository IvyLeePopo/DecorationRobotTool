#ifndef QGTLINEFOLLOWSET_H
#define QGTLINEFOLLOWSET_H

#include <QWidget>
#include "ui_qgtlinefollowset.h"

#include "GlobalUnit.h"

class QGTLineFollowSet : public QWidget
{
	Q_OBJECT

public:
	QGTLineFollowSet(QWidget *parent = 0);
	~QGTLineFollowSet();

	private slots:
	void on_toolButton_LineFollowSet_Ok_pressed();
	void on_toolButton_LineFollowSet_Cancel_pressed();
	void on_toolButton_LineFollowSet_Reset_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTLineFollowSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTLINEFOLLOWSET_H
