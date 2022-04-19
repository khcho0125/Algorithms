#include<stdio.h>
#include<stdlib.h>

int tree(int node, int start, int end, int* segmentTree, int *input) {
    if(start == end) return segmentTree[node] = input[start];

    int mid = (start + end) / 2;
    segmentTree[node] = tree(node * 2, start, mid, segmentTree, input) + tree(node * 2 + 1, mid + 1, end, segmentTree, input);
    return segmentTree[node];
}

int show(int node, int start, int end, int Left, int Right, int* segmentTree) {
    if(Left > end || Right < start) return 0;
    if(Left <= start && Right >= end) return segmentTree[node];

    int mid = (start + end) / 2;
    return show(node * 2, start, mid, Left, Right, segmentTree) + show(node * 2 + 1, mid + 1, end, Left, Right, segmentTree);
}

int main() {
    int N, M, s, e;
    scanf("%d %d", &N, &M);
    int *seg = (int*)malloc(sizeof(int) * N * 4);
    int *input = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    tree(1, 0, N - 1, seg, input);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", show(1, 0, N - 1, s - 1, e - 1, seg));
    }
}