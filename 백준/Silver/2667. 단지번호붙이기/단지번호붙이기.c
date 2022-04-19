#include<stdio.h>

int map[25][25] = {0,};
int visit[25][25] = {0,};
int sort[169] = {0,};
int pre = 0, N;

int danzi(int x, int y) {
    int sum = 1;
    if(x + 1 != N && !visit[x + 1][y] && map[x + 1][y]) {
        visit[x + 1][y] = 1;
        sum += danzi(x + 1, y);
    }
    if(x != 0 && !visit[x - 1][y] && map[x - 1][y]) {
        visit[x - 1][y] = 1;
        sum += danzi(x - 1, y);
    }
    if(y + 1 != N && !visit[x][y + 1] && map[x][y + 1]) {
        visit[x][y + 1] = 1;
        sum += danzi(x, y + 1);
    }
    if(y != 0 && !visit[x][y - 1] && map[x][y - 1]) {
        visit[x][y - 1] = 1;
        sum += danzi(x, y - 1);
    }
    return sum;
}

int main() {
    int count = 0, temp, idx;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j] && map[i][j]) {
                count++;
                visit[i][j] = 1;
                sort[pre++] = danzi(i, j);
            }
        }
    }
    printf("%d\n", count);
    for(int i = 1; i < pre; i++) {
        temp = sort[i];
        idx = i;
        while((idx != 0) && temp < sort[idx - 1]) {
            sort[idx] = sort[idx - 1];
            idx--;
        }
        sort[idx] = temp;
    }
    for(int i = 0; i < pre; i++) {
        printf("%d\n", sort[i]);
    }
}