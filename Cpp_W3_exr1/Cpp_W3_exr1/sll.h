#ifndef SLL_H
#define SLL_H

typedef struct node {
    int data;
    struct node *pNextNode;
} node_t;

class SLL{
public:
    SLL();
    SLL(int);
    void showSLL();
    void addNode(int);
    int sizeSLL();
    void removeSLL(int, int);
    void emptySLL();
private:
    node_t *pHead = nullptr;
};

#endif // SLL_H
