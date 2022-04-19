#include<stdio.h>
int main() {
    int N, M, T, G;
    scanf("%d %d %d %d", &N, &M, &T, &G);
    printf("%d", (N - 1) / M * T * G);
}