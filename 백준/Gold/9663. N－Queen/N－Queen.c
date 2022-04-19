#include <stdio.h>

int map[15][15] = {
    0,
};
int visit[15][15] = {
    0,
};
int result = 0;
int N;

void queen(int X, int Y, int add)
{
    visit[X][Y] += add;
    for (int i = 1; i < N; i++)
    {
        if(X - i >= 0) {
            visit[X - i][Y] += add;
        }
        if(Y - i >= 0) {
            visit[X][Y - i] += add;
        }
        if(X + i < N) {
            visit[X + i][Y] += add;
        }
        if(Y + i < N) {
            visit[X][Y + i] += add;
        }
        if (X - i >= 0 && Y - i >= 0)
        {
            visit[X - i][Y - i] += add;
        }
        if (X - i >= 0 && Y + i < N)
        {
            visit[X - i][Y + i] += add;
        }
        if (Y - i >= 0 && X + i < N)
        {
            visit[X + i][Y - i] += add;
        }
        if (X + i < N && Y + i < N)
        {
            visit[X + i][Y + i] += add;
        }
    }
}

void chess(int X, int* arr, int count)
{
    if (count == 0)
    {
        result++;
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if(!visit[X][i] && !arr[i]) {
                arr[i] = 1;
                queen(X, i, 1);
                chess(X + 1, arr, count - 1);
                queen(X, i, -1);
                arr[i] = 0;
            }
        }
    }
}

int main()
{
    int test[15] = {0,};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        test[i] = 1;
        queen(0, i, 1);
        chess(1, test, N - 1);
        queen(0, i, -1);
        test[i] = 0;
    }
    printf("%d", result);
}