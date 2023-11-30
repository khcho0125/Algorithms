#include<stdio.h>
#include<stdbool.h>

#define ll long long

typedef struct ExtendedEuclid {
    ll g, x, y;
}EE;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

ll md(ll block, ll mod) {
    return (block % mod + mod) % mod;
}

int main() {
    ll A, B, C, k;
    while(true) {
        scanf("%lld %lld %lld %lld", &A, &B, &C, &k);

        if(!A && !B && !C && !k) break;
        
        ll mod = (1LL << k);
        EE gcd = xGCD(C, mod);

        ll k1 = md(md(B - A, mod) / gcd.g * gcd.x, mod);
        ll ans = md(A + md(C * k1, mod), mod);
        if(ans != B) printf("FOREVER\n");
        else printf("%lld\n", md(k1, mod / gcd.g));
    }
}