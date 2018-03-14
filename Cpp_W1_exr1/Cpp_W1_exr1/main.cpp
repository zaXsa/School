#include <iostream>

#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    double number;

    do{
        cout << "Please enter a number between 5 and 10:\t";
        cin >> number;
    }while(number < 5 || number > 10);
    cout << std::fixed << std::setprecision(2) << "The squareroot of " << number  << " is:\t" << sqrt(number) << endl;

    return 0;
}
