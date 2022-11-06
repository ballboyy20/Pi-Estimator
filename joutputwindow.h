#ifndef JOUTPUTWINDOW_H
#define JOUTPUTWINDOW_H

#include <QMainWindow>
#include <QWidget>

namespace Ui{
class jOutPutWindow;
}

class jOutPutWindow: public QWidget
{
    Q_OBJECT

public:
    //explicit jOutPutWindow(QWidget *parent = 0);
    ~jOutPutWindow();

public slots:
    void print_string(QString stringToOutPut);

private:
    Ui::jOutPutWindow *ui;

};

#endif // JOUTPUTWINDOW_H
