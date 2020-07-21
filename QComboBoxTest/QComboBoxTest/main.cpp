#include "QComboBoxTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QComboBoxTest w;
	w.show();
	return a.exec();
}
