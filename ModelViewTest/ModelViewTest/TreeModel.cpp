#include "TreeModel.h"
#include "TreeItem.h"
#include <QModelIndex>
#include <QDebug>

TreeModel::TreeModel(QStringList headerData_, QStringList stringList, QObject *parent)
	: QAbstractItemModel(parent)
{
	QVector<QVariant> headerData;
	for each (QString str in headerData_)
	{
		headerData << str;
	}
	rootItem = new TreeItem(headerData);
	setModelData(rootItem, stringList);
}

TreeModel::~TreeModel()
{
	delete rootItem;
}

//读取树形结构的数据
void TreeModel::setModelData(TreeItem *rootItem, QStringList stringList)
{
	QVector<int> indentations;
	indentations << 0;
	QVector<TreeItem *> parents;
	parents << rootItem;
	TreeItem *treeItem;
	for each (QString line in stringList)
	{
		if (line.isEmpty())
		{
			continue;
		}
		int pos = 0;
		while (pos < line.length())
		{
			if (line.mid(pos, 1) != " ")
			{
				break;
			}
			++pos;
		}
		if (pos > indentations.last())
		{
			indentations << pos;
			if (treeItem)
			{
				parents << treeItem;
			}
		}
		while (pos < indentations.last())
		{
			indentations.pop_back();
			parents.pop_back();
		}

		QStringList lineData = line.trimmed().split("\t", QString::SkipEmptyParts);
		QVector<QVariant> itemData;
		for each (QString str in lineData)
		{
			itemData << str;
		}
		treeItem = new TreeItem(itemData, parents.last());
		parents.last()->insertChild(treeItem);
	}
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
	TreeItem *treeItem = parent.isValid() ? static_cast<TreeItem*>(parent.internalPointer()) : rootItem;
	if (treeItem)
	{
		if (treeItem->getChild(row))
		{
			return createIndex(row, column, treeItem->getChild(row));
		}
	}
	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &child) const
{
	if (child.isValid())
	{
		TreeItem *childItem = child.isValid() ? static_cast<TreeItem*>(child.internalPointer()): rootItem;
		TreeItem *parentItem = childItem->getParent();
		if (childItem && parentItem)
		{
			int row = parentItem->getIndex(parentItem);
			if (row >= 0)
			{
				return createIndex(row, 0, parentItem);
			}
		}
	}
	return QModelIndex();
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
	TreeItem *parentItem = parent.isValid() ? static_cast<TreeItem*>(parent.internalPointer()) : rootItem;
	if (parentItem)
	{
		qDebug() << "rowcount" << parentItem->getChildCount();
		return parentItem->getChildCount();
	}
	return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
	if (rootItem)
	{
		qDebug() << "colcount" << rootItem->getcolumns();
		return rootItem->getcolumns();
	}
	return 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
	if (index.isValid())
	{
		TreeItem *treeItem = index.isValid() ? static_cast<TreeItem*>(index.internalPointer()) : rootItem;
		if (role == Qt::DisplayRole || role == Qt::EditRole)
		{
			if (treeItem)
			{
				return treeItem->getData(index.column());
			}
		}
	}
	return QVariant();
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return rootItem->getData(section);
	}
	return QVariant();
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
	if (index.isValid()) {
		TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
		if (item)
			return item;
	}
	return rootItem;
}