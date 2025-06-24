#ifndef NIVEL1_H
#define NIVEL1_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class nivel1;
}

class nivel1 : public QWidget
{
    Q_OBJECT

public:
    explicit nivel1(QWidget *parent = nullptr);
    ~nivel1();


protected:
    void keyPressEvent(QKeyEvent *event) override;





private:
    Ui::nivel1 *ui;

    QGraphicsScene *escena;  // Declarar el puntero a la escena
    void configurarGraphicsView();
    void mostrarRoshi();
    QGraphicsPixmapItem *roshiItem;
    int posXroshi = 0;
    const int velocidad = 5;

};

#endif // NIVEL1_H
