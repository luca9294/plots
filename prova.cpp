#include "prova.h"
#include "ui_dialog_ellipse.h"


Dialog_ellipse::Dialog_ellipse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ellipse)
{
    ui->setupUi(this);
    combo = ui->comboBox;
    combo->addItem("y = mx + q");
    combo->addItem("y = mx");
    combo->addItem("y = k");
    combo->addItem("x = k");
}

Dialog_ellipse::~Dialog_ellipse()
{
    delete ui;
}



void Dialog_ellipse::test(){


ui->textEdit->setHtml(combo->currentText().replace("m", "<font color=\"red\"><b>m</b></font>").replace("q","<font color=\"red\"><b>q</b></font>").replace("k","<font color=\"red\"><b>k</b></font>"));



}






