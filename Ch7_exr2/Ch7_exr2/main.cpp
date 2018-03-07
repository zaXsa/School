/* Singly Linked List: SLL */
#include <iostream>

using namespace std;
#include <stdio.h>
#include <stdlib.h>

#include "slllib.h"
#include "queue.h"

int main(void){
    int Amount = 0;

    node_t *pHead = NULL;  /* Create an empty SLL, pHead is the 'owner' of the SLL */
    showSLL(pHead);
    printf("Size of the SLL = %lu\n", sizeSLL(pHead));

    printf("\nAdd new node to the SLL 0x%p:\n", pHead);
    addSLL(&pHead, 10);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

    printf("Add new node to the SLL 0x%p:\n", pHead);
    addSLL(&pHead, 20);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

    printf("Add new node to the SLL 0x%p:\n", pHead);
    addSLL(&pHead, 50);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

//    cout << "remove one test:\t";
//    cin >> Amount;
//    cout << endl;
//    removeSLL(pHead, Amount);

    printf("Add new node to the SLL 0x%p:\n", pHead);
    addSLL(&pHead, 70);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

    printf("Delete the SLL 0x%p (clear the contents):\n", pHead);
    emptySLL(&pHead);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

    printf("Add new node to the SLL 0x%p:\n", pHead);
    addSLL(&pHead, 70);
    addSLL(&pHead, 10);
    addSLL(&pHead, 50);
    addSLL(&pHead, 60);
    showSLL(pHead);
    printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

    return 0;
}
