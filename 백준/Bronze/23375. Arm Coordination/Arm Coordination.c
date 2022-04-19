#include <stdio.h>

int main()
{
    long x, y, r;
    scanf("%ld %ld %ld", &x, &y, &r);
    printf("%d %d\n%d %d\n%d %d\n%d %d", x - r, y + r, x + r, y + r, x + r, y - r, x - r, y - r);
}