#include<stdio.h>

#define ll long long
#define MOD 1000000007

ll segment[4000004] = {0,};
int number[1000001];
int N;

void tree(int start, int end, int index) {

    if(start == end) {
        segment[index] = number[start];
        return;
    }

    int mid = (start + end) / 2;
    tree(start, mid, index * 2);
    tree(mid + 1, end, index * 2 + 1);
    segment[index] = segment[index * 2] * segment[index * 2 + 1] % MOD;
}

void update(int start, int end, int num, int index) {

    if(num < start || end < num) return;
    if(start == num && end == num) {
        segment[index] = number[num];
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, num, index * 2);
    update(mid + 1, end, num, index * 2 + 1);
    segment[index] = segment[index * 2] * segment[index * 2 + 1] % MOD;
}

ll find(int start, int end, int s, int e, int index) {

    if(e < start || end < s) return 1LL;
    if(s <= start && end <= e) return segment[index];

    int mid = (start + end) / 2;
    ll one = find(start, mid, s, e, index * 2);
    ll two = find(mid + 1, end, s, e, index * 2 + 1);
    return one * two % MOD;
}

int main() {
    int M, K, a, b, c;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &number[i]);
    }
    tree(1, N, 1);
    for(int i = 0; i < M + K; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) {
            number[b] = c;
            update(1, N, b, 1);
        }
        else {
            printf("%lld\n", find(1, N, b, c, 1));
        }
    }
}