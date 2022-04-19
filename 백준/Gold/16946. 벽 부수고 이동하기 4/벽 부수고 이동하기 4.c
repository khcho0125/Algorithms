#include<stdio.h>

typedef struct Queue {
    int x, y;
}Q;

Q queue[1000000];
int map[1000][1000];
int result[1000][1000] = {0,};
int visited[1000][1000] = {0,};
int pre = 0, N, M;

int DFS(int x, int y) {
    int sum = 1;

    if(x != 0 && !map[x - 1][y] && !visited[x - 1][y]) {
        visited[x - 1][y] = visited[x][y];
        sum += DFS(x - 1, y);
    }

    if(y != 0 && !map[x][y - 1] && !visited[x][y - 1]) {
        visited[x][y - 1] = visited[x][y];
        sum += DFS(x, y - 1);
    }

    if(x + 1 != N && !map[x + 1][y] && !visited[x + 1][y]) {
        visited[x + 1][y] = visited[x][y];
        sum += DFS(x + 1, y);
    }

    if(y + 1 != M && !map[x][y + 1] && !visited[x][y + 1]) {
        visited[x][y + 1] = visited[x][y];
        sum += DFS(x, y + 1);
    }

    if(x != 0 && map[x - 1][y] && visited[x - 1][y] != visited[x][y]) {
        visited[x - 1][y] = visited[x][y];
        queue[pre].x = x - 1;
        queue[pre++].y = y;
    }

    if(y != 0 && map[x][y - 1] && visited[x][y - 1] != visited[x][y]) {
        visited[x][y - 1] = visited[x][y];
        queue[pre].x = x;
        queue[pre++].y = y - 1;
    }

    if(x + 1 != N && map[x + 1][y] && visited[x + 1][y] != visited[x][y]) {
        visited[x + 1][y] = visited[x][y];
        queue[pre].x = x + 1;
        queue[pre++].y = y;
    }

    if(y + 1 != M && map[x][y + 1] && visited[x][y + 1] != visited[x][y]) {
        visited[x][y + 1] = visited[x][y];
        queue[pre].x = x;
        queue[pre++].y = y + 1;
    }

    return sum;
}

int main() {

    int turn = 1, sum, temp = 0, x, y;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!map[i][j] && !visited[i][j]) {
                visited[i][j] = turn++;
                sum = DFS(i, j);
                while(temp != pre) {
                    x = queue[temp].x;
                    y = queue[temp].y;
                    map[x][y] += sum;
                    temp++;
                }
                temp = 0;
                pre = 0;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d", map[i][j] % 10);
        }
        printf("\n");
    }
}