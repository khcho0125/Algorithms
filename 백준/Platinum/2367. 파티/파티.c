#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_N 200
#define MAX_D 100
#define MAX (MAX_N + MAX_D + 2)

const int source = 0, sink = MAX - 1;

typedef struct Edge {
    int v, c;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
    E* memo;
}V;

V graph[MAX];
int flow[MAX][MAX];
int layer[MAX];

int queue[MAX_N * MAX_D];

bool BFS() {
    memset(layer, -1, sizeof(layer));
    int front = 0, back = 0;

    queue[back++] = source;
    layer[source] = 0;

    while(front < back) {
        int idx = queue[front++];

        for(E* next = graph[idx].link; next != NULL; next = next->link) {
            if (layer[next->v] == -1 && next->c - flow[idx][next->v] > 0) {
                layer[next->v] = layer[idx] + 1;
                queue[back++] = next->v;
            }
        }
    }

    return layer[sink] != -1;
}

int DFS(int idx) {
    if (idx == sink) {
        return 1;
    }

    
    for(V* point = &graph[idx]; point->memo != NULL; point->memo = point->memo->link) {
        if(layer[point->memo->v] == layer[idx] + 1 && point->memo->c - flow[idx][point->memo->v] > 0) {
            int result = DFS(point->memo->v);

            if (result) {
                flow[idx][point->memo->v] += result;
                flow[point->memo->v][idx] -= result;

                return result;
            }
        }
    }
    
    return 0;
}

int maxFlow(int V) {
    int maxflow = 0;
    
    while(BFS()) {
        for(int i = 0; i <= V; i++) {
            graph[i].memo = graph[i].link;
        }

        while(true) {
            int value = DFS(source);

            if (!value) break;

            maxflow += value;
        }
    }

    return maxflow;
}

int main() {
    int N, K, D, Z, able;
    scanf("%d %d %d", &N, &K, &D);
    for(int i = 1; i <= D; i++) {
        E* limit = (E*)malloc(sizeof(E));
        limit->v = i;
        limit->link = NULL;

        scanf("%d", &limit->c);

        if (graph[source].link == NULL) {
            graph[source].link = limit;
        }
        else {
            graph[source].back->link = limit;
        }
        graph[source].back = limit;
    }

    for(int i = 1; i <= N; i++) {
        scanf("%d", &Z);

        int chef = D + i;

        E* plate = (E*)malloc(sizeof(E));
        plate->v = sink;
        plate->c = K;
        plate->link = NULL;

        graph[chef].link = plate;
        graph[chef].back = plate;

        for(int j = 0; j < Z; j++) {
            scanf("%d", &able);

            E* cook = (E*)malloc(sizeof(E));
            cook->v = chef;
            cook->c = 1;
            cook->link = NULL;

            if (graph[able].link == NULL) {
                graph[able].link = cook;
            }
            else {
                graph[able].back->link = cook;
            }
            graph[able].back = cook;

            E* reverse = (E*)malloc(sizeof(E));
            reverse->v = able;
            reverse->c = 0;
            reverse->link = NULL;

            graph[chef].back->link = reverse;
            graph[chef].back = reverse;
        }
    }

    printf("%d", maxFlow(N + D));
}