#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main() {

    double A, P, R, P2;
    scanf("%lf %lf %lf %lf", &A, &P, &R, &P2);
    if(A / P > R * R * M_PI / P2) {
        printf("Slice of pizza");
    } else {
        printf("Whole pizza");
    }
}
