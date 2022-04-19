#include<stdio.h>

int m[1000001];
int sml = 1000001;

int main()
{
    int n, result, bis = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
        if(m[i] > bis)
        {
            bis = m[i];
        }
        if(m[i] < sml)
        {
            sml = m[i];
        }
    }
    result = bis * sml;
    printf("%d", result);
}