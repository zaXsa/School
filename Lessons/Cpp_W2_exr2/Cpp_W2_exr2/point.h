#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class point{
public:
    point();
    point(const double, const double, const string);
    void showxy();
    void setxy(const double, const double);
    void givexy(double *, double *);
private:
    double x,y;
    string ID;
};


#endif // POINT_H
