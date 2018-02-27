#include <iostream>

using namespace std;

int main()
{
   int lengthBuffer;

   cout << "Length in cm to convert to meters and cm" << endl;
   cin >> lengthBuffer;
   cout << "Length meters:\t"  << lengthBuffer / 100 << endl;
   cout << "Length cms:\t" << lengthBuffer % 100 << endl;
}
