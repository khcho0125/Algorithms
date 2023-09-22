#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N_MAX 1001

typedef struct Edge {
    int v;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
}V;

V A[N_MAX];
V B[N_MAX];

int matchA[N_MAX];
int matchB[N_MAX];

int visited[N_MAX];
int N, M;

bool dfs(int idx, int turn) {
    if(visited[idx] == turn) return false;

    visited[idx] = turn;

    for(E* prev = A[idx].link; prev != NULL; prev = prev->link) {
        if(matchB[prev->v] == -1 || dfs(matchB[prev->v], turn)) {
            matchA[idx] = prev->v;
            matchB[prev->v] = idx;
            return true;
        }
    }

    return false;
}

void bipartite() {
    memset(matchA, -1, sizeof(matchA));
    memset(matchB, -1, sizeof(matchB));

    for(int i = 1; i <= N; i++) dfs(i, i + 1);
}

bool mvcA[N_MAX];
bool mvcB[N_MAX];

int mvcAset[N_MAX];
int mvcBset[N_MAX];
int ap = 0, bp = 0;

bool mvcDFS(int idx) {
    mvcA[idx] = true;

    for(E* prev = A[idx].link; prev != NULL; prev = prev->link) {
        if(matchB[prev->v] != -1 && !mvcB[prev->v] && !mvcA[matchB[prev->v]]) {
            mvcB[prev->v] = true;
            mvcDFS(matchB[prev->v]);
        }
    }
}

int minimumVertexCover() {
    bipartite();

    for(int i = 1; i <= N; i++) if(matchA[i] == -1) mvcDFS(i);

    int result = 0;
    for(int i = 1; i <= N; i++) if(!mvcA[i]) {
        mvcAset[ap++] = i;
        result++;
    }
    for(int i = 1; i <= M; i++) if(mvcB[i]) {
        mvcBset[bp++] = i;
        result++;
    }

    return result;
}

int main() {
    int cnt, v;
    scanf("%d %d", &N, &M);
    for(int u = 1; u <= N; u++) {
        scanf("%d", &cnt);
        for(int i = 0; i < cnt; i++) {
            scanf("%d", &v);

            E* utov = (E*)malloc(sizeof(E));
            utov->link = NULL;
            utov->v = v;

            if(A[u].link == NULL) A[u].link = utov;
            else A[u].back->link = utov;
            A[u].back = utov;

            E* vtou = (E*)malloc(sizeof(E));
            vtou->link = NULL;
            vtou->v = u;

            if(B[v].link == NULL) B[v].link = vtou;
            else B[v].back->link = vtou;
            B[v].back = vtou;
        }
    }

    printf("%d\n", minimumVertexCover());

    printf("%d ", ap);
    for(int i = 0; i < ap; i++) {
        printf("%d ", mvcAset[i]);
    }
    printf("\n");
    
    printf("%d ", bp);
    for(int i = 0; i < bp; i++) {
        printf("%d ", mvcBset[i]);
    }
}