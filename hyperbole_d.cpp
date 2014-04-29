#include "hyperbole_d.h"
#include "ui_hyperbole_d.h"

#include <QPushButton>
#include <QComboBox>
#include <qdialogbuttonbox.h>
#include <mainwindow.h>
#include <QTextEdit>
#include <iostream>
#include <qcursor.h>



hyperbole_d::hyperbole_d( MainWindow &parent,_funcType func,_funcType1 func1)  :

    ui(new Ui::hyperbole_d),
      m_func(func),
      m_func1(func1),

      parent_window (parent)
{

    ui->setupUi(this);
    combo = ui->comboBox;
    combo->addItem("x^2/A - y^2/B = 1");
    combo->addItem("y^2/A - x^2/B = 1");
    combo->addItem("x^2 - y^2/B = 1");
    combo->addItem("x^2 - y^2 = 1");


 connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(test()));



QPushButton* button = ui->buttonBox_2->button(QDialogButtonBox::Ok);
QPushButton* button2 = ui->buttonBox_2->button(QDialogButtonBox::Cancel);
connect(button, SIGNAL(clicked()), this, SLOT(test2()));
connect(button2, SIGNAL(clicked()), this, SLOT(close()));



combo1 = ui->comboBox_2;
combo1->addItem("(x - xc)^2/A - (y - yc)^2/B = 1");
combo1->addItem("(y - yc)^2/A - (x - xc)^2/B = 1");
combo1->addItem("(y - yc)^2 - (x - xc)^2/B = 1");
combo1->addItem("(x - xc)^2- (y - yc)^2/B = 1");

connect(combo1, SIGNAL(currentIndexChanged(int)), this, SLOT(test_n()));




button = ui->buttonBox_3->button(QDialogButtonBox::Ok);
button2 = ui->buttonBox_3->button(QDialogButtonBox::Cancel);
connect(button, SIGNAL(clicked()), this, SLOT(test3()));
connect(button2, SIGNAL(clicked()), this, SLOT(close()));


}





void hyperbole_d::test(){
ui->textEdit->setHtml(combo->currentText()
                      .replace("A", "<font color=\"red\"><b>A</b></font>")
                      .replace("B", "<font color=\"red\"><b>B</b></font>"));



}


void hyperbole_d::test_n(){
ui->textEdit_2->setHtml(combo1->currentText()
                      .replace("A", "<font color=\"red\"><b>A</b></font>")
                      .replace("B", "<font color=\"red\"><b>B</b></font>")
                      .replace("xc", "<font color=\"red\"><b>xc</b></font>")
                      .replace("yc", "<font color=\"red\"><b>yc</b></font>"));



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


void hyperbole_d::test3(){

    QTextCursor cursor = ui->textEdit_2->textCursor();
    cursor.atBlockStart();
    cursor.setPosition(ui->textEdit_2->toPlainText().length());
    ui->textEdit_2->setTextCursor(cursor);
    string str = ui->textEdit_2->toPlainText().toStdString();
str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
close();

(parent_window.*m_func1)(str);
}







hyperbole_d::~hyperbole_d()
{
    delete ui;
}
