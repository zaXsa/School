#include <iostream>
#include <fstream>

using namespace std;

bool logicFunction(bool b1, bool b2, bool b3);

int main(){
    int i,j,k;
    bool a,b,c;
    bool Bool = true;
    bool Read = false;
    ofstream BoolTest;
    ifstream OtherTest;
    string text;

    cout << "Input\t\t\t|" << endl;
    cout << "a" << "\t" << "b" << "\t" << "c" << "\t|\t" << "answer" << endl;
    cout << string(60, '-') << endl;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                Bool = (i  &&  j) || !k;
                cout << std::boolalpha << (bool)i << "\t" << (bool)j << "\t" << (bool)k << "\t|\t" << Bool << endl;
            }
        }
    }
    cout << string(60, '-') << endl;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                Bool = (i  &&  j) || !k;
                cout << std::noboolalpha << i << "\t" << j << "\t" << k<< "\t|\t" << Bool << endl;
            }
        }
    }
    cout << string(60, '-') << endl;

    cin >> text;
    cout << "Checking for document:\t" << text << endl;

    OtherTest.open(text);
    OtherTest >> a >> b >> c;
    OtherTest.close();

    Bool = logicFunction(a,b,c);
    cout << a << "\t" << b << "\t" << c << "\t|\t" << Bool << endl;

    return 0;
}

bool logicFunction(bool b1, bool b2, bool b3){
    return (b1  &&  b2) || !b3;
}
