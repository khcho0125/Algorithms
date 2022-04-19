#include<stdio.h>

int main()
{
    long long A, B, C, D, temp;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    if((A * C) % (B * D * 2) == 0) {
        printf("1");
    } else {
        printf("0");
    }
}