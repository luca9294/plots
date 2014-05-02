#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <shape.h>;






#include "../../qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.

namespace Ui {
    class MainWindow;
}
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    int i;
    ~MainWindow();

    QStackedWidget *_widget;
    void drawPoints( QVector<double> x,QVector<double> y, QCustomPlot *customPlot);
    
    void setupPlayground(QCustomPlot *customPlot);
    
    private slots:
    void realtimeDataSlot();
    void bracketDataSlot();
    void rettaAction(string);
    void clearAction();
    void parabolaAction(string);
    void hyperboleAction(string);
    void hyperboleAction2(string);
    void ellipseAction(string);
    void ellipseAction2(string);
    void circleAction(string);
    void circleAction2(string);
    void dialog_line();
    void dialog_ellips();
    void dialog_circle();
    void dialog_parabola();
    void dialog_hyperbole();
 void prova(QCPAbstractPlottable*);
//void prova(i);

    
private:
    Ui::MainWindow *ui;
    QString demoName;
    QAction* rettaMenu;
    QAction* clearMenu;
    QAction* parabolaMenu;
    QAction* ellipseMenu;
    QAction* circleMenu;
    QAction* hyperboleMenu;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;
    list<string> list;
};

#endif // MAINWINDOW_H

