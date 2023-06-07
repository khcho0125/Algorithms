#include<stdio.h>
#include<string.h>

typedef struct Point {
    int x, y;
}P;

int N, M;

int map[1001][1001];
P queue[1000000];
int front = 0, back = 0;

void insert(int x, int y, int dist) {
    if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] != -1) return;

    map[x][y] = dist;
    queue[back++] = (P){.x = x, .y = y};
}

void BFS(P s) {
    map[s.x][s.y] = 0;
    queue[back++] = s;

    for(; front != back; front++) {
        P value = queue[front];

        insert(value.x + 1, value.y, map[value.x][value.y] + 1);
        insert(value.x - 1, value.y, map[value.x][value.y] + 1);
        insert(value.x, value.y + 1, map[value.x][value.y] + 1);
        insert(value.x, value.y - 1, map[value.x][value.y] + 1);
    }
}

int main() {
    memset(map, -1, sizeof(map));

    P s;
    int input;
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &input);

            if(input == 2) {
                s.x = i;
                s.y = j;
            }
            else if(!input) {
                map[i][j] = 0;
            }
        }
    }

    BFS(s);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}