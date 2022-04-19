#include<stdio.h>
#include<stdlib.h>

// #define ll long long
// #define cost(a, b, c) (((a) < (b)) ? (((a) < (c)) ? a : c) : (((b) < (c)) ? b : c))
#define min(a, b) (((a) < (b)) ? a : b)
#define abs(a) (((a) < 0) ? ((a) * -1) : a)
// #define INF 987654321

typedef struct Planet {
    int w, v1, v2;
}P;

typedef struct Vector {
    int first, second;
}vector;

P planet[300000];
int pre = 0;
int UnionFind[100000];
vector X[100000];
vector Y[100000];
vector Z[100000];

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

int compare(const void* a, const void* b) {
    vector num1 = *(vector*)a;
    vector num2 = *(vector*)b;
    if(num1.first > num2.first) {
        return 1;
    }
    if(num1.first < num2.first) {
        return -1;
    }
    return 0;
}

int compare2(const void* a, const void* b) {
    P num1 = *(P*)a;
    P num2 = *(P*)b;
    if(num1.w > num2.w) {
        return 1;
    }
    if(num1.w < num2.w) {
        return -1;
    }
    return 0;
}

int main() {
    int N, result = 0, ret;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        UnionFind[i] = -1;
        scanf("%d %d %d", &X[i].first, &Y[i].first, &Z[i].first);
        X[i].second = i, Y[i].second = i, Z[i].second = i;
    }
    qsort(X, N, sizeof(vector), compare);
    qsort(Y, N, sizeof(vector), compare);
    qsort(Z, N, sizeof(vector), compare);
    for(int i = 0; i < N - 1; i++) {
        planet[pre].w = abs(X[i + 1].first - X[i].first), planet[pre].v1 = X[i + 1].second, planet[pre].v2 = X[i].second;
        pre++;
        planet[pre].w = abs(Y[i + 1].first - Y[i].first), planet[pre].v1 = Y[i + 1].second, planet[pre].v2 = Y[i].second;
        pre++;
        planet[pre].w = abs(Z[i + 1].first - Z[i].first), planet[pre].v1 = Z[i + 1].second, planet[pre].v2 = Z[i].second;
        pre++;
    }
    qsort(planet, pre, sizeof(P), compare2);
    for(int i = 0; i < pre; i++) {
        ret = Union(planet[i].v1, planet[i].v2);
        if(ret) {
            result += planet[i].w;
            if(ret == N) {
                break;
            }
        }
    }
    printf("%d", result);
}