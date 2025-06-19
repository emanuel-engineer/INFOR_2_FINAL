#include "widget_main.h"
#include "ui_widget_main.h"

widget_main::widget_main(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_main)
{
    ui->setupUi(this);
}

widget_main::~widget_main()
{
    delete ui;
}

void widget_main::on_nivel1_clicked()
{
    nivel1 *w = new nivel1;
    close();
    w->show();
}


void widget_main::on_nivel2_clicked()
{
    nivel2 *w = new nivel2;
    close();
    w->show();
}


void widget_main::on_cerrar_clicked()
{
    close();
}

