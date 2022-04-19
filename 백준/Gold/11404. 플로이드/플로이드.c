#include<stdio.h>
#include<string.h>

#define INF 10000001

int min(int a, int b) {
    return a < b ? a : b;
}

int tree[100][100] = {0,};
int N;

void Floyd(int v) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(tree[i][v] + tree[v][j] < tree[i][j]) {
                tree[i][j] = tree[i][v] + tree[v][j];
            }
        }
    }
}

int main() {
    int M, start, end, weight;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            tree[i][j] = INF;
        }
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        if(tree[start - 1][end - 1] > weight) {
            tree[start - 1][end - 1] = weight;
        }
    }
    for(int i = 0; i < N; i++) {
        Floyd(i);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(tree[i][j] >= INF) {
                printf("0 ");
                continue;
            }
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }
}