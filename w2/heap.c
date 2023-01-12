#include "heap.h"

PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

void enqueuePriority(PriorityQueue *pq, int data) {
    List node = createNode(data);
    if (pq->head == NULL) {
        pq->head = node;
    } else {
        List prev = NULL;
        List curr = pq->head;
        while (curr != NULL && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            node->next = pq->head;
            pq->head = node;
        } else {
            prev->next = node;
            node->next = curr;
        }
    }
}

int dequeuePriority(PriorityQueue *pq) {
    if (pq->head == NULL) {
        return -1;
    } else {
        List node = pq->head;
        pq->head = pq->head->next;
        int data = node->data;
        free(node);
        return data;
    }
}

int searchPriorityQueue(PriorityQueue *pq, int data) {
    List node = pq->head;
    while (node != NULL) {
        if (node->data == data) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void printPriorityQueue(PriorityQueue *pq, char *label) {
    List node = pq->head;
    printf("%s: ", label);
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
