#include "mainwindow.h"
#include <QApplication>
#include "mywidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    //MyWidget w;
    w.resize(400,400);
    w.show();

    return a.exec();
}
