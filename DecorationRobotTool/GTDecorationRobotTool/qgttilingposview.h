#ifndef QGTTILINGPOSVIEW_H
#define QGTTILINGPOSVIEW_H

#include <QTableWidget>
#include <QHeaderView>
#include <QFont>
#include <QEvent>
#include <QMouseEvent>

#include "GlobalUnit.h"

class QGTTilingPosView : public QTableWidget
{
	Q_OBJECT

public:
	QGTTilingPosView(QWidget *parent);
	~QGTTilingPosView();

public:
	void Init_PosView(const QString strHead_1, const QString strHead_2, const QString strHead_3, const QString strHead_4, const QString strHead_5, const QString strHead_6);
	void Update_PosView(const GT_RobotArm_Pose pose_Input);
	void Clear_PosView();

private:
	void Display_SingleRow(const GT_RobotArm_Pose pose_Input);
};

#endif // QGTTILINGPOSVIEW_H
