#include <QtWidgets/QApplication>
#include "mypushbutton.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget *widget = new QWidget(0);
	QHBoxLayout *layout = new QHBoxLayout(widget);
	QLabel *label = new QLabel(widget);
	QPixmap pixMap(":/radio1.png");
	label->setPixmap(pixMap);
	//layout ->addWidget(label);
	MyPushButton *btn = new MyPushButton(widget);
	layout->addWidget(btn);
	widget->setLayout(layout);
	widget->setFixedSize(QSize(800, 600));
	widget->show();

	return a.exec();
}
