#include<stdio.h>

int main() {
    int N, M, max, i, j;
    scanf("%d", &N);
    int arr[10001] = { 0, };
    for(i = 0; i < N; i++) {
        scanf("%d", &M);
        arr[M]++;
        if(i == 0) {
            max = M;
        }
        if(max < M) {
            max = M;
        }
    }
    for(i = 1; i < max + 1; i++) {
        for(j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
    }
}