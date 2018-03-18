#include <iostream>

#include <limits>
//#include <cstddef>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    double number;
    double OtherNumber;
    int i,j;
    fstream NewFile;
    string Apple;
    for(j=0;j<4;j++){
        do{
            cout << "Please enter a number between 5 and 10:\t";
            cin >> number;
            if (cin.fail()){
                cout << "ERROR -- You did not enter an integer" << endl;
                /*get rid of failure state*/
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }while(number < 5.0 || number > 10.0);

        for(i=0;i<4;i++){
            cout << std::fixed << std::setprecision(2) << "The squareroot of " << number  << " is:\t" << sqrt(number) << endl;
            NewFile.open("TestFile.txt", std::ofstream::out | std::ofstream::app);
            NewFile << std::fixed << std::setprecision(2) << "The squareroot of " << number  << " is:\t" << sqrt(number) << endl;
            NewFile.close();
            number = sqrt(number);
            cout << Apple << OtherNumber;
        }
    }
    return 0;
}
