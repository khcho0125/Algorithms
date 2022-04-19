#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    while (n > 2)
    {
        if (n % 5 == 0)
        {
            count += n / 5;
            n %= 5;
        }
        else
        {
            n -= 3;
            count++;
        }
    }
    if (n)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", count);
    }
}