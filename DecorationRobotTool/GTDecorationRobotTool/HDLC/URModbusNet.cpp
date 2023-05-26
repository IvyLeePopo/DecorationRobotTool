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

	fd_set rfdSet; //描述符集 这个将测试连接是否可用
	FD_ZERO(&rfdSet); //先清空描述符集

	timeval TimeOut;
	TimeOut.tv_sec = 6; //连接超时时间为6秒
	TimeOut.tv_usec = 0;

	u_long ul;

	//初始化套结字动态库
	WSADATA wsd; //WSADATA变量
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		return false;
	}

	//创建套接字
	m_sSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_sSocket == INVALID_SOCKET)
	{
		WSACleanup();//释放套接字资源
		return false;
	}

	m_sAddr.sin_addr.S_un.S_addr = inet_addr(pBufIpAddr);
	m_sAddr.sin_family = AF_INET;
	m_sAddr.sin_port = htons(iPort);

	ul = 1;
	ioctlsocket(m_sSocket, FIONBIO, &ul); //设置为非阻塞模式
	connect(m_sSocket, (SOCKADDR*)&m_sAddr, sizeof(SOCKADDR));

	FD_SET(m_sSocket, &rfdSet);
	if (select(m_sSocket + 1, 0, &rfdSet, 0, &TimeOut) <= 0)
	{
		ClosePort();
		WSACleanup();//释放套接字资源
		return false;
	}
	getsockopt(m_sSocket, SOL_SOCKET, SO_ERROR, (char*)&iError, (int *)&len);
	ul = 0;
	ioctlsocket(m_sSocket, FIONBIO, &ul); //设置为阻塞模式
	setsockopt(m_sSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&iRobotNetTimeOut, sizeof(int)); //设置发送的超时时间
	setsockopt(m_sSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&iRobotNetTimeOut, sizeof(int)); //设置接收的超时时间
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

	//将传入的字符串按"|"进行分割
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

	//2 发数据	
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
	//2 发送查询命令
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
	//1.1（数据位：1-2） 定义我是谁(Transaction Identifier),协议给了我2byte空间定义我是谁（我代号就是01，如果Modbus TCP Server接收成功，返回信息也要有这个代号）
	BufferOut[0] = 0;
	BufferOut[1] = 1;

	//1.2 （数据位：3-4）定义协议号，协议给了我2byte空间定义协议号（协议号就是00，表示这是MODBUS 协议）
	BufferOut[2] = 0;
	BufferOut[3] = 0;

	//1.3 （数据位：5-6）现在考虑将56两位凑到一块
	int iDataLength = strlen(pBufferIn) + 7;
	BufferOut[4] = (iDataLength & 0x0000FF00) >> 8;
	BufferOut[5] = iDataLength & 0x000000FF;

	//1.4 （数据位：7）只要补全一个0即可
	BufferOut[6] = 0;

	//1.5 （数据位：8）定义功能码（把写多个寄存器这个16码转换为byte类型数据）
	BufferOut[7] = GT_Write;

	//1.6 （数据位：9-10）起始地址，现在把地址这个int类型转换为两个byte(地址他说我差1，我就给他减掉1好了)
	BufferOut[8] = (iStartAddress & 0x0000FF00) >> 8;
	BufferOut[9] = iStartAddress & 0x000000FF;

	//1.7  （数据位：11-12）寄存器数量（不可能超过255个）
	BufferOut[10] = 0;
	BufferOut[11] = iRegisterNum;

	//1.8 （数据位：13）发送数据的长度，跟前面保持不变
	BufferOut[12] = strlen(pBufferIn);

	strncat(BufferOut, pBufferIn, strlen(pBufferIn));
}

void CURModbusNet::CreateReadMessage(int iResigterNum, int iStartAddress, char BufferOut[])
{
	//1.1（数据位：1-2） 定义我是谁
	BufferOut[0] = 0;
	BufferOut[1] = 1;

	//1.2 （数据位：3-4）定义协议号
	BufferOut[2] = 0;
	BufferOut[3] = 0;

	//1.3 （数据位：5-6）header还有几位？（对于读取来说，header后面定死了还有6位）
	BufferOut[4] = (6 & 0x0000FF00) >> 8;
	BufferOut[5] = 6 & 0x000000FF;

	//1.4 （数据位：7）只要补全一个0即可
	BufferOut[6] = 0;

	//1.5 （数据位：8）定义功能码（把读多个寄存器这个03码转换为byte类型数据）Function Code : 03 (Read Multiple Registers)
	BufferOut[7] = GT_Read;

	//1.6 （数据位：9-10）起始地址，现在把地址这个int类型转换为两个byte
	BufferOut[8] = (iStartAddress & 0x0000FF00) >> 8;
	BufferOut[9] = iStartAddress & 0x000000FF;

	//1.7  （数据位：11-12）寄存器数量，默认要读取的寄存器数量不超过255个，所以高位不管了
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
