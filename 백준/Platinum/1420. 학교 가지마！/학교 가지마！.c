#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_N 100
#define MAX_V (MAX_N * MAX_N * 2)
#define MAX_E (MAX_N * MAX_N * 10)
#define REVERSE (MAX_N * MAX_N)
#define abs(x) ((x) < 0 ? (x) * -1 : x)

typedef struct Point {
    int x, y;
}P;

typedef struct Edge {
    int v, c;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
    int size;
}V;

bool map[MAX_V];

V graph[MAX_V];

int flow[MAX_V][5];
int revEdge[MAX_V][5];

int layer[MAX_V];
int work[MAX_V];

int queue[MAX_E];
int front, back;

P move[4] = { 
    {.x = 1, .y = 0},
    {.x = 0, .y = 1},
    {.x = -1, .y = 0},
    {.x = 0, .y = -1}
};
int N, M;

int ID(int x, int y) {
    return x * M + y;
}

int makeEdge(int u, int v, int capacity) {
    E* forward = (E*)malloc(sizeof(E));
    forward->v = v;
    forward->c = capacity;
    forward->link = NULL;

    if (graph[u].link == NULL) {
        graph[u].link = forward;
    }
    else {
        graph[u].back->link = forward;
    }
    graph[u].back = forward;

    return graph[u].size++;
}

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool BFS(int sourceId, int sinkId) {
    memset(layer, -1, sizeof(layer));
    front = back = 0;

    queue[back++] = sourceId;
    layer[sourceId] = 0;
    
    while(front < back) {
        int u = queue[front++];

        E* next = graph[u].link;
        for(int i = 0; next != NULL; i++, next = next->link) {
            if (layer[next->v] == -1 && next->c - flow[u][i] > 0) {
                layer[next->v] = layer[u] + 1;
                queue[back++] = next->v;
            }
        }
    }

    return layer[sinkId] != -1;
}

int DFS(int u, int sinkId) {
    if (u == sinkId) {  
        return 1;
    }

    E* next = graph[u].link;
    for(int i = 0; i < work[u]; i++) next = next->link;

    for(; next != NULL; work[u]++, next = next->link) {
        if (layer[next->v] == layer[u] + 1 && next->c - flow[u][work[u]] > 0) {
            int result = DFS(next->v, sinkId);

            if (result > 0) {
                flow[u][work[u]] += result;
                flow[next->v][revEdge[u][work[u]]] -= result;

                return result;
            }
        }
    }
    
    return 0;
}

int Dinitz(int sourceId, int sinkId) {
    int maxflow = 0;

    while(BFS(sourceId, sinkId)) {
        memset(work, 0, sizeof(work));

        while(true) {
            int value = DFS(sourceId, sinkId);
            
            if (!value) break;

            maxflow += value;
        }
    }

    return maxflow;
}

int main() {
    char space;
    P S, T;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &space);

            if (space == '#') continue;

            map[ID(i, j)] = true;

            if (space == 'K') {
                S = (P){.x = i, .y = j};
            }
            else if (space == 'H') {
                T = (P){.x = i, .y = j};
            }
        }
    }

    if (abs(S.y - T.y) + abs(S.x - T.x) == 1) {
        printf("-1");
        return 0;
    }

    int source = ID(S.x, S.y) + REVERSE;
    int sink = ID(T.x, T.y);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int in = ID(i, j);

            if (!map[in]) continue;

            int out = in + REVERSE;

            int inEdge = makeEdge(in, out, 1);
            int outEdge = makeEdge(out, in, 0);

            revEdge[in][inEdge] = outEdge;
            revEdge[out][outEdge] = inEdge;

            for(int k = 0; k < 4; k++) {
                int side = ID(i + move[k].x, j + move[k].y);

                if (inside(i + move[k].x, j + move[k].y) && map[side]) {
                    int osEdge = makeEdge(out, side, 1);
                    int soEdge = makeEdge(side, out, 0);

                    revEdge[out][osEdge] = soEdge;
                    revEdge[side][soEdge] = osEdge;
                }
            }
        }
    }

    printf("%d", Dinitz(source, sink));
}