#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow570    myMainWindow;
    myMainWindow.show();
    //myMainWindow.showFullScreen();
    return a.exec();
}
