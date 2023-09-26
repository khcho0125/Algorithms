#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define N_MAX 100001

enum Type {
    CHANGE = 1,
    SUM = 2
};

typedef struct Query {
    int idx, k, i, j;
}Q;

typedef struct Pair {
    int i, v;
}P;

int A[N_MAX];
P change[N_MAX];
ll result[N_MAX];
Q query[N_MAX];
int qp = 0;

ll segtree[N_MAX * 4];

int offline(const void* a, const void* b) {
    int ak = ((Q*)a)->k;
    int bk = ((Q*)b)->k;

    return ak < bk ? -1 : ak > bk;
}

ll tree_init(int idx, int s, int e) {
    if(s == e) return segtree[idx] = A[s];

    int m = (s + e) / 2;
    ll lt = tree_init(idx * 2, s, m);
    ll rt = tree_init(idx * 2 + 1, m + 1, e);

    return segtree[idx] = lt + rt;
}

ll update(int idx, int s, int e, int t, int v) {
    if(t < s || e < t) return segtree[idx];
    if(s == e) return segtree[idx] = v;
    
    int m = (s + e) / 2;
    ll lt = update(idx * 2, s, m, t, v);
    ll rt = update(idx * 2 + 1, m + 1, e, t, v);

    return segtree[idx] = lt + rt;
}

ll find(int idx, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return segtree[idx];

    int m = (s + e) / 2;
    ll lt = find(idx * 2, s, m, l, r);
    ll rt = find(idx * 2 + 1, m + 1, e, l, r);

    return lt + rt;
}

int main() {
    int N, M, C;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    tree_init(1, 1, N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d", &C);
        switch(C) {
            case CHANGE:
                scanf("%d %d", &change[i - qp].i, &change[i - qp].v);
                break;

            case SUM:
                query[qp].idx = qp;
                scanf("%d %d %d", &query[qp].k, &query[qp].i, &query[qp].j);
                qp++;
                break;
        }
    }

    qsort(query, qp, sizeof(Q), offline);

    int p = 0;
    for(int i = 0; i < qp; i++) {
        for(;p < query[i].k; p++) update(1, 1, N, change[p].i, change[p].v);
        result[query[i].idx] = find(1, 1, N, query[i].i, query[i].j);
    }

    for(int i = 0; i < qp; i++) {
        printf("%lld\n", result[i]);
    }
}