#include<stdio.h>
int main() {
    long N, M;
    scanf("%ld %ld", &N, &M);
    printf("%ld", (N+M)*(N-M));
}