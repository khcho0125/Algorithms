#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 15
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Pair {
    int x, y, d;
}P;

int map[N_MAX][N_MAX];
int kill[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
P queue[N_MAX * N_MAX];
int N, M, D;

bool BFS(int x, int y) {
    static int cnt = 0;
    cnt++;

    int f = 0, e = 0, time = x + 1;
    queue[e++] = (P){.x = x, .y = y, .d = 1};
    while(f < e) {
        P v = queue[f++];

        if(map[v.x][v.y] == true && kill[v.x][v.y] == 0) {
            kill[v.x][v.y] = time;
            return true;
        }
        
        if(kill[v.x][v.y] == time) {
            return false;
        }

        if(v.d == D) continue;

        if(v.y - 1 >= 0 && visited[v.x][v.y - 1] != cnt) {
            queue[e++] = (P){.x = v.x, .y = v.y - 1, .d = v.d + 1};
            visited[v.x][v.y - 1] = cnt;
        }
        if(v.x + 1 < N && visited[v.x + 1][v.y] != cnt) {
            queue[e++] = (P){.x = v.x + 1, .y = v.y, .d = v.d + 1};
            visited[v.x + 1][v.y] = cnt;
        }
        if(v.y + 1 < M && visited[v.x][v.y + 1] != cnt) {
            queue[e++] = (P){.x = v.x, .y = v.y + 1, .d = v.d + 1};
            visited[v.x][v.y + 1] = cnt;
        }
    }

    return false;
}

int defense(int a, int b, int c) {
    memset(kill, 0, sizeof(kill));
    int ret = 0;
    for(int i = 0; i < N; i++) {
        ret += BFS(i, a) + BFS(i, b) + BFS(i, c);
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &D);
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < M - 2; i++) {
        for(int j = i + 1; j < M - 1; j++) {
            for(int k = j + 1; k < M; k++) {
                int temp = defense(i, j, k);
                result = max(result, temp);
            }
        }
    }

    printf("%d", result);
}