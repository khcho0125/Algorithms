#include<stdio.h>

int N, M, result = 0;
int map[500][500] = {0,};

void max(int a, int b) {
    result = a > b ? a : b;
}

void check(int x, int y) {
    int sum = 0;
    if(y > 2) {
        sum = map[x][y - 3] + map[x][y - 2] + map[x][y - 1] + map[x][y];
        max(result, sum);
    }
    if(x > 2) {
        sum = map[x - 3][y] + map[x - 2][y] + map[x - 1][y] + map[x][y];
        max(result, sum);
    }

    if(x > 0 && y > 0) {
        sum = map[x - 1][y - 1] + map[x - 1][y] + map[x][y - 1] + map[x][y];
        max(result, sum);
    }

    if(x > 0 && y + 2 < M) {
        sum = map[x][y] + map[x - 1][y] + map[x - 1][y + 1] + map[x - 1][y + 2];
        max(result, sum);
    }
    if(x > 0 && y > 1) {
        sum = map[x][y] + map[x - 1][y] + map[x - 1][y - 1] + map[x - 1][y - 2];
        max(result, sum);
        sum = map[x][y] + map[x][y - 1] + map[x][y - 2] + map[x - 1][y - 2];
        max(result, sum);
        sum = map[x][y] + map[x][y - 1] + map[x][y - 2] + map[x - 1][y];
        max(result, sum);
        sum = map[x][y] + map[x][y - 1] + map[x - 1][y - 1] + map[x - 1][y - 2];
        max(result, sum);
        sum = map[x][y] + map[x][y - 1] + map[x][y - 2] + map[x - 1][y - 1];
        max(result, sum);
    }
    if(x > 1 && y > 0) {
        sum = map[x][y] + map[x][y - 1] + map[x - 1][y - 1] + map[x - 2][y - 1];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 2][y - 1];
        max(result, sum);
        sum = map[x][y] + map[x][y - 1] + map[x - 1][y] + map[x - 2][y];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 1][y - 1] + map[x - 2][y - 1];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 1][y - 1];
        max(result, sum);
    }
    if(x > 1 && y + 1 < M) {
        sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 2][y + 1];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 1][y + 1] + map[x - 2][y + 1];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 1][y + 1];
        max(result, sum);
    }

    if(x > 0 && y + 1 < M && y > 0) {
        sum = map[x][y] + map[x][y - 1] + map[x - 1][y] + map[x - 1][y + 1];
        max(result, sum);
        sum = map[x][y] + map[x - 1][y] + map[x - 1][y + 1] + map[x - 1][y - 1];
        max(result, sum);
    }

}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            check(i, j);
        }
    }
    printf("%d", result);
}