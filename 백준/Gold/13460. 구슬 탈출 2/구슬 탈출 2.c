#include <stdio.h>
#include <stdbool.h>

#define INF 11
#define min(a, b) ((a < b) ? a : b)

typedef struct ball
{
    int x;
    int y;
} O;

typedef struct Queue
{
    O R;
    O B;
    int turn;
} Q;

Q queue[10000] = {
    0,
};
int front = 0, back = 0;
int N, M;
char map[10][10];
bool visited[10][10][10][10] = {
    0,
};
int result = INF;

void Tracking(O R, O B, int turn)
{
    if(turn > 10) {
        return;
    }

    int temp;
    O NewR, NewB;
    if ((map[R.x + 1][R.y] != '#' && !(R.x + 1 == B.x && R.y == B.y)) || (map[B.x + 1][B.y] != '#' && !(R.x == B.x + 1 && R.y == B.y)))
    {
        if (R.x < B.x)
        {
            temp = B.x;
            while (map[temp + 1][B.y] != '#')
            {
                temp++;
                if (map[temp][B.y] == 'O')
                {
                    break;
                }
            }
            NewB.x = temp;
            NewB.y = B.y;

            temp = R.x;
            while (map[temp + 1][R.y] != '#' && !(temp + 1 == NewB.x && R.y == NewB.y && map[temp + 1][R.y] != 'O'))
            {
                temp++;
                if (map[temp][R.y] == 'O')
                {
                    break;
                }
            }
            NewR.x = temp;
            NewR.y = R.y;
        }
        else
        {
            temp = R.x;
            while (map[temp + 1][R.y] != '#')
            {
                temp++;
                if (map[temp][R.y] == 'O')
                {
                    break;
                }
            }
            NewR.x = temp;
            NewR.y = R.y;

            temp = B.x;
            while (map[temp + 1][B.y] != '#' && !(temp + 1 == NewR.x && B.y == NewR.y && map[temp + 1][B.y] != 'O'))
            {
                temp++;
                if (map[temp][B.y] == 'O')
                {
                    break;
                }
            }
            NewB.x = temp;
            NewB.y = B.y;
        }
        if (!visited[NewR.x][NewR.y][NewB.x][NewB.y] && map[NewB.x][NewB.y] != 'O')
        {
            if (map[NewR.x][NewR.y] == 'O')
            {
                result = min(result, turn + 1);
            }
            else {
                queue[back].B = NewB;
                queue[back].R = NewR;
                queue[back++].turn = turn + 1;
                visited[NewR.x][NewR.y][NewB.x][NewB.y] = true;
            }
        }
    }

    if ((map[R.x - 1][R.y] != '#' && !(R.x - 1 == B.x && R.y == B.y)) || (map[B.x - 1][B.y] != '#' && !(R.x == B.x - 1 && R.y == B.y)))
    {
        if (R.x > B.x)
        {
            temp = B.x;
            while (map[temp - 1][B.y] != '#')
            {
                temp--;
                if (map[temp][B.y] == 'O')
                {
                    break;
                }
            }
            NewB.x = temp;
            NewB.y = B.y;

            temp = R.x;
            while (map[temp - 1][R.y] != '#' && !(temp - 1 == NewB.x && R.y == NewB.y && map[temp - 1][R.y] != 'O'))
            {
                temp--;
                if (map[temp][R.y] == 'O')
                {
                    break;
                }
            }
            NewR.x = temp;
            NewR.y = R.y;
        }
        else
        {
            temp = R.x;
            while (map[temp - 1][R.y] != '#')
            {
                temp--;
                if (map[temp][R.y] == 'O')
                {
                    break;
                }
            }
            NewR.x = temp;
            NewR.y = R.y;

            temp = B.x;
            while (map[temp - 1][B.y] != '#' && !(temp - 1 == NewR.x && B.y == NewR.y && map[temp - 1][B.y] != 'O'))
            {
                temp--;
                if (map[temp][B.y] == 'O')
                {
                    break;
                }
            }
            NewB.x = temp;
            NewB.y = B.y;
        }
        if (!visited[NewR.x][NewR.y][NewB.x][NewB.y] && map[NewB.x][NewB.y] != 'O')
        {
            if (map[NewR.x][NewR.y] == 'O')
            {
                result = min(result, turn + 1);
            }
            else {
                queue[back].B = NewB;
                queue[back].R = NewR;
                queue[back++].turn = turn + 1;
                visited[NewR.x][NewR.y][NewB.x][NewB.y] = true;
            }
        }
    }

    if ((map[R.x][R.y - 1] != '#' && !(R.x == B.x && R.y - 1 == B.y)) || (map[B.x][B.y - 1] != '#' && !(R.x == B.x && R.y == B.y - 1)))
    {
        if (R.y > B.y)
        {
            temp = B.y;
            while (map[B.x][temp - 1] != '#')
            {
                temp--;
                if (map[B.x][temp] == 'O')
                {
                    break;
                }
            }
            NewB.x = B.x;
            NewB.y = temp;

            temp = R.y;
            while (map[R.x][temp - 1] != '#' && !(R.x == NewB.x && temp - 1 == NewB.y && map[R.x][temp - 1] != 'O'))
            {
                temp--;
                if (map[R.x][temp] == 'O')
                {
                    break;
                }
            }
            NewR.x = R.x;
            NewR.y = temp;
        }
        else
        {
            temp = R.y;
            while (map[R.x][temp - 1] != '#')
            {
                temp--;
                if (map[R.x][temp] == 'O')
                {
                    break;
                }
            }
            NewR.x = R.x;
            NewR.y = temp;

            temp = B.y;
            while (map[B.x][temp - 1] != '#' && !(B.x == NewR.x && temp - 1 == NewR.y && map[B.x][temp - 1] != 'O'))
            {
                temp--;
                if (map[B.x][temp] == 'O')
                {
                    break;
                }
            }
            NewB.x = B.x;
            NewB.y = temp;
        }
        if (!visited[NewR.x][NewR.y][NewB.x][NewB.y] && map[NewB.x][NewB.y] != 'O')
        {
            if (map[NewR.x][NewR.y] == 'O')
            {
                result = min(result, turn + 1);
            }
            else {
                queue[back].B = NewB;
                queue[back].R = NewR;
                queue[back++].turn = turn + 1;
                visited[NewR.x][NewR.y][NewB.x][NewB.y] = true;
            }
        }
    }

    if ((map[R.x][R.y + 1] != '#' && !(R.x == B.x && R.y + 1 == B.y)) || (map[B.x][B.y + 1] != '#' && !(R.x == B.x && R.y == B.y + 1)))
    {
        if (R.y < B.y)
        {
            temp = B.y;
            while (map[B.x][temp + 1] != '#')
            {
                temp++;
                if (map[B.x][temp] == 'O')
                {
                    break;
                }
            }
            NewB.x = B.x;
            NewB.y = temp;

            temp = R.y;
            while (map[R.x][temp + 1] != '#' && !(R.x == NewB.x && temp + 1 == NewB.y && map[R.x][temp + 1] != 'O'))
            {
                temp++;
                if (map[R.x][temp] == 'O')
                {
                    break;
                }
            }
            NewR.x = R.x;
            NewR.y = temp;
        }
        else
        {
            temp = R.y;
            while (map[R.x][temp + 1] != '#')
            {
                temp++;
                if (map[R.x][temp] == 'O')
                {
                    break;
                }
            }
            NewR.x = R.x;
            NewR.y = temp;

            temp = B.y;
            while (map[B.x][temp + 1] != '#' && !(B.x == NewR.x && temp + 1 == NewR.y && map[B.x][temp + 1] != 'O'))
            {
                temp++;
                if (map[B.x][temp] == 'O')
                {
                    break;
                }
            }
            NewB.x = B.x;
            NewB.y = temp;
        }
        if (!visited[NewR.x][NewR.y][NewB.x][NewB.y] && map[NewB.x][NewB.y] != 'O')
        {
            if (map[NewR.x][NewR.y] == 'O')
            {
                result = min(result, turn + 1);
            }
            else {
                queue[back].B = NewB;
                queue[back].R = NewR;
                queue[back++].turn = turn + 1;
                visited[NewR.x][NewR.y][NewB.x][NewB.y] = true;
            }
        }
    }
}

int main()
{
    O R, B;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'R')
            {
                R.x = i;
                R.y = j;
            }
            else if (map[i][j] == 'B')
            {
                B.x = i;
                B.y = j;
            }
        }
    }
    queue[back].turn = 0;
    queue[back].R = R;
    queue[back++].B = B;
    visited[R.x][R.y][B.x][B.y] = true;
    while (front != back)
    {
        Tracking(queue[front].R, queue[front].B, queue[front].turn);
        front++;
    }
    if (result == INF)
    {
        printf("-1");
    }
    else
    {
        printf("%d", result);
    }
}