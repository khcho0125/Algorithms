#include <stdio.h>
#include <stdlib.h>

int array[5000001] = {
    0,
};

int sosu[348513] = {
    0,
};

int main()
{
    long long min = 2, max = 0, temp;
    int n, pre = 0, cnt = 0, i, j;
    scanf("%d", &n);
    int *input = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        if (input[i] > max)
        {
            max = input[i];
            for (; min * min <= max; min++)
            {
                if (!array[min])
                {
                    sosu[cnt++] = min;
                    temp = min * 2;
                    while (temp <= 5000000)
                    {
                        array[temp] = 1;
                        temp += min;
                    }
                }
            }
        }
    }
    for(i = 0, j = 0; i < n; i++, j = 0) {
        if(i != 0) printf("\n");

        pre = input[i];
        while((sosu[j] * sosu[j]) <= pre)
        {
            if(pre % sosu[j] == 0)
            {
                printf("%d ", sosu[j]);
                pre /= sosu[j];
            }
            else {
                j++;
                if(j == cnt) {
                    break;
                }
            }
        }
        printf("%d", pre);
    }
}