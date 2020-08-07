#include "TreeView.h"
#include <QTreeView>
#include <QVBoxLayout>
#include "TreeModel.h"
#include <QFile>
#include <QTextStream>
#include <QSortFilterProxyModel>

TreeView::TreeView(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	QTreeView *treeView = new QTreeView(this);
	treeView->setFixedSize(QSize(800, 600));
	treeView->setAlternatingRowColors(true);
	
	layout->addWidget(treeView);
	this->setLayout(layout);

	//读取文件中的数据
	QStringList stringList, headData;
	headData << "title" << "description";
	QFile file(":/default.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		stringList << line;
	}

	//为视图设置model
	TreeModel *treeModel = new TreeModel(headData, stringList);
	QSortFilterProxyModel *sortModel = new QSortFilterProxyModel();
	sortModel->setSourceModel(treeModel);
	treeView->setModel(sortModel);

	//利用qss设置样式
	QFile file2(":/qss/qss/style1.qss");
	file2.open(QFile::ReadOnly);
	QString styleSheet = tr(file2.readAll());
	this->setStyleSheet(styleSheet);
	file2.close();
}

TreeView::~TreeView()
{
}
