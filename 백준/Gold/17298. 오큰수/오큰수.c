#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, pre, temp;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    int *stack = (int *)malloc(sizeof(int) * N);
    for (i = 0, pre = 0; i < N; i++, pre++)
    {
        scanf("%d", &arr[i]);
        for (temp = pre - 1; temp > -1; temp--)
        {
            if(arr[stack[temp]] >= arr[i]) break;
            if (arr[stack[temp]] < arr[i])
            {
                arr[stack[temp]] = arr[i];
                pre--;
            }
            
        }
        stack[pre] = i;
    }
    for (i = 0; i < pre; i++)
    {
        arr[stack[i]] = -1;
        printf("%d ", arr[i]);
    }
    for (i = pre; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}