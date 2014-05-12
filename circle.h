#ifndef CIRCLE_H
#define CIRCLE_H

#include <ellipse.h>

class Circle : public Ellipse
{
public:
    Circle(string);
    void perform2();
    bool isOK();

private:
       string getDescription(int);
};

#endif // CIRCLE_H
