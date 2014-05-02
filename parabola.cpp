#include "parabola.h"
#include <QRegExp>


#include <iostream>

Parabola::Parabola(string str) : Shape()
{
this->str = str;

    parser = new Parser_parabola (str);
      a = parser->getA();
      b = parser->getB();
      c = parser -> getC();
      parser = new Parser_parabola (str);
      perform();

        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
}

bool Parabola::isX(){
    return parser->isX();

}

void Parabola::perform(){
   QVector<double> x(25000);
   QVector<double> y(25000);
   QVector<double> x1(25000);
   QVector<double> y1(25000);



   if (!parser->isX()){
   double w = -1000;
   for (int i=0; i<25000; ++i)
   {
     x[i] = w; // x goes from -1 to 1
     y[i] = a*x[i]*x[i]+b*x[i] + c;  // let's plot a quadratic function


   w=w+0.1;

   }}

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



 }
xg = x;
yg = y;


}


string Parabola::getString(){
    return str;



}


string Parabola::getDescription(int i){
    return "è una parabola";



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

return xg;

}


QVector<double> Parabola::getY(){

return yg;

}


QVector<double> Parabola::getX1(){
    return xg1;


}


QVector<double> Parabola::getY1(){
    return yg1;


}






