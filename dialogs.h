#ifndef DIALOGS_H
#define DIALOGS_H

#include <QDialog>
#include <qdialogbuttonbox.h>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {
class Dialogs;
}

class Dialogs : public QDialog
{
    Q_OBJECT

public:
    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
     typedef void (MainWindow::*_funcType1)(string);
     _funcType1 m_func1;
       MainWindow &parent_window;
       Dialogs(MainWindow &parent, _funcType func, _funcType1 func1 );
       ~Dialogs();
       QDialogButtonBox buttonBox;
       QComboBox *combo;
       QComboBox *combo1;



private:
    Ui::Dialogs *ui;


private slots:
void test();
void test_n();
void test2();
void test3();
};

#endif // DIALOGS_H
