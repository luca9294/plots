#include "test2.h"
#include "QtTest"
#include <iostream>
#include "qvector.h"

Test2::Test2(QObject *parent)  : QObject(parent)
{
}

// Tests LINE PARSER

//Test parser retta getM()
void Test2::getM(){
  col = new Parser("y = 3x + 1");
  QVERIFY(col->getM() == 3);
}

//Test parser retta getQ()
void Test2::getQ(){
  col = new Parser("y = 3x + 1");
  QVERIFY(col->getQ() == 1);
}

//Test parser retta getQ()
void Test2::isX(){
  col = new Parser("x = 1");
  col->getM();
  QVERIFY(col->isX());
}

//Test RETTA class
void Test2::isOKLine(){
  retta = new Retta("y = 3x + 1");
  QVERIFY(retta->isOK());
}

void Test2::getYLine(){
 retta = new Retta("y = 3x + 1");

  QVector<double> xPoints = retta->getX();
  QVector<double> yPoints = retta->getY();

  int index = xPoints.indexOf(0);

  QVERIFY(yPoints.at(index) == 1);
}


void Test2::getDescriptionLine(){
  retta = new Retta("y = 3x + 1");
  string str = "  <p><FONT size=\"4\">Straight Line of equation";
  string str2 = retta->getDescription(1);
  str2 = str2.substr(0, 35);
  str = str.substr(1, 35);
  QVERIFY(str2==str);
}



void Test2::getXLine(){
  retta = new Retta("y = 3x + 1");

  QVector<double> xPoints = retta->getX();
  QVector<double> yPoints = retta->getY();

  int index = yPoints.indexOf(1);


  QVERIFY(xPoints.at(index) == 0);
}


//Test PARABOLA parser
void Test2::getAParabola(){
    par = new Parser_parabola("y = 3x^2 + 2x + 1");
    QVERIFY(par->getA() == 3);

}

void Test2::getBParabola(){
    par = new Parser_parabola("y = 3x^2 + 2x + 1");
    QVERIFY(par->getB() == 2);

}

void Test2::getCParabola(){
    par = new Parser_parabola("y = 3x^2 + 2x + 1");
    QVERIFY(par->getC() == 1);

}

void Test2::isXParabola(){
par = new Parser_parabola("x = 3y^2 + 2y + 1");
QVERIFY(par->isX());

}

//Test Parabola
void Test2::isOKParabola(){
    parabola = new Parabola("y = 3x^2 + 2x + 1");
    QVERIFY(parabola->isOK());

}


void Test2::getYParabola(){
    parabola = new Parabola("y = x^2");
    QVector<double> xPoints = parabola->getX();
    QVector<double> yPoints = parabola->getY();
    int index = (10010); //position of 1 in the X array
    int e = (int)yPoints.at(index);
    QVERIFY(e == 1);

}



void Test2::getXParabola(){
    parabola = new Parabola("y = x^2 + 1");
    QVector<double> xPoints = parabola->getX();
    QVector<double> yPoints = parabola->getY();
    int x = (10010); //index of y = 2
    QVERIFY((int)xPoints.at(x) == 1);

}




void Test2::getY1Parabola(){
    parabola = new Parabola("x = y^2");
    QVector<double> xPoints = parabola->getX1();
    QVector<double> yPoints = parabola->getY1();
    int indexg = 0;
    for (int i = 0 ; i < xPoints.length(); i++){
        if ((int)xPoints.at(i) == 1){
            indexg = i;
            break;
        }
    }

    //indexg position of x = 1

    QVERIFY((int)yPoints.at(indexg) == -1);

}




void Test2::getX1Parabola(){
    parabola = new Parabola("x = y^2");
    QVector<double> xPoints = parabola->getX1();
    QVector<double> yPoints = parabola->getY1();
    int indexg = 0;
    for (int i = 0 ; i < yPoints.length(); i++){
        if ((int)yPoints.at(i) == -2){
            indexg = i;
            break;
        }
    }

    //indexg position of y = 2

    QVERIFY((int)xPoints.at(indexg) == 4);

}

void Test2::getDescriptionParabola(){
  parabola = new Parabola("y = 3x^2 + x + 2");
  string str = "<p><FONT size=\"4\">Parabola of equation";
  string str2 = parabola->getDescription(1);
  str2 = str2.substr(0, 35);
  str = str.substr(0, 35);
  QVERIFY(str2==str);
}

//Test Ellipse CENTERED Parser
void Test2::getAEllipse(){
    parEl = new parser_ellipse("x^2/81 + y^2/9 = 1");
    QVERIFY(parEl->getA() == 9);

}

void Test2::getBEllipse(){
    parEl = new parser_ellipse("x^2/81 + y^2/9 = 1");
    QVERIFY(parEl->getB() == 3);

}



//Test Ellipse CENTERED class
void Test2::isOKEllipse(){
    ellipse = new Ellipse("x^2/81 + y^2/9 = 1");
    QVERIFY(ellipse->isOK());

}


void Test2::getYEllipse(){
    ellipse = new Ellipse("x^2/81 + y^2/9 = 1");
    QVector<double> xPoints = ellipse->getX();
    QVector<double> yPoints = ellipse->getY();

    int indexg = 0;
    for (int i = 0 ; i < xPoints.length(); i++){
        if ((int)xPoints.at(i) == 9){
            indexg = i;
            break;
        }

        cout <<"size " <<xPoints.length() << endl;
    int e = (int)yPoints.at(indexg);
    QVERIFY(e == 0);

}}


void Test2::getXEllipse(){
    ellipse = new Ellipse("x^2/81 + y^2/9 = 1");
    QVector<double> xPoints = ellipse->getX();
    QVector<double> yPoints = ellipse->getY();

    int indexg = 0;
    for (int i = 0 ; i < yPoints.length(); i++){
        if ((int)yPoints.at(i) == 3){
            indexg = i;
            break;
        }}


    int e = (int)xPoints.at(indexg);
    QVERIFY(e == 0);

}




void Test2::getY1Ellipse(){
    ellipse = new Ellipse("x^2/81 + y^2/9 = 1");
    QVector<double> xPoints = ellipse->getX1();
    QVector<double> yPoints = ellipse->getY1();

    int indexg = 0;
    for (int i = 0 ; i < xPoints.length(); i++){
        if ((int)xPoints.at(i) == 9){
            indexg = i;
            break;
        }}


    int e = (int)yPoints.at(indexg);
    QVERIFY(e == 0);

}


void Test2::getX1Ellipse(){
    ellipse = new Ellipse("x^2/81 + y^2/9 = 1");

    QVector<double> xPoints = ellipse->getX1();
    QVector<double> yPoints = ellipse->getY1();

    int indexg = 0;
    for (int i = 0 ; i < yPoints.length(); i++){
        if ((int)yPoints.at(i) == 0){
            indexg = i;
            break;
        }}

    cout << indexg << endl;
    int e = (int)xPoints.at(indexg);
    QVERIFY(e == -9);

}

void Test2::getDescriptionEllipse(){
  ellipse = new Ellipse("x^2/81 + y^2/9 = 1");
  string str = "<p><FONT size = \"4\">Ellipse of equation";
  string str2 = ellipse->getDescription(1);
  str2 = str2.substr(0, 35);
  str = str.substr(0, 35);
  QVERIFY(str2==str);
}














