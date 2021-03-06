#include <iostream>

using namespace std;

class CRectangle {
    int width, height;
public:
    void set_values (int, int);

    ~CRectangle(){cout << "Apple" << endl;}
    CRectangle(){cout << "Fruit" << endl;}
    int area (void) {return (width * height);}
};
void CRectangle::set_values (int a, int b) {
    width = a;
    height = b;
}

class Daughter: public CRectangle{
public:
    Daughter(int a,int b){
        set_values(a,b);
    }
    Daughter(int i){
        cout <<"Daughter "<<i<<endl;
    }

    ~Daughter(){
    }
};

int main (){
    CRectangle a, *b, *c;
    CRectangle * d = new CRectangle[2];
    b = new CRectangle;

    Daughter j(3,5);
    cout << j.area() << endl;

    c= &a;
    a.set_values (10,2);
    b->set_values (3,4);
    d->set_values (5,6);
    d[1].set_values (7,8);

    cout << "a area: " << a.area() << endl;
    cout << "*b area: " << b->area() << endl;
    cout << "*c area: " << c->area() << endl;
    cout << "d[0] area: " << d[0].area() << endl;
    cout << "d[1] area: " << d[1].area() << endl;

    delete[] d;
    delete b;
    return 0;
}
