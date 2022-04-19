#include<stdio.h>
#include<stdlib.h>

typedef struct V {
    int v1, v2, W;
}V;

int UnionFind[100001];
V Road[1000001];
int pre = 1, sum = 0, result = 0;

void Q_I(int A, int B, int C) {
    int idx = pre++;
    while((idx != 1) && Road[idx / 2].W > C) {
        Road[idx].v1 = Road[idx / 2].v1;
        Road[idx].v2 = Road[idx / 2].v2;
        Road[idx].W = Road[idx / 2].W;
        idx /= 2;
    }
    Road[idx].v1 = A;
    Road[idx].v2 = B;
    Road[idx].W = C;
}

V* Q_O() {
    V* R = (V*)malloc(sizeof(V));
    R->v1 = Road[1].v1;
    R->v2 = Road[1].v2;
    R->W = Road[1].W;
    int tempV1 = Road[--pre].v1;
    int tempV2 = Road[pre].v2;
    int tempW = Road[pre].W;
    int child = 2, parent = 1;
    while(child <= pre) {
        if(child < pre && Road[child].W > Road[child + 1].W) {
            child++;
        }

        if(Road[child].W >= tempW) {
            break;
        }

        Road[parent].v1 = Road[child].v1;
        Road[parent].v2 = Road[child].v2;
        Road[parent].W = Road[child].W;
        parent = child;
        child *= 2;
    }
    Road[parent].v1 = tempV1;
    Road[parent].v2 = tempV2;
    Road[parent].W = tempW;
    return R;
}

int find(int x) {
    if(UnionFind[x] < 0) {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

void Union(int v1, int v2, int w) {
    int x = find(v1);
    int y = find(v2);

    if(x == y) {
        return;
    }

    if(UnionFind[x] < UnionFind[y]) {
        UnionFind[x] += UnionFind[y];
        UnionFind[y] = x;
    }
    else {
        UnionFind[y] += UnionFind[x];
        UnionFind[x] = y;
    }
    sum = w;
    result += w;
}

int main() {
    V* R = (V*)malloc(sizeof(V));
    int N, M, A, B, C;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        UnionFind[i] = -1;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        Q_I(A, B, C);
    }
    for(int i = 0; i < M; i++) {
        R = Q_O();
        Union(R->v1, R->v2, R->W);
    }
    printf("%d", result - sum);
}