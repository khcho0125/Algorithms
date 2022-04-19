#include <stdio.h>

int N, M;
int count = 0;
int vertexArr[1000][1000] = {0,};
int queue[1001] = {0,};
int queueback = 0;
int queuefront = 0;
int visit[1000] = {0,};

void DFS(int V) {
    visit[V] = 1;
    printf("%d ", V + 1);
    count++;
    for(int i = 0; i < N; i++) {
        if(vertexArr[V][i] && !visit[i]) {
            DFS(i);
        }
        if(count == N) return;
    }
}

void BFS(int V) {
    int have = 0;
    printf("%d ", V + 1);
    queuefront++;
    visit[V] = 1;
    for(int i = 0; i < N; i++) {
        if(vertexArr[V][i] && !visit[i]) {
            visit[i] = 1;
            queue[queueback] = i;
            queueback++;
            have++;
        }
    }
    for(int i = 0; i < have; i++) {
        BFS(queue[queuefront]);
    }
}

int main() {
    int V, a, b;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        vertexArr[a - 1][b - 1] = 1;
        vertexArr[b - 1][a - 1] = 1;
    }
    DFS(V - 1);
    for(int i = 0; i < N; i++) {
        visit[i] = 0;
    }
    count = 0;
    printf("\n");
    queue[queueback] = V - 1;
    queueback++;
    BFS(V - 1);
}