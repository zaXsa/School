#include <QApplication>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
    std::fstream fs;
    fs.open ("Data.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << " more lorem ipsum";
    fs.close();
}

