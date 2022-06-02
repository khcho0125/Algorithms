#include<stdio.h>

#define MAX 1000000

int box[4000004] = {0,};

void update(int start, int end, int idx, int target, int weight) {
    box[idx] += weight;
    if(start == end) return;
    int mid = (start + end) / 2;
    if(mid < target) {
        update(mid + 1, end, idx * 2 + 1, target, weight);
        return;
    }
    update(start, mid, idx * 2, target, weight);
}

int query(int start, int end, int idx, int target) {
    box[idx]--;
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(box[idx * 2] < target) return query(mid + 1, end, idx * 2 + 1, target - box[idx * 2]);
    return query(start, mid, idx * 2, target);
}

int main() {
    int N, A, B, C;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A);
        if(A == 1) {
            scanf("%d", &B);
            printf("%d\n", query(1, MAX, 1, B));
        }
        else {
            scanf("%d %d", &B, &C);
            update(1, MAX, 1, B, C);
        }
    }
}