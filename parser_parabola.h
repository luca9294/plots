#ifndef PARSER_PARABOLA_H
#define PARSER_PARABOLA_H
//#include "tokenizer.h" //this is out tokenizer class header
#include <vector>
#include <list>
#include <iterator>
#include <iostream>



using namespace std;

class Parser_parabola
{
public:
    Parser_parabola(string str);
    double getA();
    double getB();
    double getC();
    bool isX();


private:
    string result;
    bool flag;




};

#endif // PARSER_PARABOLA_H
