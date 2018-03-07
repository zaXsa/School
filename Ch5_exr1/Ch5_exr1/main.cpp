#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
    int Numb;
    char Letter[3];
}t_PostCode;



int cmp(const void *a, const void *b);

int main(){
    int i = 0;

    t_PostCode PostCodes[6] = {{1234,"AB"},{6714,"CC"},{4214,"FA"},{1231,"HJ"},{1234,"AA"},{1234,"AC"}};
    for(i=0;i<6;i++){
        cout << PostCodes[i].Numb << " " << PostCodes[i].Letter << endl;
    }

    cout << endl << endl;
    qsort(PostCodes, 6, 8, cmp);

    for(i=0;i<6;i++){
        cout << PostCodes[i].Numb << " " << PostCodes[i].Letter << endl;
    }
    return 0;
}

int cmp(const void *a, const void *b){
    int result;

    const t_PostCode *PostCodeA = (t_PostCode *)a;
    const t_PostCode *PostCodeB = (t_PostCode *)b;

    result = (PostCodeA->Numb - PostCodeB->Numb);
    if (result == 0){
        result = strcmp(PostCodeB->Letter, PostCodeA->Letter);
        result = -result;
    }
    if (result < 0)
       return -1;
    else if (result > 0)
       return 1;
    else
       return 0;
}
