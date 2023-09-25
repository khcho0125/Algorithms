#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 1000000

typedef struct Edge {
    int v, p;
    struct Edge* link;
}E;

typedef struct Vertex {
    E* link;
    E* back;
    bool visited;
}V;

V number[N_MAX + 1];
bool matched[N_MAX + 1];

int matching[N_MAX];
bool visited[N_MAX];

bool inQ[N_MAX + 1];
int queue[N_MAX + 1];
int temp = 0;

bool impossible = false;

void makeEdge(int s, int t, int p, V* graph) {
    E* stot = (E*)malloc(sizeof(E));
    stot->v = t;
    stot->p = p;
    stot->link = NULL;

    if(graph[s].link == NULL) number[s].link = stot;
    else graph[s].back->link = stot;
    graph[s].back = stot;
}

bool dfs(int idx) {
    if(number[idx].visited) return true;

    number[idx].visited = true;

    for(E* prev = number[idx].link; prev != NULL; prev = prev->link) {
        if(!visited[prev->p]) {
            visited[prev->p] = true;
            if(dfs(prev->v)) {
                if(matched[idx]) {
                    impossible = true;
                    return true;
                }

                matching[prev->p] = idx;
                matched[idx] = true;
            }
            else {
                matching[prev->p] = prev->v;
                matched[prev->v] = true;
            }
        }
    }

    return matched[idx];
}

int main() {
    int N, obverse, back;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &obverse, &back);

        makeEdge(obverse, back, i, number);
        makeEdge(back, obverse, i, number);
        if(!inQ[obverse]) {
            queue[temp++] = obverse;
            inQ[obverse] = true;
        }
        if(!inQ[back]) {
            queue[temp++] = back;
            inQ[back] = true;
        }
    }

    memset(matching, -1, sizeof(matching));
    for(int i = 0; i < temp; i++) {
        dfs(queue[i]);
    }

    if(impossible) {
        printf("-1");
        return 0;
    }

    for(int i = 0; i < N; i++) {
        printf("%d\n", matching[i]);
    }
}