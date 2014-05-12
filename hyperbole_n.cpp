#include "hyperbole_n.h"
#include <QRegExp>

#include <math.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <iostream>



Hyperbole_n::Hyperbole_n(string str) : Hyperbole("")
{
    this->str = str;


    parser = new parser_ellipse_n (str);
    a = parser->getA();
    b = parser->getB();
    Xc = parser->getXc();
    Yc = parser->getYc();

    perform();

}



bool Hyperbole_n::isOK(){
    QString string = QString::fromUtf8(str.c_str());

    string.replace("^2", "");
    string.replace("(", "");
    string.replace(")", "");



    // (x - xc)^2/A + (y - yc)^2/B = 1
    QRegExp r("x [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [-] y [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [=] [1]");

    QRegExp r7("y [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [-] x [+-] [0-9]*[.]?[0-9]?[/][0-9]*[.]?[0-9]? [=] [1]");


    //(x - xc)^2/A + (y - yc)^2/B = 1
    QRegExp r1("x [+-] [0-9]*[.]?[0-9]? [-] y [+-] [0-9]*[.]?[0-9]? [=] [1]");


    QRegExp r2("x [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]?] [-] y [+-] [0-9]*[.]?[0-9]? [=] [1]");

    QRegExp r3("x [+-] [0-9]*[.]?[0-9]? [-] y [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]? [=] [1]");



    QRegExp r4("y [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]?] [-] x [+-] [0-9]*[.]?[0-9]? [=] [1]");

    QRegExp r5("y [+-] [0-9]*[.]?[0-9]? [-] x [+-] [0-9]*[.]?[0-9]?/[0-9]*[.]?[0-9]? [=] [1]");

    QRegExp r6("y [+-] [0-9]*[.]?[0-9]? [-] x [+-] [0-9]*[.]?[0-9]? [=] [1]");


    if (r.exactMatch(string)){return true;}

    else if (r1.exactMatch(string)){return true;}

    else if (r2.exactMatch(string)){return true;}
    else if (r3.exactMatch(string)){return true;}
    else if (r7.exactMatch(string)){return true;}
    else if (r4.exactMatch(string)){return true;}
    else if (r5.exactMatch(string)){return true;}
    else if (r6.exactMatch(string)){return true;}

    else return false;


}




void Hyperbole_n::perform(){


    if (str[1] == 'x'){



        QVector<double> x(100000), y(100000); // initialize with entries 0..100

        double w = a;
        int count = 0;
        for (int i=0; i <x.length(); ++i)
        {

            x[i] = w;  // let's plot a quadratic function
            y[i] = (b/a)*sqrt(((x[i]*x[i]) - (a*a)));

            count++;
            w+=0.01;}


        QVector<double> x1(100000), y1(100000); // initialize with entries 0..100
        w = a;
        count = 0;
        for (int i=0; i <x.length(); ++i)
        {

            x1[i] = w;  // let's plot a quadratic function
            y1[i] = -(b/a)*sqrt(((x[i]*x[i]) - (a*a)));




            count++;
            w+=0.01;
        }
        xg = x;
        yg = y;

        xg1 = x1;
        yg1 = y1;


        for (int i = 0; i< xg.length(); i ++){
            xg[i] = xg[i] + Xc;
            yg[i] = yg[i] + Yc;
            xg1[i] = xg1[i] + Xc;
            yg1[i] = yg1[i] + Yc;
        }
    }

    else{
        QVector<double> x(100000), y(100000); // initialize with entries 0..100

        double w = a;
        int count = 0;
        for (int i=0; i <x.length(); ++i)
        {
            y[i] = w ;
            x[i] = (b/a)*sqrt(((y[i]*y[i]) - (a*a)));  // let's plot a quadratic function


            count++;
            w+=0.01;}



        QVector<double> x1(100000), y1(100000); // initialize with entries 0..100

        w = -a;
        count = 0;
        for (int i=0; i <x1.length(); ++i)
        {
            y1[i] = w;
            x1[i] = (b/a)*sqrt(((y[i]*y[i]) - (a*a)));  // let's plot a quadratic function



            count++;
            w-=0.01;
        }
        xg = x;
        yg = y;

        xg1 = x1;
        yg1 = y1;

        for (int i = 0; i< xg.length(); i ++){
            xg[i] = xg[i] + Yc;
            yg[i] = yg[i] + Xc;
            xg1[i] = xg1[i] + Yc;
            yg1[i] = yg1[i] + Xc;
        }


    }
}

void Hyperbole_n::perform2(){


    if (str[1] == 'x'){



        QVector<double> x(100000), y(100000); // initialize with entries 0..100

        double w = -a;
        int count = 0;
        for (int i=0; i <x.length(); ++i)
        {

            x[i] = w;  // let's plot a quadratic function
            y[i] = (b/a)*sqrt(((x[i]*x[i]) - (a*a)));

            count++;
            w-=0.01;}


        QVector<double> x1(100000), y1(100000); // initialize with entries 0..100
        w = -a;
        count = 0;
        for (int i=0; i <x.length(); ++i)
        {

            x1[i] = w;  // let's plot a quadratic function
            y1[i] = -(b/a)*sqrt(((x[i]*x[i]) - (a*a)));




            count++;
            w-=0.01;
        }
        xg = x;
        yg = y;

        xg1 = x1;
        yg1 = y1;


        for (int i = 0; i< xg.length(); i ++){
            xg[i] = xg[i] + Xc;
            yg[i] = yg[i] + Yc;
            xg1[i] = xg1[i] + Xc;
            yg1[i] = yg1[i] + Yc;
        }
    }

    else{
        QVector<double> x(100000), y(100000); // initialize with entries 0..100

        double w = a;
        int count = 0;
        for (int i=0; i <x.length(); ++i)
        {
            y[i] = w ;
            x[i] = -(b/a)*sqrt(((y[i]*y[i]) - (a*a)));  // let's plot a quadratic function


            count++;
            w+=0.01;}



        QVector<double> x1(100000), y1(100000); // initialize with entries 0..100

        w = -a;
        count = 0;
        for (int i=0; i <x1.length(); ++i)
        {
            y1[i] = w;
            x1[i] = -(b/a)*sqrt(((y[i]*y[i]) - (a*a)));  // let's plot a quadratic function



            count++;
            w-=0.01;
        }
        xg = x;
        yg = y;

        xg1 = x1;
        yg1 = y1;

        for (int i = 0; i< xg.length(); i ++){
            xg[i] = xg[i] + Yc;
            yg[i] = yg[i] + Xc;
            xg1[i] = xg1[i] + Yc;
            yg1[i] = yg1[i] + Xc;
        }


    }}


    string Hyperbole_n::getDescription(int i){
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
              std::ostringstream f1;
              std::ostringstream f2;
              std::ostringstream as;
              std::ostringstream ecc;
              std::ostringstream c1;
              std::ostringstream c2;
              a_n << std::setprecision(3) << a;
              b_n << std::setprecision(3) << b;
              c1 << std::setprecision(3) << Xc;
              c2 << std::setprecision(3) << Yc;





    if (!this->isX()){
                  ecc << std::setprecision(3) << sqrt(a*a + b*b) / a;
                  as << std::setprecision(3)  << b / a;
                  f1 << std::setprecision(3) << sqrt(a*a + b*b)+Xc;
                  f2 << std::setprecision(3) << -sqrt(a*a + b*b)+Yc;


             result =
              "<p><FONT size = \"4\">Hyperbole of equation</FONT> <b><FONT size = \"4\" COLOR=\""+color+"\">"+getString()+"</FONT></b></p>"
              +"<p>The hyperbole is traslated with center in C("+c1.str()+", "+c2.str()+") </p>"
              + "<p> <FONT size = \"4\"> The distance from the origin <b>a</b> is "+ a_n.str() +"</FONT></p>"
              + "<p> <FONT size = \"4\"> <b>FOCUS 1</b> is in the point F1("+ f1.str() +", "+c2.str()+")</FONT></p>"
              + "<p> <FONT size = \"4\"> <b>FOCUS 2</b> is in the point F2("+ f2.str() +", "+c2.str()+")</FONT></p>"
              + "<p> <FONT size = \"4\">The <b>eccentricity</b> of the hyperbole is "+ ecc.str()+"</FONT></p>"
              + "<p> <FONT size = \"4\"> The <b>equations</b> of the asymptotes are y = +/- "+ as.str()+ "x</FONT></p>"
        ;


    }


    else{

        ecc << std::setprecision(3) << sqrt(a*a + b*b) / a;
        as << std::setprecision(3)  << b / a;
        f1 << std::setprecision(3) << sqrt(a*a + b*b);
        f2 << std::setprecision(3) << -sqrt(a*a + b*b);


    result =
    "<p><FONT size = \"4\">Hyperbole of equation</FONT> <b><FONT size = \"4\" COLOR=\""+color+"\">"+getString()+"</FONT></b></p>"
    + "<p> <FONT size = \"4\"> The distance from the origin <b>a</b> is "+ a_n.str() +"</FONT></p>"
    + "<p> <FONT size = \"4\"> <b>FOCUS 1</b> is in the point F1(0, "+ f1.str()+")</FONT></p>"
    + "<p> <FONT size = \"4\"> <b>FOCUS 2</b> is in the point F2(0, "+ f2.str() +")</FONT></p>"
    + "<p> <FONT size = \"4\">The <b>eccentricity</b> of the hyperbole is "+ ecc.str()+"</FONT></p>"
    + "<p> <FONT size = \"4\"> The <b>equations</b> of the asymptotes are y = +/- "+ as.str()+ "x</FONT></p>"
    ;



    }
    return result;




    }











