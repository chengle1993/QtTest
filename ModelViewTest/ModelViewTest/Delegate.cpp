#include "Delegate.h"
#include "QStyle"
#include <QApplication>
#include <QRect>
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QBrush>

Delegate::Delegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

Delegate::~Delegate()
{
}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (index.column() == 1 && index.row() % 2 == 0)
	{
		QString text = index.data(Qt::DisplayRole).toString();
		QStyle *style = option.widget ? option.widget->style() : QApplication::style();
		QRect rect(option.rect);
		rect.adjust(30, 0, 0, 0);
		style->drawItemText(painter, rect, Qt::AlignLeft | Qt::AlignVCenter, option.palette, true, index.data(Qt::DisplayRole).toString());
		QPixmap pixmap(":/icon/icon/icon_idc_quote.png");
		rect.setRect(option.rect.left(), rect.top()+5, 20, rect.width());
		style->drawItemPixmap(painter, rect, Qt::AlignLeft, pixmap);
		return;
	}
	QStyledItemDelegate::paint(painter, option, index);
}
