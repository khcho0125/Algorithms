#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1000

bool network[N_MAX][N_MAX];

int connectBy[N_MAX];
int visited[N_MAX];

bool dfs(int idx, int turn, int N) {

    if(visited[idx] == turn) return false;

    visited[idx] = turn;

    for(int i = 0; i < N; i++) {
        if(network[idx][i] && (connectBy[i] == -1 || dfs(connectBy[i], turn, N))) {
            connectBy[i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite(int N) {
    memset(connectBy, -1, sizeof(connectBy));
    memset(visited, 0, sizeof(visited));

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dfs(i, i + 1, N);
    }

    return ans;
}

int main() {
    int T, n, m, u, v;
    scanf("%d", &T);
    while(T--) {
        memset(network, 0, sizeof(network));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            network[u][v] = true;
        }

        printf("%d\n", bipartite(n));
    }
}