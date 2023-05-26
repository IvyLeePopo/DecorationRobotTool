#include "qgtdrawlineset.h"

QGTDrawLineSet::QGTDrawLineSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);



	ui.doubleSpinBox_DrawLineSet_InitPos_X->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwX);
	ui.doubleSpinBox_DrawLineSet_InitPos_Y->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwY);
	ui.doubleSpinBox_DrawLineSet_InitPos_Z->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwZ);
	ui.doubleSpinBox_DrawLineSet_InitPos_U->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwU);
	ui.doubleSpinBox_DrawLineSet_InitPos_V->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwV);
	ui.doubleSpinBox_DrawLineSet_InitPos_W->setValue(g_pGlobalUnit->m_nDrawLine_InitPos.dwW);

	ui.doubleSpinBox_DrawLineSet_topLeft_X->setValue(g_pGlobalUnit->m_ptDrawLine_topLeft.x());
	ui.doubleSpinBox_DrawLineSet_topLeft_Y->setValue(g_pGlobalUnit->m_ptDrawLine_topLeft.y());
	ui.doubleSpinBox_DrawLineSet_topLeft_Z->setValue(g_pGlobalUnit->m_ptDrawLine_topLeft.z());

	ui.doubleSpinBox_DrawLineSet_Width->setValue(g_pGlobalUnit->m_dDrawLine_Width);
	ui.doubleSpinBox_DrawLineSet_Height->setValue(g_pGlobalUnit->m_dDrawLine_Height);

	ui.spinBox_DrawLineSet_LiftPlat_topPos->setValue(g_pGlobalUnit->m_iDrawLine_LiftPlat_topPos);
	ui.spinBox_DrawLineSet_LiftPlat_bottomPos->setValue(g_pGlobalUnit->m_iDrawLine_LiftPlat_bottomPos);

	ui.toolButton_DrawLineSet_Ok->SetButtonIcon("DrawLineSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_DrawLineSet_Cancel->SetButtonIcon("DrawLineSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_DrawLineSet_Reset->SetButtonIcon("DrawLineSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_LineFollowSet_Ok_pressed()), Qt::UniqueConnection);

}

QGTDrawLineSet::~QGTDrawLineSet()
{
	if (NULL != EnterKey)
	{
		delete EnterKey;
		EnterKey = NULL;
	}
}

void QGTDrawLineSet::on_toolButton_DrawLineSet_Ok_pressed()
{
	g_pGlobalUnit->m_nDrawLine_InitPos.dwX = ui.doubleSpinBox_DrawLineSet_InitPos_X->value();
	g_pGlobalUnit->m_nDrawLine_InitPos.dwY = ui.doubleSpinBox_DrawLineSet_InitPos_Y->value();
	g_pGlobalUnit->m_nDrawLine_InitPos.dwZ = ui.doubleSpinBox_DrawLineSet_InitPos_Z->value();
	g_pGlobalUnit->m_nDrawLine_InitPos.dwU = ui.doubleSpinBox_DrawLineSet_InitPos_U->value();
	g_pGlobalUnit->m_nDrawLine_InitPos.dwV = ui.doubleSpinBox_DrawLineSet_InitPos_V->value();
	g_pGlobalUnit->m_nDrawLine_InitPos.dwW = ui.doubleSpinBox_DrawLineSet_InitPos_W->value();

	g_pGlobalUnit->m_ptDrawLine_topLeft.setX(ui.doubleSpinBox_DrawLineSet_topLeft_X->value());
	g_pGlobalUnit->m_ptDrawLine_topLeft.setY(ui.doubleSpinBox_DrawLineSet_topLeft_Y->value());
	g_pGlobalUnit->m_ptDrawLine_topLeft.setZ(ui.doubleSpinBox_DrawLineSet_topLeft_Z->value());

	g_pGlobalUnit->m_dDrawLine_Width = ui.doubleSpinBox_DrawLineSet_Width->value();
	g_pGlobalUnit->m_dDrawLine_Height = ui.doubleSpinBox_DrawLineSet_Height->value();

	g_pGlobalUnit->m_iDrawLine_LiftPlat_topPos = ui.spinBox_DrawLineSet_LiftPlat_topPos->value();
	g_pGlobalUnit->m_iDrawLine_LiftPlat_bottomPos = ui.spinBox_DrawLineSet_LiftPlat_bottomPos->value();


	this->close();
}

void QGTDrawLineSet::on_toolButton_DrawLineSet_Cancel_pressed()
{
	this->close();
}

void QGTDrawLineSet::on_toolButton_DrawLineSet_Reset_pressed()
{
	ui.doubleSpinBox_DrawLineSet_InitPos_X->setValue(100);
	ui.doubleSpinBox_DrawLineSet_InitPos_Y->setValue(100);
	ui.doubleSpinBox_DrawLineSet_InitPos_Z->setValue(500);
	ui.doubleSpinBox_DrawLineSet_InitPos_U->setValue(0.11);
	ui.doubleSpinBox_DrawLineSet_InitPos_V->setValue(0.11);
	ui.doubleSpinBox_DrawLineSet_InitPos_W->setValue(0.11);

	ui.doubleSpinBox_DrawLineSet_topLeft_X->setValue(100);
	ui.doubleSpinBox_DrawLineSet_topLeft_Y->setValue(100);
	ui.doubleSpinBox_DrawLineSet_topLeft_Z->setValue(500);

	ui.doubleSpinBox_DrawLineSet_Width->setValue(300);
	ui.doubleSpinBox_DrawLineSet_Height->setValue(500);

	ui.spinBox_DrawLineSet_LiftPlat_topPos->setValue(1800);
	ui.spinBox_DrawLineSet_LiftPlat_bottomPos->setValue(700);
}

void QGTDrawLineSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTDrawLineSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTDrawLineSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}
