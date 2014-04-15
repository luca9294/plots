#ifndef ELLIPSE_N_H
#define ELLIPSE_N_H
#include "ellipse.h"
#include "parser_ellipse_n.h"

class Ellipse_n : public Ellipse
{
public:
    Ellipse_n(string);
    void perform();
    double getXc();
    double getYc();
    bool isOK();

private:
        parser_ellipse_n *parser;
        double Xc;
        double Yc;

};

#endif // ELLIPSE_N_H
