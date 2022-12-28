#include <stdio.h>
#include <stdlib.h>

typedef struct baekjoon
{
    int x;
    int y;
    int op;
} xy;

int map[1000][1000] = {
    0,
};
int visit[1000][1000][2] = {
    0,
};

xy* queue[2000000];
int count = 0, N, M, find = 0, back = 0, front = 0;

void bfs()
{
    int x, y, op;
    int pre = back;
    while (front != pre)
    {
        x = queue[front]->x;
        y = queue[front]->y;
        op = queue[front]->op;
        front++;
        if (x == N - 1 && y == M - 1)
        {
            find = 1;
            return;
        }
        if (x != 0)
        {
            xy *New = (xy *)malloc(sizeof(xy));
            New->x = x - 1;
            New->y = y;
            New->op = op;
            if (map[x - 1][y] == 0 && !visit[x - 1][y][op])
            {
                queue[back++] = New;
                visit[x - 1][y][op] = 1;
            }
            else if(map[x - 1][y] && !op)
            {
                New->op = 1;
                queue[back++] = New;
                visit[x - 1][y][1] = 1;
            }
        }
        if (y != 0 && !visit[x][y - 1][op])
        {
            xy *New = (xy *)malloc(sizeof(xy));
            New->x = x;
            New->y = y - 1;
            New->op = op;
            if (map[x][y - 1] == 0 && !visit[x][y - 1][op])
            {
                queue[back++] = New;
                visit[x][y - 1][op] = 1;
            }
            else if(map[x][y - 1] && !op)
            {
                New->op = 1;
                queue[back++] = New;
                visit[x][y - 1][1] = 1;
            }
        }
        if (x != N - 1 && !visit[x + 1][y][op])
        {
            xy *New = (xy *)malloc(sizeof(xy));
            New->x = x + 1;
            New->y = y;
            New->op = op;
            if (map[x + 1][y] == 0 && !visit[x + 1][y][op])
            {
                queue[back++] = New;
                visit[x + 1][y][op] = 1;
            }
            else if(map[x + 1][y] && !op)
            {
                New->op = 1;
                queue[back++] = New;
                visit[x + 1][y][1] = 1;
            }
        }
        if (y != M - 1 && !visit[x][y + 1][op])
        {
            xy *New = (xy *)malloc(sizeof(xy));
            New->x = x;
            New->y = y + 1;
            New->op = op;
            if (map[x][y + 1] == 0 && !visit[x][y + 1][op])
            {
                queue[back++] = New;
                visit[x][y + 1][op] = 1;
            }
            else if(map[x][y + 1] && !op)
            {
                New->op = 1;
                queue[back++] = New;
                visit[x][y + 1][1] = 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    xy *New = (xy *)malloc(sizeof(xy));
    New->x = 0;
    New->y = 0;
    New->op = 0;
    queue[back++] = New;
    visit[0][0][0] = 1;
    while (front != back && !find)
    {
        count++;
        bfs();
    }
    if (!find)
        printf("-1");
    else
    {
        printf("%d", count);
    }

}