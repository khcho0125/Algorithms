#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define N_MAX 80
#define M_MAX 80

#define E_MAX 6

typedef struct Edge {
    int v;
    struct Edge *link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
}V;

bool table[N_MAX * M_MAX];
V graph[N_MAX * M_MAX];

int matching[N_MAX * M_MAX];

int set[N_MAX * M_MAX];
int size;

int visited[N_MAX * M_MAX];
int N, M;

int xmv[E_MAX] = {-1, 0, 1, -1, 0, 1};
int ymv[E_MAX] = {-1, -1, -1, 1, 1, 1};

bool dfs(int u, int turn) {
    if(visited[u] == turn) return false;

    visited[u] = turn;

    for(E* prev = graph[u].link; prev != NULL; prev = prev->link) if(table[prev->v]) {
        if(matching[prev->v] == -1 || dfs(matching[prev->v], turn)) {
            matching[prev->v] = u;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(matching, -1, sizeof(matching));
    memset(visited, 0, sizeof(visited));

    int result = 0;
    for(int i = 0; i < size; i++) {
        result += dfs(set[i], i + 1);
    }

    return result;
}

void buildGraph(int x, int y) {
    int u = x * M_MAX + y;
    for(int i = 0; i < E_MAX; i++) {
        if(x + xmv[i] >= 0 && x + xmv[i] < N_MAX && y + ymv[i] >= 0 && y + ymv[i] < M_MAX) {
            E* edge = (E*)malloc(sizeof(E));
            edge->link = NULL;
            edge->v = (x + xmv[i]) * M_MAX + (y + ymv[i]);
                
            if(graph[u].link == NULL) graph[u].link = edge;
            else graph[u].back->link = edge;
            graph[u].back = edge;
        }
    }
}

void testcase() {
    memset(table, false, sizeof(table));

    char place;
    int seat = 0;
    scanf("%d %d", &N, &M);

    size = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &place);
            if (place == '.') {
                seat += table[i * M_MAX + j] = true;

                if(j & 1) {
                    set[size++] = i * M_MAX + j;
                }
            }
        }
    }

    printf("%d\n", seat - bipartite());
}

int main() {
    for(int i = 0; i < N_MAX; i++) {
        for(int j = 0; j < M_MAX; j++) {
            if(j & 1) buildGraph(i, j);
        }
    }
    
    int C;
    scanf("%d", &C);
    while(C--) testcase();
}