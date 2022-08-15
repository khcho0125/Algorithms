#include<stdio.h>

#define ll long long

int indexSet[1000001];
int tree[2000000] = {0,};
ll result = 0;

ll segment(int start, int end, int idx, int node) {
    if(idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] = 1;

    int mid = (start + end) / 2;
    ll l = segment(start, mid, idx, node * 2);
    ll r = segment(mid + 1, end, idx, node * 2 + 1);

    return tree[node] = l + r;
}

void cross(int start, int end, int A, int node) {
    if(end < A) return;
    if(A <= start) {
        result += tree[node];
        return;
    }

    int mid = (start + end) / 2;
    cross(start, mid, A, node * 2);
    cross(mid + 1, end, A, node * 2 + 1);
}

int main() {
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &M);
        indexSet[M] = i;
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &M);
        cross(0, N - 1, indexSet[M], 1);
        segment(0, N - 1, indexSet[M], 1);
    }
    printf("%lld", result);
}