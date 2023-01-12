#include "defs.h"

List createNode(int data) {
    List node = (List) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}