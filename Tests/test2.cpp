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
    int index = (parabola->getX()).indexOf(1);
    cout << "TTES " << index << endl;
    QVERIFY(parabola->getY().at(index) == 0);

}












