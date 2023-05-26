#include "qgtspraypaintset.h"

QGTSprayPaintSet::QGTSprayPaintSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);


	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_X->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwX);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Y->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwY);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Z->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_U->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwU);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_V->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwV);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_W->setValue(g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwW);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_X->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwX);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Y->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwY);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Z->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwZ);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_U->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwU);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_V->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwV);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_W->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwW);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_X->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwX);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Y->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwY);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Z->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwZ);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_U->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwU);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_V->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwV);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_W->setValue(g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwW);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_X->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwX);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Y->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwY);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Z->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwZ);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_U->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwU);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_V->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwV);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_W->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwW);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_X->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwX);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Y->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwY);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Z->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwZ);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_U->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwU);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_V->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwV);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_W->setValue(g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwW);


	ui.checkBox_SprayPaintSet_Enable_VerInsideCorner->setChecked(g_pGlobalUnit->m_bIs_SprayPaint_VerInsideCorner_Enable);
	ui.checkBox_SprayPaintSet_Enable_HorInsideCorner->setChecked(g_pGlobalUnit->m_bIs_SprayPaint_HorInsideCorner_Enable);
	ui.spinBox_SprayPaintSet_Count_VerInsideCorner->setValue(g_pGlobalUnit->m_iSprayPaint_Count_VerInsideCorner);
	ui.spinBox_SprayPaintSet_Count_HorInsideCorner->setValue(g_pGlobalUnit->m_iSprayPaint_Count_HorInsideCorner);

	Enable_VerInsideCorner(g_pGlobalUnit->m_bIs_SprayPaint_VerInsideCorner_Enable);
	Enable_HorInsideCorner(g_pGlobalUnit->m_bIs_SprayPaint_HorInsideCorner_Enable);

	ui.spinBox_SprayPaintSet_Count_MovedBy_Chasis->setValue(g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_Chasis);
	ui.spinBox_SprayPaintSet_Count_MovedBy_LiftPlat->setValue(g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_LiftPlat);
	ui.spinBox_SprayPaintSet_Count_MovedBy_Robot->setValue(g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_Robot);

	ui.doubleSpinBox_SprayPaintSet_LiftPlat_InitPos->setValue(g_pGlobalUnit->m_dSprayPaint_LiftPlat_InitPos);
	ui.doubleSpinBox_SprayPaintSet_HorDis_MovedBy_Robot->setValue(g_pGlobalUnit->m_dSprayPaint_HorDis_MovedBy_Robot);
	ui.doubleSpinBox_SprayPaintSet_Width_By_Spray->setValue(g_pGlobalUnit->m_dSprayPaint_Width_By_Spray);

	ui.doubleSpinBox_SprayPaintSet_Overlap_By_Robot->setValue(g_pGlobalUnit->m_dSprayPaint_Overlap_By_Robot);
	ui.doubleSpinBox_SprayPaintSet_Overlap_By_LiftPlat->setValue(g_pGlobalUnit->m_dSprayPaint_Overlap_By_LiftPlat);
	ui.doubleSpinBox_SprayPaintSet_Overlap_By_Chasis->setValue(g_pGlobalUnit->m_dSprayPaint_Overlap_By_Chasis);

	ui.toolButton_SprayPaintSet_Read_RobotInfo->SetButtonIcon("SprayPaintSet_Read_RobotInfo", QSize(160, 50), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Set_Robot_InitPos->SetButtonIcon("SprayPaintSet_Set_Robot_InitPos", QSize(160, 50), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_A->SetButtonIcon("SprayPaintSet_Set_VerInsideCorner_RobotPos_A", QSize(180, 30), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_B->SetButtonIcon("SprayPaintSet_Set_VerInsideCorner_RobotPos_B", QSize(180, 30), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_A->SetButtonIcon("SprayPaintSet_Set_HorInsideCorner_RobotPos_A", QSize(180, 30), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_B->SetButtonIcon("SprayPaintSet_Set_HorInsideCorner_RobotPos_B", QSize(180, 30), TBT_Round_Rect);

	ui.toolButton_SprayPaintSet_Ok->SetButtonIcon("SprayPaintSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Cancel->SetButtonIcon("SprayPaintSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_SprayPaintSet_Reset->SetButtonIcon("SprayPaintSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_SprayPaintSet_Ok_pressed()), Qt::UniqueConnection);

}

QGTSprayPaintSet::~QGTSprayPaintSet()
{

}

void QGTSprayPaintSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTSprayPaintSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTSprayPaintSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

void QGTSprayPaintSet::Enable_VerInsideCorner(bool bIsChecked)
{
	ui.spinBox_SprayPaintSet_Count_VerInsideCorner->setEnabled(bIsChecked);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_X->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Y->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Z->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_U->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_V->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_W->setEnabled(bIsChecked);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_X->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Y->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Z->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_U->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_V->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_W->setEnabled(bIsChecked);

	ui.toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_A->setEnabled(bIsChecked);
	ui.toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_B->setEnabled(bIsChecked);
}

void QGTSprayPaintSet::Enable_HorInsideCorner(bool bIsChecked)
{
	ui.spinBox_SprayPaintSet_Count_HorInsideCorner->setEnabled(bIsChecked);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_X->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Y->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Z->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_U->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_V->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_W->setEnabled(bIsChecked);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_X->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Y->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Z->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_U->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_V->setEnabled(bIsChecked);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_W->setEnabled(bIsChecked);

	ui.toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_A->setEnabled(bIsChecked);
	ui.toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_B->setEnabled(bIsChecked);
}

void QGTSprayPaintSet::on_checkBox_SprayPaintSet_Enable_VerInsideCorner_clicked(bool bIsChecked)
{
	Enable_VerInsideCorner(bIsChecked);
}

void QGTSprayPaintSet::on_checkBox_SprayPaintSet_Enable_HorInsideCorner_clicked(bool bIsChecked)
{
	Enable_HorInsideCorner(bIsChecked);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Read_RobotInfo_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_Actual_RobotPos_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Set_Robot_InitPos_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_A_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Set_VerInsideCorner_RobotPos_B_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_A_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Set_HorInsideCorner_RobotPos_B_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Reset_pressed()
{
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_X->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Y->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Z->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_U->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_V->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_W->setValue(0);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_X->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Y->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Z->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_U->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_V->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_W->setValue(0);

	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_X->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Y->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Z->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_U->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_V->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_W->setValue(0);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_X->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Y->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Z->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_U->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_V->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_W->setValue(0);

	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_X->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Y->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Z->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_U->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_V->setValue(0);
	ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_W->setValue(0);


	ui.checkBox_SprayPaintSet_Enable_VerInsideCorner->setChecked(false);
	ui.checkBox_SprayPaintSet_Enable_HorInsideCorner->setChecked(false);
	ui.spinBox_SprayPaintSet_Count_VerInsideCorner->setValue(6);
	ui.spinBox_SprayPaintSet_Count_HorInsideCorner->setValue(6);

	ui.spinBox_SprayPaintSet_Count_MovedBy_Chasis->setValue(2);
	ui.spinBox_SprayPaintSet_Count_MovedBy_LiftPlat->setValue(5);
	ui.spinBox_SprayPaintSet_Count_MovedBy_Robot->setValue(2);

	ui.doubleSpinBox_SprayPaintSet_LiftPlat_InitPos->setValue(700);
	ui.doubleSpinBox_SprayPaintSet_HorDis_MovedBy_Robot->setValue(400);
	ui.doubleSpinBox_SprayPaintSet_Width_By_Spray->setValue(115);

	ui.doubleSpinBox_SprayPaintSet_Overlap_By_Robot->setValue(0.3);
	ui.doubleSpinBox_SprayPaintSet_Overlap_By_LiftPlat->setValue(0.3);
	ui.doubleSpinBox_SprayPaintSet_Overlap_By_Chasis->setValue(0.1);

}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Ok_pressed()
{
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwX = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_X->value();
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwY = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Y->value();
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwZ = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_Z->value();
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwU = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_U->value();
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwV = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_V->value();
	g_pGlobalUnit->m_nSprayPaint_Robot_InitPos.dwW = ui.doubleSpinBox_SprayPaintSet_Robot_InitPos_W->value();

	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwX = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_X->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwY = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Y->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwZ = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_Z->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwU = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_U->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwV = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_V->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_A.dwW = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_A_W->value();

	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwX = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_X->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwY = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Y->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwZ = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_Z->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwU = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_U->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwV = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_V->value();
	g_pGlobalUnit->m_nSprayPaintSet_VerInsideCorner_RobotPos_B.dwW = ui.doubleSpinBox_SprayPaintSet_VerInsideCorner_RobotPos_B_W->value();

	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwX = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_X->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwY = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Y->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwZ = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_Z->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwU = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_U->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwV = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_V->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_A.dwW = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_A_W->value();

	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwX = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_X->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwY = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Y->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwZ = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_Z->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwU = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_U->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwV = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_V->value();
	g_pGlobalUnit->m_nSprayPaintSet_HorInsideCorner_RobotPos_B.dwW = ui.doubleSpinBox_SprayPaintSet_HorInsideCorner_RobotPos_B_W->value();


	g_pGlobalUnit->m_bIs_SprayPaint_VerInsideCorner_Enable = ui.checkBox_SprayPaintSet_Enable_VerInsideCorner->isChecked();
	g_pGlobalUnit->m_bIs_SprayPaint_HorInsideCorner_Enable = ui.checkBox_SprayPaintSet_Enable_HorInsideCorner->isChecked();
	g_pGlobalUnit->m_iSprayPaint_Count_VerInsideCorner = ui.spinBox_SprayPaintSet_Count_VerInsideCorner->value();
	g_pGlobalUnit->m_iSprayPaint_Count_HorInsideCorner = ui.spinBox_SprayPaintSet_Count_HorInsideCorner->value();

	g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_Chasis = ui.spinBox_SprayPaintSet_Count_MovedBy_Chasis->value();
	g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_LiftPlat = ui.spinBox_SprayPaintSet_Count_MovedBy_LiftPlat->value();
	g_pGlobalUnit->m_iSprayPaint_Count_MovedBy_Robot = ui.spinBox_SprayPaintSet_Count_MovedBy_Robot->value();

	g_pGlobalUnit->m_dSprayPaint_LiftPlat_InitPos = ui.doubleSpinBox_SprayPaintSet_LiftPlat_InitPos->value();
	g_pGlobalUnit->m_dSprayPaint_HorDis_MovedBy_Robot = ui.doubleSpinBox_SprayPaintSet_HorDis_MovedBy_Robot->value();
	g_pGlobalUnit->m_dSprayPaint_Width_By_Spray = ui.doubleSpinBox_SprayPaintSet_Width_By_Spray->value();

	g_pGlobalUnit->m_dSprayPaint_Overlap_By_Robot = ui.doubleSpinBox_SprayPaintSet_Overlap_By_Robot->value();
	g_pGlobalUnit->m_dSprayPaint_Overlap_By_LiftPlat = ui.doubleSpinBox_SprayPaintSet_Overlap_By_LiftPlat->value();
	g_pGlobalUnit->m_dSprayPaint_Overlap_By_Chasis = ui.doubleSpinBox_SprayPaintSet_Overlap_By_Chasis->value();


	this->close();
}

void QGTSprayPaintSet::on_toolButton_SprayPaintSet_Cancel_pressed()
{
	this->close();
}

