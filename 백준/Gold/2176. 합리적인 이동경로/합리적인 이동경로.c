#include<stdio.h>
#include<stdlib.h>

#define INF 987654321

typedef struct Edge {
    int v;
    int w;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
}V;

typedef struct Queue {
    int v;
    int w;
}Q;

V graph[1001];
Q heap[100000];

int dist[1001];
int dp[1001] = {0,};

int back = 0;

void in(int v, int w) {
    int temp = ++back;
    while(temp != 1 && heap[temp / 2].w > w) {
        heap[temp] = heap[temp / 2];
        temp /= 2;
    }
    heap[temp].v = v;
    heap[temp].w = w;
}

Q* out() {
    Q* first = (Q*)malloc(sizeof(Q));
    first->v = heap[1].v;
    first->w = heap[1].w;
    Q last = heap[back--];
    int temp = 1;
    int child = 2;
    while(child <= back) {
        if(child + 1 <= back && heap[child + 1].w < heap[child].w) {
            child++;
        }

        if(heap[child].w > last.w) {
            break;
        }

        heap[temp] = heap[child];
        temp = child;
        child *= 2;
    }
    heap[temp] = last;
    return first;
}

void dijkstra() {
    E* edge = (E*)malloc(sizeof(E));
    while(back) {
        Q* temp = out();
        edge = graph[temp->v].link;
        while(edge != NULL) {
            if(dist[edge->v] > edge->w + temp->w) {
                dist[edge->v] = edge->w + temp->w;
                in(edge->v, dist[edge->v]);
            }
            edge = edge->link;
        }
    }
}

int DFS(int idx) {
    if(dp[idx]) {
        return dp[idx];
    }

    E* edge = (E*)malloc(sizeof(E));
    edge = graph[idx].link;
    while(edge != NULL) {
        if(dist[idx] > dist[edge->v]) {
            dp[idx] += DFS(edge->v);
        }

        edge = edge->link;
    }
    return dp[idx];
}

int main() {
    int N, M, v1, v2, w;
    scanf("%d %d", &N, &M);
    dist[1] = INF;
    dist[2] = 0;
    for(int i = 3; i <= N; i++) {
        dist[i] = INF;
    }
    dp[2] = 1;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        E* one = (E*)malloc(sizeof(E));
        one->link = NULL;
        one->v = v2;
        one->w = w;
        if(graph[v1].link == NULL) {
            graph[v1].link = one;
        }
        else {
            graph[v1].back->link = one;
        }
        graph[v1].back = one;

        E* two = (E*)malloc(sizeof(E));
        two->link = NULL;
        two->v = v1;
        two->w = w;
        if(graph[v2].link == NULL) {
            graph[v2].link = two;
        }
        else {
            graph[v2].back->link = two;
        }
        graph[v2].back = two;
    }

    in(2, 0);
    dijkstra();
    printf("%d", DFS(1));
}