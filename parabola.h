#ifndef PARABOLA_H
#define PARABOLA_H

#include <QVector>
#include <QPoint>
#include "retta.h"
#include "parser_parabola.h"
#include "shape.h"



    using namespace std;
class Parabola : public Shape

{

public:
    Parabola(string);
    void perform();
    QVector<double> getX();
    QVector<double> getY();
    QVector<double> getX1();
    QVector<double> getY1();
    bool isOK();
     bool isX();
    string getString();
     string getDescription(int);

private:
    double a,b,c;
    QVector<double> xg;
    QVector<double> yg;
    QVector<double> xg1;
    QVector<double> yg1;
    QPoint vertex;
    QPoint focus;
    Parser_parabola *parser;

    string str;
};

#endif // PARABOLA_H
