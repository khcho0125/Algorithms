#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000001

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

int dist[1000] = {0,};
int graf[1000][1000];
node Priority_queue[100000] = {0,};
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

void dijkstra(int start, int N) {
    pre = 1;
    Priority_I(start, 0);
    node* out = (node*)malloc(sizeof(node));
    while(pre != 0) {
        memcpy(out, Priority_O(), sizeof(node));
        
        for(int temp = 0; temp < N; temp++) {
            if(graf[out->idx][temp] != -1 && dist[temp] > out->weight + graf[out->idx][temp]) {
                dist[temp] = out->weight + graf[out->idx][temp];
                Priority_I(temp, graf[out->idx][temp] + out->weight);
            }
        }
    }
}

int main()
{
    int N, M, start, end, weight, A, B;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
        for(int j = 0; j < N; j++) {
            graf[i][j] = -1;
        }
    }
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        if(graf[start -1][end - 1] > weight || graf[start - 1][end - 1] == -1)
            graf[start - 1][end - 1] = weight;
    }
    scanf("%d %d", &A, &B);
    dist[A - 1] = 0;
    dijkstra(A - 1, N);
    printf("%d", dist[B - 1]);
}