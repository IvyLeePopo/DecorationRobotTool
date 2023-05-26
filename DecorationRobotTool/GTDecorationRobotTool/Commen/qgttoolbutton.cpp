#include "qgttoolbutton.h"

QGTToolButton::QGTToolButton(QWidget *parent)
	: QToolButton(parent)
{
	m_msStatus = TBMS_INIT;
	m_bIsChecked = false;
	pMenu_Now = new QMenu(this);
	pMenu_Now->setStyleSheet("background-image: url(:/GTDecorationRobotTool/Resources/BaseSet_BackGround.png);color: rgb(135, 206, 250);");
}

QGTToolButton::~QGTToolButton()
{

}

void QGTToolButton::enterEvent(QEvent *event)
{
	if (m_msStatus == TBMS_INIT)
	{
		return;
	}

	if (m_bIsChecked)
	{
		m_msStatus = TBMS_PRESS;
	}
	else
	{
		m_msStatus = TBMS_HOVER;
	}
	update();
}

void QGTToolButton::leaveEvent(QEvent *event)
{
	if (m_msStatus == TBMS_INIT)
	{
		return;
	}

	if (m_bIsChecked)
	{
		m_msStatus = TBMS_PRESS;
	}
	else
	{
		m_msStatus = TBMS_NORMAL;
	}
	update();
}

void QGTToolButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (m_msStatus != TBMS_INIT)
		{
			m_msStatus = TBMS_PRESS;
			update();
		}

		// 鼠标在弹起的时候光标在按钮上才激发pressed信号
		if (rect().contains(event->pos()))
		{
			if (m_iType == TBT_Menu)
			{
				PopupCurrentMenu();
			}
			emit pressed();
			this->setDown(true);
		}
	}
}

void QGTToolButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (m_msStatus != TBMS_INIT)
		{
			m_msStatus = TBMS_PRESS;
			update();
		}
		// 鼠标在弹起的时候光标在按钮上才激发clicked信号  
		if (rect().contains(event->pos()))
		{
			emit released();
			this->setDown(false);
		}
	}
}

void QGTToolButton::paintEvent(QPaintEvent *event)
{
	if (m_msStatus == TBMS_INIT)
	{
		QToolButton::paintEvent(event);
		return;
	}
	QPainter painter_Temp(this);
	QPixmap pixmap(m_szBtnImage[m_msStatus]);
	
	QToolButton::setStyleSheet(GetCuttentStyle());
	
	if (m_iType != TBT_Round_Rect)
	{
		QToolButton::setIcon(pixmap);
		QToolButton::setIconSize(m_nIconSize);
	}

	QToolButton::paintEvent(event);
}

void QGTToolButton::SetButtonChecked(bool bChecked)
{
	m_bIsChecked = bChecked;
	if (bChecked)
	{
		m_msStatus = TBMS_PRESS;
	}
	else
	{
		m_msStatus = TBMS_NORMAL;
	}
	update();
}

void QGTToolButton::SetButtonIcon(QString strIconName, QSize nIconSize, GT_ToolBtn_Type iType)
{
	QString strIconPath_Normal, strIconPath_Hover, strIconPath_Press;
	QString strBasePath = ":/GTDecorationRobotTool/Resources/";
	strIconPath_Normal = strBasePath + strIconName + "_Normal.png";
	strIconPath_Hover = strBasePath + strIconName + "_Hover.png";
	strIconPath_Press = strBasePath + strIconName + "_Press.png";
	m_msStatus = TBMS_NORMAL;
	m_szBtnImage[TBMS_NORMAL] = strIconPath_Normal;
	m_szBtnImage[TBMS_HOVER] = strIconPath_Hover;
	m_szBtnImage[TBMS_PRESS] = strIconPath_Press;
	m_nIconSize = nIconSize;
	m_iType = iType;
}

QString QGTToolButton::GetCuttentStyle()
{
	QString strOutput = "";
	int iRadius = 0;

	if (m_msStatus == TBMS_HOVER || m_msStatus == TBMS_PRESS)
	{
		if (m_iType == TBT_Normal_Rect)
		{
			strOutput = "color: rgb(85, 170, 255);border-style: solid";
		}
		else if (m_iType == TBT_Menu)
		{
			strOutput = "color: rgb(85, 0, 255);border-style: solid";
		}
		else if (m_iType == TBT_Round_Rect)
		{
			iRadius = m_nIconSize.width() < m_nIconSize.height() ? m_nIconSize.width() : m_nIconSize.height();
// 			strOutput = "border-radius:" + QString::number(iRadius / 3) + "px;padding:2px 4px;color: rgb(85, 255, 255); background-color: rgb(19, 95, 153); ";
			strOutput = "border-radius:" + QString::number(iRadius / 3) + "px;padding:2px 4px;color: rgb(85, 255, 255); background-color: rgb(65, 105, 225); ";
		}
		else if (m_iType == TBT_Circle)
		{
			iRadius = m_nIconSize.width();
			strOutput = "border-radius:" + QString::number(iRadius / 2) + "px;padding:2px 4px;color: rgb(85, 255, 255); background-color: rgb(19, 95, 153); ";
		}
	}
	else
	{
		if (m_iType == TBT_Normal_Rect)
		{
			strOutput = "color: rgb(85, 0, 255);border-style: solid";
		}
		else if (m_iType == TBT_Menu)
		{
			strOutput = "border-style: solid";
		}
		else if (m_iType == TBT_Round_Rect)
		{
			iRadius = m_nIconSize.width() < m_nIconSize.height() ? m_nIconSize.width() : m_nIconSize.height();
// 			strOutput = "border-radius:" + QString::number(iRadius / 3) + "px;padding:2px 4px;color: rgb(85, 135, 198); border-style: solid ";
			strOutput = "border-radius:" + QString::number(iRadius / 3) + "px;padding:2px 4px;color: rgb(135, 206, 235); border-style: solid ";
		}
		else if (m_iType == TBT_Circle)
		{
			iRadius = m_nIconSize.width();
			strOutput = "border-radius:" + QString::number(iRadius / 2) + "px;padding:2px 4px;color: rgb(85, 255, 255);border-style: solid";
		}
	}

	return strOutput;
}

void QGTToolButton::PopupCurrentMenu()
{
	QPoint pos;
	int y = pos.y();
	pos.setY(y + this->geometry().height());
	pMenu_Now->exec(this->mapToGlobal(pos));
}

QMenu * QGTToolButton::GetCurrentMenu()
{
	return pMenu_Now;
}
