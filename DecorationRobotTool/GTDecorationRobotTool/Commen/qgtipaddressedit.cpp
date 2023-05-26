#include "qgtipaddressedit.h"

QGTIpAddressEdit::QGTIpAddressEdit(QWidget *parent)
	: QWidget(parent)
{
	QFont font_temp;
	font_temp.setPointSize(12);
	font_temp.setFamily("simsun");
	font_temp.setBold(true);

	pEdit_Part1_ = new QGTIpPartLineEdit(this);
	pEdit_Part2_ = new QGTIpPartLineEdit(this);
	pEdit_Part3_ = new QGTIpPartLineEdit(this);
	pEdit_Part4_ = new QGTIpPartLineEdit(this);

	pLabel_Part1_ = new QLabel(this);
	pLabel_Part2_ = new QLabel(this);
	pLabel_Part3_ = new QLabel(this);

	pEdit_Part1_->setFont(font_temp);
	pEdit_Part2_->setFont(font_temp);
	pEdit_Part3_->setFont(font_temp);
	pEdit_Part4_->setFont(font_temp);

	pEdit_Part1_->setGeometry(QRect(0, 0, 50, 30));
	pEdit_Part2_->setGeometry(QRect(50, 0, 50, 30));
	pEdit_Part3_->setGeometry(QRect(100, 0, 50, 30));
	pEdit_Part4_->setGeometry(QRect(150, 0, 50, 30));

	pLabel_Part1_->setFont(font_temp);
	pLabel_Part1_->setText(" .");
	pLabel_Part1_->setGeometry(QRect(47, 6, 6, 28));
	pLabel_Part1_->setAlignment(Qt::AlignCenter);

	pLabel_Part2_->setFont(font_temp);
	pLabel_Part2_->setText(" .");
	pLabel_Part2_->setGeometry(QRect(97, 6, 6, 28));
	pLabel_Part2_->setAlignment(Qt::AlignCenter);

	pLabel_Part3_->setFont(font_temp);
	pLabel_Part3_->setText(" .");
	pLabel_Part3_->setGeometry(QRect(147, 6, 6, 28));
	pLabel_Part3_->setAlignment(Qt::AlignCenter);

	setTabOrder(pEdit_Part1_, pEdit_Part2_);
	setTabOrder(pEdit_Part2_, pEdit_Part3_);
	setTabOrder(pEdit_Part3_, pEdit_Part4_);
	pEdit_Part1_->setNextPartEdit(pEdit_Part2_);
	pEdit_Part2_->setNextPartEdit(pEdit_Part3_);
	pEdit_Part3_->setNextPartEdit(pEdit_Part4_);

	connect(pEdit_Part1_, SIGNAL(changetext(QString)), this, SLOT(textchanged(QString)));
	connect(pEdit_Part2_, SIGNAL(changetext(QString)), this, SLOT(textchanged(QString)));
	connect(pEdit_Part3_, SIGNAL(changetext(QString)), this, SLOT(textchanged(QString)));
	connect(pEdit_Part4_, SIGNAL(changetext(QString)), this, SLOT(textchanged(QString)));

	connect(pEdit_Part1_, SIGNAL(edittext(QString)), this, SLOT(textedited(QString)));
	connect(pEdit_Part2_, SIGNAL(edittext(QString)), this, SLOT(textedited(QString)));
	connect(pEdit_Part3_, SIGNAL(edittext(QString)), this, SLOT(textedited(QString)));
	connect(pEdit_Part4_, SIGNAL(edittext(QString)), this, SLOT(textedited(QString)));
}

QGTIpAddressEdit::~QGTIpAddressEdit()
{

}

void QGTIpAddressEdit::textchanged(const QString strText)
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = pEdit_Part1_->text();
	ippart2 = pEdit_Part2_->text();
	ippart3 = pEdit_Part3_->text();
	ippart4 = pEdit_Part4_->text();

	QString ipaddr = QString("%1.%2.%3.%4")
		.arg(ippart1)
		.arg(ippart2)
		.arg(ippart3)
		.arg(ippart4);

	emit changetext(ipaddr);
}

void QGTIpAddressEdit::textedited(const QString strText)
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = pEdit_Part1_->text();
	ippart2 = pEdit_Part2_->text();
	ippart3 = pEdit_Part3_->text();
	ippart4 = pEdit_Part4_->text();

	QString ipaddr = QString("%1.%2.%3.%4")
		.arg(ippart1)
		.arg(ippart2)
		.arg(ippart3)
		.arg(ippart4);

	emit edittext(ipaddr);
}

void QGTIpAddressEdit::setIpText(const QString strText)
{
	QString ippart1, ippart2, ippart3, ippart4;
	QString qstring_validate = strText;

	// IP地址验证
	QRegExp regexp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
	QRegExpValidator regexp_validator(regexp, this);
	int nPos = 0;
	QValidator::State state = regexp_validator.validate(qstring_validate, nPos);
	// IP合法
	if (state == QValidator::Acceptable)
	{
		QStringList ippartlist = strText.split(".");

		int strcount = ippartlist.size();
		int index = 0;
		if (index < strcount)
		{
			ippart1 = ippartlist.at(index);
		}
		if (++index < strcount)
		{
			ippart2 = ippartlist.at(index);
		}
		if (++index < strcount)
		{
			ippart3 = ippartlist.at(index);
		}
		if (++index < strcount)
		{
			ippart4 = ippartlist.at(index);
		}
	}

	pEdit_Part1_->setText(ippart1);
	pEdit_Part2_->setText(ippart2);
	pEdit_Part3_->setText(ippart3);
	pEdit_Part4_->setText(ippart4);
}

bool QGTIpAddressEdit::isValidIpAddr()
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = pEdit_Part1_->text();
	ippart2 = pEdit_Part2_->text();
	ippart3 = pEdit_Part3_->text();
	ippart4 = pEdit_Part4_->text();
	if ((false == ippart1.isEmpty()) && (false == ippart2.isEmpty()) &&
		(false == ippart3.isEmpty()) && (false == ippart4.isEmpty()))
	{
		return true;
	}
	return false;
}

QString QGTIpAddressEdit::GetIpText()
{
	QString ippart1, ippart2, ippart3, ippart4;
	ippart1 = pEdit_Part1_->text();
	ippart2 = pEdit_Part2_->text();
	ippart3 = pEdit_Part3_->text();
	ippart4 = pEdit_Part4_->text();

	QString ipaddr = QString("%1.%2.%3.%4")
		.arg(ippart1)
		.arg(ippart2)
		.arg(ippart3)
		.arg(ippart4);

	return ipaddr;
}

void QGTIpAddressEdit::setStyleSheet(const QString strStyleSheet)
{
	pEdit_Part1_->setStyleSheet(strStyleSheet);
	pEdit_Part2_->setStyleSheet(strStyleSheet);
	pEdit_Part3_->setStyleSheet(strStyleSheet);
	pEdit_Part4_->setStyleSheet(strStyleSheet);
}
