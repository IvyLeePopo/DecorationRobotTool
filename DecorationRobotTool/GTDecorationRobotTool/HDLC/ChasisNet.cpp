#include "ChasisNet.h"


CChasisNet::CChasisNet()
{
}


CChasisNet::~CChasisNet()
{
}

bool CChasisNet::OpenPort(const char *pBufIpAddr, const unsigned short iPort)
{
	if (false == Init_NetWork(pBufIpAddr, iPort, m_sSocket))
	{
		return false;
	}
	return true;
}

bool CChasisNet::ClosePort()
{
	if (SOCKET_ERROR == closesocket(m_sSocket))
	{
		return false;
	}
	return true;
}

bool CChasisNet::Write(byte Buffer[], byte addr, int iBufferLen)
{
	char szCmd[30] = { 0 };
	char pBuffer[100] = { 0 };
	Create_Write_Messgae(Buffer, addr, iBufferLen, szCmd);
	Sleep(10);
	if (SOCKET_ERROR == send(m_sSocket, szCmd, 0x0d + iBufferLen, 0))
	{
		return false;
	}
	Sleep(10);
	if (SOCKET_ERROR == recv(m_sSocket, pBuffer, sizeof(pBuffer), 0))
	{
		return false;
	}
	if (false == Parse_Write_Data(pBuffer, sizeof(pBuffer)))
	{
		return false;
	}
	return true;
}

bool CChasisNet::Read(byte addr, char RecvBuf[])
{
	char szCmd[13] = { 0 };
	char pBuffer[100] = { 0 };
	Create_Read_Message(addr, szCmd);
	Sleep(10);
	if (SOCKET_ERROR == send(m_sSocket, szCmd, 13, 0))
	{
		return false;
	}

	Sleep(10);
	if (SOCKET_ERROR == recv(m_sSocket, pBuffer, sizeof(pBuffer), 0))
	{
		return false;
	}
	if (false == Parse_Read_Data(pBuffer, sizeof(pBuffer), RecvBuf))
	{
		return false;
	}
	return true;
}
