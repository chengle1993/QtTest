#include "itemdelegate.h"
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <iostream>
#include <QApplication>
#include <QToolTip>
using namespace std;

ItemDelegate::ItemDelegate(QObject * parent)
	: QStyledItemDelegate(parent)
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItem  viewOption(option);
	if (viewOption.state & QStyle::State_HasFocus)
	{
		viewOption.state = viewOption.state ^ QStyle::State_HasFocus;
	}

	QStyledItemDelegate::paint(painter, viewOption, index);

	int height = (viewOption.rect.height() - 9) / 2;
	QPixmap pixmap = QPixmap("C:/IDBProject/idb/idbbondapp/resources/images/classical_gray/icon_market.png");
	QRect decorationRect = QRect(viewOption.rect.left() + viewOption.rect.width() - 30, viewOption.rect.top() + height, 9, 9);
	QString str = index.data(Qt::DisplayRole).toString();
	if (index.data(Qt::DisplayRole) == QStringLiteral("二级"))
	{
		painter->drawPixmap(decorationRect, pixmap);
	}
}

bool ItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
	int height = (option.rect.height() - 9) / 2;
	QRect decorationRect = QRect(option.rect.left() + option.rect.width() - 30, option.rect.top() + height, 9, 9);

	QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
	if (event->type() == QEvent::MouseButtonPress && decorationRect.contains(mouseEvent->pos()))
	{
		emit deleteItem(index);
	}

	if (event->type() == QEvent::MouseMove && decorationRect.contains(mouseEvent->pos()))
	{
		QCursor cursor(Qt::PointingHandCursor);
		QApplication::setOverrideCursor(cursor);
		QString strText = QStringLiteral("删除账号信息");
		QToolTip::showText(mouseEvent->globalPos(), strText);
	}
	else
	{
		QCursor cursor(Qt::ArrowCursor);
		QApplication::setOverrideCursor(cursor);
	}

	return QStyledItemDelegate::editorEvent(event, model, option, index);
}
