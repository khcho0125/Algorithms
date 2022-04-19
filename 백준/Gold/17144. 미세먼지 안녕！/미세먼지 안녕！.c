#include<stdio.h>

typedef struct MUNZI {
    int x, y, weight;
}M;

int airClear[2] = {0,};
M Queue[2500] = {0,};
int A = 0, front = 0, back;

int map[50][50] = {0,};
int R, C;

void Munzi() {
    int x, y, w;
    while(front != back) {
        x = Queue[front].x;
        y = Queue[front].y;
        w = Queue[front++].weight;
        int temp = 0;
        if(x + 1 != R && map[x + 1][y] != -1) {
            map[x + 1][y] += w / 5;
            temp++;
        }
        if(y + 1 != C && map[x][y + 1] != -1) {
            map[x][y + 1] += w / 5;
            temp++;
        }
        if(x != 0 && map[x - 1][y] != -1) {
            map[x - 1][y] += w / 5;
            temp++;
        }
        if(y != 0 && map[x][y - 1] != -1) {
            map[x][y - 1] += w / 5;
            temp++;
        }
        map[x][y] -= (w / 5) * temp;
    }
}

void Clear() {
    int x;
    x = airClear[0];
    for(int i = x; i > 0; i--) {
        if(map[i - 1][0]) {
            if(map[i][0] != -1) {
                map[i][0] = map[i - 1][0];
            }
            map[i - 1][0] = 0;
        }
    }
    for(int i = 0; i < C - 1; i++) {
        if(map[0][i + 1]) {
            map[0][i] = map[0][i + 1];
            map[0][i + 1] = 0;
        }
    }
    for(int i = 0; i < x; i++) {
        if(map[i + 1][C - 1]) {
            map[i][C - 1] = map[i + 1][C - 1];
            map[i + 1][C - 1] = 0;
        }
    }
    for(int i = C - 1; i > 1; i--) {
        if(map[x][i - 1]) {
            map[x][i] = map[x][i - 1];
            map[x][i - 1] = 0;
        }
    }
    x = airClear[1];
    for(int i = x; i < R - 1; i++) {
        if(map[i + 1][0]) {
            if(map[i][0] != -1) {
                map[i][0] = map[i + 1][0];
            }
            map[i + 1][0] = 0;
        }
    }
    for(int i = 0; i < C - 1; i++) {
        if(map[R - 1][i + 1]) {
            map[R - 1][i] = map[R - 1][i + 1];
            map[R - 1][i + 1] = 0;
        }
    }
    for(int i = R - 1; i > x; i--) {
        if(map[i - 1][C - 1]) {
            map[i][C - 1] = map[i - 1][C - 1];
            map[i - 1][C - 1] = 0;
        }
    }
    for(int i = C - 1; i > 1; i--) {
        if(map[x][i - 1]) {
            map[x][i] = map[x][i - 1];
            map[x][i - 1] = 0;
        }
    }
}

int count() {
    int sum = 0;
    front = 0, back = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j] > 4) {
                Queue[back].x = i;
                Queue[back].y = j;
                Queue[back++].weight = map[i][j];
            }
            sum += map[i][j];
        }
    }
    return sum;
}

int main() {
    int T, result = 0;
    scanf("%d %d %d", &R, &C, &T);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1) {
                airClear[A++] = i;
            }
            else if(map[i][j] > 4) {
                Queue[back].x = i;
                Queue[back].y = j;
                Queue[back++].weight = map[i][j];
            }
        }
    }
    for(int i = 0; i < T; i++) {
        Munzi();
        Clear();
        result = count();
    }
    printf("%d", result + 2);
}