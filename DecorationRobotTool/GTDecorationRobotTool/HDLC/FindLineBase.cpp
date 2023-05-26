
#include "FindLineBase.h"


CFindLineBase::CFindLineBase()
{
}


CFindLineBase::~CFindLineBase()
{

}

cv::Mat CFindLineBase::GetCandyImage(const Mat ImgInput)
{
	Mat Image_Output;
	Mat Img_Blur;
	//输入图像ImgInput必须为灰度图像
	//先方框滤波
	blur(ImgInput, Img_Blur, cvSize(3, 3));
	//再提取边缘
	int iCannyThreshold = 120;
	Canny(Img_Blur, Image_Output, iCannyThreshold, iCannyThreshold * 3, 3);
	return Image_Output;
}

cv::Mat CFindLineBase::GetLaplsImage(const Mat ImgInput)
{
	Mat Img_gray, Img_Dst, Img_absDst, Image_Output;
	//使用高斯变换清除噪声
	GaussianBlur(ImgInput, ImgInput, cvSize(3, 3), 3, 0, BORDER_DEFAULT);
	if (ImgInput.channels() == 3)
	{
		cvtColor(ImgInput, Img_gray, CV_RGB2GRAY);
		Laplacian(Img_gray, Img_Dst, Img_gray.depth(), 5, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_Dst, Img_absDst);
		Img_absDst.copyTo(Image_Output);
	}
	else if (ImgInput.channels() == 1)
	{
		Laplacian(ImgInput, Img_Dst, ImgInput.depth(), 3, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_Dst, Img_absDst);
		Img_absDst.copyTo(Image_Output);
	}
	return Image_Output;
}

cv::Mat CFindLineBase::GetScharrImage(const Mat ImgInput, const int iLevel)
{
	Mat Img_grad_x, Img_grad_y, Img_absGrad_x, Img_absGrad_y, Img_Dst, Img_temp, Image_Output;
	switch (iLevel)
	{
	case 1:
		//X方向上滤波
		Scharr(ImgInput, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_absGrad_x);
		//Y方向上滤波
		Scharr(ImgInput, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_absGrad_y);
		break;
	case 2:
		//X方向上滤波
		Scharr(ImgInput, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_temp);

		Scharr(Img_temp, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_absGrad_x);


		//Y方向上滤波
		Scharr(ImgInput, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_temp);

		Scharr(Img_temp, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_absGrad_y);
		break;
	case 3:
		//X方向上滤波
		Scharr(ImgInput, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_temp);

		Scharr(Img_temp, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_temp);

		Scharr(Img_temp, Img_grad_x, ImgInput.depth(), 1, 0, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_x, Img_absGrad_x);


		//Y方向上滤波
		Scharr(ImgInput, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_temp);

		Scharr(Img_temp, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_temp);

		Scharr(Img_temp, Img_grad_y, ImgInput.depth(), 0, 1, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(Img_grad_y, Img_absGrad_y);
		break;
	default:
		break;
	}
	//合并梯度
	addWeighted(Img_absGrad_x, 0.5, Img_absGrad_y, 0.5, 0, Img_Dst);
	Img_Dst.copyTo(Image_Output);
	return Image_Output;
}

cv::Mat CFindLineBase::GetFilterImage(const Mat ImgInput, int iType)
{
	Mat Image_Output;
	switch (iType)
	{
	case 0:
		Image_Output = GetCandyImage(ImgInput);
		break;
	case 1:
		Image_Output = GetScharrImage(ImgInput, 1);
		break;
	case 2:
		Image_Output = GetLaplsImage(ImgInput);
		break;
	case 3:
		break;
	default:
		break;
	}
	return Image_Output;
}

cv::Mat CFindLineBase::GetBinaryzationImage(Mat ImgInput, int iThreshold)
{
	Mat Image_Gray, Image_Binary, Image_Output;
	if (ImgInput.channels() == 3)
	{
		cvtColor(ImgInput, Image_Gray, CV_BGR2GRAY);
		Image_Gray.copyTo(Image_Binary);
	}
	if (ImgInput.channels() == 1)
	{
		ImgInput.copyTo(Image_Gray);
		ImgInput.copyTo(Image_Binary);
	}

	threshold(Image_Gray, Image_Binary, iThreshold, 255, CV_THRESH_BINARY);
	Image_Binary.copyTo(Image_Output);
	return Image_Output;
}

bool CFindLineBase::SearchContour(const Mat ImgInput, const int iThreshold_Input, const int iMin_LaserArea, const int iMax_LaserArea)
{
	Mat Image_Grey, Image_Binary, Image_Contour;
	double dwContourArea = 0;

	//二值化
	if (ImgInput.channels() == 3)
	{
		cvtColor(ImgInput, Image_Grey, CV_RGB2GRAY, 1);
		cvtColor(ImgInput, Image_Binary, CV_RGB2GRAY, 1);
	}
	if (ImgInput.channels() == 1)
	{
		ImgInput.copyTo(Image_Grey);
		ImgInput.copyTo(Image_Binary);
	}

	threshold(Image_Grey, Image_Binary, iThreshold_Input, 255, CV_THRESH_BINARY);

	//找轮廓
	Image_Binary.copyTo(Image_Contour);
	vector<vector<Point> > contours_Array;
	vector<Vec4i> hierarchy_Array;
	contours_Array.clear();
	hierarchy_Array.clear();

	findContours(Image_Contour, contours_Array, hierarchy_Array, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	if (contours_Array.size() <= 0)
	{
		return false;
	}
	if (hierarchy_Array.size() <= 0)
	{
		return false;
	}

	vector<vector<Point> > Poly_Array(contours_Array.size());

	for (size_t i = 0; i < contours_Array.size(); i++)
	{
		approxPolyDP(contours_Array[i], Poly_Array[i], 5, true);
		dwContourArea = contourArea(Poly_Array[i], false);

		if ((dwContourArea > iMin_LaserArea) && (dwContourArea < iMax_LaserArea))
		{
			return true;
		}
	}
	return false;
}

int CFindLineBase::GetCurrentThreshold(const Mat ImgInput, const int iMin_threshold, const int iMax_threshold, const int iMin_LaserArea, const int iMax_LaserArea)
{
	int iThreshold_Output = -1;
	for (int i = iMax_threshold; i > iMin_threshold; i--)
	{
		if (true == SearchContour(ImgInput, i, iMin_LaserArea, iMax_LaserArea))
		{
			iThreshold_Output = i;
			break;
		}
	}
	return iThreshold_Output;
}

LineType CFindLineBase::QueryLineType(const QPoint ptA, const QPoint ptB)
{
	LineType iType_Output;
	if ((ptA.x() != ptB.x()) && (ptA.y() != ptB.y()))
	{
		iType_Output = L_Normal;
	}
	else if ((ptA.x() == ptB.x()) && (ptA.y() != ptB.y()))
	{
		iType_Output = L_Vertical;
	}
	else if ((ptA.x() != ptB.x()) && (ptA.y() == ptB.y()))
	{
		iType_Output = L_Horizontal;
	}
	return iType_Output;
}

LineType CFindLineBase::QueryLineType(const QLine lineInput)
{
	LineType iType_Output;
	if ((lineInput.p1().x() != lineInput.p2().x()) && (lineInput.p1().y() != lineInput.p2().y()))
	{
		iType_Output = L_Normal;
	}
	else if ((lineInput.p1().x() == lineInput.p2().x()) && (lineInput.p1().y() != lineInput.p2().y()))
	{
		iType_Output = L_Vertical;
	}
	else if ((lineInput.p1().x() != lineInput.p2().x()) && (lineInput.p1().y() == lineInput.p2().y()))
	{
		iType_Output = L_Horizontal;
	}
	return iType_Output;
}

//坐标系不同导致计算出的直线斜率与正常的直角坐标系不同
/*                                   \       */
/*                                    \       */
/*           —————————————       */
/*           |                        /       */
/*           |                       /       */
/*           |          */
/*           |          */
/*           |          */
/*           |          */
/*         \ | /        */
/*          \|/         */
QLine CFindLineBase::GetValidLine(const QPoint ptA, const QPoint ptB)
{
	QLine line_Output;
	
	LineType iLien_Type = QueryLineType(ptA,ptB);
	if (iLien_Type == L_Normal)
	{
		double dwK = (ptB.y() - ptA.y()) / (ptB.x() - ptA.x());
		if (dwK < 0)
		{
			if ((ptA.x() < ptB.x()) && (ptA.y() > ptB.y()))
			{
				line_Output = QLine(ptA, ptB);
			}
			else
			{
				line_Output = QLine(ptB, ptA);
			}
		}
		else if (dwK > 0)
		{
			if ((ptA.x() > ptB.x()) && (ptA.y() > ptB.y()))
			{
				line_Output = QLine(ptA, ptB);
			}
			else
			{
				line_Output = QLine(ptB, ptA);
			}
		}
	}
	else if (iLien_Type == L_Vertical)
	{
		if (ptA.y() > ptB.y())
		{
			line_Output = QLine(ptA, ptB);
		}
		else
		{
			line_Output = QLine(ptB, ptA);
		}
	}
	else if (iLien_Type == L_Horizontal)
	{
		if (ptA.x() < ptB.x())
		{
			line_Output = QLine(ptA, ptB);
		}
		else
		{
			line_Output = QLine(ptB, ptA);
		}
	}
	return line_Output;
}

double CFindLineBase::GetLineAngle(const QLine lineInput)
{
	/*----------------------------计算向量n1(x1,y1)与n2(x2,y2)的夹角的公式----------------------*/
	/*       向量乘积 v = x1*x2 + y1*y2                                                         */
	/*       向量的模的乘积 l = sqrt(pow(x1,2) + pow(y1,2)) * sqrt(pow(x2,2) + pow(y2,2))       */
	/*       cos(θ) = v / l                                                                    */
	/*       θ = arcos(v / l)                                                                  */
	/*----------------------------计算向量n1(x1,y1)与n2(x2,y2)的夹角的公式----------------------*/
	double dwAngle_Output;
	QPoint ptVector_Line = lineInput.p2() - lineInput.p1(); //直线的向量
	QPoint ptVector_vertical = QPoint(0, -1); //图像中垂线的单位向量
	double dwV = ptVector_Line.x() * ptVector_vertical.x() + ptVector_Line.y() * ptVector_vertical.y();
	double dwL = sqrt(pow(ptVector_Line.x(), 2) + pow(ptVector_Line.y(), 2)) * sqrt(pow(ptVector_vertical.x(), 2) + pow(ptVector_vertical.y(), 2));
	double dwAngle = acos(dwV / dwL) * 180 / Line_PI;
	if (L_Normal == QueryLineType(lineInput))
	{
		double dwK = lineInput.dy() / lineInput.dx();
		if (dwK < 0)
		{
			dwAngle_Output = -dwAngle;
		}
		else
		{
			dwAngle_Output = dwAngle;
		}
	}
	else
	{
		dwAngle_Output = dwAngle;
	}
	return dwAngle_Output;
}

QLine CFindLineBase::GetFitLine(const vector<QLine> lineArray_Input)
{
	QLine line_Output;
	QPoint ptLine_Offset;
	if (lineArray_Input.size() == 1)
	{
		QLine line_One = lineArray_Input.at(0);
		ptLine_Offset = GetLineOffset(line_One);
		line_One.translate(ptLine_Offset);
		line_Output = line_One;
	}
	else
	{
		QLine line_A = lineArray_Input.at(0);
		for (int i = 0; i < lineArray_Input.size(); i++)
		{
			QLine line_B = lineArray_Input.at(i + 1);
			if (!IsSameLine(line_A,line_B)) //如果判断为两条不同的直线
			{
				QPoint ptBegin = QPoint((line_A.x1() + line_B.x1()) / 2, (line_A.y1() + line_B.y1()) / 2);
				QPoint ptEnd = QPoint((line_A.x2() + line_B.x2()) / 2, (line_A.y2() + line_B.y2()) / 2);
				line_Output = GetValidLine(ptBegin, ptEnd);
				break;
			}
			else
			{
				ptLine_Offset = GetLineOffset(line_A);
				line_A.translate(ptLine_Offset);
				line_Output = line_A;
			}
		}
	}
	return line_Output;
}

QPoint CFindLineBase::GetLineCenter(const QLine lineInput)
{
	QPoint ptOutput = QPoint((lineInput.p1().x() + lineInput.p2().x()) / 2, (lineInput.p1().y() + lineInput.p2().y()) / 2);
	return ptOutput;
}

void CFindLineBase::GetLineBesidePoints(const QLine lineInput, QPoint &ptLeft_Output, QPoint &ptRight_Output)
{
	QMatrix lineMatrix;
	int iSize = 2;
	double dwAngle = GetLineAngle(lineInput);
	QPoint ptLineCenter = GetLineCenter(lineInput);
	QPoint ptBeside_Left = QPoint(ptLineCenter.x() - iSize, ptLineCenter.y());
	QPoint ptBeside_Right = QPoint(ptLineCenter.x() + iSize, ptLineCenter.y());
	QPolygon pol_Temp;
	pol_Temp.clear();
	pol_Temp.push_back(ptBeside_Left);
	pol_Temp.push_back(ptBeside_Right);
	lineMatrix.translate(ptLineCenter.x(), ptLineCenter.y());
	lineMatrix.rotate(-dwAngle);
	lineMatrix.translate(-ptLineCenter.x(), -ptLineCenter.y());
	pol_Temp = pol_Temp * lineMatrix;
	ptLeft_Output = pol_Temp.at(0);
	ptRight_Output = pol_Temp.at(1);
}

bool CFindLineBase::QueryEdgeLineDirection(const Mat ImgInput, const QLine lineInput)
{
	bool bRet = false;
	QPoint ptBeside_Left, ptBeside_Right;
	QPoint ptLineCenter = GetLineCenter(lineInput);
	GetLineBesidePoints(lineInput, ptBeside_Left, ptBeside_Right);

	//比较两点的像素
	if (ImgInput.channels() == 3)
	{
		int izPix_Left[3] = { 0 };
		int izPix_Right[3] = { 0 };
		izPix_Left[0] = ImgInput.at<cv::Vec3b>(ptBeside_Left.y(), ptBeside_Left.x())[0];
		izPix_Left[1] = ImgInput.at<cv::Vec3b>(ptBeside_Left.y(), ptBeside_Left.x())[1];
		izPix_Left[2] = ImgInput.at<cv::Vec3b>(ptBeside_Left.y(), ptBeside_Left.x())[2];

		izPix_Right[0] = ImgInput.at<cv::Vec3b>(ptBeside_Right.y(), ptBeside_Right.x())[0];
		izPix_Right[1] = ImgInput.at<cv::Vec3b>(ptBeside_Right.y(), ptBeside_Right.x())[1];
		izPix_Right[2] = ImgInput.at<cv::Vec3b>(ptBeside_Right.y(), ptBeside_Right.x())[2];

		if ((izPix_Left[0] < izPix_Right[0]) && (izPix_Left[1] < izPix_Right[1]) && (izPix_Left[2] < izPix_Right[2]))
		{
			bRet = true; //此时直线在激光线左侧，即是由黑到白找到的
		}
		else
		{
			bRet = false; //此时直线在激光线右侧，即是由白到黑找到的
		}
	}
	else if (ImgInput.channels() == 1)
	{
		int iPix_left = ImgInput.at<uchar>(ptBeside_Left.y(), ptBeside_Left.x());
		int iPix_right = ImgInput.at<uchar>(ptBeside_Right.y(), ptBeside_Right.x());
		if (iPix_left < iPix_right)
		{
			bRet = true; //此时直线在激光线左侧，即是由黑到白找到的
		}
		else
		{
			bRet = false; //此时直线在激光线右侧，即是由白到黑找到的
		}
	}
	return bRet;
}

QPoint CFindLineBase::GetLineOffset(const QLine lineInput)
{
	QMatrix lineMatrix;
	QPoint ptLaserLine_Center_Init;
	QPoint ptLineCenter = GetLineCenter(lineInput);
	double dwAngle = GetLineAngle(lineInput);

	if (true == QueryEdgeLineDirection(m_nImage_Binary,lineInput))
	{
		//此时找到的直线在激光线左侧
		ptLaserLine_Center_Init = QPoint(ptLineCenter.x() + LaserLine_width / 2, ptLineCenter.y());
	}
	else
	{
		//此时找到的直线在激光线右侧
		ptLaserLine_Center_Init = QPoint(ptLineCenter.x() - LaserLine_width / 2, ptLineCenter.y());
	}
	QPolygon pol_Temp;
	pol_Temp.clear();
	pol_Temp.push_back(ptLaserLine_Center_Init);
	lineMatrix.translate(ptLineCenter.x(), ptLineCenter.y());
	lineMatrix.rotate(-dwAngle);
	lineMatrix.translate(-ptLineCenter.x(), -ptLineCenter.y());
	pol_Temp = pol_Temp * lineMatrix;
	QPoint ptLaserLine_Center_Now = pol_Temp.at(0);

	QPoint ptOutput = QPoint(ptLaserLine_Center_Now.x() - ptLineCenter.x(), ptLaserLine_Center_Now.y() - ptLineCenter.y());
	return ptOutput;
}

bool CFindLineBase::IsSameLine(const QLine lineA, const QLine lineB)
{
	LineType iLine_Type = QueryLineType(lineA);
	if (iLine_Type != QueryLineType(lineB))
	{
		return false;
	}

	QPoint ptCenter_A = GetLineCenter(lineA);
	QPoint ptCenter_B = GetLineCenter(lineB);
	if ((abs(ptCenter_A.x() - ptCenter_B.x()) < 2) && (abs(ptCenter_A.y() - ptCenter_B.y()) < 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CFindLineBase::FindCurrentLine(const Mat ImgInput, const int iThreshold_toFindline, const int iMin_threshold, const int iMax_threshold, const int iMin_LaserArea, const int iMax_LaserArea, Mat &ImgOutput, QLine &lineOutput)
{
	cv::Mat Image_Input;
	ImgInput.copyTo(Image_Input);

	//获取适合当前图像二值化的阈值
	int iThreshold_Binary = GetCurrentThreshold(Image_Input, iMin_threshold, iMax_threshold, iMin_LaserArea, iMax_LaserArea);
	if (iThreshold_Binary < 20)
	{
		return false;
	}
	Mat Img_Binary = GetBinaryzationImage(Image_Input, iThreshold_Binary);
	Img_Binary.copyTo(m_nImage_Binary);

	Mat Img_Filter = GetFilterImage(Img_Binary, 0);

	vector<Vec4i> LinePoints_Array;
	LinePoints_Array.clear();
	HoughLinesP(Img_Filter, LinePoints_Array, 1, CV_PI / 180, iThreshold_toFindline, 20, 10);
	
	if (LinePoints_Array.size() <= 0)
	{
		Image_Input.copyTo(ImgOutput);
		return false;
	}

	vector<QLine> line_Array;
	line_Array.clear();
	for (int i = 0; i < LinePoints_Array.size(); i++)
	{
		QPoint ptA, ptB;
		ptA.setX(LinePoints_Array[i][0]);
		ptA.setY(LinePoints_Array[i][1]);
		ptB.setX(LinePoints_Array[i][2]);
		ptB.setY(LinePoints_Array[i][3]);
		QLine line_temp = GetValidLine(ptA, ptB);
		line_Array.push_back(line_temp);
	}

	if (line_Array.size() <= 0)
	{
		Image_Input.copyTo(ImgOutput);
		return false;
	}

	lineOutput = GetFitLine(line_Array);
	cv::Point ptBegin(lineOutput.x1(), lineOutput.y1());
	cv::Point ptEnd(lineOutput.x2(), lineOutput.y2());
	cv::line(Image_Input, ptBegin, ptEnd, Line_RED, 2, 8, 0);
	Image_Input.copyTo(ImgOutput);
	return true;
}
