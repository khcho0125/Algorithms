#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int idx;
    struct node* link;
}node;

typedef struct Tree {
    int v;
    node* link;
    node* back;
}T;

T tree[1000001];
bool visit[1000001] = {0,};
bool adapter[1000001] = {0,};
int result = 0;

int DFS(int idx) {
    node* query = (node*)malloc(sizeof(node));
    query = tree[idx].link;
    while(query != NULL) {
        if(!visit[query->idx]) {
            visit[query->idx] = true;
            tree[query->idx].v--;
            if(DFS(query->idx)) {
                adapter[idx] = 1;
            }
        }
        query = query->link;
    }
    if(tree[idx].v == 0 || !adapter[idx]) {
        return 1;
    }
    result++;
    return 0;
}

int main() {
    int N, u, v;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %d", &u, &v);
        node* one = (node*)malloc(sizeof(node));
        one->idx = v;
        one->link = NULL;
        if(tree[u].link == NULL) {
            tree[u].link = one;
            tree[u].back = one;
        }
        else {
            tree[u].back->link = one;
            tree[u].back = one;
        }
        tree[u].v++;
        node* two = (node*)malloc(sizeof(node));
        two->idx = u;
        two->link = NULL;
        if(tree[v].link == NULL) {
            tree[v].link = two;
            tree[v].back = two;
        }
        else {
            tree[v].back->link = two;
            tree[v].back = two;
        }
        tree[v].v++;
    }
    visit[1] = true;
    DFS(1);
    if(N == 1) {
        printf("1");
    }
    else {
        printf("%d", result);
    }
}