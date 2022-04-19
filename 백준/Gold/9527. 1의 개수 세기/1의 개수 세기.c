#include<stdio.h>

#define ll long long

ll dp[55] = {0,};

ll get(ll x) {
    ll i = 54, ans = x & 1;
    for(; i > 0; i--) {
        if(x & (1LL << i)) {
            ans += dp[i] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}

int main() {
    int i;
    ll A, B, temp;
    for(i = 1, temp = 1; i < 55; i++, temp = (temp << 1)) {
        dp[i] = temp + dp[i - 1] * 2;
    }
    scanf("%lld %lld", &A, &B);
    printf("%lld", get(B) - get(A - 1));
}