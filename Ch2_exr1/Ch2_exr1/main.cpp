#include <iostream>
#include <stdbool.h>

using namespace std;
//----------------------------------------------------------------------------------------
#define Size 4

bool compareIntArray(const int arr1[], const int arr2[], int size);
//----------------------------------------------------------------------------------------
int main(){
    bool isTrue = false;
    //----------------------------------------------------------------------------------------
    int array1[Size] = {1,2,3,4};
    int array2[Size] = {1,2,3,4};

    isTrue = compareIntArray(array1, array2, Size);

    cout << "Arrays are equal = ";
    isTrue ? cout << "True" << endl: cout << "False" << endl;
    //----------------------------------------------------------------------------------------
    array1[3] = 6;

    isTrue = compareIntArray(array1, array2, Size);

    cout << "Arrays are equal = ";
    isTrue ? cout << "True" << endl: cout << "False" << endl;
    //----------------------------------------------------------------------------------------
    array2[3] = 6;

    isTrue = compareIntArray(array1, array2, Size);

    cout << "Arrays are equal = ";
    isTrue ? cout << "True" << endl: cout << "False" << endl;
    return 0;
}
//----------------------------------------------------------------------------------------
bool compareIntArray(const int arr1[], const int arr2[], int size){
    int i;
    bool Boob = true;
    for (i=0;i<size;i++){
        if(arr1[i] != arr2[i]){
            Boob = false;
            break;
        }
    }
    return Boob;
}
