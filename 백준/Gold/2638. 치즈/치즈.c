#include<stdio.h>

typedef struct Queue {
    int x;
    int y;
}Q;

int map[100][100] = {0,};
int visit[100][100] = {0,};
Q queue[10000] = {0,};
int front = 0, back = 0, cheeze = 0, N, M;

void dfs(int x, int y) {
    if(x != 0 && !visit[x - 1][y]) {
        if(map[x - 1][y]) {
            map[x - 1][y]++;
            if(map[x - 1][y] > 2) {
                cheeze--;
                queue[back].x = x - 1;
                queue[back++].y = y;
                visit[x - 1][y] = 1;
            }
        }
        else {
            visit[x - 1][y] = 1;
            dfs(x - 1, y);
        }
    }
    if(y != 0 && !visit[x][y - 1]) {
        if(map[x][y - 1]) {
            map[x][y - 1]++;
            if(map[x][y - 1] > 2) {
                cheeze--;
                queue[back].x = x;
                queue[back++].y = y - 1;
                visit[x][y - 1] = 1;
            }
        }
        else {
            visit[x][y - 1] = 1;
            dfs(x, y - 1);
        }
    }
    if(x + 1 != N && !visit[x + 1][y]) {
        if(map[x + 1][y]) {
            map[x + 1][y]++;
            if(map[x + 1][y] > 2) {
                cheeze--;
                queue[back].x = x + 1;
                queue[back++].y = y;
                visit[x + 1][y] = 1;
            }
        }
        else {
            visit[x + 1][y] = 1;
            dfs(x + 1, y);
        }
    }
    if(y + 1 != M && !visit[x][y + 1]) {
        if(map[x][y + 1]) {
            map[x][y + 1]++;
            if(map[x][y + 1] > 2) {
                cheeze--;
                queue[back].x = x;
                queue[back++].y = y + 1;
                visit[x][y + 1] = 1;
            }
        }
        else {
            visit[x][y + 1] = 1;
            dfs(x, y + 1);
        }
    }
}

void bfs() {
    int temp = back, x, y;
    while(front != temp) {
        x = queue[front].x;
        y = queue[front++].y;
        dfs(x, y);
    }
}

int main() {
    int count = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j]) cheeze++;
        }
    }
    if(cheeze) {
        visit[0][0] = 1;
        dfs(0, 0);
        count++;
        while(cheeze) {
            bfs();
            count++;
        }
    }
    printf("%d", count);
}