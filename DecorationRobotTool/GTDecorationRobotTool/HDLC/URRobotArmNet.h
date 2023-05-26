
#include "URModbusNet.h"

#pragma once

class CURRobotArmNet
{
public:
	CURRobotArmNet();
	virtual ~CURRobotArmNet();

public:
	bool OpenPort(const char *pBufIpAddr, const unsigned short iPort);
	bool ClosePort();

	void GetSpacePositions(double dzPostisions[]); //��ȡ��е�ֿռ�����ֵ
	void GetSpaceSpeed(double dzSpeed[]); //��ȡ��е�ֿռ��ٶ�
	void GetJointAngle(double dzAngle[]); //��ȡ��е�ֹؽڽǶ�
	void GetJointSpeed(double dzSpeed[]); //��ȡ��е�ֹؽڽ��ٶ�
	void GetJointCurrent(double dzCurrent[]); //��ȡ��е�ֹؽڵ���ֵ
	void GetJointTemperature(double dzTemperature[]); //��ȡ��е�ֹؽ��¶�ֵ

	QString GetRobotState();

	double GetTcpForce();     //��ȡTcpĩ�˵���

	bool Write_Register(const QString strCmd);

	bool Write(QString strCmd);
	bool Write_withFreeBack(QString strCmd, char szRecvBuffer[]);

	bool Write_Other(QString strCmd);

	bool addCommandToQueue(QString strCmd);

private:
	void ur_unPack(const char* pBuffer);

	std::vector<double> ur_unpackVector(const char* pBuffer, const int iIndex, const int iNum);

	std::vector<bool> ur_unpackDigitalInputBits(int64_t data);

private:
	CURModbusNet *m_pURRobotSpacePos;
	CURModbusNet *m_pURRobotSpaceSpeed;
	CURModbusNet *m_pURRobotJointAngle;
	CURModbusNet *m_pURRobotJointSpeed;
	CURModbusNet *m_pURRobotJointCurrent;
	CURModbusNet *m_pURRobotJointTemperature;
	CURModbusNet *m_pURRobotState;
	CURModbusNet *m_pURRobot_RegisterWrite;

	CURModbusNet *m_pURRobot_Move_Control;
	CURModbusNet *m_pURRobot_Other_Control;


	std::vector<double> tcp_force_; //Generalised forces in the TC
};

