#include<stdio.h>

int dp[1001] = {0, 1, 3,};

int func(int n) {

    if(dp[n]) {
        return dp[n];
    }

    dp[n] = (func(n - 1) + func(n - 2) * 2) % 10007;
    return dp[n];
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", func(N));
}