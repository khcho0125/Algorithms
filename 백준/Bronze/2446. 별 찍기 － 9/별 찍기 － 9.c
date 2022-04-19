#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int re1=0; re1 < n; re1++)
    {
        for(int blk1=0; blk1 < re1; blk1++)
        {
            printf(" ");
        }
        for(int s1=1; s1 < n*2-re1*2; s1++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int re2=1; re2 < n; re2++)
    {
        for(int blk2=1; blk2 < n-re2; blk2++)
        {
            printf(" ");
        }
        for(int s2=0; s2 < re2*2+1; s2++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}