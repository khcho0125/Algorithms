#include <stdio.h>

int main()
{
    int A, B, C, temp;
    scanf("%d %d %d %d", &A, &B, &C, &temp);
    A += temp / 3600;
    temp %= 3600;
    B += temp / 60;
    C += temp % 60;
    if(C >= 60) {
        B++;
        C %= 60;
    }
    if(B >= 60) {
        A++;
        B %= 60;
    }
    if(A >= 24) {
        A %= 24;
    }
    printf("%d %d %d", A, B, C);
}