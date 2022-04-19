#include<stdio.h>


long long dp[1000000] = {1, 2, 4};

long long func(int n) {

    if(dp[n - 1]) {
        return dp[n - 1];
    }

    if(n <= 3) {
        return dp[n - 1];
    }
    
    
    for(int i = 3; i < n; i++) {
        dp[i] = dp[i - 3] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 1] % 1000000009;
    }
    return dp[n - 1];
}

int main() {
    int n, T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%lld\n", func(n) % 1000000009);
    }
}