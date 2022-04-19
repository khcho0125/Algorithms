#include<stdio.h>
#include<stdlib.h>

int N, M;
int visit[8] = {0,};

void NandM(int* arr, int num) {
    if(M == num) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = arr[num - 1] + 1; i <= N; i++) {
        if(!visit[i - 1]) {
            arr[num] = i;
            visit[i - 1] = 1;
            NandM(arr, num + 1);
            visit[i - 1] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int* list = (int*)malloc(sizeof(int) * M);
    for(int i = 1; i <= N - M + 1; i++) {
        list[0] = i;
        visit[i - 1] = 1;
        NandM(list, 1);
        visit[i - 1] = 0;
    }
}