#include <stdio.h>

int main()
{
    double k;
    scanf("%lf", &k);
    printf("%lf", ((k / 100 + 25) > 100 ? (k / 100 + 25) : 100) > 2000 ? 2000 : ((k / 100 + 25) > 100 ? (k / 100 + 25) : 100));
}