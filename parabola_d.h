#ifndef PARABOLA_D_H
#define PARABOLA_D_H

#include <QDialog>
#include <qdialogbuttonbox.h>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {

class parabola_d;
}

class parabola_d : public QDialog
{
    Q_OBJECT

public:
    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
       MainWindow &parent_window;
       parabola_d(MainWindow &parent, _funcType func);
       ~parabola_d();
       QDialogButtonBox buttonBox;
       QComboBox *combo;
       QComboBox *combo1;


private:
    Ui::parabola_d *ui;

private slots:
void test();
void test2();

};



#endif // PARABOLA_D_H
