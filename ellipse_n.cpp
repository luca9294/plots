#include "ellipse_n.h"
#include <QRegExp>

#include <math.h>
#include <iostream>

Ellipse_n::Ellipse_n(string str) : Ellipse(str)
{
this->str = str;

    parser = new parser_ellipse_n (str);
      a = parser->getA();
      b = parser->getB();
      Xc = parser->getXc();
      Yc = parser->getYc();

      perform();

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



cout << yg[i]<< endl;
}



}






