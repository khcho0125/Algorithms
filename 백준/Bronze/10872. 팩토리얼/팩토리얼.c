#include<stdio.h>

int N_(int num)
{
    static int result = 1;
    if(num != 0)
    {
        result *= num;
        N_(num-1);
    }
    else
    {
        return result;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", N_(n));
}