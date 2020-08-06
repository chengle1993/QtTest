#include "TreeView.h"
#include <QTreeView>
#include <QVBoxLayout>
#include "TreeModel.h"
#include <QFile>
#include <QTextStream>

TreeView::TreeView(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	QTreeView *treeView = new QTreeView(this);
	treeView->setFixedSize(QSize(800, 600));
	layout->addWidget(treeView);
	this->setLayout(layout);

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

	TreeModel *treeModel = new TreeModel(headData, stringList);
	treeView->setModel(treeModel);
}

TreeView::~TreeView()
{
}
