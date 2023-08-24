#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define N_MAX 400

typedef struct Edge {
    int x;
    struct Edge* next;
}E;

typedef struct Node {
    E* link;
    E* back;
}N;

N graph[N_MAX * 2];

int capacity[N_MAX * 2][N_MAX * 2];
int flow[N_MAX * 2][N_MAX * 2];
int visited[N_MAX * 2];

void dfs(int idx, int sink) {
    for(E* road = graph[idx].link; road != NULL && visited[sink] == -1; road = road->next) {
        if (visited[road->x] == -1 && capacity[idx][road->x] - flow[idx][road->x] > 0) {
            visited[road->x] = idx;
            dfs(road->x, sink);
        }
    }
}

int fordFulkerson(int source, int sink) {
    int maxflow = 0;
    while(TRUE) {
        memset(visited, -1, sizeof(visited));

        visited[source] = source;
        dfs(source, sink);
        
        if (visited[sink] == -1) break;

        for(int i = sink; i != source; i = visited[i]) {
            flow[visited[i]][i]++;
            flow[i][visited[i]]--;
        }

        maxflow++;
    }

    return maxflow;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    
    int a, b;
    for(int i = 0; i < n; i++) {
        E* ItoR = (E*)malloc(sizeof(E));
        ItoR->next = NULL;
        ItoR->x = i + N_MAX;
        graph[i].link = ItoR;
        graph[i].back = ItoR;

        E* RtoI = (E*)malloc(sizeof(E));
        RtoI->next = NULL;
        RtoI->x = i;
        graph[i + N_MAX].link = RtoI;
        graph[i + N_MAX].back = RtoI;

        capacity[i][i + N_MAX] = 1;
    }
    
    for(int i = 0; i < p; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        
        int rA = a + N_MAX, rB = b + N_MAX;
        
        E* rAtoB = (E*)malloc(sizeof(E));
        rAtoB->next = NULL;
        rAtoB->x = b;

        graph[rA].back->next = rAtoB;
        graph[rA].back = rAtoB;

        E* BtorA = (E*)malloc(sizeof(E));
        BtorA->next = NULL;
        BtorA->x = rA;

        graph[b].back->next = BtorA;
        graph[b].back = BtorA;

        capacity[rA][b] = 1;


        E* rBtoA = (E*)malloc(sizeof(E));
        rBtoA->next = NULL;
        rBtoA->x = a;

        graph[rB].back->next = rBtoA;
        graph[rB].back = rBtoA;

        E* AtorB = (E*)malloc(sizeof(E));
        AtorB->next = NULL;
        AtorB->x = rB;

        graph[a].back->next = AtorB;
        graph[a].back = AtorB;

        capacity[rB][a] = 1;        
    }

    printf("%d", fordFulkerson(N_MAX, 1));
}