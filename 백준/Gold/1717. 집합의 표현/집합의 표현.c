#include<stdio.h>
#include<string.h>

int UnionFind[1000001];

int find(int x) {
    if(UnionFind[x] < 0) return x;
    return UnionFind[x] = find(UnionFind[x]);
}

void Union(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);

    if(r1 == r2) return;

    if(UnionFind[r1] < UnionFind[r2]) {
        UnionFind[r1] += UnionFind[r2];
        UnionFind[r2] = r1;
        return;
    }

    UnionFind[r2] += UnionFind[r1];
    UnionFind[r1] = r2;
}

int main() {
    memset(UnionFind, -1, sizeof(UnionFind));
    int N, M, c, a, b;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &c, &a, &b);
        if(c) {
            printf(find(a) == find(b) ? "YES\n" : "NO\n");
        }
        else {
            Union(a, b);
        }
    }
}