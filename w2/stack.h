#ifndef BASE_INCLUDE
    #include "defs.h"
    #define BASE_INCLUDE
#endif

typedef struct stack {
    List head;
} Stack;

Stack* createStack();

void push(Stack *s, int data); 

int pop(Stack *s);

int searchStack(Stack *s, int data);
