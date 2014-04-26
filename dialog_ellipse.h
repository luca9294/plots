#ifndef DIALOG_ELLIPSE_H
#define DIALOG_ELLIPSE_H

#include <QDialog>
#include <qdialogbuttonbox.h>
#include <QDialog>
#include <QComboBox>
#include "mainwindow.h"
namespace Ui {
class Dialog_ellipse;
}

class Dialog_ellipse : public QDialog
{
    Q_OBJECT

public:


    typedef void (MainWindow::*_funcType)(string);
     _funcType m_func;
       MainWindow &parent_window;
    Dialog_ellipse(MainWindow &parent, _funcType func );
      ~Dialog_ellipse();
    QDialogButtonBox buttonBox;
    QComboBox *combo;


private:
    Ui::Dialog_ellipse *ui;

private slots:
void test();
void test2();


};

#endif // DIALOG_ELLIPSE_H
