#include <stdio.h>
#include <string.h>
#include <math.h>

#define IN 99
#define N 6

int dijkstra(int cost[][N], int source, int target);

int main() {
    int cost[N][N], i, j, w, co, source, target;
    printf("\tDIJKSTRA'S ALGORITHM\n\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cost[i][j] = IN;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            printf("Enter the weight of the path between nodes %d and %d: ", i, j);
            scanf("%d", &w);
            cost[i][j] = cost[j][i] = w;
        }
        printf("\n");
    }

    printf("Enter the source: ");
    scanf("%d", &source);
    printf("Enter the target: ");
    scanf("%d", &target);

    co = dijkstra(cost, source, target);
    printf("\nThe Shortest Path: %d\n", co);

    return 0;
}
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int dijkstra(int cost[][N], int source, int target) {
    int dist[N], prev[N], selected[N] = {0};
    int i, m, min, start, d, j;
    char path[N];

    for (i = 0; i < N; i++) {
        dist[i] = IN;
        prev[i] = -1;
    }

    start = source;
    selected[start] = 1;
    dist[start] = 0;

    while (selected[target] == 0) {
        min = IN;
        m = 0;

        for (i = 0; i < N; i++) {
            d = dist[start] + cost[start][i];
            if (d < dist[i] && selected[i] == 0) {
                dist[i] = d;
                prev[i] = start;
            }

            if (min > dist[i] && selected[i] == 0) {
                min = dist[i];
                m = i;
            }
        }

        start = m;
        selected[start] = 1;
    }

    start = target;
    j = 0;

    while (start != -1) {
        path[j++] = start + 65;
        start = prev[start];
    }

    path[j] = '\0';
    reverse(path);

    printf("\nShortest Path: %s", path);

    return dist[target];
}
