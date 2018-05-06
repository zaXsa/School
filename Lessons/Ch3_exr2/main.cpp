#include <iostream>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

bool isInt(const char str[]);

int main(int argc, char *argv[]){
    bool isTrue = true;
    int i;

    for (i=1;i<argc;i++){
        isTrue = isInt(argv[i]);
        isTrue ? cout << "True" << endl : cout << "False" << endl;
    }
}

bool isInt(const char str[]){
    int i = 0;
    bool isInteger = true;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i] != '\0'){
        if (! isdigit(str[i])){
            isInteger = false;
            break;
        }
        i++;
    }
    return isInteger ;
}
