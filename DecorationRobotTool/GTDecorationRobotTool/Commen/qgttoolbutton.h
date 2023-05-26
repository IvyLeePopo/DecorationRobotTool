#ifndef QGTTOOLBUTTON_H
#define QGTTOOLBUTTON_H

#include <QToolButton>
#include <QMouseEvent>
#include <QPainter>
#include <QMenu>

enum GT_ToolBtn_Mouse_Status
{
	TBMS_INIT   = 0,
	TBMS_NORMAL = 1,
	TBMS_HOVER  = 2,
	TBMS_PRESS  = 3,
	TBMS_COUNT  = 4
};

enum GT_ToolBtn_Type
{
	TBT_Normal_Rect = 0,  //�������ΰ�ť
	TBT_Round_Rect  = 1,  //Բ�Ǿ��ΰ�ť
	TBT_Circle      = 2,  //Բ�ΰ�ť
	TBT_Menu        = 3
};

class QGTToolButton : public QToolButton
{
	Q_OBJECT

public:
	QGTToolButton(QWidget *parent);
	~QGTToolButton();

public:
	void SetButtonIcon(QString strIconName, QSize nIconSize, GT_ToolBtn_Type iType);
	void SetButtonChecked(bool bChecked);
	bool IsButtonChecked() {return m_bIsChecked; };
	QMenu *GetCurrentMenu();
protected:
	virtual void enterEvent(QEvent *event);
	virtual void leaveEvent(QEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
private:
	QString GetCuttentStyle();
	void PopupCurrentMenu();
private:
	GT_ToolBtn_Mouse_Status m_msStatus;
	GT_ToolBtn_Type m_iType;
	QMenu *pMenu_Now;
	QSize m_nIconSize;
	QString m_szBtnImage[TBMS_COUNT];
	bool m_bIsChecked;
};

#endif // QGTTOOLBUTTON_H
