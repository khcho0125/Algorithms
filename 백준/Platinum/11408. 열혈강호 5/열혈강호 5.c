#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define N_MAX 401
#define INF 987654321

int salary[N_MAX * 2][N_MAX * 2];
int capacity[N_MAX * 2][N_MAX * 2];
int flow[N_MAX * 2][N_MAX * 2];

int visited[N_MAX * 2];
int dist[N_MAX * 2];

int queue[N_MAX * N_MAX];
bool state[N_MAX * 2];

int N, M;

void spfa(int source, int sink) {
    int front = 0, rear = 0;
    memset(state, 0, sizeof(state));
    memset(visited, -1, sizeof(visited));

    dist[0] = 0;
    for(int i = 1; i <= N + M + 1; dist[i++] = INF);

    queue[rear++] = source;
    while(front < rear) {
        int u = queue[front++];
        state[u] = false;

        for(int v = 1; v <= N + M + 1; v++) {
            if(capacity[u][v] - flow[u][v] > 0 && dist[v] > dist[u] + salary[u][v]) {
                dist[v] = dist[u] + salary[u][v];
                visited[v] = u;

                if(!state[v]) {
                    queue[rear++] = v;
                    state[v] = true;
                }
            }
        }
    }
}

void mcmf(int source, int sink) {
    int maxflow = 0, mincost = 0;
    
    while(true) {
        spfa(source, sink);

        if(visited[sink] == -1) break;

        maxflow++;
        for(int i = sink; i != source; i = visited[i]) {
            mincost += salary[visited[i]][i];
            flow[visited[i]][i]++;
            flow[i][visited[i]]--;
        }
    }

    printf("%d\n%d", maxflow, mincost);
}

int main() {
    int c, w, s;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; capacity[0][i++] = 1); 
    for(int i = N + 1; i <= N + M; capacity[i++][N + M + 1] = 1);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d %d", &w, &s);
            salary[i][N + w] = s;
            salary[N + w][i] = -s;
            capacity[i][N + w] = 1;
        }
    }

    mcmf(0, N + M + 1);
}