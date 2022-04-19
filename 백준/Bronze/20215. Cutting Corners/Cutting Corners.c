#include <stdio.h>
#include <math.h>

int main()
{
    int N, W;
    scanf("%d %d", &N, &W);
    printf("%lf", N + W - sqrt(N * N + W * W));
}