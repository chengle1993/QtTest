/********************************************************************************
** Form generated from reading UI file 'TreeView.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEVIEW_H
#define UI_TREEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeView
{
public:

    void setupUi(QWidget *TreeView)
    {
        if (TreeView->objectName().isEmpty())
            TreeView->setObjectName(QStringLiteral("TreeView"));
        TreeView->resize(400, 300);

        retranslateUi(TreeView);

        QMetaObject::connectSlotsByName(TreeView);
    } // setupUi

    void retranslateUi(QWidget *TreeView)
    {
        TreeView->setWindowTitle(QApplication::translate("TreeView", "TreeView", 0));
    } // retranslateUi

};

namespace Ui {
    class TreeView: public Ui_TreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEVIEW_H
