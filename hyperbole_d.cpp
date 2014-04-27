#include "hyperbole_d.h"
#include "ui_hyperbole_d.h"

#include <QPushButton>
#include <QComboBox>
#include <qdialogbuttonbox.h>
#include <mainwindow.h>
#include <QTextEdit>
#include <iostream>
#include <qcursor.h>



hyperbole_d::hyperbole_d( MainWindow &parent,_funcType func)  :

    ui(new Ui::hyperbole_d),
      m_func(func),
      parent_window (parent)
{

    ui->setupUi(this);
    combo = ui->comboBox;
    combo->addItem("y = ax^2 + bx + c");
    combo->addItem("y = ax^2 + c");
    combo->addItem("y = ax^2 + bx");
    combo->addItem("x = ay^2 + by + c");
    combo->addItem("x = ay^2 + c");
    combo->addItem("x = ay^2 + by");

 connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(test()));



QPushButton* button = ui->buttonBox_2->button(QDialogButtonBox::Ok);
QPushButton* button2 = ui->buttonBox_2->button(QDialogButtonBox::Cancel);
connect(button, SIGNAL(clicked()), this, SLOT(test2()));
connect(button2, SIGNAL(clicked()), this, SLOT(close()));





}





void hyperbole_d::test(){
ui->textEdit->setHtml(combo->currentText()
                      .replace("ax^2", "<font color=\"red\"><b>a</b></font>x^2")
                      .replace("ay^2", "<font color=\"red\"><b>a</b></font>y^2")
                      .replace("bx","<font color=\"red\"><b>b</b></font>x")
                      .replace("by","<font color=\"red\"><b>b</b></font>y")
                      .replace("+ c","+ <font color=\"red\"><b>c</b></font>")
                      .replace("- c","- <font color=\"red\"><b>c</b></font>"));



}




void hyperbole_d::test2(){

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.atBlockStart();
    cursor.setPosition(ui->textEdit->toPlainText().length());
    ui->textEdit->setTextCursor(cursor);
    string str = ui->textEdit->toPlainText().toStdString();
str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
close();

(parent_window.*m_func)(str);
}


hyperbole_d::~hyperbole_d()
{
    delete ui;
}
