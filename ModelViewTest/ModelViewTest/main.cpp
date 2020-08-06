#include "TreeView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	TreeView view;
	view.show();

	return a.exec();
}
