/********************************************************************************
** Form generated from reading UI file 'PersonalizedButton.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALIZEDBUTTON_H
#define UI_PERSONALIZEDBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalizedButtonClass
{
public:

    void setupUi(QWidget *PersonalizedButtonClass)
    {
        if (PersonalizedButtonClass->objectName().isEmpty())
            PersonalizedButtonClass->setObjectName(QStringLiteral("PersonalizedButtonClass"));
        PersonalizedButtonClass->resize(600, 400);

        retranslateUi(PersonalizedButtonClass);

        QMetaObject::connectSlotsByName(PersonalizedButtonClass);
    } // setupUi

    void retranslateUi(QWidget *PersonalizedButtonClass)
    {
        PersonalizedButtonClass->setWindowTitle(QApplication::translate("PersonalizedButtonClass", "PersonalizedButton", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonalizedButtonClass: public Ui_PersonalizedButtonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALIZEDBUTTON_H
