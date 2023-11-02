#include<stdio.h>

#define ll long long

#define N_MAX 100000
#define K_MAX 10
#define MOD 1000000007
#define min(a, b) ((a) < (b) ? a : b)

int A[N_MAX];
ll segtree[K_MAX][N_MAX * 4];

ll update(int k, int node, int s, int e, int index, int value) {
    if(s == index && index == e) return segtree[k][node] = value;
    if(index < s || e < index) return segtree[k][node];

    int mid = (s + e) / 2;
    ll lt = update(k, node * 2, s, mid, index, value);
    ll rt = update(k, node * 2 + 1, mid + 1, e, index, value);

    return segtree[k][node] = (lt + rt) % MOD;
}

ll select(int k, int node, int s, int e, int index) {
    if(index <= s) return 0;
    if(e < index) return segtree[k][node];

    int mid = (s + e) / 2;
    ll lt = select(k, node * 2, s, mid, index);
    ll rt = select(k, node * 2 + 1, mid + 1, e, index);

    return (lt + rt) % MOD;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i++) { 
        ll len = 1;
        for(int k = 0; k < K && len; k++) {
            update(k, 1, 1, N, A[i], len);
            len = select(k, 1, 1, N, A[i]);
        }
    }

    printf("%lld", segtree[K - 1][1]);
}