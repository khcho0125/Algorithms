#include<stdio.h>

int map[5][5] = {0,};
int R, C, K, result = 0;

void solve(int x, int y, int turn) {
    if(turn == K) {
        result += (x == 0 && y == C - 1);
        return;
    }

    if(x != 0 && !map[x - 1][y]) {
        map[x - 1][y] = 1;
        solve(x - 1, y, turn + 1);
        map[x - 1][y] = 0;
    }

    if(y != 0 && !map[x][y - 1]) {
        map[x][y - 1] = 1;
        solve(x, y - 1, turn + 1);
        map[x][y - 1] = 0;
    }

    if(x != R - 1 && !map[x + 1][y]) {
        map[x + 1][y] = 1;
        solve(x + 1, y, turn + 1);
        map[x + 1][y] = 0;
    }

    if(y != C - 1 && !map[x][y + 1]) {
        map[x][y + 1] = 1;
        solve(x, y + 1, turn + 1);
        map[x][y + 1] = 0;
    }
}

int main() {
    char value;
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &value);
            if(value == 'T') map[i][j] = 1;
        }
    }
    if(!map[R - 1][0]) {
        map[R - 1][0] = 1;
        solve(R - 1, 0, 1);
    }
    printf("%d", result);
}