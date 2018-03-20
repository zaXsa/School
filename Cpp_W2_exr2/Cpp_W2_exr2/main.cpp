#include <iostream>

#include "point.h"
using namespace std;

int main(){
    point Apple;
    point Peer(10.4,31.3, "Start");
    Apple.showxy();
    Peer.showxy();
    return 0;
}
