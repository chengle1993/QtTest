#pragma once

#include <QAbstractItemModel>
#include <QStringList>

class TreeItem;

class TreeModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	TreeModel(QStringList headerData_, QStringList stringList, QObject *parent = 0);
	~TreeModel();
	QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &child) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const ;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
private:
	void setModelData(TreeItem *rootItem, QStringList stringList);
private:
	TreeItem *rootItem;
};
