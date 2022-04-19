#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (A == B && A == C)
    {
        printf("%d", 10000 + A * 1000);
        return 0;
    }
    if(A != B && A != C && B != C)
    {
        printf("%d", ((A > B ? A : B) > C ? (A > B ? A : B) : C) * 100);
        return 0;
    }
    if(B == C) {
        printf("%d", 1000 + B * 100);
    } else {
        printf("%d", 1000 + A * 100);
    }
}