#include "nivel2.h"
#include "ui_nivel2.h"

nivel2::nivel2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nivel2)
{
    ui->setupUi(this);



}

nivel2::~nivel2()
{    
    delete ui;
}
