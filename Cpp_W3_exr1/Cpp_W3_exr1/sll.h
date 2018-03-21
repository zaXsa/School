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
    void showSLL();                                             // Shows the entire SLL
    void addNode(int);                                          // Adds a node to the end of the SLL
    int sizeSLL();                                              // Gives the size of the SLL
    int getdata(int the_data_point, int the_size);              // Gets the data of the specified SLL
    void removeSLL(int, int);                                   // Removes a specified SLL
    void emptySLL();                                            // Empties the SLL
private:
    node_t *pHead = nullptr;
};

#endif // SLL_H
