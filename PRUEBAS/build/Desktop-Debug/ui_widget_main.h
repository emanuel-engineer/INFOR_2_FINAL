/********************************************************************************
** Form generated from reading UI file 'widget_main.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MAIN_H
#define UI_WIDGET_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_main
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *nivel1;
    QPushButton *nivel2;
    QPushButton *cerrar;
    QPushButton *iniciarjuego;

    void setupUi(QWidget *widget_main)
    {
        if (widget_main->objectName().isEmpty())
            widget_main->setObjectName("widget_main");
        widget_main->resize(405, 282);
        verticalLayoutWidget = new QWidget(widget_main);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(230, 170, 160, 95));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nivel1 = new QPushButton(verticalLayoutWidget);
        nivel1->setObjectName("nivel1");

        verticalLayout->addWidget(nivel1);

        nivel2 = new QPushButton(verticalLayoutWidget);
        nivel2->setObjectName("nivel2");

        verticalLayout->addWidget(nivel2);

        cerrar = new QPushButton(verticalLayoutWidget);
        cerrar->setObjectName("cerrar");

        verticalLayout->addWidget(cerrar);

        iniciarjuego = new QPushButton(widget_main);
        iniciarjuego->setObjectName("iniciarjuego");
        iniciarjuego->setGeometry(QRect(230, 50, 161, 51));

        retranslateUi(widget_main);

        QMetaObject::connectSlotsByName(widget_main);
    } // setupUi

    void retranslateUi(QWidget *widget_main)
    {
        widget_main->setWindowTitle(QCoreApplication::translate("widget_main", "widget_main", nullptr));
        nivel1->setText(QCoreApplication::translate("widget_main", "NIVEL 1", nullptr));
        nivel2->setText(QCoreApplication::translate("widget_main", "NIVEL 2", nullptr));
        cerrar->setText(QCoreApplication::translate("widget_main", "cerrar", nullptr));
        iniciarjuego->setText(QCoreApplication::translate("widget_main", "INICIAR JUEGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_main: public Ui_widget_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MAIN_H
