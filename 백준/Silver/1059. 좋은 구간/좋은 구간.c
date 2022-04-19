#include<stdio.h>

int main()
{
    int l, n, m[51] = {0,};
    int x = 0, y = 1001, count = 0;
    scanf("%d", &l);
    for(int i = 0; i < l; i++)
    {
        scanf("%d", &m[i]);
    }
    scanf("%d", &n);
    for(int i = 0; i < l; i++)
    {
        if(n == m[i])
        {
            y = 0;
            break;
        }
        if(m[i] < n && x < m[i])
        {
            x = m[i];
        }
        if(m[i] > n && y > m[i])
        {
            y = m[i];
        }
    }
    for(int i = x+1; i <= n; i++)
    {
        for(int j = i+1; j < y; j++)
        {
            if(j >= n)
                count++;
        }
    }
    printf("%d", count);
}