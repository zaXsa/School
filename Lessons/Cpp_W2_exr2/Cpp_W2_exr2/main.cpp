#include <iostream>
#include "array"

#include "point.h"
#include "math.h"
using namespace std;

int main(){
    double A,B,C,D;
    double distance;

    int i,j,c = 0;

    array<double, 4> ArrayOne;

    point One;
    point Two(10.4,31.3, "Start");
    point Three;
    point ArrayTest[4];

    Three.setxy(5.13,16.2);

    cout << "show test one:\t\t";
    One.showxy();
    cout << "show test two:\t\t";
    Two.showxy();
    cout << "show test three:\t";
    Three.showxy();

    ArrayTest[0].setxy(0.8,3.6);
    ArrayTest[1].setxy(3.2,2.0);
    ArrayTest[2].setxy(5.5,6.0);
    ArrayTest[3].setxy(8.4,6.5);

    cout << "show test array points:\t";
    for(i=0;i<4;i++){
        ArrayTest[i].showxy();
    }

    for(i=0;i<3;i++){
        ArrayTest[i].givexy(&A,&B);
        for(j=1;j<4;j++){
            ArrayTest[j].givexy(&C,&D);
            if(i == 2 && j == 1 ){
            } else if(i == j){
            } else {
                cout << "The distance between the array point " << i+1 << " and " << j+1 << ":\t";
                distance = sqrt((B-D)*(B-D)+(A-C)*(A-C));
                ArrayOne[c]=distance;
                cout << ArrayOne[c] << endl;
                c++;
            }
        }
    }
    return 0;
}
