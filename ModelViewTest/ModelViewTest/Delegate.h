#pragma once

#include <QObject>
#include <QStyledItemDelegate>

class Delegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	Delegate(QObject *parent = 0);
	~Delegate();
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
