#include<stdio.h>

#define ll long long

ll input[100001];
ll segment[400004] = {0,};

ll find(int idx, int start, int end, ll value) {
    if(value < start || value > end) return 0;
    if(start == end) return input[value] + segment[idx];

    int mid = (start + end) / 2;
    return find(idx * 2, start, mid, value) + find(idx * 2 + 1, mid + 1, end, value) + segment[idx];
}

void update(int idx, int start, int end, int s, int e, ll value) {
    if(e < start || s > end) return; 
    if(s <= start && end <= e) {
        segment[idx] += value;
        return;
    }

    int mid = (start + end) / 2;
    update(idx * 2, start, mid, s, e, value);
    update(idx * 2 + 1, mid + 1, end, s, e, value);
}

int main() {
    int N, M, q, i, j, x;
    ll k;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%lld", &input[i]);
    }
    scanf("%d", &M);
    for(int query = 0; query < M; query++) {
        scanf("%d", &q);
        if(q == 2) {
            scanf("%d", &x);
            printf("%lld\n", find(1, 1, N, x));
        }
        else {
            scanf("%d %d %lld", &i, &j, &k);
            update(1, 1, N, i, j, k);
        }
    }
}