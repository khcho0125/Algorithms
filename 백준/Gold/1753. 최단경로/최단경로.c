#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 3000001

typedef struct Node
{
    int idx;
    int weight;
    struct Node *link;
} node;

typedef struct Tree
{
    node *link;
    node *back;
} tree;


int dist[20000] = {0,};
tree graf[20000];
node Priority_queue[300000] = {0,};
int pre = 1;

void Priority_I(int idx, int weight) {
    int parent = pre++;
    while((parent != 1) && weight < Priority_queue[parent / 2].weight) {
        Priority_queue[parent].idx = Priority_queue[parent / 2].idx;
        Priority_queue[parent].weight = Priority_queue[parent / 2].weight;
        parent /= 2;
    }
    Priority_queue[parent].idx = idx;
    Priority_queue[parent].weight = weight;
}

node* Priority_O() {
    node* first = (node*)malloc(sizeof(node));
    int tempIdx, tempWeight;
    first->idx = Priority_queue[1].idx;
    first->weight = Priority_queue[1].weight;
    tempIdx = Priority_queue[--pre].idx;
    tempWeight = Priority_queue[pre].weight;
    int child = 2, parent = 1;
    while(child <= pre) {
        if((child + 1 < pre) && (Priority_queue[child].weight > Priority_queue[child + 1].weight)) {
            child++;
        }

        if(tempWeight <= Priority_queue[child].weight) {
            break;
        }
        Priority_queue[parent].idx = Priority_queue[child].idx;
        Priority_queue[parent].weight = Priority_queue[child].weight;
        parent = child;
        child *= 2;
    }
    Priority_queue[parent].idx = tempIdx;
    Priority_queue[parent].weight = tempWeight;
    return first;
}

void dijkstra(int start, tree* list, int* distance) {
    pre = 1;
    node* temp = (node*)malloc(sizeof(node));
    temp = list[start].link;
    while(temp != NULL) {
        if(distance[temp->idx] > temp->weight) {
            distance[temp->idx] = temp->weight;
            Priority_I(temp->idx, temp->weight);
        }
        temp = temp->link;
    }
    node* out = (node*)malloc(sizeof(node));
    while(pre != 0) {
        memcpy(out, Priority_O(), sizeof(node));
        temp = list[out->idx].link;
        
        while(temp != NULL) {
            if(distance[temp->idx] > out->weight + temp->weight) {
                distance[temp->idx] = out->weight + temp->weight;
                Priority_I(temp->idx, temp->weight + out->weight);
            }
            temp = temp->link;
        }
    }
}

int main()
{
    int N, M, X, start, end, weight, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    dist[V - 1] = 0;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &weight);
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
    dijkstra(V - 1, graf, dist);
    for(int i = 0; i < N; i++) {
        if(dist[i] >= INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", dist[i]);
        }
    }
}