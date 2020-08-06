#pragma once
#include <QList>
#include <QVector>
#include <QVariant>
#include <QSharedPointer>

class TreeItem
{
public:
	TreeItem(QVector<QVariant> data_, TreeItem *parent_ = 0);
	~TreeItem();
	int getChildCount();
	TreeItem* getParent();
	TreeItem* getChild(int index);
	void insertChild(TreeItem* child);
	void insertChild(int index, TreeItem* child);
	QVariant getData(int col);
	int getIndex(TreeItem *child);
	int getcolumns();
private:
	QVector<QVariant> data;
	QList<TreeItem*> children;
	TreeItem *parent;
};
