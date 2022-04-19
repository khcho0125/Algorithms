#include <stdio.h>

int N = 0, sum = 0;
char map[101][101] = {
    0,
};
int visit[100][100] = {
    0,
};
int RG[100][100] = {
    0,
};
int common = 0, redgreen = 0;

void Blue(int, int);
void Green(int, int);
void Red(int, int);

void RedANDGrn(int x, int y)
{
    RG[x][y] = 1;
    if((x + 1 != N) && !RG[x + 1][y] && (map[x + 1][y] == 'R' || map[x + 1][y] == 'G')) {
        RedANDGrn(x + 1, y);
    }
    if((x != 0) && !RG[x - 1][y] && (map[x - 1][y] == 'R' || map[x - 1][y] == 'G')) {
        RedANDGrn(x - 1, y);
    }
    if((y + 1 != N) && !RG[x][y + 1] && (map[x][y + 1] == 'R' || map[x][y + 1] == 'G')) {
        RedANDGrn(x, y + 1);
    }
    if((y != 0) && !RG[x][y - 1] && (map[x][y - 1] == 'R' || map[x][y - 1] == 'G')) {
        RedANDGrn(x, y - 1);
    }
}

int main()
{
    char str;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        getchar();
        for (int j = 0; j < N; j++)
            scanf("%c", &map[i][j]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j])
            {
                visit[i][j] = 1;
                str = map[i][j];
                if (str == 'B')
                {
                    Blue(i, j);
                    redgreen++;
                }
                else if (str == 'G')
                {
                    if(!RG[i][j]) {
                        RedANDGrn(i, j);
                        redgreen++;
                    }
                    Green(i, j);
                }
                else
                {
                    if(!RG[i][j]) {
                        RedANDGrn(i, j);
                        redgreen++;
                    }
                    Red(i, j);
                }
                common++;
            }
        }
    }
    printf("%d %d", common, redgreen);
}

void Red(int x, int y)
{
    if ((x + 1 != N) && !visit[x + 1][y] && map[x + 1][y] == 'R')
    {
        visit[x + 1][y] = 1;
        Red(x + 1, y);
    }
    if ((x != 0) && !visit[x - 1][y] && map[x - 1][y] == 'R')
    {
        visit[x - 1][y] = 1;
        Red(x - 1, y);
    }
    if ((y + 1 != N) && !visit[x][y + 1] && map[x][y + 1] == 'R')
    {
        visit[x][y + 1] = 1;
        Red(x, y + 1);
    }
    if ((y != 0) && !visit[x][y - 1] && map[x][y - 1] == 'R')
    {
        visit[x][y - 1] = 1;
        Red(x, y - 1);
    }
}

void Green(int x, int y)
{
    if ((x + 1 != N) && !visit[x + 1][y] && map[x + 1][y] == 'G')
    {
        visit[x + 1][y] = 1;
        Green(x + 1, y);
    }
    if ((x != 0) && !visit[x - 1][y] && map[x - 1][y] == 'G')
    {
        visit[x - 1][y] = 1;
        Green(x - 1, y);
    }
    if ((y + 1 != N) && !visit[x][y + 1] && map[x][y + 1] == 'G')
    {
        visit[x][y + 1] = 1;
        Green(x, y + 1);
    }
    if ((y != 0) && !visit[x][y - 1] && map[x][y - 1] == 'G')
    {
        visit[x][y - 1] = 1;
        Green(x, y - 1);
    }
}

void Blue(int x, int y)
{
    if ((x + 1 != N && !visit[x + 1][y]) && map[x + 1][y] == 'B')
    {
        visit[x + 1][y] = 1;
        Blue(x + 1, y);
    }
    if ((x != 0 && !visit[x - 1][y]) && map[x - 1][y] == 'B')
    {
        visit[x - 1][y] = 1;
        Blue(x - 1, y);
    }
    if ((y + 1 != N && !visit[x][y + 1]) && map[x][y + 1] == 'B')
    {
        visit[x][y + 1] = 1;
        Blue(x, y + 1);
    }
    if ((y != 0 && !visit[x][y - 1]) && map[x][y - 1] == 'B')
    {
        visit[x][y - 1] = 1;
        Blue(x, y - 1);
    }
}