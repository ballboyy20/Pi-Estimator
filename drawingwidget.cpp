#include "drawingwidget.h"
#include "piestimator.h"

#include <QPainter>
#include <QPoint>

DrawingWidget::DrawingWidget(QWidget *parent): QWidget{parent}
{

}

void DrawingWidget::set_points_to_draw(std::vector<double> randomXValues, std::vector<double> randomYValues)
{
    //store points as member data

    protectedRandomXValues = randomXValues;
    protectedRandomYValues = randomYValues;
    update(); // this will redraw the points when it is called
}

void DrawingWidget::draw_circle_and_square()
{

    QPen circlePen;
    circlePen.setWidth(penThickness);
    circlePen.setColor(Qt::green);

    QPainter circlePainter(this);
    circlePainter.setPen(circlePen);

    QPoint centerPointForCircleandSquare;
    centerPointForCircleandSquare.setX(width()/2);
    centerPointForCircleandSquare.setY(height()/2);
    //circlePainter.drawEllipse(centerPointForCircleandSquare, circleSize, circleSize);

    QPainter squarePainter(this);
    squarePainter.setPen(circlePen);
    squarePainter.drawRect(centerPointForCircleandSquare.x()-circleSize,centerPointForCircleandSquare.y()-circleSize,(circleSize*2),(circleSize*2));
    circlePainter.drawEllipse(centerPointForCircleandSquare, circleSize, circleSize);
}

void DrawingWidget::draw_shots(PiEstimator inputFromMainWindow)
{
    privateData = inputFromMainWindow;
    QPainter dotPainter(this);
    //QPoint screenCenter;
    QPen dotPen;

    dotPen.setWidth(penThickness);
    dotPen.setWidth(penThickness);
    dotPen.setColor(Qt::red);
    dotPainter.setPen(dotPen);


    screenCenter.setX((width()/2));
    screenCenter.setY((height()/2));


    protectedRandomXValues = privateData.get_x_values();
    protectedRandomYValues = privateData.get_y_values();


    for(int i = 0; i < protectedRandomXValues.size(); i++)
    {
        protectedRandomXValues[i] = trunc(protectedRandomXValues[i]);
        protectedRandomYValues[i] = trunc(protectedRandomYValues[i]);
    }

    for(int i = 0; i < privateData.get_amount_samples(); i++)
    {
        dotPainter.drawText(screenCenter.x()+protectedRandomXValues[i],screenCenter.y() + protectedRandomYValues[i], "π");
    }


}

void DrawingWidget::erase_shots()
{
    QPainter shotEraser;
    shotEraser.eraseRect(screenCenter.x(),screenCenter.y(),penThickness,penThickness);
    //draw_circle_and_square();
    PiEstimator emptyPiEstimator;
    //draw_shots(emptyPiEstimator);
    //draw_circle_and_square();
}


void DrawingWidget::paintEvent(QPaintEvent *event)
{
    //    QPainter painter(this);
    //    painter.setPen(Qt::green);
    //    painter.setFont(QFont("Arial", 30));
    //    painter.drawText(rect(), Qt::AlignCenter, "Annie");
    //look for more funcitons like this under Qpainter documetnation

    //painter.drawPoint(100,200);
    erase_shots();
    draw_circle_and_square();
    draw_shots(privateData);
    update();

}
