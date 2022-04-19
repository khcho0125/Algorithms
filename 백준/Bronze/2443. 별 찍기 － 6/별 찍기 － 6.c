#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i <= n; i++)
    {
        for(int nul=0; nul < i-1; nul++)
        {
            printf(" ");
        }
        for(int star=0; star<=((n*2)-(i*2)); star++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}