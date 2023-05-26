#include "qgtippartlineedit.h"

QGTIpPartLineEdit::QGTIpPartLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	m_pNextTab = NULL;

	this->setMaxLength(3);
	this->setFrame(false);
	this->setAlignment(Qt::AlignCenter);

	QValidator *validator = new QIntValidator(0, 255, this);
	this->setValidator(validator);

	connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(text_edited(const QString&)));
}

QGTIpPartLineEdit::~QGTIpPartLineEdit()
{

}

void QGTIpPartLineEdit::focusInEvent(QFocusEvent *event)
{
	this->selectAll();
	QLineEdit::focusInEvent(event);
}

void QGTIpPartLineEdit::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Period)
	{
		if (NULL != m_pNextTab)
		{
			m_pNextTab->setFocus();
			m_pNextTab->selectAll();
		}
	}
	QLineEdit::keyPressEvent(event);
}

void QGTIpPartLineEdit::text_edited(const QString strText)
{
	QIntValidator v(0, 255, this);
	QString ipaddr = strText;
	int pos = 0;
	QValidator::State state = v.validate(ipaddr, pos);
	if (state == QValidator::Acceptable)
	{
		if (ipaddr.size() > 1)
		{
			if (ipaddr.size() == 2)
			{
				int ipnum = ipaddr.toInt();

				if (ipnum > 25)
				{
					if (NULL != m_pNextTab)
					{
						m_pNextTab->setFocus();
						m_pNextTab->selectAll();
					}
				}
			}
			else
			{
				if (NULL != m_pNextTab)
				{
					m_pNextTab->setFocus();
					m_pNextTab->selectAll();
				}
			}
		}
	}
}
