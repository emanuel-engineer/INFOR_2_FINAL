/********************************************************************************
** Form generated from reading UI file 'nivel1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL1_H
#define UI_NIVEL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nivel1
{
public:

    void setupUi(QWidget *nivel1)
    {
        if (nivel1->objectName().isEmpty())
            nivel1->setObjectName("nivel1");
        nivel1->resize(400, 300);

        retranslateUi(nivel1);

        QMetaObject::connectSlotsByName(nivel1);
    } // setupUi

    void retranslateUi(QWidget *nivel1)
    {
        nivel1->setWindowTitle(QCoreApplication::translate("nivel1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nivel1: public Ui_nivel1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL1_H
