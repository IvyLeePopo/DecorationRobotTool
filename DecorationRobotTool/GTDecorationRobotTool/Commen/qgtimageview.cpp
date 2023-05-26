#include "qgtimageview.h"

QGTImageView::QGTImageView(QWidget *parent)
	: QGraphicsView(parent)
{
	m_pScene = new QGraphicsScene(this);
	setScene(m_pScene);

	m_pItem_Image = new QGraphicsPixmapItem(NULL);
	m_pItem_CoordinateSystem = new QGraphicsPathItem(NULL);

	m_pItem_Lidar_CoordinateSystem = new QGraphicsPathItem(NULL);
	m_pItem_Lidar_NormalDot = new QGraphicsPathItem(NULL);
	m_pItem_Lidar_TurningDot = new QGraphicsPathItem(NULL);
	m_pItem_Lidar_Line_endPoint = new QGraphicsPathItem(NULL);
	m_pItem_Lidar_Line = new QGraphicsPathItem(NULL);
	m_pScene->addItem(m_pItem_Image);
	m_pScene->addItem(m_pItem_CoordinateSystem);

	m_pScene->addItem(m_pItem_Lidar_CoordinateSystem);
	m_pScene->addItem(m_pItem_Lidar_NormalDot);
	m_pScene->addItem(m_pItem_Lidar_TurningDot);
	m_pScene->addItem(m_pItem_Lidar_Line_endPoint);
	m_pScene->addItem(m_pItem_Lidar_Line);

	m_pItem_CoordinateSystem->setPen(QPen(QColor(Qt::black), 3));

	m_pItem_Lidar_CoordinateSystem->setPen(QPen(QColor(255, 128, 0), 10));
	m_pItem_Lidar_CoordinateSystem->setTransform(QTransform(-1, 0, 0, 0, -1, 0, 0, 0, 1));

	m_pItem_Lidar_NormalDot->setPen(QPen(QColor(Qt::black), 10));
	m_pItem_Lidar_NormalDot->setTransform(QTransform(-1, 0, 0, 0, -1, 0, 0, 0, 1));

	m_pItem_Lidar_TurningDot->setPen(QPen(QColor(Qt::yellow), 10));
	m_pItem_Lidar_TurningDot->setTransform(QTransform(-1, 0, 0, 0, -1, 0, 0, 0, 1));

	m_pItem_Lidar_Line_endPoint->setPen(QPen(QColor(Qt::red), 10));
	m_pItem_Lidar_Line_endPoint->setTransform(QTransform(-1, 0, 0, 0, -1, 0, 0, 0, 1));

	m_pItem_Lidar_Line->setPen(QPen(QColor(Qt::blue), 10));
	m_pItem_Lidar_Line->setTransform(QTransform(-1, 0, 0, 0, -1, 0, 0, 0, 1));
}

QGTImageView::~QGTImageView()
{

}

QImage QGTImageView::MatImageToQImage(const cv::Mat ImageInput)
{
	cv::Mat Img_Input, Img_Transfor;
	QImage ImageOut;
	//将图像的尺寸限定在窗口范围
	cv::Size dSize = cv::Size(ImageWindow_width, ImageWindow_height);
	cv::resize(ImageInput, Img_Transfor, dSize);

	QImage image_temp;
	const uchar *pSrc = NULL;
	if (Img_Transfor.channels() == 1)
	{
		image_temp = QImage(Img_Transfor.cols, Img_Transfor.rows, QImage::Format_Indexed8);
		image_temp.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image_temp.setColor(i, qRgb(i, i, i));
		}
		pSrc = (const uchar *)Img_Transfor.data;
		for (int j = 0; j < Img_Transfor.rows; j++)
		{
			uchar *pDest = image_temp.scanLine(j);
			memcpy(pDest, pSrc, Img_Transfor.cols);
			pSrc += Img_Transfor.step;
		}
		ImageOut = image_temp.copy();
	}
	else if (Img_Transfor.channels() == 3)
	{
		pSrc = (const uchar *)Img_Transfor.data;
		image_temp = QImage(pSrc, Img_Transfor.cols, Img_Transfor.rows, Img_Transfor.step, QImage::Format_RGB888);
		ImageOut = image_temp.rgbSwapped();
	}
	else if (Img_Transfor.channels() == 4)
	{
		pSrc = (const uchar*)Img_Transfor.data;
		image_temp = QImage(pSrc, Img_Transfor.cols, Img_Transfor.rows, Img_Transfor.step, QImage::Format_ARGB32);
		ImageOut = image_temp.copy();
	}
	return ImageOut;
}

void QGTImageView::enterEvent(QEvent *event)
{
	//修改鼠标外观
	QCursor mouseShape;
	mouseShape.setShape(Qt::CrossCursor);
	setCursor(mouseShape);
}

void QGTImageView::leaveEvent(QEvent *event)
{
	//修改鼠标外观
	QCursor mouseShape;
	mouseShape.setShape(Qt::ArrowCursor);
	setCursor(mouseShape);
}

void QGTImageView::wheelEvent(QWheelEvent *event)
{
	float fScaleRatio;
	if (event->delta() > 0)
	{
		fScaleRatio = 2;
	}
	else
	{
		fScaleRatio = 0.5;
	}
	scale(fScaleRatio, fScaleRatio);
}

void QGTImageView::mousePressEvent(QMouseEvent *event)
{
	QPoint ptCurrent = event->pos();
	if (event->button() == Qt::RightButton)
	{
		m_ptMoveStart = mapToScene(event->pos());
		//修改鼠标外观
		QCursor mouseShape;
		mouseShape.setShape(Qt::ClosedHandCursor);
		setCursor(mouseShape);
	}
}

void QGTImageView::mouseMoveEvent(QMouseEvent *event)
{
	QCursor mouseShape;
	QPoint ptCurrent = event->pos();
	if (event->buttons() == Qt::RightButton)
	{
		if (this->rect().contains(ptCurrent))
		{
			QPointF ptMove = mapToScene(ptCurrent);
			QPointF ptOffset = ptMove - m_ptMoveStart;
			QPoint ptViewCenter(viewport()->width() / 2, viewport()->height() / 2);
			QPointF ptScenceCenter = mapToScene(ptViewCenter);
			QPointF ptTarget = ptScenceCenter - ptOffset;
			centerOn(ptTarget);

			//修改鼠标外观
			mouseShape.setShape(Qt::ClosedHandCursor);
		}
		else
		{
			mouseShape.setShape(Qt::ArrowCursor);
		}
	}
	setCursor(mouseShape);
}

void QGTImageView::mouseReleaseEvent(QMouseEvent *event)
{
	QPoint ptCurrent = event->pos();
	m_ptMoveStart = mapToScene(ptCurrent);
	//修改鼠标外观
	QCursor mouseShape;
	mouseShape.setShape(Qt::CrossCursor);
	setCursor(mouseShape);
}

void QGTImageView::DisplayImage(const cv::Mat ImageInput)
{
	if (NULL != ImageInput.data)
	{
		QImage Image_Draw = MatImageToQImage(ImageInput);;
		QPixmap m_nPixImageShow = QPixmap::fromImage(Image_Draw);
		m_pItem_Image->setPixmap(m_nPixImageShow);
		DrawNormalLine();
	}
}

void QGTImageView::DrawNormalLine()
{
	QPainterPath linePath;
	QPoint ptTop_Center(this->width() / 2, 0);
	QPoint ptBottom_Center(this->width() / 2, this->height());
	QPoint ptLeft_Center(0, this->height() / 2);
	QPoint ptRight_Center(this->width(), this->height() / 2);
	linePath.moveTo(ptTop_Center);
	linePath.lineTo(ptBottom_Center);
	linePath.moveTo(ptLeft_Center);
	linePath.lineTo(ptRight_Center);
	m_pItem_CoordinateSystem->setPath(linePath);
}

void QGTImageView::Display_LidarData(const QList<QPointF> ptNormal_Array_Input, const QPointF pt_Turning_Input, const QLineF Line_Input)
{
	QPainterPath Path_CoordinateSystem;    //扫描的坐标系图元
	QPainterPath Path_Normal;              //扫描的正常点图元
	QPainterPath Path_Turning;             //扫描的转折点图元
	QPainterPath Path_Line_endPoint;       //线段端点图元
	QPainterPath Path_Line;                //线段图元

	for (int i = 0; i < ptNormal_Array_Input.size(); i++)
	{
		QPointF pt_Normal = ptNormal_Array_Input.at(i);
		Path_Normal.addEllipse(pt_Normal, 5, 5);
	}

	Path_Turning.addEllipse(pt_Turning_Input, 5, 5);

	Path_Line_endPoint.addEllipse(Line_Input.p1(), 5, 5);
	Path_Line_endPoint.addEllipse(Line_Input.p2(), 5, 5);

	Path_Line.moveTo(Line_Input.p1());
	Path_Line.lineTo(Line_Input.p2());

	Path_CoordinateSystem.addEllipse(QPointF(0, 0), 5, 5);

	m_pItem_Lidar_CoordinateSystem->setPath(Path_CoordinateSystem);
	m_pItem_Lidar_NormalDot->setPath(Path_Normal);
	m_pItem_Lidar_TurningDot->setPath(Path_Turning);
	m_pItem_Lidar_Line_endPoint->setPath(Path_Line_endPoint);
	m_pItem_Lidar_Line->setPath(Path_Line);
}
