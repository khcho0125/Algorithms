#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define abs(a) ((a) < 0 ? ((a) * -1) : a)

typedef struct Vector {
    double first, second;
}vector;

typedef struct Edge {
    double w;
    int v1, v2;
}E;

int UnionFind[100];
vector star[100];
E edge[5000];
int pre = 0;

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
        return UnionFind[x] * -1;
    }
    else {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
        return UnionFind[y] * -1;
    }
}

int main() {
    double result = 0, a, b;
    int N, ret;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        UnionFind[i] = -1;
        scanf("%lf %lf", &star[i].first, &star[i].second);
        for(int j = 0; j < i; j++) {
            edge[pre].v1 = i;
            edge[pre].v2 = j;
            a = abs(star[i].first - star[j].first);
            b = abs(star[i].second - star[j].second);
            edge[pre++].w = a * a + b * b;
        }
    }
    qsort(edge, pre, sizeof(E), compare);
    for(int i = 0; i < pre; i++) {
        ret = Union(edge[i].v1, edge[i].v2);
        if(ret) {
            result += sqrt(edge[i].w);
            if(ret == N) break;
        }
    }
    printf("%.2lf", result);
}