#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, max, min = 0, temp;
    long long int sum, result = -1, M, get;
    scanf("%d %lld", &N, &M);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if (!i)
        {
            max = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    while (min <= max)
    {
        temp = (min + max) / 2;

        for (i = 0, sum = 0; i < N; i++)
        {
            if (arr[i] > temp)
            {
                sum += arr[i] - temp;
            }
        }

        if (sum >= M && (sum < result || result == -1))
        {
            result = sum;
            get = temp;
        }

        if (sum >= M)
        {
            min = temp + 1;
        }
        else
        {
            max = temp - 1;
        }
    }
    printf("%d", get);
}