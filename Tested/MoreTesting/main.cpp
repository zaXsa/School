#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.windowTitleChanged("New title");
    w.show();



    return a.exec();
}
