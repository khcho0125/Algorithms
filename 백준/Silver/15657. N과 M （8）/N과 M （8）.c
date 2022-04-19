#include<stdio.h>
#include<stdlib.h>

int N, M;
int input[8] = {0,};

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if(num1 > num2) {
        return 1;
    }
    if(num1 < num2) {
        return -1;
    }
    return 0;
}

void NandM(int* arr, int num) {
    if(M == num) {
        for(int i = 0; i < M; i++) {
            printf("%d ", input[arr[i]]);
        }
        printf("\n");
        return;
    }
    for(int i = arr[num - 1]; i < N; i++) {
        arr[num] = i;
        NandM(arr, num + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    qsort(input, N, sizeof(int), compare);
    int* list = (int*)malloc(sizeof(int) * M);
    for(int i = 0; i < N; i++) {
        list[0] = i;
        NandM(list, 1);
    }
}