#include <iostream>
#include <vector>
#include "sll.h"

using namespace std;

int main(){
    std::vector<SLL> One(3);

    SLL Test1;
    SLL Test2(15);

    One[0].addNode(5);
    One[1].addNode(10);
    One[2].addNode();

    Test2.addNode(20);
    Test2.addNode(231);
    Test2.showSLL();
    cout << "Size of SLL: " << Test2.sizeSLL() << endl;
    Test2.addNode(23);
    Test2.addNode(21);
    Test2.showSLL();
    cout << "Size of SLL: " << Test2.sizeSLL() << endl;

    Test2.removeSLL(2,Test2.sizeSLL());
    Test2.showSLL();
    cout << "Size of SLL: " << Test2.sizeSLL() << endl;

    Test2.emptySLL();
    Test2.showSLL();
    cout << "Size of SLL: " << Test2.sizeSLL() << endl;

    return 0;
}
