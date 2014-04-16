#include "hyperbole.h"
#include <math.h>

Hyperbole::Hyperbole(string str)
{
this->str = str;
a = 1;
b = 1;
perform();
}

void Hyperbole::perform(){



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
/*

for (int i = 0; i<100*a*2 + 1; i ++){
xg[i] = xg[i];

yg[i] = (yg[i]);

xg1[i] = xg1[i];
yg1[i] = yg1[i];

*/

}


void Hyperbole::perform2(){



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
/*

for (int i = 0; i<100*a*2 + 1; i ++){
xg[i] = xg[i];

yg[i] = (yg[i]);

xg1[i] = xg1[i];
yg1[i] = yg1[i];

*/

}

