#include "parabola_d.h"
#include "ui_parabola_d.h"

parabola_d::parabola_d(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parabola_d)
{
    ui->setupUi(this);
}

parabola_d::~parabola_d()
{
    delete ui;
}
