#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool visit[501];
bool graph[501][501];

bool DFS(int parent, int idx, int N) {
    bool temp = true;
    for(int i = 1; i <= N; i++) {
        if(graph[idx][i]) {
            if(visit[i] && parent != i) {
                temp = false;
            }
            else if(!visit[i]) {
                visit[i] = true;
                temp &= DFS(idx, i, N);
            }
        }
    }
    return temp;
}

int main() {
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for(int turn = 1; N || M; turn++) {
        for(int i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            graph[A][B] = true;
            graph[B][A] = true;
        }

        int count = 0;
        for(int i = 1; i <= N; i++) {
            if(!visit[i]) {
                visit[i] = true;
                count += DFS(0, i, N) ? 1 : 0;
            }
        }

        if(count == 0) {
            printf("Case %d: No trees.\n", turn);
        }
        else if(count == 1) {
            printf("Case %d: There is one tree.\n", turn);
        }
        else {
            printf("Case %d: A forest of %d trees.\n", turn, count);
        }
        scanf("%d %d", &N, &M);
        memset(visit, 0, sizeof(visit));
        memset(graph, 0, sizeof(graph));
    }
}