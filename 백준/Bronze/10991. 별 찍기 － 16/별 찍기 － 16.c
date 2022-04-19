#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; i++)
    {
        for(int j=1; j <= n-(i+1); j++)
        {
            printf(" ");
        }
        printf("*");
        for(int k=1; k <= i; k++)
        {
            printf(" ");
            printf("*");
        }
        printf("\n");    
    }
    return 0;
}