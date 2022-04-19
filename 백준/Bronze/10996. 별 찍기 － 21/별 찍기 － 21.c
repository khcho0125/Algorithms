#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i <= n*2; i++)
    {
        for(int j=1; j <=n; j++)
        {
            if((i+j)%2==1)
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