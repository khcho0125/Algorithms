#include<stdio.h>

int main() {
    long long R, C, N, result = 0;
    scanf("%lld %lld %lld", &R, &C, &N);
    result += (R / N  + (R % N != 0)) * (C / N + (C % N != 0));
    printf("%lld", result);
}