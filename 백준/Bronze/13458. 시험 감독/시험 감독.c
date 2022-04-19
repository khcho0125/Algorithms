#include<stdio.h>

int A[1000000];

int main() {
    int N, B, C, tmp;
    long long result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d %d", &B, &C);
    result = N;
    for(int i = 0; i < N; i++) {
        tmp = (A[i] - B < 0 ? 0 : A[i] - B);
        result += (tmp / C) + (tmp % C != 0);     
    }
    printf("%lld", result);
}