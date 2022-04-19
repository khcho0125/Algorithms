#include <stdio.h>

int arr[2501][2501] = {
    0,
};
int N = 0, M = 0;
void visited(int x, int y)
{
    if (x != N)
    {
        if (arr[x + 1][y])
        {
            arr[x + 1][y] = 0;
            visited(x + 1, y);
        }
    }

    if (y != M)
    {
        if (arr[x][y + 1])
        {
            arr[x][y + 1] = 0;
            visited(x, y + 1);
        }
    }
    
    if(x != 0) {
        if(arr[x - 1][y]) {
            arr[x - 1][y] = 0;
            visited(x - 1, y);
        }
    }

    if(y != 0) {
        if(arr[x][y - 1]) {
            arr[x][y - 1] = 0;
            visited(x, y - 1);
        }
    }
}

int main()
{
    int K, T, X, Y, idx, i, Case, j;
    scanf("%d", &T);
    for (Case = 0; Case < T; Case++)
    {
        scanf("%d %d %d", &N, &M, &K);
        for (i = 0; i < K; i++)
        {
            scanf("%d %d", &X, &Y);
            arr[X][Y] = 1;
        }
        for (i = 0, idx = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] = 0;
                    visited(i, j);
                    idx++;
                }
            }
        }
        printf("%d\n", idx);
    }
}