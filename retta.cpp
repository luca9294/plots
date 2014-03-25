#include "retta.h"

#include <iostream>

Retta::Retta(string str)
{
this->str = str;
  parser = new Parser (str);
    m = parser->getM();
    q = parser->getQ();
    cout << m << endl;
    cout << q << endl;


}

  QVector<double> Retta::getX(){

    QVector<double> x(250000); // initialize with entries 0..100

    if (!parser->isX()){
    int w = -100000;
    for (int i=0; i<250000; ++i)
    {
      x[i] = w; // x goes from -1 to 1
     // y[i] = x[i]*x[i];  // let's plot a quadratic function


    w++;

    }}

    else {


        for (int i=0; i<250000; ++i)
        {
          x[i] = q; // x goes from -1 to 1
         // y[i] = x[i]*x[i];  // let's plot a quadratic function
        }

  }


return x;

}


  QVector<double> Retta::getY(){
    QVector<double> x(250000), y(250000);  // initialize with entries 0..100


        if (!parser->isX()){
    int p = -100000;

    for (int i=0; i<250000; ++i)
    {
      x[i] = p; // x goes from -1 to 1
      y[i] = m*x[i] + q;  // let's plot a quadratic function


    p++;}}

    else {
        int p = -100000;

        for (int i=0; i<250000; ++i)
        {
     // x goes from -1 to 1
          y[i] = p;  // let's plot a quadratic function


        p++;}

    }
return y;

}



