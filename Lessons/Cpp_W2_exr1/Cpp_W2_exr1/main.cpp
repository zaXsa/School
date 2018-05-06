#include <iostream>
#include <string>

using namespace std;

void inputLogicValues(bool &b1, bool &b2, bool &b3);
bool logicFunction(bool b1, bool b2, bool b3);

int main(){
    bool a,b,c;
    bool answer = true;
    cout << a << " " << b << " " << c << endl;
    while(1){
        inputLogicValues(a,b,c);
        cout << a << " " << b << " " << c << endl;
        answer = logicFunction(a,b,c);
        cout << "The outcome is: " << std::boolalpha << answer << endl << string(60,'-') << endl;
    }
    return 0;
}

void inputLogicValues(bool &b1, bool &b2, bool &b3){
    cout << "Enter 3 bools" << endl;
    cin >> b1 >> b2 >> b3;
}

bool logicFunction(bool b1, bool b2, bool b3){
    return (b1  &&  b2) || !b3;
}
