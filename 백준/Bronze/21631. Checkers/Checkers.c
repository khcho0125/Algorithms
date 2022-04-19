#include <stdio.h>

int main()
{
    long long B, W;
    scanf("%lld %lld", &W, &B);
    if(B) {
        printf("%lld",  1 + (B - 1 > W ? W : B - 1));
    } else {
        printf("0");
    }
}