#include<stdio.h>
#include<string.h>

#define INF 987654321

int graph[201][201] = {0,};
int map[201][201] = {0,};

void Floyd(int N) {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(map[i][k] + map[k][j] < map[i][j]) {
                    if(i != k) graph[i][j] = graph[i][k];
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main() {
    int N, M, A, B, C;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i != j) map[i][j] = INF;
        }
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        graph[B][A] = A;
        graph[A][B] = B;
        map[B][A] = C;
        map[A][B] = C;
    }
    Floyd(N);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            graph[i][j] ? printf("%d ", graph[i][j]) : printf("- ");
        }
        printf("\n");
    }
}