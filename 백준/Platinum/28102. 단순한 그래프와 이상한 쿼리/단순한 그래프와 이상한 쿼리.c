#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N_MAX 100001

typedef struct Edge {
    int v;
    struct Edge *link;
}E;

typedef struct Vertex {
    bool w;
    E *link;
    E *back;
}V;

V graph[N_MAX];
int visited[N_MAX];
bool existsCycle[N_MAX];

void makeEdge(int u, int v) {
    E* utov = (E*)malloc(sizeof(E));
    utov->link = NULL;
    utov->v = v;

    if(graph[u].link == NULL) graph[u].link = utov;
    else graph[u].back->link = utov;
    graph[u].back = utov;
}

void dfs(int group, int idx, bool w) {
    visited[idx] = group;
    graph[idx].w = w;

    for(E* temp = graph[idx].link; temp != NULL; temp = temp->link) {
        if(!visited[temp->v]) dfs(group, temp->v, !w);
        else if(graph[temp->v].w == w) existsCycle[group] = true;
    }
}

void solution(int N) {
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) dfs(i, i, false);
    }
}

bool existsPath(int a, int b, int k) {
    if(visited[a] != visited[b]) return false;
    if(existsCycle[visited[a]]) return true; 
    
    return (k & 1) || (graph[a].w == graph[b].w);
}

int main() {
    int N, M, Q, u, v, w;
    scanf("%d %d %d", &N, &M, &Q);

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &w);
        makeEdge(u, v);
        makeEdge(v, u);
    }

    solution(N);

    int a, b, k;
    for(int i = 0; i < Q; i++) {
        scanf("%d %d %d", &a, &b, &k);
        printf(existsPath(a, b, k) ? "Yes\n" : "No\n");
    }
}