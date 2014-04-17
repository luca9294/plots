#ifndef DIALOG_H
#define DIALOG_H
#include <qdialogbuttonbox.h>
#include <QDialog>
#include <QComboBox>
#include "mainwindow.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:


    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
       MainWindow &parent_window;
    Dialog(MainWindow &parent, _funcType func );
     ~Dialog();
    QDialogButtonBox buttonBox;


    QComboBox *combo;

private:
    Ui::Dialog *ui;

private slots:
void test();
void test2();
};

#endif // DIALOG_H
