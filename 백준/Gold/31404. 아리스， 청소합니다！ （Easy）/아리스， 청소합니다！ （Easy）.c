#include<stdio.h>
#include<stdbool.h>

#define N_MAX 64

int H, W;
int A[N_MAX][N_MAX];
int B[N_MAX][N_MAX];
bool room[N_MAX][N_MAX];
int visited[N_MAX][N_MAX][4];

int axisX[4] = { -1, 0, 1, 0 };
int axisY[4] = { 0, 1, 0, -1 };

int dfs(int x, int y, int d, int ans, int move, int dust) {
    if(x >= H || x < 0 || y >= W || y < 0)
        return ans;

    if(visited[x][y][d] == dust)
        return ans;

    visited[x][y][d] = dust;

    if(!room[x][y]) {
        dust += room[x][y] = true;
        d = (d + A[x][y]) % 4;
        ans = move;
    }
    else {
        d = (d + B[x][y]) % 4;
    }

    return dfs(x + axisX[d], y + axisY[d], d, ans, move + 1, dust);
}

int main() {
    int R, C, D;
    scanf("%d %d %d %d %d", &H, &W, &R, &C, &D);

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf("%1d", &A[i][j]);

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf("%1d", &B[i][j]);

    printf("%d", dfs(R, C, D, 0, 1, 1));
}