#include <stdio.h>

int main()
{
    int a, x, b, y, T;
    scanf("%d %d %d %d %d", &a, &x, &b, &y, &T);
    printf("%d %d", a + (T > 30 ? T - 30 : 0) * 21 * x, b + (T > 45 ? T - 45 : 0) * 21 * y);
}