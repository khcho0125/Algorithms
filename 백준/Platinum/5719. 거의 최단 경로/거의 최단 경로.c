#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 987654321

typedef struct Priority {
    int v, w;
}Queue;

Queue path[10000];
int temp = 0;

int place[500][500] = {0,};
int dist[500];
int S, D, N;

void Q_IN(int v, int w) {
    int index = ++temp;
    while(index != 1 && path[index / 2].w > w) {
        path[index] = path[index / 2];
        index /= 2;
    }
    path[index].v = v;
    path[index].w = w;
}

Queue Q_out() {
    Queue top = path[1];
    Queue last = path[temp--];
    int child = 2, parent = 1;
    while(child <= temp) {
        if(child + 1 <= temp && path[child].w > path[child + 1].w) {
            child++;
        }

        if(path[child].w > last.w) {
            break;
        }

        path[parent] = path[child];
        parent = child;
        child *= 2;
    }
    path[parent] = last;
    return top;
}

void DFS(int idx) {
    for(int i = 0; i < N; i++) {
        if(place[i][idx] && dist[idx] == dist[i] + place[i][idx]) {
            place[i][idx] = 0;
            DFS(i);
        }
    }
}

void Dijkstra() {
    Queue room;
    dist[S] = 0;
    Q_IN(S, 0);
    while(temp) {
        room = Q_out();

        if(room.w > dist[room.v]) continue;

        for(int i = 0; i < N; i++) {
            if(place[room.v][i] && dist[i] > room.w + place[room.v][i]) {
                dist[i] = room.w + place[room.v][i];
                Q_IN(i, dist[i]);
            }
        }
    }

    DFS(D);

    for(int i = 0; i < N; i++) {
        dist[i] = INF;
    }

    dist[S] = 0;
    Q_IN(S, 0);
    while(temp) {
        room = Q_out();

        if(room.w > dist[room.v]) continue;

        for(int i = 0; i < N; i++) {
            if(place[room.v][i] && dist[i] > room.w + place[room.v][i]) {
                dist[i] = room.w + place[room.v][i];
                Q_IN(i, dist[i]);
            }
        }
    }
}

int main() {
    int M, U, V, P;
    scanf("%d %d", &N, &M);
    while(N && M) {
        scanf("%d %d", &S, &D);
        for(int i = 0; i < N; i++) {
            dist[i] = INF;
        }
        for(int i = 0; i < M; i++) {
            scanf("%d %d %d", &U, &V, &P);
            place[U][V] = P;
        }

        Dijkstra();

        printf("%d\n", dist[D] == INF ? -1 : dist[D]);

        memset(place, 0, sizeof(place));
        scanf("%d %d", &N, &M);
    }
}