#ifndef GTDECORATIONROBOTTOOL_H
#define GTDECORATIONROBOTTOOL_H

#include <QtWidgets/QMainWindow>
#include "ui_gtdecorationrobottool.h"

#include "Commen/qgtthread.h"
#include "qgtloginpage.h"
#include "qgtcommunicationset.h"
#include "qgtdemoplanset.h"
#include "qgtlinefollowset.h"
#include "qgtdrawlineset.h"
#include "qgttilingset.h"
#include "qgtspraypaintset.h"
#include "qgtrosspraypaintset.h"

enum GT_MenuButon_Action_Type
{
	MBAT_Connect = 0,
	MBAT_Showlog = 1
};

class GTDecorationRobotTool : public QMainWindow
{
	Q_OBJECT

public:
	GTDecorationRobotTool(QWidget *parent = 0);
	~GTDecorationRobotTool();


	private slots:
	void on_toolButton_Login_pressed();
	void on_toolButton_MiniSize_pressed();
	void on_toolButton_Exit_pressed();

	void on_toolButton_Select_FunctionalDemo_pressed();
	void on_toolButton_Select_ModularControl_pressed();

	void on_toolButton_Auto_Run_pressed();

	void on_Update_Login_State();
	void on_Action_Connect_pressed();
	void on_Action_ShowLog_pressed();
	void on_Action_CommunicationSet_pressed();
	void on_Action_DemoPlanSet_pressed();
	void on_Action_LineFollowSet_pressed();
	void on_Action_DrawLineSet_pressed();
	void on_Action_TilingSet_pressed();
	void on_Action_SprayPaintSet_pressed();
	void on_Action_RosSprayPaintSet_pressed();

private:
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);
	void paintEvent(QPaintEvent *pEvent);

	void InitBaseSetMenu();
	void UpdateActionState(GT_MenuButon_Action_Type iType, bool bIsNormaStatel);

private:
	QAction *action_Connect;
	QAction *action_ShowLog;
	QAction *action_CommunicationSet;
	QAction *action_DemoPlanSet;
	QAction *action_LineFollowSet;
	QAction *action_DrawLineSet;
	QAction *action_TilingSet;
	QAction *action_SprayPaintSet;
	QAction *action_RosSprayPaintSet;

	QShortcut *EnterKey;

	bool m_bIsLeftMousePressed;
	QPoint m_ptMoveBegin;
private:
	Ui::GTDecorationRobotToolClass ui;
};

#endif // GTDECORATIONROBOTTOOL_H
