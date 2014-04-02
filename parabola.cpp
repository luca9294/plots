#include "parabola.h"
#include <QRegExp>


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

bool Parabola::isX(){
    return parser->isX();

}


string Parabola::getString(){
    return str;



}


bool Parabola::isOK(){
    QString string = QString::fromUtf8(str.c_str());
    string.replace("^", "");

        // y = ax^2 + bx + c
        QRegExp r("[y] [=] [-+]?[0-9]*[.]?[0-9]*x2 [+-] [0-9]*[.]?[0-9]*x [+-] [0-9]+[.]?[0-9]*");

    // y = ax^2
        QRegExp r1("[y] [=] [-+]?[0-9]*[.]?[0-9]?x2");

    // y = ax^2 + c
        QRegExp r2("[y] [=] [-+]?[0-9]*[.]?[0-9]*x2 [-+] [0-9]*[.]?[0-9]*");

    // x = ax^2 + bx
        QRegExp r3("[y] [=] [-+]?[0-9]*[.]?[0-9]*x2 [+-] [0-9]*[.]?[0-9]*x");

        // y = ax^2 + bx + c
        QRegExp r4("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [+-] [0-9]*[.]?[0-9]*y [+-] [0-9]+[.]?[0-9]*");

    // y = ax^2
        QRegExp r5("[x] [=] [-+]?[0-9]*[.]?[0-9]?y2");

    // y = ax^2 + c
        QRegExp r6("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [-+] [0-9]*[.]?[0-9]*");

    // x = ax^2 + bx
        QRegExp r7("[x] [=] [-+]?[0-9]*[.]?[0-9]*y2 [+-] [0-9]*[.]?[0-9]*y");




    if (r.exactMatch(string)){return true;}
    else if (r1.exactMatch(string)){return true;}
    else if (r2.exactMatch(string)){return true;}
    else if (r3.exactMatch(string)){return true;}
    else if (r4.exactMatch(string)){return true;}
    else if (r5.exactMatch(string)){return true;}
    else if (r6.exactMatch(string)){return true;}
    else if (r7.exactMatch(string)){return true;}

    else return false;


}



QVector<double> Parabola::getX(){

  QVector<double> x(25000); // initialize with entries 0..100

  if (!parser->isX()){
  double w = -1000;
  for (int i=0; i<25000; ++i)
  {
    x[i] = w; // x goes from -1 to 1
   // y[i] = x[i]*x[i];  // let's plot a quadratic function


  w=w+0.1;

  }}

  else {

 double w =  -(b/2*a);

    //  double w =  -20;
      for (int i=0; i<250; ++i)
      {
        x[i] = a*w*w + b*w + c; // x goes from -1 to 1
        cout << "x " <<  x[i] << endl;
      w+=0.1;

      }



}


return x;

}


QVector<double> Parabola::getY(){
  QVector<double> x(25000), y(25000);  // initialize with entries 0..100


if (!parser->isX()){
  double p = -1000;

  for (int i=0; i<25000; ++i)
  {
    x[i] = p; // x goes from -1 to 1
    y[i] = a*x[i]*x[i] + b*x[i] + c;  // let's plot a quadratic function

  p=p+0.1;

}}

  else {
      double p = -(b/2*a);
   // p = -20;
      for (int i=0; i<250; ++i)
      {
   // x goes from -1 to 1
        y[i] = p;  // let's plot a quadratic function
  cout <<  y[i] << endl;

      p+=0.1;}

  }
return y;

}


QVector<double> Parabola::getX1(){

  QVector<double> x(25000); // initialize with entries 0..100



 double w =  -(b/2*a);

    //  double w =  -20;
      for (int i=0; i<250; ++i)
      {
        x[i] = a*w*w + b*w + c; // x goes from -1 to 1
        cout << "x " <<  x[i] << endl;
      w+=0.1;

      }





return x;

}


QVector<double> Parabola::getY1(){
  QVector<double> x(25000), y(25000);  // initialize with entries 0..100





      double p = -(b/2*a);
   // p = -20;
      for (int i=0; i<250; ++i)
      {
   // x goes from -1 to 1
        y[i] = p;  // let's plot a quadratic function
  cout <<  y[i] << endl;

      p-=0.1;}


return y;

}






