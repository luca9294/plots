#ifndef PARABOLA_D_H
#define PARABOLA_D_H

#include <QDialog>

namespace Ui {
class parabola_d;
}

class parabola_d : public QDialog
{
    Q_OBJECT

public:
    explicit parabola_d(QWidget *parent = 0);
    ~parabola_d();

private:
    Ui::parabola_d *ui;
};

#endif // PARABOLA_D_H
