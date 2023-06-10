#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_V 501
#define MAX_E 10000
#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)

typedef struct Edge {
    int v, capacity;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
}V;

V graph[MAX_V];
int flow[MAX_V][MAX_V];
int layer[MAX_V];
int memo[MAX_V];

int queue[MAX_E];
int front = 0, back = 0;

bool BFS(int, int);
int DFS(int, int, int);
int Dinitz(int, int);

int main() {
    int N, M, A, B, C, S, T;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);

        E* AB = (E*)malloc(sizeof(E));
        E* BA = (E*)malloc(sizeof(E));

        AB->link = BA->link = NULL;
        AB->capacity = BA->capacity = C;
        AB->v = B;
        BA->v = A;

        if(graph[A].link == NULL) {
            graph[A].link = AB;
        }
        else {
            graph[A].back->link = AB;
        }
        graph[A].back = AB;
        
        if(graph[B].link == NULL) {
            graph[B].link = BA;
        }
        else {
            graph[B].back->link = BA;
        }
        graph[B].back = BA;
    }
    scanf("%d %d", &S, &T);

    printf("%d", Dinitz(S, T));
}

bool BFS(int source, int sink) {
    memset(layer, -1, sizeof(layer));
    front = back = 0;

    queue[back++] = source;
    layer[source] = 0;

    while(front < back) {
        int idx = queue[front++];

        for(E* next = graph[idx].link; next != NULL; next = next->link) {
            if(layer[next->v] == -1 && next->capacity - flow[idx][next->v] > 0) {
                layer[next->v] = layer[idx] + 1;
                queue[back++] = next->v;
            }
        }
    }

    return layer[sink] != -1;
}

int DFS(int idx, int amount, int sink) {
    if(idx == sink) {
        return amount;
    }

    E* next = graph[idx].link;
    for(int i = 0; i < memo[idx]; i++) next = next->link;

    for(; next != NULL; next = next->link, memo[idx]++) {
        if(layer[idx] + 1 == layer[next->v] && next->capacity - flow[idx][next->v] > 0) {
            int result = DFS(next->v, min(amount, next->capacity - flow[idx][next->v]), sink);

            if(result) {
                flow[idx][next->v] += result;
                flow[next->v][idx] -= result;

                return result;
            }
        }
    }

    return 0;
}

int Dinitz(int source, int sink) {
    int maxflow = 0;
    while(BFS(source, sink)) {
        memset(memo, 0, sizeof(memo));

        while(true) {
            int value = DFS(source, INF, sink); 

            if(!value) break;

            maxflow += value;
        }
    }

    return maxflow;
}