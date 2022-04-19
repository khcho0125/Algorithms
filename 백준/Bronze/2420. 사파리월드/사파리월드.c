#include <stdio.h>

int main()
{
    long A, B;
    scanf("%ld %ld", &A, &B);
    printf("%ld", A > B ? A - B : B - A);
}