#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define N_MAX 1001

bool graph[N_MAX][N_MAX + N_MAX];
int manager[N_MAX + N_MAX];
int visited[N_MAX];
int N, M, K;

bool dfs(int idx, int turn) {
    if(visited[idx] == turn) {
        return false;
    }

    visited[idx] = turn;

    for(int i = 1; i <= N + K; i++) if(graph[idx][i]) {
        if(manager[i] == -1 || dfs(manager[i], turn)) {
            manager[i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(manager, -1, sizeof(manager));
    int result = 0;

    for(int i = 1; i <= M; i++) {
        result += dfs(i, i);
    }

    return result;
}

int main() {
    int c, w;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &w);
            graph[w][i] = true;
            for(int k = N + 1; k <= N + K; k++) graph[w][k] = true;
        }
    }

    printf("%d", bipartite());
}