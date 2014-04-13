#include "ellipse.h"
#include <QRegExp>

#include <math.h>
#include <iostream>

Ellipse::Ellipse(string str)
{
this->str = str;

    parser = new parser_ellipse (str);
      a = parser->getA();
      b = parser->getB();

      perform();

}

bool Ellipse::isX(){
    return parser->isX();

}

void Ellipse::perform(){






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




   /*}}

   else {


  double w =  -(b / (2*a));


     //  double w =  -20;
       for (int i=0; i<25000; ++i)
       {


           y[i] = w; // x goes from -1 to 1
           x[i] = (a)*(y[i])*(y[i])+(b)*(y[i]) + c;  // let's plot a quadratic function



       w+=0.1;

       }

       w =  -(b / (2*a));


          //  double w =  -20;
            for (int i=0; i<25000; ++i)
            {


                y1[i] = w; // x goes from -1 to 1
                x1[i] = (a)*(y[i])*(y[i])+(b)*(y[i]) + c;  // let's plot a quadratic function



            w-=0.1;

            }

            xg1 = x1;
            yg1 = y1;



 }*/
xg = x;
yg = y;

xg1 = x1;
yg1 = y1;



}


string Ellipse::getString(){
    return str;



}


bool Ellipse::isOK(){
    QString string = QString::fromUtf8(str.c_str());
    string.replace("^", "");



        // x^2/A + y^2/B = 1
        QRegExp r("x2[/]?[0-9]*[.]?[0-9]*[ ][+][ ]y2[/]?[0-9]*[.]?[0-9]*[ ][=][ ][1]");



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



QVector<double> Ellipse::getX(){

return xg;

}


QVector<double> Ellipse::getY(){

return yg;

}


QVector<double> Ellipse::getX1(){
    return xg1;


}


QVector<double> Ellipse::getY1(){
    return yg1;


}


