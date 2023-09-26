#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define N_MAX 200001
#define max(a, b) ((a) > (b) ? a : b)

enum COMMAND {
    INSERT = 1,
    SELECT = 2
};

typedef struct Edge {
    int v;
    struct Edge *next;
}E;

typedef struct Vertex {
    E* link;
    E* back;
}V;

typedef struct Section {
    int u, v;
}S;

V graph[N_MAX];
S euler[N_MAX];
ll level[N_MAX];
int number = 0;

void makeEdge(int s, int t) {
    E* edge = (E*)calloc(1, sizeof(E));
    edge->v = t;

    if(graph[s].link == NULL) graph[s].link = edge;
    else graph[s].back->next = edge;
    graph[s].back = edge;
}

int dfs(int idx) {
    euler[idx].u = euler[idx].v = ++number;
    for(E* prev = graph[idx].link; prev != NULL; prev = prev->next) {
        if(!level[prev->v]) {
            level[prev->v] = level[idx] + 1;
            int last = dfs(prev->v);
            euler[idx].v = max(euler[idx].v, last);
        }
    }
    return euler[idx].v;
}

int segtree[N_MAX * 4];

int update(int idx, int s, int e, int t) {
    if(t < s || e < t) return segtree[idx];
    if(s == e) return ++segtree[idx];

    int m = (s + e) / 2;
    int lt = update(idx * 2, s, m, t);
    int rt = update(idx * 2 + 1, m + 1, e, t);

    return segtree[idx] = lt + rt;
}

int find(int idx, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return segtree[idx];

    int m = (s + e) / 2;
    int lt = find(idx * 2, s, m, l, r);
    int rt = find(idx * 2 + 1, m + 1, e, l, r);

    return lt + rt;
}

int main() {
    int N, C, x, y, Q, P, A;
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %d", &x, &y);

        makeEdge(x, y);
        makeEdge(y, x);
    }

    level[C] = 1;
    dfs(C);

    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%d %d", &P, &A);
        switch(P) {
            case INSERT:
                update(1, 1, N, euler[A].u);
                break;
            case SELECT:
                printf("%lld\n", level[A] * find(1, 1, N, euler[A].u, euler[A].v));
                break;
        }
    }
}