#include "parabola.h"
#include <QRegExp>
#include <iomanip>
#include <locale>
#include <sstream>
#include <iostream>


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
    std::ostringstream c_n;
      a_n << std::setprecision(3) << a;
      b_n << std::setprecision(3) << b;
      c_n << std::setprecision(3) << c;




    //std::string str = boost::lexical_cast<string>(m);
          string result =
          "<p><FONT size=\"4\">Parabola of equation </FONT><b><FONT  size=\"4\" COLOR=\""+color+"\">"+getString()+"</FONT></b>"
          + "<p><b><FONT size=\"4\">a </b> = "+ a_n.str() +"</FONT></p>"
          + "<p><b><FONT size=\"4\">b </b>= "+ b_n.str() +"</FONT></p>"
          + "<p><b><FONT size=\"4\">c = </b>"+ c_n.str() +"</FONT></p>";

          //TIPO y = ax^2 + bx + c
          if (!parser->isX()){
            double x_vertex = -(b/(2*a));
            double y_vertex = a*(x_vertex*x_vertex) + b*(x_vertex) + c;
            double y_focus = (1 - b*b + 4*a*c)/(4*a);
            double directrix = -((1 + b*b - 4*a*c)/(4*a));

            std::ostringstream v1;
            std::ostringstream v2;
            std::ostringstream v3,v4;

              v1 << std::setprecision(3) << x_vertex;
              v2 << std::setprecision(3) << y_vertex;
              v3 << std::setprecision(3) << y_focus;
              v4 << std::setprecision(3) << directrix;

               string str = v1.str();
               if (str == "-0"){

                   str = "0";
               }


            result = result +
                    "<p><font size=\"4\">The <b>vertex</b> of the parabola is in the point V("+str+", "+v2.str()+")</font></p>"
                    +"<p><font size=\"4\">The <b>focus</b> of the parabola is in the point F("+str+", "+v3.str()+")</font></p>"
                    +"<p><font size=\"4\">The <b>axis of symmetry</b> of the parabola has equation x = "+str+ "</font></p>"
                    +"<p><font size=\"4\">The <b>directrix</b> of the parabola has equation y = "+v4.str()+ "</font></p>"
                    ;


          }

          else{
              double x_vertex = -((b*b - 4*a*c)/(4*a));
              double y_vertex = -(b/(2*a));
              double x_focus = (1 - b*b + 4*a*c)/(4*a);
              double directrix = -((1 + b*b - 4*a*c)/(4*a));

              std::ostringstream v1;
              std::ostringstream v2;
              std::ostringstream v3,v4;

                v1 << std::setprecision(3) << x_vertex;
                v2 << std::setprecision(3) << y_vertex;
                v3 << std::setprecision(3) << x_focus;
                v4 << std::setprecision(3) << directrix;

                 string str = v2.str();
                 if (str == "-0"){

                     str = "0";
                 }


              result = result +
                      "<p><font size=\"4\">The <b>vertex</b> of the parabola is in the point V("+v1.str()+", "+str+")</font></p>"
                      +"<p><font size=\"4\">The <b>focus</b> of the parabola is in the point F("+v3.str()+", "+str+")</font></p>"
                      +"<p><font size=\"4\">The <b>axis of symmetry</b> of the parabola has equation y = "+str+ "</font></p>"
                      +"<p><font size=\"4\">The <b>directrix</b> of the parabola has equation x = "+v4.str()+ "</font></p>"
                      ;





          }




          return result;



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






