#include <stdio.h>

int map[1000][1000] = {
    0,
};

int visit[1000][1000] = {
    0,
};

int x_queue[1000000] = {
    0,
};
int y_queue[1000000] = {
    0,
};
int cnt_queue[1000000] = {
    0,
};
int front = -1, back = 0;
int n, m, result = 0;

void func(int x, int y, int cnt)
{

    if (cnt > result)
    {
        result = cnt;
    }
    if (x + 1 < n)
    {
        if (map[x + 1][y] == 0 && !visit[x + 1][y])
        {
            visit[x + 1][y] = 1;
            x_queue[back] = x + 1;
            y_queue[back] = y;
            cnt_queue[back] = cnt + 1;
            back++;
        }
    }
    if (x - 1 >= 0)
    {
        if (map[x - 1][y] == 0 && !visit[x - 1][y])
        {
            visit[x - 1][y] = 1;
            x_queue[back] = x - 1;
            y_queue[back] = y;
            cnt_queue[back] = cnt + 1;
            back++;
        }
    }
    if (y + 1 < m)
    {
        if (map[x][y + 1] == 0 && !visit[x][y + 1])
        {
            visit[x][y + 1] = 1;
            x_queue[back] = x;
            y_queue[back] = y + 1;
            cnt_queue[back] = cnt + 1;
            back++;
        }
    }
    if (y - 1 >= 0) {
        if(map[x][y - 1] == 0 && !visit[x][y - 1]) {
            visit[x][y - 1] = 1;
            x_queue[back] = x;
            y_queue[back] = y - 1;
            cnt_queue[back] = cnt + 1;
            back++;
        }
    }

    if(front == back) {
        return;
    }

    front++;
    func(x_queue[front], y_queue[front], cnt_queue[front]);
}

int main()
{
    int none = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
            {
                x_queue[back] = i;
                y_queue[back] = j;
                cnt_queue[back] = 0;
                visit[i][j] = 1;
                back++;
            }
            else if (map[i][j] == -1)
                none++;
        }
    }

    if (back)
    {
        front++;
        func(x_queue[front], y_queue[front], cnt_queue[front]);
    }

    if (n * m - none == back)
    {
        printf("%d", result);
    }
    else
    {
        printf("-1");
    }
}