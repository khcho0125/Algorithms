#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ll long long

#define INF (1LL << 31) - 1
#define N_MAX 100001
#define P_MAX 32622

typedef struct Edge {
    int v, c, t;
    struct Edge *link;
}E;

typedef struct Vertex {
    E *link, *back;
}V;

V graph[N_MAX];

void makeEdge(int u, int v, int c, int t) {
    E* utov = (E*)malloc(sizeof(E));
    utov->link = NULL;
    utov->c = c;
    utov->v = v;
    utov->t = t;
    
    if(graph[u].link == NULL) graph[u].link = utov;
    else graph[u].back->link = utov;
    graph[u].back = utov;
}

typedef struct Pair {
    int v;
    ll w;
}P;

int dist[N_MAX];
P queue[N_MAX];
int temp;

void pushQ(int v, ll w) {
    int p = ++temp;
    while(p != 1 && w < queue[p / 2].w) {
        queue[p] = queue[p / 2];
        p /= 2;
    }
    queue[p] = (P){.v = v, .w = w};
}

P popQ() {
    P top = queue[1];
    P last = queue[temp--];
    
    int parent = 1, child = 2;
    while(child <= temp) {
        if(child + 1 <= temp && queue[child + 1].w < queue[child].w) child++;
        if(last.w <= queue[child].w) break;

        queue[parent] = queue[child];
        parent = child;
        child *= 2;
    }
    queue[parent] = last;
    return top;
}

ll calculateCost(ll C, ll P, ll T) {
    if(P <= T) return 0;
    return C * (P - T) * (P - T);
}

bool dijkstra(int n, int p, int k) {
    temp = 0;
    dist[1] = 0;
    for(int i = 2; i <= n; i++) dist[i] = INF;
    
    pushQ(1, 0);
    while(temp) {
        P node = popQ();

        if(dist[node.v] < node.w) continue;

        for(E* cur = graph[node.v].link; cur != NULL; cur = cur->link) {
            ll cost = calculateCost(cur->c, p, cur->t);
            if(dist[cur->v] > node.w + cost && node.w + cost <= k) {
                if(cur->v == n) return true;

                dist[cur->v] = node.w + cost;
                pushQ(cur->v, node.w + cost);
            }
        }
    }

    return false;
}

int solution(int n, int k) {
    int low = 1, high = P_MAX + 1;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(dijkstra(n, mid, k)) low = mid;
        else high = mid;
    }

    return low;
}

int main() {
    int N, M, K, A, B, C, T;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &A, &B, &C, &T);
        makeEdge(A, B, C, T);
        makeEdge(B, A, C, T);
    }

    printf("%d", solution(N, K));
}