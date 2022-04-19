#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int f=0; f<(n-i); f++)
        {
            printf(" ");
        }
        for(int g=1; g<i*2; g++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int h=1; h <= n; h++)
    {
        for(int j=0; j<=h-1; j++)
        {
            printf(" ");
        }
        for(int k=1; k <(n-h)*2 ; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}