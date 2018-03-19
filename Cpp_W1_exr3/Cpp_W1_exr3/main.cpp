#include <iostream>
#include <array>

using namespace std;

#define Size 10

int main(){
    array<int, Size> arraytest = {0,1,2,3,4,5,6,7,8,9};
    array<int, Size> two;
    int i = 0;
    double counter = 0;

    for(auto a : arraytest){
        cout << a << endl;
    }

    for(i=0;i<Size;i++){
        counter += arraytest[i];
    }
    cout << "Total value:\t" << counter << endl;
    counter /= Size;
    cout << "Avarage value:\t" << counter << endl;

    two = arraytest;
    for(auto a : two){
        cout << a << endl;
    }
    return 0;
}
