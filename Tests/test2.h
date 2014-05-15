#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include "parser_line.h"
#include "tests/AutoTest.h"


class Test2 : public QObject
{
    Q_OBJECT
public:
    explicit Test2(QObject *parent = 0);

private:
    Parser *col;

signals:

public slots:

private slots:


    void getM();


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
