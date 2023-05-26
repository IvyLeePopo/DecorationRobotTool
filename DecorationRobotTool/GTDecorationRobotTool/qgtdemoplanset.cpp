#include "qgtdemoplanset.h"

QGTDemoPlanSet::QGTDemoPlanSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);

	ui.comboBox_DemoPlanSet_Select->addItem("A", 0);
	ui.comboBox_DemoPlanSet_Select->addItem("B", 1);
	ui.comboBox_DemoPlanSet_Select->addItem("C", 2);
	ui.comboBox_DemoPlanSet_Select->addItem("D", 3);
	ui.comboBox_DemoPlanSet_Select->addItem("E", 4);
	ui.comboBox_DemoPlanSet_Select->addItem("F", 4);



	ui.comboBox_DemoPlanSet_Select->setCurrentIndex(g_pGlobalUnit->m_iDemoPlanSet_Index);

	ui.toolButton_DemoPlanSet_Ok->SetButtonIcon("DemoPlanSet_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_DemoPlanSet_Cancel->SetButtonIcon("DemoPlanSet_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_DemoPlanSet_Reset->SetButtonIcon("DemoPlanSet_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_DemoPlanSet_Ok_pressed()), Qt::UniqueConnection);
}

QGTDemoPlanSet::~QGTDemoPlanSet()
{
	if (NULL != EnterKey)
	{
		delete EnterKey;
		EnterKey = NULL;
	}
}

void QGTDemoPlanSet::on_toolButton_DemoPlanSet_Ok_pressed()
{
	g_pGlobalUnit->m_iDemoPlanSet_Index = ui.comboBox_DemoPlanSet_Select->currentIndex();

	this->close();
}

void QGTDemoPlanSet::on_toolButton_DemoPlanSet_Cancel_pressed()
{
	this->close();
}

void QGTDemoPlanSet::on_toolButton_DemoPlanSet_Reset_pressed()
{
	ui.comboBox_DemoPlanSet_Select->setCurrentIndex(2);
}

void QGTDemoPlanSet::on_comboBox_DemoPlanSet_Select_currentIndexChanged(int iValue)
{
	QString strValue = "";
	if (iValue == 0)
	{
		strValue = QString::fromLocal8Bit("1、循线(沿激光线前行到指定位置)");
	}
	else if (iValue == 1)
	{
		strValue = QString::fromLocal8Bit("1、循线(沿激光线前行到指定位置)\n2、结构光检测(结构光投影光栅条纹检测墙面上的缺陷点) \n3、打磨");
	}
	else if (iValue == 2)
	{
		strValue = QString::fromLocal8Bit("1、画线(机械臂模拟装修前画线工艺，在墙面上画出一个矩形框)");
	}
	else if (iValue == 3)
	{
		strValue = QString::fromLocal8Bit("1、贴瓷砖(机械臂从料盒中取料后将瓷砖贴在墙面上)");
	}
	else if (iValue == 4)
	{
		strValue = QString::fromLocal8Bit("1、循线(沿激光线前行到指定位置)\n 2、升降平台上升\n 3、机械臂喷漆");
	}
	else if (iValue == 5)
	{
		strValue = QString::fromLocal8Bit("1、循线(沿激光线前行到指定位置)\n 2、升降平台上升\n 3、机械臂喷漆");
	}
	ui.textEditDemoPlanSet_View->setText(strValue);
}

void QGTDemoPlanSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTDemoPlanSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTDemoPlanSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

