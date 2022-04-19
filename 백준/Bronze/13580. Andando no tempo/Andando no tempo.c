#include<stdio.h>

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    if(N == M || N == K || M == K || N == M + K || M == N + K || K == M + N) {
        printf("S");
    }
    else {
        printf("N");
    }
}