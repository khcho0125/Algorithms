#include <stdio.h>

int main()
{
    double N, M, num = 0;
    scanf("%lf %lf", &N, &M);
    if (M * 7 <= N)
    {
        num = M * 7;
    }
    else if (M * 3 + M / 2 <= N)
    {
        num = M * 3 + M / 2;
    }
    else if(M + M / 2 + M / 4 <= N)
    {
        num = M + M / 2 + M / 4;
    }
    printf("%.lf", num * 1000);
}