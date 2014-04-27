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
       MainWindow &parent_window;
       hyperbole_d(MainWindow &parent, _funcType func);
       ~hyperbole_d();
       QDialogButtonBox buttonBox;
       QComboBox *combo;
       QComboBox *combo1;


private:
    Ui::hyperbole_d *ui;

private slots:
void test();
void test2();

};



#endif // HYPERBOLE_D_H
