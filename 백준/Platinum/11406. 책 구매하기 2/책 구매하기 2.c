#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 101
#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)

int capacity[N_MAX * 2][N_MAX * 2];
int flow[N_MAX * 2][N_MAX * 2];
int layer[N_MAX * 2];
int work[N_MAX * 2];

int queue[N_MAX * N_MAX];
int front, rear;

bool bfs(int source, int sink) {
    memset(layer, -1, sizeof(layer));
    front = rear = 0;

    queue[rear++] = source;
    layer[source] = 0;

    while(front < rear) {
        int u = queue[front++];

        for(int v = 1; v <= sink; v++) {
            if(layer[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                layer[v] = layer[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    return layer[sink] != -1;
}

int dfs(int idx, int amount, int sink) {
    if(idx == sink) return amount;

    for(; work[idx] <= sink; work[idx]++) {
        if(layer[work[idx]] == layer[idx] + 1 && capacity[idx][work[idx]] - flow[idx][work[idx]] > 0) {
            int result = dfs(work[idx], min(amount, capacity[idx][work[idx]] - flow[idx][work[idx]]), sink);

            if(result > 0) {
                flow[idx][work[idx]] += result;
                flow[work[idx]][idx] -= result;

                return result;
            }
        }
    }

    return 0;
}

int maxflow(int source, int sink) {
    int result = 0;

    while(bfs(source, sink)) {
        memset(work, 0, sizeof(work));

        while(true) {
            int book = dfs(source, INF, sink);

            if(!book) break;

            result += book;
        }
    }

    return result;
}

int main() {
    int N, M, A, B, C;
    scanf("%d %d", &N, &M);

    int source = 0, sink = N + M + 1;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A);
        capacity[M + i][sink] = A;
    }
    for(int i = 1; i <= M; i++) {
        scanf("%d", &B);
        capacity[source][i] = B;
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &C);
            capacity[i][M + j] = C;
        }
    }
    printf("%d", maxflow(source, sink));
}