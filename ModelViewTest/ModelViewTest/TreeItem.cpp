#include "TreeItem.h"

TreeItem::TreeItem(QVector<QVariant> data_, TreeItem *parent_ )
{
	data = data_;
	parent = parent_;
}

TreeItem::~TreeItem()
{
}

int TreeItem::getChildCount()
{
	return children.count();
}

TreeItem* TreeItem::getParent()
{
	return parent;
}

TreeItem* TreeItem::getChild(int index)
{
	if (index < children.size())
	{
		return children.at(index);
	}
	return NULL;
}

void TreeItem::insertChild(TreeItem* child)
{
	children.append(child);
}

void TreeItem::insertChild(int index, TreeItem* child)
{
	children.insert(index, child);
}

QVariant TreeItem::getData(int col)
{
	if (col < data.size())
	{
		return data.at(col);
	}
	return QVariant();
}

int TreeItem::getIndex(TreeItem *child_)
{
	TreeItem *parent;
	if (child_)
	{
		parent = child_->getParent() ? child_->getParent() : 0;
	}
	int index = -1;
	if (parent)
	{
		for each (TreeItem* child in parent->children)
		{
			if (child == child_)
			{
				++index;
			}
		}
		if (index >= 0 && index < children.size())
		{
			return index;
		}
	}
	return -1;
}

int TreeItem::getcolumns()
{
	return data.size();
}