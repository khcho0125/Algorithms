#include<stdio.h>

int main()
{
    int i, n, m, t, temp;
    scanf("%d %d", &n, &m);
    t = n/100;
    for(i=0;i < 99; i++)
    {
        temp=(t*100)+i;
        if(temp%m==0)
        {
            break;
        }
    }
    printf("%02d", i);
    return 0;
}