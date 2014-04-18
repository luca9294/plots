/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011, 2012, 2013 Emanuel Eichhammer                     **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 09.12.13                                             **
**          Version: 1.1.1                                                **
****************************************************************************/

/************************************************************************************************************
**                                                                                                         **
**  This is the example code for QCustomPlot.                                                              **
**                                                                                                         **
**  It demonstrates basic and some advanced capabilities of the widget. The interesting code is inside     **
**  the "setup(...)Demo" functions of MainWindow.                                                          **
**                                                                                                         **
**  In order to see a demo in action, call the respective "setup(...)Demo" function inside the             **
**  MainWindow constructor. Alternatively you may call setupDemo(i) where i is the index of the demo       **
**  you want (for those, see MainWindow constructor comments). All other functions here are merely a       **
**  way to easily create screenshots of all demos for the website. I.e. a timer is set to successively     **
**  setup all the demos and make a screenshot of the window area and save it in the ./screenshots          **
**  directory.                                                                                             **
**                                                                                                         **
*************************************************************************************************************/
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QMenu>
#include "retta.h"
#include "dialog_line.h"
#include "parabola.h"
#include "ellipse_n.h"
#include "ellipse.h"
#include "circle.h"
#include "hyperbole.h"
#include "circle_n.h"
#include <QtGui/QPen>
#include <cstdlib>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

   setStyleSheet("background-color: white;");
    i = 0;
    setGeometry(400, 250, 542, 390);
    rettaMenu = new QAction(("&Draw a new Straight Line"), this);

    parabolaMenu = new QAction(("&Draw a new Parabola"), this);
    ellipseMenu = new QAction(("&Ellipse centered in the origin"), this);
    ellipseMenu2 = new QAction(("&Ellipse not centered in the origin"), this);
    circleMenu = new QAction(("&Circle centered in the origin"), this);
    circleMenu2 = new QAction(("&Circle not centered in the origin"), this);

    clearMenu = new QAction(("&Clear All"), this);
    QMenuBar* bar = ui->menuBar;



    QMenu* menu1 = new QMenu("Draw Functions", bar);
    QMenu* menu2 = new QMenu("&Draw a new Ellipse", bar);
    QMenu* menu3 = new QMenu("&Draw a new Circle", bar);

    menu1->addAction(rettaMenu);

    //connect(rettaMenu, SIGNAL(triggered()), this, SLOT(rettaAction()));
connect(rettaMenu, SIGNAL(triggered()), this, SLOT(test()));

    menu1->addAction(parabolaMenu);
    connect(parabolaMenu, SIGNAL(triggered()), this, SLOT(parabolaAction()));




    menu2->addAction(ellipseMenu);
    connect(ellipseMenu, SIGNAL(triggered()), this, SLOT(ellipseAction()));
    menu2->addAction(ellipseMenu2);
    connect(ellipseMenu2, SIGNAL(triggered()), this, SLOT(ellipseAction2()));

    menu3->addAction(circleMenu);
    connect(circleMenu, SIGNAL(triggered()), this, SLOT(circleAction()));
    menu3->addAction(circleMenu2);
    connect(circleMenu2, SIGNAL(triggered()), this, SLOT(circleAction2()));


    menu1->addMenu(menu3);

    menu1->addMenu(menu2);
    menu1->addAction(clearMenu);





    connect(clearMenu, SIGNAL(triggered()), this, SLOT(clearAction()));

// menu1->addAction(circleMenu2);
 //


    bar->addMenu(menu1);



    Hyperbole h ("");
    drawPoints(h.xg,h.yg,ui->customPlot);
    i--;
    drawPoints(h.xg1 ,h.yg1,ui->customPlot);
    h.perform2();
    i--;
    drawPoints(h.xg,h.yg,ui->customPlot);
    i--;
    drawPoints(h.xg1 ,h.yg1,ui->customPlot);



}



void MainWindow::circleAction()
{

    bool ok;

    QInputDialog  msgBox;

    msgBox.setFixedSize(100000,100000);
    msgBox.setStyleSheet("background-color: blue;");

    QString text = msgBox.getText(this, tr("INSERT CIRCLE"),
                                  tr("Enter the explicity equation of a centered origin circle:            \t\t             \nThe equation should be of the form: x^2 + y^2 = r^2 \nPlease put a space between the elements of the equation.\n\n"), QLineEdit::Normal,
                                  "", &ok);


    if ((ok && !text.isEmpty()) && i<5){
        Circle circle (text.toStdString());

      if (!circle.isOK())  {
            QMessageBox msgBox;
            msgBox.setText("The INPUT format is not right.\nPay attention to the white spaces!\nAccept formats: x^2 + y^2 = A\nwhere A stands for r^2");
            msgBox.exec();
        }


        else{

          drawPoints(circle.getX(), circle.getY(),ui->customPlot);
           i--;
           drawPoints(circle.getX1(), circle.getY1(),ui->customPlot);
           QString string = "<b>";
           string.append(QString::fromUtf8(circle.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
           }

        }}

    else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();
    }
}


void MainWindow::circleAction2()
{

    bool ok;

    QInputDialog  msgBox;

    msgBox.setFixedSize(100000,100000);

    QString text = msgBox.getText(this, tr("INSERT CIRCLE"),
                                  tr("Enter the explicity equation of a non-centered origin circle:            \t\t             \nThe equation should be of the form: (x - Xc)^2 + (y - Yc)^2 = r^2 \nPlease put a space between the elements of the equation.\n\n"), QLineEdit::Normal,
                                  "", &ok);
    if ((ok && !text.isEmpty()) && i<5){
        circle_n circle (text.toStdString());

      if (!circle.isOK())  {
            QMessageBox msgBox;
            msgBox.setText("The INPUT format is not right.\nPay attention to the white spaces!\nAccept formats: (x -(+) Xc)^2 + (y -(+) Yc)^2 = A\nwhere A stands for r^2");
            msgBox.exec();
        }


        else{

         drawPoints(circle.getX(), circle.getY(),ui->customPlot);
          i--;
          drawPoints(circle.getX1(), circle.getY1(),ui->customPlot);
           QString string = "<b>";
           string.append(QString::fromUtf8(circle.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
        }

        }}

    else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();
    }
}












void MainWindow::rettaAction(string str)
{
if (i < 5){
        cout << str << endl;
        Retta retta (str);

        if (!retta.isOK())  {
            QMessageBox msgBox;
            msgBox.setText("The INPUT format is not right.\nPay attention to the white spaces!\nAccept formats: y = mx + q, y = k, x = k");
            if (msgBox.exec() == QMessageBox::Ok){


            };



        }


        else{

            drawPoints(retta.getX(), retta.getY(),ui->customPlot);
           QString string = "<b>";
           string.append(QString::fromUtf8(retta.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
           }

        }}

    else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();

        Dialog *gwe = new Dialog(*this, &MainWindow::rettaAction);
         gwe->exec();
    }
}





void MainWindow::ellipseAction()
{

    bool ok;

    QInputDialog  msgBox;

    msgBox.setFixedSize(100000,100000);

    QString text = msgBox.getText(this, tr("INSERT ELLIPSE origin centered"),
                                  tr("Enter the explicity equation of a Eclipse:            \t\t             \nThe equation should be of the form: x^2/A + y^2/B = 1 7\nPlease put a space between the elements of the equation.\n\n"), QLineEdit::Normal,
                                  "", &ok);
    if ((ok && !text.isEmpty()) && i<5){


         Ellipse eclipse (text.toStdString());
         if (!eclipse.isOK())  {
             QMessageBox msgBox;
             msgBox.setText("The INPUT format is not right.\nPay attention to the white spaces!\nAccept formats: x^2/A + y^2/B = 1");
             msgBox.exec();
         }

else{

        drawPoints(eclipse.getX(), eclipse.getY(),ui->customPlot);
        i--;
        drawPoints(eclipse.getX1(), eclipse.getY1(),ui->customPlot);





/*

        else{

            if (!parabola.isX()){

            drawPoints(parabola.getX(), parabola.getY(),ui->customPlot);}

           else{
            drawPoints(parabola.getX(), parabola.getY(),ui->customPlot);
            i--;
            drawPoints(parabola.getX1(), parabola.getY1(),ui->customPlot);}
*/

QString string = "<b>";
           string.append(QString::fromUtf8(eclipse.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
           }
}
}

    else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();
    }
}

void MainWindow::ellipseAction2()
{

    bool ok;

    QInputDialog  msgBox;

    msgBox.setFixedSize(100000,100000);

    QString text = msgBox.getText(this, tr("INSERT ELLIPSE non origin centered"),
                                  tr("Enter the explicity equation of a Eclipse:            \t\t             \nThe equation should be of the form: (x -(+) Xc)^2/A + (y^2 -(+) Yc)^2/B = 1 7\nPlease put a space between the elements of the equation.\n\n"), QLineEdit::Normal,
                                  "", &ok);
    if ((ok && !text.isEmpty()) && i<5){


         Ellipse_n eclipse (text.toStdString());



         if (eclipse.isOK()){

         drawPoints(eclipse.getX(), eclipse.getY(),ui->customPlot);
         i--;
         drawPoints(eclipse.getX1(), eclipse.getY1(),ui->customPlot);




QString string = "<b>";
           string.append(QString::fromUtf8(eclipse.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
           }}



         else{
             QMessageBox msgBox;
             msgBox.setText("Please write the eclipse in the right form ");
             msgBox.exec();



         }
}



         else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();
    }

}




void MainWindow::parabolaAction()
{

    bool ok;

    QInputDialog  msgBox;

    msgBox.setFixedSize(100000,100000);

    QString text = msgBox.getText(this, tr("INSERT PARABOLA"),
                                  tr("Enter the explicity equation of a parabola Line:            \t\t             \nThe equation should be of the form: y = (-)ax^2 (+/-) bx + c or x = (-)ay^2 (+/-) by + c\nPlease put a space between the elements of the equation.\n\n"), QLineEdit::Normal,
                                  "", &ok);
    if ((ok && !text.isEmpty()) && i<5){
        Parabola parabola (text.toStdString());

        if (!parabola.isOK())  {
            QMessageBox msgBox;
            msgBox.setText("The INPUT format is not right.\nPay attention to the white spaces!\nAccept formats: y = ax^2 + bx + c");
            msgBox.exec();
        }


        else{

            if (!parabola.isX()){

            drawPoints(parabola.getX(), parabola.getY(),ui->customPlot);}

           else{
            drawPoints(parabola.getX(), parabola.getY(),ui->customPlot);
            i--;
            drawPoints(parabola.getX1(), parabola.getY1(),ui->customPlot);}
           QString string = "<b>";
           string.append(QString::fromUtf8(parabola.getString().c_str()));
           string.append("</b>");
           switch (i){

            case 1:
            ui->label0->setText(string);
            ui->label0->setStyleSheet("color : blue;  background-color : white; ");
            break;

           case 2:
           ui->label1->setText(string);
           ui->label1->setStyleSheet("color : red; background-color : white;");
           break;

           case 3:
           ui->label2->setText(string);
           ui->label2->setStyleSheet("color : yellow; background-color : white;");
           break;

           case 4:
           ui->label3->setText(string);
           ui->label3->setStyleSheet("color : black; background-color : white;");
           break;

           case 5:
           ui->label4->setText(string);
           ui->label4->setStyleSheet("color : green; background-color : white;");
           break;
           }

        }}

    else{
        QMessageBox msgBox;
        msgBox.setText("Unfortunatly, you can draw max 5 functions in the same cartesian plane");
        msgBox.exec();
    }
}








//do your task for help about item.


//msgBox.setFixedSize(500, 500);
//msgBox.setLabelText("Enter the explicity equation of a straight Line:\nThe equation should be of the form: y = x + 1 or x = k\nPlease put a space between the elements of the equation.");
//msgBox.setTextValue("");


//msgBox.exec();
void MainWindow::clearAction()
{

    ui->customPlot->clearGraphs();
    ui->customPlot->replot();
    i = 0;
    ui->label0->clear();
    ui->label1->clear();
    ui->label2->clear();
    ui->label3->clear();
    ui->label4->clear();

}


void MainWindow::dialog_line()
{

   Dialog *gwe = new Dialog(*this, &MainWindow::rettaAction);
    gwe->exec();

}





void MainWindow::drawPoints(QVector<double> xg,QVector<double> yg,QCustomPlot *customPlot){
    // add two new graphs and set their look:
    customPlot->addGraph();


    if (i == 5){
        i=0;
    }


    if (i == 0){
        customPlot->graph()->setPen(QPen(Qt::blue));}

    if (i == 1){
        customPlot->graph()->setPen(QPen(Qt::red));}


    if (i == 2){
        customPlot->graph()->setPen(QPen(Qt::yellow));}

    if (i == 3){
        customPlot->graph()->setPen(QPen(Qt::black));}

    if (i == 4){
        customPlot->graph()->setPen(QPen(Qt::green));}

    i++;

    // line color blue for first graph
    // customPlot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    //customPlot->addGraph();
    // customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph

    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)



    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    customPlot->graph()->setData(xg, yg);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    //customPlot->graph()->rescaleAxes();
    //customPlot->graph()->rescaleAxes(true);
    customPlot->xAxis->setRange(-10, 10);
    customPlot->yAxis->setRange(-10, 10);

    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):

    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:

      // make top right axes clones of bottom left axes. Looks prettier:


 customPlot->yAxis->scaleRange(1, customPlot->xAxis->range().center());

      customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    customPlot->replot();

}










void MainWindow::realtimeDataSlot()
{
    // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double key = 0;
#else
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {
        double value0 = qSin(key); //sin(key*1.6+cos(key*1.7)*2)*10 + sin(key*1.2+0.56)*20 + 26;
        double value1 = qCos(key); //sin(key*1.3+cos(key*1.2)*1.2)*7 + sin(key*0.9+0.26)*24 + 26;
        // add data to lines:
        ui->customPlot->graph(0)->addData(key, value0);
        ui->customPlot->graph(1)->addData(key, value1);
        // set data of dots:
        ui->customPlot->graph(2)->clearData();
        ui->customPlot->graph(2)->addData(key, value0);
        ui->customPlot->graph(3)->clearData();
        ui->customPlot->graph(3)->addData(key, value1);
        // remove data of lines that's outside visible range:
        ui->customPlot->graph(0)->removeDataBefore(key-8);
        ui->customPlot->graph(1)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->customPlot->graph(0)->rescaleValueAxis();
        ui->customPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
    ui->customPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        ui->statusBar->showMessage(
                    QString("%1 FPS, Total Data points: %2")
                    .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                    .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
                    , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}

void MainWindow::bracketDataSlot()
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double secs = 0;
#else
    double secs = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif

    // update data to make phase move:
    int n = 500;
    double phase = secs*5;
    double k = 3;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
        x[i] = i/(double)(n-1)*34 - 17;
        y[i] = qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
    }
    ui->customPlot->graph()->setData(x, y);

    itemDemoPhaseTracer->setGraphKey((8*M_PI+fmod(M_PI*1.5-phase, 6*M_PI))/k);

    ui->customPlot->replot();

    // calculate frames per second:
    double key = secs;
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        ui->statusBar->showMessage(
                    QString("%1 FPS, Total Data points: %2")
                    .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                    .arg(ui->customPlot->graph(0)->data()->count())
                    , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}

void MainWindow::setupPlayground(QCustomPlot *customPlot)
{
    Q_UNUSED(customPlot)
}

MainWindow::~MainWindow()
{
    delete ui;
}


























