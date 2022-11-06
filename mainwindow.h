#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "piestimator.h"

#include <QMainWindow>
#include <QtCore>
#include <QHBoxLayout>
#include <QFrame>
#include <QLineSeries>
#include <QtCharts>
#include <QChart>

class DrawingWidget;
namespace Ui

{
class MainWindowForm;
}

class MainWindow570 : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow570(QWidget *parent = 0);
    ~MainWindow570();

    void setup_chart();
    void setup_drawing();
    void clear_chart();
    void replot_line();

public slots:
    void actionExit_triggered();

private slots:
    void calculateButton_clicked();
    void clearButton_clicked();

private:
    Ui::MainWindowForm *mMainWindowUI;
    DrawingWidget* drawing;
    QChart *chartForViewingPiEstimate;
    PiEstimator piEstimation;
    QLineSeries *piSeries;

    int amountSamples{0};
};

#endif // MAINWINDOW_H
