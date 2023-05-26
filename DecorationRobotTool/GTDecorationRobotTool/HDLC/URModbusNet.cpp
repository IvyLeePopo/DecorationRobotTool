#include "URModbusNet.h"


CURModbusNet::CURModbusNet()
{
}


CURModbusNet::~CURModbusNet()
{
}

bool CURModbusNet::InitNetWork(const char *pBufIpAddr, const unsigned short iPort)
{
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
	m_sSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_sSocket == INVALID_SOCKET)
	{
		WSACleanup();//�ͷ��׽�����Դ
		return false;
	}

	m_sAddr.sin_addr.S_un.S_addr = inet_addr(pBufIpAddr);
	m_sAddr.sin_family = AF_INET;
	m_sAddr.sin_port = htons(iPort);

	ul = 1;
	ioctlsocket(m_sSocket, FIONBIO, &ul); //����Ϊ������ģʽ
	connect(m_sSocket, (SOCKADDR*)&m_sAddr, sizeof(SOCKADDR));

	FD_SET(m_sSocket, &rfdSet);
	if (select(m_sSocket + 1, 0, &rfdSet, 0, &TimeOut) <= 0)
	{
		ClosePort();
		WSACleanup();//�ͷ��׽�����Դ
		return false;
	}
	getsockopt(m_sSocket, SOL_SOCKET, SO_ERROR, (char*)&iError, (int *)&len);
	ul = 0;
	ioctlsocket(m_sSocket, FIONBIO, &ul); //����Ϊ����ģʽ
	setsockopt(m_sSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&iRobotNetTimeOut, sizeof(int)); //���÷��͵ĳ�ʱʱ��
	setsockopt(m_sSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&iRobotNetTimeOut, sizeof(int)); //���ý��յĳ�ʱʱ��
	return true;
}

bool CURModbusNet::OpenPort(const char *pBufIpAddr, const unsigned short iPort)
{
	if (false == InitNetWork(pBufIpAddr, iPort))
	{
		return false;
	}
	return true;
}

bool CURModbusNet::ClosePort()
{
	if (SOCKET_ERROR == closesocket(m_sSocket))
	{
		return false;
	}
	return true;
}

bool CURModbusNet::WriteMultipleRegister(QString strRegisterInput, int iRegisterNum, int iStartAddress, bool bSlow)
{
	char *pRegisterData = new char[iRegisterNum * 2];

	//��������ַ�����"|"���зָ�
	QStringList strRegisterArray = strRegisterInput.split(QRegExp("[, | ]"));
	if (strRegisterArray.length() != iRegisterNum)
	{
		return false;
	}
	for (int i = 0; i < strRegisterArray.length(); i++)
	{
		byte bzTemp[5];
		TranslateIntToByte(strRegisterArray[i].toInt(), bzTemp);
		pRegisterData[i * 2] = bzTemp[0];
		pRegisterData[i * 2 + 1] = bzTemp[1];
	}

	char szCmd[255] = { 0 };
	CreateWriteMessgae(pRegisterData, iRegisterNum, iStartAddress, szCmd);

	//2 ������	
	if (SOCKET_ERROR == send(m_sSocket, szCmd, sizeof(szCmd), 0))
	{
		return false;
	}
	return true;
}

bool CURModbusNet::ReadMultipleRegister(int iResigterNum, int iStartAddress, bool bSlow, int RecvBuf[])
{
	char szCmd[12] = { 0 };
	CreateReadMessage(iResigterNum, iStartAddress, szCmd);
	//2 ���Ͳ�ѯ����
	if (SOCKET_ERROR == send(m_sSocket, szCmd, sizeof(szCmd), 0))
	{
		return false;
	}

	char szBuffer[255] = { 0 };
	if (SOCKET_ERROR == recv(m_sSocket, szBuffer, sizeof(szBuffer), 0))
	{
		return false;
	}


	byte bzBufferOut[12] = {0};
	for (int i = 0; i < iResigterNum * 2; i++)
	{
		bzBufferOut[i] = (byte)szBuffer[i + 9];
	}

	for (int i = 0; i < iResigterNum; i++)
	{
		RecvBuf[i] = bzBufferOut[i * 2] * 256 + bzBufferOut[i * 2 + 1];
	}
	return true;
}

void CURModbusNet::CreateWriteMessgae(char *pBufferIn, int iRegisterNum, int iStartAddress, char BufferOut[])
{
	//1.1������λ��1-2�� ��������˭(Transaction Identifier),Э�������2byte�ռ䶨������˭���Ҵ��ž���01�����Modbus TCP Server���ճɹ���������ϢҲҪ��������ţ�
	BufferOut[0] = 0;
	BufferOut[1] = 1;

	//1.2 ������λ��3-4������Э��ţ�Э�������2byte�ռ䶨��Э��ţ�Э��ž���00����ʾ����MODBUS Э�飩
	BufferOut[2] = 0;
	BufferOut[3] = 0;

	//1.3 ������λ��5-6�����ڿ��ǽ�56��λ�յ�һ��
	int iDataLength = strlen(pBufferIn) + 7;
	BufferOut[4] = (iDataLength & 0x0000FF00) >> 8;
	BufferOut[5] = iDataLength & 0x000000FF;

	//1.4 ������λ��7��ֻҪ��ȫһ��0����
	BufferOut[6] = 0;

	//1.5 ������λ��8�����幦���루��д����Ĵ������16��ת��Ϊbyte�������ݣ�
	BufferOut[7] = GT_Write;

	//1.6 ������λ��9-10����ʼ��ַ�����ڰѵ�ַ���int����ת��Ϊ����byte(��ַ��˵�Ҳ�1���Ҿ͸�������1����)
	BufferOut[8] = (iStartAddress & 0x0000FF00) >> 8;
	BufferOut[9] = iStartAddress & 0x000000FF;

	//1.7  ������λ��11-12���Ĵ��������������ܳ���255����
	BufferOut[10] = 0;
	BufferOut[11] = iRegisterNum;

	//1.8 ������λ��13���������ݵĳ��ȣ���ǰ�汣�ֲ���
	BufferOut[12] = strlen(pBufferIn);

	strncat(BufferOut, pBufferIn, strlen(pBufferIn));
}

void CURModbusNet::CreateReadMessage(int iResigterNum, int iStartAddress, char BufferOut[])
{
	//1.1������λ��1-2�� ��������˭
	BufferOut[0] = 0;
	BufferOut[1] = 1;

	//1.2 ������λ��3-4������Э���
	BufferOut[2] = 0;
	BufferOut[3] = 0;

	//1.3 ������λ��5-6��header���м�λ�������ڶ�ȡ��˵��header���涨���˻���6λ��
	BufferOut[4] = (6 & 0x0000FF00) >> 8;
	BufferOut[5] = 6 & 0x000000FF;

	//1.4 ������λ��7��ֻҪ��ȫһ��0����
	BufferOut[6] = 0;

	//1.5 ������λ��8�����幦���루�Ѷ�����Ĵ������03��ת��Ϊbyte�������ݣ�Function Code : 03 (Read Multiple Registers)
	BufferOut[7] = GT_Read;

	//1.6 ������λ��9-10����ʼ��ַ�����ڰѵ�ַ���int����ת��Ϊ����byte
	BufferOut[8] = (iStartAddress & 0x0000FF00) >> 8;
	BufferOut[9] = iStartAddress & 0x000000FF;

	//1.7  ������λ��11-12���Ĵ���������Ĭ��Ҫ��ȡ�ļĴ�������������255�������Ը�λ������
	BufferOut[10] = 0;
	BufferOut[11] = iResigterNum;
}

void CURModbusNet::TranslateIntToByte(int iNumberInput, byte BufOut[])
{
	memset(BufOut, 0, sizeof(BufOut));

	int InputNumber_Hign = iNumberInput / 256;
	int InputNumber_Low = iNumberInput % 256;
	BufOut[0] = (byte)InputNumber_Hign;
	BufOut[1] = (byte)InputNumber_Low;
}

bool CURModbusNet::WriteControlCmd(const char szCmd[], const int iLength)
{
	if (SOCKET_ERROR == send(m_sSocket, szCmd, iLength, 0))
	{
		return false;
	}
	return true;
}

bool CURModbusNet::WriteControlCmd_WithFreeBack(const char szCmd[], const int iLength, char szRecvBuffer[])
{
	if (SOCKET_ERROR == send(m_sSocket, szCmd, iLength, 0))
	{
		return false;
	}

	if (SOCKET_ERROR == recv(m_sSocket, szRecvBuffer, 255, 0))
	{
		return false;
	}
	return true;
}

bool CURModbusNet::Read_Prog(char szRecvBuffer[])
{
	if (SOCKET_ERROR == recv(m_sSocket, szRecvBuffer, 2048, 0))
	{
		return false;
	}
	return true;
}
