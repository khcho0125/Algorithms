#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INF (1LL << 31) - 1
#define N_MAX 10001
#define M_MAX 1000001

typedef struct Edge {
    int v, w;
    struct Edge *link;
}E;

typedef struct Vertex {
    int cnt;
    E *link, *back;
}V;

V graph[N_MAX];

void makeEdge(int u, int v, int w) {
    E* utov = (E*)malloc(sizeof(E));
    utov->link = NULL;
    utov->v = v;
    utov->w = w;

    if(graph[u].link == NULL) graph[u].link = utov;
    else graph[u].back->link = utov;
    graph[u].back = utov;
}

typedef struct Pair {
    int v, w;
}P;

int dist[N_MAX];
P queue[M_MAX];
int temp;

void pushQ(int v, int w) {
    int p = ++temp;
    while(p != 1 && w < queue[p / 2].w) {
        queue[p] = queue[p / 2];
        p /= 2;
    }
    queue[p] = (P){.v = v, .w = w};
}

P popQ() {
    P top = queue[1];
    P last = queue[temp--];
    
    int parent = 1, child = 2;
    while(child <= temp) {
        if(child + 1 <= temp && queue[child + 1].w < queue[child].w) child++;
        if(last.w <= queue[child].w) break;

        queue[parent] = queue[child];
        parent = child;
        child *= 2;
    }
    queue[parent] = last;
    return top;
}

void dijkstra(int n) {
    temp = 0;
    dist[1] = 0;
    for(int i = 2; i <= n; i++) dist[i] = INF;
    
    pushQ(1, 0);
    while(temp) {
        P node = popQ();

        if(dist[node.v] < node.w) continue;

        for(E* cur = graph[node.v].link; cur != NULL; cur = cur->link) {
            if(dist[cur->v] == node.w + cur->w) graph[cur->v].cnt++;

            if(dist[cur->v] > node.w + cur->w) {
                graph[cur->v].cnt = 1;
                dist[cur->v] = node.w + cur->w;
                pushQ(cur->v, node.w + cur->w);
            }
        }
    }
}

int path[N_MAX];

bool solution(int N, int K) {
    dijkstra(N);

    for(int i = 1; i < K; i++) {
        if(graph[path[i]].cnt > 1) return true;
    }

    return false;
}

int main() {
    int N, M, K, a, b, c;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < K; i++) {
        scanf("%d", &path[i]);
    }

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        makeEdge(a, b, c);
        makeEdge(b, a, c);
    }

    printf(solution(N, K) ? "yes" : "no");
}