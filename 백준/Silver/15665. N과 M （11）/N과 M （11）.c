#include<stdio.h>
#include<stdlib.h>

int array[8];
int set[8] = {0,};
int N, M;

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

void func(int index) {
    if(index == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < N; i++) {
        if(array[i] != set[index]) {
            set[index] = array[i];
            func(index + 1);
        }
    }

    set[index] = 0;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    qsort(array, N, sizeof(int), compare);
    func(0);
}