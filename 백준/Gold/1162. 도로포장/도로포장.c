#include<stdio.h>
#include<stdlib.h>

#define ll long long

typedef struct Edge {
    int v;
    ll w;
    struct Edge* link;
}E;

typedef struct Queue {
    int v, cnt;
    ll w;
}Q;

typedef struct City {
    E* link;
    E* back;
}C;

ll dist[10001][21];
C city[10001];
Q Priority_Queue[100000];
int pre = 0, K;

ll min(ll a, ll b) {
    if(a != -1 && a < b) {
        return a;
    }
    return b;
}

void Q_I(int v, ll w, int cnt) {
    int temp = ++pre;
    while(temp != 1 && w < Priority_Queue[temp / 2].w) {
        Priority_Queue[temp] = Priority_Queue[temp / 2];
        temp /= 2;
    }
    Priority_Queue[temp].v = v;
    Priority_Queue[temp].w = w;
    Priority_Queue[temp].cnt = cnt;
}

Q* Q_O() {
    Q* first = (Q*)malloc(sizeof(Q));
    first->v = Priority_Queue[1].v;
    first->w = Priority_Queue[1].w;
    first->cnt = Priority_Queue[1].cnt;
    Q temp = Priority_Queue[pre--];
    int child = 2, parent = 1;
    while(child <= pre) {
        if(child + 1 <= pre && Priority_Queue[child].w > Priority_Queue[child + 1].w) {
            child++;
        }

        if(Priority_Queue[child].w > temp.w) {
            break;
        }

        Priority_Queue[parent] = Priority_Queue[child];
        parent = child;
        child *= 2;
    }
    Priority_Queue[parent] = temp;
    return first;
}

void dijkstra(int N) {
    dist[1][0] = 0;
    Q_I(1, 0, 0);
    Q* tmp = (Q*)malloc(sizeof(Q));
    E* query = (E*)malloc(sizeof(E));
    while(pre != 0) {
        tmp = Q_O();

        if(tmp->w > dist[tmp->v][tmp->cnt]) {
            continue;
        }

        query = city[tmp->v].link;
        while(query != NULL) {
            
            if(tmp->cnt < K && (dist[query->v][tmp->cnt + 1] > tmp->w || dist[query->v][tmp->cnt + 1] == -1)) {
                dist[query->v][tmp->cnt + 1] = tmp->w;
                Q_I(query->v, tmp->w, tmp->cnt + 1);
            }

            if(dist[query->v][tmp->cnt] > tmp->w + query->w || dist[query->v][tmp->cnt] == -1) {
                dist[query->v][tmp->cnt] = tmp->w + query->w;
                Q_I(query->v, tmp->w + query->w, tmp->cnt);
            }
            
            query = query->link;
        }
    }
}

int main() {
    int N, M, u, v;
    ll result, w;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) {
        city[i].link = NULL;
        for(int j = 0; j < 21; j++) {
            dist[i][j] = -1;
        }   
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %lld", &u, &v, &w);
        E* one = (E*)malloc(sizeof(E));
        one->link = NULL;
        one->v = u;
        one->w = w;
        if(city[v].link == NULL) {
            city[v].link = one;
            city[v].back = one;
        }
        else {
            city[v].back->link = one;
            city[v].back = one;
        }
        E* two = (E*)malloc(sizeof(E));
        two->link = NULL;
        two->v = v;
        two->w = w;
        if(city[u].link == NULL) {
            city[u].link = two;
            city[u].back = two;
        }
        else {
            city[u].back->link = two;
            city[u].back = two;
        }
    }
    dijkstra(N);
    result = dist[N][0];
    for(int i = 1; i <= K; i++) {
        result = min(dist[N][i], result);
    }
    printf("%lld", result);
}