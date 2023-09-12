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
int manager[N_MAX];
int visited[N_MAX];
int N, M, K;

bool dfs(int idx, int turn) {
    if(visited[idx] == turn) {
        return false;
    }

    visited[idx] = turn;

    for(E* list = graph[idx].link; list != NULL; list = list->and) if(manager[list->i] != idx) {
        if(manager[list->i] == -1 || dfs(manager[list->i], turn)) {
            manager[list->i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(manager, -1, sizeof(manager));
    int R = 0, Rk = 0;

    for(int i = 1; i <= N; i++) {
        R += dfs(i, i);
    }

    for(int i = 1; i <= N; i++) {
        Rk += dfs(i, N + i);
        
        if(Rk == K) break;
    }

    return R + Rk;
}

int main() {
    int c, w;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &w);
            E* Wtoi = (E*)malloc(sizeof(E));
            Wtoi->i = w;
            Wtoi->and = NULL;

            if(graph[i].link == NULL) graph[i].link = Wtoi;
            else graph[i].back->and = Wtoi;
            graph[i].back = Wtoi;
        }
    }

    printf("%d", bipartite());
}