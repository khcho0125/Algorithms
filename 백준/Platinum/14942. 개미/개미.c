#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Edge {
    int v;
    int w;
    struct Edge* link;
}Edge;

typedef struct Tree {
    Edge* link;
    Edge* back;
}Tree;

int ant[100001];
int parent[18][100001];
int weight[18][100001] = {0,};
int visit[100001] = {0,};
Tree tree[100001];

void DFS(int idx) {
    Edge* connect = (Edge*)malloc(sizeof(Edge));
    connect = tree[idx].link;
    while(connect != NULL) {
        if(!visit[connect->v]) {
            parent[0][connect->v] = idx;
            weight[0][connect->v] = connect->w;
            visit[connect->v] = 1;
            DFS(connect->v);
        }
        connect = connect->link;
    }
}

int main() {
    int N, v1, v2, w;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &ant[i]);
    }
    for(int i = 1; i < N; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = v2;
        one->w = w;
        if(tree[v1].link == NULL) {
            tree[v1].link = one;
        }
        else {
            tree[v1].back->link = one;
        }
        tree[v1].back = one;

        Edge* two = (Edge*)malloc(sizeof(Edge));
        two->link = NULL;
        two->v = v1;
        two->w = w;
        if(tree[v2].link == NULL) {
            tree[v2].link = two;
        }
        else {
            tree[v2].back->link = two;
        }
        tree[v2].back = two;
    }

    memset(parent, -1, sizeof(parent));
    visit[1] = 1;
    DFS(1);
    for(int i = 0; i < 17; i++) {
        for(int j = 2; j <= N; j++) {
            if(parent[i][j] != -1) {
                parent[i + 1][j] = parent[i][parent[i][j]];
                if(parent[i + 1][j] != -1) weight[i + 1][j] = weight[i][parent[i][j]] + weight[i][j];
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        int k = i;
        for(int j = 17; j >= 0; j--) {
            if(parent[j][k] != -1 && weight[j][k] <= ant[i]) {
                ant[i] -= weight[j][k];
                k = parent[j][k];
            }
        }

        printf("%d\n", k);
    }
}