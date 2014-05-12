#include "circle.h"
#include <math.h>
#include <QRegExp>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>





Circle::Circle(string str) : Ellipse(str)
{
this->str = str;

perform2();
perform();
}


void Circle:: perform2(){
string str1 = str.substr(12,str.length()-12);
double af = atof(str1.c_str());
a =  sqrt (af);
b =  sqrt (af);

}

bool Circle::isOK(){
    QString string = QString::fromUtf8(str.c_str());
    string.replace("^", "");



        // x^2/A + y^2/B = 1
        QRegExp r("[x][2][ ][+][ ][y][2][ ][=][ ][0-9]+[.]?[0-9]*");



    // y = ax^2
       // QRegExp r1("[y] [=] [-+]?[0-9]*[.]?[0-9]?x2");

    // y = ax^2 + c
        //QRegExp r2("[y] [=] [-+]?[0-9]*[.]?[0-9]*x2 [-+] [0-9]*[.]?[0-9]*");

    // x = ax^2 + bx
//        QRegExp r3("[y] [=] [-+]?[0-9]*[.]?[0-9]*x2 [+-] [0-9]*[.]?[0-9]*x");

        // y = ax^2 + bx + c
//        QRegExp r4("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [+-] [0-9]*[.]?[0-9]*y [+-] [0-9]+[.]?[0-9]*");

    // y = ax^2
  //      QRegExp r5("[x] [=] [-+]?[0-9]*[.]?[0-9]?y2");

    // y = ax^2 + c
    //    QRegExp r6("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [-+] [0-9]*[.]?[0-9]*");

    // x = ax^2 + bx
      //  QRegExp r7("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [+-] [0-9]*[.]?[0-9]*y");




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

string Circle::getDescription(int i){
    string result;

    string color = "";



          switch (i){
          case (1):
          color = "blue";
          break;

          case (2):
          color = "red";
          break;

          case 3:
          color = "yellow";
          break;

          case 4:
          color = "black";
          break;

          case 5:
          color = "green";
          break;

    }



    std::ostringstream a_n;
    std::ostringstream b_n;

    a_n << std::setprecision(3) << a;
    b_n << std::setprecision(3) << b;



   result = "<p> <FONT size = \"4\">Circle of equation <b><FONT COLOR=\""+color+"\">"+getString()+"</FONT></FONT></b></p>"
              + "<p> <FONT size = \"4\">The center of the <b>circle</b> is the origin of the axes </FONT></p>"
              + "<p> <FONT size = \"4\">The <b>Radius</b> of the circle has value "+ b_n.str() +"</FONT></p>";







          return result;


}

