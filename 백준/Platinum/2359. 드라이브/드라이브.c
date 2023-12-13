#include<stdio.h>
#include<stdlib.h>

#define N_MAX 501
#define M_MAX 2000

#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)

const int INF = 1e9 + 1;

typedef struct Edge {
    int v, w;
    struct Edge *link;
}E;

typedef struct Vertex {
    E *link;
    E *back;
}V;

V graph[N_MAX];

void makeEdge(int a, int b, int c) {
    E* atob = (E*)malloc(sizeof(E));
    atob->link = NULL;
    atob->v = b;
    atob->w = c;

    if(graph[a].link == NULL) graph[a].link = atob;
    else graph[a].back->link = atob;
    graph[a].back = atob;
}

int cost = INF;
int path[N_MAX];

int inv[N_MAX];
int visited[N_MAX];

void dfs(int turn, int node, int last, int idx, int m, int M) {
    inv[idx] = node;
    visited[node] = turn;

    if(node == last) {
        if(cost > M - m) {
            cost = M - m;
            for(int i = 0; i <= idx; i++) path[i] = inv[i];
        }
        return;
    }

    for(E* temp = graph[node].link; temp != NULL; temp = temp->link) {
        if(visited[temp->v] != turn && m <= temp->w && temp->w <= M)
            dfs(turn, temp->v, last, idx + 1, m, M);
    }
}

int weightSet[M_MAX];

int compare(const void *a, const void *b) {
    int A = *(int*)a;
    int B = *(int*)b;

    return A < B ? -1 : A > B;
}

void travel(int source, int sink, int M) {
    int p = 0, q = 0;

    qsort(weightSet, M, sizeof(int), compare);

    for(int t = 1; q < M; t++) {
        dfs(t, source, sink, 0, weightSet[p], weightSet[q]);

        if(visited[sink] == t) {
            p++;
            if(q < p) q = p;
        }
        else q++;
    }
}

int main() {
    int n, m, S, T, a, b, c;
    scanf("%d %d %d %d", &n, &m, &S, &T);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        makeEdge(a, b, c);
        makeEdge(b, a, c);

        weightSet[i] = c;
    }

    travel(S, T, m);

    printf("%d\n", cost);
    for(int i = 0; path[i] != T; i++) printf("%d ", path[i]);
    printf("%d", T);
}