#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, pre, i, j;
    scanf("%d %d", &N, &M);
    int *queue = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        queue[i] = i + 1;
    }
    for (i = 0, pre = -1; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            pre++;
            if(pre >= N) {
                pre = 0;
            }
            while (!queue[pre])
            {
                pre++;
                if(pre >= N) {
                    pre = 0;
                }
            }
        }
        if(i == 0) 
            printf("<%d", queue[pre]);
        else
            printf(", %d", queue[pre]);
        queue[pre] = 0;
    }
    printf(">");
}