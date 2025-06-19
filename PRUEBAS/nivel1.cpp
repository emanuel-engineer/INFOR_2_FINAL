#include "nivel1.h"
#include "ui_nivel1.h"

nivel1::nivel1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nivel1)
{
    ui->setupUi(this);
}

nivel1::~nivel1()
{
    delete ui;
}
