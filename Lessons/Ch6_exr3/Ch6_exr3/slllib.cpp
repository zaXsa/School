#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "slllib.h"

/* Shows the contents of all nodes from the head to the end of the list */
void showSLL(const node_t *pHead){
    const node_t *pNext = pHead;

    if (pHead == NULL){
        printf("SLL is empty\n");
    } else {
        while (pNext != NULL){
            printf("Node %p:  Data = %d  pNext = %p\n", pNext, pNext->data, pNext->pNextNode);
            pNext = pNext->pNextNode;
        }
    }
}

/* Returns the size of the SLL (equals the number of nodes) */
int sizeSLL(const node_t *pHead){
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

/* Adds data to a new node at the end of the SLL */
void addSLL(node_t **ppHead, int data){
    node_t *pNext = *ppHead;
    node_t *pNew = (node_t*)malloc(sizeof(node_t));

    /* Check if allocation has succeeded */
    if (pNew != NULL){
        pNew->data = data;
        pNew->pNextNode = NULL;
    }

    if (pNext != NULL){
        /* Traverse through every subsequent node in the SLL */
        while (pNext->pNextNode != NULL){
            pNext = pNext->pNextNode;
        }
        pNext->pNextNode = pNew;
    } else {
        *ppHead = pNew;
    }
}

/* Empties the SLL */
void emptySLL(node_t **ppHead){
    node_t *pToBeRemoved = *ppHead;
    node_t *pNext = NULL;

    while (pToBeRemoved != NULL){
        pNext = pToBeRemoved->pNextNode;
        free(pToBeRemoved);
        pToBeRemoved = pNext;
    }
    *ppHead = NULL;
}

bool isEmptySLL (const node_t *pHead){
    return sizeSLL(pHead) == 0;
}

//bool isEmptySLL (const node_t *pHead){
//    return pHead == NULL;
//}


void removeSLL(node_t **pHead, int Amount){
    node_t *pToBeRemoved = *pHead;
    node_t *pToSafed = *pHead;
    node_t *pNext = NULL;
    int i;
    int size = (sizeSLL(*pHead));

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
            free(pToBeRemoved);
        }
    }
    if(Amount == 0){
        for (i=0;i<Amount+1;i++){
            pNext = pToSafed->pNextNode;
            pToSafed = pNext;
        }
        if (pToBeRemoved != NULL){
            free(pToBeRemoved);
            *pHead = pToSafed;
        }
    }
}

