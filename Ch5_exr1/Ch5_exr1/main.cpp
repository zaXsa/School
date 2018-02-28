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

    t_PostCode PostCodes[6];

    strcpy(PostCodes[0].Letter, "AB");
    PostCodes[0].Numb = 1234;

    strcpy(PostCodes[1].Letter, "CC");
    PostCodes[1].Numb = 6714;

    strcpy(PostCodes[2].Letter, "FA");
    PostCodes[2].Numb = 4214;

    strcpy(PostCodes[3].Letter, "HJ");
    PostCodes[3].Numb = 1231;

    strcpy(PostCodes[4].Letter, "AA");
    PostCodes[4].Numb = 1234;

    strcpy(PostCodes[5].Letter, "AC");
    PostCodes[5].Numb = 1234;


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

