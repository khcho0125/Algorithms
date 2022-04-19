#include <stdio.h>

int main()
{
    double A, B, C, D, E, F;
    scanf("%lf %lf %lf %lf %lf %lf", &A, &B, &C, &D, &E, &F);
    if(A <= D && B <= E && C <= F) {
        printf("A");
    } else if(B <= E && C <= F) {
        if(A / 2 <= D) {
            printf("B");
        } else {
            printf("C");
        }
    } else if(B / 2 <= E && C <= F) {
        printf("D");
    } else {
        printf("E");
    }
}