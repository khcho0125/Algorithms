#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define swap(a, b) {int i = a; a = b; b = i;}

typedef struct node {
    int v;
    struct node* link;
}node;

typedef struct Tree {
    node* link;
    node* back;
}tree;

int parent[17][50001] = {0,};
int depth[50001] = {0,};
tree T[50001];

void DFS(int idx) {
    node* query = (node*)malloc(sizeof(node));
    query = T[idx].link;
    while(query != NULL) {
        if(!depth[query->v]) {
            depth[query->v] = depth[idx] + 1;
            parent[0][query->v] = idx;
            DFS(query->v);
        }
        query = query->link;
    }
}

int main() {
    int N, M, u, v;
    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
        T[i].link = NULL;
    }
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %d", &u, &v);
        node* one = (node*)malloc(sizeof(node));
        one->v = v;
        one->link = NULL;
        if(T[u].link == NULL) {
            T[u].link = one;
            T[u].back = one;
        }
        else {
            T[u].back->link = one;
            T[u].back = one;
        }
        node* two = (node*)malloc(sizeof(node));
        two->v = u;
        two->link = NULL;
        if(T[v].link == NULL) {
            T[v].link = two;
            T[v].back = two;
        }
        else {
            T[v].back->link = two;
            T[v].back = two;
        }
    }
    depth[1] = 1;
    DFS(1);
    for(int i = 0; i < 16; i++) {
        for(int j = 1; j <= N; j++) {
            if(parent[i][j] != 0) {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);

        if(depth[u] < depth[v]) swap(u, v);
        int sub = depth[u] - depth[v];

        for(int k = 0; sub; k++) {
            if(sub % 2) u = parent[k][u];
            sub /= 2;
        }

        if(u != v) {
            for(int k = 16; k >= 0; k--) {
                if(parent[k][u] != 0 && parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            u = parent[0][u];
        }
        printf("%d\n", u);
    }
}