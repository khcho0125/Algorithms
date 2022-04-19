#include<stdio.h>
#include<stdlib.h>

typedef struct baekjoon {
    int value;
    int idx;
}node;

int compare(const void* a, const void* b) {

    node num1 = *(node*)a;
    node num2 = *(node*)b;

    if(num1.value > num2.value) {
        return 1;
    }

    if(num1.value < num2.value) {
        return -1;
    }
    
    return 0;
}

node input[500000];
int segtree[2000000] = {0,};

int tree(int node, int start, int end, int index) {
    if(start == end) return segtree[node] = 1;
    int mid = (start + end) / 2;
    if(index <= mid) tree(node * 2, start, mid, index);
    else tree(node * 2 + 1, mid + 1, end, index);
    return segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int count(int node, int start, int end, int Left, int Right) {
    if(start > Right || end < Left) return 0;
    if(Left <= start && Right >= end) return segtree[node];
    int mid = (start + end) / 2;
    return count(node * 2, start, mid, Left, Right) + count(node * 2 + 1, mid + 1, end, Left, Right);
}

int main() {
    int N;
    long long result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i].value);
        input[i].idx = i;
    }
    qsort(input, N, sizeof(node), compare);
    for(int i = 0; i < N; i++) {
        result += (long long)count(1, 0, N - 1, input[i].idx + 1, N - 1);
        tree(1, 0, N - 1, input[i].idx);
    }
    printf("%lld", result);
}