#include<stdio.h>
#include<stdlib.h>

#define INF 10001
#define min(a, b) (a < b ? a : b)

typedef struct Edge {
    int v;
    struct Edge* link;
}Edge;

typedef struct Vertex {
    Edge* link;
    Edge* back;
}Vertex;

Vertex graph[10001];
int visit[10001] = {0,};
int CC[10001] = {0,};
int ans = 0, pre;

void DFS(int idx) {
    int count = 0, dist = INF;
    Edge* temp = (Edge*)malloc(sizeof(Edge));
    temp = graph[idx].link;

    while(temp != NULL) {
        if(!visit[temp->v]) {
            count++;
            visit[temp->v] = pre++;
            DFS(temp->v);
            if(visit[idx] != 1 && !CC[idx] && visit[temp->v] >= visit[idx]) {
                CC[idx] = 1;
                ans++;
            }
        }
        dist = min(dist, visit[temp->v]);
        temp = temp->link;
    }

    if(visit[idx] == 1 && count > 1) {
        CC[idx] = 1;
        ans++;
    }

    visit[idx] = dist;
}

int main() {
    int V, E, v1, v2;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &v1, &v2);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = v2;
        if(graph[v1].link == NULL) {
            graph[v1].link = one;
        }
        else {
            graph[v1].back->link = one;
        }
        graph[v1].back = one;

        Edge* two = (Edge*)malloc(sizeof(Edge));
        two->v = v1;
        two->link = NULL;
        if(graph[v2].link == NULL) {
            graph[v2].link = two;
        }
        else {
            graph[v2].back->link = two;
        }
        graph[v2].back = two;
    }

    for(int i = 1; i <= V; i++) {
        if(!visit[i]) {
            pre = 1;
            visit[i] = pre++;
            DFS(i);
        }
    }

    printf("%d\n", ans);
    for(int i = 1; i <= V; i++) {
        if(CC[i]) printf("%d ", i);
    }
}