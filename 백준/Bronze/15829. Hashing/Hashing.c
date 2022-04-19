#include<stdio.h>
#include<stdlib.h>

int main() {
    int N, i, M = 1234567891;
    unsigned long long result = 0;
    unsigned long long r = 1;
    scanf("%d", &N);
    char* str = (char*)malloc(N);
    scanf("%s", str);
    for(i = 0; i < N; i++) {
        result = (result + (str[i] - 96) * r) % M;
        r *= 31;
        r %= M;
    }
    printf("%llu", result);
    return 0;
}