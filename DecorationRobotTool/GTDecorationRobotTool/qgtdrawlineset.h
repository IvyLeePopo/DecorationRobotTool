#ifndef QGTDRAWLINESET_H
#define QGTDRAWLINESET_H

#include <QWidget>
#include "ui_qgtdrawlineset.h"

#include "GlobalUnit.h"

class QGTDrawLineSet : public QWidget
{
	Q_OBJECT

public:
	QGTDrawLineSet(QWidget *parent = 0);
	~QGTDrawLineSet();

	private slots:
	void on_toolButton_DrawLineSet_Ok_pressed();
	void on_toolButton_DrawLineSet_Cancel_pressed();
	void on_toolButton_DrawLineSet_Reset_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTDrawLineSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTDRAWLINESET_H
