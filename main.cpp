#include "mainwindow.h"
#include "widget.h"
#include <QApplication>
#include "global.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Widget log;
    //log.show();



    MainWindow w;
    w.show();

    return a.exec();
}
