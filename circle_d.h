#ifndef CIRCLE_D_H
#define CIRCLE_D_H

#include <QDialog>

namespace Ui {
class circle_d;
}

class circle_d : public QDialog
{
    Q_OBJECT

public:
    explicit circle_d(QWidget *parent = 0);
    ~circle_d();

private:
    Ui::circle_d *ui;
};

#endif // CIRCLE_D_H
