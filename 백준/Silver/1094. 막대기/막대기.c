#include<stdio.h>

int main()
{
    int n, m = 0;
    int count = 0;
    scanf("%d", &n);
    while(n != 0)
    {
        m = n % 2;
        n = n / 2;
        if(m == 1)
        {
            count++;
        }
    }
    printf("%d", count);
}