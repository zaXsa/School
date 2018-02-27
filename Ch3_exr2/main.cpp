#include <iostream>

using namespace std;

int main()
{
    int feet, inch, pounds;
    float length, weight;
    float BMI;

    cout << "Give your length in feet:\t";
    cin >> feet;
    cout << "Give your length in inches:\t";
    cin >> inch;
    cout << "Give your weigth in pounds:\t";
    cin >> pounds;
    cout << endl;

    feet *= 12;
    length = feet + inch;
    length *= 2.54;
    length /= 100;
    weight = pounds / 2.2;

    BMI = weight/(length*length);
    cout << "Your BMI is:\t" << BMI << endl;

    return 0;
}
