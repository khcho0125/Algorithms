#include<stdio.h>
#include<stdlib.h>

#define INF 987654321

typedef struct pair {
    int v;
    int w;
}pair;

typedef struct Edge {
    int v;
    int w;
    struct Edge* link;
}Edge;

typedef struct Vertex {
    Edge* link;
    Edge* back;
}Vertex;

int dist[1001];
int house[100];
pair heap[10000];
Vertex node[1001];
int temp = 0;

void QIn(int v, int w) {
    int index = ++temp;
    while(index != 1 && heap[index / 2].w > w) {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = (pair){v, w};
}

pair QOut() {
    pair top = heap[1];
    pair last = heap[temp--];
    int child = 2, parent = 1;
    while(child <= temp) {
        if(child + 1 <= temp && heap[child].w > heap[child + 1].w) {
            child++;
        }

        if(heap[child].w > last.w) break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = last;
    return top;
}

int Dijkstra(int start, int V, int N) {
    int result = 0;
    pair get;
    Edge* connect = (Edge*)malloc(sizeof(Edge));
    for(int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;
    QIn(start, 0);
    while(temp) {
        get = QOut();
        
        if(get.w > dist[get.v]) continue;

        connect = node[get.v].link;
        while(connect != NULL) {
            if(dist[connect->v] > get.w + connect->w) {
                dist[connect->v] = get.w + connect->w;
                QIn(connect->v, dist[connect->v]);
            }
            connect = connect->link;
        }
    }

    for(int i = 0; i < N; i++) {
        if(dist[house[i]] == INF) {
            dist[house[i]] = -1;
        }
        result += dist[house[i]];
    }

    return result;
}

int main() {
    int N, V, E, A, B, n, h, a, b;
    scanf("%d %d %d %d %d", &N, &V, &E, &A, &B);

    for(int i = 0; i < N; i++) {
        scanf("%d", &house[i]);
    }

    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &h);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = a;
        one->w = h;
        if(node[b].link == NULL) {
            node[b].link = one;
        }
        else {
            node[b].back->link = one;
        }
        node[b].back = one;

        Edge* two = (Edge*)malloc(sizeof(Edge));
        two->link = NULL;
        two->v = b;
        two->w = h;
        if(node[a].link == NULL) {
            node[a].link = two;
        }
        else {
            node[a].back->link = two;
        }
        node[a].back = two;
    }

    printf("%d", Dijkstra(A, V, N) + Dijkstra(B, V, N));
}