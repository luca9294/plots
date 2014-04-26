#include "dialog_line.h"
#include "ui_dialog_line.h"
#include <QPushButton>
#include <QComboBox>
#include <qdialogbuttonbox.h>
#include <mainwindow.h>
#include <QTextEdit>
#include <iostream>
#include <qcursor.h>


Dialog_line::Dialog_line( MainWindow &parent,_funcType func)  :

    ui(new Ui::Dialog_line),
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





void Dialog_line::test(){


ui->textEdit->setHtml(combo->currentText().replace("m", "<font color=\"red\"><b>m</b></font>").replace("q","<font color=\"red\"><b>q</b></font>").replace("k","<font color=\"red\"><b>k</b></font>"));



}


void Dialog_line::test2(){
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.atBlockStart();
    cursor.setPosition(ui->textEdit->toPlainText().length());
    //cursor.movePosition(ui->textEdit->toPlainText().length());
    ui->textEdit->setTextCursor(cursor);
    string str = ui->textEdit->toPlainText().toStdString();
str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
(parent_window.*m_func)(str);


}




Dialog_line::~Dialog_line()
{
    delete ui;
}
