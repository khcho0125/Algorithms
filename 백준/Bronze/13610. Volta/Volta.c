#include<stdio.h>

int main() {
    int A, B, sum = 0, i;
    scanf("%d %d", &A, &B);
    A = B - A;
    for(i = 0; sum < B; i++, sum += A);
    printf("%d", i);
}