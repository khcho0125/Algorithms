#include <stdio.h>

int main() {
    long long int A, B, V, COUNT = 1, i, AB;
    scanf("%lld %lld %lld", &A, &B, &V);
    COUNT += (V - A) / (A - B);
    if((V - A) % (A - B)) COUNT++;
    printf("%lld", COUNT);
}