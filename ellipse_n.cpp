#include "ellipse_n.h"
#include <QRegExp>

#include <math.h>
#include <iostream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <iostream>



Ellipse_n::Ellipse_n(string str) : Ellipse("")
{
this->str = str;


    parser = new parser_ellipse_n (str);
     a = parser->getA();
     b = parser->getB();
     Xc = parser->getXc();
     Yc = parser->getYc();

     perform();

}



string Ellipse_n::getDescription(int i){
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
    std::ostringstream c_1;
    std::ostringstream c_2;
    std::ostringstream f1;
    std::ostringstream f2;
    std::ostringstream ecc;
    a_n << std::setprecision(3) << a;
    b_n << std::setprecision(3) << b;



          if (a > b){

              f1 << std::setprecision(3) << sqrt(a*a - b*b) + Xc;
              f2 << std::setprecision(3) << -sqrt(a*a - b*b) + Xc;
              ecc << std::setprecision(3) << (sqrt(a*a - b*b)) / a;

              c_1 << std::setprecision(3) << Xc;
              c_2 << std::setprecision(3) << Yc;

         result =
          "<p><FONT size = \"4\"> Ellipse traslated of equation <b><FONT COLOR=\""+color+"\">"+getString()+"</FONT></FONT></b></p>"
         + "<p> <FONT size = \"4\"> The ellipse is traslated with center in C("+ c_1.str()+ ", " + c_2.str() + ") </FONT></p>"
          + "<p> <FONT size = \"4\"> MAJOR <b>SEMI-AXIS A</b> = "+ a_n.str() +" on the line y = "+ c_2.str()+ "</FONT></p>"
          + "<p><FONT size = \"4\">MINOR <b>SEMI-AXIS B</b> = "+ b_n.str() +" on the line x = "+ c_1.str() +"</p></FONT>"
         + "<p> <FONT size = \"4\"> <b>FOCUS 1</b> is in the point F1("+ f1.str() +", "+ c_2.str()+")</FONT></p>"
          + "<p> <FONT size = \"4\"> <b>FOCUS 2</b> is in the point F2("+ f2.str() +", "+ c_2.str()+")</FONT></p>"
         + "<p> <FONT size = \"4\"> The <b>eccentricity</b> of the ellipse has value "+ ecc.str()+ "</FONT></p>"
   ;


}

           else if (a < b){
              c_1 << std::setprecision(3) << Xc;
              c_2 << std::setprecision(3) << Yc;
              f1 << std::setprecision(3) << sqrt(b*b - a*a) + Yc;
              f2 << std::setprecision(3) << -sqrt(b*b - a*a) + Yc;
              ecc << std::setprecision(3) << (sqrt(b*b - a*a)) / b;



              result = "<p><FONT size = \"4\">Ellipse of equation <b><FONT COLOR=\""+color+"\">"+getString()+"</FONT></b></FONT></p>"
             + "<p> <FONT size = \"4\"> The ellipse is traslated with center in C("+ c_1.str()+ ", " + c_2.str() + ") </FONT></p>"
             + "<p> <FONT size = \"4\"> MAJOR <b>SEMI-AXIS A</b> = "+ b_n.str() +" on the line x = "+ c_1.str()+"</FONT></p>"
              + "<p><FONT size = \"4\">MINOR <b>SEMI-AXIS B</b> = "+ a_n.str() +" on the line y = "+ c_2.str()+"</p></FONT>"
             + "<p> <FONT size = \"4\"> <b>FOCUS 1</b> is in the point F1("+c_1.str()+", "+ f1.str() +")</FONT></p>"
              + "<p> <FONT size = \"4\"> <b>FOCUS 2</b> is in the point F2("+c_1.str()+", "+ f2.str() +")</FONT></p>"
              + "<p> <FONT size = \"4\"> The <b>eccentricity</b> of the ellipse has value "+ ecc.str()+ "</FONT></p>";





          }

          else{
              c_1 << std::setprecision(3) << Xc;
              c_2 << std::setprecision(3) << Yc;
              result = "<p><FONT size = \"4\">Circle of equation <b><FONT COLOR=\""+color+"\">"+getString()+"</FONT></b></FONT></p>"
              + "<p> <FONT size = \"4\">The center of the <b>circle</b> is in the point C("+c_1.str()+", "+c_2.str()+") </FONT></p>"
              + "<p> <FONT size = \"4\">The <b>Radius</b> of the circle has value "+ b_n.str() +"</FONT></p>";



          }





          return result;


}






bool Ellipse_n::isOK(){
    QString string = QString::fromUtf8(str.c_str());
cout <<"to " << string.toStdString() << endl;

    string.replace("^2", "");
    string.replace("(", "");
    string.replace(")", "");

cout <<"to " << string.toStdString() << endl;

        // (x - xc)^2/A + (y - yc)^2/B = 1
        QRegExp r("x [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [+] y [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [=] [1]");




        //(x - xc)^2/A + (y - yc)^2/B = 1
        QRegExp r1("x [+-] [0-9]*[.]?[0-9]? [+] y [+-] [0-9]*[.]?[0-9]? [=] [1]");


         QRegExp r2("x [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]?] [+] y [+-] [0-9]*[.]?[0-9]? [=] [1]");

          QRegExp r3("x [+-] [0-9]*[.]?[0-9]? [+] y [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]? [=] [1]");




    if (r.exactMatch(string)){return true;}
    else if (r1.exactMatch(string)){return true;}

    else if (r2.exactMatch(string)){return true;}
    else if (r3.exactMatch(string)){return true;}
    /*else if (r4.exactMatch(string)){return true;}
    else if (r5.exactMatch(string)){return true;}
    else if (r6.exactMatch(string)){return true;}
    else if (r7.exactMatch(string)){return true;}*/

    else return false;


}






void Ellipse_n::perform(){



    QVector<double> x(100*a*2+1), y(100*a*2+1); // initialize with entries 0..100

   double w = -a;
   int count = 0;
   for (int i=0; w<a; ++i)
   {

       x[i] = w;  // let's plot a quadratic function
       y[i] = b*sqrt((1) - ((x[i]*x[i]) / (a*a)));

count++;
   w+=0.01;

   }

   if (x[x.size()-1] != a){
   x[x.size()-1] = a;
   y[x.size()-1] = b*sqrt((1) - ((x[x.size()-1]*x[x.size()-1]) / (a*a)));

   }



   QVector<double> x1(100*a*2+1), y1(100*a*2+1); // initialize with entries 0..100

    w = -a;
   for (int i=0; w<a; ++i)
   {

       x1[i] = w;  // let's plot a quadratic function
       y1[i] = (-b)*sqrt((1) - ((x[i]*x[i]) / (a*a)));



   w+=0.01;

   }

   if (x1[x1.size()-1] != a){
   x1[x1.size()-1] = a;
   y1[x1.size()-1] = (-b)*sqrt((1) - ((x[x1.size()-1]*x[x1.size()-1]) / (a*a)));

   }


xg = x;
yg = y;



xg1 = x1;
yg1 = y1;


for (int i = 0; i<100*a*2 + 1; i ++){
xg[i] = xg[i] + Xc;

yg[i] = (yg[i] + Yc);

xg1[i] = xg1[i] + Xc;
yg1[i] = yg1[i] + Yc;



}



}






