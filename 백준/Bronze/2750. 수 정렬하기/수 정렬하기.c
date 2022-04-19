#include<stdio.h>

int main()
{
    int n, x;
    int m[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(m[i] < m[j])
            {
                x = m[i];
                m[i] = m[j];
                m[j] = x;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", m[i]);
    }
}