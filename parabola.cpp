#include "parabola.h"


#include <iostream>

Parabola::Parabola(string str)
{
this->str = str;

    parser = new Parser_parabola (str);
      a = parser->getA();
      b = parser->getB();
      c = parser -> getC();
      parser = new Parser_parabola (str);

        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
}
string Parabola::getString(){
    return str;



}



QVector<double> Parabola::getX(){

  QVector<double> x(250000); // initialize with entries 0..100

 // if (!parser->isX()){
  int w = -1000;
  for (int i=0; i<250000; ++i)
  {
    x[i] = w; // x goes from -1 to 1
   // y[i] = x[i]*x[i];  // let's plot a quadratic function


  w=w+0.1;

  }//}

  /*else {


      for (int i=0; i<250000; ++i)
      {
        x[i] = q; // x goes from -1 to 1

      }*/

//}


return x;

}


QVector<double> Parabola::getY(){
  QVector<double> x(250000), y(250000);  // initialize with entries 0..100


 //     if (!parser->isX()){
  int p = -1000;

  for (int i=0; i<250000; ++i)
  {
    x[i] = p; // x goes from -1 to 1
    y[i] = a*x[i]*x[i] + b*x[i] + c;  // let's plot a quadratic function

  p=p+0.1;
}//}

  /*else {
      int p = -100000;

      for (int i=0; i<250000; ++i)
      {
   // x goes from -1 to 1
        y[i] = p;  // let's plot a quadratic function


      p++;}

  }*/
return y;

}
