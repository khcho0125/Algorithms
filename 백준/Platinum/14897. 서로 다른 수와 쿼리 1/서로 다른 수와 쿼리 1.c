#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N_MAX 1000001

typedef struct Query {
    int idx, l, r;
}Q;

typedef struct Array {
    int idx, value;
}A;

A arr[N_MAX];
int number[N_MAX];

Q range[N_MAX];
int cnt[N_MAX];

int ans[N_MAX];

int k;

int sqrtDecomposition(const void *a, const void *b) {
    Q A = *(Q*)a;
    Q B = *(Q*)b;

    int Ask = A.l / k, Bsk = B.l / k;
    if(Ask == Bsk) return A.r < B.r ? -1 : A.r > B.r;
    return Ask > Bsk ? 1 : -1;
}

int compression(const void *a, const void *b) {
    int va = ((A*)a)->value;
    int vb = ((A*)b)->value;

    return va < vb ? -1 : va > vb;
}

int main() {
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i].value);
        arr[i].idx = i + 1;
    }

    k = sqrt(N);

    qsort(arr, N, sizeof(A), compression);
    number[arr[0].idx] = 0;
    for(int i = 1; i < N; i++) {
        number[arr[i].idx] = number[arr[i - 1].idx] + (arr[i].value != arr[i - 1].value);
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &range[i].l, &range[i].r);
        range[i].idx = i;
    }

    qsort(range, M, sizeof(Q), sqrtDecomposition);

    int s = 1, e = 0, result = 0;
    for(int i = 0; i < M; i++) {
        for(; range[i].l < s; cnt[number[s]]++) result += !cnt[number[--s]];
        for(; s < range[i].l; s++) result -= !(--cnt[number[s]]);
        for(; range[i].r < e; e--) result -= !(--cnt[number[e]]);
        for(; e < range[i].r; cnt[number[e]]++) result += !cnt[number[++e]];

        ans[range[i].idx] = result;
    }

    for(int i = 0; i < M; i++) {
        printf("%d\n", ans[i]);
    }
}