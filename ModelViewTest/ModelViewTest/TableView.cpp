#include "TableView.h"
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
#include <QTableView>
#include "TableModel.h"
#include <QPalette>
#include "Delegate.h"
#include <QModelIndex>
#include <QMessageBox>
#include <QDebug>

TableView::TableView(QWidget *p)
	:QWidget(p)
{
	QTableView *tableView = new QTableView(this);
	tableView->setAlternatingRowColors(true);
	QPalette palette;
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置整行选中

	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(tableView);
	this->setLayout(layout);
	this->setMinimumSize(QSize(800, 600));

	//读取文件中的数据
	QStringList stringList, headData;
	QFile file(":/bond_bank.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		stringList << line.toLocal8Bit();
	}
	headData = stringList.at(0).split(";", QString::KeepEmptyParts);
	stringList.removeAt(0);

	//加载数据到Model
	TableModel *tableModel = new TableModel(headData, stringList);
	tableView->setModel(tableModel);

	//设置自定义的Delegate
	Delegate *delegate = new Delegate();
	tableView->setItemDelegate(delegate);

	//利用qss设置样式
	QFile file2(":/qss/qss/style1.qss");
	file2.open(QFile::ReadOnly);
	QString styleSheet = tr(file2.readAll());
	this->setStyleSheet(styleSheet);
	file2.close();


	connect(tableView, &QTableView::doubleClicked, [=](QModelIndex index){
		QString str = index.data(index.column()).toString();
		qDebug() << "column:" << str << "  row num:" << index.row() << "  column num:" << index.column();
		QMessageBox::information(0, "QTableView Column", str);
	});
}

TableView::~TableView()
{
}
