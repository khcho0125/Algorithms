#include<stdio.h>
#include<stdlib.h>

typedef struct Arr {
    int idx, value;
}Arr;

Arr arr[50];

int first(const void* a, const void* b) {
    Arr num1 = *(Arr*)a;
    Arr num2 = *(Arr*)b;

    if(num1.value > num2.value) {
        return 1;
    }

    if(num1.value < num2.value) {
        return -1;
    }

    if(num1.idx < num2.idx) {
        return -1;
    }

    return 1;
}

int second(const void* a, const void* b) {
    Arr num1 = *(Arr*)a;
    Arr num2 = *(Arr*)b;

    if(num1.idx > num2.idx) {
        return 1;
    }

    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i].value);
        arr[i].idx = i;
    }
    qsort(arr, N, sizeof(Arr), first);
    for(int i = 0; i < N; i++) {
        arr[i].value = i;
    }
    qsort(arr, N, sizeof(Arr), second);
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i].value);
    }
}