#ifndef RETTA_H
#define RETTA_H
#include "parser_line.h"
#include <qpoint.h>
#include <qvector.h>
#include "shape.h"
#include "ui_mainwindow.h"



using namespace std;
class Retta : public Shape
{

private:
    double m, q;
    string str;
    Parser *parser;
    QPoint zero;
    QPoint zerox;
    QPoint zeroy;
    Ui::MainWindow *ui;



public:
    QVector<double> getX();
    QVector<double> getY();
    bool isOK();
    string getString();
    string getDescription(int);
    Retta(string);





};

#endif // RETTA_H
