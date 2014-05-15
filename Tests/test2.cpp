#include "test2.h"
#include "QtTest"
#include <iostream>

Test2::Test2(QObject *parent)  : QObject(parent)
{
}

void Test2::getM(){
  col = new Parser("y = 3x + 1");
  cout << col ->getM() << endl;
  QVERIFY(col->getM() == 33);
}
