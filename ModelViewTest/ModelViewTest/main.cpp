#include "TreeView.h"
#include "TableView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//TreeView treeView;
	//treeView.show();

	TableView tableView;
	tableView.show();

	return a.exec();
}
