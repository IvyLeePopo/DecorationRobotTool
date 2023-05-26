#pragma once

#include "HDLCNet.h"

class CChasisNet :
	public CHDLCnet
{
public:
	CChasisNet(void);
	virtual ~CChasisNet(void);


public:
	bool OpenPort(const char *pBufIpAddr, const unsigned short iPort);
	bool ClosePort();
	bool Write(byte Buffer[], byte addr, int iBufferLen);
	bool Read(byte addr, char RecvBuf[]);

private:
	SOCKET m_sSocket;
	SOCKADDR_IN m_sAddr;
};

