#include<stdio.h>

int a[100001];
int result=-999999999;

int main()
{
    int n, m, data=0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int j = 0; j < m; j++)
    {
        data += a[j];
    }
    for(int k = 0; k <= n-m; k++)
    {
        if(data > result)
        {
            result = data;
        }
        data += a[m+k];
        data -= a[k];
    }
    printf("%d", result);
    return 0;
}