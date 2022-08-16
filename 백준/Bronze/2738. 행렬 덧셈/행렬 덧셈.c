#include<stdio.h>

int main() {
    int N, M, A[10000], B;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N * M; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &B);
            printf("%d ", A[i * M + j] + B);
        }
        printf("\n");
    }
}