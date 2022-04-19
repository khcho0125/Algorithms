#include <stdio.h>
#include <math.h>

#define MOD 1000000007
#define ll long long

ll GCD(long long a, long long b)
{
    if (a % b == 0)
    {
        return b;
    }
    return GCD(b, a % b);
}

ll moduler(long long a)
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

int main()
{
    ll N, S, a = 0, b = 0, gcd, E = 0;
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%lld %lld", &N, &S);
        if (S % N == 0)
        {
            E += S / N;
        }
        else
        {
            gcd = GCD(S, N);
            N /= gcd;
            S /= gcd;
            E += (S * moduler(N)) % MOD;
        }
    }
    printf("%lld", E % MOD);
}