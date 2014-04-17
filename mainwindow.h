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

    void setupSincScatterDemo(QCustomPlot *customPlot);
    void setupScatterStyleDemo(QCustomPlot *customPlot);
    void setupLineStyleDemo(QCustomPlot *customPlot);
    void setupScatterPixmapDemo(QCustomPlot *customPlot);
    void setupDateDemo(QCustomPlot *customPlot);
    void setupTextureBrushDemo(QCustomPlot *customPlot);
    void setupMultiAxisDemo(QCustomPlot *customPlot);
    void setupLogarithmicDemo(QCustomPlot *customPlot);
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    void setupParametricCurveDemo(QCustomPlot *customPlot);
    void setupBarChartDemo(QCustomPlot *customPlot);
    void setupStatisticalDemo(QCustomPlot *customPlot);
    void setupSimpleItemDemo(QCustomPlot *customPlot);
    void setupItemDemo(QCustomPlot *customPlot);
    void setupStyledDemo(QCustomPlot *customPlot);
    void setupAdvancedAxesDemo(QCustomPlot *customPlot);
    
    void setupPlayground(QCustomPlot *customPlot);
    
    private slots:
    void realtimeDataSlot();
    void bracketDataSlot();
    void screenShot();
    void allScreenShots();
    void rettaAction(string);
    void clearAction();
    void parabolaAction();
    void ellipseAction();
    void ellipseAction2();
    void circleAction();
    void circleAction2();
     void test();


    
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

