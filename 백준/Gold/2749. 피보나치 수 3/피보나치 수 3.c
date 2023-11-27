#include<stdio.h>

#define ll long long

#define MOD 1000000

typedef struct Pair {
    ll first, second;
}P;

P operator(P a, P b) {
    return (P) {
        .first = ((a.first * b.first) % MOD + (a.second * b.second) % MOD) % MOD,
        .second = ((a.first * b.second) % MOD + (a.second * (b.first + b.second) % MOD)) % MOD
    };
}

int main() {
    ll n;
    scanf("%lld", &n);

    P temp = (P) {0, 1};
    P fib = (P) {0, 1};
    for(int i = 0; (1ULL << i) <= n; i++) {
        if(n & (1ULL << i)) temp = operator(temp, fib);
        fib = operator(fib, fib);
    }

    printf("%lld", temp.first);
}