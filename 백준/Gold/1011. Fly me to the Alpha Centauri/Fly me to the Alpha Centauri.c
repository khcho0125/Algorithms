#include <stdio.h>
#include <math.h>

int main()
{
    long x, y;
    int T, N, temp, result, i;
    scanf("%d", &T);
    for (int j = 0; j < T; j++)
    {
        scanf("%ld %ld", &x, &y);
        N = y - x;
        i = floor(sqrt(N));
        result = i * 2 - 1;
        temp = N - (i * i);
        if (temp != 0)
        {
            if (temp > i)
            {
                result += 2;
            }
            else
            {
                result++;
            }
        }
        printf("%d\n", result);
    }
}