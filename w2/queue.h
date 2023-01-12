#ifndef BASE_INCLUDE
    #include "defs.h"
    #define BASE_INCLUDE
#endif

typedef struct queue {
    List head;
    List tail;
} Queue;

Queue* createQueue(); 

void enqueue(Queue *q, int data); 

int dequeue(Queue *q);

int searchQueue(Queue *q, int data); 

void printQueue(Queue *q, char *label);