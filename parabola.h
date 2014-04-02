#ifndef PARABOLA_H
#define PARABOLA_H

#include <QVector>
#include <QPoint>
#include "retta.h"
#include "parser_parabola.h"



    using namespace std;
class Parabola

{

public:
    Parabola(string);
    QVector<double> getX();
    QVector<double> getY();
    QVector<double> getX1();
    QVector<double> getY1();
    bool isOK();
     bool isX();
    string getString();

private:
    double a,b,c;
    QPoint vertex;
    QPoint focus;
    Parser_parabola *parser;
    //Retta directrix;
    string str;
};

#endif // PARABOLA_H
