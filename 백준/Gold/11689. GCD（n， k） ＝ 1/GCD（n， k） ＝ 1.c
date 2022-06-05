#include<stdio.h>

#define ll long long

int main() {
    ll N;
    scanf("%lld", &N);
    ll ans = N;
    for(ll i = 2LL; i * i <= ans; i++) {
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
    printf("%lld\n", ans);
}