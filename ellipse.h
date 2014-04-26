#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QVector>
#include <QPoint>
#include "parser_ellipse.h"



class Ellipse
{
public:
    Ellipse(string);
    void perform();
    QVector<double> getX();
    QVector<double> getY();
    QVector<double> getX1();
    QVector<double> getY1();
    bool isOK();
    bool isX();
    string getString();
    double a,b;
    string str;
    QVector<double> xg;
    QVector<double> yg;
    QVector<double> xg1;
    QVector<double> yg1;


private:


    QPoint vertex;
    QPoint focus;
    parser_ellipse *parser;




};

#endif // ELLIPSE_H
