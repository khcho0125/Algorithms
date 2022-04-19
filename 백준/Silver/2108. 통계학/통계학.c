#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 500001

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

int bin[MAX] = {0,};

int main()
{
    int n, i, cnt_max = 0, idx = 1;
    double sum = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*n);
    int list[8001] = {
        0,
    };
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        list[arr[i] + 4000]++;
        sum += arr[i];
    }

    printf("%d\n", (int)round(sum / n));
    qsort(arr, n, sizeof(int), compare);
    printf("%d\n", arr[n / 2]);
    for (i = 0; i < 8001; i++)
    {
        if (cnt_max < list[i])
        {
            cnt_max = list[i];
        }
    }
    for (i = 0; i < 8001; i++)
    {
        if (cnt_max == list[i])
        {
            bin[idx] = i - 4000;
            idx++;
        }
    }
    if (idx > 2)
    {
        printf("%d\n", bin[2]);
    }
    else
    {
        printf("%d\n", bin[1]);
    }
    printf("%d", arr[n - 1] - arr[0]);
}