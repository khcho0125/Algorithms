#include<stdio.h>
#include<stdlib.h>

typedef struct baekjoon {
    char value;
    int Llink;
    int Rlink;
}node;

typedef struct Head {
    node* link;
}head;

head tree[26];

void first(int N) {
    printf("%c", tree[N].link->value);
    if(tree[N].link->Llink != -1) {
        first(tree[N].link->Llink);
    }
    if(tree[N].link->Rlink != -1) {
        first(tree[N].link->Rlink);
    }
}

void second(int N) {
    if(tree[N].link->Llink != -1) {
        second(tree[N].link->Llink);
    }
    printf("%c", tree[N].link->value);
    if(tree[N].link->Rlink != -1) {
        second(tree[N].link->Rlink);
    }   
}

void third(int N) {
    if(tree[N].link->Llink != -1) {
        third(tree[N].link->Llink);
    }
    if(tree[N].link->Rlink != -1) {
        third(tree[N].link->Rlink);
    }
    printf("%c", tree[N].link->value);   
}

int main() {
    int N;
    char parent, L, R;
    scanf("%d", &N);
    for(int i = 0; i < 26; i++) {
        tree[i].link = NULL;
    }
    for(int i = 0; i < N; i++) {
        scanf(" %c %c %c", &parent, &L, &R);
        node* newNode = (node*)malloc(sizeof(node));
        newNode->value = parent;
        if(L != '.') newNode->Llink = L - 'A';
        else newNode->Llink = -1;
        if(R != '.') newNode->Rlink = R - 'A';
        else newNode->Rlink = -1;
        tree[parent - 'A'].link = newNode;
    }
    first(0);
    printf("\n");
    second(0);
    printf("\n");
    third(0);
}