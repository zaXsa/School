#include <iostream>
#include <stdio.h>

using namespace std;

void hexdumplong (long data );

int main(void){
    long i1 = 1;
    long i2 = 21;
    long i3 = 255;

    hexdumplong (i1);
    hexdumplong (i2);
    hexdumplong (-i2);
    hexdumplong (i3);
    hexdumplong (-i3);

    return 0;
}

void hexdumplong (long data){
    size_t i = 0;
    const unsigned char *pData = (const unsigned char*)& data;

    cout << data << "\t=\t";
    for (i = 0; i < sizeof(long); i++){
        printf("%02x  ", pData[i]);
    }
    printf("\n");
}
