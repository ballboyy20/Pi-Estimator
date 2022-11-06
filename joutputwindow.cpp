#include "joutputwindow.h"
//#include "ui_OutPutWindow.h"

jOutPutWindow::~jOutPutWindow()
{
    delete ui;
}


void jOutPutWindow::print_string(QString stringToOutPut)
{
    //ui->jOutPutText->appendPlainText(stringToOutPut);
}


/*
jOutPutWindow::~jOutPutWindow()
{
    delete ui;
}

jOutPutWindow::jOutPutWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::jOutPutWindow)
{
    ui->setupUi(this);
}
*/
