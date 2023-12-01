#include<stdio.h>

#define ll long long
#define max(a, b) ((a) > (b) ? a : b)

const ll LIMIT = 1e9;

typedef struct ExtendedEuclid {
    ll g, x, y;
}EE;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

int solution(ll K, ll C) {
    EE gcd = xGCD(C, K);
    if(gcd.g != 1) return -1;

    if(gcd.x <= 0) {
        ll need = (-gcd.x + 1) / K + ((-gcd.x + 1) % K != 0);

        gcd.x += need * K;
        gcd.y -= need * C;
    }

    if(gcd.y >= 0) {
        ll need = (gcd.y + 1) / C + ((gcd.y + 1) % C != 0);

        gcd.x += need * K;
        gcd.y -= need * C;
    }

    if(gcd.x > 0 && gcd.x <= LIMIT && gcd.y < 0) return gcd.x;

    return -1;
}

int main() {
    ll t, K, C;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &K, &C); 
        int result = solution(K, C);
        if(result == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", result);
    }
}