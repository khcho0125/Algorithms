#include <stdio.h>

int graf[100][100] = {
    0,
};
int visit[100][100] = {
    0,
};

void travel(int i, int j, int N)
{
    visit[i][j] = 1;
    if (i == j)
        return;
    for (int m = 0; m < N; m++)
    {
        if (graf[j][m] && !visit[i][m])
        {
            travel(i, m, N);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &graf[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graf[i][j] && !visit[i][j])
            {
                travel(i, j, N);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}