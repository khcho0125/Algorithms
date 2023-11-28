#include<stdio.h>

#define ll long long

typedef struct ExtendEuclid {
    ll g, x, y;
}EE;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

ll inverse(ll a, ll n) {
    EE gcd = xGCD(a, n);

    if(gcd.g != 1) return -1;
    while(gcd.x < 0) gcd.x += n;
    
    return gcd.x;
}

int main() {
    ll N, A;
    scanf("%lld %lld", &N, &A);
    printf("%lld %lld", N - A, inverse(A, N));
}