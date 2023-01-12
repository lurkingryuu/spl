#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node* List;

List createNode(int data) {
    List node = (List) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

typedef struct queue {
    List head;
    List tail;
} Queue;

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

typedef struct stack {
    List head;
} Stack;

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

void printQueue(Queue *q, char *label) {
    List node = q->head;
    printf("%s: ", label);
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Priority Queue
typedef struct priorityQueue {
    List head;
} PriorityQueue;

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

void bfs(int **adj, int nodes, int start){
    Queue *visited = createQueue(), *exploration = createQueue();
    int i, k;
    enqueue(visited, start);
    enqueue(exploration, start);
    while(exploration->head != NULL)
    {
        k = dequeue(exploration);
        for(i = 0; i < nodes; i++){
            if(adj[k][i] == 1){
                if(searchQueue(visited, i) == 0){
                    enqueue(visited, i);
                    enqueue(exploration, i);
                }
            }
        }
    }
    printQueue(visited, "BFS");
}

void dfs(int **adj, int nodes, int start){
    Queue *visited = createQueue();
    Stack *exploration = createStack();
    int i, k;
    push(exploration, start);
    while(exploration->head != NULL)
    {
        k = pop(exploration);
        if(searchQueue(visited, k) == 0){
            enqueue(visited, k);
        }

        for(i = 0; i < nodes; i++){
            if(adj[k][i] == 1){
                if(searchQueue(visited, i) == 0){
                    push(exploration, i);
                }
            }
        }
    }
    printQueue(visited, "DFS");
}

void dfs_recursion_helper(int **adj, int nodes, int start, Queue *visited){
    int i;
    if(searchQueue(visited, start) == 0){
        enqueue(visited, start);
    }
    for(i = 0; i < nodes; i++){
        if(adj[start][i] == 1){
            if(searchQueue(visited, i) == 0){
                dfs_recursion_helper(adj, nodes, i, visited);
            }
        }
    }
}



void dfs_rec(int **adj, int nodes, int start){
    Queue *visited = createQueue();
    dfs_recursion_helper(adj, nodes, start, visited);
    printQueue(visited, "DFS");
}


void dijkstra(int **adj, int nodes, int start){
    int i, k;
    int *distance = (int *) malloc(sizeof(int) * nodes);
    int *visited = (int *) malloc(sizeof(int) * nodes);
    for(i = 0; i < nodes; i++){
        distance[i] = 999999;
        visited[i] = 0;
    }
    distance[start] = 0;
    PriorityQueue *pq = createPriorityQueue();
    enqueuePriority(pq, start);
    while(pq->head != NULL)
    {
        k = dequeuePriority(pq);
        visited[k] = 1;
        for(i = 0; i < nodes; i++){
            if(adj[k][i]){
                if(visited[i] == 0){
                    if(distance[i] > distance[k] + adj[k][i]){
                        distance[i] = distance[k] + adj[k][i];
                        enqueuePriority(pq, i);
                    }
                }
            }
        }
    }
    for(i = 0; i < nodes; i++){
        printf("Distance from %d to %d: %d", start, i, distance[i]);
    }
}

void prim(int **adj, int nodes, int start){
    int i, k;
    int *distance = (int *) malloc(sizeof(int) * nodes);
    int *visited = (int *) malloc(sizeof(int) * nodes);
    for(i = 0; i < nodes; i++){
        distance[i] = 999999;
        visited[i] = 0;
    }
    distance[start] = 0;
    PriorityQueue *pq = createPriorityQueue();
    enqueuePriority(pq, start);
    while(pq->head != NULL)
    {
        k = dequeuePriority(pq);
        visited[k] = 1;
        for(i = 0; i < nodes; i++){
            if(adj[k][i]){
                if(visited[i] == 0){
                    if(distance[i] > adj[k][i]){
                        distance[i] = adj[k][i];
                        enqueuePriority(pq, i);
                    }
                }
            }
        }
    }
    int sum = 0;
    for(i = 0; i < nodes; i++){
        sum += distance[i];
    }
    printf("MST: %d", sum);
}

void kruskal(int **adj, int nodes, int start){
    int i, j, k;
    int *distance = (int *) malloc(sizeof(int) * nodes);
    int *visited = (int *) malloc(sizeof(int) * nodes);
    for(i = 0; i < nodes; i++){
        distance[i] = 999999;
        visited[i] = 0;
    }
    distance[start] = 0;
    PriorityQueue *pq = createPriorityQueue();
    enqueuePriority(pq, start);
    while(pq->head != NULL)
    {
        k = dequeuePriority(pq);
        visited[k] = 1;
        for(i = 0; i < nodes; i++){
            if(adj[k][i]){
                if(visited[i] == 0){
                    if(distance[i] > adj[k][i]){
                        distance[i] = adj[k][i];
                        enqueuePriority(pq, i);
                    }
                }
            }
        }
    }
    int sum = 0;
    for(i = 0; i < nodes; i++){
        sum += distance[i];
    }
    printf("MST: %d", sum);
}

int main(){
    int n = 7, **adj, i, j;
    int arr[7][7] = {{0, 1, 1, 1, 0, 0, 0}, 
                     {1, 0, 1, 0, 0, 0, 0},
                     {1, 1, 0, 1, 1, 0, 0},
                     {1, 0, 1, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};
    
    adj = (int**) malloc(n * sizeof(int*));
    for(i = 0; i < n; i++){
        adj[i] = (int*) malloc(n * sizeof(int));
        for(j = 0; j < n; j++){
            adj[i][j] = arr[i][j];
        }
    }

    
    // dfs(adj, n, 0);
    // dfs_rec(adj, n, 0);

    // priority queue
    PriorityQueue *pq = createPriorityQueue();
    enqueuePriority(pq, 5);
    enqueuePriority(pq, 3);
    enqueuePriority(pq, 1);
    enqueuePriority(pq, 4);
    enqueuePriority(pq, 2);
    printPriorityQueue(pq, "Priority Queue");
    

    return 0;
}