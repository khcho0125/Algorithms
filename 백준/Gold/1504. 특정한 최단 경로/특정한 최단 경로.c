#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) ((a > b ? b : a))
#define INF 200000001

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


int dist[800] = {0,};
int dist2[800] = {0,};
tree graf[800];
node Priority_queue[200000] = {0,};
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
        distance[temp->idx] = temp->weight;
        Priority_I(temp->idx, temp->weight);
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
    int N, M, X, start, end, weight, MAX = 0, V1, V2, result;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
        dist2[i] = INF;
    }
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
        node* newNode2 = (node*)malloc(sizeof(node));
        newNode2->idx = start - 1;
        newNode2->weight = weight;
        newNode2->link = NULL;
        if(graf[end - 1].link == NULL) {
            graf[end - 1].link = newNode2;
            graf[end - 1].back = newNode2;
        }
        else {
            graf[end - 1].back->link = newNode2;
            graf[end - 1].back = newNode2;
        }
    }
    scanf("%d %d", &V1, &V2);
    dist[V1 - 1] = 0;
    dist2[V2 - 1] = 0;
    dijkstra(V1 - 1, graf, dist);
    dijkstra(V2 - 1, graf, dist2);
    result = min(dist[0] + dist[V2 - 1] + dist2[N - 1], dist2[0] + dist2[V1 - 1] + dist[N - 1]);
    printf("%d", result > 200000000 ? -1 : result);
}