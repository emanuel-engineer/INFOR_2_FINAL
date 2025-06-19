#ifndef NIVEL2_H
#define NIVEL2_H

#include <QWidget>

namespace Ui {
class nivel2;
}

class nivel2 : public QWidget
{
    Q_OBJECT

public:
    explicit nivel2(QWidget *parent = nullptr);
    ~nivel2();

private:
    Ui::nivel2 *ui;
};

#endif // NIVEL2_H
