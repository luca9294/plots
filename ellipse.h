#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse
{
public:
    Ellipse();
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


};

#endif // ELLIPSE_H
