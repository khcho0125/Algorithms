#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool pop = true;
    int count = 0;
    int temp;
    int n, i, turn = 1, idx = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    while(count != n - 1)
    {
        for(i = 0; i < n; i++) {
            if(!arr[i]) {
                temp = i;
                break;
            }
        }
        for (i = temp; i < n; i += turn)
        {
            if (pop)
            {
                arr[i] = 1;
                pop = false;
                count++;
            }
            else
            {
                pop = true;
            }
        }
        if(turn > 1)
            turn *= 2;
        else turn++;
    }
    for (i = 0; i < n; i++)
    {
        if (!arr[i])
        {
            printf("%d", i + 1);
            break;
        }
    }
}