#include "widget_main.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Limpiar variables de entorno conflictivas
    qunsetenv("LIBVA_DRIVERS_PATH");
    qunsetenv("VDPAU_DRIVER");

    // Configurar backend mínimo
    qputenv("QT_AVPLAYER_NO_HWDEVICE", "1");
    qputenv("QT_XCB_GL_INTEGRATION", "none");
    QApplication a(argc, argv);
    widget_main w;
    w.show();
    return a.exec();
}
