#include<stdio.h>

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%d", ((A + D) - (B + C) > 0 ? (A + D) - (B + C) : (B + C) - (A + D)));
}