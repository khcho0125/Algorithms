#include <stdio.h>

int dp[1001] = {0, 1, 2,};

int func(int n) {

    if(dp[n]) {
        return dp[n];
    }

    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
}