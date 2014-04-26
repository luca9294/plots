#include "dialog_ellipse.h"
#include "ui_dialog_ellipse.h"




Dialog_ellipse::Dialog_ellipse( MainWindow &parent,_funcType func)  :

    ui(new Ui::Dialog_ellipse),
      m_func(func),
  parent_window (parent)



{
    ui->setupUi(this);
}

Dialog_ellipse::~Dialog_ellipse()
{
    delete ui;
}



void Dialog_ellipse::test(){


ui->textEdit->setHtml(combo->currentText().replace("m", "<font color=\"red\"><b>m</b></font>").replace("q","<font color=\"red\"><b>q</b></font>").replace("k","<font color=\"red\"><b>k</b></font>"));



}


void Dialog_ellipse::test2(){

(parent_window.*m_func)(ui->textEdit->toPlainText().toStdString());


}



