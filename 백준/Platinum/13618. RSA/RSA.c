#include<stdio.h>
#include<stdbool.h>

#define ll long long
#define PRIME_SIZE 32000

typedef struct ExtendedEuclid {
    ll g, x, y;
}EE;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

bool prime[PRIME_SIZE];

ll eulerPhi(ll n) {
    ll ret = n;
    for(ll i = 2; i * i <= n; i++) {
        if(!prime[i]) {
            if(n % i == 0) {
                ret = ret * (i - 1) / i;

                do {
                    n /= i;
                } while(n % i == 0);
            }

            for(ll temp = i * i; temp < PRIME_SIZE; temp += i) prime[temp] = true;
        }
    }
    if(n > 0) {
        ret = ret * (n - 1) / n;
    }

    return ret;
}

ll modinverse(ll x, ll exp, ll mod) {
    ll ret = 1;
    while(exp) {
        if(exp & 1) ret = ret * x % mod;

        x = x * x % mod;
        exp >>= 1;
    }
    return ret;
}

ll solution(ll N, ll E, ll C) {
    ll P = eulerPhi(N);

    EE en = xGCD(E, P);
    ll D = en.x;
    ll lcm = E * P / en.g;

    if(D < 0) D += (-D / (lcm / E) + (-D % (lcm / E) != 0)) * (lcm / E);

    return modinverse(C, D, N);
}

int main() {
    ll N, E, C;
    scanf("%lld %lld %lld", &N, &E, &C);
    printf("%lld", solution(N, E, C));
}