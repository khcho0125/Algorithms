#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)

typedef struct Edge {
    int v, w;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
    E* p;
}V;

typedef struct Q {
    int v, sum, edge;
}Q;

Q pq[30000];
int temp = 0;

V city[1001];
int dp[1001][1001];

int tex = 0;

void QIn(int v, int sum, int edge) {
    int idx = ++temp;
    while(idx != 1 && pq[idx / 2].edge > edge) {
        pq[idx] = pq[idx / 2];
        idx /= 2;
    }
    pq[idx] = (Q){.v = v, .sum = sum, .edge = edge};
}

Q Qout() {
    Q top = pq[1];
    Q last = pq[temp--];
    int child = 2, parent = 1;
    while(child <= temp) {
        if(child + 1 <= temp && pq[child].edge > pq[child + 1].edge) {
            child++;
        }

        if(pq[child].edge > last.edge) break;

        pq[parent] = pq[child];
        parent = child;
        child *= 2;
    }
    
    pq[parent] = last;
    return top;
}

void dijkstra(int N, int S, int D) {
    for(int i = 1; i <= N; i++)
        dp[N][i] = -1;
    
    QIn(S, 0, 0);

    while(temp != 0) {
        Q next = Qout();

        if(next.v == D || (dp[next.edge][next.v] != 0 && dp[next.edge][next.v] < next.sum)) continue;   

        city[next.v].p = city[next.v].link;
        while(city[next.v].p != NULL) {

            if(!dp[next.edge + 1][city[next.v].p->v] || dp[next.edge + 1][city[next.v].p->v] > next.sum + city[next.v].p->w) {
                QIn(city[next.v].p->v, next.sum + city[next.v].p->w, next.edge + 1);
                dp[next.edge + 1][city[next.v].p->v] = next.sum + city[next.v].p->w;
            }
            
            city[next.v].p = city[next.v].p->link;
        }
    }
}

int tollFee(int N, int D) {
    int fee = INF;
    for(int k = 1; k < N; k++) {
        if(dp[k][D] > 0) fee = min(fee, dp[k][D] + k * tex);
    }
    
    return fee;
}

int main() {
    int N, M, K, S, D, a, b, w, extra;
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &w);

        E* ab = (E*)malloc(sizeof(E));
        ab->link = NULL;
        ab->v = b;
        ab->w = w;

        E* ba = (E*)malloc(sizeof(E));
        ba->link = NULL;
        ba->v = a;
        ba->w = w;

        if(city[a].link == NULL)
            city[a].link = ab;
        else 
            city[a].back->link = ab;

        if(city[b].link == NULL)
            city[b].link = ba;
        else
            city[b].back->link = ba;

        city[a].back = ab;
        city[b].back = ba;
    }

    dijkstra(N, S, D);

    printf("%d\n", tollFee(N, D));
    for(int i = 0; i < K; i++) {
        scanf("%d", &extra);

        tex += extra;

        printf("%d\n", tollFee(N, D));
    }
}