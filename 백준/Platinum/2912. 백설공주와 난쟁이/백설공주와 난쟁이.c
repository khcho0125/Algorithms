#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define N_MAX 300000
#define C_MAX 10000
#define M_MAX 10000

typedef struct Query {
    int id, s, e, w;
}Q;

int dwarf[N_MAX + 1];
int color[C_MAX + 1];
Q query[M_MAX];

int k;

int sqrtDecomposition(const void* a, const void* b) {
    Q A = *(Q*)a;
    Q B = *(Q*)b;

    int Ask = A.s / k, Bsk = B.s / k;
    
    if(Ask != Bsk) return Ask > Bsk ? 1 : -1;
    return A.e > B.e ? 1 : -1;
}

int orderId(const void* a, const void* b) {
    Q A = *(Q*)a;
    Q B = *(Q*)b;

    return A.id > B.id ? 1 : -1;
}

int isPretty(int idx, int c) {
    int half = (query[idx].e - query[idx].s + 1) / 2;

    for(int i = 1; i <= c; i++) {
        if(half < color[i]) return i;
    }

    return 0;
}

int main() {
    int N, C, M;
    scanf("%d %d", &N, &C);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &dwarf[i]);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &query[i].s, &query[i].e);
        query[i].id = i;
    }

    k = sqrt(N);
    qsort(query, M, sizeof(Q), sqrtDecomposition);

    for(int s = query[0].s; s <= query[0].e; ++color[dwarf[s++]]);
    query[0].w = isPretty(0, C);
    
    for(int i = 1; i < M; i++) {
        for(int s = query[i].s; s < query[i - 1].s; color[dwarf[s++]]++); 
        for(int s = query[i - 1].s; s < query[i].s; color[dwarf[s++]]--); 
        for(int e = query[i - 1].e; e < query[i].e; color[dwarf[++e]]++);
        for(int e = query[i].e; e < query[i - 1].e; color[dwarf[++e]]--);
        query[i].w = isPretty(i, C);
    }

    qsort(query, M, sizeof(Q), orderId);

    for(int i = 0; i < M; i++) {
        if(query[i].w) printf("yes %d\n", query[i].w);
        else printf("no\n");
    }
}