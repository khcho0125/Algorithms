#include<stdio.h>
#include<string.h>

int UnionFind[500001];

int find(int x) {
    if(UnionFind[x] < 0) {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

int Union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return 0;
    }

    if(UnionFind[x] < UnionFind[y]) {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
    }
    else {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
    }

    return 1;
}

int main() {
    memset(UnionFind, -1, sizeof(UnionFind));
    int N, M, u, v;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d %d",&u, &v);
        if(!Union(u, v)) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}