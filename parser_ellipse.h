#ifndef PARSER_ELLIPSE_H
#define PARSER_ELLIPSE_H

#include <vector>
#include <list>
#include <iterator>
#include <iostream>



using namespace std;


class parser_ellipse
{
public:
    parser_ellipse(string str);
    double getA();
    double getB();
    bool isX();

private:
    string result;
    bool flag;




};

#endif // PARSER_ELLIPSE_H
