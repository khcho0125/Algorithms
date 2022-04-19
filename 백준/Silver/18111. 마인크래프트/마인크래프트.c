#include <stdio.h>

int main()
{
    int N, M, B, i, j, top, bot, move, result, Block, Case, move_result;
    scanf("%d %d %d", &N, &M, &B);
    int mincraft[N][M];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &mincraft[i][j]);
            if (!i && !j)
            {
                top = mincraft[i][j];
                bot = mincraft[i][j];
            }
            if (top < mincraft[i][j])
                top = mincraft[i][j];
            if (bot > mincraft[i][j])
                bot = mincraft[i][j];
        }
    }
    for (i = 0, move = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            move += mincraft[i][j] - bot;
        }
    }
    move_result = move * 2;
    result = bot;
    for (Case = bot; Case < top + 1; Case++)
    {
        for (i = 0, Block = B, move = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (mincraft[i][j] >= Case)
                {
                    move += (mincraft[i][j] - Case) * 2;
                    Block += mincraft[i][j] - Case;
                }
                else
                {
                    move += Case - mincraft[i][j];
                    Block -= Case - mincraft[i][j];
                }
            }
        }
        if (Block < 0)
        {
            break;
        }
        if (move_result == move && result < Case)
        {
            result = Case;
        }
        else if (move_result > move)
        {
            move_result = move;
            result = Case;
        }
    }
    printf("%d %d", move_result, result);
}