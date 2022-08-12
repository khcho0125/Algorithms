#include<stdio.h>

#define MOD 1000000007LL
#define ll long long

ll fact[4000001] = {1,};

ll factorial(int N) {
    if(fact[N]) return fact[N];
    return fact[N] = N * factorial(N - 1) % MOD;
}

int main() {
    int M, N, K;
    ll a, b, p, temp;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &N, &K);

        a = factorial(N);
        b = factorial(K) * factorial(N - K) % MOD;

        temp = 1;
        p = MOD - 2;
        while(p) {
            if(p & 1) {
                temp = temp * b % MOD;
            }

            b = b * b % MOD;
            p >>= 1;
        }
        
        printf("%lld\n", a * temp % MOD);
    }
}