#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;
    return 0;
}

int main()
{

    int min, max, temp, mid, top, low;
    int N, M, i, j;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        min = 0;
        max = N - 1;
        while (min <= max)
        {
            mid = (min + max) / 2;

            if (arr[mid] > temp)
                max = mid - 1;
            else if (arr[mid] <= temp)
                min = mid + 1;
        }
        top = max;
        min = 0;
        max = N - 1;
        while (min <= max) {
            mid = (min + max) / 2;

            if(arr[mid] >= temp)
                max = mid - 1;
            else if(arr[mid] < temp) {
                min = mid + 1;
            }
        }
        low = min;
        printf("%d ", top - low + 1);
    }
}