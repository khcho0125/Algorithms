#include<stdio.h>

#define ll long long

typedef struct Pair {
    ll sum, value;
}Pair;

enum COMMAND { UPDATE = 1, SUM = 2 };

ll arr[1000001];
Pair segtree[4000004];

ll init_tree(int node, int start, int end) {
    if (start == end) return segtree[node].sum = arr[start];

    int mid = (start + end) / 2;
    ll Ltree = init_tree(node * 2, start, mid);
    ll Rtree = init_tree(node * 2 + 1, mid + 1, end);

    return segtree[node].sum = Ltree + Rtree;
}

ll update(int node, int start, int end, int s, int e, ll value) {
    if (end < s || e < start) return segtree[node].sum + segtree[node].value * (end - start + 1);

    if (s <= start && end <= e) {
        segtree[node].value += value;
        return segtree[node].sum + segtree[node].value * (end - start + 1);
    }

    int mid = (start + end) / 2;
    ll Ltree = update(node * 2, start, mid, s, e, value);
    ll Rtree = update(node * 2 + 1, mid + 1, end, s, e, value);
    segtree[node].sum = Ltree + Rtree;
    return segtree[node].sum + segtree[node].value * (end - start + 1);
}

ll query(int node, int start, int end, int s, int e, ll value) {
    if (end < s || e < start) return 0LL;

    value += segtree[node].value;
    if (s <= start && end <= e) return segtree[node].sum + value * (end - start + 1);

    int mid = (start + end) / 2;
    ll Ltree = query(node * 2, start, mid, s, e, value);
    ll Rtree = query(node * 2 + 1, mid + 1, end, s, e, value);

    return Ltree + Rtree;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
    }

    init_tree(1, 1, N);

    int a, b, c;
    ll d;
    for(int i = 0; i < M + K; i++) {
        scanf("%d", &a);
        switch(a) {
            case UPDATE:
                scanf("%d %d %lld", &b, &c, &d);
                update(1, 1, N, b, c, d);
                break;

            case SUM:
                scanf("%d %d", &b, &c);
                printf("%lld\n", query(1, 1, N, b, c, 0));
                break;
        }
    }
}