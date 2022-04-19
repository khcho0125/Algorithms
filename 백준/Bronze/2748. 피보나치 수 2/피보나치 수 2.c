#include<stdio.h>

long long int sum[91];

int main()
{
    int n;
    scanf("%d", &n);
    sum[1] = 1;
    sum[0] = 0;
    for(int i = 0; i <= n; i++)
    {
        sum[i+2] = sum[i] + sum[i+1];
    }
    printf("%lld", sum[n]);
}