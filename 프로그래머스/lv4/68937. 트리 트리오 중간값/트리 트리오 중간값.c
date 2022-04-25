#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Edge {
    int v;
    struct Edge* link;
}E;

typedef struct Tree {
    E* link;
    E* back;
}T;

T Tree[250001];

bool visit[250001] = {0,};
int cnt = 0;
int endpoint = -1;
int temp = -1;

int DFS(int idx, int w) {
    visit[idx] = 1;
    if(temp < w) {
        temp = w;
        endpoint = idx;
        cnt = 1;
    }
    else if(temp == w) {
        cnt++;
    }
    E* query = (E*)malloc(sizeof(E));
    query = Tree[idx].link;
    while(query != NULL) {
        if(!visit[query->v]) {
            DFS(query->v, w + 1);
        }
        query = query->link;
    }
}

int solution(int n, int** edges, size_t edges_rows, size_t edges_cols) {
    for(int i = 0; i < n - 1; i++) {
        E* one = (E*)malloc(sizeof(E));
        one->link = NULL;
        one->v = edges[i][0];
        if(Tree[edges[i][1]].link == NULL) {
            Tree[edges[i][1]].link = one;
            Tree[edges[i][1]].back = one;
        }
        else {
            Tree[edges[i][1]].back->link = one;
            Tree[edges[i][1]].back = one;
        }
        E* two = (E*)malloc(sizeof(E));
        two->link = NULL;
        two->v = edges[i][1];
        if(Tree[edges[i][0]].link == NULL) {
            Tree[edges[i][0]].link = two;
            Tree[edges[i][0]].back = two;
        }
        else {
            Tree[edges[i][0]].back->link = two;
            Tree[edges[i][0]].back = two;
        }
    }
    
    DFS(1, 0);
    temp = -1;
    cnt = 0;
    memset(visit, 0, sizeof(visit));
    DFS(endpoint, 0);
    if(cnt > 1) {
        return temp;
    }
    temp = -1;
    cnt = 0;
    memset(visit, 0, sizeof(visit));
    DFS(endpoint, 0);
    if(cnt > 1) {
        return temp;
    }
    return temp - 1;
}