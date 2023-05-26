#include "FindLine.h"


CFindLine::CFindLine()
{
	InitializeCamera();
}


CFindLine::~CFindLine()
{
	ReleaseCameraUnit();
}

void CFindLine::InitializeCamera()
{
	m_pFindLineBase = new CFindLineBase();
	m_vCapture.open(0);
}

cv::Mat CFindLine::GetFramImage()
{
	Mat ImageOutput;
	if (true == m_vCapture.isOpened())
	{
		Mat img_Frame;
		m_vCapture.retrieve(img_Frame);

		if (NULL != img_Frame.data)
		{
			img_Frame.copyTo(ImageOutput);
		}
	}
	return ImageOutput;
}

void CFindLine::ReleaseCameraUnit()
{
	m_vCapture.release();
	if (NULL != m_pFindLineBase)
	{
		delete m_pFindLineBase;
		m_pFindLineBase = NULL;
	}
}

double CFindLine::GetDis_PointToLine(const QLine lineInput, const QPoint ptInput)
{
	double dwDis_Output, iPoint_X, iPoint_Y;
	QPoint ptVector_Line = QPoint(lineInput.x2() - lineInput.x1(), lineInput.y2() - lineInput.y1());
	LineType iType = m_pFindLineBase->QueryLineType(lineInput);
	if (iType == L_Normal)
	{
		double dwK = lineInput.dy() / lineInput.dx();
		double dwB = lineInput.y1() - dwK * lineInput.x1();
		
		//点到直线的垂线与直线成90度角，则两个向量乘积的结果为0；
		//计算点到直线的垂线交点
		iPoint_X = (ptVector_Line.x() * ptInput.x() + ptVector_Line.y() * ptInput.y() - ptVector_Line.y() * dwB) / (ptVector_Line.x() + dwK * ptVector_Line.y());
		iPoint_Y = dwK * iPoint_X + dwB;

		QPoint ptCross = QPoint((ptInput.y() - dwB) / dwK, ptInput.y()); //计算直线与过当前输入点的水平直线的交点

		if (ptCross.x() < ptInput.x())
		{
			dwDis_Output = -sqrt(pow(iPoint_X - ptInput.x(), 2) + pow(iPoint_Y - ptInput.y(), 2));
		}
		else
		{
			dwDis_Output = sqrt(pow(iPoint_X - ptInput.x(), 2) + pow(iPoint_Y - ptInput.y(), 2));
		}
	}
	else if (iType == L_Vertical)
	{
		iPoint_Y = ptInput.y();
		iPoint_X = lineInput.x1();
		dwDis_Output = iPoint_X - ptInput.x();
	}
	else if (iType == L_Horizontal)
	{
		//不可能
	}

	return dwDis_Output;
}

bool CFindLine::StartFindLine(const double dwCalibration, const int iThreshold_toFindline, const int iMin_threshold, const int iMax_threshold, const int iMin_LaserArea, const int iMax_LaserArea, Mat &ImgOutput, double &dwAngle_Output, double &dwDis_Output)
{
	QLine line_Output;
	Mat ImageToFindLine = GetFramImage();
	if (false == m_pFindLineBase->FindCurrentLine(ImageToFindLine, iThreshold_toFindline, iMin_threshold, iMax_threshold, iMin_LaserArea, iMax_LaserArea, ImgOutput, line_Output))
	{
		return false;
	}

	dwAngle_Output = m_pFindLineBase->GetLineAngle(line_Output);

	QPoint ptChasis_Center = QPoint(ImageToFindLine.cols / 2, ImageToFindLine.rows / 2);
	dwDis_Output = GetDis_PointToLine(line_Output, ptChasis_Center);
	return true;
}
