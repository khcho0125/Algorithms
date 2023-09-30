#include<stdio.h>

#define ll long long
#define N_MAX 100001
#define LEN_MAX 11

const int MOD = 1e9 + 7;

int A[N_MAX];
ll segment[LEN_MAX][N_MAX * 4];

ll modulus(ll a, ll b) {
    return (a + b) % MOD;
}

ll update(int k, int idx, int s, int e, int t, ll value) {
    if(t < s || e < t) return segment[k][idx];
    if(s == e) return segment[k][idx] = modulus(segment[k][idx], value);

    int m = (s + e) / 2;
    ll lt = update(k, idx * 2, s, m, t, value);
    ll rt = update(k, idx * 2 + 1, m + 1, e, t, value);

    return segment[k][idx] = modulus(lt, rt);
}

ll find(int k, int idx, int s, int e, int t) {
    if(t <= s) return 0;
    if(e < t) return segment[k][idx];

    int m = (s + e) / 2;
    ll lt = find(k, idx * 2, s, m, t);
    ll rt = find(k, idx * 2 + 1, m + 1, e, t);

    return modulus(lt, rt); 
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= N; i++) {
        update(0, 1, 1, N, A[i], 1);
        for(int k = 1; k < LEN_MAX; k++) {
            ll weight = find(k - 1, 1, 1, N, A[i]);
            update(k, 1, 1, N, A[i], weight);
        }
    }

    printf("%lld", segment[10][1]);
}