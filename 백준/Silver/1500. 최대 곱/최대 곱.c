#include<stdio.h>

#define ll long long

ll pow(ll a, ll n) {
    if(!n) return 1;
    if(n % 2 == 0) return pow(a * a, n / 2);
    return pow(a * a, n / 2) * a;
}

int main() {
    ll S, K;
    scanf("%lld %lld", &S, &K);
    printf("%lld", pow(S / K, K - S % K) * pow(S / K + 1, S % K));
}