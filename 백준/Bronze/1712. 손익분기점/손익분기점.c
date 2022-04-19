#include <stdio.h>

int main()
{
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    if(A >= B) {
        printf("-1");
        return 0;
    }
    printf("%d", N / (B - A) + 1);
}