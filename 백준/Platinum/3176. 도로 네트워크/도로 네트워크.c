#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 1000001
#define swap(a, b) {int i = a;a = b;b = i;}
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define MAX 100001

typedef struct Network {
    int v;
    int w;
    struct Network* link;
}Edge;

typedef struct City {
    Edge* link;
    Edge* back;
}Vertex;

typedef struct Path {
    int idx, maximum, minimum;
}Path;

int depth[MAX];
Vertex city[MAX];
Path parent[18][MAX];

void DFS(int idx) {
    Edge* road = (Edge*)malloc(sizeof(Edge));
    road = city[idx].link;
    while(road != NULL) {
        if(depth[road->v] == -1) {
            depth[road->v] = depth[idx] + 1;
            parent[0][road->v].idx = idx;
            parent[0][road->v].maximum = road->w;
            parent[0][road->v].minimum = road->w;
            DFS(road->v);
        }
        road = road->link;
    }
}

int main() {
    int N, A, B, C, K, D, E, Max, Min;
    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
        scanf("%d %d %d", &A, &B, &C);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = B;
        one->w = C;
        if(city[A].link != NULL) {
            city[A].back->link = one;
        }
        else {
            city[A].link = one;
        }
        city[A].back = one;

        Edge* two = (Edge*)malloc(sizeof(Edge));
        two->link = NULL;
        two->v = A;
        two->w = C;
        if(city[B].link != NULL) {
            city[B].back->link = two;
        }
        else {
            city[B].link = two;
        }
        city[B].back = two;
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    parent[0][1].maximum = 0;
    parent[0][1].minimum = INF;
    DFS(1);

    for(int i = 0; i < 17; i++) {
        for(int j = 2; j <= N; j++) {
            if(parent[i][parent[i][j].idx].idx != -1) {
                parent[i + 1][j].idx = parent[i][parent[i][j].idx].idx;
                parent[i + 1][j].maximum = max(parent[i][parent[i][j].idx].maximum, parent[i][j].maximum);
                parent[i + 1][j].minimum = min(parent[i][parent[i][j].idx].minimum, parent[i][j].minimum);
            }
        }
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        scanf("%d %d", &D, &E);
        Max = 0;
        Min = INF;

        if(depth[D] < depth[E]) swap(D, E);
        int d = depth[D] - depth[E];

        for(int i = 0; d; i++) {
            if(d & 1) {
                Max = max(parent[i][D].maximum, Max);
                Min = min(parent[i][D].minimum, Min);
                D = parent[i][D].idx;
            }
            d = d >> 1; 
        }

        if(D != E) {
            for(int i = 17; i >= 0; i--) {
                if(parent[i][D].idx != -1 && parent[i][D].idx != parent[i][E].idx) {
                    Max = max(parent[i][D].maximum, Max);
                    Min = min(parent[i][D].minimum, Min);
                    D = parent[i][D].idx;

                    Max = max(parent[i][E].maximum, Max);
                    Min = min(parent[i][E].minimum, Min);
                    E = parent[i][E].idx;
                }
            }
            Max = max(parent[0][D].maximum, Max);
            Min = min(parent[0][D].minimum, Min);

            Max = max(parent[0][E].maximum, Max);
            Min = min(parent[0][E].minimum, Min);
        }

        printf("%d %d\n", Min, Max);
    }
}