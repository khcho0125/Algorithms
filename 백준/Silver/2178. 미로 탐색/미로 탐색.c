#include <stdio.h>

int map[101][101] = {
    0,
};

int visit[101][101] = {
    1, 0
};

int x_queue[10000] = {0,};
int y_queue[10000] = {0,};
int cnt_queue[10000] = {0,};
int front = -1, back = 0;
int n, m;

void func(int x, int y, int cnt)
{
    if(x + 1 == n && y + 1 == m) {
        printf("%d", cnt);
        return;
    }
    
    if(map[x + 1][y] && !visit[x + 1][y]) {
        x_queue[back] = x + 1;
        y_queue[back] = y;
        cnt_queue[back] = cnt + 1;
        visit[x + 1][y] = 1;
        back++;
    }
    if(map[x][y + 1] && !visit[x][y + 1]) {
        x_queue[back] = x;
        y_queue[back] = y + 1;
        cnt_queue[back] = cnt + 1;
        visit[x][y + 1] = 1;
        back++;
    }
    if(x > 0) {
        if(map[x - 1][y] && !visit[x - 1][y]) {
            x_queue[back] = x - 1;
            y_queue[back] = y;
            cnt_queue[back] = cnt + 1;
            visit[x - 1][y] = 1;
            back++;
        }
    }
    if(y > 0) {
        if(map[x][y - 1] && !visit[x][y - 1]) {
            x_queue[back] = x;
            y_queue[back] = y - 1;
            cnt_queue[back] = cnt + 1;
            visit[x][y - 1] = 1;
            back++;
        }
    }

    front++;
    func(x_queue[front], y_queue[front], cnt_queue[front]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    func(0, 0, 1);
}