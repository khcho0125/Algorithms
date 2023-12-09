#include<stdio.h>

#define ll long long

typedef struct Pair {
    ll a, b;
}P;

typedef struct ExtendedEuclid {
    ll g, x, y;
}EE;

const ll LIMIT = 1e9;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

P solution(ll N) {
    P result = (P){1, N};

    for(P seq = (P){1, 1}; seq.a + seq.b <= LIMIT; seq = (P){seq.b, seq.a + seq.b}) {
        EE gcd = xGCD(seq.a, seq.b);

        gcd.x = N / gcd.g * gcd.x;
        gcd.y = N / gcd.g * gcd.y;

        ll lcm = seq.a / gcd.g * seq.b;

        if(gcd.x < gcd.y) {
            ll diff = (gcd.y - gcd.x) / (lcm / seq.a + lcm / seq.b);

            gcd.x += lcm / seq.a * diff;
            gcd.y -= lcm / seq.b * diff;
        }
        else {
            ll diff = (gcd.x - gcd.y) / (lcm / seq.a + lcm / seq.b) + ((gcd.x - gcd.y) % (lcm / seq.a + lcm / seq.b) != 0);
            
            gcd.x -= lcm / seq.a * diff;
            gcd.y += lcm / seq.b * diff;
        }

        if(gcd.x <= gcd.y && gcd.x > 0 && gcd.y > 0 && gcd.x * seq.a + gcd.y * seq.b == N) {
            if(result.b > gcd.y || (result.b == gcd.y && result.a > gcd.x)) result = (P){gcd.x, gcd.y};
        }
    }

    return result;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        P result = solution(N);
        printf("%lld %lld\n", result.a, result.b);
    }
}