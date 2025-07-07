#include "nivel1.h"
#include "ui_nivel1.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

nivel1::nivel1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nivel1)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    /*
    escenaPiedra = new QGraphicsScene(this);
    ui->piedra->setScene(escenaPiedra);
*/
    configurarGraphicsView();
    mostrarRoshi();
    setFocus();
    setFocusPolicy(Qt::StrongFocus); //Eventos del teclado
    //QDebug() << "Item creado:" << roshiItem;
    mostrarPiedra();
}

nivel1::~nivel1()
{
    //INNECESARIO
    //QGraphicsScene *scene = new QGraphicsScene (this);
    //ui->graphicsView->setScene(scene);

    delete ui;
    delete escena;
   // delete escenaPiedra;
}

void nivel1::mostrarRoshi(){
    //escena->clear();
    QPixmap imagen(":/new/sprites/parado.png");

    if (imagen.isNull()){
        qDebug()<<"Error al cargar el sprite de roshi";
        return;
    }
    /*IMAGEN ESCALADA
    QPixmap imagenEscalada = imagen.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    escena->addPixmap(imagenEscalada);*/

    /// IMAGEN SIN ESCALAR ::
    //ui->graphicsView->fitInView(escena->itemsBoundingRect(), Qt::KeepAspectRatio);
    roshiItem = escena->addPixmap(imagen);
    roshiItem -> setPos(posXroshi, 0);
    roshiItem->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
};


void nivel1::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Left:
        posXroshi -= velocidad;
        break;
    case Qt::Key_Right:
        posXroshi += velocidad;
        break;
    case Qt::Key_Space:
        verificarInteraccion();
        return;
    default:
        QWidget::keyPressEvent(event);
        return;
    }

    // Actualizar posición del sprite
    roshiItem->setPos(posXroshi, 0);
    piedraItem->setPos(posXpiedra, posYpiedra);

    verificarInteraccion();


    // Opcional: Limitar el movimiento dentro de los bordes
    //if(posXroshi < 0) posXroshi = 0;
    //if(posXroshi > escena->width()) posXroshi =1000;
    //if(posXroshi > escena->width() - roshiItem->boundingRect().width())
      //  posXroshi = escena->width() - roshiItem->boundingRect().width();
}
void nivel1::configurarGraphicsView()
{
    // Opcional: Configurar propiedades de la vista
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
}

void animacion_inicioNVL(){
//ANIMACION AL INICIO DEL NIVEL::
    //Un rectangulo rosa cubre toda la ventana, y se va deshaciendo desde
    //el centro hacia afuera , con un circulo en medio, dejando ver la escena (4 segundos)


}
void nivel1::mostrarPiedra(){
    QPixmap roca_C(":/new/sprites/roca_completa.png");

    if (roca_C.isNull()){
        qDebug()<<"Error al cargar el sprite de piedra";
        return;
    }
    /*IMAGEN ESCALADA
    QPixmap imagenEscalada = imagen.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    escena->addPixmap(imagenEscalada);*/

    /// IMAGEN SIN ESCALAR ::
    //ui->graphicsView->fitInView(escena->itemsBoundingRect(), Qt::KeepAspectRatio);
    //piedraItem = escena->addPixmap(roca_C);


    QPixmap imagenEscalada = roca_C.scaled(200,200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    piedraItem = escena->addPixmap(imagenEscalada);
    piedraItem->setPos(posXpiedra, posYpiedra); // Posición inicial
    piedraItem->setFlag(QGraphicsItem::ItemIsMovable, false); //QUE NO SE MUEVA ESTA PUTA PIEDRA POR DIOS
}

void nivel1::verificarInteraccion(){
    if (roshiItem -> collidesWithItem(piedraItem, Qt::IntersectsItemBoundingRect)&& !interaccionPiedra){
        //Cambiamos el sprite de roshi

        interaccionPiedra = true;
        piedraItem->setPixmap(QPixmap(":/new/sprites/roca_levantada.png"));
    }

}
