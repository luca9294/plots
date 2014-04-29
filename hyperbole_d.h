#ifndef HYPERBOLE_D_H
#define HYPERBOLE_D_H

#include <QDialog>
#include <qdialogbuttonbox.h>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {

class hyperbole_d;
}

class hyperbole_d : public QDialog
{
    Q_OBJECT

public:
    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
     typedef void (MainWindow::*_funcType1)(string);
      _funcType1 m_func1;

       MainWindow &parent_window;
       hyperbole_d(MainWindow &parent, _funcType func, _funcType1 func1);
       ~hyperbole_d();
       QDialogButtonBox buttonBox;
       QComboBox *combo;
       QComboBox *combo1;


private:
    Ui::hyperbole_d *ui;

private slots:
void test();
void test_n();
void test2();
void test3();

};



#endif // HYPERBOLE_D_H
