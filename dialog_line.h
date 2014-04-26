#ifndef DIALOG_H
#define DIALOG_H
#include <qdialogbuttonbox.h>
#include <QDialog>
#include <QComboBox>
#include "mainwindow.h"
namespace Ui {
class Dialog_line;
}

class Dialog_line : public QDialog
{
    Q_OBJECT

public:


    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
       MainWindow &parent_window;
    Dialog_line(MainWindow &parent, _funcType func );
     ~Dialog_line();
    QDialogButtonBox buttonBox;


    QComboBox *combo;

private:
    Ui::Dialog_line *ui;

private slots:
void test();
void test2();
};

#endif // DIALOG_H
