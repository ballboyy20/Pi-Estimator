#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "drawingwidget.h"

#include <QHBoxLayout>
#include <QWidget>
#include <QChartView>
#include <vector>


MainWindow570::MainWindow570(QWidget *parent):QMainWindow{parent}, mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);

    connect(mMainWindowUI->actionExit, SIGNAL(triggered()), this, SLOT(actionExit_triggered()));
    connect(mMainWindowUI->clearButton, SIGNAL(clicked()), this, SLOT(clearButton_clicked()));
    connect(mMainWindowUI->calculateButton, SIGNAL(clicked()), this, SLOT(calculateButton_clicked()));

    resize(1000,600);

    setup_chart();
    setup_drawing();
}

MainWindow570::~MainWindow570()
{
    delete mMainWindowUI;
}

void MainWindow570::setup_chart()
{
    piSeries = new QLineSeries();

    //piEstimation = new PiEstimator();
    piSeries->setName("Every Pi Estimation");

    chartForViewingPiEstimate = new QChart();
    chartForViewingPiEstimate->legend()->hide();
    chartForViewingPiEstimate->addSeries(piSeries);
    chartForViewingPiEstimate->createDefaultAxes();
    chartForViewingPiEstimate->setTitle("Pi Estimation");

    QChartView *chartView = new QChartView(mMainWindowUI->chartFrame);//Parent should be the frame not the chart
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(chartForViewingPiEstimate);

    QGridLayout *gridLayout = new QGridLayout(mMainWindowUI->chartFrame);
    gridLayout->addWidget(chartView,0,0);
}

void MainWindow570::setup_drawing()
{
    //this is like promoting in the designer
    QHBoxLayout* layoutForCircleandSquare = new QHBoxLayout{mMainWindowUI->drawingFrame};
    drawing = new DrawingWidget{mMainWindowUI->drawingFrame};
    layoutForCircleandSquare->addWidget(drawing);
}

void MainWindow570::clear_chart()
{
    chartForViewingPiEstimate->removeAllSeries();
}

void MainWindow570::replot_line()
{
    clear_chart();
    piSeries = new QLineSeries();

    for (int i = 0; i < piEstimation.get_amount_darts_landed(); ++i)
    {
        piSeries->append(piEstimation.get_darts_landed(i),piEstimation.get_estimated_values(i));
    }

    chartForViewingPiEstimate->addSeries(piSeries);//Order matters. Create the series. Then add the points.  Then add to chart
    chartForViewingPiEstimate->createDefaultAxes();

}

void MainWindow570::actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow570::clearButton_clicked()
{
    //clear chart and drawing here
    piEstimation.clear();
    clear_chart();
    mMainWindowUI->lcdNumber->display(0);
    drawing->erase_shots();
    //drawing->set_points_to_draw();//Pass in an empty list of points.  This way the circle and square are still drawn
}

void MainWindow570::calculateButton_clicked()
{
    piEstimation.clear();
    piEstimation.set_amount_samples(mMainWindowUI->amountSamplesInputBox->value());
    piEstimation.estimate_pi();
    replot_line();
    drawing->set_points_to_draw(piEstimation.get_x_values(),piEstimation.get_y_values());//Pass in the list of points here
    drawing->draw_shots(piEstimation);
    mMainWindowUI->lcdNumber->display(piEstimation.get_final_pi_estimation());

}
