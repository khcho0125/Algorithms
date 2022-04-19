#include <stdio.h>

int map[16][16] = {
    0,
};
int N, result = 0;

void DFS(int x, int y, int state) {
    if(x + 1 == N && y + 1 == N) {
        result++;
        return;
    }
    if(y + 1 != N && !map[x][y + 1] && (!state || state == 2)) {
        DFS(x, y + 1, 0);
    }
    if(x + 1 != N && !map[x + 1][y] && state) {
        DFS(x + 1, y, 1);
    }
    if(y + 1 != N && x + 1 != N && !map[x + 1][y + 1] && !map[x][y + 1] && !map[x + 1][y]) {
        DFS(x + 1, y + 1, 2);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    DFS(0, 1, 0);
    printf("%d", result);
}