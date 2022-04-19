#include<stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    printf("%d", N / 5 + (N % 5 != 0));
}