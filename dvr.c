#include <stdio.h>
#include <limits.h>
#define N 10
#define INF INT_MAX

void dvr(int c[N][N], int n) {
    int d[N], v[N];
    for (int i = 0; i < n; i++) {
        d[i] = c[0][i];
        v[i] = (d[i] != INF && i != 0) ? i : -1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i] > c[0][k] + c[k][i] && c[0][k] != INF && c[k][i] != INF) {
                d[i] = c[0][k] + c[k][i];
                v[i] = k;
            }
        }
    }
    printf("Node\tDist\tVia\n");
    for (int i = 0; i < n; i++) {
        if (d[i] == INF)
            printf("%d\tINF\t-\n", i);
        else
            printf("%d\t%d\t%d\n", i, d[i], v[i]);
    }
}

int main() {
    int n, c[N][N];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix (-1 for INF):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == -1)
                c[i][j] = INF;
        }
    dvr(c, n);
    return 0;
}
