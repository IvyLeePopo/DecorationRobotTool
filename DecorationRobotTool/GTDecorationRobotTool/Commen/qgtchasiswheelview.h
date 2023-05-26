#ifndef QGTCHASISWHEELVIEW_H
#define QGTCHASISWHEELVIEW_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>

class QGTChasisWheelView : public QLabel
{
	Q_OBJECT

public:
	QGTChasisWheelView(QWidget *parent);
	~QGTChasisWheelView();

public:
	void UpdateChasisWheel(const QPixmap pix_Input, const double dwAngle_Input);
protected:
	virtual void paintEvent(QPaintEvent *nEvent);
private:
	QPixmap pix_Wheel;
	double m_dAngle;
};

#endif // QGTCHASISWHEELVIEW_H
