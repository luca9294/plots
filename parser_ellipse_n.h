#ifndef PARSER_ELLIPSE_N_H
#define PARSER_ELLIPSE_N_H

#include <parser_ellipse.h>

class parser_ellipse_n : public parser_ellipse
{
public:
    parser_ellipse_n(string);
    double getA();
    double getB();
    double getXc();
    double getYc();
    void perform();

private:
    double Xc;
    double Yc;
    double a;
    double b;




};

#endif // PARSER_ELLIPSE_N_H
