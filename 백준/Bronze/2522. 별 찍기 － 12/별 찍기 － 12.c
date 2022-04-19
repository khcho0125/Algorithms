#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j <= n-i; j++)
        {
            printf(" ");
        }
        for(int l=1; l <= i; l++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j <= i; j++)
        {
            printf(" ");
        }
        for(int l=1; l <= n-i; l++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}