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

private:
    double a,b;
    QVector<double> xg;
    QVector<double> yg;
    QVector<double> xg1;
    QVector<double> yg1;
    QPoint vertex;
    QPoint focus;
    parser_ellipse *parser;
    string str;



};

#endif // ELLIPSE_H
