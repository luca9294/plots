#ifndef CIRCLE_H
#define CIRCLE_H

#include <ellipse.h>

class Circle : public Ellipse
{
public:
    Circle(string);
    void perform2();
    bool isOK();
      string getDescription(int);
private:

};

#endif // CIRCLE_H
