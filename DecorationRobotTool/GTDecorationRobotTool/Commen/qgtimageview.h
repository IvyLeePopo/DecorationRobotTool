#ifndef QGTIMAGEVIEW_H
#define QGTIMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMouseEvent>

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>

const int ImageWindow_width = 640;
const int ImageWindow_height = 480;

class QGTImageView : public QGraphicsView
{
	Q_OBJECT

public:
	QGTImageView(QWidget *parent);
	~QGTImageView();

public:
	void DisplayImage(const cv::Mat ImageInput);

	void Display_LidarData(const QList<QPointF> ptNormal_Array_Input, const QPointF pt_Turning_Input, const QLineF Line_Input);

protected:
	virtual void enterEvent(QEvent *event);
	virtual void leaveEvent(QEvent *event);
	virtual void wheelEvent(QWheelEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
private:
	QImage MatImageToQImage(const cv::Mat ImageInput);

	void DrawNormalLine();

	void Draw_Lidar_Line(const QLineF line_Input);
private:
	QGraphicsScene *m_pScene; //��ͼ����
	QGraphicsPixmapItem *m_pItem_Image;
	QGraphicsPathItem *m_pItem_CoordinateSystem;

	QGraphicsPathItem *m_pItem_Lidar_CoordinateSystem;        //ɨ�������ϵͼԪ
	QGraphicsPathItem *m_pItem_Lidar_NormalDot;               //ɨ���������ͼԪ
	QGraphicsPathItem *m_pItem_Lidar_TurningDot;              //ɨ���ת�۵�ͼԪ
	QGraphicsPathItem *m_pItem_Lidar_Line_endPoint;           //�߶ζ˵�ͼԪ
	QGraphicsPathItem *m_pItem_Lidar_Line;                    //�߶�ͼԪ

	cv::Mat m_cvImageInput; //����ͼ��
	QPointF m_ptMoveStart;	//�����Ҽ��ƶ�ͼ��
};

#endif // QGTIMAGEVIEW_H
