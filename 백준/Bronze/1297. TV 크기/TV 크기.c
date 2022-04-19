#include <stdio.h>
#include <math.h>

int main()
{
    double D, M, H, temp;
    scanf("%lf %lf %lf", &D, &H, &M);
    temp = sqrt(H*H + M*M);
    printf("%0.lf %0.lf", floor(D * H / temp), floor(D * M / temp));
}