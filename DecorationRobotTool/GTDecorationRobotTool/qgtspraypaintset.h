#ifndef QGTSPRAYPAINTSET_H
#define QGTSPRAYPAINTSET_H

#include <QWidget>
#include "ui_qgtspraypaintset.h"

#include "GlobalUnit.h"

class QGTSprayPaintSet : public QWidget
{
	Q_OBJECT

public:
	QGTSprayPaintSet(QWidget *parent = 0);
	~QGTSprayPaintSet();


	private slots:

	void on_checkBox_SprayPaintSet_Enable_VerInsideCorner_clicked(bool bIsChecked);
	void on_checkBox_SprayPaintSet_Enable_HorInsideCorner_clicked(bool bIsChecked);

	void on_toolButton_SprayPaintSet_Read_RobotInfo_pressed();
	void on_toolButton_SprayPaintSet_Set_Robot_InitPos_pressed();
	void on_toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_A_pressed();
	void on_toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_B_pressed();
	void on_toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_A_pressed();
	void on_toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_B_pressed();

	void on_toolButton_SprayPaintSet_Reset_pressed();
	void on_toolButton_SprayPaintSet_Ok_pressed();
	void on_toolButton_SprayPaintSet_Cancel_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);

	void Enable_VerInsideCorner(bool bIsChecked);

	void Enable_HorInsideCorner(bool bIsChecked);

private:
	Ui::QGTSprayPaintSet ui;
	QShortcut *EnterKey;
	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
};

#endif // QGTSPRAYPAINTSET_H
