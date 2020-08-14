#include "TableModel.h"
#include <QVector>
#include <QVariant>
#include <QString>

TableModel::TableModel(QStringList headData_, QStringList data_, QObject *parent)
	: QAbstractItemModel(parent)
{
	QVector<QVariant> headData;
	for each (QString str in headData_)
	{
		headData << str;
	}
	rootItem = new TreeItem(headData);
	setModelData(data_);
}

TableModel::~TableModel()
{
}

void TableModel::setModelData(QStringList data_)
{
	for each (QString str in data_)
	{
		QStringList lineList = str.split(";", QString::KeepEmptyParts);
		QVector<QVariant> lineVec;
		for each (QString str in lineList)
		{
			lineVec << str;
		}
		TreeItem *item = new TreeItem(lineVec, rootItem);
		rootItem->insertChild(item);
	}
}

QModelIndex TableModel::index(int row, int column, const QModelIndex &parent) const
{
	TreeItem *item = rootItem->getChild(row);
	if (item)
	{
		if (column < item->getcolumns())
		{
			return createIndex(row, column, item);
		}
	}
	return QModelIndex();
}

QModelIndex TableModel::parent(const QModelIndex &child) const
{
	return QModelIndex();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
	return rootItem->getChildCount();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
	return rootItem->getcolumns();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
	if (index.isValid())
	{
		if (role == Qt::DisplayRole || role == Qt::EditRole)
		{
			return ((TreeItem*)index.internalPointer())->getData(index.column());
		}
	}
	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		if (section < rootItem->getcolumns())
			return rootItem->getData(section);
	}
	return QVariant();
}