#include<stdio.h>

int main() {
    int A, B, C, D, E, sum, temp = 0;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    if(C < E) temp = E - C;
    sum = B + temp * D;
    printf("%d", sum < A * E ? sum : A * E);
}