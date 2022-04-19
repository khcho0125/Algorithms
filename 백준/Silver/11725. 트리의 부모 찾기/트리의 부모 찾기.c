#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node* link;
}node;

typedef struct Tree {
    node* link;
    node* back;
}tree;

tree T[100000] = {0,};
int visit[100000] = {0,};

void dfs(int value, int parent) {
    visit[value - 1] = parent;
    node* temp = (node*)malloc(sizeof(node));
    temp = T[value - 1].link;
    while(temp != NULL) {
        if(!visit[temp->value - 1]) {
            dfs(temp->value, value);
        }
        temp = temp->link;
    }
}

int main() {
    int N, v1, v2;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        T[i].link = NULL;
    }
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %d", &v1, &v2);
        node* n1 = (node*)malloc(sizeof(node));
        n1->value = v2;
        n1->link = NULL;
        if(T[v1 - 1].link == NULL) {
            T[v1 - 1].link = n1;
            T[v1 - 1].back = n1;
        }
        else {
            T[v1 - 1].back->link = n1;
            T[v1 - 1].back = n1;
        }
        node* n2 = (node*)malloc(sizeof(node));
        n2->value = v1;
        n2->link = NULL;
        if(T[v2 - 1].link == NULL) {
            T[v2 - 1].link = n2;
            T[v2 - 1].back = n2;
        }
        else {
            T[v2 - 1].back->link = n2;
            T[v2 - 1].back = n2;
        }
    }
    dfs(1, 1);
    for(int i = 1; i < N; i++) {
        printf("%d\n", visit[i]);
    }
}