#include <stdio.h>

int main()
{
    long N;
    scanf("%ld", &N);
    N %= 8;
    if (N == 0)
        printf("2");
    else if (N > 5)
    {
        if (N == 7)
            printf("3");
        else
            printf("4");
    }
    else
    {
        printf("%d", N);
    }
}