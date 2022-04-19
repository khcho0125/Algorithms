#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long
#define Abs(a) (((a) < 0) ? (a) * -1 : a)

typedef struct node {
    int x, y;
}node;

typedef struct Edge {
    int v1, v2;
    double w;
}E;

int UnionFind[1000];
node Sin[1000];
E edge[500501];
int pre = 0, connect = 0;

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

int compare(const void* a, const void* b) {
    E num1 = *(E*)a;
    E num2 = *(E*)b;

    if(num1.w > num2.w) {
        return 1;
    }

    if(num1.w < num2.w) {
        return -1;
    }
    
    return 0;
}

int main() {
    double sum = 0;
    int N, M, x, y;
    ll d1, d2;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        Sin[i].x = x;
        Sin[i].y = y;
        for(int j = 0; j < i; j++) {
            d1 = Abs(Sin[j].x - Sin[i].x);
            d2 = Abs(Sin[j].y - Sin[i].y);
            edge[pre].v1 = i;
            edge[pre].v2 = j;
            edge[pre++].w = d1 * d1 + d2 * d2;
        }
        UnionFind[i] = -1;
    }
    qsort(edge, pre, sizeof(E), compare);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        connect += Union(x - 1, y - 1);
    }
    for(int i = 0; i < pre && connect != N - 1; i++) {
        if(Union(edge[i].v1, edge[i].v2)) {
            sum += sqrt(edge[i].w);
            connect++;
        }
    }
    printf("%.2lf", sum);
}