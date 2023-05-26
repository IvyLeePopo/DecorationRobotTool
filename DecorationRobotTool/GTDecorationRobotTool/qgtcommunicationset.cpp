#include "qgtcommunicationset.h"

QGTCommunicationSet::QGTCommunicationSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);

	for (int i = 0; i < 20; i++)
	{
		QString strItem = "com" + QString::number(i + 1);
		ui.comboBox_Lidar_Port->addItem(strItem, i);
		ui.comboBox_LaserMeasure_Port->addItem(strItem, i);
		ui.comboBox_LiftPlatform_Port->addItem(strItem, i);
	}

	QStringList strList_Baudrate;
	strList_Baudrate << "9600" << "14400" << "19200" << "38400" << "56000" << "57600" << "115200";
	ui.comboBox_Lidar_Baudrate->addItems(strList_Baudrate);
	ui.comboBox_LaserMeasure_Baudrate->addItems(strList_Baudrate);
	ui.comboBox_LiftPlatform_Baudrate->addItems(strList_Baudrate);

	if (g_pGlobalUnit->m_nLoginState == LS_Developer)
	{
		ui.checkBox_IsSelect_Chasis_Connect->show();
		ui.checkBox_IsSelect_Robot_Connect->show();
		ui.checkBox_IsSelect_Ros_Connect->show();
		ui.checkBox_IsSelect_LiftPlat_Connect->show();
		ui.checkBox_IsSelect_JoyHandle_Connect->show();
		ui.checkBox_IsSelect_Chasis_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Chasis_Connect);
		ui.checkBox_IsSelect_Robot_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Robot_Connect);
		ui.checkBox_IsSelect_Ros_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Ros_Connect);
		ui.checkBox_IsSelect_Lidar_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Lidar_Connect);
		ui.checkBox_IsSelect_LaserMeasure_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_LaserMeasure_Connect);
		ui.checkBox_IsSelect_LiftPlat_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_LiftPlat_Connect);
		ui.checkBox_IsSelect_JoyHandle_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_JoyHandle_Connect);
	}
	else
	{
		ui.checkBox_IsSelect_Chasis_Connect->hide();
		ui.checkBox_IsSelect_Robot_Connect->hide();
		ui.checkBox_IsSelect_Ros_Connect->hide();
		ui.checkBox_IsSelect_Lidar_Connect->hide();
		ui.checkBox_IsSelect_LaserMeasure_Connect->hide();
		ui.checkBox_IsSelect_LiftPlat_Connect->hide();
		ui.checkBox_IsSelect_JoyHandle_Connect->hide();
		g_pGlobalUnit->m_bIsSelect_Chasis_Connect = true;
		g_pGlobalUnit->m_bIsSelect_Robot_Connect = true;
		g_pGlobalUnit->m_bIsSelect_Ros_Connect = true;
		g_pGlobalUnit->m_bIsSelect_Lidar_Connect = true;
		g_pGlobalUnit->m_bIsSelect_LaserMeasure_Connect = true;
		g_pGlobalUnit->m_bIsSelect_LiftPlat_Connect = true;
		g_pGlobalUnit->m_bIsSelect_JoyHandle_Connect = true;
	}

	ui.widget_Chasis_IpAddress->setIpText(g_pGlobalUnit->m_strChasis_IpAddr);
	ui.lineEdit_Chasis_Port->setText(g_pGlobalUnit->m_strChasis_Port);

	ui.widget_Robot_IpAddress->setIpText(g_pGlobalUnit->m_strRobot_IpAddr);
	ui.lineEdit_Robot_Port->setText(g_pGlobalUnit->m_strRobot_Port);

	ui.widget_Ros_IpAddress->setIpText(g_pGlobalUnit->m_strRos_IpAddr);
	ui.lineEdit_Ros_Port->setText(g_pGlobalUnit->m_strRos_Port);
	ui.comboBox_Lidar_Port->setCurrentText(g_pGlobalUnit->m_strLidar_Port);
	ui.comboBox_Lidar_Baudrate->setCurrentText(QString::number(g_pGlobalUnit->m_iLidar_Baudrate));
	ui.comboBox_LaserMeasure_Port->setCurrentIndex(g_pGlobalUnit->m_iLaserMeasure_Port - 1);
	ui.comboBox_LaserMeasure_Baudrate->setCurrentText(QString::number(g_pGlobalUnit->m_iLaserMeasure_Baudrate));

	ui.comboBox_LiftPlatform_Port->setCurrentIndex(g_pGlobalUnit->m_iLiftPlat_PortNum - 1);
	ui.comboBox_LiftPlatform_Baudrate->setCurrentText(QString::number(g_pGlobalUnit->m_iLiftPlat_Baudrate));

	ui.toolButton_Communication_Ok->SetButtonIcon("Communication_Ok", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_Communication_Cancel->SetButtonIcon("Communication_Cancel", QSize(100, 50), TBT_Round_Rect);
	ui.toolButton_Communication_Reset->SetButtonIcon("Communication_Reset", QSize(100, 50), TBT_Round_Rect);

	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_Communication_Ok_pressed()), Qt::UniqueConnection);
}

QGTCommunicationSet::~QGTCommunicationSet()
{
	if (NULL != EnterKey)
	{
		delete EnterKey;
		EnterKey = NULL;
	}
}

void QGTCommunicationSet::mousePressEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = true;
		QPoint ptWindow_temp = this->pos(); //获取部件当前的位置
		QPoint ptMouse_temp = pEvent->globalPos(); //获取移动前鼠标的位置
		this->m_ptMoveBegin = ptMouse_temp - ptWindow_temp;
	}
}

void QGTCommunicationSet::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if (pEvent->button() == Qt::LeftButton)
	{
		this->m_bIsLeftMousePressed = false;
		this->m_ptMoveBegin = QPoint(0, 0);
	}
}

void QGTCommunicationSet::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (true == m_bIsLeftMousePressed)
	{
		move(pEvent->globalPos() - m_ptMoveBegin);
	}
}

void QGTCommunicationSet::on_toolButton_Communication_Ok_pressed()
{
	if ((false == ui.widget_Chasis_IpAddress->isValidIpAddr()) || (true == ui.lineEdit_Chasis_Port->text().isEmpty()) ||
		(false == ui.widget_Robot_IpAddress->isValidIpAddr()) || (true == ui.lineEdit_Robot_Port->text().isEmpty()) ||
		(false == ui.widget_Ros_IpAddress->isValidIpAddr()) || (true == ui.lineEdit_Ros_Port->text().isEmpty()))
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Invalid ip address, Please input valid ip address first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
		return;
	}

	g_pGlobalUnit->m_strChasis_IpAddr = ui.widget_Chasis_IpAddress->GetIpText();
	g_pGlobalUnit->m_strChasis_Port = ui.lineEdit_Chasis_Port->text();
	
	g_pGlobalUnit->m_strRobot_IpAddr = ui.widget_Robot_IpAddress->GetIpText();
	g_pGlobalUnit->m_strRobot_Port = ui.lineEdit_Robot_Port->text();

	g_pGlobalUnit->m_strRos_IpAddr = ui.widget_Ros_IpAddress->GetIpText();
	g_pGlobalUnit->m_strRos_Port = ui.lineEdit_Ros_Port->text();
	g_pGlobalUnit->m_strLidar_Port = ui.comboBox_Lidar_Port->currentText();
	g_pGlobalUnit->m_iLidar_Baudrate = ui.comboBox_Lidar_Baudrate->currentText().toInt();
	g_pGlobalUnit->m_iLaserMeasure_Port = ui.comboBox_LaserMeasure_Port->currentIndex() + 1;
	g_pGlobalUnit->m_iLaserMeasure_Baudrate = ui.comboBox_LaserMeasure_Baudrate->currentText().toInt();

	g_pGlobalUnit->m_iLiftPlat_PortNum = ui.comboBox_LiftPlatform_Port->currentIndex() + 1;
	g_pGlobalUnit->m_iLiftPlat_Baudrate = ui.comboBox_LiftPlatform_Baudrate->currentText().toInt();

	this->close();
}

void QGTCommunicationSet::on_toolButton_Communication_Cancel_pressed()
{
	this->close();
}

void QGTCommunicationSet::on_toolButton_Communication_Reset_pressed()
{
	ui.widget_Chasis_IpAddress->setIpText("192.168.0.7");
	ui.lineEdit_Chasis_Port->setText("23");
	
	ui.widget_Robot_IpAddress->setIpText("192.168.0.102");
	ui.lineEdit_Robot_Port->setText("30001");

	ui.widget_Ros_IpAddress->setIpText("192.168.0.105");
	ui.lineEdit_Ros_Port->setText("23");
	ui.comboBox_Lidar_Port->setCurrentIndex(5);
	ui.comboBox_Lidar_Baudrate->setCurrentIndex(5);
	ui.comboBox_LaserMeasure_Port->setCurrentIndex(5);
	ui.comboBox_LaserMeasure_Baudrate->setCurrentIndex(5);

	ui.comboBox_LiftPlatform_Port->setCurrentIndex(5);
	ui.comboBox_LiftPlatform_Baudrate->setCurrentIndex(5);
}

void QGTCommunicationSet::on_checkBox_IsSelect_Chasis_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_Chasis_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Chasis_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_Chasis_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_LiftPlat_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_LiftPlat_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_LiftPlat_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_LiftPlat_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_Robot_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_Robot_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Robot_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_Robot_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_Ros_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_Ros_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Ros_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_Ros_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_Lidar_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_Lidar_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_Lidar_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_Lidar_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_LaserMeasure_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_LaserMeasure_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_LaserMeasure_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_LaserMeasure_Connect = bIsCheck;
}

void QGTCommunicationSet::on_checkBox_IsSelect_JoyHandle_Connect_clicked(bool bIsCheck)
{
	if (g_pGlobalUnit->m_bIsConnect)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Warning"),
			"Can't select when system Connected, please disconnect first",
			QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

		ui.checkBox_IsSelect_JoyHandle_Connect->setChecked(g_pGlobalUnit->m_bIsSelect_JoyHandle_Connect);
		return;
	}
	g_pGlobalUnit->m_bIsSelect_JoyHandle_Connect = bIsCheck;
}
