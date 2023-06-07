#include<stdio.h>
#include<string.h>

typedef struct Point {
    int x, y;
}P;

int N, M;
int ans = 0;

int map[600][600];
P queue[360000];
int front = 0, back = 0;

void insert(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || !map[x][y]) return;

    if(map[x][y] == 1) ans++;

    map[x][y] = 0;
    queue[back++] = (P){.x = x, .y = y};
}

void BFS(P s) {
    map[s.x][s.y] = 0;
    queue[back++] = s;

    for(; front != back; front++) {
        P value = queue[front];

        insert(value.x + 1, value.y);
        insert(value.x - 1, value.y);
        insert(value.x, value.y + 1);
        insert(value.x, value.y - 1);
    }
}

int main() {
    memset(map, -1, sizeof(map));

    P s;
    char input;
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &input);

            if(input == 'I') {
                s.x = i;
                s.y = j;
            }
            else if(input == 'X') {
                map[i][j] = 0;
            }
            else if(input == 'P') {
                map[i][j] = 1;
            }
        }
    }

    BFS(s);

    ans ? printf("%d", ans) : printf("TT");
}