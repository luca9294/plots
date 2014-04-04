#ifndef PARSER_ELLIPSE_H
#define PARSER_ELLIPSE_H

class parser_ellipse
{
    using namespace std;


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
