#include<stdio.h>
#include<string.h>

int UnionFind[100001];

int find(int x) {
    if(UnionFind[x] < 0) {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

int Union(int x) {
    x = find(x);
    int y = x - 1;
    y = find(y);
    
    if(!x && !y) {
        return 0;
    }

    UnionFind[y] += UnionFind[x];
    UnionFind[x] = y;
    
    return 1;
}

int main() {
    memset(UnionFind, -1, sizeof(UnionFind));
    int G, P, g, result = 0;
    scanf("%d %d", &G, &P);
    for(int i = 0; i < P; i++) {
        scanf("%d", &g);
        if(Union(g)) {
            result++;
        }
        else break;
    }
    printf("%d", result);
}