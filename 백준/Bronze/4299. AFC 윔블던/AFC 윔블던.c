#include<stdio.h>

int main() {
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    if((N + M) % 2 || N < M) {
        printf("-1");
        return 0;
    }
    A = (N + M) / 2;
    B = N - A;
    printf("%d %d", A, B);
}
