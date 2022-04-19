#include<stdio.h>

int main()
{
    int A, B, C, D, N;
    scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
    B *= (N / A) + (N % A != 0);
    D *= (N / C) + (N % C != 0);
    printf("%d", B < D ? B : D);
}