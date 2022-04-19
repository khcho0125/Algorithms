#include<stdio.h>
#include<string.h>

typedef struct XY {
    int x;
    int y;
}xy;

int N, result = 0;
int space[20][20] = {0,};
int visit[20][20] = {0,};

xy queue[400] = {0,};
int front = 0, back = 0;
int size = 2, ates = 0;

void shark();

int main() {
    int move = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &space[i][j]);
            if(space[i][j] == 9) {
                queue[back].x = i;
                queue[back++].y = j;
                visit[i][j] = 1;
                space[i][j] = 0;
            }
        }
    }
    while(front < back) {
        shark(move++);
    }
    printf("%d", result);
}

void shark(int move) {
    int x, y, temp = back, test;
    while(front < temp) {
        x = queue[front].x;
        y = queue[front++].y;
        if(space[x][y] != 0 && space[x][y] < size) {
            ates++;
            result = move;
            memset(visit, 0, sizeof(visit));
            while(front < temp) {
                test = space[queue[front].x][queue[front].y];
                if(test != 0 && test < size && (queue[front].x < x || (queue[front].x == x && queue[front].y < y))) {
                    x = queue[front].x;
                    y = queue[front].y;
                }
                front++;
            }
            memset(queue, 0, sizeof(queue));
            back = 0;
            front = 0;
            temp = 0;
            visit[x][y] = 1;
            if(ates == size) {
                ates = 0;
                size++;
            }
            space[x][y] = 0;
        }
        

        if(x != 0 && !visit[x - 1][y] && size >= space[x - 1][y]) {
            queue[back].x = x - 1;
            queue[back++].y = y;
            visit[x - 1][y] = 1;
        }
        if(y != 0 && !visit[x][y - 1] && size >= space[x][y - 1]) {
            queue[back].x = x;
            queue[back++].y = y - 1;
            visit[x][y - 1] = 1;
        }
        if(y + 1 != N && !visit[x][y + 1] && size >= space[x][y + 1]) {
            queue[back].x = x;
            queue[back++].y = y + 1;
            visit[x][y + 1] = 1;
        }
        if(x + 1 != N && !visit[x + 1][y] && size >= space[x + 1][y]) {
            queue[back].x = x + 1;
            queue[back++].y = y;
            visit[x + 1][y] = 1;
        }
    }
}