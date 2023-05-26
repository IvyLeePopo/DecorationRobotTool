#include "qgtloginpage.h"

QGTLoginPage::QGTLoginPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);
	this->setAttribute(Qt::WA_DeleteOnClose, true); //设置当关闭时销毁窗口，通常默认关闭只隐藏窗口
	this->setAttribute(Qt::WA_StyledBackground, true);

	ui.toolButton_Login_Ok->SetButtonIcon("Btn_Login_Ok", QSize(200, 50), TBT_Round_Rect);
	ui.toolButton_Login_Cancel->SetButtonIcon("Btn_Exit", QSize(40, 40), TBT_Normal_Rect);

	QString strBtn_LoginOk = "";
	if (g_pGlobalUnit->m_nLoginState == LS_Nobody)
	{
		ui.stackedWidget->setCurrentIndex(0);
		ui.comboBox_Login_Username->addItem("Developer", 0);
		ui.comboBox_Login_Username->addItem("Customer", 1);
		ui.comboBox_Login_Username->setCurrentIndex(0);
		strBtn_LoginOk = QString::fromLocal8Bit("安全登录");
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(1);
		if (g_pGlobalUnit->m_nLoginState == LS_Developer)
		{
			ui.label_UserName->setText("Developer");
		}
		else if (g_pGlobalUnit->m_nLoginState == LS_Customer)
		{
			ui.label_UserName->setText("Customer");
		}
		strBtn_LoginOk = QString::fromLocal8Bit("退出登录");
	}
	ui.toolButton_Login_Ok->setText(strBtn_LoginOk);


	EnterKey = new QShortcut(QKeySequence(Qt::Key_Enter), this);
	connect(EnterKey, SIGNAL(activated()), this, SLOT(on_toolButton_Login_Ok_pressed()), Qt::UniqueConnection);
}

QGTLoginPage::~QGTLoginPage()
{

}

bool QGTLoginPage::IsValidPassword()
{
	QString strPassword = ui.lineEdit_Login_Password->text();
	if (ui.comboBox_Login_Username->currentIndex() == 0)
	{
		if (0 == strPassword.compare("1"))
		{
			g_pGlobalUnit->m_nLoginState = LS_Developer;
			return true;
		}
	}
	else if (ui.comboBox_Login_Username->currentIndex() == 1)
	{
		if (0 == strPassword.compare("GR123456"))
		{
			g_pGlobalUnit->m_nLoginState = LS_Customer;
			return true;
		}
	}
	g_pGlobalUnit->m_nLoginState = LS_Nobody;
	return false;
}

void QGTLoginPage::on_toolButton_Login_Ok_pressed()
{
	if (g_pGlobalUnit->m_nLoginState == LS_Nobody)
	{
		if (g_pGlobalUnit->m_bIsConnect)
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, tr("Warning"),
				"Can't login when system Connected, please disconnect first",
				QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
			return;
		}

		if (false == IsValidPassword())
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, tr("Warning"),
				"Input password error, Please try again",
				QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);

			ui.lineEdit_Login_Password->setText("");
			return;
		}
	}
	else
	{
		if (g_pGlobalUnit->m_bIsConnect)
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, tr("Warning"),
				"Can't login when system Connected, please disconnect first",
				QMessageBox::NoButton | QMessageBox::Ok | QMessageBox::NoButton);
			return;
		}

		g_pGlobalUnit->m_nLoginState = LS_Nobody;
	}
	emit Update_Login_State();
	this->close();
}

void QGTLoginPage::on_toolButton_Login_Cancel_pressed()
{
	emit Update_Login_State();
	this->close();
}
