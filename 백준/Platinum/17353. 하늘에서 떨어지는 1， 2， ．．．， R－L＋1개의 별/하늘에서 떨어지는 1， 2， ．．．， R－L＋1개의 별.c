#include<stdio.h>

#define ll long long
#define N_MAX 100001

enum Command {
    UPDATE = 1,
    SELECT = 2
};

typedef struct Segment {
    ll w, base;
}ST;

int A[N_MAX];
ST segtree[N_MAX * 4];

void update(int idx, int s, int e, int l, int r) {
    if(r < s || e < l) return;
    if(l <= s & e <= r) {
        segtree[idx].w++;
        segtree[idx].base += s - l + 1;
        return;
    }

    int m = (s + e) / 2;
    update(idx * 2, s, m, l, r);
    update(idx * 2 + 1, m + 1, e, l, r);
}

ll find(int idx, int s, int e, int x) {
    if(x < s || e < x) return 0;
    if(s == e) return segtree[idx].base;

    int m = (s + e) / 2;
    ll lt = find(idx * 2, s, m, x);
    ll rt = find(idx * 2 + 1, m + 1, e, x);

    return lt + rt + segtree[idx].base + segtree[idx].w * (x - s);
}

int main() {
    int N, Q, C, L, R, X;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%d", &C);
        switch(C) {
            case UPDATE:
                scanf("%d %d", &L, &R);
                update(1, 1, N, L, R);
                break;
            
            case SELECT:
                scanf("%d", &X);
                printf("%lld\n", find(1, 1, N, X) + A[X]);
                break;
        }
    }
}