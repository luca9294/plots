#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "Tokenizer.h" //this is out tokenizer class header
#include <vector>
#include <list>
#include <iterator>


using namespace std;

class Parser{

    public:
        Parser(string str);
        double getM();
        double getQ();



    protected:
    private:
        string result;
        bool flag;


};

#endif // PARSER_H
