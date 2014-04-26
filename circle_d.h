#ifndef CIRCLE_D_H
#define CIRCLE_D_H

#include <QDialog>
#include <qdialogbuttonbox.h>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {

class circle_d;
}

class circle_d : public QDialog
{
    Q_OBJECT

public:
    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
     typedef void (MainWindow::*_funcType1)(string);
     _funcType1 m_func1;
       MainWindow &parent_window;
       circle_d(MainWindow &parent, _funcType func, _funcType1 func1 );
       ~circle_d();
       QDialogButtonBox buttonBox;
       QComboBox *combo;
       QComboBox *combo1;


private:
    Ui::circle_d *ui;

private slots:
void test();
void test_n();
void test2();
void test3();
};

#endif // CIRCLE_D_H
