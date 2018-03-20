#include <iostream>

#include "point.h"
using namespace std;

point::point(){
    x = 0.0;
    y = 0.0;
}

point::point(const double a, const double b, const string c){
    x = a;
    y = b;
    ID = c;
}
void point::showxy(){
    cout << x << " " << y << " " << ID << endl;
}

void point::setxy(const double a, const double b){
    x = a;
    y = b;
}

void point::givexy(double *a, double *b){
    *a = x;
    *b = y;
}
