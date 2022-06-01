#include<stdio.h>
#include<stdlib.h>

typedef struct Edge {
    int v;
    struct Edge* link;
}Edge;

typedef struct Tree {
    Edge* link;
    Edge* back;
    int visit;
    int cnt;
}Tree;

Tree graph[100001];
int result = 0;

void DFS(int idx) {
    if(graph[idx].cnt == 0) {
        result = 1;
        return;
    }
    graph[idx].visit = 1;
    Edge* connect = (Edge*)malloc(sizeof(Edge));
    connect = graph[idx].link;
    while(connect != NULL && !result) {
        if(!graph[connect->v].visit) {
            DFS(connect->v);
        }
        connect = connect->link;
    }
}

int main() {
    int N, M, u, v, S, s;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = v;
        if(graph[u].link == NULL) {
            graph[u].link = one;
        }
        else {
            graph[u].back->link = one;
        }
        graph[u].back = one;
        graph[u].cnt++;
    }
    scanf("%d", &S);
    for(int i = 0; i < S; i++) {
        scanf("%d", &s);
        graph[s].visit = 1;
    }

    if(!graph[1].visit) DFS(1);

    printf(result ? "yes" : "Yes");
}