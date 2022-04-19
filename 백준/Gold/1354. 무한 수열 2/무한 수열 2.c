#include<stdio.h>

#define MAX 50000000
#define ll long long

ll dp[MAX] = {0,};
ll N, P, Q, X, Y;

ll func(ll idx) {
    if(idx <= 0) {
        return 1LL;
    }

    if(idx < MAX && dp[idx]) {
        return dp[idx];
    }
    
    if(idx >= MAX) {
        return func(idx / P - X) + func(idx / Q - Y);
    }
    else {
        return dp[idx] = func(idx / P - X) + func(idx / Q - Y);
    }

}

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
    printf("%lld", func(N));
}