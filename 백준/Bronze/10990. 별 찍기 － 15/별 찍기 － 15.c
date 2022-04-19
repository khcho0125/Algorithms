#include<stdio.h>

int main()
{
    int sud;
    scanf("%d", &sud);
    for(int i=0; i < sud; i++)
    {
        for(int j=1; j <= sud-(i+1); j++)
        {
            printf(" ");
        }
        printf("*");
        for(int k=1; k <= i*2-1; k++)
        {
            printf(" ");
        }
        if(i!=0)
            printf("*");
        printf("\n");
    }
    return 0;
}