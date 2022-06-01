#include<stdio.h>
#include<stdlib.h>

typedef struct Data {
    int v;
    int w;
}Data;

int main() {
    int N, M, U, V, pre = 0;
    scanf("%d %d", &N, &M);
    Data* stack = (Data*)malloc(sizeof(Data) * M);
    int* list = (int*)malloc(sizeof(int) * (N + 1));
    for(int i = 1; i <= N; i++) {
        list[i] = i;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &U, &V);
        stack[pre].v = U;
        stack[pre++].w = V;
    }
    while(pre--) {
        list[stack[pre].v] = list[stack[pre].w];
    }
    for(int i = 1; i <= N; i++) {
        printf("%d ", list[i]);
    }
}