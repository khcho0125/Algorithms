#include<stdio.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

typedef struct center {
    int Left;
    int Right;
}Diamond;

int map[750][750];
Diamond dp[750][750] = {0,};
int R, C, result = 0;

void setdp(int x, int y) {
    if(x != 0 && y + 1 != C && map[x - 1][y + 1]) {
        dp[x][y].Right = dp[x - 1][y + 1].Right + 1;
    }
    else {
        dp[x][y].Right = 1;
    }
    if(x != 0 && y != 0 && map[x - 1][y - 1]) {
        dp[x][y].Left = dp[x - 1][y - 1].Left + 1;
    }
    else {
        dp[x][y].Left = 1;
    }
}

int main() {
    int size, a;
    scanf("%d %d", &R, &C);
    a = min(R, C);
    size = a / 2 + (a % 2);

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf("%1d", &map[i][j]);
            if(map[i][j]) {
                setdp(i, j);
            }
        }
    }

    for(int i = size; i > 0; i--) {
        for(int j = i - 1; j <= R - i; j++) {
            int down = ((i - 1) * 2);
            for(int k = 0; k <= C - down; k++) {
                if(min(dp[j][k].Right, dp[j][k + down].Left) >= i && min(dp[j + i - 1][k + i - 1].Left, dp[j + i - 1][k + i - 1].Right) >= i) {
                    printf("%d", i);
                    return 0;
                }
            }
        }
    }
    printf("0");
}