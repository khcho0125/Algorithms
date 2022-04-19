#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if(A + B + C != 180) {
        printf("Error");
    } else {
        if(A != B && B != C && A != C) {
            printf("Scalene");
        } else {
            if(A == 60 && B == 60) {
                printf("Equilateral");
            } else {
                printf("Isosceles");
            }
        }
    }
}