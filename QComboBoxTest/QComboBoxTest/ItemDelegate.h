#pragma once

#include <QStyledItemDelegate>

class ItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT

signals :
	void showItemMessage(const QModelIndex &index);

public:
	ItemDelegate(QObject * parent = 0);
	~ItemDelegate(){}
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private slots :
	void showMessage(const QModelIndex &index);
};
