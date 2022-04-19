#include<stdio.h>

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    if(N * M - K < 0) {
        printf("0");
        return 0;
    }
    printf("%d", N * M - K);
}