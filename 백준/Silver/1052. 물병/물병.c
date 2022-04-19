#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int bottle = 0;
    int N, K, i, len, temp;
    int cnt = 0;
    scanf("%d %d", &N, &K);
    for (cnt = 0, temp = N; temp != 0;)
    {
        if (temp % 2 != 0)
        {
            cnt++;
        }
        temp /= 2;
    }
    while (cnt > K)
    {
        bottle += N & (-N);
        N += N & (-N);
        for (cnt = 0, temp = N; temp != 0; )
        {
            if (temp % 2 != 0)
            {
                cnt++;
            }
            temp /= 2;
        }
    }
    printf("%d", bottle);
    return 0;
}