/********************************************************************************
** Form generated from reading UI file 'QComboBoxTest.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCOMBOBOXTEST_H
#define UI_QCOMBOBOXTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QComboBoxTestClass
{
public:

    void setupUi(QWidget *QComboBoxTestClass)
    {
        if (QComboBoxTestClass->objectName().isEmpty())
            QComboBoxTestClass->setObjectName(QStringLiteral("QComboBoxTestClass"));
        QComboBoxTestClass->resize(600, 400);

        retranslateUi(QComboBoxTestClass);

        QMetaObject::connectSlotsByName(QComboBoxTestClass);
    } // setupUi

    void retranslateUi(QWidget *QComboBoxTestClass)
    {
        QComboBoxTestClass->setWindowTitle(QApplication::translate("QComboBoxTestClass", "QComboBoxTest", 0));
    } // retranslateUi

};

namespace Ui {
    class QComboBoxTestClass: public Ui_QComboBoxTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCOMBOBOXTEST_H
