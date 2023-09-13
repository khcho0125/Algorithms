#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 101
#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)

int capacity[N_MAX * 2][N_MAX * 2];
int flow[N_MAX * 2][N_MAX * 2];
int charge[N_MAX * 2][N_MAX * 2];

int queue[N_MAX * N_MAX];
int visited[N_MAX * 2];
int dist[N_MAX * 2];
bool inQueue[N_MAX * 2];

void spfa(int source, int sink) {
    memset(visited, -1, sizeof(visited));

    for(int i = 0; i <= sink; i++) dist[i] = INF;
    dist[source] = 0;

    int front = 0, rear = 0, u;
    queue[rear++] = source;
    while(front < rear) {
        u = queue[front++];
        inQueue[u] = false;

        for(int v = 1; v <= sink; v++) {
            if(capacity[u][v] - flow[u][v] > 0 && dist[v] > dist[u] + charge[u][v]) {
                dist[v] = dist[u] + charge[u][v];
                visited[v] = u;

                if(!inQueue[v]) {
                    queue[rear++] = v;
                    inQueue[v] = true;
                }
            }
        }
    }
}

int mcmf(int source, int sink) {
    int result = 0, book = INF;

    while(true) {
        spfa(source, sink);

        if(visited[sink] == -1) break;

        for(int i = sink; i != source; i = visited[i]) {
            book = min(book, capacity[visited[i]][i] - flow[visited[i]][i]);
        }

        for(int i = sink; i != source; i = visited[i]) {
            result += book * charge[visited[i]][i];
            flow[visited[i]][i] += book;
            flow[i][visited[i]] -= book;
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
            charge[i][M + j] = C;
            charge[M + j][i] = -C;
            capacity[i][M + j] = INF;
        }
    }
    
    printf("%d", mcmf(source, sink));
}