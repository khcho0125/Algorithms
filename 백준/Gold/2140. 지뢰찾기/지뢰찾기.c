#include<stdio.h>

typedef struct backjoon {
    int x;
    int y;
}xy;

char map[100][100] = {0,};
xy queue[400] = {0,};
int visit[400] = {0,};
int pre = 0, size, N;

int compare(int x, int y, char str) {
    
    int count = 0;

    if(x != 0) {
        count += map[x - 1][y] == str;
        if(y != 0) 
            count += map[x - 1][y - 1] == str;
        if(y + 1 != N) 
            count += map[x - 1][y + 1] == str;
    }
    if(x + 1 != N) { 
        count += map[x + 1][y] == str;
        if(y != 0)
            count += map[x + 1][y - 1] == str;
        if(y + 1 != N)
            count += map[x + 1][y + 1] == str;
    }

    if(y != 0) {
        count += map[x][y - 1] == str;
    }
    if(y + 1 != N) {
        count += map[x][y + 1] == str;
    }
    
    return count;
}

void change(int x, int y, char str) {
    if(x != 0) {
        if(map[x - 1][y] == '#') {
            map[x - 1][y] = str;
        }

        if(y != 0 && map[x - 1][y - 1] == '#') {
            map[x - 1][y - 1] = str;
        }

        if(y + 1 != N && map[x - 1][y + 1] == '#')  {
            map[x - 1][y + 1] = str;
        }
    }
    if(x + 1 != N) { 
        if(map[x + 1][y] == '#') {
            map[x + 1][y] = str;
        }
        if(y != 0 && map[x + 1][y - 1] == '#') {
            map[x + 1][y - 1] = str;
        }
        if(y + 1 != N && map[x + 1][y + 1] == '#') {
            map[x + 1][y + 1] = str;
        }
    }

    if(y != 0 && map[x][y - 1] == '#') {
        map[x][y - 1] = str;
    }
    if(y + 1 != N && map[x][y + 1] == '#') {
        map[x][y + 1] = str;
    }
}

int check(int x, int y) {
    int num = map[x][y] - '0';
    num -= compare(x, y, '*');
    if(!num) {
        change(x, y, '@');
        return 1;
    }

    if(num == compare(x, y, '#')) {
        change(x, y, '*');
        return 1;
    }

    return 0;
}

int main() {
    int result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %1c", &map[i][j]);
            if(map[i][j] != '#') {
                queue[pre].x = i;
                queue[pre++].y = j;
            }
        }
    }
    size = pre - 1;
    for(int i = 0; size; i++) {
        if(i == pre) i = 0;
        if(!visit[i]) {
            visit[i] = check(queue[i].x, queue[i].y);
            size -= visit[i];
        }
    }
    for(int i = 1; i < N - 1; i++) {
        for(int j = 1; j < N - 1; j++) {
            if(map[i][j] != '@')
                result++;
        }
    }
    printf("%d", result);
}