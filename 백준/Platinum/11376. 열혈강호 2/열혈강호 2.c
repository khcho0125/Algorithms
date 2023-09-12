#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define N_MAX 1001

typedef struct Employee {
    int i;
    struct Employee* and;
}E;

typedef struct Work {
    E* link;
    E* back;
}W;

W graph[N_MAX];
int manager[N_MAX + N_MAX];
int visited[N_MAX];
int N, M;

bool dfs(int idx, int turn) {
    if(visited[idx] == turn) {
        return false;
    }

    visited[idx] = turn;

    for(E* list = graph[idx].link; list != NULL; list = list->and) {
        if(manager[list->i] == -1 || dfs(manager[list->i], turn)) {
            manager[list->i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(manager, -1, sizeof(manager));
    int result = 0;

    for(int i = 1; i <= M; i++) {
        result += dfs(i, i);
    }

    return result;
}

int main() {
    int c, w;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &w);
            E* Wtoi = (E*)malloc(sizeof(E));
            E* Wtoii = (E*)malloc(sizeof(E));
            Wtoi->i = i;
            Wtoii->i = i + N;
            Wtoi->and = Wtoii;
            Wtoii->and = NULL;

            if(graph[w].link == NULL) graph[w].link = Wtoi;
            else graph[w].back->and = Wtoi;
            graph[w].back = Wtoii;
        }
    }

    printf("%d", bipartite());
}