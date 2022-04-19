#include <stdio.h>

int main()
{
    long x, y;
    scanf("%ld %ld", &x, &y);
    printf("%ld", (x < y ? x : y) / 2);
}