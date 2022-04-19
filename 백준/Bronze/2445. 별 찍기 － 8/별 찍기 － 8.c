#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int o=0; o<i; o++)
        {
            printf("*");
        }
        for(int p=1; p<=(n*2)-(i*2); p++)
        {
            printf(" ");
        }
        for(int a=0; a<i; a++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int q=1; q < n; q++)
    {
        for(int w=0; w < (n-q); w++)
        {
            printf("*");
        }
        for(int e=0; e < (n-(n-q))*2; e++)
        {
            printf(" ");
        }
        for(int r=0; r < (n-q); r++)
        {
            printf("*");
        }
        printf("\n");
    }
}