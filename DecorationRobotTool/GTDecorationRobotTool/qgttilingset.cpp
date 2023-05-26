#include "qgttilingset.h"

QGTTilingSet::QGTTilingSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);



	ui.doubleSpinBox_TilingSet_InitPos_X->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwX);
	ui.doubleSpinBox_TilingSet_InitPos_Y->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwY);
	ui.doubleSpinBox_TilingSet_InitPos_Z->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwZ);
	ui.doubleSpinBox_TilingSet_InitPos_U->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwU);
	ui.doubleSpinBox_TilingSet_InitPos_V->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwV);
	ui.doubleSpinBox_TilingSet_InitPos_W->setValue(g_pGlobalUnit->m_nTiling_InitPos.dwW);

	ui.doubleSpinBox_TilingSet_Material_InitPos_X->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwX);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Y->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwY);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Z->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwZ);
	ui.doubleSpinBox_TilingSet_Material_InitPos_U->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwU);
	ui.doubleSpinBox_TilingSet_Material_InitPos_V->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwV);
	ui.doubleSpinBox_TilingSet_Material_InitPos_W->setValue(g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwW);

	ui.doubleSpinBox_TilingSet_Paste_InitPos_X->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwX);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Y->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwY);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Z->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwZ);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_U->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwU);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_V->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwV);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_W->setValue(g_pGlobalUnit->m_nTiling_InitPos_Paste.dwW);

	ui.doubleSpinBox_TilingSet_Material_InitAngle_X->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwX);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Y->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwY);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Z->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwZ);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_U->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwU);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_V->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwV);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_W->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwW);

	ui.doubleSpinBox_TilingSet_Paste_InitAngle_X->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwX);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Y->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwY);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Z->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwZ);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_U->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwU);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_V->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwV);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_W->setValue(g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwW);

	ui.doubleSpinBox_TilingSet_Material_Width->setValue(g_pGlobalUnit->m_dTiling_Materiel_Width);
	ui.doubleSpinBox_TilingSet_Material_Thickness->setValue(g_pGlobalUnit->m_dTiling_Materiel_Thickness);
	ui.doubleSpinBox_TilingSet_Paste_Feed->setValue(g_pGlobalUnit->m_dTiling_Paste_Feed);
	ui.spinBox_TilingSet_Material_Num->setValue(g_pGlobalUnit->m_iTiling_Materiel_Num);
	ui.spinBox_TilingSet_Pressure->setValue(g_pGlobalUnit->m_iTiling_Pressure_Range);

	ui.toolButton_TilingSet_InitPos_Read->SetButtonIcon("TilingSet_InitPos_Read", QSize(180, 80), TBT_Round_Rect);
	ui.toolButton_TilingSet_Material_InitPos_Read->SetButtonIcon("TilingSet_Material_InitPos_Read", QSize(180, 80), TBT_Round_Rect);
	ui.toolButton_TilingSet_Paste_InitPos_Read->SetButtonIcon("TilingSet_Paste_InitPos_Read", QSize(180, 80), TBT_Round_Rect);
	

	ui.toolButton_TilingSet_Ok->SetButtonIcon("TilingSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_TilingSet_Cancel->SetButtonIcon("TilingSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_TilingSet_Reset->SetButtonIcon("TilingSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_TilingSet_Ok_pressed()), Qt::UniqueConnection);
}

QGTTilingSet::~QGTTilingSet()
{

}

void QGTTilingSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTTilingSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTTilingSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

void QGTTilingSet::on_toolButton_TilingSet_InitPos_Read_pressed()
{
	ui.doubleSpinBox_TilingSet_InitPos_X->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwX);
	ui.doubleSpinBox_TilingSet_InitPos_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwY);
	ui.doubleSpinBox_TilingSet_InitPos_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwZ);
	ui.doubleSpinBox_TilingSet_InitPos_U->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwU);
	ui.doubleSpinBox_TilingSet_InitPos_V->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwV);
	ui.doubleSpinBox_TilingSet_InitPos_W->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwW);
}

void QGTTilingSet::on_toolButton_TilingSet_Material_InitPos_Read_pressed()
{
	ui.doubleSpinBox_TilingSet_Material_InitPos_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_TilingSet_Material_InitPos_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_TilingSet_Material_InitPos_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_TilingSet_Material_InitPos_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);

	ui.doubleSpinBox_TilingSet_Material_InitAngle_X->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwX);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwY);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwZ);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_U->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwU);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_V->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwV);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_W->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwW);
}

void QGTTilingSet::on_toolButton_TilingSet_Paste_InitPos_Read_pressed()
{
	ui.doubleSpinBox_TilingSet_Paste_InitPos_X->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwX);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwY);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwZ);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_U->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwU);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_V->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwV);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_W->setValue(g_pGlobalUnit->m_nRobot_Actual_SpacePos.dwW);

	ui.doubleSpinBox_TilingSet_Paste_InitAngle_X->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwX);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Y->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwY);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Z->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwZ);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_U->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwU);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_V->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwV);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_W->setValue(g_pGlobalUnit->m_nRobot_Actual_JointAngle.dwW);
}

void QGTTilingSet::on_toolButton_TilingSet_Ok_pressed()
{
	g_pGlobalUnit->m_nTiling_InitPos.dwX = ui.doubleSpinBox_TilingSet_InitPos_X->value();
	g_pGlobalUnit->m_nTiling_InitPos.dwY = ui.doubleSpinBox_TilingSet_InitPos_Y->value();
	g_pGlobalUnit->m_nTiling_InitPos.dwZ = ui.doubleSpinBox_TilingSet_InitPos_Z->value();
	g_pGlobalUnit->m_nTiling_InitPos.dwU = ui.doubleSpinBox_TilingSet_InitPos_U->value();
	g_pGlobalUnit->m_nTiling_InitPos.dwV = ui.doubleSpinBox_TilingSet_InitPos_V->value();
	g_pGlobalUnit->m_nTiling_InitPos.dwW = ui.doubleSpinBox_TilingSet_InitPos_W->value();

	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwX = ui.doubleSpinBox_TilingSet_Material_InitPos_X->value();
	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwY = ui.doubleSpinBox_TilingSet_Material_InitPos_Y->value();
	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwZ = ui.doubleSpinBox_TilingSet_Material_InitPos_Z->value();
	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwU = ui.doubleSpinBox_TilingSet_Material_InitPos_U->value();
	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwV = ui.doubleSpinBox_TilingSet_Material_InitPos_V->value();
	g_pGlobalUnit->m_nTiling_InitPos_Materiel.dwW = ui.doubleSpinBox_TilingSet_Material_InitPos_W->value();

	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwX = ui.doubleSpinBox_TilingSet_Paste_InitPos_X->value();
	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwY = ui.doubleSpinBox_TilingSet_Paste_InitPos_Y->value();
	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwZ = ui.doubleSpinBox_TilingSet_Paste_InitPos_Z->value();
	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwU = ui.doubleSpinBox_TilingSet_Paste_InitPos_U->value();
	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwV = ui.doubleSpinBox_TilingSet_Paste_InitPos_V->value();
	g_pGlobalUnit->m_nTiling_InitPos_Paste.dwW = ui.doubleSpinBox_TilingSet_Paste_InitPos_W->value();

	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwX = ui.doubleSpinBox_TilingSet_Material_InitAngle_X->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwY = ui.doubleSpinBox_TilingSet_Material_InitAngle_Y->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwZ = ui.doubleSpinBox_TilingSet_Material_InitAngle_Z->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwU = ui.doubleSpinBox_TilingSet_Material_InitAngle_U->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwV = ui.doubleSpinBox_TilingSet_Material_InitAngle_V->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Materiel.dwW = ui.doubleSpinBox_TilingSet_Material_InitAngle_W->value();

	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwX = ui.doubleSpinBox_TilingSet_Paste_InitAngle_X->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwY = ui.doubleSpinBox_TilingSet_Paste_InitAngle_Y->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwZ = ui.doubleSpinBox_TilingSet_Paste_InitAngle_Z->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwU = ui.doubleSpinBox_TilingSet_Paste_InitAngle_U->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwV = ui.doubleSpinBox_TilingSet_Paste_InitAngle_V->value();
	g_pGlobalUnit->m_nTiling_InitAngle_Paste.dwW = ui.doubleSpinBox_TilingSet_Paste_InitAngle_W->value();

	g_pGlobalUnit->m_dTiling_Materiel_Width = ui.doubleSpinBox_TilingSet_Material_Width->value();
	g_pGlobalUnit->m_dTiling_Materiel_Thickness = ui.doubleSpinBox_TilingSet_Material_Thickness->value();
	g_pGlobalUnit->m_dTiling_Paste_Feed = ui.doubleSpinBox_TilingSet_Paste_Feed->value();
	g_pGlobalUnit->m_iTiling_Materiel_Num = ui.spinBox_TilingSet_Material_Num->value();
	g_pGlobalUnit->m_iTiling_Pressure_Range = ui.spinBox_TilingSet_Pressure->value();


	this->close();
}

void QGTTilingSet::on_toolButton_TilingSet_Cancel_pressed()
{
	this->close();
}

void QGTTilingSet::on_toolButton_TilingSet_Reset_pressed()
{
	ui.doubleSpinBox_TilingSet_Material_InitPos_X->setValue(0);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Y->setValue(-360);
	ui.doubleSpinBox_TilingSet_Material_InitPos_Z->setValue(0);
	ui.doubleSpinBox_TilingSet_Material_InitPos_U->setValue(-360);
	ui.doubleSpinBox_TilingSet_Material_InitPos_V->setValue(-359.9);
	ui.doubleSpinBox_TilingSet_Material_InitPos_W->setValue(0);

	ui.doubleSpinBox_TilingSet_Paste_InitPos_X->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Y->setValue(-360);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_Z->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_U->setValue(-360);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_V->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitPos_W->setValue(0);

	ui.doubleSpinBox_TilingSet_Material_InitAngle_X->setValue(0);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Y->setValue(-360);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_Z->setValue(0);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_U->setValue(-360);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_V->setValue(0);
	ui.doubleSpinBox_TilingSet_Material_InitAngle_W->setValue(0);

	ui.doubleSpinBox_TilingSet_Paste_InitAngle_X->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Y->setValue(-360);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_Z->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_U->setValue(-360);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_V->setValue(0);
	ui.doubleSpinBox_TilingSet_Paste_InitAngle_W->setValue(0);

	ui.doubleSpinBox_TilingSet_Material_Width->setValue(100);
	ui.doubleSpinBox_TilingSet_Material_Thickness->setValue(10);
	ui.doubleSpinBox_TilingSet_Paste_Feed->setValue(200);
	ui.spinBox_TilingSet_Material_Num->setValue(16);
	ui.spinBox_TilingSet_Pressure->setValue(100);
}
