#include "circle_n.h"
#include <math.h>
#include <qstring.h>
#include <qregexp.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>



circle_n::circle_n(string str) : Ellipse_n(str)
{
this->str = str;

if (isOK()){
perform2();

perform();
}





}


void circle_n:: perform2(){
string str1 = str.substr(24,str.length()-24);
cout << str1 << endl;

double af = atof(str1.c_str());
a =  sqrt (af);
b =  sqrt (af);

}



bool circle_n::isOK(){
    QString string = QString::fromUtf8(str.c_str());
    string.replace("^2", "");
    string.replace("(", "");
    string.replace(")", "");

    cout << string.toStdString() << endl;


        // x^2/A + y^2/B = 1
        QRegExp r("x [+-] [0-9]+[ ][+][ ]y[ ][+-] [0-9]+[ ]=[ ][0-9]+");


    if (r.exactMatch(string)){return true;}
    /*else if (r1.exactMatch(string)){return true;}
    else if (r2.exactMatch(string)){return true;}
    else if (r3.exactMatch(string)){return true;}
    else if (r4.exactMatch(string)){return true;}
    else if (r5.exactMatch(string)){return true;}
    else if (r6.exactMatch(string)){return true;}
    else if (r7.exactMatch(string)){return true;}*/

    else return false;


}








