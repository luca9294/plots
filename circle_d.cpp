#include "circle_d.h"
#include "ui_circle_d.h"

circle_d::circle_d(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::circle_d)
{
    ui->setupUi(this);
}

circle_d::~circle_d()
{
    delete ui;
}
