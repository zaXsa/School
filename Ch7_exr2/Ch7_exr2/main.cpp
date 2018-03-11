#include <iostream>

using namespace std;

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    data_t data = {1, "Hello queue"};
    /* Create empty queue, pBack = NULL */
    queue_t queue = {NULL};

    showQueue(&queue);
    printf("\nCreate queue\n");
    createQueue(&queue, data);
    showQueue(&queue);

    data.intVal++;
    printf("\nAdd new data to queue\n");
    pushQueue(&queue, data);
    showQueue(&queue);
    cout << endl << "Contains:\t" << sizeQueue(&queue) << endl;

    data.intVal++;
    printf("\nAdd new data to queue\n");
    pushQueue(&queue, data);
    showQueue(&queue);

    data.intVal++;
    printf("\nAdd new data to queue\n");
    pushQueue(&queue, data);
    showQueue(&queue);
    cout << endl << "Contains:\t" << sizeQueue(&queue) << endl;

    if(!emptyQueue(&queue))
    {
        printf("\nFront iValue: %d\n", frontQueue(&queue)->intVal);
        printf("Front text:   %s\n", frontQueue(&queue)->text);
        printf("Back  iValue: %d\n", backQueue(&queue)->intVal);
        printf("Back  text:   %s\n", backQueue(&queue)->text);
    }

    cout << endl << "Contains:\t" << sizeQueue(&queue) << endl;

    printf("\nPop queue\n");
    popQueue(&queue);
    showQueue(&queue);
    cout << endl << "Contains:\t" << sizeQueue(&queue) << endl;
    printf("\nPop queue\n");
    popQueue(&queue);
    showQueue(&queue);
    cout << endl << "Contains:\t" << sizeQueue(&queue) << endl;
    printf("\nPop queue\n");
    popQueue(&queue);
    showQueue(&queue);
    printf("\nPop queue\n");
    popQueue(&queue);
    showQueue(&queue);
    printf("\nPop queue\n");
    popQueue(&queue);
    showQueue(&queue);
    printf("\n");

    return 0;
}
