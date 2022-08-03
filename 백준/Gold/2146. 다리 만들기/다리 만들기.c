#include<stdio.h>

#define min(a, b) (a < b ? a : b)
#define INF 987654321

typedef struct Point {
    int x, y;
}Point;

int movex[4] = {0, 1, 0, -1};
int movey[4] = {1, 0, -1, 0};

int visit[101][101] = {0,};
int map[101][101] = {0,};
Point queue[10000];
int front = 0, back = 0;
int piece = 0, N;

void DFS(int x, int y) {
    int numx, numy;
    for(int i = 0; i < 4; i++) {
        numx = x + movex[i];
        numy = y + movey[i];
        if(numx >= N || numx < 0 || numy >= N || numy < 0) continue;

        if(!visit[numx][numy] && map[numx][numy]) {
            visit[numx][numy] = 1;
            map[numx][numy] = map[x][y];
            queue[back++] = (Point){numx, numy};
            DFS(numx, numy);
        }
    }
}

int BFS() {
    int x, y, temp = back, numx, numy, ans = INF;
    while(front <= temp) {
        x = queue[front].x;
        y = queue[front++].y;

        for(int i = 0; i < 4; i++) {
            numx = x + movex[i];
            numy = y + movey[i];

            if(numx >= N || numx < 0 || numy >= N || numy < 0) continue;

            if(visit[numx][numy] && map[numx][numy] != map[x][y]) {
                ans = min(visit[numx][numy] + visit[x][y] - 2, ans);
            }
            
            if(!visit[numx][numy]) {
                visit[numx][numy] = visit[x][y] + 1;
                map[numx][numy] = map[x][y];
                queue[back++] = (Point){numx, numy};
            }
        }
    }
    return ans == INF ? BFS() : ans;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j] && map[i][j]) {
                visit[i][j] = 1;
                map[i][j] += piece++;
                queue[back++] = (Point){i, j};
                DFS(i, j);
            }
        }
    }

    printf("%d", BFS());
}