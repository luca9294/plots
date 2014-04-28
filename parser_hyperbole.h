#ifndef PARSER_HYPERBOLE_H
#define PARSER_HYPERBOLE_H

#include <vector>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;



class parser_hyperbole
{
public:
    parser_hyperbole(string);
    double getA();
    double getB();
    bool isX();
    string result;

private:
    bool flag;




};

#endif // PARSER_HYPERBOLE_H
