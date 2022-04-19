#include<stdio.h>
#include<stdlib.h>

int N, M;

void NandM(int* arr, int num) {
    if(M == num) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = arr[num - 1]; i <= N; i++) {
        arr[num] = i;
        NandM(arr, num + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int* list = (int*)malloc(sizeof(int) * M);
    for(int i = 1; i <= N; i++) {
        list[0] = i;
        NandM(list, 1);
    }
}