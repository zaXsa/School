#include <iostream>

using namespace std;

void average2D(double *pD1, double *pD2);

int main()
{
    double a = 5.123;
    double b = 5.213;

    average2D(&a, &b);
    cout << a << "\t" << b << endl;
    a = 7.123;
    b = 12.23;
    average2D(&a, &b);
    cout << a << "\t" << b << endl;
    return 0;
}

void average2D(double *pD1, double *pD2){
    *pD1 = *pD2 = (*pD1 + *pD2) / 2;
}
