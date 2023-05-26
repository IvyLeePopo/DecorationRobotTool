#include "qgttilingposview.h"

QGTTilingPosView::QGTTilingPosView(QWidget *parent)
	: QTableWidget(parent)
{
	this->setColumnCount(6); //��������
	//���ñ�ͷ����
// 	QStringList header;
// 	header << tr("Step name") << tr("Step value") << tr("Step result");
// 	this->setHorizontalHeaderLabels(header);

	//���ñ�ͷ����Ӵ�
	QFont font = this->horizontalHeader()->font();
	font.setBold(true);
	this->horizontalHeader()->setFont(font);

	this->horizontalHeader()->setStretchLastSection(true); //���ó�������
	this->verticalHeader()->resizeSections(QHeaderView::Stretch);//������Ӧ���

	this->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭

	this->verticalHeader()->setDefaultSectionSize(30); //�����и�
	// 	this->setFrameShape(QFrame::NoFrame); //�����ޱ߿�
	// 	this->setShowGrid(false); //���ò���ʾ������
	this->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ
	this->horizontalHeader()->setFixedHeight(25); //���ñ�ͷ�ĸ߶�

	this->setStyleSheet("selection-background-color:lightblue;"); //����ѡ�б���ɫ

	this->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //���ñ�ͷ����ɫ

	this->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ

	this->setSelectionMode(QAbstractItemView::SingleSelection);  //����Ϊѡ�е���Ŀ��

	this->setFocus();
}

QGTTilingPosView::~QGTTilingPosView()
{

}

void QGTTilingPosView::Init_PosView(const QString strHead_1, const QString strHead_2, const QString strHead_3, const QString strHead_4, const QString strHead_5, const QString strHead_6)
{
	//���ñ�ͷ����
	QStringList header;
	header << strHead_1 << strHead_2 << strHead_3 << strHead_4 << strHead_5 << strHead_6;
	this->setHorizontalHeaderLabels(header);
}

void QGTTilingPosView::Display_SingleRow(const GT_RobotArm_Pose pose_Input)
{
	int row_count = this->rowCount(); //��ȡ������
	this->insertRow(row_count); //��������

	QTableWidgetItem *item1 = new QTableWidgetItem();
	QTableWidgetItem *item2 = new QTableWidgetItem();
	QTableWidgetItem *item3 = new QTableWidgetItem();
	QTableWidgetItem *item4 = new QTableWidgetItem();
	QTableWidgetItem *item5 = new QTableWidgetItem();
	QTableWidgetItem *item6 = new QTableWidgetItem();

	item1->setText(QString::number(pose_Input.dwX));
	item2->setText(QString::number(pose_Input.dwY));
	item3->setText(QString::number(pose_Input.dwZ));
	item4->setText(QString::number(pose_Input.dwU));
	item5->setText(QString::number(pose_Input.dwV));
	item6->setText(QString::number(pose_Input.dwW));

	item1->setTextAlignment(Qt::AlignCenter);
	item2->setTextAlignment(Qt::AlignCenter);
	item3->setTextAlignment(Qt::AlignCenter);
	item4->setTextAlignment(Qt::AlignCenter);
	item5->setTextAlignment(Qt::AlignCenter);
	item6->setTextAlignment(Qt::AlignCenter);

	this->setItem(row_count, 0, item1);
	this->setItem(row_count, 1, item2);
	this->setItem(row_count, 2, item3);
	this->setItem(row_count, 3, item4);
	this->setItem(row_count, 4, item5);
	this->setItem(row_count, 5, item6);
}

void QGTTilingPosView::Update_PosView(const GT_RobotArm_Pose pose_Input)
{
	Display_SingleRow(pose_Input);
}

void QGTTilingPosView::Clear_PosView()
{
	this->setRowCount(0);
	this->clearContents();
}
