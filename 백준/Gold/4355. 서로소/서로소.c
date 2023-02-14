#include<stdio.h>

#define ll long long

ll count(ll);

int main() {
    ll N;
    scanf("%lld", &N);
    while(N) {
        printf("%lld\n", N == 1 ? 0 : count(N));
        scanf("%lld", &N);
    }
}

ll count(ll N) {
    ll ans = N;
    for(ll i = 2; i * i <= ans; i++) {
        if(N % i == 0) {
            ans -= ans / i;

            do {
                N /= i;
            } while(N % i == 0);
        }
    }
    if(N > 1) {
        ans -= ans / N;
    }

    return ans;
}