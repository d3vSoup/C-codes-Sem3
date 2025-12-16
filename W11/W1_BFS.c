#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int adj[MAX][MAX], int n, int start) {
    int i, node;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear && front != -1) {
        node = dequeue();
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(adj, n, start);

    return 0;
}
