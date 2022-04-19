#include<stdio.h>
#include<stdlib.h>

#define swap(a, b) {int i = a; a = b; b = i;}
#define ll long long

typedef struct node {
    int idx;
    ll w;
    struct node* link;
}node;

typedef struct Tree {
    node* link;
    node* back;
}T;

typedef struct Family {
    int v;
    ll w;
}F;

T tree[40001];
int depth[40001] = {0,};
F parent[17][40001] = {0,};

void DFS(int idx) {
    node* query = (node*)malloc(sizeof(node));
    query = tree[idx].link;
    while(query != NULL) {
        if(!depth[query->idx]) {
            parent[0][query->idx].v = idx;
            parent[0][query->idx].w = query->w;
            depth[query->idx] = depth[idx] + 1;
            DFS(query->idx);
        }
        query = query->link;
    }
}

int main() {
    int N, u, v, E;
    ll w;
    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
        scanf("%d %d %lld", &u, &v, &w);
        node* one = (node*)malloc(sizeof(node));
        one->idx = v;
        one->link = NULL;
        one->w = w;
        if(tree[u].link == NULL) {
            tree[u].link = one;
            tree[u].back = one;
        }
        else {
            tree[u].back->link = one;
            tree[u].back = one;
        }
        node* two = (node*)malloc(sizeof(node));
        two->idx = u;
        two->link = NULL;
        two->w = w;
        if(tree[v].link == NULL) {
            tree[v].link = two;
            tree[v].back = two;
        }
        else {
            tree[v].back->link = two;
            tree[v].back = two;
        }
    }
    depth[1] = 1;
    DFS(1);
    for(int i = 0; i < 16; i++) {
        for(int j = 1; j <= N; j++) {
            if(parent[i][j].v) {
                parent[i + 1][j].v = parent[i][parent[i][j].v].v;
                parent[i + 1][j].w = parent[i][parent[i][j].v].w + parent[i][j].w;
            }
        }
    }

    scanf("%d", &E);
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        if(depth[u] < depth[v]) swap(u, v);
        int tmp = depth[u] - depth[v];
        ll sum = 0;

        for(int k = 0; tmp; k++) {
            if(tmp % 2) {
                sum += parent[k][u].w;
                u = parent[k][u].v;
            }
            tmp /= 2;
        }

        if(u != v) {
            for(int k = 16; k >= 0; k--) {
                if(parent[k][u].v && parent[k][u].v != parent[k][v].v) {
                    sum += parent[k][u].w + parent[k][v].w;
                    u = parent[k][u].v;
                    v = parent[k][v].v;
                }
            }

            sum += parent[0][v].w + parent[0][u].w;
        }

        printf("%lld\n", sum);
    }
}