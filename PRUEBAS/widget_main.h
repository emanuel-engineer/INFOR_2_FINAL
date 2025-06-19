#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include <QWidget>
#include <nivel1.h>
#include <nivel2.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class widget_main;
}
QT_END_NAMESPACE

class widget_main : public QWidget
{
    Q_OBJECT

public:
    widget_main(QWidget *parent = nullptr);
    ~widget_main();

private slots:
    void on_nivel1_clicked();

    void on_nivel2_clicked();

    void on_cerrar_clicked();

private:
    Ui::widget_main *ui;
};
#endif // WIDGET_MAIN_H
