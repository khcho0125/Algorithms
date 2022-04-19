#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 987654321

typedef struct Node
{
    int idx;
    long long weight;
    struct Node *link;
} node;

typedef struct Tree
{
    node *link;
    node *back;
} tree;


long long dist[500] = {0,};
tree graf[500];

int Bellman(int start, int N) {
    node* temp = (node*)malloc(sizeof(node));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(temp = graf[j].link; temp != NULL; temp = temp->link) {
                if(dist[j] != INF && dist[temp->idx] > temp->weight + dist[j]) {
                    dist[temp->idx] = temp->weight + dist[j];
                    if(i == N - 1) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, X, start, end, cycle = 0;
    long long weight;
    scanf("%d %d", &N, &M);
    for(int i = 1; i < N; i++) {
        dist[i] = INF;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %lld", &start, &end, &weight);
        node* newNode = (node*)malloc(sizeof(node));
        newNode->idx = end - 1;
        newNode->weight = weight;
        newNode->link = NULL;
        if(graf[start - 1].link == NULL) {
            graf[start - 1].link = newNode;
            graf[start - 1].back = newNode;
        } else {
            graf[start - 1].back->link = newNode;
            graf[start - 1].back = newNode;
        }
    }
    if(Bellman(0, N)) {
        printf("-1");
    }
    else {
        for(int i = 1; i < N; i++) {
            if(dist[i] == INF) printf("-1\n");
            else printf("%lld\n", dist[i]);
        }
    }
}