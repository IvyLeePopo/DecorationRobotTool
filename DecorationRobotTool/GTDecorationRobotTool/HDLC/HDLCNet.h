
#include <QString>
#include <vector>
#include <string>
#include "winsock2.h"

#pragma comment(lib, "ws2_32.lib")

#pragma once


const int iNetTimeOut = 1000;


class CHDLCnet
{
public:
	virtual~CHDLCnet(void)
	{};

public:
	virtual bool OpenPort(const char *pBufIpAddr, const unsigned short iPort) = 0;
	virtual bool ClosePort() = 0;
	virtual bool Write(byte Buffer[], byte addr, int iBufferLen) = 0;
	virtual bool Read(byte addr, char RecvBuf[]) = 0;

public:
	inline bool Init_NetWork(const char *pBufIpAddr, const unsigned short iPort, SOCKET &socket_Out);

	inline void Create_Write_Messgae(byte BufferIn[], byte addr, int ilen, char BufOut[]);
	inline void Create_Read_Message(byte addr, char BufferOut[]);
	inline bool Parse_Read_Data(char RecvData[], int iDataLen, char RecvBuf[]);
	inline bool Parse_Write_Data(char RecvData[], int iDataLen);
	inline int Get_Head_RecvData(char RecvData[], int iDataLen, bool bIsRead);
	inline int Get_Tail_RecvData(char RecvData[], const int iIndex_Begin, int iDataLen);
	inline QString Get_Hex_ErrorInfo(const char ReadData[], const int iDataLen);

	inline std::string byteToHexStr(byte *pData, int iLen);

private:

};

bool CHDLCnet::Init_NetWork(const char *pBufIpAddr, const unsigned short iPort, SOCKET &socket_Out)
{
	SOCKET sSocket_Temp;

	int iError = -1;
	int len = sizeof(int);

	fd_set rfdSet; //�������� ��������������Ƿ����
	FD_ZERO(&rfdSet); //�������������

	timeval TimeOut;
	TimeOut.tv_sec = 6; //���ӳ�ʱʱ��Ϊ6��
	TimeOut.tv_usec = 0;

	u_long ul;

	//��ʼ���׽��ֶ�̬��
	WSADATA wsd; //WSADATA����
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		return false;
	}

	//�����׽���
	sSocket_Temp = socket(AF_INET, SOCK_STREAM, 0);
	if (sSocket_Temp == INVALID_SOCKET)
	{
		WSACleanup();//�ͷ��׽�����Դ
		return false;
	}

	SOCKADDR_IN sAddr_Temp;
	sAddr_Temp.sin_addr.S_un.S_addr = inet_addr(pBufIpAddr);
	sAddr_Temp.sin_family = AF_INET;
	sAddr_Temp.sin_port = htons(iPort);

	ul = 1;
	ioctlsocket(sSocket_Temp, FIONBIO, &ul); //����Ϊ������ģʽ
	connect(sSocket_Temp, (SOCKADDR*)&sAddr_Temp, sizeof(SOCKADDR));

	FD_SET(sSocket_Temp, &rfdSet);
	if (select(sSocket_Temp + 1, 0, &rfdSet, 0, &TimeOut) <= 0)
	{
		ClosePort();
		WSACleanup();//�ͷ��׽�����Դ
		return false;
	}
	getsockopt(sSocket_Temp, SOL_SOCKET, SO_ERROR, (char*)&iError, (int *)&len);
	ul = 0;
	ioctlsocket(sSocket_Temp, FIONBIO, &ul); //����Ϊ����ģʽ
	setsockopt(sSocket_Temp, SOL_SOCKET, SO_SNDTIMEO, (char*)&iNetTimeOut, sizeof(int)); //���÷��͵ĳ�ʱʱ��
	setsockopt(sSocket_Temp, SOL_SOCKET, SO_RCVTIMEO, (char*)&iNetTimeOut, sizeof(int)); //���ý��յĳ�ʱʱ��

	socket_Out = sSocket_Temp;
	return true;
}

void CHDLCnet::Create_Write_Messgae(byte BufferIn[], byte addr, int ilen, char BufOut[])
{
	byte checksum = 0;
	memset(BufOut, 0, sizeof(BufOut));

	BufOut[0] = '{';
	BufOut[1] = 'G';
	BufOut[2] = 'T';
	BufOut[3] = addr;
	BufOut[4] = 0x00;
	BufOut[5] = 0x00;
	BufOut[6] = 0x01;
	BufOut[7] = ilen;
	for (int i = 8; i < ilen + 8; i++)
	{
		BufOut[i] = BufferIn[i - 8];
	}
	for (int i = 3; i < ilen + 8; i++)
	{
		checksum += (byte)BufOut[i];
	}
	BufOut[8 + ilen] = 0xff - checksum;
	BufOut[9 + ilen] = 'E';
	BufOut[10 + ilen] = 'N';
	BufOut[11 + ilen] = 'D';
	BufOut[12 + ilen] = '}';
}

void CHDLCnet::Create_Read_Message(byte addr, char BufferOut[])
{
	byte checksum = 0;
	BufferOut[0] = '{';
	BufferOut[1] = 'G';
	BufferOut[2] = 'T';
	BufferOut[3] = addr;
	BufferOut[4] = 0x00;
	BufferOut[5] = 0x00;
	BufferOut[6] = 0x00;
	BufferOut[7] = 0x00;
	for (int i = 3; i < 8; i++)
	{
		checksum += BufferOut[i];
	}
	BufferOut[8] = 0xff - checksum;
	BufferOut[9] = 'E';
	BufferOut[10] = 'N';
	BufferOut[11] = 'D';
	BufferOut[12] = '}';
}

bool CHDLCnet::Parse_Read_Data(char RecvData[], int iDataLen, char RecvBuf[])
{
	int iPos_Begin = Get_Head_RecvData(RecvData, iDataLen, true);
	int iPos_End = Get_Tail_RecvData(RecvData, iPos_Begin, iDataLen);

	if ((iPos_Begin < 0) || (iPos_End < 0) || (iPos_End < iPos_Begin + 10))
	{
		return false;
	}

	byte checkSum = 0;
	for (int i = iPos_Begin + 3; i < iPos_End - iPos_Begin - 3; i++)
	{
		checkSum += RecvData[i];
	}
	if (checkSum != 0xff)
	{
		return false;
	}
	for (int i = 0; i < iPos_End - iPos_Begin - 12; i++)
	{
		RecvBuf[i] = RecvData[i + iPos_Begin + 8];
	}
	return true;
}

bool CHDLCnet::Parse_Write_Data(char RecvData[], int iDataLen)
{
	int iPos_Begin = Get_Head_RecvData(RecvData, iDataLen, false);
	int iPos_End = Get_Tail_RecvData(RecvData, iPos_Begin, iDataLen);

	if ((iPos_Begin < 0) || (iPos_End < 0) || (iPos_End < iPos_Begin + 10))
	{
		return false;
	}

	byte checkSum = 0;
	for (int i = iPos_Begin + 3; i < iPos_End - iPos_Begin - 3; i++)
	{
		checkSum += RecvData[i];
	}
	if (checkSum != 0xff)
	{
		return false;
	}
	return true;
}

int CHDLCnet::Get_Head_RecvData(char RecvData[], int iDataLen, bool bIsRead)
{
	int iPos_Output = -1;
	for (int i = 0; i < iDataLen; i++)
	{
		//���ҵ�'{'�������е�����
		if (0x7B != RecvData[i]) // "{" = 123(ʮ����) = 0x7b��ʮ�����ƣ�
		{
			continue;
		}
		if (i + 6 > iDataLen)
		{
			continue;
		}
		if (0x47 != RecvData[i + 1]) // "G" = 71(ʮ����) = 0x47��ʮ�����ƣ�
		{
			continue;
		}
		if (0x54 != RecvData[i + 2]) // "T" = 84(ʮ����) = 0x54��ʮ�����ƣ�
		{
			continue;
		}
		if (0x00 != RecvData[i + 4]) // ָ��汾��_1
		{
			continue;
		}
		if (0x00 != RecvData[i + 5]) // ָ��汾��_2
		{
			continue;
		}
		if (bIsRead)
		{
			if (0x00 != RecvData[i + 6]) // CMD-1
			{
				continue;
			}
		}
		else
		{
			if (0x01 != RecvData[i + 6]) // CMD-1
			{
				continue;
			}
		}
		iPos_Output = i;
		break;
	}

	return iPos_Output;
}

int CHDLCnet::Get_Tail_RecvData(char RecvData[], const int iIndex_Begin, int iDataLen)
{
	int iPos_Output = -1;
	for (int i = iIndex_Begin; i < iDataLen; i++)
	{
		//���ҵ�'}'�������е�����
		if (0x7d != RecvData[i])
		{
			continue;
		}
		if (i - 3 < 0)
		{
			continue;
		}
		if (0x45 != RecvData[i - 3]) // "E" = 69(ʮ����) = 0x45��ʮ�����ƣ�
		{
			continue;
		}
		if (0x4e != RecvData[i - 2]) // "N" = 78(ʮ����) = 0x4e��ʮ�����ƣ�
		{
			continue;
		}
		if (0x44 != RecvData[i - 1]) // "D" = 68(ʮ����) = 0x44��ʮ�����ƣ�
		{
			continue;
		}
		if (0x7d != RecvData[i]) // "}" = 125(ʮ����) = 0x7d��ʮ�����ƣ�
		{
			continue;
		}
		iPos_Output = i;
		break;
	}
	return iPos_Output;
}

QString CHDLCnet::Get_Hex_ErrorInfo(const char ReadData[], const int iDataLen)
{
	QString strOutput;
	char szError[300] = { 0 };
	int iSpaceCount = iDataLen - 1; //�ո������
	int iPos_End = -1;
	for (int i = 0; i < iDataLen; i++)
	{
		//���ҵ�'}'�������е�����
		if (0x7d == ReadData[i])
		{
			iPos_End = i;
		}
	}
	if (iPos_End < 0)
	{
		strOutput = "NULL";
	}
	else
	{
		for (int i = 0; i < iPos_End; i++)
		{
			szError[2 * i] = ReadData[i];
			szError[2 * i - 1] = ' ';
		}
		strOutput = ((QByteArray)szError).toHex();
	}
	return strOutput;
}

std::string CHDLCnet::byteToHexStr(byte *pData, int iLen)
{
	std::string strHex, strTemp_1, strTemp_2;
	strHex.clear();
	for (int i = 0; i < iLen; i++)
	{
		int high = pData[i] / 16;
		int low = pData[i] % 16;
		strTemp_1 = (high < 10) ? ('0' + high) : ('A' + high - 10);
		strTemp_2 = (low < 10) ? ('0' + low) : ('A' + low - 10);
		strHex.append(strTemp_1);
		strHex.append(strTemp_2);
	}
	return strHex;
}
