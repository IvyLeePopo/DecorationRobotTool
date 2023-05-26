

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
const int LaserLine_width = 4; //三线仪投射到视野内的直线的宽度的1/2
const Scalar Line_GREEN = Scalar(0, 255, 0);
const Scalar Line_RED = Scalar(0, 0, 255);
const Scalar Line_Purple = Scalar(128, 0, 128);
const Scalar Line_BLACK = Scalar(0, 0, 0);

enum LineType
{
	L_Horizontal,  //水平方向的直线
	L_Vertical,    //垂直方向的直线
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

	double GetLineAngle(const QLine lineInput); //获取当前直线与垂线的夹角
	LineType QueryLineType(const QLine lineInput); //查询直线的类型
private:
	cv::Mat GetCandyImage(const Mat ImgInput);                     //边缘滤波
	cv::Mat GetLaplsImage(const Mat ImgInput);                     //拉普拉斯滤波
	cv::Mat GetScharrImage(const Mat ImgInput, const int iLevel);  //Scharr滤波
	cv::Mat GetFilterImage(const Mat ImgInput, int iType);         //将输入图像进行滤波处理
	cv::Mat GetBinaryzationImage(Mat ImgInput, int iThreshold);    //二值化图像

	int GetCurrentThreshold(const Mat ImgInput, const int iMin_threshold, 
		                    const int iMax_threshold, const int iMin_LaserArea, 
							const int iMax_LaserArea); //查找适合当前找激光线的阈值
	
	bool SearchContour(const Mat ImgInput, const int iThreshold_Input, 
		               const int iMin_LaserArea, const int iMax_LaserArea); //查找激光线的轮廓


	LineType QueryLineType(const QPoint ptA, const QPoint ptB); //查询直线的类型

	QLine GetValidLine(const QPoint ptA, const QPoint ptB); //获取有效的（正向的向量）直线

	QPoint GetLineCenter(const QLine lineInput); //获取直线的中心点

	QPoint GetLineOffset(const QLine lineInput); //获取直线的平移增量（只有当前找到一条或同一条直线上的不同线段时）

	void GetLineBesidePoints(const QLine lineInput, QPoint &ptLeft_Output, QPoint &ptRight_Output); //得到直线中心点两边的点坐标，用于之后判断直线的搜索方向

	QLine GetFitLine(const vector<QLine> lineArray_Input); //得到适合的直线(激光线的中线)

	bool IsSameLine(const QLine lineA, const QLine lineB); //查询两条直线是否为同一条

	bool QueryEdgeLineDirection(const Mat ImgInput, const QLine lineInput);//查询当前找到的直线是从黑到白搜索的还是从白到黑搜索的(即查询直线是在激光线左侧还是在右侧)

private:
	Mat m_nImage_Binary; //二值化之后的图像
};

