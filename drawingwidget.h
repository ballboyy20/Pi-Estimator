#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QRect>

#include "piestimator.h"

//class PiEstimator;


class DrawingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingWidget(QWidget *parent = nullptr);
    void set_points_to_draw(std::vector<double> randomXValues, std::vector<double> randomYValues);
    void draw_circle_and_square();
    void draw_shots(PiEstimator inputFromMainWindow);
    void erase_shots();


signals:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    int penThickness{5};
    int circleSize{150};

    PiEstimator privateData;
    std::vector<double> protectedRandomXValues;
    std::vector<double> protectedRandomYValues;
    QPoint screenCenter;
    //I believe that here ill put a vector will all of the points and ill set those points in set_points_to_draw()
    //then it will redraw them

};

#endif // DRAWINGWIDGET_H
