#include "retta.h"

#include <QRegExp>
#include <QString>
#include <iomanip>
#include <locale>
#include <sstream>
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

  string Retta::getDescription(int i){
string color = "";
double y0 = (-q/m);

i++;
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
      char s[32];
      sprintf(s, "%f", m);

cout << color << endl;
std::ostringstream m_n;
std::ostringstream q_n;
std::ostringstream y_n;
  m_n << std::setprecision(3) << m;
  q_n << std::setprecision(3) << q;
  y_n << std::setprecision(3) << y0;

  string str = y_n.str();


      string result =
      " <p><FONT size=\"4\">Straight Line of equation </FONT><b><FONT  size=\"5\" COLOR=\""+color+"\">"+getString()+"</FONT></b></p>"
      + "<p><FONT size=\"4\"> <b>m</b> = "+ m_n.str() +"</FONT></p>"
      + "<p><FONT size=\"4\"><b>q</b> = "+ q_n.str() +"</FONT></p>";

      if (parser->isX()){
          result = "<p><FONT size=\"4\">Straight Line of equation </FONT> <FONT COLOR=\""+color+"\">"+getString()+"</FONT></p>"
          + "<p><FONT size=\"4\">m = "+ m_n.str() +"<p></FONT>";


      }

      //TIPO y = k
      if (m_n.str()=="0"  && !parser->isX()){
        result = result + + "<p><font size=\"4\">It meets the <b>Y axis</b> in the point (0, "+q_n.str()+")</font></p>";


      }
      //TIPO x = k
      else if (m_n.str()=="0"  && parser->isX()){
    result = result + + "<p><font size=\"4\">It meets the <b>X axis</b> in the point ("+q_n.str()+", 0)</font></p>";

      }



      else if (q != 0 ){
      result = result + "<p><font size=\"4\">It meets the <b>X axis</b> in the point ("+str+", 0)</font></p>"

      + "<p><font size=\"4\">It meets the <b>Y axis</b> in the point (0, "+q_n.str()+")</font></p>";}

      else{
          result = result + "<p><font size=\"4\">It meets the <b>X axis</b> and <b>Y axis</b> in the <b>origin</b>. </font></p>";



      }


return result;
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



