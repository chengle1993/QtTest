#pragma once

#include <QAbstractItemModel>
#include <QStringList>
#include "TreeItem.h"

class TableModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	TableModel(QStringList headData_, QStringList data_, QObject *parent = 0);
	~TableModel();
	virtual QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const;
	virtual QModelIndex parent(const QModelIndex &child) const;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	void setModelData(QStringList data_);
private:
	TreeItem *rootItem;
};
