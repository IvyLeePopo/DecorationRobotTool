#ifndef QGTTILINGSET_H
#define QGTTILINGSET_H

#include <QWidget>
#include "ui_qgttilingset.h"

#include "GlobalUnit.h"

class QGTTilingSet : public QWidget
{
	Q_OBJECT

public:
	QGTTilingSet(QWidget *parent = 0);
	~QGTTilingSet();

	private slots:
	void on_toolButton_TilingSet_InitPos_Read_pressed();
	void on_toolButton_TilingSet_Material_InitPos_Read_pressed();
	void on_toolButton_TilingSet_Paste_InitPos_Read_pressed();

	void on_toolButton_TilingSet_Ok_pressed();
	void on_toolButton_TilingSet_Cancel_pressed();
	void on_toolButton_TilingSet_Reset_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

private:
	Ui::QGTTilingSet ui;
	QShortcut *EnterKey;

	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;

};

#endif // QGTTILINGSET_H
