#include<stdio.h>

int UnionFind[51] = {0,};
int parent[51] = {0,};

int find(int x) {
    if(UnionFind[x] < 0) {
        return x;
    }
    else {
        int y = find(UnionFind[x]);
        UnionFind[x] = y;
        return y;
    }
}

int Union(int x, int y) {

    x = find(x);
    y = find(y);

    if(x == y) {
        return x;
    }

    if(x == 1) {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
        return x;
    }

    if(y == 1) {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
        return y;
    }

    if(UnionFind[x] < UnionFind[y]) {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
        return x;
    }
    else {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
        return y;
    }
}

int main() {
    int N, M, P, input;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M + 1; i++) {
        scanf("%d", &P);
        UnionFind[i]--;
        for(int j = 0; j < P; j++) {
            scanf("%d", &input);
            if(!parent[input]) {
                parent[input] = i;
            }
            else {
                Union(parent[input], i);
            }
        }
    }
    printf("%d", M + 1 + UnionFind[1]);
}