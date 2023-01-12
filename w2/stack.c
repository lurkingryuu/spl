#include "stack.h"

Stack* createStack() {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->head = NULL;
    return s;
}

void push(Stack *s, int data) {
    List node = createNode(data);
    if (s->head == NULL) {
        s->head = node;
    } else {
        node->next = s->head;
        s->head = node;
    }
}

int pop(Stack *s) {
    if (s->head == NULL) {
        return -1;
    } else {
        List node = s->head;
        s->head = s->head->next;
        int data = node->data;
        free(node);
        return data;
    }
}

int searchStack(Stack *s, int data) {
    List node = s->head;
    while (node != NULL) {
        if (node->data == data) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
