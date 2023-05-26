
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <vector>
#include <string>
#include <stdint.h>
#include "winsock2.h"

#pragma comment(lib, "ws2_32.lib")

#pragma once

const int iRobotNetTimeOut = 1000;

enum FunctionCode
{
	GT_Read = 3,
	GT_Write = 16
};

//CURRobotArmNet

class CURModbusNet
{
public:
	CURModbusNet();
	virtual ~CURModbusNet();

public:
	bool OpenPort(const char *pBufIpAddr, const unsigned short iPort);
	bool ClosePort();

	bool WriteControlCmd(const char szCmd[], const int iLength);
	bool WriteControlCmd_WithFreeBack(const char szCmd[], const int iLength, char szRecvBuffer[]);

	bool Read_Prog(char szRecvBuffer[]);

	bool WriteMultipleRegister(QString strRegisterInput, int iRegisterNum, int iStartAddress, bool bSlow);
	bool ReadMultipleRegister(int iResigterNum, int iStartAddress, bool bSlow, int RecvBuf[]);
private:
	bool InitNetWork(const char *pBufIpAddr, const unsigned short iPort);

	void CreateWriteMessgae(char *pBufferIn, int iRegisterNum, int iStartAddress, char BufferOut[]);
	void CreateReadMessage(int iResigterNum, int iStartAddress, char BufferOut[]);
	void TranslateIntToByte(int iNumberInput, byte BufOut[]);
private:
	SOCKET m_sSocket;
	SOCKADDR_IN m_sAddr;
};

