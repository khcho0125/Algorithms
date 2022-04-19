#include <stdio.h>

double Factorial(double n, double m);

int main()
{
    double N, M, Case, i;
    scanf("%lf", &Case);
    for (i = 0; i < Case; i++)
    {
        scanf("%lf %lf", &N, &M);
        printf("%.lf\n", Factorial(N, M));
    }
}

double Factorial(double n, double m) {

    if(n == 1) {
        return m;
    }

    return (m / n) * Factorial(n - 1, m - 1);
}