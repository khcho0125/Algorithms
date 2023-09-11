#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1001

bool graph[N_MAX][N_MAX];
int manager[N_MAX];
int visited[N_MAX];
int N, M;

bool dfs(int idx, int turn) {
    if(visited[idx] == turn) {
        return false;
    }

    visited[idx] = turn;

    for(int i = 1; i <= M; i++) {
        if(graph[idx][i] && (manager[i] == -1 || dfs(manager[i], turn))) {
            manager[i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(manager, -1, sizeof(manager));
    int result = 0;

    for(int i = 1; i <= N; i++) {
        result += dfs(i, i);
    }

    return result;
}

int main() {
    int WN, W;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &WN);
        for(int j = 0; j < WN; j++) {
            scanf("%d", &W);
            graph[i][W] = true;
        }
    }

    printf("%d", bipartite());
}