#include<stdio.h>
#include<stdlib.h>

int array[8];
int set[8];
int N, M;

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 > num2) {
        return 1;
    }

    return -1;
}

void func(int index, int turn) {
    if(index == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", array[set[i]]);
        }
        printf("\n");
        return;
    }

    for(int i = turn; i < N; i++) {
        set[index] = i;
        func(index + 1, i + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    qsort(array, N, sizeof(int), compare);
    func(0, 0);
}