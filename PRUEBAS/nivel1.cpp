#include "nivel1.h"
#include "ui_nivel1.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

nivel1::nivel1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nivel1)
{
    ui->setupUi(this);

    configurarGraphicsView();
    mostrarRoshi();
    setFocus();
    setFocusPolicy(Qt::StrongFocus); //Eventos del teclado
    qDebug() << "Item creado:" << roshiItem;
}

nivel1::~nivel1()
{
    //INNECESARIO
    //QGraphicsScene *scene = new QGraphicsScene (this);
    //ui->graphicsView->setScene(scene);

    delete ui;
    delete escena;
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
    default:
        QWidget::keyPressEvent(event);
        return;
    }

    // Actualizar posición del sprite
    roshiItem->setPos(posXroshi, 0);

    // Opcional: Limitar el movimiento dentro de los bordes
    //if(posXroshi < 0) posXroshi = 0;
    //if(posXroshi > escena->width()) posXroshi =1000;
    //if(posXroshi > escena->width() - roshiItem->boundingRect().width())
      //  posXroshi = escena->width() - roshiItem->boundingRect().width();
}
void nivel1::configurarGraphicsView()
{
    // Crear e inicializar la escena
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    // Opcional: Configurar propiedades de la vista
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
}
