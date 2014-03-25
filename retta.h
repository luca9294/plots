#ifndef RETTA_H
#define RETTA_H
#include "parser.h"
#include <qpoint.h>
#include <qvector.h>
#include "parser.h"
using namespace std;
class Retta
{

private:
    double m, q;
    string str;
    QPoint zero;
    QPoint zerox;
    QPoint zeroy;





public:
    QVector<double> getX();
    QVector<double> getY();
    Retta(string);




};

#endif // RETTA_H
