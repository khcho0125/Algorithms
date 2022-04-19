#include<stdio.h>
#include<stdlib.h>

int N, M;
int visit[8] = {0,};
int input[8] = {0,};
int number[8][10000] = {0,};

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
    for(int i = 0; i < N; i++) {
        if(!visit[i] && !number[num][input[i] - 1]) {
            arr[num] = i;
            visit[i] = 1;
            number[num][input[i] - 1] = 1;
            NandM(arr, num + 1);
            visit[i] = 0;
        }
    }
    for(int i = 0; i < 10000; i++) {
        number[num][i] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    qsort(input, N, sizeof(int), compare);
    int* list = (int*)malloc(sizeof(int) * M);
    NandM(list, 0);
}