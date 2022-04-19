#include <stdio.h>
#include <math.h>
int main()
{
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    printf("%.lf", floor(A * B / C) > floor((A / B) * C) ? floor(A * B / C) : floor((A / B) * C));
}