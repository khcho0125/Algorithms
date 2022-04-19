#include<stdio.h>

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    printf("%d", (M > K ? K : M) + ((N - M) > (N - K) ? (N - K) : (N - M)));
}
