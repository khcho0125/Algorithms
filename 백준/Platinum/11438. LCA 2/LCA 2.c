#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define swap(a, b) {int i = a; a = b; b = i;}

typedef struct node {
    int V;
    struct node* link;
}node;

typedef struct Tree {
    node* link;
    node* back;
}tree;

int N, M;
int parent[18][MAX];
int depth[MAX];
tree list[MAX];

int DFS(int idx) {
    node* query = (node*)malloc(sizeof(node));
    query = list[idx].link;
    while(query != NULL) {
        if(depth[query->V] == -1) {
            parent[0][query->V] = idx;
            depth[query->V] = depth[idx] + 1;
            DFS(query->V);
        }
        query = query->link;
    }
}

int main() {
    int v, u;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        depth[i] = -1;
        list[i].link = NULL;
    }
    depth[0] = 0;
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %d", &v, &u);
        --v, --u;
        node* one = (node*)malloc(sizeof(node));
        one->V = u;
        one->link = NULL;
        if(list[v].link == NULL) {
            list[v].link = one;
            list[v].back = one;
        } else {
            list[v].back->link = one;
            list[v].back = one;
        }
        node* two = (node*)malloc(sizeof(node));
        two->V = v;
        two->link = NULL;
        if(list[u].link == NULL) {
            list[u].link = two;
            list[u].back = two;
        }
        else {
            list[u].back->link = two;
            list[u].back = two;
        }
    }
    memset(parent, -1, sizeof(parent));
    DFS(0);
    for(int i = 0; i < 17; i++) {
        for(int j = 1; j < N; j++) {
            if(parent[i][j] != -1) {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        --u, --v;
        if(depth[u] < depth[v]) swap(u, v);
        int dep = depth[u] - depth[v];

        for(int k = 0; dep; k++) {
            if(dep % 2) u = parent[k][u];
            dep /= 2;
        }

        if(u != v) {

            for(int k = 17; k >= 0; k--) {
                if(parent[k][u] != -1 && parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            u = parent[0][u];
        }

        printf("%d\n", u + 1);
    }
}