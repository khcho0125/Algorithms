#include<stdio.h>
#include<stdlib.h>

#define N_MAX 100000

typedef struct Pair {
    int idx, val;
}P;

typedef struct Query {
    int idx, i, j, k;
}Q;

P arr[N_MAX];
Q query[N_MAX];

int segment[N_MAX * 4];

int result[N_MAX];

int P_bigger(const void* a, const void* b) {
    int A = ((P*)a)->val;
    int B = ((P*)b)->val;

    return A > B ? -1 : A < B;
}

int Q_bigger(const void* a, const void* b) {
    int A = ((Q*)a)->k;
    int B = ((Q*)b)->k;

    return A > B ? -1 : A < B;
}

void update(int idx, int s, int e, int v) {
    segment[idx]++;

    if(s == e) return;
    
    int m = (s + e) >> 1;
    if(v <= m) update(idx * 2, s, m, v);
    else update(idx * 2 + 1, m + 1, e, v);
}

int count(int idx, int s, int e, int i, int j) {
    if(i <= s && e <= j) return segment[idx];
    if(j < s || e < i) return 0;

    int m = (s + e) >> 1;
    return count(idx * 2, s, m, i, j) + count(idx * 2 + 1, m + 1, e, i, j);
}

int main() {
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i + 1;
    }

    qsort(arr, N, sizeof(P), P_bigger);

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &query[i].i, &query[i].j, &query[i].k);
        query[i].idx = i;
    }

    qsort(query, M, sizeof(Q), Q_bigger);

    for(int np = 0, mp = 0; mp < M; mp++) {
        for(;np < N && query[mp].k < arr[np].val; np++) update(1, 1, N, arr[np].idx);
        result[query[mp].idx] = count(1, 1, N, query[mp].i, query[mp].j);
    }

    for(int i = 0; i < M; i++) {
        printf("%d\n", result[i]);
    }
}