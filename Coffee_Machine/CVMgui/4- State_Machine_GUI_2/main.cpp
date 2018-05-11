#include "MainWindow.h"
#include <QApplication>
#include <string>
#include <iostream>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);                         // Creates an application named a
    MainWindow w;                                       // Creates a object of class MainWindow with the constructor layout
    w.show();                                           // Shows the created window
    return a.exec();                                    // executes a
}

