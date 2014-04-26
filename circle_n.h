#ifndef CIRCLE_N_H
#define CIRCLE_N_H
#include <ellipse_n.h>


class circle_n : public Ellipse_n
{
public:
    circle_n(string);
    bool isOK();
    void perform2();
};

#endif // CIRCLE_N_H
