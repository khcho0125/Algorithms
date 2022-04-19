#include <stdio.h>

int main()
{
    double M, S, G, A, B, L, R;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &M, &S, &G, &A, &B, &L, &R);
    if(M / G + L / A > M / S + R / B) {
        printf("latmask");
    } else {
        printf("friskus");
    }
}