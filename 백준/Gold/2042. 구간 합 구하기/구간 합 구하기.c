#include<stdio.h>
#include<stdlib.h>

long long tree(int node, int start, int end, long long* segmentTree, long long *input) {
    if(start == end) return segmentTree[node] = input[start];

    int mid = (start + end) / 2;
    segmentTree[node] = tree(node * 2, start, mid, segmentTree, input) + tree(node * 2 + 1, mid + 1, end, segmentTree, input);
    return segmentTree[node];
}

long long show(int node, long long start, long long end, long long Left, long long Right, long long* segmentTree) {
    if(Left > end || Right < start) return 0;
    if(Left <= start && Right >= end) return segmentTree[node];

    long long mid = (start + end) / 2;
    return show(node * 2, start, mid, Left, Right, segmentTree) + show(node * 2 + 1, mid + 1, end, Left, Right, segmentTree);
}

void change(int node, long long start, long long end, long long *segmentTree, long long here, long long input) {
    if(start > here || end < here) return;

    segmentTree[node] += input;
    
    if(start != end) {
        long long mid = (start + end) / 2;
        change(node * 2, start, mid, segmentTree, here, input);
        change(node * 2 + 1, mid + 1, end, segmentTree, here, input);
    }
}

int main() {
    int N, M, K, T;
    long long s, e;
    scanf("%d %d %d", &N, &M, &K);
    long long *seg = (long long*)malloc(sizeof(long long) * N * 4);
    long long *input = (long long*)malloc(sizeof(long long) * N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &input[i]);
    }
    tree(1, 0, N - 1, seg, input);
    for(int i = 0; i < M + K; i++) {
        scanf("%d %lld %lld", &T, &s, &e);
        if(T == 2) {
            printf("%lld\n", show(1, 0, N - 1, s - 1, e - 1, seg));
        }
        else {
            change(1, 0, N - 1, seg, s - 1, e - input[s - 1]);
            input[s - 1] = e;
        }
    }
}