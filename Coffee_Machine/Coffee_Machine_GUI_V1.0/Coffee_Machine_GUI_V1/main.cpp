#include "MainWindow.h"
#include <QApplication>
#include <string>
#include <iostream>

int AvailableAmount1 = 1;
int AvailableAmount2 = 1;
int AvailableAmount3 = 1;

int AvailableChange1 = 1;
int AvailableChange2 = 1;
int AvailableChange3 = 1;
int AvailableChange4 = 1;
int AvailableChange5 = 1;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);                         // Creates an application named a
    MainWindow w;                                       // Creates a object of class MainWindow with the constructor layout
    w.show();                                           // Shows the created window
    return a.exec();                                    // executes a
}

