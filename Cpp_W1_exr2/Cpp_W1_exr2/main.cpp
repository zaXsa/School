#include <iostream>

using namespace std;

bool logicFunction(bool b1, bool b2, bool b3);

int main(){
    int i,j,k;
    bool a,b,c;
    bool Bool = true;
    cout << "Nummber\t|" << endl;
    cout << string(60, '-') << endl;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                Bool = (i  &&  j) || !k;
                cout << i << " " << j << k<< "|" << Bool << endl;
            }
        }
    }
    a = true;
    b = false;
    c = false;

    Bool = logicFunction(a,b,c);

    cout << Bool << endl;
    return 0;
}

bool logicFunction(bool b1, bool b2, bool b3){
    return (b1  &&  b2) || !b3;
}
