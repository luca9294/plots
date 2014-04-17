#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QComboBox>
#include <qdialogbuttonbox.h>
#include <mainwindow.h>
#include <QTextEdit>



Dialog::Dialog( MainWindow &parent,_funcType func) :

    ui(new Ui::Dialog),
      m_func(func),
  parent_window (parent)


{

    ui->setupUi(this);
    combo = ui->comboBox;
    combo->addItem("y = mx + q");
    combo->addItem("y = mx");
    combo->addItem("y = k");
    combo->addItem("x = k");
    connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(test()));

QPushButton* button = ui->buttonBox->button(QDialogButtonBox::Ok);
connect(button, SIGNAL(clicked()), this, SLOT(test2()));



}


void Dialog::test(){

ui->textEdit->setText(combo->currentText());



}


void Dialog::test2(){

(parent_window.*m_func)(ui->textEdit->toPlainText().toStdString());


}




Dialog::~Dialog()
{
    delete ui;
}
