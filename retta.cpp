#include "retta.h"

#include <QRegExp>
#include <QString>
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

bool Retta::isOK(){
    QString string = QString::fromUtf8(str.c_str());


        QRegExp r("[y] [=] [-+]?[0-9]*[.]?[0-9]*x [+-] [0-9]+[.]?[0-9]*");

    // y = mx
        QRegExp r1("[y] [=] [-+]?[0-9]*[.]?[0-9]*x");

    // y = k
        QRegExp r2("[y] [=] [-+]?[0-9]*[.]?[0-9]*");

    // x = k
        QRegExp r3("[x] [=] [-+]?[0-9]*[.]?[0-9]*");

    if (r.exactMatch(string)){return true;}
    else if (r1.exactMatch(string)){return true;}
    else if (r2.exactMatch(string)){return true;}
    else if (r3.exactMatch(string)){return true;}
    else return false;


}

  string Retta::getString(){
      return str;

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



