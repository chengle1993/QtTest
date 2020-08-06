/********************************************************************************
** Form generated from reading UI file 'ModelViewTest.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELVIEWTEST_H
#define UI_MODELVIEWTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelViewTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelViewTestClass)
    {
        if (ModelViewTestClass->objectName().isEmpty())
            ModelViewTestClass->setObjectName(QStringLiteral("ModelViewTestClass"));
        ModelViewTestClass->resize(600, 400);
        menuBar = new QMenuBar(ModelViewTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ModelViewTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelViewTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ModelViewTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ModelViewTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ModelViewTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ModelViewTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ModelViewTestClass->setStatusBar(statusBar);

        retranslateUi(ModelViewTestClass);

        QMetaObject::connectSlotsByName(ModelViewTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *ModelViewTestClass)
    {
        ModelViewTestClass->setWindowTitle(QApplication::translate("ModelViewTestClass", "ModelViewTest", 0));
    } // retranslateUi

};

namespace Ui {
    class ModelViewTestClass: public Ui_ModelViewTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELVIEWTEST_H
