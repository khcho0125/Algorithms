#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    short idx;
    short weight;
    struct Node* link;
}node;

typedef struct Tree {
    node* link;
}tree;

int visit[10001] = {0,};
tree list[10001];
int length = 0;
int end_point = 0;

void bfs(int x, int point) {
    if(visit[x]) {
        return;
    }

    visit[x] = 1;

    if(length < point) {
        length = point;
        end_point = x;
    }

    node* temp = (node*)malloc(sizeof(node));
    temp = list[x].link;
    while(temp != NULL) {
        bfs(temp->idx, point + temp->weight);
        temp = temp->link;
    }
}

int main() {
    int V, parent, children, weight;
    scanf("%d", &V);
    node* P = (node*)malloc(sizeof(node));
    node* C = (node*)malloc(sizeof(node));
    for(int i = 1; i <= V; i++) {
        list[i].link = NULL;
    }
    for(int i = 0; i < V - 1; i++) {
        scanf("%d %d %d", &parent, &children, &weight);
        P = list[parent].link;
        C = list[children].link;
        node* N = (node*)malloc(sizeof(node));
        N->idx = children;
        N->weight = weight;
        N->link = NULL;
        if(P == NULL) {
            list[parent].link = N;
        }
        else {
            while(P->link != NULL) {
                P = P->link;
            }
            P->link = N;
        }
        node* M = (node*)malloc(sizeof(node));
        M->idx = parent;
        M->weight = weight;
        M->link = NULL;
        if(C == NULL) {
            list[children].link = M;
        }
        else {
            while(C->link != NULL) {
                C = C->link;
            }
            C->link = M;
        }
    }
    bfs(1, 0);
    memset(visit, 0, sizeof(visit));
    bfs(end_point, 0);
    printf("%d", length);
}