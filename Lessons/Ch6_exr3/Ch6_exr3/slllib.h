#ifndef SLLLIB_H
#define SLLLIB_H

typedef struct node {
    int data;
    struct node *pNextNode;
} node_t;

void showSLL(const node_t *pHead);
int sizeSLL(const node_t *pHead);
void addSLL(node_t **ppHead, int data);
void emptySLL(node_t **ppHead);
void removeSLL(node_t **pHead, int Amount);

bool isEmptySLL (const node_t *pHead);

#endif // SLLLIB_H
