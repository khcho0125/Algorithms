#include<stdio.h>

int main() {
    double galon = 3.785411784, milja = 1609.344, input;
    scanf("%lf", &input);
    milja *= input;
    galon = galon / (milja / 1000);
    printf("%lf", galon * 100);
}