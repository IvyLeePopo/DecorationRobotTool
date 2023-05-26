#ifndef QGTIPPARTLINEEDIT_H
#define QGTIPPARTLINEEDIT_H

#include <QLineEdit>
#include <QIntValidator>
#include <QKeyEvent>

class QGTIpPartLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	QGTIpPartLineEdit(QWidget *parent);
	~QGTIpPartLineEdit();

public:
	void setNextPartEdit(QLineEdit *pNextTab){ m_pNextTab = pNextTab; };
protected:
	virtual void focusInEvent(QFocusEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);

	private slots:
	void text_edited(const QString strText);
private:
	QLineEdit *m_pNextTab;
};

#endif // QGTIPPARTLINEEDIT_H
