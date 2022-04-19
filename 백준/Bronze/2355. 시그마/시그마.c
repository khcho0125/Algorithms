#include<stdio.h>

int main() {
    double n, m;
    scanf("%lf %lf", &n, &m);
    printf("%.lf", (n + m) * (n > m ? n - m + 1 : m - n + 1) / 2);
}