#include <stdio.h>

#define MAX 100

int visited[MAX];

void dfs(int adj[MAX][MAX], int n, int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(adj, n, i);
        }
    }
}

int main() {
    int n, start = 0, count = 0;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(adj, n, start);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            count++;
    }

    if (count == n)
        printf("Graph is Connected");
    else
        printf("Graph is Not Connected");

    return 0;
}
