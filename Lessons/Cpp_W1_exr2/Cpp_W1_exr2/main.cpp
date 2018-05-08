#include <iostream>
#include <fstream>

#include <iomanip>

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

    cout << setw(8) << "Input" << setw(24) << "|" <<  endl;
    cout << setw(8) << "a" << setw(8) << "b" << setw(8) << "c" << setw(8) <<"|" << setw(8) << "answer" << endl;
    cout << string(60, '-') << endl;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                Bool = logicFunction((bool)i,(bool)j,(bool)k);
                cout << setw(8) << std::boolalpha << setw(8) << (bool)i << setw(8) << (bool)j << setw(8)  << (bool)k << setw(8) << "|" << setw(8) << Bool << endl;
            }
        }
    }
    cout << string(60, '-') << endl;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                Bool = logicFunction((bool)i,(bool)j,(bool)k);
                cout << setw(8) << std::noboolalpha << setw(8) << (bool)i << setw(8) << (bool)j << setw(8)  << (bool)k << setw(8) << "|" << setw(8) << Bool << endl;
            }
        }
    }
    cout << string(60, '-') << endl;

    cin >> text;
    cout << "Checking for document:\t" << text << endl;

    OtherTest.open(text);
    if (OtherTest.is_open()){
        OtherTest >> a >> b >> c;
        OtherTest.close();
        Bool = logicFunction(a,b,c);
        cout << setw(8) << a << setw(8) << b << setw(8) << c << setw(8) << "|" << setw(8) << Bool << endl;
    } else {
        cout << "you entered the wrong ducument" << endl;
    }


    return 0;
}

bool logicFunction(bool b1, bool b2, bool b3){
    return (b1  &&  b2) || !b3;
}
