#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define V_MAX 1001

#define INF 987654321
#define undefine -1
#define min(a, b) ((a) < (b) ? a : b)

int graph[V_MAX + V_MAX][V_MAX + V_MAX];

int capacity[V_MAX + V_MAX][V_MAX + V_MAX];
int flow[V_MAX + V_MAX][V_MAX + V_MAX];

int queue[V_MAX * V_MAX];
int dist[V_MAX + V_MAX];
int visited[V_MAX + V_MAX];
bool inQ[V_MAX + V_MAX];

void spfa(int v) {
    memset(inQ, false, sizeof(inQ));
    memset(visited, undefine, sizeof(visited));

    int front = 0, back = 0;
    
    for(int i = 1; i <= v; dist[i++] = INF); 

    dist[0] = 0;
    queue[back++] = 0;
    while(front < back) {
        int u = queue[front++];
        inQ[u] = false;
        for(int i = 0; i <= v; i++) {
            if(capacity[u][i] - flow[u][i] > 0 && dist[i] > graph[u][i] + dist[u]) {
                dist[i] = graph[u][i] + dist[u];
                visited[i] = u;
                if(!inQ[i]) {
                    queue[back++] = i;
                    inQ[i] = true;
                }
            }
        }
    }
}

int mcmf(int source, int sink) {
    int cost = 0;
    while(true) {
        spfa(sink);

        if(visited[sink] == undefine) break;

        for(int i = sink; i != source; i = visited[i]) {
            cost += graph[visited[i]][i];
            flow[visited[i]][i]++;
            flow[i][visited[i]]--;
        }
    }

    return cost;
}

int main() {
    int v, e, a, b, c;
    while(~scanf("%d %d", &v, &e)) {
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));

        for(int i = 0; i < v * 2; i++)
            for(int j = 0; j < v * 2; j++)
                graph[i][j] = INF;

        for(int i = 0; i < v; i++) {
            graph[i * 2][i * 2 + 1] = 0;
            graph[i * 2 + 1][i * 2] = 0;
        }

        capacity[0][1] = 2;
        capacity[(v - 1) * 2][v * 2 - 1] = 2;
        for(int i = 1; i < v - 1; i++) {
            capacity[i * 2][i * 2 + 1] = 1;
        }

        for(int i = 0; i < e; i++) {
            scanf("%d %d %d", &a, &b, &c);
            --a, --b;
            graph[a * 2 + 1][b * 2] = c;
            graph[b * 2][a * 2 + 1] = -c;
            capacity[a * 2 + 1][b * 2] = 1;
        }

        printf("%d\n", mcmf(0, v * 2 - 1));
    }
}