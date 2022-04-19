#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    N += M % 12;
    printf("%d", (N > 12 ? N - 12 : N));
}