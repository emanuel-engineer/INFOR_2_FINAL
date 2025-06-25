#include "widget_main.h"
#include "ui_widget_main.h"

widget_main::widget_main(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_main)
{
    ui->setupUi(this);

    logo = new QGraphicsScene(this);
    ui->DBLOGO->setScene(logo);

    //AUDIO::
    //(Configurar el reproductor)
    player =new QMediaPlayer(this);
    audioOut = new QAudioOutput(this);
    player->setAudioOutput(audioOut);


    // Configuración específica para solo audio
    player->setLoops(QMediaPlayer::Infinite);
    qputenv("QT_MEDIA_BACKEND", "audioonly");




    //Configurar el volumen
    audioOut->setVolume(70); //Volumen al 70%
    //Cargar MUsica::
    player ->setSource(QUrl("qrc:/new/sprites/intro.MP3"));

    //Asignar el boton pl/stp::
    QPushButton *plstp = new QPushButton("🔊", this);

    connect(plstp, &QPushButton::clicked, this, &widget_main::plstp_clicked);

    //Reproducir::

    player->setLoops(QMediaPlayer::Infinite);
    player->play();

    //LogoDB
    mostrarLOGO();
}

widget_main::~widget_main()
{
    delete player;
    delete audioOut;
    delete ui;
    delete logo;
}

void widget_main::on_nivel1_clicked()
{
    player->stop();
    nivel1 *w = new nivel1;
    close();
    w->show();
}


void widget_main::on_nivel2_clicked()
{
    player->stop();
    nivel2 *w = new nivel2;
    close();
    w->show();
}


void widget_main::on_cerrar_clicked()
{
    player->stop();
    close();

    delete player;
    delete audioOut;
    delete ui;
    delete logo;
}

void widget_main::plstp_clicked()
{
    if(isPlaying) {
        player->pause();
        dynamic_cast<QPushButton*>(sender())->setText("🔇");
    } else {
        player->play();
        dynamic_cast<QPushButton*>(sender())->setText("🔊");
    }
    isPlaying = !isPlaying;
}


void widget_main::mostrarLOGO(){
    QPixmap imagen(":/new/sprites/logoDB.png");


    if (imagen.isNull()){
        qDebug()<<"Error al cargar el sprite de logoDB";
        return;
    }

    QPixmap imagenEscalada = imagen.scaled(200, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logo->addPixmap(imagenEscalada);
}
