#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 10
#define INF 1001

#define abs(a) ((a) > 0 ? a : (a) * -1)
#define min(a, b) ((a) < (b) ? a : b)

int person[N_MAX];
int graph[N_MAX];
int N;

int dp[1 << N_MAX];

void DFS(int path, int visited, int sum) {
    if(dp[visited] != -1) return;

    dp[visited] = sum;

    for(int i = 0; i < N; i++) if((path & (1 << i)) && !(visited & (1 << i))) {
        DFS(path | graph[i], visited | (1 << i), sum + person[i]);
    }
}

int main() {
    int M, num;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &person[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &M);
        for(int e = 0; e < M; e++) {
            scanf("%d", &num);
            graph[i] |= (1 << (num - 1));
        }
    }

    memset(dp, -1, sizeof(dp));
    for(int v = 0; v < N; v++) {
        DFS(graph[v], 1 << v, person[v]);
    }

    int result = INF;
    for(int i = 1; i < (1 << N) - 1; i++) {
        if(dp[i] != -1 && dp[(1 << N) - 1 - i] != -1) {
            int value = abs(dp[i] - dp[(1 << N) - 1 - i]);
            result = min(result, value);
        }
    }

    printf("%d", result == INF ? -1 : result);
}