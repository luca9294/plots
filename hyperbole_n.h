#ifndef HYPERBOLE_N_H
#define HYPERBOLE_N_H

#include "parser_ellipse_n.h"
#include "hyperbole.h"

class Hyperbole_n : public Hyperbole
{
public:
    Hyperbole_n(string);
    void perform();
    void perform2();
    double getXc();
    double getYc();
    bool isOK();
    double Xc;
    double Yc;
    string getDescription(int);
private:
    parser_ellipse_n *parser;



};
#endif // HYPERBOLE_N_H
