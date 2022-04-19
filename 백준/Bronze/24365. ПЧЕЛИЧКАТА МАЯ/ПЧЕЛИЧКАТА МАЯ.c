#include<stdio.h>

#define abs(a) ((a) < 0 ? (a) * -1 : a)

int main() {
    int result, sum, a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sum = (a + b + c) / 3;
    b += a - sum;
    c += b - sum;
    result = (sum - a) + (sum - b) + (sum - c);
    printf("%d", abs(result));
}