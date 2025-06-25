#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include <QWidget>
#include <nivel1.h>
#include <nivel2.h>
#include <QMediaPlayer>
#include <QAudioOutput>

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

    void plstp_clicked();


    void mostrarLOGO();

private:


    Ui::widget_main *ui;
    QGraphicsScene *logo;  //LogoDB.png
    //PARA AUDIO
    QMediaPlayer *player;
    QAudioOutput *audioOut;
    bool isPlaying;

};
#endif // WIDGET_MAIN_H
