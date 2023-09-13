#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ll long long
#define N_MAX 100000
#define A_MAX 1000000

typedef struct Query {
    int i, s, e;
}Q;

int a[N_MAX + 1];
Q query[N_MAX + 1];
ll result[N_MAX + 1];

int counting[A_MAX + 1];

ll kks(int s) {
    return (ll)counting[s] * counting[s] * s;
}

int k;

int sqrtDecomposition(const void* a, const void* b) {
    Q A = *(Q*)a;
    Q B = *(Q*)b;

    int Ask = A.s / k, Bsk = B.s / k;

    if(Ask != Bsk) return Ask > Bsk ? 1 : -1;
    return A.e > B.e ? 1 : -1;
}

int main() {
    int n, t, l, r;
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < t; i++) {
        scanf("%d %d", &l, &r);
        query[i] = (Q) {
            .i = i,
            .s = l,
            .e = r
        };
    }

    k = sqrt(n);
    qsort(query, t, sizeof(Q), sqrtDecomposition);

    int start = 0, end = 0;
    for(int i = 0; i < t; i++) {
        for(;start < query[i].s; start++) {
            result[query[i].i] -= kks(a[start]);
            counting[a[start]]--;
            result[query[i].i] += kks(a[start]);
        }

        for(;query[i].s < start; start--) {
            result[query[i].i] -= kks(a[start - 1]);
            counting[a[start - 1]]++;
            result[query[i].i] += kks(a[start - 1]);
        }

        for(;end < query[i].e; end++) {
            result[query[i].i] -= kks(a[end + 1]);
            counting[a[end + 1]]++;
            result[query[i].i] += kks(a[end + 1]);
        }

        for(;query[i].e < end; end--) {
            result[query[i].i] -= kks(a[end]);
            counting[a[end]]--;
            result[query[i].i] += kks(a[end]);
        }

        if(i + 1 < t) result[query[i + 1].i] = result[query[i].i];
    }

    for(int i = 0; i < t; i++) {
        printf("%lld\n", result[i]);
    }
}