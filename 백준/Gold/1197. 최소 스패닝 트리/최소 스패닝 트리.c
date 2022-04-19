#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int v1;
    int v2;
    int weight;
}node;

int UnionFind[10001] = {0,};
node N[100000] = {0,};

int compare(const void* a, const void* b) {
    node num1 = *(node*)a;
    node num2 = *(node*)b;

    if(num1.weight > num2.weight) {
        return 1;
    }

    if(num1.weight < num2.weight) {
        return -1;
    }

    return 0;
}

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
    int V, E, result = 0;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++) {
        UnionFind[i + 1] = -1;
    }
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &N[i].v1, &N[i].v2, &N[i].weight);
    }
    qsort(N, E, sizeof(node), compare);
    for(int i = 0; i < E; i++) {
        if(Union(N[i].v1, N[i].v2))
            result += N[i].weight;
    }
    printf("%d", result);
}