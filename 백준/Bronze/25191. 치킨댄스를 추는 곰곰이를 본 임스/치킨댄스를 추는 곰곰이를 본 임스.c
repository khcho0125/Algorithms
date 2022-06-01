#include<stdio.h>

int main() {
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);
    printf("%d", ((A / 2) + B) > N ? N : ((A / 2) + B));
}