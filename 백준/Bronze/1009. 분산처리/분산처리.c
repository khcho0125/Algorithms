#include<stdio.h>

int main()
{
    long int a, b, n, m;
    scanf("%ld", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &a, &b);
        m = 1;
        for(int j = 0; j < b; j++)
        {
            m = m*a;
            m = m%10;
        }
        if(m==0)
        {
            m = 10;
        }
        printf("%d\n", m);
    }
    return 0;
}