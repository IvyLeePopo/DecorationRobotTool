#include "URRobotArmNet.h"


CURRobotArmNet::CURRobotArmNet()
{
	m_pURRobotSpacePos = new CURModbusNet();
	m_pURRobotSpaceSpeed = new CURModbusNet();
	m_pURRobotJointAngle = new CURModbusNet();
	m_pURRobotJointSpeed = new CURModbusNet();
	m_pURRobotJointCurrent = new CURModbusNet();
	m_pURRobotJointTemperature = new CURModbusNet();

	m_pURRobotState = new CURModbusNet();


	m_pURRobot_RegisterWrite = new CURModbusNet();

	m_pURRobot_Move_Control = new CURModbusNet();

	m_pURRobot_Other_Control = new CURModbusNet();
}


CURRobotArmNet::~CURRobotArmNet()
{
}

bool CURRobotArmNet::OpenPort(const char *pBufIpAddr, const unsigned short iPort)
{
	if (false == m_pURRobotSpacePos->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}
	if (false == m_pURRobotSpaceSpeed->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}
	if (false == m_pURRobotJointAngle->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}
	if (false == m_pURRobotJointSpeed->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}
	if (false == m_pURRobotJointCurrent->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}
	if (false == m_pURRobotJointTemperature->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}

	if (false == m_pURRobotState->OpenPort(pBufIpAddr, 30003))
	{
		return false;
	}

	if (false == m_pURRobot_RegisterWrite->OpenPort(pBufIpAddr, 502))
	{
		return false;
	}

	if (false == m_pURRobot_Move_Control->OpenPort(pBufIpAddr,iPort))
	{
		return false;
	}

	if (false == m_pURRobot_Other_Control->OpenPort(pBufIpAddr, 29999))
	{
		return false;
	}
	return true;
}

bool CURRobotArmNet::ClosePort()
{
	if (false == m_pURRobotSpacePos->ClosePort())
	{
		return false;
	}
	if (false == m_pURRobotSpaceSpeed->ClosePort())
	{
		return false;
	}
	if (false == m_pURRobotJointAngle->ClosePort())
	{
		return false;
	}
	if (false == m_pURRobotJointSpeed->ClosePort())
	{
		return false;
	}
	if (false == m_pURRobotJointCurrent->ClosePort())
	{
		return false;
	}
	if (false == m_pURRobotJointTemperature->ClosePort())
	{
		return false;
	}

	if (false == m_pURRobotState->ClosePort())
	{
		return false;
	}

	if (false == m_pURRobot_RegisterWrite->ClosePort())
	{
		return false;
	}

	if (false == m_pURRobot_Move_Control->ClosePort())
	{
		return false;
	}

	if (false == m_pURRobot_Other_Control->ClosePort())
	{
		return false;
	}
	return true;
}

void CURRobotArmNet::GetSpacePositions(double dzPostisions[])
{
	int izSixPositions[6] = { 0 };
	//这里实时读取UR数据（先读取六个坐标值，手册来看地址就是400）
	m_pURRobotSpacePos->ReadMultipleRegister(6, 400, false, izSixPositions);

	for (int i = 0; i < 6; i++)
	{
		//见Modbus UR参考文档：如果XYZ有超过32768，则变成负值（虽然是0-65535，但是我们要自己变成有符号数“-32767”到“32768”）
		if (izSixPositions[i] > 32768)
		{
			izSixPositions[i] = izSixPositions[i] - 65535;
		}
		//前面三个XYZ做同样处理(对于所有的XYZ都要除以10)
		if (i < 3)
		{
			dzPostisions[i] = (float)izSixPositions[i] / 10;
		}
		//后面三个UVW只要直接除以1000即可
		else
		{
			dzPostisions[i] = (float)izSixPositions[i] / 1000;
		}
	}
}

void CURRobotArmNet::GetSpaceSpeed(double dzSpeed[])
{
	int izSixSpeed[6] = { 0 };
	m_pURRobotSpaceSpeed->ReadMultipleRegister(6, 410, false, izSixSpeed);

	for (int i = 0; i < 6; i++)
	{
		//见Modbus UR参考文档：如果XYZ有超过32768，则变成负值（虽然是0-65535，但是我们要自己变成有符号数“-32767”到“32768”）
		if (izSixSpeed[i] > 32768)
		{
			izSixSpeed[i] = izSixSpeed[i] - 65535;
		}
		//前面三个XYZ做同样处理(对于所有的XYZ都要除以10)
		if (i < 3)
		{
			dzSpeed[i] = (float)izSixSpeed[i];
		}
		//后面三个UVW只要直接除以1000即可
		else
		{
			dzSpeed[i] = (double)izSixSpeed[i] / 1000 * (180 / 3.14);
		}
	}
}

void CURRobotArmNet::GetJointAngle(double dzAngle[])
{
	int izSixAngle[6] = { 0 };
	m_pURRobotJointAngle->ReadMultipleRegister(6, 270, false, izSixAngle);

	for (int i = 0; i < 6; i++)
	{
		if (izSixAngle[i] > 32768)
		{
			izSixAngle[i] = izSixAngle[i] - 65535;
		}
		//这里取到的都是弧度值，要转换为角度值(除以1000之后还是弧度，要再转换为角度)
		dzAngle[i] = (double)izSixAngle[i] / 1000 * (180 / 3.14);

// 		if ((i == 0) || (i == 1) || (i == 3))
// 		{
// 			dzAngle[i] = dzAngle[i] - 360;
// 		}

// 		if ((i == 1) || (i == 3) || (i == 4))
// 		{
// 			dzAngle[i] = dzAngle[i] - 360;
// 		}

		if ((i == 1) || (i == 3))
		{
			dzAngle[i] = dzAngle[i] - 360;
		}

	}
}

void CURRobotArmNet::GetJointSpeed(double dzSpeed[])
{
	int izSixSpeed[6] = { 0 };
	m_pURRobotJointSpeed->ReadMultipleRegister(6, 280, false, izSixSpeed);

	for (int i = 0; i < 6; i++)
	{
		if (izSixSpeed[i] > 32768)
		{
			izSixSpeed[i] = izSixSpeed[i] - 65535;
		}
		if (i < 3)
		{
			dzSpeed[i] = (float)izSixSpeed[i] / 1000 * (180 / 3.14);
		}
		else
		{
			dzSpeed[i] = (float)izSixSpeed[i] / 1000 * (180 / 3.14);
		}
	}
}

void CURRobotArmNet::GetJointCurrent(double dzCurrent[])
{
	int izSixCurrent[6] = { 0 };
	m_pURRobotJointCurrent->ReadMultipleRegister(6, 290, false, izSixCurrent);

	for (int i = 0; i < 6; i++)
	{
		if (izSixCurrent[i] > 32768)
		{
			izSixCurrent[i] = izSixCurrent[i] - 65535;
		}
		dzCurrent[i] = (double)izSixCurrent[i] / 1000;
	}
}

void CURRobotArmNet::GetJointTemperature(double dzTemperature[])
{
	int izSixTemperature[6] = { 0 };
	m_pURRobotJointTemperature->ReadMultipleRegister(6, 300, false, izSixTemperature);

	for (int i = 0; i < 6; i++)
	{
		if (izSixTemperature[i] > 32768)
		{
			izSixTemperature[i] = izSixTemperature[i] - 65535;
		}
		dzTemperature[i] = (double)izSixTemperature[i];
	}
}

double CURRobotArmNet::GetTcpForce()
{
	int izTcpForce[1] = { 0 };
	m_pURRobotJointTemperature->ReadMultipleRegister(1, 145, false, izTcpForce);

	if (izTcpForce[0] > 32768)
	{
		izTcpForce[0] = izTcpForce[0] - 65535;
	}
	double dwTcpForce = (double)izTcpForce[0];
	return dwTcpForce;
}

bool CURRobotArmNet::Write_Register(const QString strCmd)
{
	if (false == m_pURRobot_RegisterWrite->WriteMultipleRegister(strCmd,1,146,false))
	{
		return false;
	}
	return true;
}

bool CURRobotArmNet::Write(QString strCmd)
{
	strCmd += "\r\n";
	if (false == m_pURRobot_Move_Control->WriteControlCmd(strCmd.toStdString().c_str(), strCmd.length()))
	{
		return false;
	}
	return true;
}

bool CURRobotArmNet::Write_withFreeBack(QString strCmd, char szRecvBuffer[])
{
	strCmd += "\r\n";
	if (false == m_pURRobot_Move_Control->WriteControlCmd_WithFreeBack(strCmd.toStdString().c_str(), strCmd.length(), szRecvBuffer))
	{
		return false;
	}
	return true;
}

bool CURRobotArmNet::Write_Other(QString strCmd)
{
	strCmd += "\r\n";
	if (false == m_pURRobot_Other_Control->WriteControlCmd(strCmd.toStdString().c_str(), strCmd.length()))
	{
		return false;
	}
	return true;
}

bool CURRobotArmNet::addCommandToQueue(QString strCmd)
{
	strCmd += "\r\n";
	if (false == m_pURRobotState->WriteControlCmd(strCmd.toStdString().c_str(), strCmd.length()))
	{
		return false;
	}
	return true;
}

void CURRobotArmNet::ur_unPack(const char* pBuffer)
{
	std::vector<double> q_target_; //Target joint positions
	std::vector<double> qd_target_; //Target joint velocities
	std::vector<double> qdd_target_; //Target joint accelerations
	std::vector<double> i_target_; //Target joint currents
	std::vector<double> m_target_; //Target joint moments (torques)
	std::vector<double> q_actual_; //Actual joint positions
	std::vector<double> qd_actual_; //Actual joint velocities
	std::vector<double> i_actual_; //Actual joint currents
	std::vector<double> i_control_; //Joint control currents
	std::vector<double> tool_vector_actual_; //Actual Cartesian coordinates of the tool: (x,y,z,rx,ry,rz), where rx, ry and rz is a rotation vector representation of the tool orientation
	std::vector<double> tcp_speed_actual_; //Actual speed of the tool given in Cartesian coordinates
// 	std::vector<double> tcp_force_; //Generalised forces in the TC
	std::vector<double> tool_vector_target_; //Target Cartesian coordinates of the tool: (x,y,z,rx,ry,rz), where rx, ry and rz is a rotation vector representation of the tool orientation
	std::vector<double> tcp_speed_target_; //Target speed of the tool given in Cartesian coordinates
	std::vector<bool> digital_input_bits_; //Current state of the digital inputs. NOTE: these are bits encoded as int64_t, e.g. a value of 5 corresponds to bit 0 and bit 2 set high
	std::vector<double> motor_temperatures_;
	double controller_timer_;

	int64_t digital_input_bits;
	uint64_t unpack_to;
	uint16_t iOffset = 0;
	int iLen = 0;
	memcpy(&iLen, &pBuffer[iOffset], sizeof(iLen));

	iOffset += sizeof(iLen);
	iLen = ntohl(iLen);

	iOffset += sizeof(double);
	q_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	qd_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	qdd_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	i_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	m_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	q_actual_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	qd_actual_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	i_actual_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	i_control_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	tool_vector_actual_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	tcp_speed_actual_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	tcp_force_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	tool_vector_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	tcp_speed_target_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	memcpy(&digital_input_bits, &pBuffer[iOffset], sizeof(digital_input_bits));
	digital_input_bits_ = ur_unpackDigitalInputBits(ntohd(digital_input_bits));

	iOffset += sizeof(double);
	motor_temperatures_ = ur_unpackVector(pBuffer, iOffset, 6);

	iOffset += sizeof(double)* 6;
	memcpy(&unpack_to, &pBuffer[iOffset], sizeof(unpack_to));
	controller_timer_ = ntohd(unpack_to);
}

std::vector<double> CURRobotArmNet::ur_unpackVector(const char* pBuffer, const int iIndex, const int iNum)
{
	std::vector<double> ret;
	uint64_t q;
	for (int i = 0; i < iNum; i++)
	{
		memcpy(&q, &pBuffer[iIndex + i * sizeof(q)], sizeof(q));
		ret.push_back(ntohd(q));
	}
	return ret;
}

std::vector<bool> CURRobotArmNet::ur_unpackDigitalInputBits(int64_t data)
{
	std::vector<bool> ret;
	for (int i = 0; i < 64; i++) {
		ret.push_back((data & (1 << i)) >> i);
	}
	return ret;
}

QString CURRobotArmNet::GetRobotState()
{
	char szBuffer[2048];
	memset(szBuffer, 0, sizeof(szBuffer));
	m_pURRobotState->Read_Prog(szBuffer);
	ur_unPack(szBuffer);
	double dwForce_X = tcp_force_.at(0);
	double dwForce_Y = tcp_force_.at(1);
	double dwForce_Z = tcp_force_.at(2);
	double dwForce_tcp = sqrtf(pow(dwForce_X, 2) + pow(dwForce_Y, 2) + pow(dwForce_Z, 2));
	QString strOutput = QString::number(dwForce_tcp);
	return strOutput;
}
