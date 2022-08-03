#include<stdio.h>
#include<map>

using namespace std;

#define MOD 1000000000
#define ll long long

map<ll, ll> dp;

ll fibonacci(ll N) {
    if(!dp.count(N)) {
        ll Fn = fibonacci(N / 2);
        if(N % 2 == 0) {
            ll Fn_1 = fibonacci(N / 2 - 1);
            dp[N] = (Fn * (Fn + 2 * Fn_1) % MOD) % MOD;
        }
        else {
            ll Fnt1 = fibonacci(N / 2 + 1);
            dp[N] = ((Fnt1 * Fnt1) % MOD + (Fn * Fn) % MOD) % MOD;
        }
    }

    return dp[N];
}

int main() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    ll a, b, sum = 0, minus = 0;
    scanf("%lld %lld", &a, &b);
    sum = fibonacci(b + 2);
    minus = fibonacci(a + 1);
    printf("%lld", (sum + MOD - minus) % MOD);
}