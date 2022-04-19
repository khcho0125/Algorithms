#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node* Llink;
    struct Node* Rlink;
}node;

typedef struct Tree {
    node* link;
    node* query;
}T;

T tree;

void insert(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    
    newNode->value = value;
    newNode->Llink = NULL;
    newNode->Rlink = NULL;
    if(tree.link == NULL) {
        tree.link = newNode;
    }
    else {
        tree.query = tree.link;
        while(tree.query->value != value) {
            if(tree.query->value < value) {
                if(tree.query->Rlink == NULL) {
                    tree.query->Rlink = newNode;
                }
                tree.query = tree.query->Rlink;
            }
            else {
                if(tree.query->Llink == NULL) {
                    tree.query->Llink = newNode;
                }
                tree.query = tree.query->Llink;
            }
        }
    }
}

void Print(node* N) {
    if(N->Llink != NULL) {
        Print(N->Llink);
    }
    if(N->Rlink != NULL) {
        Print(N->Rlink);
    }
    printf("%d\n", N->value);
}

int main() {
    tree.link = NULL;
    int input;
    while(scanf("%d", &input) != EOF) {
        insert(input);
    }
    Print(tree.link);
}