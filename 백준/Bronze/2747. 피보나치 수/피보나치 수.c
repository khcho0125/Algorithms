#include<stdio.h>

int main()
{
    int n, m, result = 0;
    int sum[46];
    scanf("%d", &n);
    sum[1] = 1;
    sum[0] = 0;
    for(int i = 0; i <= n; i++)
    {
        sum[i+2] = sum[i] + sum[i+1];
    }
    printf("%d", sum[n]);
}