#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include "parser_line.h"
#include "retta.h"
#include "tests/AutoTest.h"


class Test2 : public QObject
{
    Q_OBJECT
public:
    explicit Test2(QObject *parent = 0);

private:
    Parser *col;
    Retta *retta;

signals:

public slots:

private slots:
    //Line Parsers
    void getM();
    void getQ();
    void isX();

    //Line Class
    void isOKLine();
    void getXLine();
    void getYLine();
    void getDescriptionLine();



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
