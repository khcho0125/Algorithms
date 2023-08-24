#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define N_MAX 50

typedef struct Shark {
    int size, speed, intel;
}Shark;

Shark info[N_MAX];
bool graph[N_MAX + N_MAX][N_MAX];

int eaten[N_MAX];
int visit[N_MAX + N_MAX];

int compare(int i, int j) {
    if(info[i].size >= info[j].size && info[i].speed >= info[j].speed && info[i].intel >= info[j].intel) return 1;
    if(info[i].size <= info[j].size && info[i].speed <= info[j].speed && info[i].intel <= info[j].intel) return -1;
    return 0;
}

int N;

bool dfs(int idx, int turn) {
    
    if (visit[idx] == turn) {
        return false;
    }

    visit[idx] = turn;

    for(int i = 0; i < N; i++) {
        if(graph[idx][i]) {
            if(eaten[i] == -1 || dfs(eaten[i], turn)) {
                eaten[i] = idx;

                return true;
            }
        }
    }

    return false;
}

int bipartite() {
    memset(eaten, -1, sizeof(eaten));

    int ans = 0;
    for(int i = 0; i < N + N; i++) {
        ans += dfs(i, i + 1);
    }

    return ans;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &info[i].size, &info[i].speed, &info[i].intel);

        for(int j = 0; j < i; j++) {
            int temp = compare(i, j);
            if(temp == 1) {
                graph[i * 2][j] = true;
                graph[i * 2 + 1][j] = true;
            }
            else if(temp == -1) {
                graph[j * 2][i] = true;
                graph[j * 2 + 1][i] = true;
            }
        }
    }

    printf("%d", N - bipartite());
}