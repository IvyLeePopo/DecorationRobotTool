

#include <vector>

#include <QLine>
#include <QMatrix>
#include <QPolygon>

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
using namespace cv;


#pragma once

#define GetNumMax(x,y)(x>y?x:y)
#define GetNumMin(x,y)(x<y?x:y)

const double Line_PI = 3.1415926;
const int LaserLine_width = 4; //������Ͷ�䵽��Ұ�ڵ�ֱ�ߵĿ�ȵ�1/2
const Scalar Line_GREEN = Scalar(0, 255, 0);
const Scalar Line_RED = Scalar(0, 0, 255);
const Scalar Line_Purple = Scalar(128, 0, 128);
const Scalar Line_BLACK = Scalar(0, 0, 0);

enum LineType
{
	L_Horizontal,  //ˮƽ�����ֱ��
	L_Vertical,    //��ֱ�����ֱ��
	L_Normal
};

struct AllImagePixInfo
{
	Point m_ptEveryOne;
	int m_szEveryPointPix[3];
};

class CFindLineBase
{
public:
	CFindLineBase();
	virtual ~CFindLineBase();

public:
	bool FindCurrentLine(const Mat ImgInput, const int iThreshold_toFindline, 
		                 const int iMin_threshold,const int iMax_threshold, 
						 const int iMin_LaserArea,const int iMax_LaserArea, 
						 Mat &ImgOutput, QLine &lineOutput);

	double GetLineAngle(const QLine lineInput); //��ȡ��ǰֱ���봹�ߵļн�
	LineType QueryLineType(const QLine lineInput); //��ѯֱ�ߵ�����
private:
	cv::Mat GetCandyImage(const Mat ImgInput);                     //��Ե�˲�
	cv::Mat GetLaplsImage(const Mat ImgInput);                     //������˹�˲�
	cv::Mat GetScharrImage(const Mat ImgInput, const int iLevel);  //Scharr�˲�
	cv::Mat GetFilterImage(const Mat ImgInput, int iType);         //������ͼ������˲�����
	cv::Mat GetBinaryzationImage(Mat ImgInput, int iThreshold);    //��ֵ��ͼ��

	int GetCurrentThreshold(const Mat ImgInput, const int iMin_threshold, 
		                    const int iMax_threshold, const int iMin_LaserArea, 
							const int iMax_LaserArea); //�����ʺϵ�ǰ�Ҽ����ߵ���ֵ
	
	bool SearchContour(const Mat ImgInput, const int iThreshold_Input, 
		               const int iMin_LaserArea, const int iMax_LaserArea); //���Ҽ����ߵ�����


	LineType QueryLineType(const QPoint ptA, const QPoint ptB); //��ѯֱ�ߵ�����

	QLine GetValidLine(const QPoint ptA, const QPoint ptB); //��ȡ��Ч�ģ������������ֱ��

	QPoint GetLineCenter(const QLine lineInput); //��ȡֱ�ߵ����ĵ�

	QPoint GetLineOffset(const QLine lineInput); //��ȡֱ�ߵ�ƽ��������ֻ�е�ǰ�ҵ�һ����ͬһ��ֱ���ϵĲ�ͬ�߶�ʱ��

	void GetLineBesidePoints(const QLine lineInput, QPoint &ptLeft_Output, QPoint &ptRight_Output); //�õ�ֱ�����ĵ����ߵĵ����꣬����֮���ж�ֱ�ߵ���������

	QLine GetFitLine(const vector<QLine> lineArray_Input); //�õ��ʺϵ�ֱ��(�����ߵ�����)

	bool IsSameLine(const QLine lineA, const QLine lineB); //��ѯ����ֱ���Ƿ�Ϊͬһ��

	bool QueryEdgeLineDirection(const Mat ImgInput, const QLine lineInput);//��ѯ��ǰ�ҵ���ֱ���ǴӺڵ��������Ļ��ǴӰ׵���������(����ѯֱ�����ڼ�������໹�����Ҳ�)

private:
	Mat m_nImage_Binary; //��ֵ��֮���ͼ��
};

