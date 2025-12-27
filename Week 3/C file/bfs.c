#include <stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20];
int adj[20][20];
int n;

void bfs(int start) {
    int i;
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (i = 0; i < n; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start);

    return 0;
}

