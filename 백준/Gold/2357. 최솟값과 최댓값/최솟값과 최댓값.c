#include<stdio.h>

typedef struct baekjoon {
    long long max;
    long long min;
}maxAndmin;

long long input[100001] = {0,};
maxAndmin segmentTree[400004] = {0,};

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a > b ? b : a;
}

maxAndmin sum(maxAndmin a, maxAndmin b) {

    maxAndmin temp = {0, 0};
    temp.max = max(a.max, b.max);
    temp.min = min(a.min, b.min);
    return temp;
}

maxAndmin Tree(int node, int start, int end) {
    if(start == end) {
        segmentTree[node].max = input[start];
        segmentTree[node].min = input[start];
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    maxAndmin node_1 = Tree(node * 2, start, mid);
    maxAndmin node_2 = Tree(node * 2 + 1, mid + 1, end);
    segmentTree[node] = sum(node_1, node_2);
    return segmentTree[node];
}

maxAndmin show(int node, int start, int end, int Left, int Right) {
    maxAndmin temp = {0, 1000000001};
    if(end < Left || start > Right) return temp;
    if(start >= Left && end <= Right) {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    maxAndmin node_1 = show(node * 2, start, mid, Left, Right);
    maxAndmin node_2 = show(node * 2 + 1, mid + 1, end, Left, Right);
    temp =  sum(node_1, node_2);
    return temp;
}

int main() {
    int N, M, s, e;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &input[i]);
    }
    Tree(1, 0, N - 1);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        maxAndmin temp = show(1, 0, N - 1, s - 1, e - 1);
        printf("%lld %lld\n", temp.min, temp.max);
    }
}