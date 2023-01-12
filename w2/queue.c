#include "queue.h"

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    List node = createNode(data);
    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

int dequeue(Queue *q) {
    if (q->head == NULL) {
        return -1;
    } else {
        List node = q->head;
        q->head = q->head->next;
        int data = node->data;
        free(node);
        return data;
    }
}

int searchQueue(Queue *q, int data) {
    List node = q->head;
    while (node != NULL) {
        if (node->data == data) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void printQueue(Queue *q, char *label) {
    List node = q->head;
    printf("%s: ", label);
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}