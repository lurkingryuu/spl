#ifndef BASE_INCLUDE
    #include "defs.h"
    #define BASE_INCLUDE
#endif
// Priority Queue
typedef struct priorityQueue {
    List head;
} PriorityQueue;

PriorityQueue* createPriorityQueue();

void enqueuePriority(PriorityQueue *pq, int data);

int dequeuePriority(PriorityQueue *pq);

int searchPriorityQueue(PriorityQueue *pq, int data);

void printPriorityQueue(PriorityQueue *pq, char *label);