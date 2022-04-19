#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int v, w;
    struct Node* link;
}node;

typedef struct Tree {
    node* link;
    node* back;
}tree;

tree T[1001];
int visit[1001] = {0,};

int DFS(int idx, int end, int sum) {
    visit[idx] = 1;
    if(idx == end) {
        printf("%d\n", sum);
        visit[idx] = 0;
        return 1;
    }
    node* query = (node*)malloc(sizeof(node));
    query = T[idx].link;
    while(query != NULL) {
        if(!visit[query->v]) 
        {
            if(DFS(query->v, end, sum + query->w)) {
                visit[idx] = 0;
                return 1;
            }
        }
        query = query->link;
    }
    visit[idx] = 0;
    return 0;
}

int main() {
    
    int N, M, u, v, w, k, g;
    scanf("%d %d", &N, &M);
    for(int i = 1; i < N; i++) {
        scanf("%d %d %d", &u, &v, &w);
        node* one = (node*)malloc(sizeof(node));
        one->v = v;
        one->w = w;
        one->link = NULL;
        if(T[u].link == NULL) {
            T[u].link = one;
            T[u].back = one;
        }
        else {
            T[u].back->link = one;
            T[u].back = one;
        }
        node* two = (node*)malloc(sizeof(node));
        two->v = u;
        two->w = w;
        two->link = NULL;
        if(T[v].link == NULL) {
            T[v].link = two;
            T[v].back = two;
        }
        else {
            T[v].back->link = two;
            T[v].back = two;
        }
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &k, &g);
        DFS(k, g, 0);
    }
}