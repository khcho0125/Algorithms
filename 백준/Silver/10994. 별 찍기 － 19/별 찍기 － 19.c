#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d", &m);
    n = m + m -1;
    for(int i=1; i <= n; i++)
    {
        for(int j=0; j < i; j++){
            if(j%2==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for(int j=0; j<(n*2)-(i*2); j++)
        {
            if(i%2==1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for(int j=0; j < i; j++)
        {
            if((j+i)%2==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j < n-i; j++)
        {
            if(j%2==0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        for(int j=0; j <=(i+i)-1; j++)
        {
            if(i%2==1 || i==1)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        for(int j=1; j <= n-i; j++)
        {
            if((j+i)%2==0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}