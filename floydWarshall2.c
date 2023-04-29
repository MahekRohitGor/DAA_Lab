#include <stdio.h>
#include <limits.h>

#define V 5

void floyd_warshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distance matrix using the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Negative cycle detected!\n");
            return;
        }
    }

    // Print the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, -1, 4, INT_MAX, INT_MAX},
        {INT_MAX, 0, 3, 2, 2},
        {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX},
        {INT_MAX, 1, 5, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -3, 0}
    };

    floyd_warshall(graph);

    return 0;
}
