#ifndef QGTIPADDRESSEDIT_H
#define QGTIPADDRESSEDIT_H

#include <QWidget>
#include <QRegExpValidator>
#include <QFont>
#include <QLabel>
#include <QLine>
#include "qgtippartlineedit.h"

class QGTIpAddressEdit : public QWidget
{
	Q_OBJECT

public:
	QGTIpAddressEdit(QWidget *parent);
	~QGTIpAddressEdit();

public:
	void setIpText(const QString strText);
	void setStyleSheet(const QString strStyleSheet);
	bool isValidIpAddr();
	QString GetIpText();

signals:
	void changetext(const QString strText);
	void edittext(const QString strText);

	private slots:
	void textchanged(const QString strText);
	void textedited(const QString strText);
private:
	QGTIpPartLineEdit *pEdit_Part1_;
	QGTIpPartLineEdit *pEdit_Part2_;
	QGTIpPartLineEdit *pEdit_Part3_;
	QGTIpPartLineEdit *pEdit_Part4_;

	QLabel *pLabel_Part1_;
	QLabel *pLabel_Part2_;
	QLabel *pLabel_Part3_;
};

#endif // QGTIPADDRESSEDIT_H
