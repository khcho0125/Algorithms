#include <stdio.h>
#include <math.h>
#define _M_PI

int main()
{
    double a;
    scanf("%lf", &a);
    printf("%lf", sqrt(a / M_PI) * 2 * M_PI);
}