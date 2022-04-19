#include <stdio.h>

int map[101] = {
    0,
};
int queue[101] = {
    1,
};
int visit[101] = {
    0,
};
int front = 0, back = 1;

void func(int turn)
{
    int temp = back, Z;
    while (front < temp)
    {
        Z = queue[front++];
        for (int i = 1; i <= 6; i++)
        {
            
            if (!visit[Z + i])
            {
                visit[Z + i] = turn;
                if (map[Z + i])
                {
                    if(!visit[map[Z + i]]) {
                        visit[map[Z + i]] = turn;
                        queue[back++] = map[Z + i];
                    }
                }
                else {
                    queue[back++] = Z + i;
                }
            }
            if(visit[100]) {
                printf("%d", visit[100]);
                return;
            }
        }
    }
}

int main()
{
    int N, M, X, Y, turn = 1;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N + M; i++)
    {
        scanf("%d %d", &X, &Y);
        map[X] = Y;
    }
    while(!visit[100])
    {
        func(turn++);
    }
}