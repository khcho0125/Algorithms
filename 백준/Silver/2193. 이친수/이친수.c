#include<stdio.h>

#define ll long long

ll dp[91][2] = {0,};

int main() {
    int N;
    scanf("%d", &N);
    dp[1][1] = 1;
    for(int i = 1; i < N; i++) {
        dp[i + 1][1] = dp[i][0];
        dp[i + 1][0] = dp[i][1] + dp[i][0];
    }
    printf("%lld", dp[N][0] + dp[N][1]);
}