#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define MAX 200000
#define max(a, b) (((a) > (b)) ? a : b)
#define swap(a, b) {int i = a; a = b; b = i;}

typedef struct node {
    int v1;
    int v2;
    ll weight;
} node;

typedef struct graf {
    int V;
    int W;
    struct graf* link;  
}G;

typedef struct Tree {
    G* link;
    G* back;
}tree;

typedef struct W {
    int idx;
    ll weight;
}W;

int UnionFind[MAX + 1];

node N[MAX];
node NUM[MAX];
W Parent[20][MAX + 1];
int depth[MAX + 1];
tree T[MAX + 1];

int pre = 0;
ll real = 0;

int compare(const void *a, const void *b)
{
    node num1 = *(node *)a;
    node num2 = *(node *)b;

    if (num1.weight > num2.weight)
    {
        return 1;
    }

    if (num1.weight < num2.weight)
    {
        return -1;
    }

    return 0;
}

int find(int x)
{
    if (UnionFind[x] < 0)
    {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

int Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return 0;
    }

    if (UnionFind[x] < UnionFind[y])
    {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
    }
    else
    {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
    }
    return 1;
}

int DFS(int idx) {
    G* query = (G*)malloc(sizeof(G));
    query = T[idx].link;
    while(query != NULL) {
        if(depth[query->V] == -1) {
            depth[query->V] = depth[idx] + 1;
            Parent[0][query->V].idx = idx;
            Parent[0][query->V].weight = query->W;
            DFS(query->V);
        }
        query = query->link;
    }
}

int LCA(int E, int V) {
    memset(depth, -1, sizeof(depth));
    memset(Parent, -1, sizeof(Parent));
    depth[1] = 0;
    DFS(1);
    for(int i = 0; i < 19; i++) {
        for(int j = 1; j <= V; j++) {
            if(Parent[i][j].idx != -1) {
                Parent[i + 1][j].idx = Parent[i][Parent[i][j].idx].idx;
                Parent[i + 1][j].weight = max(Parent[i][Parent[i][j].idx].weight, Parent[i][j].weight);
            }
        }
    }

    for(int i = 0; i < E; i++) {
        int u = NUM[i].v1;
        int v = NUM[i].v2;
        ll w = NUM[i].weight;

        if(depth[u] < depth[v]) swap(u, v);
        int d = depth[u] - depth[v];
        ll res = 0;

        for(int k = 0; d; k++) {
            if(d % 2) {
                res = max(res, Parent[k][u].weight);
                u = Parent[k][u].idx;
            }
            d /= 2;
        }

        if(u != v) {

            for(int k = 19; k >= 0; k--) {
                if(Parent[k][u].idx != -1 && Parent[k][u].idx != Parent[k][v].idx) {
                    res = max(res, max(Parent[k][u].weight, Parent[k][v].weight));

                    u = Parent[k][u].idx;
                    v = Parent[k][v].idx;
                }
            }

            res = max(res, max(Parent[0][v].weight, Parent[0][u].weight));
        }

        printf("%lld\n", real - res + w);
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 1; i <= V; i++) {
        UnionFind[i] = -1;
        T[i].link = NULL;
    }
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %lld", &N[i].v1, &N[i].v2, &N[i].weight);
        NUM[i] = N[i];
    }
    qsort(N, E, sizeof(node), compare);
    for (int i = 0, temp = 0; i < E && temp != V - 1; i++)
    {
        if (Union(N[i].v1, N[i].v2)) {
            real += N[i].weight;
            temp++;
            G* one = (G*)malloc(sizeof(G));
            one->V = N[i].v2;
            one->W = N[i].weight;
            one->link = NULL;
            if(T[N[i].v1].link == NULL) {
                T[N[i].v1].link = one;
                T[N[i].v1].back = one;
            }
            else {
                T[N[i].v1].back->link = one;
                T[N[i].v1].back = one;
            }
            G* two = (G*)malloc(sizeof(G));
            two->V = N[i].v1;
            two->W = N[i].weight;
            two->link = NULL;
            if(T[N[i].v2].link == NULL) {
                T[N[i].v2].link = two;
                T[N[i].v2].back = two;
            }
            else {
                T[N[i].v2].back->link = two;
                T[N[i].v2].back = two;
            }
        }
    }
    LCA(E, V);
}