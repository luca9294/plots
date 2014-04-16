#ifndef HYPERBOLE_H
#define HYPERBOLE_H
#include<QVector>
using namespace std;


class Hyperbole
{
public:
    Hyperbole(string);
    void perform();
     void perform2();
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




};

#endif // HYPERBOLE_H
