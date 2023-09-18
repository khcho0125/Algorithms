#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_MAX 100001

typedef struct Node {
    int size, *set;
}N;

typedef struct Query {
    int i, j, k;
}Q;

int arr[N_MAX];
Q query[N_MAX];

N tree[N_MAX * 4];

int build(int idx, int s, int e) {
    if(s == e) {
        tree[idx].set = &arr[s];
        return tree[idx].size = 1;
    }

    int m = (s + e) >> 1;
    tree[idx].size = build(idx * 2, s, m) + build(idx * 2 + 1, m + 1, e);
    tree[idx].set = (int*)malloc(sizeof(int) * tree[idx].size);

    N *l = &tree[idx * 2], *r = &tree[idx * 2 + 1];
    int temp = 0, ls = 0, rs = 0;
    while(temp < tree[idx].size) {
        if(ls == l->size) tree[idx].set[temp++] = r->set[rs++];
        else if(rs == r->size) tree[idx].set[temp++] = l->set[ls++];
        else tree[idx].set[temp++] = l->set[ls] < r->set[rs] ? l->set[ls++] : r->set[rs++];
    }
    
    return tree[idx].size;
}

int upper_bound(int x, int* set, int size) {
    int s = -1, e = size, m; 
    while(s + 1 < e) {
        m = (s + e) >> 1;
        if(set[m] <= x) s = m;
        else e = m; 
    }
    return e;
}

int count(int idx, int s, int e, Q param) {
    if(param.i <= s && e <= param.j) {
        return tree[idx].size - upper_bound(param.k, tree[idx].set, tree[idx].size);
    }
    if(param.j < s || e < param.i) return 0;

    int m = (s + e) >> 1;
    return count(idx * 2, s, m, param) + count(idx * 2 + 1, m + 1, e, param);
}

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &query[i].i, &query[i].j, &query[i].k);
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        query[i] = (Q) {
            .i = query[i].i ^ ans,
            .j = query[i].j ^ ans,
            .k = query[i].k ^ ans
        };

        ans = count(1, 1, n, query[i]);
        printf("%d\n", ans);
    }
}