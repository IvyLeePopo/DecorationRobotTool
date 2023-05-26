#include "qgtrosspraypaintset.h"

QGTRosSprayPaintSet::QGTRosSprayPaintSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);

	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setValue(g_pGlobalUnit->m_iLidar_SearchTurning_Step);
	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setValue(g_pGlobalUnit->m_iLidar_SearchTurning_Dis_Threshold);
	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setValue(g_pGlobalUnit->m_iLidar_SearchTurning_Len_Threshold);

	ui.doubleSpinBox_RosSprayPaintSet_Dis_Precision->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Dis_Precision);
	ui.doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setValue(g_pGlobalUnit->m_dRos_SprayPaint_LiftPlat_InitPos);
	ui.doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Hor_WorkDis);
	ui.doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Ver_WorkDis);
	ui.doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Hor_Overlap);
	ui.doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Ver_Overlap);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setValue(g_pGlobalUnit->m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall);


	ui.toolButton_RosSprayPaintSet_Ok->SetButtonIcon("RosSprayPaintSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_RosSprayPaintSet_Cancel->SetButtonIcon("RosSprayPaintSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_RosSprayPaintSet_Reset->SetButtonIcon("RosSprayPaintSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_RosSprayPaintSet_Ok_pressed()), Qt::UniqueConnection);

}

QGTRosSprayPaintSet::~QGTRosSprayPaintSet()
{

}

void QGTRosSprayPaintSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTRosSprayPaintSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTRosSprayPaintSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

void QGTRosSprayPaintSet::on_toolButton_RosSprayPaintSet_Reset_pressed()
{
	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->setValue(20);
	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->setValue(100);
	ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->setValue(30);

	ui.doubleSpinBox_RosSprayPaintSet_Dis_Precision->setValue(2);
	ui.doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->setValue(650);
	ui.doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->setValue(400);
	ui.doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->setValue(400);
	ui.doubleSpinBox_RosSprayPaintSet_Hor_Overlap->setValue(0.3);
	ui.doubleSpinBox_RosSprayPaintSet_Ver_Overlap->setValue(0.3);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->setValue(2);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->setValue(500);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->setValue(700);
	ui.doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->setValue(3000);
}

void QGTRosSprayPaintSet::on_toolButton_RosSprayPaintSet_Ok_pressed()
{
	g_pGlobalUnit->m_iLidar_SearchTurning_Step = ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Step->value();
	g_pGlobalUnit->m_iLidar_SearchTurning_Dis_Threshold = ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Dis_Threshold->value();
	g_pGlobalUnit->m_iLidar_SearchTurning_Len_Threshold = ui.spinBox_RosSprayPaintSet_Lidar_SearchTurning_Len_Threshold->value();

	g_pGlobalUnit->m_dRos_SprayPaint_Dis_Precision = ui.doubleSpinBox_RosSprayPaintSet_Dis_Precision->value();
	g_pGlobalUnit->m_dRos_SprayPaint_LiftPlat_InitPos = ui.doubleSpinBox_RosSprayPaintSet_LiftPlat_InitPos->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Hor_WorkDis = ui.doubleSpinBox_RosSprayPaintSet_Hor_WorkDis->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Ver_WorkDis = ui.doubleSpinBox_RosSprayPaintSet_Ver_WorkDis->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Hor_Overlap = ui.doubleSpinBox_RosSprayPaintSet_Hor_Overlap->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Ver_Overlap = ui.doubleSpinBox_RosSprayPaintSet_Ver_Overlap->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Angle_Range_fromWorkwall = ui.doubleSpinBox_RosSprayPaintSet_Chasis_Angle_Range_fromWorkwall->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Chasis_Dis_Threshold_fromWorkwall = ui.doubleSpinBox_RosSprayPaintSet_Chasis_Dis_Threshold_fromWorkwall->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Chasis_MinDis_fromLeftwall = ui.doubleSpinBox_RosSprayPaintSet_Chasis_MinDis_fromLeftwall->value();
	g_pGlobalUnit->m_dRos_SprayPaint_Chasis_MaxDis_fromLeftwall = ui.doubleSpinBox_RosSprayPaintSet_Chasis_MaxDis_fromLeftwall->value();

	this->close();
}

void QGTRosSprayPaintSet::on_toolButton_RosSprayPaintSet_Cancel_pressed()
{
	this->close();
}
