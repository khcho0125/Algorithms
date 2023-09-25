#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1001
#define M_MAX 100001
#define Q_MAX 200000
#define INF 987654321

typedef enum Type {
    SELECT = 'E',
    INSERT = 'U'
}T;

typedef struct Line {
    int u, v;
}L;

typedef struct Query {
    char t;
    int p;
}Q;

typedef struct Edge {
    int v;
    struct Edge* link;
}E;

typedef struct Node {
    E* link;
    E* back;
}N;

L line[M_MAX];
bool not_init[M_MAX];

Q query[Q_MAX];
int result[Q_MAX];

N graph[N_MAX];
int dist[N_MAX];

int queue[N_MAX];

void makeEdge(int s, int t) {
    E* stot = (E*)malloc(sizeof(E));
    stot->v = t;
    stot->link = NULL;

    if(graph[s].link == NULL) graph[s].link = stot;
    else graph[s].back->link = stot;
    graph[s].back = stot;
}

void bfs(int idx) {
    int front = 0, rear = 0;
    queue[rear++] = idx;
    
    while(front < rear) {
        int u = queue[front++];

        for(E* prev = graph[u].link; prev != NULL; prev = prev->link) {
            if(dist[u] + 1 < dist[prev->v]) {
                dist[prev->v] = dist[u] + 1;
                queue[rear++] = prev->v;
            }
        }
    }
}

void connect(int p) {
    makeEdge(line[p].u, line[p].v);

    if(dist[line[p].u] + 1 < dist[line[p].v]) {
        dist[line[p].v] = dist[line[p].u] + 1;
        bfs(line[p].v);
    }
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &line[i].u, &line[i].v);
    }
    for(int i = 0; i < q; i++) {
        scanf(" %c %d", &query[i].t, &query[i].p);
        if(query[i].t == INSERT) not_init[query[i].p] = true;
    }

    dist[1] = 0;
    for(int i = 2; i <= n; i++) dist[i] = INF;
    for(int i = 1; i <= m; i++) if(!not_init[i]) connect(i);

    for(int i = q - 1; i >= 0; i--) {
        switch(query[i].t) {
            case INSERT:
                connect(query[i].p);
                break;
            case SELECT:
                result[i] = (dist[query[i].p] == INF ? -1 : dist[query[i].p]);
                break;
        }
    }

    for(int i = 0; i < q; i++) {
        if(query[i].t == SELECT) printf("%d\n", result[i]);
    }
}