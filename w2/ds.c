#include "stack.h"
#include "queue.h"
#include "heap.h"

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