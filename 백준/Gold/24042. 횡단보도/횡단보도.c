#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ll long long

#define N_MAX 100001
#define M_MAX 700000
#define INF (1ULL << 63) - 1

typedef struct Pair {
    int v;
    ll w;
}P;

typedef struct Edge {
    int v;
    ll i;
    struct Edge *link;
}E;

typedef struct Vertex {
    E *link;
    E *back;
}V;

V area[N_MAX];
ll dist[N_MAX];
P queue[M_MAX];
int qp = 0;

void push(int v, ll w) {
    int temp = ++qp;
    while(temp != 1 && queue[temp / 2].w > w) {
        queue[temp] = queue[temp / 2];
        temp /= 2;
    }
    queue[temp] = (P){.v = v, .w = w};
}

P pop() {
    P top = queue[1];
    P last = queue[qp--];

    int child = 2, parent = 1;
    while(child <= qp) {
        if(child + 1 <= qp && queue[child + 1].w < queue[child].w) child++;

        if(last.w < queue[child].w) break;

        queue[parent] = queue[child];
        parent = child;
        child *= 2;
    }
    queue[parent] = last;

    return top;
}

void makeEdge(int u, int v, ll i) {
    E* utov = (E*)malloc(sizeof(E));
    utov->link = NULL;
    utov->v = v;
    utov->i = i;

    if(area[u].link == NULL) area[u].link = utov;
    else area[u].back->link = utov;
    area[u].back = utov;
}

ll calculateWeight(ll cur, ll w, int M) {
    if(cur <= w) return w;
    return ((cur - w) / M + ((cur - w) % M != 0)) * M + w;
}

ll dijkstra(int N, int M) {
    for(int i = 2; i <= N; i++) dist[i] = INF;

    push(1, 0);
    while(qp) {
        P point = pop();

        if(dist[point.v] < point.w) continue;

        for(E* cw = area[point.v].link; cw != NULL; cw = cw->link) {
            ll weight = calculateWeight(point.w, cw->i, M);

            if(weight + 1 < dist[cw->v]) {
                dist[cw->v] = weight + 1;
                push(cw->v, weight + 1);
            }
        }
    }

    return dist[N];
}

int main() {
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        makeEdge(A, B, i);
        makeEdge(B, A, i);
    }

    printf("%lld", dijkstra(N, M));
}