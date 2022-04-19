#include<stdio.h>
#include<math.h>

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.10lf", n * n * (sqrt(3) / 4));
}