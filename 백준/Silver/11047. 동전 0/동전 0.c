#include<stdio.h>

int main()
{
    int n, h=0, result=0;
    int a[11];
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int j = n - 1; 0 <= j; j--)
    {
        if(h / a[j] != 0)
        {
            result += h / a[j];
            h = h % a[j];
        }
    }
    printf("%d\n", result);
    return 0;
}