#include <stdio.h>

int Queue[100001] = {
    0,
};
int back = 0, front = 0;
int visit[100001] = {
    0,
};
int fin[100001] = {
    0,
};
int K;

void find(int X)
{
    if (X == K)
        return;
    if (X != 0 && (!fin[X - 1] || fin[X - 1] == fin[X] + 1))
    {
        if(!visit[X - 1]) {
            Queue[back++] = X - 1;
            fin[X - 1] = fin[X] + 1;
        }
        visit[X - 1] += visit[X];
    }
    if (X != 100000 && X < K && (!fin[X + 1] || fin[X + 1] == fin[X] + 1))
    {
        if(!visit[X + 1]) {
            Queue[back++] = X + 1;
            fin[X + 1] = fin[X] + 1;
        }
        visit[X + 1] += visit[X];
    }
    if (X * 2 <= 100000 && X < K && (!fin[X * 2] || fin[X * 2] == fin[X] + 1))
    {
        if(!visit[X * 2]) {
            Queue[back++] = X * 2;
            fin[X * 2] = fin[X] + 1;
        }
        visit[X * 2] += visit[X];
        
    }
}

void bfs()
{
    int pre = back;
    while (front != pre)
    {
        find(Queue[front++]);
    }
}

int main()
{
    int N;
    scanf("%d %d", &N, &K);
    Queue[back++] = N;
    visit[N] = 1;
    while (front != back && !visit[K])
    {
        bfs();
    }
    printf("%d\n%d", fin[K], visit[K]);
}