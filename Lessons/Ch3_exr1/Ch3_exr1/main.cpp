#include <iostream>
#include <stdbool.h>

using namespace std;

bool isInt(const char str[]);

int main(){
    bool isTrue = true;
    char Apple[6] = "123";


    isTrue = isInt(Apple);

    isTrue ? cout << "True" << endl : cout << "False" << endl;
}

bool isInt(const char str[]){
    int i = 0;
    bool isInteger = true;
    while (str[i] != '\0'){
        if (! isdigit(str[i])){
            isInteger = false;
            break;
        }
        i++;
    }
    return isInteger ;
}
