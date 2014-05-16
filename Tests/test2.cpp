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

//Test line class
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

