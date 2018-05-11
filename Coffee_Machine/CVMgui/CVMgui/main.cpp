#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
   QApplication a(argc, argv);
   //MainWindow w;
   //w.show();

   MainWindow Apples;

   Apples.window();
   //Apples.display();
   Apples.setDisplay("Man, apples right");
   Apples.show();

   return a.exec();
}
