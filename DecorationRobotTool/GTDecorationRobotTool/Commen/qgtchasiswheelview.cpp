#include "qgtchasiswheelview.h"

QGTChasisWheelView::QGTChasisWheelView(QWidget *parent)
	: QLabel(parent)
{

}

QGTChasisWheelView::~QGTChasisWheelView()
{

}

void QGTChasisWheelView::paintEvent(QPaintEvent *nEvent)
{
	QPainter paintWheel(this);
	paintWheel.setRenderHint(QPainter::SmoothPixmapTransform);
	paintWheel.setRenderHint(QPainter::Antialiasing);

	int iWidth = this->width();

	paintWheel.translate(iWidth / 2, iWidth / 2);
	paintWheel.rotate(-m_dAngle);
	paintWheel.translate(-iWidth / 2, -iWidth / 2);

	paintWheel.drawPixmap(0, 0, iWidth, iWidth, pix_Wheel);

	this->update();
}

void QGTChasisWheelView::UpdateChasisWheel(const QPixmap pix_Input, const double dwAngle_Input)
{
	pix_Wheel = pix_Input;
	m_dAngle = dwAngle_Input - 90;
}
