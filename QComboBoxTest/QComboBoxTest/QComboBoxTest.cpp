#include "qcomboboxtest.h"
#include <QComboBox>
#include <QIcon>
#include <QLineEdit>
#include "itemdelegate.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QLabel>

QComboBoxTest::QComboBoxTest(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(200, 180);
	//QIcon icon("C:/IDBProject/idb/idbbondapp/resources/images/classical_gray/icon_market.png");
	QIcon icon(":/icon_market.png");
	QComboBox *combo = new QComboBox(this);
	ItemDelegate *pDelegate = new ItemDelegate(this);
	combo->setItemDelegate(pDelegate);
	combo->setFixedSize(100, 20);
	combo->move(60, 40);
	
	combo->addItem(icon, QStringLiteral("全部"), -100);
	combo->addItem(QStringLiteral("一级"), 1);
	combo->addItem(QStringLiteral("二级"), 2);
}

QComboBoxTest::~QComboBoxTest()
{

}
