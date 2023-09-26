#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_MAX 100001
#define max(a, b) ((a) > (b) ? a : b)

enum Type {
    UPDATE = 1,
    SELECT = 2
};

typedef struct Edge {
    int v;
    struct Edge *link;
}E;

typedef struct Node {
    E *link;
    E *back;
}N;

typedef struct Section {
    int s, e;
}S;

N graph[N_MAX];
S number[N_MAX];
int num = 0;

int segtree[N_MAX * 4];

void makeEdge(int s, int t) {
    E* edge = (E*)malloc(sizeof(E));
    edge->link = NULL;
    edge->v = t;

    if(graph[s].link == NULL) graph[s].link = edge;
    else graph[s].back->link = edge;
    graph[s].back = edge;
}

int dfs(int idx) {
    number[idx].s = number[idx].e = ++num;
    for(E* prev = graph[idx].link; prev != NULL; prev = prev->link) {
        int last = dfs(prev->v);
        number[idx].e = max(number[idx].e, last);
    }
    return number[idx].e;
}

void update(int idx, int s, int e, int l, int r, int w) {
    if(e < l || r < s) return;
    if(l <= s && e <= r) {
        segtree[idx] += w;
        return;
    }

    int m = (s + e) / 2;
    update(idx * 2, s, m, l, r, w);
    update(idx * 2 + 1, m + 1, e, l, r, w);
}

int find(int idx, int s, int e, int t) {
    if(t < s || e < t) return 0;
    if(s == e) return segtree[idx];

    int m = (s + e) / 2;
    int lt = find(idx * 2, s, m, t);
    int rt = find(idx * 2 + 1, m + 1, e, t);

    return lt + rt + segtree[idx];
}

int main() {
    int N, M, P, source;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &P);
        if(P == -1) source = i;
        else makeEdge(P, i);
    }

    dfs(source);

    int T, i, w;
    for(int q = 0; q < M; q++) {
        scanf("%d %d", &T, &i);
        switch(T) {
            case UPDATE:
                scanf("%d", &w);
                update(1, 1, num, number[i].s, number[i].e, w);
                break;
            case SELECT:
                printf("%d\n", find(1, 1, num, number[i].s));
                break;
        }
    }
}