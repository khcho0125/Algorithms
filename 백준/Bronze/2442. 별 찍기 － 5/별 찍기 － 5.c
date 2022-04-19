#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int k=1; k <=(n-i); k++)
        {
            printf(" ");
        }
        for(int j=1; j<=i; j++)

        {
            printf("*");
        }
        for(int p=1; p<=(i-1); p++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}