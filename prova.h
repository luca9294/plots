#ifndef DIALOG_H
#define DIALOG_H
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
    explicit Dialog_ellipse(QWidget *parent = 0);
    ~Dialog_ellipse();


private:
    Ui::Dialog_ellipse *ui;
QComboBox *combo;

private slots:
void test();

};

#endif // DIALOG_H
