#include <stdio.h>
#include <math.h>

#define MOD 1000000007
#define ll long long

ll moduler(ll a)
{
    ll result = 1;
    ll N = a;
    ll P = MOD - 2;
    while (P)
    {
        if (P & 1)
        {
            result = (result * N) % MOD;
        }
        N = (N * N) % MOD;
        P >>= 1;
    }
    return result;
}

ll factorial(ll N) {
    ll result = 1;
    for(int i = 2; i <= N; i++) {
        result *= i;
        result %= MOD;
    }
    return result;
}

int main()
{
    ll N, R, gcd, E;
    scanf("%lld %lld", &N, &R);
    E = factorial(N) * moduler((factorial(R) % MOD) * (factorial(N - R) % MOD) % MOD) % MOD;
    printf("%lld", E);
}