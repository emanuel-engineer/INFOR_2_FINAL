#ifndef NIVEL1_H
#define NIVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include <QLabel>


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


private slots:

    /*  REACTIVAR CUANDO SE TENGA TODO LO DEMAS LISTO (AGREGAR LABELS A nivel1.ui
    void mostrarMensajeGameover();
    */
    //void mostrarMensajeInteraccion();

private:
    Ui::nivel1 *ui;

    void animacion_inicioNVL();

    // Declarar el puntero a las escenas (Sprite roshi, piedra)
    QGraphicsScene *escena;
    //QGraphicsScene *escenaPiedra;

    //atributos y puntero ROSHI
    void configurarGraphicsView();
    void mostrarRoshi();
    QGraphicsPixmapItem *roshiItem;
    int posXroshi = 0;
    const int velocidad = 5;
    //Atributos y puntero Piedra
    void mostrarPiedra();
    int posYpiedra = 40;
    int posXpiedra = 100;
    QGraphicsPixmapItem *piedraItem;

    //Interaccion entre piedra y roshi
    QLabel *mensaje1label; //Mensaje que muestra si la interaccion entre roshi y piedra, termina el nivel.
    bool interaccionPiedra = false ;
    bool terminarNivel = false ;
    void verificarInteraccion();


};

#endif // NIVEL1_H
