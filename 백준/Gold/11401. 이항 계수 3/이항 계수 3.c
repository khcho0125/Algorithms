#include <stdio.h>

#define MOD 1000000007
#define ll long long

ll dp[4000001] = {1,};

ll div(ll a, ll b) {
    if(b == 1) {
        return a % MOD;
    }
    ll D = div(a, b / 2);
    if(b % 2) {
        return (D * D % MOD) * a % MOD; 
    }
    return D * D % MOD;
}

int main()
{
    ll N, R, gcd;
    scanf("%lld %lld", &N, &R);
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] * i % MOD;
    }
    printf("%lld", dp[N] * div(dp[N - R] * dp[R] % MOD, MOD - 2) % MOD);
}