#include<stdio.h>
#include<stdbool.h>

#define max(a, b) ((a > b) ? a : b)

long map[20][20] = {0,};
bool visit[20][20] = {0,};
int R, C, result = 0;

void DFS(int x, int y, int cnt, long num) {
    if(!(map[x][y] & num)) {
        result = max(result, cnt);
        num = num | map[x][y];
        if(x != 0 && !visit[x - 1][y]) {
            visit[x - 1][y] = true;
            DFS(x - 1, y, cnt + 1, num);
            visit[x - 1][y] = false;
        }
        if(y != 0 && !visit[x][y - 1]) {
            visit[x][y - 1] = true;
            DFS(x, y - 1, cnt + 1, num);
            visit[x][y - 1] = false;
        }
        if(x + 1 != R && !visit[x + 1][y]) {
            visit[x + 1][y] = true;
            DFS(x + 1, y, cnt + 1, num);
            visit[x + 1][y] = false;
        }
        if(y + 1 != C && !visit[x][y + 1]) {
            visit[x][y + 1] = true;
            DFS(x, y + 1, cnt + 1, num);
            visit[x][y + 1] = false;
        }
    }
}

int main() {
    char input;
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &input);
            map[i][j] = (1 << (input - 'A'));
        }
    }
    DFS(0, 0, 1, 0);
    printf("%d", result);
}