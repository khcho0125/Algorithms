#include<stdio.h>

int main() {
    int A, B, C, min1, min2, min3;
    scanf("%d %d %d", &A, &B, &C);
    min1 = A * 4 + B * 2;
    min2 = A * 2 + C * 2;
    min3 = B * 2 + C * 4;
    printf("%d", (min1 < min2 ? min1 : min2) < min3 ? (min1 < min2 ? min1 : min2) : min3);
}