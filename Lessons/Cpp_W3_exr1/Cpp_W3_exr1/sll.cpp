#include <iostream>
#include "sll.h"

using namespace std;

SLL::SLL(){
}

SLL::SLL(int x){
    node_t *pNext = pHead;
    node_t *pNew = new node_t;

    /* Check if allocation has succeeded */
    if (pNew != nullptr){
        pNew->data = x;
        pNew->pNextNode = nullptr;
    }

    if (pNext != nullptr){
        /* Traverse through every subsequent node in the SLL */
        while (pNext->pNextNode != nullptr){
            pNext = pNext->pNextNode;
        }
        pNext->pNextNode = pNew;
    } else {
        pHead = pNew;
    }
}

SLL::~SLL(){}

void SLL::showSLL(){
    const node_t *pNext = pHead;
    if (pNext == nullptr){
        cout << "SLL is empty" << endl;
    } else {
        while (pNext != nullptr){
            printf("Node %p:  Data = %d  pNext = %p\n", pNext, pNext->data, pNext->pNextNode);
            pNext = pNext->pNextNode;
        }
    }
}

void SLL::addNode(int x){
    node_t *pNext = pHead;
    node_t *pNew = new node_t;

    /* Check if allocation has succeeded */
    if (pNew != nullptr){
        pNew->data = x;
        pNew->pNextNode = nullptr;
    }

    if (pNext != nullptr){
        /* Traverse through every subsequent node in the SLL */
        while (pNext->pNextNode != nullptr){
            pNext = pNext->pNextNode;
        }
        pNext->pNextNode = pNew;
    } else {
        pHead = pNew;
    }
}

void SLL::emptySLL(){
    node_t *pToBeRemoved = pHead;
    node_t *pNext = nullptr;

    while (pToBeRemoved != nullptr){
        pNext = pToBeRemoved->pNextNode;
        delete(pToBeRemoved);
        pToBeRemoved = pNext;
    }
    pHead = nullptr;
}

int SLL::sizeSLL(){
    const node_t *pNext = pHead;
    int size = 0;

    if (pHead == NULL){
        return size;
    } else if (pHead != NULL) {
        size = 1;
        while (pNext->pNextNode != NULL){
            size++;
            pNext = pNext->pNextNode;
        }
        return size;
    }
}

int SLL::getdata(int Amount,int size){
    const node_t *pNext = pHead;
    int data;

    int i;

    if(Amount > 0 && Amount < size){
        for (i=0;i<Amount;i++){
            pNext = pNext->pNextNode;
        }
        if (pNext != NULL){
            data = pNext->data;
            return data;
        }
    }
    if(Amount == 0){
        if (pNext != NULL){
            data = pNext->data;
            return data;
        }
    }
}

void SLL::removeSLL(int Amount, int size){
    node_t *pToBeRemoved = pHead;
    node_t *pToSafed = pHead;
    node_t *pNext = nullptr;
    int i;

    if(Amount > 0 && Amount < size){
        for (i=0;i<Amount;i++){
            pNext = pToBeRemoved->pNextNode;
            pToBeRemoved = pNext;
        }
        for (i=0;i<Amount-1;i++){
            pNext = pToSafed->pNextNode;
            pToSafed = pNext;
        }
        if (pToBeRemoved != NULL){
            pToSafed->pNextNode = pToBeRemoved->pNextNode;
            delete(pToBeRemoved);
        }
    }
    if(Amount == 0){
            pNext = pToSafed->pNextNode;
            pToSafed = pNext;
        if (pToBeRemoved != NULL){
            delete(pToBeRemoved);
            pHead = pToSafed;
        }
    }
}
