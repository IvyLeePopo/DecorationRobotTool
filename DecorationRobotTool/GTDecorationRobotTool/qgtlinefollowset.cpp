#include "qgtlinefollowset.h"

QGTLineFollowSet::QGTLineFollowSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);


	ui.doubleSpinBox_LineFollowSet_Calibration->setValue(g_pGlobalUnit->m_dLineFollowSet_Calibration);
	ui.spinBox_LineFollowSet_SearchThreshold->setValue(g_pGlobalUnit->m_iLineFollowSet_SearchThreshold);
	ui.spinBox_LineFollowSet_MinBinaryThreshold->setValue(g_pGlobalUnit->m_iLineFollowSet_MinBinaryThreshold);
	ui.spinBox_LineFollowSet_MaxBinaryThreshold->setValue(g_pGlobalUnit->m_iLineFollowSet_MaxBinaryThreshold);
	ui.spinBox_LineFollowSet_MinContourArea->setValue(g_pGlobalUnit->m_iLineFollowSet_MinContourArea);
	ui.spinBox_LineFollowSet_MaxContourArea->setValue(g_pGlobalUnit->m_iLineFollowSet_MaxContourArea);
	ui.doubleSpinBox_LineFollowSet_AngleRange->setValue(g_pGlobalUnit->m_dLineFollowSet_AngleRange);
	ui.doubleSpinBox_LineFollowSet_DisRange->setValue(g_pGlobalUnit->m_dLineFollowSet_DisRange);
	ui.spinBox_LineFollowSet_TargetDis->setValue(g_pGlobalUnit->m_iLineFollowSet_TargetDis);
	ui.spinBox_LineFollowSet_SpeedRate->setValue(g_pGlobalUnit->m_iLineFollowSet_SpeedRate);

	ui.toolButton_LineFollowSet_Ok->SetButtonIcon("LineFollowSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_LineFollowSet_Cancel->SetButtonIcon("LineFollowSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_LineFollowSet_Reset->SetButtonIcon("LineFollowSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_LineFollowSet_Ok_pressed()), Qt::UniqueConnection);
}

QGTLineFollowSet::~QGTLineFollowSet()
{
	if (NULL != EnterKey)
	{
		delete EnterKey;
		EnterKey = NULL;
	}
}

void QGTLineFollowSet::on_toolButton_LineFollowSet_Ok_pressed()
{
	g_pGlobalUnit->m_dLineFollowSet_Calibration = ui.doubleSpinBox_LineFollowSet_Calibration->value();
	g_pGlobalUnit->m_iLineFollowSet_SearchThreshold = ui.spinBox_LineFollowSet_SearchThreshold->value();
	g_pGlobalUnit->m_iLineFollowSet_MinBinaryThreshold = ui.spinBox_LineFollowSet_MinBinaryThreshold->value();
	g_pGlobalUnit->m_iLineFollowSet_MaxBinaryThreshold = ui.spinBox_LineFollowSet_MaxBinaryThreshold->value();
	g_pGlobalUnit->m_iLineFollowSet_MinContourArea = ui.spinBox_LineFollowSet_MinContourArea->value();
	g_pGlobalUnit->m_iLineFollowSet_MaxContourArea = ui.spinBox_LineFollowSet_MaxContourArea->value();
	g_pGlobalUnit->m_dLineFollowSet_AngleRange = ui.doubleSpinBox_LineFollowSet_AngleRange->value();
	g_pGlobalUnit->m_dLineFollowSet_DisRange = ui.doubleSpinBox_LineFollowSet_DisRange->value();
	g_pGlobalUnit->m_iLineFollowSet_TargetDis = ui.spinBox_LineFollowSet_TargetDis->value();
	g_pGlobalUnit->m_iLineFollowSet_SpeedRate = ui.spinBox_LineFollowSet_SpeedRate->value();

	this->close();
}

void QGTLineFollowSet::on_toolButton_LineFollowSet_Cancel_pressed()
{
	this->close();
}

void QGTLineFollowSet::on_toolButton_LineFollowSet_Reset_pressed()
{
	ui.doubleSpinBox_LineFollowSet_Calibration->setValue(0.307594);
	ui.spinBox_LineFollowSet_SearchThreshold->setValue(90);
	ui.spinBox_LineFollowSet_MinBinaryThreshold->setValue(160);
	ui.spinBox_LineFollowSet_MaxBinaryThreshold->setValue(255);
	ui.spinBox_LineFollowSet_MinContourArea->setValue(200);
	ui.spinBox_LineFollowSet_MaxContourArea->setValue(100000);
	ui.doubleSpinBox_LineFollowSet_AngleRange->setValue(3);
	ui.doubleSpinBox_LineFollowSet_DisRange->setValue(50);
	ui.spinBox_LineFollowSet_TargetDis->setValue(100);
	ui.spinBox_LineFollowSet_SpeedRate->setValue(2);
}

void QGTLineFollowSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTLineFollowSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTLineFollowSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}
