

#include "FindLineBase.h"

#pragma once


class CFindLine
{
public:
	CFindLine();
	virtual ~CFindLine();

public:
	bool StartFindLine(const double dwCalibration, const int iThreshold_toFindline,
		               const int iMin_threshold, const int iMax_threshold, 
		               const int iMin_LaserArea, const int iMax_LaserArea, 
					   Mat &ImgOutput, double &dwAngle_Output, double &dwDis_Output);
private:
	void InitializeCamera();//初始化相机
	void ReleaseCameraUnit();
	Mat GetFramImage();

	double GetDis_PointToLine(const QLine lineInput,const QPoint ptInput);
private:
	CFindLineBase *m_pFindLineBase;
	VideoCapture m_vCapture;
	Point m_ptImageCenter; //采集的图像的中点
};

