#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct Queue {
    int x;
    int y;
}Q;

int map[8][8] = {0,};
int visit[8][8] = {0,};
Q queue[64] = {0,};
int front = 0, back = 0, result = 0, all = 0, N, M;

int dfs(int X, int Y) {
    int temp = 0;
    if(X + 1 != N && !map[X + 1][Y] && !visit[X + 1][Y]) {
        visit[X + 1][Y] = 1;
        temp += dfs(X + 1, Y) + 1;
    }
    if(Y + 1 != M && !map[X][Y + 1] && !visit[X][Y + 1]) {
        visit[X][Y + 1] = 1;
        temp += dfs(X, Y + 1) + 1; 
    }
    if(X != 0 && !map[X - 1][Y] && !visit[X - 1][Y]) {
        visit[X - 1][Y] = 1;
        temp += dfs(X - 1, Y) + 1;
    }
    if(Y != 0 && !map[X][Y - 1] && !visit[X][Y - 1]) {
        visit[X][Y - 1] = 1;
        temp += dfs(X, Y - 1) + 1;
    }
    return temp;
}

void WALL(int cnt, int x, int y) {
    if(cnt == 0) {
        int X, Y, sum = 0;
        while(front != back) {
            X = queue[front].x;
            Y = queue[front++].y;
            sum += dfs(X, Y);
        }
        front = 0;
        memset(visit, 0, sizeof(visit));
        result = max(result, all - sum - 3);
        return;
    }
    for(int i = x; i < N; i++) {
        for(int j = (i == x ? y : 0); j < M; j++) {
            if(!map[i][j] && !visit[i][j]) {
                map[i][j] = 1;
                WALL(cnt - 1, i, j);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    int input;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            scanf("%d", &input);
            if(input) {
                if(input == 2) {
                    queue[back].x = i;
                    queue[back++].y = j;
                }
                map[i][j] = 1;
            }
            else {
                all++;
            }
        }
    }
    WALL(3, 0, 0);
    printf("%d", result);
}