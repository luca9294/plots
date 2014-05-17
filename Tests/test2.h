#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include "parser_line.h"
#include "retta.h"
#include "circle.h"
#include "parabola.h"
#include "parser_parabola.h"
#include "ellipse.h"
#include "ellipse_n.h"
#include "circle_n.h"
#include "parser_ellipse_n.h"
#include "parser_ellipse.h"
#include "parser_hyperbole.h"
#include "tests/AutoTest.h"


class Test2 : public QObject
{
    Q_OBJECT
public:
    explicit Test2(QObject *parent = 0);

private:
    Parser *col;
    Parser_parabola *par;
    parser_ellipse *parEl;
    parser_ellipse_n *parElN;
    Ellipse *ellipse;
    Ellipse_n *ellipseN;
    Retta *retta;
    Circle *circle;
    circle_n *circleN;
    parser_hyperbole *parHy;
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

    //Center ellipse parser
    void getAEllipse();
    void getBEllipse();


    //Ellipse_n parser
    void getAEllipseN();
    void getBEllipseN();
    void getXcEllipseN();
    void getYcEllipseN();

    //Hyperbole parser
    void getAHyperbole();
    void getBHyperbole();
    void isXHyperbole();



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

    //Ellipse Class
    void isOKEllipse();
    void getXEllipse();
    void getYEllipse();
    void getX1Ellipse();
    void getY1Ellipse();
    void getDescriptionEllipse();

    //Circle Class
    void isOKCircle();
    void getXCircle();
    void getYCircle();
    void getX1Circle();
    void getY1Circle();
    void getDescriptionCircle();



    //Ellipse Traslated Class
    void isOKEllipseN();
    void getXEllipseN();
    void getYEllipseN();
    void getX1EllipseN();
    void getY1EllipseN();
    void getDescriptionEllipseN();


    //Circle traslated Class
    void isOKCircleN();
    void getXCircleN();
    void getYCircleN();
    void getX1CircleN();
    void getY1CircleN();
    void getDescriptionCircleN();





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
