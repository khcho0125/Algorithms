#include <stdio.h>

int main()
{
    long long N, M;
    scanf("%lld %lld", &N, &M);
    if (N % 2 == 0 || M % 2 == 0)
        printf("0");
    else
        printf("%lld", N > M ? M : N);
}