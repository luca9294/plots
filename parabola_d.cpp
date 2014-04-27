#include "parabola_d.h"
#include "ui_parabola_d.h"

#include <QPushButton>
#include <QComboBox>
#include <qdialogbuttonbox.h>
#include <mainwindow.h>
#include <QTextEdit>
#include <iostream>
#include <qcursor.h>



parabola_d::parabola_d( MainWindow &parent,_funcType func)  :

    ui(new Ui::parabola_d),
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

QPushButton* button = ui->buttonBox->button(QDialogButtonBox::Ok);
QPushButton* button2 = ui->buttonBox->button(QDialogButtonBox::Cancel);
connect(button, SIGNAL(clicked()), this, SLOT(test2()));
connect(button2, SIGNAL(clicked()), this, SLOT(close()));





}





void parabola_d::test(){
ui->textEdit->setHtml(combo->currentText().replace("a", "<font color=\"red\"><b>a</b></font>").replace("b","<font color=\"red\"><b>b</b></font>").replace("c","<font color=\"red\"><b>c</b></font>"));

}




void parabola_d::test2(){

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.atBlockStart();
    cursor.setPosition(ui->textEdit->toPlainText().length());
    ui->textEdit->setTextCursor(cursor);
    string str = ui->textEdit->toPlainText().toStdString();
str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
close();

(parent_window.*m_func)(str);
}


parabola_d::~parabola_d()
{
    delete ui;
}
