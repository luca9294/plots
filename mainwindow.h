#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>






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


    void drawPoints( QVector<double> x,QVector<double> y, QCustomPlot *customPlot);
    
    void setupPlayground(QCustomPlot *customPlot);
    
    private slots:
    void realtimeDataSlot();
    void bracketDataSlot();
    void rettaAction(string);
    void clearAction();
    void parabolaAction();
    void ellipseAction(string);
    void ellipseAction2(string);
    void circleAction(string);
    void circleAction2(string);
    void dialog_line();
    void dialog_ellips();
    void dialog_circle();


    
private:
    Ui::MainWindow *ui;
    QString demoName;
    QAction* rettaMenu;
    QAction* clearMenu;
    QAction* parabolaMenu;
    QAction* ellipseMenu;
    QAction* ellipseMenu2;
    QAction* circleMenu;
    QAction* circleMenu2;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;
};

#endif // MAINWINDOW_H

