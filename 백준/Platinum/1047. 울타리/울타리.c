#include<stdio.h>
#include<stdlib.h>

#define round(x, y) ((x + y) * 2)
#define min(a, b) ((a) < (b) ? a : b)

typedef struct Tree {
    int x, y, w;
}T;

T forest[40];
int N;

int compareX(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    if (forest[A].x > forest[B].x) {
        return 1;
    }

    if (forest[A].x < forest[B].x) {
        return -1;
    }

    return 0;
}

int compareY(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    if (forest[A].y > forest[B].y) {
        return 1;
    }

    if (forest[A].y < forest[B].y) {
        return -1;
    }

    return 0;
}

int compareW(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    if (forest[A].w > forest[B].w) {
        return 1;
    }

    if (forest[A].w < forest[B].w) {
        return -1;
    }

    return 0;
}

int XSet[40];
int YSet[40];
int includeSet[40];

int cut(int fX, int bX, int fY, int bY) {
    int minX = forest[XSet[fX]].x;
    int maxX = forest[XSet[bX]].x;
    int minY = forest[YSet[fY]].y;
    int maxY = forest[YSet[bY]].y;

    int current = round(maxX - minX, maxY - minY);

    int temp = 0, cnt = 0, fence = 0;
    for(int i = 0; i < N; i++) {
        if(minX <= forest[i].x && forest[i].x <= maxX && minY <= forest[i].y && forest[i].y <= maxY) {
            includeSet[temp++] = i;
        }
        else {
            fence += forest[i].w;
            cnt++;
        }
    }

    qsort(includeSet, temp, sizeof(int), compareW);

    for(;temp != 0 && fence < current; cnt++) fence += forest[includeSet[--temp]].w;

    return cnt;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &forest[i].x, &forest[i].y, &forest[i].w);
        XSet[i] = YSet[i] = i;
    }

    qsort(XSet, N, sizeof(int), compareX);
    qsort(YSet, N, sizeof(int), compareY);

    int result = N - 1, temp;
    for(int fX = 0; fX < N; fX++) {
        for(int bX = fX; bX < N; bX++) {
            for(int fY = 0; fY < N; fY++) {
                for(int bY = fY; bY < N; bY++) {
                    temp = cut(fX, bX, fY, bY);
                    result = min(temp, result);
                }
            }
        }
    }

    printf("%d", result);
}