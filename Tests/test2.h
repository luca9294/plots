#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include "parser_line.h"
#include "retta.h"
#include "parabola.h"
#include "parser_parabola.h"

#include "tests/AutoTest.h"


class Test2 : public QObject
{
    Q_OBJECT
public:
    explicit Test2(QObject *parent = 0);

private:
    Parser *col;
    Parser_parabola *par;
    Retta *retta;
    Parabola *parabola;

signals:

public slots:

private slots:
    //Line Parser
    void getM();
    void getQ();
    void isX();

    //Parabola Parser
    void getAParabola();
    void getBParabola();
    void getCParabola();
    void isXParabola();

    //Line Class
    void isOKLine();
    void getXLine();
    void getYLine();
    void getDescriptionLine();

    //Parabola
    void isOKParabola();
    void getXParabola();
    void getYParabola();
    void getX1Parabola();
    void getY1Parabola();
    void getDescriptionParabola();




   /* void testCreateUser();
    void testLogin();
    void testCreateTaskLocally();
    void testCreateTaskPermanently();
    void testDeleteUser();
    void testDestruction();
    void clean();*/

};

DECLARE_TEST(Test2);

#endif // COLLECTIONTEST_H
