#include <iostream>

using namespace std;
#define Size 4

void avarageDdata(double pData[], int size);

int main(){
    double a[Size] = {1.0,2.0,3.0,4.0};
    double b[Size] = {6.2,3.1,2.7,2.8};
    int i;

    avarageDdata(a, Size);
    avarageDdata(b, Size);

    for (i=0;i<Size;i++){
        cout << a[i] << endl;
    }
    for (i=0;i<Size;i++){
        cout << b[i] << endl;
    }
    return 0;
}

void avarageDdata(double pData[], int size){
    int i;
    double Data;
    for (i=0;i<size;i++){
        Data += pData[i];
    }
    Data /= size;
    for (i=0;i<size;i++){
        pData[i] = Data;
    }
}
